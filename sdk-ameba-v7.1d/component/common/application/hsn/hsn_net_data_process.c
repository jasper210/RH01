/*
 * @Description: rlt_net_data_process.c
 * @Author: xuetong
 * @Date: 2019-08-05 08:48:44
 * @LastEditTime: 2019-10-22 14:04:18
 * @LastEditors: Please set LastEditors
 */
#include "hsn_common.h"

#include <time.h>

#if 0

struct tm {
	int tm_sec; /* 秒 – 取值区间为[0,59] */
	int tm_min; /* 分 - 取值区间为[0,59] */
	int tm_hour; /* 时 - 取值区间为[0,23] */
	int tm_mday; /* 一个月中的日期 - 取值区间为[1,31] */
	int tm_mon; /* 月份（从一月开始，0代表一月） - 取值区间为[0,11] */
	int tm_year; /* 年份，其值等于实际年份减去1900 */
};




typedef struct tm_s {
　　int tm_sec; /* 秒 – 取值区间为[0,59] */
　　int tm_min; /* 分 - 取值区间为[0,59] */
　　int tm_hour; /* 时 - 取值区间为[0,23] */
　　int tm_mday; /* 一个月中的日期 - 取值区间为[1,31] */
　　int tm_mon; /* 月份（从一月开始，0代表一月） - 取值区间为[0,11] */
　　int tm_year; /* 年份，其值等于实际年份减去1900 */
} tm;
#endif


int need_offline_flag = 0;
static int hb_miss_times = 0;
TimerHandle_t heartbeat_timer = NULL;
TimerHandle_t dataresp_timer = NULL;
extern unsigned char msg_data_1e[8];
extern int udp_socket_fd;
extern int tcp_socket_fd;
extern struct sockaddr_in to;
extern struct sockaddr_in from_addr;
extern unsigned char config_bssid[6];
extern unsigned char config_passwd[32];
extern int config_passwd_len;
unsigned char bssid[17];
extern struct netif xnetif[NET_IF_NUM]; 
extern unsigned char server_aes_key[16];
unsigned char server_token[256] = {0};
int hb_flag;


t_net_packet_param net_packet_info;

char gv_pakect_tmp_buf[512] = {0};


int tcp_server_socket;

#if 0

const char Days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
void localtime(unsigned int time,struct tm *t)
{
	unsigned int Pass4year;
	int hours_per_year;
	
	if(time < 0)
	{
		time = 0;
	}
	//取秒时间
	t->tm_sec=(int)(time % 60);
	time /= 60;
	//取分钟时间
	t->tm_min=(int)(time % 60);
	time /= 60;
	//取过去多少个四年，每四年有 1461*24 小时
	Pass4year=((unsigned int)time / (1461L * 24L));
	//计算年份
	t->tm_year=(Pass4year << 2) + 1970;
	//四年中剩下的小时数
	time %= 1461L * 24L;
	//校正闰年影响的年份，计算一年中剩下的小时数
	for (;;)
	{
		//一年的小时数
		hours_per_year = 365 * 24;
		//判断闰年
		if ((t->tm_year & 3) == 0)
		{
			//是闰年，一年则多24小时，即一天
			hours_per_year += 24;
		}
		if (time < hours_per_year)
		{
			break;
		}
		t->tm_year++;
		time -= hours_per_year;
	}
	//小时数
	t->tm_hour=(int)(time % 24);
	//一年中剩下的天数
	time /= 24;
	//假定为闰年
	time++;
	//校正闰年的误差，计算月份，日期
	if((t->tm_year & 3) == 0)
	{
		if (time > 60)
		{
			time--;
		}
		else
		{
			if (time == 60)
			{
				t->tm_mon = 1;
				t->tm_mday = 29;
				return ;
			}
		}
	}
	//计算月日
	for (t->tm_mon = 0; Days[t->tm_mon] < time;t->tm_mon++)
	{
		time -= Days[t->tm_mon];
	}
	
	t->tm_mday = (int)(time);
	
	return;
}

static unsigned int mon_yday[2][12] =
{
	{0,31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334},
	{0,31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335},
};

int isleap(int year)
{
	return (year) % 4 == 0 && ((year) % 100 != 0 || (year) % 400 == 0);
}

unsigned int mktime(struct tm dt)
{
	unsigned int result;
	int i =0;
	// 以平年时间计算的秒数
	result = (dt.tm_year - 1970) * 365 * 24 * 3600 +
	(mon_yday[isleap(dt.tm_year)][dt.tm_mon-1] + dt.tm_mday - 1) * 24 * 3600 +
	dt.tm_hour * 3600 + dt.tm_min * 60 + dt.tm_sec;
	// 加上闰年的秒数
	for(i=1970; i < dt.tm_year; i++)
	{
		if(isleap(i))
		{
			result += 24 * 3600;
		}
	}
	return(result);
}
#endif

const char Days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


static unsigned int mon_yday[2][12] =
{
	{0,31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334},
	{0,31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335},
};


typedef struct bbtTM {
	int tm_sec; /* 秒 – 取值区间为[0,59] */
	int tm_min; /* 分 - 取值区间为[0,59] */
	int tm_hour; /* 时 - 取值区间为[0,23] */
	int tm_mday; /* 一个月中的日期 - 取值区间为[1,31] */
	int tm_mon; /* 月份（从一月开始，0代表一月） - 取值区间为[0,11] */
	int tm_year; /* 年份，其值等于实际年份 */
} bbtTM_S;
 
 
 
// 时间戳转年月日时分秒
void bbt_localtime(uint32_t time, bbtTM_S *t)
{
	uint32_t Pass4year;
	int hours_per_year;
 
	//取秒时间
	t->tm_sec=(int)(time % 60);
	time /= 60;
	//取分钟时间
	t->tm_min=(int)(time % 60);
	time /= 60;
	//取过去多少个四年，每四年有 1461*24 小时
	Pass4year = time / (1461L * 24L);
	//计算年份
	t->tm_year=(Pass4year << 2) + 1970;
	//四年中剩下的小时数
	time %= 1461L * 24L;
	//校正闰年影响的年份，计算一年中剩下的小时数
	while(1)
	{
		//一年的小时数
		hours_per_year = 365 * 24;
		//判断闰年，是闰年，一年则多24小时，即一天
		if ((t->tm_year & 3) == 0) hours_per_year += 24;
 
		if (time < hours_per_year) break;
 
		t->tm_year++;
		time -= hours_per_year;
	}
	//小时数
	t->tm_hour=(int)(time % 24);
	//一年中剩下的天数
	time /= 24;
	//假定为闰年
	time++;
	//校正闰年的误差，计算月份，日期
	if((t->tm_year & 3) == 0) {
		if (time > 60) {
			time--;
		} else {
			if (time == 60) {
				t->tm_mon = 1;
				t->tm_mday = 29;
				return ;
			}
		}
	}
	//计算月日
	for (t->tm_mon = 0; Days[t->tm_mon] < time;t->tm_mon++)
	{
		time -= Days[t->tm_mon];
	}
 
	t->tm_mday = (int)(time);
 
	return;
}
 
 
int bbtIsLeap(int year)
{
	return (year) % 4 == 0 && ((year) % 100 != 0 || (year) % 400 == 0);
}
 
// 年月日时分秒转时间戳
uint32_t bbt_mktime(bbtTM_S dt)
{
	uint32_t ret;
	int i =0;
	// 以平年时间计算的秒数
	ret = (dt.tm_year - 1970) * 365 * 24 * 3600;
	ret += (mon_yday[bbtIsLeap(dt.tm_year)][dt.tm_mon] + dt.tm_mday - 1) * 24 * 3600;
	ret += dt.tm_hour * 3600 + dt.tm_min * 60 + dt.tm_sec;
	// 加上闰年的秒数
	for(i=1970; i < dt.tm_year; i++)
	{
		if(bbtIsLeap(i)) {
			ret += 24 * 3600;
		}
	}
	if (ret > 4107715199) { //2100-02-29 23:59:59
		ret += 24 * 3600;
	}
	return(ret);
}




