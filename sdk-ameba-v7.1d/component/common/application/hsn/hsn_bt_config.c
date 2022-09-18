#include "hsn_common.h"


static unsigned short gv_tag = 0;
static unsigned char gp_bt_config_tmp_buf[255] = {0};
static unsigned short gp_bt_config_tmp_buf_len = 0;

#ifdef HSN_UPDATE_20210924


static xTaskHandle s_hsn_scan_ssid_task_handle = NULL;
static t_HSN_BT_CONFIG_AP_INFO sa_btconfig_ap_info[HSN_BT_CONFIG_AP_INFO_MAX_SIZE];
static unsigned char sv_ap_num_in = 0;
static unsigned char sv_ap_num_out = 0;
static eHSN_BTCONFIG_SCAN_STATE sv_btconfig_scan_state = HSN_BTCONFIG_SCAN_STATE_IDLE;

static unsigned char sv_remainder = 0;
static unsigned char sv_arrangement = 0;


int hsn_btconfig_scan_ssid_start(void);


#endif





extern int sniffer_config_finish;



unsigned short hsn_ble_config_tlv_packet(unsigned short vp_tag, unsigned char* pp_value, unsigned short vp_value_len, unsigned char* pp_out_packet)
{
	unsigned short vl_tag = vp_tag | 0x8000;

	unsigned char vl_tag0 = vl_tag >> 8;
	unsigned char vl_tag1 = vl_tag;

	unsigned char vl_len2 = vp_value_len >> 8;
	unsigned char vl_len3 = vp_value_len;

	pp_out_packet[0] = vl_tag0;
	pp_out_packet[1] = vl_tag1;
	pp_out_packet[2] = vl_len2;
	pp_out_packet[3] = vl_len3;
	if (NULL != pp_value)
		memcpy(pp_out_packet + 4, pp_value, vp_value_len);

	return vp_value_len + 4;
}




//0001
void hsn_bt_cmd_scan(unsigned short vp_tag, unsigned char* pp_value, int pv_value_len)
{
	if ((1 == pv_value_len) && (0 == pp_value[0]))
	{
		gv_tag = vp_tag;
#ifdef HSN_UPDATE_20210924
		hsn_btconfig_scan_ssid_start();
#endif

	}
	else
	{
		gv_tag = 0;
		printf("bt cmd invalid len:%d\n", pv_value_len);
	}

	
}

//8001
void hsn_bt_cmd_scan_reply(unsigned char *pp_out_data, unsigned int *pv_data_len, unsigned short read_offset)
{
#ifdef HSN_UPDATE_20210924

	if (HSN_BTCONFIG_SCAN_STATE_SCANNING == sv_btconfig_scan_state)
	{
		unsigned char al_sta[4] = {0xFF};
		memset(al_sta, 0xFF, 4);
		
		*pv_data_len = hsn_ble_config_tlv_packet(gv_tag, al_sta, 4, pp_out_data);
	}
	else
	{
		if (sv_arrangement > 0) 
		{
			gp_bt_config_tmp_buf[0] = sv_ap_num_in;
			gp_bt_config_tmp_buf[1] = HSN_BTCONFIG_MAX_APNUM_FOR_ONETIME;
			memcpy(&gp_bt_config_tmp_buf[2], (unsigned char*)(sa_btconfig_ap_info + sv_ap_num_out), HSN_BTCONFIG_MAX_APNUM_FOR_ONETIME*sizeof(t_HSN_BT_CONFIG_AP_INFO));
			gp_bt_config_tmp_buf_len = 2 + HSN_BTCONFIG_MAX_APNUM_FOR_ONETIME*sizeof(t_HSN_BT_CONFIG_AP_INFO);
			sv_ap_num_out += HSN_BTCONFIG_MAX_APNUM_FOR_ONETIME;
			sv_arrangement--;
			*pv_data_len = hsn_ble_config_tlv_packet(gv_tag, gp_bt_config_tmp_buf, gp_bt_config_tmp_buf_len, pp_out_data);
		}
		else
		{
			if ((sv_remainder > 0) && (sv_remainder < HSN_BTCONFIG_MAX_APNUM_FOR_ONETIME))
			{
				gp_bt_config_tmp_buf[0] = sv_ap_num_in;
				gp_bt_config_tmp_buf[1] = sv_remainder;
				memcpy(&gp_bt_config_tmp_buf[2], (unsigned char*)(sa_btconfig_ap_info + sv_ap_num_out), sv_remainder*sizeof(t_HSN_BT_CONFIG_AP_INFO));
				
				gp_bt_config_tmp_buf_len = 2 + sv_remainder*sizeof(t_HSN_BT_CONFIG_AP_INFO);
				sv_ap_num_out = 0;
				sv_remainder = 0;
				*pv_data_len = hsn_ble_config_tlv_packet(gv_tag, gp_bt_config_tmp_buf, gp_bt_config_tmp_buf_len, pp_out_data);
			}
			else 
			{
				*pv_data_len = hsn_ble_config_tlv_packet(gv_tag, NULL, 0, pp_out_data);
			}
		}
	}
#else
	unsigned char vl_band = HSN_BT_CONFIG_WIFI_BAND_24G;
	*pv_data_len = hsn_ble_config_tlv_packet(gv_tag, &vl_band, 1, pp_out_data);

#endif

}