void UTCToBeijing(struct tm* time)
{
	unsigned char days = 0;
	if (time->tm_mon == 1 || time->tm_mon == 3 || time->tm_mon == 5 || time->tm_mon == 7 || time->tm_mon == 8 || time->tm_mon == 10 || time->tm_mon == 12)
	{
		days = 31;
	}
	else if (time->tm_mon == 4 || time->tm_mon == 6 || time->tm_mon == 9 || time->tm_mon == 11)
	{
		days = 30;
	}
	else if (time->tm_mon == 2)
	{
		if ((time->tm_year % 400 == 0) || ((time->tm_year % 4 == 0) && (time->tm_year % 100 != 0))) /* 判断平年还是闰年 */
		{
			days = 29;
		}
		else
		{
			days = 28;
		}
	}
	time->tm_hour += 8;                 /* 北京时间比格林威治时间快8小时 */
	if (time->tm_hour >= 24)            /* 跨天 */
	{
		time->tm_hour -= 24;
		time->tm_mday++;
		if (time->tm_mday > days)        /* 跨月 */
		{
			time->tm_mday = 1;
			time->tm_mon++;
			if (time->tm_mon > 12)    /* 跨年 */
			{
				time->tm_year++;
			}
		}
	}
}




/// 返回值：1-7，对应周一到周天
unsigned char GetWeekDayNum(uint32_t year, uint8_t month, uint8_t day)
{
#if 1
	int iWeekDay = -1;

	iWeekDay = (day + 1 + 2 * month + 3 * (month + 1) / 5 + year + year / 4 - year / 100 + year / 400) % 7;

	return iWeekDay;
#else
  unsigned int weekday = 0U;

  if (month < 3U)
  {
	/*D = { [(23 x month)/9] + day + 4 + year + [(year-1)/4] - [(year-1)/100] + [(year-1)/400] } mod 7*/
	weekday = (((23U * month) / 9U) + day + 4U + year + ((year - 1U) / 4U) - ((year - 1U) / 100U) + ((year - 1U) / 400U)) % 7U;
  }
  else
  {
	/*D = { [(23 x month)/9] + day + 4 + year + [year/4] - [year/100] + [year/400] - 2 } mod 7*/
	weekday = (((23U * month) / 9U) + day + 4U + year + (year / 4U) - (year / 100U) + (year / 400U) - 2U) % 7U;
  }

  if(weekday == 0)
  {
	  weekday = 7;
  }

  return (unsigned char)weekday;
#endif
}





int GetWeekDayNum_ex (uint32_t vp_year, uint8_t vp_month, uint8_t vp_day)
{
	int year,month,day;
	int iWeekDay = -1; 

	year = vp_year;
	month = vp_month;
	day = vp_day;
	//printf("year:%d, %d, %d\n", year, month, day);
 
      
    switch (month) {
 	    case 1 :
 	    case 3 :
 	    case 5 :
 	    case 7 :
 	    case 8 : 
 	    case 10:
 	    case 12://当月份为1，3，5，7，8，10，12 
 		    if (day<1 || day>31){//先判断是否为正确日期 
 			    printf ("您输入的日期有误，请重新输入\n");
			}
			else
			{
			    if (1 == month || 2 == month) 
				{   
                    month += 12; 
                    year--;// 把一月和二月看成是上一年的十三月和十四月，例：如果是2004-1-10则换算成：2003-13-10来代入公式计算。
                }                       
			    iWeekDay = (day + 1 + 2 * month + 3 * (month + 1) / 5 + year + year / 4 - year / 100 + year / 400) % 7;// 利用基姆拉尔森计算日期公式  w=(d+2*m+3*(m+1)/5+y+y/4-y/100+y/400)   	
                    
				printf ("weekday1:%d\n",iWeekDay);
            }
 		    break;
 		
 	    case 2://当月份为2月时 
 		    if  ( year%4==0 && year%100!=0 || year%400==0 )
			{//先判断是否为闰年 
			    if (day<1 || day>29){//判断日期是否正确
			    	printf ("您输入的日期有误，请重新输入\n"); 
				}
				else 
				{//若日期正确，进行后续计算 
			        if (1==month || 2==month){   
	                    month += 12; 
	                    year--;
	                }   
			        iWeekDay = (day + 1 + 2 * month + 3 * (month + 1) / 5 + year + year / 4 - year / 100 + year / 400) % 7;
		
	            	printf ("weekday2:%d\n",iWeekDay);
				}
			}
 		    else{  //不是闰年的情况 
			      if (day<1 || day>28){  //判断日期是否有误 
			    	printf ("您输入的日期有误，请重新输入\n"); 
				  }
				  else {  //若日期无误，进行后续计算 
				    if (1 == month || 2 == month) {   
                        month += 12; 
                        year--;
                      }   
				    iWeekDay = (day +1+ 2*month + 3*(month+1)/5 + year + year/4 - year/100 + year/400)%7;

	                    
                    printf ("weekday3:%d\n",iWeekDay);
				  }
			    }
		    break; 
			   
	    case 4 :
	    case 6 :
	    case 9 :
	    case 11:   //当月份为4，6，9，11时 
		    if (day<1 || day>30){  //判断日期是否有误 
		    	printf ("您输入的日期有误，请重新输入\n");
			}
			else {  //若日期无误，进行后续计算 
				if (1 == month || 2 == month) {   
                        month += 12; 
                        year--;
                    } 
				iWeekDay = (day +1+ 2*month + 3*(month+1)/5 + year + year/4 - year/100 + year/400)%7;

	                  
                printf ("weekday4:%d\n",iWeekDay);
			}
		    break;

	    default://月份不是1~12 
	    	iWeekDay = -1;
    }

    return (unsigned char)iWeekDay;
  } 







void cJSON_Hooks_int()
{
	cJSON_Hooks memoryHook;
	memoryHook.malloc_fn = malloc;
	memoryHook.free_fn = free;
	cJSON_InitHooks(&memoryHook);
}


void set_net_packet_seq(int msg_type, int msg_seq)
{
	net_packet_info.msg_type = msg_type;
	net_packet_info.msg_seq = msg_seq;
}



int json_net_packet_build()
{
	log_printf_d("[%s]\n",__FUNCTION__);
	md5_context md5;
  	unsigned char tmp_16_md5[16];
	unsigned char temp_8_md5[8];
	unsigned char temp_json[256] = {0};
	unsigned char packet[512] = {0};
	sprintf(temp_json, "{ \"HConfig\": \"01\", \"Range\": 0, \"Hcmd\": 2 }");
    md5_starts(&md5);
    md5_update(&md5, temp_json, strlen(temp_json));
    md5_finish(&md5, tmp_16_md5);
	memcpy(temp_8_md5, &tmp_16_md5[4], 8);
	sprintf(tmp_16_md5, "%02x%02x%02x%02x%02x%02x%02x%02x", temp_8_md5[0],temp_8_md5[1],temp_8_md5[2],temp_8_md5[3],temp_8_md5[4],temp_8_md5[5],temp_8_md5[6],temp_8_md5[7]);
	sprintf(packet, "HS%s", temp_json);
    return strlen(packet);
}


int bc_wifi_msg_packet_build(unsigned char *packet)
{
	t_WIFI_GLOBAL* pl_wg = MC_WIFI_GLOBAL_PTR();
	md5_context md5;
  	unsigned char tmp_16_md5[16];
	unsigned char temp_8_md5[8];
	unsigned char temp_json[210] = {0};
	sprintf(temp_json, "{\"Hcmd\":1,\"DID\":\"%s\",\"RID\":%d,\"PLVer\":\"%s\",\"CInfo\":\"%s\",\"HType\":0,\"ConnPort\":%d,\"ExtData\":0,\"DevList\":[{\"DevId\":\"%s\",\"DevType\":%d}]}", pl_wg->wifi_id, RID, PLVer, pl_wg->v_cinfo_version, ConnPort, pl_wg->wifi_id, pl_wg->v_device_type);
	sprintf(packet, "HS%s", temp_json);
	md5_starts(&md5);
    md5_update(&md5, temp_json, strlen(temp_json));
    md5_finish(&md5, tmp_16_md5);
	memcpy(temp_8_md5, &tmp_16_md5[4], 8);
	sprintf(tmp_16_md5, "%02x%02x%02x%02x%02x%02x%02x%02x", temp_8_md5[0],temp_8_md5[1],temp_8_md5[2],temp_8_md5[3],temp_8_md5[4],temp_8_md5[5],temp_8_md5[6],temp_8_md5[7]);
	sprintf(packet + strlen(packet), "%s", tmp_16_md5);
	return strlen(packet);
}


int discover_send_offline_notify(unsigned char *packet)
{
	t_WIFI_GLOBAL* pl_wg = MC_WIFI_GLOBAL_PTR();
	int ret;
	md5_context md5;
  	unsigned char tmp_16_md5[16];
	unsigned char temp_8_md5[8];
	unsigned char temp_json[300] = {0};
	sprintf(temp_json, "{\"Hcmd\":1,\"DID\":\"%s\",\"RID\":%d,\"PLVer\":\"%s\",\"CInfo\":\"%s\",\"HType\":0,\"ConnPort\":%d,\"HState\":1,\"ExtData\":0,\"DevList\":[{\"DevId\":\"%s\",\"DevType\":%d}]}", pl_wg->wifi_id, RID, PLVer, pl_wg->v_cinfo_version, ConnPort,pl_wg->wifi_id, pl_wg->v_device_type);
	sprintf(packet, "HS%s", temp_json);
	md5_starts(&md5);
    md5_update(&md5, temp_json, strlen(temp_json));
    md5_finish(&md5, tmp_16_md5);
	memcpy(temp_8_md5, &tmp_16_md5[4], 8);
	sprintf(tmp_16_md5, "%02x%02x%02x%02x%02x%02x%02x%02x", temp_8_md5[0],temp_8_md5[1],temp_8_md5[2],temp_8_md5[3],temp_8_md5[4],temp_8_md5[5],temp_8_md5[6],temp_8_md5[7]);
	sprintf(packet + strlen(packet), "%s", tmp_16_md5);
	return strlen(packet);
}



void translate_to_hex_bssid(char *buff, int buff_len, unsigned char *temp_buff)
{
	char hi_part;
	char lo_part;

	hi_part = char_to_hex(buff[0]);
	lo_part = char_to_hex(buff[1]);
	temp_buff[0] =  (hi_part << 4) | lo_part;

	hi_part = char_to_hex(buff[3]);
	lo_part = char_to_hex(buff[4]);
	temp_buff[1] =  (hi_part << 4) | lo_part;

	hi_part = char_to_hex(buff[6]);
	lo_part = char_to_hex(buff[7]);
	temp_buff[2] =  (hi_part << 4) | lo_part;

	hi_part = char_to_hex(buff[9]);
	lo_part = char_to_hex(buff[10]);
	temp_buff[3] =  (hi_part << 4) | lo_part;

	hi_part = char_to_hex(buff[12]);
	lo_part = char_to_hex(buff[13]);
	temp_buff[4] =  (hi_part << 4) | lo_part;

	hi_part = char_to_hex(buff[15]);
	lo_part = char_to_hex(buff[16]);
	temp_buff[5] =  (hi_part << 4) | lo_part;
}

int router_info_get(unsigned char *data, int flag)
{
	t_WIFI_GLOBAL* pl_wg = MC_WIFI_GLOBAL_PTR();
  	int ret;
	int pos = data[2];
	unsigned char bssid[17] = {0};
	unsigned char bssid_len = 17;
	unsigned char vl_pwd_len = 0;

	memset(&pl_wg->v_wg_wifi_setting, 0, sizeof(pl_wg->v_wg_wifi_setting));
	
	memcpy(bssid, &data[4], bssid_len);
	vl_pwd_len = data[21];
	if (vl_pwd_len > 64)
	{
		printf("passwd(%d) > 64\n", vl_pwd_len);
		bapi_set_reboot_flag(20);
		return -1;
	}
		
	translate_to_hex_bssid(bssid, 17, pl_wg->v_wg_wifi_setting.ssid);
	WAPI_DUMP_HEX(pl_wg->v_wg_wifi_setting.ssid, 6, "BSSID:");
	if(vl_pwd_len > 0)
	{
		memcpy(pl_wg->v_wg_wifi_setting.password, &data[22], vl_pwd_len);
		printf("router passwd:%s\n", pl_wg->v_wg_wifi_setting.password);
	}

	return 0;
}

int router_info_get_ex(unsigned char *data, int flag)
{
	t_WIFI_GLOBAL* pl_wg = MC_WIFI_GLOBAL_PTR();
  	int ret;
	unsigned char vl_ssid_len = 0;
	unsigned char vl_pwd_len = 0;
	unsigned char vl_ssid_pos = 0;
	
	router_info_get(data, 0);

	vl_pwd_len = data[21];
	vl_ssid_len = data[21 + vl_pwd_len];
	vl_ssid_pos = 21 + vl_pwd_len +1;

	memset(pl_wg->a_router_ssid, 0, sizeof(pl_wg->a_router_ssid));
	memcpy(pl_wg->a_router_ssid, &data[vl_ssid_pos], vl_ssid_len);

	printf("router ssid:%s\n", pl_wg->a_router_ssid);
	printf("router passwd:%s\n", pl_wg->v_wg_wifi_setting.password);

	return 0;
}



int router_info_save2flash()
{
	t_WIFI_GLOBAL* pl_wg = MC_WIFI_GLOBAL_PTR();
	t_CONFIG_TABLE_BODY* pl_cfg = MC_WG_CONFIG_TABLE_PTR();

	WAPI_DUMP_HEX(pl_wg->v_wg_wifi_setting.ssid, 6, "BSSID1:");
	printf("router passwd1:%s\n", pl_wg->v_wg_wifi_setting.password);
	
	unsigned char vl_pwd_len = strlen(pl_wg->v_wg_wifi_setting.password);
	if(vl_pwd_len > 0)
	{		
		pl_wg->v_wg_wifi_setting.security_type = RTW_SECURITY_WPA2_AES_PSK;
	}
	else if(vl_pwd_len == 0)
	{
		pl_wg->v_wg_wifi_setting.security_type = RTW_SECURITY_OPEN;
	}

	pl_wg->v_wg_wifi_setting.key_idx = 1;
	
	memcpy(&pl_cfg->v_wifi_setting, &pl_wg->v_wg_wifi_setting, sizeof(pl_wg->v_wg_wifi_setting));
	pl_cfg->v_cur_mode = WIFI_MODE_STA;
	pl_cfg->v_router_info_flag = BAPI_CONFIG_FLAG;

	printf("Save router info to flash\n");
	
	bapi_set_write_config_flag();
	return 0;
}

int hsn_get_router_info(unsigned char *pp_data, unsigned char vp_data_len)
{
	int ret = 0;
	int vl_offset = pp_data[2];
	unsigned char vl_checksum = pp_data[vp_data_len-1];
	if ((vl_offset >=1) && (vl_offset <=7))
	{
		uint8 ch = hsn_checkSum(pp_data, vp_data_len - 1);
		if (ch == vl_checksum)
		{
			hex_2_bit(&pp_data[3], (unsigned int)(vp_data_len - 3), vl_offset);
			printf("switch data: \n");
			print_hex(pp_data, vp_data_len);
			ret = router_info_get(pp_data, 0);
		}
		else
		{
			printf("check sum ch is:%2x != %2x\n", ch, vl_checksum);
			goto EXIT;
		}
	}
	else
	{
		printf("KeyType invalid:%d\n", vl_offset);
		goto EXIT;
	}
	
	return ret;

EXIT:
	return -1;

}


int hsn_get_router_info_ex(unsigned char *pp_data, unsigned char vp_data_len)
{
	int ret = 0;
	int vl_offset = pp_data[2];
	unsigned char vl_checksum = pp_data[vp_data_len-1];
	if ((vl_offset >=1) && (vl_offset <=7))
	{
		uint8 ch = hsn_checkSum(pp_data, vp_data_len - 1);
		if (ch == vl_checksum)
		{
			hex_2_bit(&pp_data[3], (unsigned int)(vp_data_len - 3), vl_offset);
			printf("switch data: \n");
			print_hex(pp_data, vp_data_len);
			ret = router_info_get_ex(pp_data, 0);
		}
		else
		{
			printf("check sum ch is:%2x != %2x\n", ch, vl_checksum);
			goto EXIT;
		}
	}
	else
	{
		printf("KeyType invalid:%d\n", vl_offset);
		goto EXIT;
	}
	
	return ret;

EXIT:
	return -1;

}