///////////////////////////
//0002
void hsn_bt_cmd_connect(unsigned short vp_tag, unsigned char* pp_value, int pv_value_len)
{
    int ret = 0;
	if (pv_value_len < 255)
	{
		gv_tag = vp_tag;
		memcpy(gp_bt_config_tmp_buf, pp_value, pv_value_len);
		gp_bt_config_tmp_buf_len = (unsigned short)pv_value_len;

		ret = hsn_get_router_info(pp_value, pv_value_len);
		if (0 == ret)
		{
			//router_info_save2flash();
			//bapi_set_reboot_flag(56);
			wapi_send_net_msg(CONNECT_ROUTER, NULL, 0, NULL);
		}	
		else
		{
			printf("bt config fail...\n");
			bapi_set_reboot_flag(32);
		}
	}
	else
	{
		gv_tag = 0;
		printf("bt cmd invalid len:%d\n", pv_value_len);
	}	
}

//8002
void hsn_bt_cmd_connect_reply(unsigned char *pp_out_data, unsigned int *pv_data_len, unsigned short read_offset)
{
    if(gp_bt_config_tmp_buf_len > 0)
    {
		*pv_data_len = hsn_ble_config_tlv_packet(gv_tag, gp_bt_config_tmp_buf, gp_bt_config_tmp_buf_len, pp_out_data);
		//gp_bt_config_tmp_buf_len = 0;
	}
	else
    {
		printf("[%s]malloc error\n",__FUNCTION__);
		return;
	}	
}

///////////////////////////
//0003
void hsn_bt_cmd_status(unsigned short vp_tag, unsigned char* pp_value, int pv_value_len)
{
	if ((1 == pv_value_len) && (0 == pp_value[0]))
	{
		gv_tag = vp_tag;
	}
	else
	{
		gv_tag = 0;
		printf("bt cmd invalid len:%d\n", pv_value_len);
	}
}