int lan_cmd_0x03_ack(unsigned int socket)
{
	t_WIFI_GLOBAL* pl_wg = MC_WIFI_GLOBAL_PTR();
	int ret;
	unsigned char *tdata;
	md5_context md5;
  	unsigned char tmp_16_md5[16];
	unsigned char temp_8_md5[8];
	unsigned char temp_json[128];
	unsigned char key_json_str[160];
	memset(temp_json, 0, 128);
	tdata = malloc(150);
	if(tdata == NULL)
	{
		log_printf_w("[%s]malloc error\n",__FUNCTION__);
		return 0;
	}
	sprintf(temp_json, "{\"Hcmd\":3,\"Err\":0,\"ExtData\":\"%s\"}", pl_wg->wifi_id_base64);
	sprintf(tdata, "HS%s", temp_json);
	md5_starts(&md5);
    md5_update(&md5, temp_json, strlen(temp_json));
    md5_finish(&md5, tmp_16_md5);
	memcpy(temp_8_md5, &tmp_16_md5[4], 8);
	sprintf(tmp_16_md5, "%02x%02x%02x%02x%02x%02x%02x%02x%s", temp_8_md5[0],temp_8_md5[1],temp_8_md5[2],temp_8_md5[3],temp_8_md5[4],temp_8_md5[5],temp_8_md5[6],temp_8_md5[7],"\r\n");
	sprintf(tdata + strlen(tdata), "%s", tmp_16_md5);
	ret = send(tcp_server_socket, tdata, strlen(tdata), 0);
    if(ret >= 0)
    {
		printf("cloud send packet:%s, length:%d\n", tdata, strlen(tdata));
    	free(tdata);
    	return 1;
    }
	else
	{
		printf("cloud send packet error,%d\n",__LINE__);
    	free(tdata);
		return 0;
	}
}


void lan_cmd_0x03_handle(unsigned char *json_str, unsigned int socket_fd)
{
	int offset = 0;
	int len;
	unsigned char buffer[80] = {0};
	cJSON *IOTJSObject,*json_hconfig;
	tcp_server_socket = socket_fd;
	if((IOTJSObject = cJSON_Parse(json_str)) != NULL) 
	{
		json_hconfig = cJSON_GetObjectItem(IOTJSObject, "CData");
		if(json_hconfig) 
		{
			char *hconfig = cJSON_GetObjectItem(IOTJSObject, "CData")->valuestring;
			if(xt_mbedtls_base64_decode( buffer, sizeof(buffer), &len, hconfig, strlen(hconfig) ) != 0 )
			{
				printf("decode error\n");
			}
			else
			{
				print_hex(buffer, len);
				offset = buffer[2];
				printf("switch offset: %d\n", offset);
				uint8 vl_checksum = buffer[len - 1];
				if ((offset >=1) && (offset <=7))
				{
					uint8 ch = hsn_checkSum(buffer, len - 1);
					if (ch == vl_checksum)
					{
						hex_2_bit(&buffer[3], len - 4, offset);
						printf("switch data: \n");
						print_hex(buffer, len);
						int ret = router_info_get(buffer, 1);
						if (0 == ret)
						{
							lan_cmd_0x03_ack(tcp_server_socket);
							router_info_save2flash();
							bapi_set_reboot_flag(6);
						}
						else
						{
							printf("lan get router fail\n");
						}
					}
				}					
			}	
		}
	}
    cJSON_Delete(IOTJSObject);
}

void lan_cmd_0x02_handle(unsigned char *json_str, unsigned int socket_fd)
{
	int ret;
	int offset = 0;
	int len;
	//unsigned char buffer[80] = {0};
	unsigned char packet[256] = {0};
	cJSON *IOTJSObject,*json_hconfig;
	if((IOTJSObject = cJSON_Parse(json_str)) != NULL) 
	{
		json_hconfig = cJSON_GetObjectItem(IOTJSObject, "HConfig");
		if(json_hconfig) 
		{
			char *hconfig = cJSON_GetObjectItem(IOTJSObject, "HConfig")->valuestring;
			if(hconfig != NULL)
			{
				ret = bc_wifi_msg_packet_build(packet);
				if(ret > 0)
				{
					ret = sendto(udp_socket_fd, packet, ret, 0, (struct sockaddr*)&from_addr, sizeof(struct sockaddr));
					if(ret >= 0)
					{
						//printf("LAN send: %s %s, length:%d\n", inet_ntoa(from_addr.sin_addr), packet, strlen(packet));
						printf("LAN send: %s\n", inet_ntoa(from_addr.sin_addr));
					}
				}
			}	
		}
	}
	cJSON_Delete(IOTJSObject);
}

void lan_cmd_0x09_handle(unsigned char *json_str, unsigned int socket_fd)
{
	wapi_send_tcpsend_msg(LAN_LOGOUT, NULL, 0, NULL);
}

#ifdef HSN_UPDATE_20210926

void lan_cmd_4_handle(unsigned char *json_str, unsigned int socket_fd)
{
	printf("lan_cmd_4_handle\n");
}


void lan_cmd_15_handle(unsigned char *json_str, unsigned int socket_fd)
{
	printf("lan_cmd_15_handle\n");
}

void lan_cmd_17_handle(unsigned char *json_str, unsigned int socket_fd)
{
	printf("lan_cmd_17_handle\n");
}

#endif


int json_lan_packet_parse(unsigned char *json_str, unsigned int socket_fd)
{
	cJSON *IOTJSObject, *json_hcmd,*json_hconfig;
	if((IOTJSObject = cJSON_Parse(json_str)) != NULL) 
	{
		json_hcmd = cJSON_GetObjectItem(IOTJSObject, "Hcmd");
		if(json_hcmd) 
		{
			int cmd = json_hcmd->valueint;
			if(cmd == 0x03)
			{
				lan_cmd_0x03_handle(json_str, socket_fd);
			}
			else if(cmd == 0x02)
			{
				lan_cmd_0x02_handle(json_str, socket_fd);
			}
			else if(cmd == 0x09)
			{
				lan_cmd_0x09_handle(json_str, socket_fd);
			}
#ifdef HSN_UPDATE_20210926
			else if(cmd == 4)
			{//router info
				lan_cmd_4_handle(json_str, socket_fd);
			}
			else if(cmd == 15)
			{//get ap list
				lan_cmd_15_handle(json_str, socket_fd);
			}
			else if(cmd == 17)
			{//control
				lan_cmd_17_handle(json_str, socket_fd);
			}
#endif
			else
			{
				printf("unknow Hcmd:%d\n", cmd);
			}
		}
	}
	cJSON_Delete(IOTJSObject);
    return 0;
}

void lan_net_data_parse(unsigned char *data, unsigned int data_len, unsigned int socket_fd)
{
	unsigned char *temp_json;
	unsigned int temp_json_len = data_len - sizeof("HS") - PACKET_MD5_LEN - strlen("\r\n");
	temp_json = malloc(temp_json_len);
	if(temp_json == NULL)
	{
		log_printf_w("[%s]malloc error\n",__FUNCTION__);
		return;
	}
	memcpy(temp_json, &data[2], temp_json_len);

	json_lan_packet_parse(temp_json, socket_fd);
    free(temp_json);
}


int data2uart_decode(unsigned char *str, unsigned int str_len)
{
	int len;
	unsigned char *tx_data;
	unsigned char *buffer;
	buffer = malloc(256);
	if(buffer == NULL)
	{
		log_printf_w("[%s]malloc error\n",__FUNCTION__);
		return -1;
	}
	if(xt_mbedtls_base64_decode( buffer, 128, &len, str, str_len) != 0 )
	{
		log_printf_w("[%s]decode error\n",__FUNCTION__);
        free(buffer);
		return -1;
	}
	//WAPI_DUMP_HEX(buffer,len,"BASE64:");
	tx_data = malloc(128);
	if(tx_data == NULL)
	{
		log_printf_w("[%s]malloc error\n",__FUNCTION__);
        free(buffer);
		return -1;
	}
	if(0 == multibyte_aes_decode(tx_data, 128, &len, buffer, len))
	{
		//WAPI_DUMP_HEX(tx_data,len,"AES DECODE:");
		uart_data_send(tx_data, len);
	}
	free(tx_data);
	free(buffer);
	return 0;
}