//8003
void hsn_bt_cmd_status_reply(unsigned char *pp_out_data, unsigned int *pv_data_len, unsigned short read_offset)
{
	t_WIFI_GLOBAL* pl_wg = MC_WIFI_GLOBAL_PTR();
	t_CONFIG_TABLE_BODY* pl_cfg = MC_WG_CONFIG_TABLE_PTR();
	unsigned char al_sta[2] = {0};

	al_sta[0] = HSN_WIFI_STATE_DISABLED;
	al_sta[1] = HSN_CLOUD_STATE_DISABLED;

	if (WIFI_MODE_STA == pl_cfg->v_cur_mode)
	{
		if (HSN_ROUTER_STATE_DISCONNET == pl_wg->v_router_sta)
		{
			
		}
		else if (HSN_ROUTER_STATE_CONNECTED == pl_wg->v_router_sta)
		{
			al_sta[0] = HSN_WIFI_STATE_CONNECTED;
			
			if (HSN_LOGIN_STATE_DISCONNET == pl_wg->v_cloud_login_sta)
			{
				
			}
			else if (HSN_LOGIN_STATE_HB == pl_wg->v_cloud_login_sta)
			{
				al_sta[1] = HSN_CLOUD_STATE_CONNECTED;
			}
			else if (HSN_LOGIN_STATE_START_REGISTER == pl_wg->v_cloud_login_sta)
			{
				
			}
			else if (HSN_LOGIN_STATE_REGISTER == pl_wg->v_cloud_login_sta)
			{
				
			}
			else if (HSN_LOGIN_STATE_DYNAMIC_KEY == pl_wg->v_cloud_login_sta)
			{
				
			}
			else if (HSN_LOGIN_STATE_SYSTEM_PARAM == pl_wg->v_cloud_login_sta)
			{
				
			}
		}
		else if (HSN_ROUTER_STATE_CONNECTING == pl_wg->v_router_sta)
		{
			
		}
	}
		
	*pv_data_len = hsn_ble_config_tlv_packet(gv_tag, al_sta, 2, pp_out_data);
}
////////////////////////////////////


//0004
void hsn_bt_cmd_get_wlan_band(unsigned short vp_tag, unsigned char* pp_value, int pv_value_len)
{
	if ((1 == pv_value_len) && (0 == pp_value[0]))
	{
		gv_tag = vp_tag;
	}
	else
	{
		gv_tag = 0;
		printf("bt cmd invalid len:%d\n", pv_value_len);
	}
}

//8004
void hsn_bt_cmd_get_wlan_band_reply(unsigned char *pp_out_data, unsigned int *pv_data_len, unsigned short read_offset)
{
	unsigned char vl_band = HSN_BT_CONFIG_WIFI_BAND_24G;
	*pv_data_len = hsn_ble_config_tlv_packet(gv_tag, &vl_band, 1, pp_out_data);
}
///////////////////////////////////////

//0005
void hsn_bt_cmd_get_wifi_id(unsigned short vp_tag, unsigned char* pp_value, int pv_value_len)
{
	if ((1 == pv_value_len) && (0 == pp_value[0]))
	{
		gv_tag = vp_tag;
	}
	else
	{
		gv_tag = 0;
		printf("bt cmd invalid len:%d\n", pv_value_len);
	}	
}
//8005
void hsn_bt_cmd_get_wifi_id_reply(unsigned char *pp_out_data, unsigned int *pv_data_len, unsigned short read_offset)
{
	//wifi_id 
	t_WIFI_GLOBAL* pl_wg = MC_WIFI_GLOBAL_PTR();
	*pv_data_len = hsn_ble_config_tlv_packet(gv_tag, pl_wg->wifi_id, strlen((char*)pl_wg->wifi_id), pp_out_data);		
}


//////////////////////////////////////
//0006
void hsn_bt_cmd_get_dev_id(unsigned short vp_tag, unsigned char* pp_value, int pv_value_len)
{
	if ((1 == pv_value_len) && (0 == pp_value[0]))
	{
		gv_tag = vp_tag;
	}
	else
	{
		gv_tag = 0;
		printf("bt cmd invalid len:%d\n", pv_value_len);
	}
}


//8006