void cloud_cmd_0x65_handle(unsigned char *json_str, unsigned int socket)
{
	t_WIFI_GLOBAL* pl_wg = MC_WIFI_GLOBAL_PTR();
	cJSON *IOTJSObject,*json_token;

	if((IOTJSObject = cJSON_Parse(json_str)) != NULL) 
	{
		json_token = cJSON_GetObjectItem(IOTJSObject, "token");
		if(json_token) 
		{
            memcpy(server_token, json_token->valuestring, strlen(json_token->valuestring) + 1);
			pl_wg->v_cloud_login_sta = HSN_LOGIN_STATE_REGISTER;
			device_aes_key_request(server_token, socket);
		}
	}
	cJSON_Delete(IOTJSObject);
}


void cloud_cmd_0x66_handle(unsigned char *json_str, unsigned int socket)
{
	int len;
	t_WIFI_GLOBAL* pl_wg = MC_WIFI_GLOBAL_PTR();
	unsigned char buffer[32] = {0};
	unsigned char temp_key_buff[16] = {0};
	cJSON *IOTJSObject,*json_key;

	if((IOTJSObject = cJSON_Parse(json_str)) != NULL) 
	{
		json_key = cJSON_GetObjectItem(IOTJSObject, "key");
		if(json_key) 
		{
			char *key = cJSON_GetObjectItem(IOTJSObject, "key")->valuestring;
			//printf("key: %s\n", key);
			if(xt_mbedtls_base64_decode( buffer, sizeof(buffer), &len, key, strlen(key) ) != 0 )
			{
				printf("decode error\n");
			}
			else
			{
				memcpy(temp_key_buff, buffer, sizeof(temp_key_buff));
				mbedtls_aes_context aes_ctx;
				mbedtls_aes_init(&aes_ctx);
				mbedtls_aes_setkey_dec(&aes_ctx, pl_wg->v_featurecode_aeskey, 128);
				mbedtls_aes_crypt_ecb(&aes_ctx, MBEDTLS_AES_DECRYPT, temp_key_buff, temp_key_buff);
				updata_aes_key(temp_key_buff);
				pl_wg->v_cloud_login_sta = HSN_LOGIN_STATE_DYNAMIC_KEY;
				device_system_param_request(socket);
			}
			//device_aes_key_request(token, socket);
		}
	}
	cJSON_Delete(IOTJSObject);
}

#define BCD2TODEC(bcd) (bcd) = (((bcd) & 0x0f)+ ((bcd)>>4)*10)
#define BIN2BCD(val) (unsigned char)(((val/10)<<4) + ((val)%10))

void hsn_calibrate_time()
{
	char al_buf[17] = {0};
	char al_time_string[32] = {0};
	t_WIFI_GLOBAL* pl_wg = MC_WIFI_GLOBAL_PTR();
	struct tm vl_tm;
	unsigned char vl_week = 0;
	struct tm * timeinfo;
	unsigned int vl_year = 0;
	unsigned char vl_month = 0;
	unsigned char vl_day = 0;


	time_t rawtime = pl_wg->v_time;
	timeinfo = localtime (&rawtime);
	memset(al_time_string, 0, sizeof(al_time_string));
	strftime (al_time_string, sizeof(al_time_string), "%Y-%m-%d %H:%M:%S", timeinfo);
	printf("GMT: %s\r\n", al_time_string);

	al_buf[9] = (unsigned char)((al_time_string[17] - '0')<<4) + (al_time_string[18] - '0');
	al_buf[10] = (unsigned char)((al_time_string[14] - '0')<<4) + (al_time_string[15] - '0');
	al_buf[11] = (unsigned char)((al_time_string[11] - '0')<<4) + (al_time_string[12] - '0');

	al_buf[13] = (unsigned char)((al_time_string[8] - '0')<<4) + (al_time_string[9] - '0');
	al_buf[14] = (unsigned char)((al_time_string[5] - '0')<<4) + (al_time_string[6] - '0');
	al_buf[15] = (unsigned char)((al_time_string[2] - '0')<<4) + (al_time_string[3] - '0');
	al_buf[16] = (unsigned char)((al_time_string[0] - '0')<<4) + (al_time_string[1] - '0');

	vl_year = ((al_buf[15]) & 0x0f)+ ((al_buf[15])>>4)*10 + ((al_buf[16]) & 0x0f)*100 + ((al_buf[16])>>4)*1000;
	vl_month = ((al_buf[14]) & 0x0f)+ ((al_buf[14])>>4)*10;
	vl_day = ((al_buf[13]) & 0x0f)+ ((al_buf[13])>>4)*10;
	vl_week = GetWeekDayNum_ex(vl_year, vl_month, vl_day);
	al_buf[12] = BIN2BCD(vl_week);
	

	UTCToBeijing(timeinfo);
	memset(al_time_string, 0, sizeof(al_time_string));
	strftime (al_time_string, sizeof(al_time_string), "%Y-%m-%d %H:%M:%S", timeinfo);
	printf("Beijing: %s\r\n", al_time_string);

	al_buf[0] = 0;
	al_buf[1] = (unsigned char)((al_time_string[17] - '0')<<4) + (al_time_string[18] - '0');
	al_buf[2] = (unsigned char)((al_time_string[14] - '0')<<4) + (al_time_string[15] - '0');
	al_buf[3] = (unsigned char)((al_time_string[11] - '0')<<4) + (al_time_string[12] - '0');
	
	//al_buf[4] = BIN2BCD(vl_week);
	
	al_buf[5] = (unsigned char)((al_time_string[8] - '0')<<4) + (al_time_string[9] - '0');
	al_buf[6] = (unsigned char)((al_time_string[5] - '0')<<4) + (al_time_string[6] - '0');
	al_buf[7] = (unsigned char)((al_time_string[2] - '0')<<4) + (al_time_string[3] - '0');
	al_buf[8] = (unsigned char)((al_time_string[0] - '0')<<4) + (al_time_string[1] - '0');

	vl_year = ((al_buf[7]) & 0x0f)+ ((al_buf[7])>>4)*10 + ((al_buf[8]) & 0x0f)*100 + ((al_buf[8])>>4)*1000;
	vl_month = ((al_buf[6]) & 0x0f)+ ((al_buf[6])>>4)*10;
	vl_day = ((al_buf[5]) & 0x0f)+ ((al_buf[5])>>4)*10;
	vl_week = GetWeekDayNum_ex(vl_year, vl_month, vl_day);
	al_buf[4] = BIN2BCD(vl_week);

	WAPI_DUMP_HEX(&al_buf[1],16,"TIME:");

	unsigned char *tdata;
	unsigned int tdata_len;
	tdata_len = PACKET_LEN_WITHOUT_MSGBODY + 16;
	tdata = malloc(tdata_len);
	if(tdata == NULL)
	{
		log_printf_w("[%s]malloc error\n",__FUNCTION__);
		return;
	}
	memset(tdata, 0, tdata_len);
	tdata_len = uart_packet_build(101, 32, &al_buf[1], 16, tdata, 0);
	uart_data_send(tdata, tdata_len);
	free(tdata);
}