void hsn_bt_cmd_get_dev_id_reply(unsigned char *pp_out_data, unsigned int *pv_data_len, unsigned short read_offset)
{
	#if 0
	unsigned char *model_mac;
	extern struct netif xnetif[NET_IF_NUM]; 
	char al_mac_str[36] = {0};
	model_mac = LwIP_GetMAC(&xnetif[0]);
	sprintf(al_mac_str, "%s%02x%02x%02x%02x%02x%02x", HSN_DASHWASHER_CODE, model_mac[0], model_mac[1], model_mac[2], model_mac[3], model_mac[4], model_mac[5]);
	printf("mac str:%s\n", al_mac_str);
	
	*pv_data_len = hsn_ble_config_tlv_packet(gv_tag, al_mac_str, strlen(al_mac_str), pp_out_data);
	#else
	
	unsigned char *model_mac;
	char al_mac_str[2] = {0};
	*pv_data_len = hsn_ble_config_tlv_packet(gv_tag, al_mac_str, 1, pp_out_data);
	#endif
}

#ifdef HSN_UPDATE_20210924

//////////////////////////////////////
//0007
void hsn_bt_cmd_ssid_connect(unsigned short vp_tag, unsigned char* pp_value, int pv_value_len)
{
	int ret = 0;
	if (pv_value_len < 255)
	{
		gv_tag = vp_tag;
		memcpy(gp_bt_config_tmp_buf, pp_value, pv_value_len);
		gp_bt_config_tmp_buf_len = (unsigned short)pv_value_len;

		ret = hsn_get_router_info_ex(pp_value, pv_value_len);
		if (0 == ret)
		{
			wapi_send_net_msg(CONNECT_ROUTER, NULL, 0, NULL);
		}	
		else
		{
			printf("bt config fail...\n");
			bapi_set_reboot_flag(32);
		}
	}
	else
	{
		gv_tag = 0;
		printf("bt cmd invalid len:%d\n", pv_value_len);
	}
}


//8007

void hsn_bt_cmd_ssid_connect_reply(unsigned char *pp_out_data, unsigned int *pv_data_len, unsigned short read_offset)
{
	if(gp_bt_config_tmp_buf_len > 0)
    {
		*pv_data_len = hsn_ble_config_tlv_packet(gv_tag, gp_bt_config_tmp_buf, gp_bt_config_tmp_buf_len, pp_out_data);
		//gp_bt_config_tmp_buf_len = 0;
	}
	else
    {
		printf("[%s]malloc error\n",__FUNCTION__);
		return;
	}
}



//////////////////////////////////////
//0008
void hsn_bt_cmd_start_scan(unsigned short vp_tag, unsigned char* pp_value, int pv_value_len)
{
	if ((1 == pv_value_len) && (0 == pp_value[0]))
	{
		gv_tag = vp_tag;
		hsn_btconfig_scan_ssid_start();
	}
	else
	{
		gv_tag = 0;
		printf("bt cmd invalid len:%d\n", pv_value_len);
	}
}


//8008

void hsn_bt_cmd_start_scan_reply(unsigned char *pp_out_data, unsigned int *pv_data_len, unsigned short read_offset)
{
	unsigned char vl_sta = 0;
	*pv_data_len = hsn_ble_config_tlv_packet(gv_tag, &vl_sta, 1, pp_out_data);

}

#endif



void hsn_ble_config_tlv_write_parse(unsigned char *pp_data, unsigned int pv_data_len)
{
	unsigned short vl_tag = 0;
	unsigned short vl_value_len = 0;
	vl_tag = (unsigned short)(pp_data[0] << 8 | pp_data[1]);
	vl_value_len = (unsigned short)(pp_data[2] << 8 | pp_data[3]);
	printf("TAG: %d, LEN: %d[%02x]\n", vl_tag, vl_value_len, vl_value_len);
	switch(vl_tag)
	{
		case HSN_TAG_BT_CMD_SCAN:
			{
				hsn_bt_cmd_scan(vl_tag, pp_data + 4, vl_value_len);
			}
			break;
		case HSN_TAG_BT_CMD_CONNECT:
			{
				hsn_bt_cmd_connect(vl_tag, pp_data + 4, vl_value_len);
			}
			break;
		case HSN_TAG_BT_CMD_STATUE:
			{
				hsn_bt_cmd_status(vl_tag, pp_data + 4, vl_value_len);
			}
			break;
		case HSN_TAG_BT_CMD_GET_WLAN_BAND:
			{
				hsn_bt_cmd_get_wlan_band(vl_tag, pp_data + 4, vl_value_len);
			}
			break;
		case HSN_TAG_BT_CMD_GET_WIFI_ID:
			{
				hsn_bt_cmd_get_wifi_id(vl_tag, pp_data + 4, vl_value_len);
			}
			break;
		case HSN_TAG_BT_CMD_GET_DEV_ID:
			{
				hsn_bt_cmd_get_dev_id(vl_tag, pp_data + 4, vl_value_len);
			}
			break;
#ifdef HSN_UPDATE_20210924
		case HSN_TAG_BT_CMD_SSID_CONNECT:
			{
				hsn_bt_cmd_ssid_connect(vl_tag, pp_data + 4, vl_value_len);
			}
			break;
		case HSN_TAG_BT_CMD_START_SCAN:
			{
				hsn_bt_cmd_start_scan(vl_tag, pp_data + 4, vl_value_len);
			}
			break;

#endif
		default:
			printf("unknown tag: %4X\n", vl_tag);
			break;

	}
}

void hsn_ble_config_tlv_read_reply(unsigned char *pp_out_data, unsigned int *pv_data_len, unsigned short read_offset)
{
	switch(gv_tag)
	{
		case HSN_TAG_BT_CMD_SCAN:
			{
				hsn_bt_cmd_scan_reply(pp_out_data, pv_data_len, read_offset);
			}
			break;
		case HSN_TAG_BT_CMD_CONNECT:
			{
				hsn_bt_cmd_connect_reply(pp_out_data, pv_data_len, read_offset);
			}
			break;
		case HSN_TAG_BT_CMD_STATUE:
			{
				hsn_bt_cmd_status_reply(pp_out_data, pv_data_len, read_offset);
			}
			break;
		case HSN_TAG_BT_CMD_GET_WLAN_BAND:
			{
				hsn_bt_cmd_get_wlan_band_reply(pp_out_data, pv_data_len, read_offset);
			}
			break;
		case HSN_TAG_BT_CMD_GET_WIFI_ID:
			{
				hsn_bt_cmd_get_wifi_id_reply(pp_out_data, pv_data_len, read_offset);
			}
			break;
		case HSN_TAG_BT_CMD_GET_DEV_ID:
			{
				hsn_bt_cmd_get_dev_id_reply(pp_out_data, pv_data_len, read_offset);
			}
			break;
#ifdef HSN_UPDATE_20210924
		case HSN_TAG_BT_CMD_SSID_CONNECT:
			{
				hsn_bt_cmd_ssid_connect_reply(pp_out_data, pv_data_len, read_offset);
			}
			break;
		case HSN_TAG_BT_CMD_START_SCAN:
			{
				hsn_bt_cmd_start_scan_reply(pp_out_data, pv_data_len, read_offset);
			}
			break;
#endif
		default:
			printf("unknown tag: %4X\n", gv_tag);
			break;

	}
}



void hsn_test_bt_cmd_parse()
{
	unsigned char al_buf[64] = {0x00, 0x02, 0x00, 0x21, 0x21, 0x00, 0x01, 0x22, 0x6A, 0xC6, 0x74, 0xC6, 0xC4, 0x74, 0xC6, 0xC2, 0x74, 0x72, 0xC4, 0x74, 0x66, 0xC6, 0x74, 0x6A, 0xCC, 0x14, 0x68, 0x60, 0x60, 0x70, 0x62, 0x64, 0x62, 0x62, 0x64, 0x62, 0x60};

	hsn_ble_config_tlv_write_parse(al_buf, 64);
}

#ifdef HSN_UPDATE_20210924