void cloud_cmd_0x67_handle(unsigned char *json_str)
{
	t_WIFI_GLOBAL* pl_wg = MC_WIFI_GLOBAL_PTR();
	t_CONFIG_TABLE_BODY* pl_cfg = MC_WG_CONFIG_TABLE_PTR();
	int len;
	struct tm vl_tm;
	unsigned char buffer[32] = {0};
	unsigned char temp_key_buff[16] = {0};
	cJSON *IOTJSObject;     //整体
	cJSON *json_args;       //arg
	cJSON *json_array;      //获取数组
	cJSON *object;          //数组内的json串
	cJSON *json_hb, *json_rp, *json_retry;


	if((IOTJSObject = cJSON_Parse(json_str)) != NULL) 
	{
		json_array = cJSON_GetObjectItem(IOTJSObject, "args");
		if(json_array) 
		{
			int size = cJSON_GetArraySize(json_array);
			//printf("cJSON_GetArraySize: size = %d\n",size);
			for(int i = 0; i < size; i++)
			{
				object = cJSON_GetArrayItem(json_array,i);
				pl_wg->v_param_hb_time = cJSON_GetObjectItem(object, "hb")->valueint;
				pl_wg->v_param_rp_time = cJSON_GetObjectItem(object, "rp")->valueint;
				pl_wg->v_param_retry_time = cJSON_GetObjectItem(object, "retry")->valueint;
				pl_wg->v_time = cJSON_GetObjectItem(object, "time")->valueint;
				pl_wg->v_timezone = cJSON_GetObjectItem(object, "timezone")->valueint;
				
				printf("hb: %d, rp: %d, retry:%d\n", pl_wg->v_param_hb_time, pl_wg->v_param_rp_time, pl_wg->v_param_retry_time);
				printf("time:%d, timezone:%d\r\n", pl_wg->v_time, pl_wg->v_timezone);
				

				if (HSN_LOGIN_STATE_HB == pl_wg->v_cloud_login_sta)
				{
					hsn_calibrate_time();
				}
				else
				{
					printf("Login OK!\n");
					pl_wg->v_cloud_login_sta = HSN_LOGIN_STATE_SYSTEM_PARAM;
					pl_wg->v_cloud_login_sta = HSN_LOGIN_STATE_HB;
					
					pl_wg->v_cloud_reconnect_flag = 0;
					pl_wg->v_cloud_reconnect_cnt = 0;
					hsn_calibrate_time();
					vTaskDelay(100);
					vTaskDelay(100);

					wapi_send_net_msg(STATUS_CHECK, NULL, 0, NULL);
					
					//to do 查询状态，开启心跳定时器
					need_offline_flag = 1;			
					set_heartbeat_init(pl_wg->v_param_hb_time);
					//set_dataresp_timer_uninit();
					set_dataresp_timer_init(pl_wg->v_param_rp_time);
					hb_miss_times = 0;

					printf("connected serv, %d,%d\n", pl_wg->v_bt_sta, pl_wg->v_connect_router_from);
					if ((HSN_BT_STATE_STARTED == pl_wg->v_bt_sta) 
						&& (HSN_CONNECT_ROUTER_FROM_NETCONFIG == pl_wg->v_connect_router_from))
					{
						wapi_send_net_msg(HSN_BLE_CONFIG_STOP, NULL, 0, NULL);
						pl_wg->v_wifi_config_on = 0;
					}
				}

			}
		}
	}
	cJSON_Delete(IOTJSObject);
}


void cloud_cmd_0xca_handle(unsigned char *json_str)
{
	//t_CONFIG_TABLE_BODY* pl_cfg = MC_WG_CONFIG_TABLE_PTR();
	int len;
	cJSON *IOTJSObject,*json_seq;
	
	//bapi_set_write_config_flag();

	if((IOTJSObject = cJSON_Parse(json_str)) != NULL) 
	{
		json_seq = cJSON_GetObjectItem(IOTJSObject, "seq");
		if(json_seq) 
		{
			int cmd_seq = cJSON_GetObjectItem(IOTJSObject, "seq")->valueint;
			//printf("seq:%d\n", cmd_seq);
			set_net_packet_seq(202, cmd_seq);
			cmd_0x66_status_check();
		}
	}
	cJSON_Delete(IOTJSObject);
}

void cloud_cmd_0xc9_handle(unsigned char *json_str)
{
	int len;
	cJSON *IOTJSObject,*json_seq, *json_com;

	if((IOTJSObject = cJSON_Parse(json_str)) != NULL) 
	{
		json_seq = cJSON_GetObjectItem(IOTJSObject, "seq");
		if(json_seq) 
		{
			int cmd_seq = cJSON_GetObjectItem(IOTJSObject, "seq")->valueint;
			set_net_packet_seq(201, cmd_seq);
			//mcu_status_check();
		}
		json_com = cJSON_GetObjectItem(IOTJSObject, "com");
		if(json_com)
		{
			unsigned char *com_data = json_com->valuestring;
			//printf("N(201)->U: %s\n", com_data);
			
			if(data2uart_decode(com_data, strlen(com_data)) != 0)
			{
				printf("send error\n");
			}
			//mcu_status_check();
		}
	}
	cJSON_Delete(IOTJSObject);
}

void cloud_cmd_302_handle(unsigned char *json_str)
{
	int len;
	cJSON *IOTJSObject,*json_addr;

	if((IOTJSObject = cJSON_Parse(json_str)) != NULL) 
	{
		json_addr = cJSON_GetObjectItem(IOTJSObject, "addr");
		if(json_addr) 
		{
			char *addr = cJSON_GetObjectItem(IOTJSObject, "addr")->valuestring;
			ota_entry(addr);
			//printf("\n\nota addr: %s\n\n\n", addr);
			//set_wifi_connect_status_2(WIFI_UPDATE);
		}
	}
	cJSON_Delete(IOTJSObject);
}

void cloud_cmd_402_handle(unsigned char *json_str)
{
	t_CONFIG_TABLE_BODY* pl_cfg = MC_WG_CONFIG_TABLE_PTR();
	int len;
	cJSON *IOTJSObject,*json_err;

	if((IOTJSObject = cJSON_Parse(json_str)) != NULL) 
	{
		json_err = cJSON_GetObjectItem(IOTJSObject, "err");
		if(json_err) 
		{
			int err = cJSON_GetObjectItem(IOTJSObject, "err")->valueint;
			if(err == 0)
			{
				printf("device unbind ok\n");
				hsn_reset_config_table(0);
				bapi_set_write_config_flag();
				rlt_udp_offline_func_entry();
			}	
		}
	}
	cJSON_Delete(IOTJSObject);
}


int json_cloud_packet_parse(unsigned char *json_str, unsigned int socket)
{
	cJSON *IOTJSObject, *json_id;
	if((IOTJSObject = cJSON_Parse(json_str)) != NULL) 
	{
		json_id = cJSON_GetObjectItem(IOTJSObject, "id");
		if(json_id) 
		{
			int cmd_id = json_id->valueint;
			printf("N->:%d\n", cmd_id);
			if(cmd_id == 101)
			{//register
				//printf("get cmd 101\n");
				cloud_cmd_0x65_handle(json_str, socket);
			}

			else if(cmd_id == 102)
			{//dynamic aes key
				//printf("get cmd 102\n");
				cloud_cmd_0x66_handle(json_str, socket);
			}

			else if(cmd_id == 103)
			{//system param
				//printf("get cmd 103\n");
				cloud_cmd_0x67_handle(json_str);
			}
			
			else if(cmd_id == 202)
			{//get state
				//printf("get cmd: 202\n");
				cloud_cmd_0xca_handle(json_str);
				printf("Seq:%d\n", net_packet_info.msg_seq);
				
			}
			
			else if(cmd_id == 201)
			{//control
				//printf("get cmd: 201\n");
				cloud_cmd_0xc9_handle(json_str);
				printf("Seq:%d\n", net_packet_info.msg_seq);
			}

			else if(cmd_id == 302)
			{//ota update
				printf("Start OTA\n");
				cloud_cmd_302_handle(json_str);
			}

			else if(cmd_id == 402)
			{//unbind
				printf("serv unbind dev\n");
				cloud_cmd_402_handle(json_str);
			}

			else
			{
				printf("unknonw cmd_id: %d\n", cmd_id);
			}
		}
		else
		{
			printf("get id error\n");
		}
	}
	else
	{
		printf("json parse error\n");
	}
	cJSON_Delete(IOTJSObject);
    return 0;
}

void cloud_data_parse(unsigned char *data, int data_len, unsigned int socket_fd)
{
	t_WIFI_GLOBAL* pl_wg = MC_WIFI_GLOBAL_PTR();
	unsigned char *temp_json;
	if(data_len == 14)
	{
		set_hb_flag(1);
		pl_wg->v_cloud_login_sta = HSN_LOGIN_STATE_HB;
		printf("HB_RSP\n");
		return;
	}
	else if(data_len <= 0)
	{
		return;
	}
	unsigned int temp_json_len = data_len - sizeof("HS") - PACKET_MD5_LEN - strlen("\r\n") + 1;
	temp_json = malloc(temp_json_len);
	if(temp_json == NULL)
	{
		log_printf_w("[%s]malloc error\n",__FUNCTION__);
		return;
	}
	memcpy(temp_json, &data[2], temp_json_len);
	json_cloud_packet_parse(temp_json, socket_fd);
    free(temp_json);
}