static void hsn_btconfig_my_scan_result( rtw_scan_result_t* record )
{
	if ((sv_ap_num_in < HSN_BT_CONFIG_AP_INFO_MAX_SIZE)
		&& (record->SSID.len > 0))
	{
		//unsigned char temp_buff[256] = {0};
	    //sprintf(temp_buff, "%s: %s         %s: %d%s", "SSID", record->SSID.val, "RSSI", record->signal_strength,"\r\n");
	    //printf("AP-%d: %s\n", sv_ap_num_in, temp_buff);
	
		memset(&sa_btconfig_ap_info[sv_ap_num_in], 0, sizeof(t_HSN_BT_CONFIG_AP_INFO));
		memcpy(sa_btconfig_ap_info[sv_ap_num_in].bssid_octer, record->BSSID.octet, 6);
		sa_btconfig_ap_info[sv_ap_num_in].rssi = (unsigned char)record->signal_strength;
		sa_btconfig_ap_info[sv_ap_num_in].secuity = record->security;
		sa_btconfig_ap_info[sv_ap_num_in].ssid_len = record->SSID.len;
		memcpy(sa_btconfig_ap_info[sv_ap_num_in].ssid, record->SSID.val, record->SSID.len);

		//WAPI_DUMP_HEX(&sa_btconfig_ap_info[sv_ap_num_in], sizeof(t_HSN_BT_CONFIG_AP_INFO), "AP INFO");

		sv_ap_num_in++;
		
	}
	
	
	
}



static rtw_result_t hsn_btconfig_scan_ssid_result( rtw_scan_handler_result_t* malloced_scan_result )
{
	static int ApNum = 0;

	if (malloced_scan_result->scan_complete != RTW_TRUE) 
    {
		rtw_scan_result_t* record = &malloced_scan_result->ap_details;
		record->SSID.val[record->SSID.len] = 0; /* Ensure the SSID is null terminated */
		hsn_btconfig_my_scan_result(record);
	} 
    else
    {
		ApNum = 0;
	}
	return RTW_SUCCESS;
}





void hsn_btconfig_scan_ssid_task(void *param)
{	
	if (HSN_BTCONFIG_SCAN_STATE_IDLE == sv_btconfig_scan_state)
	{
		printf("start scan...\n");
		sv_ap_num_in = 0;
		sv_ap_num_out = 0;
		sv_arrangement = 0;
		sv_remainder = 0;
		
		sv_btconfig_scan_state = HSN_BTCONFIG_SCAN_STATE_SCANNING;
		wifi_scan_networks(hsn_btconfig_scan_ssid_result, NULL);
		vTaskDelay(2100);
		printf("stop scan.\n");
		sv_btconfig_scan_state = HSN_BTCONFIG_SCAN_STATE_IDLE;
		
		if (sv_ap_num_in > 0)
		{
			sv_arrangement = sv_ap_num_in / HSN_BTCONFIG_MAX_APNUM_FOR_ONETIME;
			sv_remainder = sv_ap_num_in % HSN_BTCONFIG_MAX_APNUM_FOR_ONETIME;
			sv_ap_num_out = 0;
		}

	}
	else
	{
		bapi_set_reboot_flag(102);
		vTaskDelay(100);
	}
	
    vTaskDelete(s_hsn_scan_ssid_task_handle);
	s_hsn_scan_ssid_task_handle = NULL;
}



int hsn_btconfig_scan_ssid_start(void)
{
	if(xTaskCreate((TaskFunction_t)hsn_btconfig_scan_ssid_task, (char const *)"hsn_btconfig_scan_ssid_task", 512, NULL, tskIDLE_PRIORITY + 5, &s_hsn_scan_ssid_task_handle) != pdPASS) {
		printf("hsn_btconfig_scan_ssid_task failed\n");	
	}
	printf("hsn_btconfig_scan_ssid_task success\n");
	return 0;
}

#endif