int device_register_request(unsigned int socket)
{
	t_WIFI_GLOBAL* pl_wg = MC_WIFI_GLOBAL_PTR();
	int ret;

	md5_context md5;
  	unsigned char tmp_16_md5[16];
	unsigned char temp_8_md5[8];
	unsigned char temp_json[128];
	unsigned char key_json_str[160];
	memset(temp_json, 0, 128);
	memset(key_json_str, 0, 160);
	memset(gv_pakect_tmp_buf, 0, sizeof(gv_pakect_tmp_buf));

	sprintf(temp_json, "{\"id\":101,\"wid\":\"%s\",\"ver\":\"%s\",\"ProtVer\":\"215\"}", pl_wg->wifi_id, pl_wg->v_cinfo_version);
	sprintf(key_json_str, "%s%s", pl_wg->v_featurecode_aeskey, temp_json);
	sprintf(gv_pakect_tmp_buf, "HS%s", temp_json);
	md5_starts(&md5);
    md5_update(&md5, key_json_str, strlen(key_json_str));
    md5_finish(&md5, tmp_16_md5);
	
	memcpy(temp_8_md5, &tmp_16_md5[4], 8);
	
	sprintf(tmp_16_md5, "%02x%02x%02x%02x%02x%02x%02x%02x%s", temp_8_md5[0],temp_8_md5[1],temp_8_md5[2],temp_8_md5[3],temp_8_md5[4],temp_8_md5[5],temp_8_md5[6],temp_8_md5[7],"\r\n");
	
	sprintf(gv_pakect_tmp_buf + strlen(gv_pakect_tmp_buf), "%s", tmp_16_md5);
	
	
	ret = hsn_tcp_client_send(gv_pakect_tmp_buf, strlen(gv_pakect_tmp_buf));
	if(0 == ret)
    {
		printf("cloud register...\n");
    	return 1;
    }
	else
	{
		LOGW("send fail\n");
		return 0;
	}
	
}

int device_aes_key_request(unsigned char *token, unsigned int socket)
{
	int ret;
	t_WIFI_GLOBAL* pl_wg = MC_WIFI_GLOBAL_PTR();
	md5_context md5;
  	unsigned char tmp_16_md5[16];
	unsigned char temp_8_md5[8];
	unsigned char temp_json[128];
	unsigned char key_json_str[160];
	memset(temp_json, 0, 128);
	memset(key_json_str, 0, 160);
	memset(gv_pakect_tmp_buf, 0, sizeof(gv_pakect_tmp_buf));

	sprintf(temp_json, "{\"id\":102,\"token\":\"%s\"}", token);
	sprintf(key_json_str, "%s%s", pl_wg->v_featurecode_aeskey, temp_json);
	//printf("key_json_str: %s\n", key_json_str);
	sprintf(gv_pakect_tmp_buf, "HS%s", temp_json);
	md5_starts(&md5);
    md5_update(&md5, key_json_str, strlen(key_json_str));
    md5_finish(&md5, tmp_16_md5);
	memcpy(temp_8_md5, &tmp_16_md5[4], 8);
	sprintf(tmp_16_md5, "%02x%02x%02x%02x%02x%02x%02x%02x%s", temp_8_md5[0],temp_8_md5[1],temp_8_md5[2],temp_8_md5[3],temp_8_md5[4],temp_8_md5[5],temp_8_md5[6],temp_8_md5[7],"\r\n");
	sprintf(gv_pakect_tmp_buf + strlen(gv_pakect_tmp_buf), "%s", tmp_16_md5);

	ret = hsn_tcp_client_send(gv_pakect_tmp_buf, strlen(gv_pakect_tmp_buf));
	if(0 == ret)
    {
		printf("cloud get dynamic key...\n");
    	return 1;
    }
	else
	{
		LOGW("send fail\n");
		return 0;
	}
	
}

int device_system_param_request(unsigned int socket)
{
	int ret;
	t_WIFI_GLOBAL* pl_wg = MC_WIFI_GLOBAL_PTR();

	md5_context md5;
  	unsigned char tmp_16_md5[16];
	unsigned char temp_8_md5[8];
	unsigned char temp_json[128];
	unsigned char key_json_str[160];
	memset(temp_json, 0, 128);
	memset(key_json_str, 0, 160);
	memset(gv_pakect_tmp_buf, 0, sizeof(gv_pakect_tmp_buf));
	
	sprintf(temp_json, "{\"id\":103,\"token\":\"%s\"}", server_token);
	sprintf(key_json_str, "%s%s", pl_wg->v_featurecode_aeskey, temp_json);
	//printf("key_json_str: %s\n", key_json_str);
	sprintf(gv_pakect_tmp_buf, "HS%s", temp_json);
	md5_starts(&md5);
    md5_update(&md5, key_json_str, strlen(key_json_str));
    md5_finish(&md5, tmp_16_md5);
	memcpy(temp_8_md5, &tmp_16_md5[4], 8);
	sprintf(tmp_16_md5, "%02x%02x%02x%02x%02x%02x%02x%02x%s", temp_8_md5[0],temp_8_md5[1],temp_8_md5[2],temp_8_md5[3],temp_8_md5[4],temp_8_md5[5],temp_8_md5[6],temp_8_md5[7],"\r\n");
	sprintf(gv_pakect_tmp_buf + strlen(gv_pakect_tmp_buf), "%s", tmp_16_md5);

	ret = hsn_tcp_client_send(gv_pakect_tmp_buf, strlen(gv_pakect_tmp_buf));
	if(0 == ret)
    {
		printf("cloud get system param...\n");
    	return 1;
    }
	else
	{
		LOGW("send fail\n");
		return 0;
	}
	
}

void set_hb_flag(int flag)
{
	hb_flag = flag;
}

int hb_request()
{
	int ret;
	unsigned char temp_json[20];
	memset(temp_json, 0, 20);
	unsigned char al_data[32] = {0};
	memset(al_data, 0, sizeof(al_data));
	
	sprintf(temp_json, "{\"id\":902}");
	sprintf(al_data, "HS%s%s", temp_json, "\r\n");

	ret = hsn_tcp_client_send(al_data, strlen(al_data));
	if(0 == ret)
    {
    	printf("HB_REQ\n");
		//printf("cloud send packet:%s, length:%d\n", tdata, strlen(tdata));
    	return 1;
    }
	else
	{
		LOGW("send fail\n");
		return 0;
	}
}

int hsn_tcp_client_send(char *pl_data, int vp_data_len)
{
	int ret = 0;
	if (tcp_socket_fd >= 0)
	{
		ret = send(tcp_socket_fd, pl_data, vp_data_len, 0);
		if(ret >= 0)
	    {
#if (HSN_DEBUG_NET==1)
			printf("%s\n",pl_data);
#endif
	    	ret = 0;
	    }
		else
		{
			printf("tcp_socket_fd send err:%d\n", ret);
			ret = -1;
		}
	}
	else
	{
		printf("tcp_socket_fd err:%d\n", tcp_socket_fd);
		ret = -1;
	}
	return ret;
		
}

extern unsigned char wifi_router_connect_status;
void heartbeat_handle(xTimerHandle pxTimer)
{
	t_WIFI_GLOBAL* pl_wg = MC_WIFI_GLOBAL_PTR();
	if(hb_flag == 1)
	{
		hb_miss_times = 0;
	}
	else
	{
		hb_miss_times++;
		if(hb_miss_times > 3)
		{
			pl_wg->v_cloud_login_sta = HSN_LOGIN_STATE_DISCONNET;
			printf("HB timeout, cloud disconnect,%d\n",__LINE__);
			set_heartbeat_uninit();
			pl_wg->v_cloud_reconnect_flag = 1;
			pl_wg->v_cloud_reconnect_cnt = 0;
		}
	}
	set_hb_flag(0);
	if (HSN_LOGIN_STATE_HB == pl_wg->v_cloud_login_sta)
	{
		hb_request();
	}
}

int set_heartbeat_init(unsigned int vp_hb_time)
{
	heartbeat_timer = xTimerCreate("heart beat", vp_hb_time * 1000, pdTRUE, NULL, heartbeat_handle);
	xTimerStart(heartbeat_timer, 0);
	return 1;
}

int set_heartbeat_uninit()
{
	if (heartbeat_timer != NULL)
	{
		xTimerStop(heartbeat_timer, 0);
		xTimerDelete(heartbeat_timer, 0);
		heartbeat_timer = NULL;			
	}
	return 1;
}


void dataresp_handle(xTimerHandle pxTimer)
{
	mcu_status_check();
}

int set_dataresp_timer_init(unsigned int vp_rp_time)
{
	dataresp_timer = xTimerCreate("data handle", vp_rp_time * 1000, pdTRUE, NULL, dataresp_handle);
	xTimerStart(dataresp_timer, 0);
	return 1;
}

int set_dataresp_timer_uninit()
{
	if (dataresp_timer != NULL)
	{
		xTimerStop(dataresp_timer, 0);
		xTimerDelete(dataresp_timer, 0);
		dataresp_timer = NULL;			
	}
	return 1;
}


void data_uart2net_handle(unsigned char *data, unsigned int data_len)
{
	t_WIFI_GLOBAL* pl_wg = MC_WIFI_GLOBAL_PTR();
	int len;
	int ret;
	int msg_type = 102;//data[13];
	unsigned char *tdata;
	unsigned char *data_base64;
	unsigned char *msg_data_1e_base64;
	md5_context md5;
  	unsigned char tmp_16_md5[16];
	unsigned char temp_8_md5[8];
	unsigned char temp_json[320];
	unsigned char key_json_str[400];
	memset(temp_json, 0, 320);
	memset(key_json_str, 0, 400);
	
	tdata = malloc(512);
	if(tdata == NULL)
	{
		log_printf_w("[%s]malloc error\n",__FUNCTION__);
		return;
	}

	data_base64 = malloc(160);
	if(data_base64 == NULL)
	{
		log_printf_w("[%s]malloc error\n",__FUNCTION__);
        free(tdata);
		return;
	}
	//print_hex(msg_data_1e, 8);
	msg_data_1e_base64 = malloc(16);
	if(msg_data_1e_base64 == NULL)
	{
		log_printf_w("[%s]malloc error\n",__FUNCTION__);
        free(tdata);
        free(data_base64);
		return;
	}
	
	memset(data_base64, 0, 160);
	memset(msg_data_1e_base64, 0, 16);
	msg_data_1e[1] = msg_data_1e[1] | 0x01;

	ret = mbedtls_base64_encode_x(data_base64, 160, &len, data,data_len);
	ret = mbedtls_base64_encode_x(msg_data_1e_base64, 16, &len, msg_data_1e,8);
	//sprintf(temp_json, "{\"id\":%d,\"token\":\"%s\", \"seq\":%d, \"err\":0, \"status\":[{\"msgtype\":%d, \"msgsubtype\":0,\"result\":\"%s\"}]}" ,net_packet_info.msg_type, server_token, net_packet_info.msg_seq,msg_type, data_base64);
	sprintf(temp_json, "{\"id\":%d,\"token\":\"%s\",\"seq\":%d,\"err\":0,\"status\":[{\"msgtype\":30,\"msgsubtype\":0,\"result\":\"%s\"}, {\"msgtype\":%d,\"msgsubtype\":0,\"result\":\"%s\"}]}" ,net_packet_info.msg_type, server_token, net_packet_info.msg_seq,msg_data_1e_base64,msg_type, data_base64);
	sprintf(key_json_str, "%s%s", pl_wg->v_featurecode_aeskey, temp_json);
	sprintf(tdata, "HS%s", temp_json);
	md5_starts(&md5);
    md5_update(&md5, key_json_str, strlen(key_json_str));
    md5_finish(&md5, tmp_16_md5);
	memcpy(temp_8_md5, &tmp_16_md5[4], 8);
	sprintf(tmp_16_md5, "%02x%02x%02x%02x%02x%02x%02x%02x%s", temp_8_md5[0],temp_8_md5[1],temp_8_md5[2],temp_8_md5[3],temp_8_md5[4],temp_8_md5[5],temp_8_md5[6],temp_8_md5[7],"\r\n");
	sprintf(tdata + strlen(tdata), "%s", tmp_16_md5);

	ret = hsn_tcp_client_send(tdata, strlen(tdata));
	if(0 == ret)
    {
    	printf("U->N:%d, seq:%d\n", net_packet_info.msg_type, net_packet_info.msg_seq);
		//printf("%s, length:%d\n", tdata, strlen(tdata));
    }
	else
	{
		LOGW("send fail\n");
	}

	free(msg_data_1e_base64);
	free(data_base64);
	free(tdata);
	
}


int device_ask_unbind_to_net()
{
	int ret;
	t_WIFI_GLOBAL* pl_wg = MC_WIFI_GLOBAL_PTR();
	md5_context md5;
  	unsigned char tmp_16_md5[16];
	unsigned char temp_8_md5[8];
	unsigned char temp_json[128];
	unsigned char key_json_str[160];
	memset(temp_json, 0, 128);
	memset(key_json_str, 0, 160);
	memset(gv_pakect_tmp_buf, 0, sizeof(gv_pakect_tmp_buf));

	sprintf(temp_json, "{\"id\":402,\"token\":\"%s\"}", server_token);
	sprintf(key_json_str, "%s%s", pl_wg->v_featurecode_aeskey, temp_json);
	printf("key_json_str: %s\n", key_json_str);
	sprintf(gv_pakect_tmp_buf, "HS%s", temp_json);
	md5_starts(&md5);
    md5_update(&md5, key_json_str, strlen(key_json_str));
    md5_finish(&md5, tmp_16_md5);
	memcpy(temp_8_md5, &tmp_16_md5[4], 8);
	sprintf(tmp_16_md5, "%02x%02x%02x%02x%02x%02x%02x%02x%s", temp_8_md5[0],temp_8_md5[1],temp_8_md5[2],temp_8_md5[3],temp_8_md5[4],temp_8_md5[5],temp_8_md5[6],temp_8_md5[7],"\r\n");
	sprintf(gv_pakect_tmp_buf + strlen(gv_pakect_tmp_buf), "%s", tmp_16_md5);

	ret = hsn_tcp_client_send(gv_pakect_tmp_buf, strlen(gv_pakect_tmp_buf));
	if(0 == ret)
    {
    	printf("REQ unbind dev:%s, length:%d\n", gv_pakect_tmp_buf, strlen(gv_pakect_tmp_buf));
		//printf("cloud send packet:%s, length:%d\n", tdata, strlen(tdata));
    	return 1;
    }
	else
	{
		LOGW("send fail\n");
		return 0;
	}
}





#if 0

void test_time_to_date()
{
	unsigned int time = 0;
	unsigned int time2 = 0;
	long i = 0;
	struct tm t;
	//2018-01-01 01:01:01
	time = 1514768461;
	// 验证一个周期4年 一天打印一次
	for(i=0;i<(4*365+1);i++)
	{
		localtime(time,&t);
		printf("A time:%d\r\n",time);
		printf("A %04d-%02d-%02d %02d:%02d:%02d\r\n",t.tm_year,t.tm_mon+1,t.tm_mday,t.tm_hour,t.tm_min,t.tm_sec);

		t.tm_mon+=1;	//转换时月份需要加1，因为月份是从0开始的
		time2 = mktime(t);	//将localtime得到年月日时分秒再次转换成时间戳，验证算法是否正确
		printf("B time:%d\r\n",time2);
		memset((void*)&t,0x00,sizeof(t));
		localtime(time2,&t);
		printf("B %04d-%02d-%02d %02d:%02d:%02d\r\n",t.tm_year,t.tm_mon+1,t.tm_mday,t.tm_hour,t.tm_min,t.tm_sec);
		memset((void*)&t,0x00,sizeof(t));
		time += 24*3600;
	}

	return;
}

#endif


