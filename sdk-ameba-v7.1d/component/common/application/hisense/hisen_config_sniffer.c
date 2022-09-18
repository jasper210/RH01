#include "hisen_common.h"


xTaskHandle switch_channel_task = NULL;
xTaskHandle softap_task = NULL;
extern struct netif xnetif[NET_IF_NUM]; 
static int simple_config_promisc_channel_tbl[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,1,2,3,4,5,6,7,8,9,10,11,12,13};
extern xQueueHandle status_queue;
int base_len = 0;
int base_len_x = 0;
xQueueHandle config_queue;
static int mode_change_cnt = 0;
gtimer_t config_timer;
//TimerHandle_t config_timer;
int config_finish = 0;

typedef unsigned char uint8;
int lock_channel = 0;
static int timeout_time = 0;

uint8 g_packData[512] = {0};
uint8 g_packOrder[512] = {0};
int g_isFull = 0;
int g_packDataLen = 0;


unsigned char da[6] = {0};
unsigned char sa[6] = {0};
int frame_len = 0;

static hisen_sniffer_config_callback s_sniffer_config_cb;


static xSemaphoreHandle g_mutexChannelLock;

#define print_hex(a,b)  { \
                int count_tmp; \
                for(count_tmp = 0;count_tmp < b;){ \
                        printf("%02x ",a[count_tmp++]); \
                        if(count_tmp % 16 == 0){ \
                                printf("\n"); \
                        } \
                } \
                printf("\n"); \
        } 


static void JudgePackOrder(uint8 order, uint8 alen)
{
    int i;
    int totalLen = ((alen * 2) + 2) / 3;

    /* if the first package not come */
    if (alen == 0) {
        return;
    }
    
    for (i = 0; i < totalLen - 1; i++) {
        if (g_packOrder[i] == 0) {
            printf("left package is not full: %d", i);
            return;
        }
    }

    /* if all order have come, set flag */
    g_isFull = 1;
    if (totalLen % 2 == 0) {
        g_packDataLen = totalLen * 3 / 2;
    } else {
        g_packDataLen = totalLen * 3 / 2 + 1;
    }
    return;
}

int base_len_get(uint8 x1, uint8 x2, uint8 x3)
{
    uint8 Ai = 0;
    uint8 Bi = 0;
    uint8 Ci = 0;
    uint8 N2 = 0;

    Ai = (x1 >> 5) << 7;
    Ai = Ai | (x2 & 0x7F);

    Bi = x3 &0x0F;
    Ci = x1 & 0x1F;

    if (((Ai ^ Bi) & 0x1F) != Ci) 
    {
        printf("check code fail \n");
        return -1;
    }

    N2 = (x3 & 0x7F) >> 4;
    /* check code */
    printf("Ai is:%02x, Bi is:%02x, Ci is:%02x, N2 is:%d \n", Ai,Bi,Ci,N2);
    if(N2 == 7)
    {
        return 1;
    }
}

int MulticastProtocolAnalysis(uint8 x1, uint8 x2, uint8 x3, uint8 len)
{
    uint8 Ai = 0;
    uint8 Bi = 0;
    uint8 Ci = 0;
    int N1 =0;
    uint8 N2 = 0;
    int packageOrder;
    int pos;
    static unsigned int Alen = 0;

    if (g_isFull) {
        printf("package buff have recv complete, no need handler");
        return 1;
    }

    Ai = (x1 >> 5) << 7;
    Ai = Ai | (x2 & 0x7F);

    Bi = x3 &0x0F;
    Ci = x1 & 0x1F;

    N2 = (x3 & 0x7F) >> 4;
    N1 = len - 1;

    /* check code */
    if (((Ai ^ Bi) & 0x1F) != Ci) {
        printf("check code fail \n");
        return -1;
    }

    printf("Ai is:%02x, Bi is:%02x, Ci is:%02x, N1 is:%d, N2 is:%d \n", Ai,Bi,Ci,N1,N2);

    packageOrder = N1 * 7 + N2;
    if ((N1 == 0) && (N2 == 7)) {
        packageOrder = 0;
        Alen = Ai;
    }

    g_packOrder[packageOrder] = 1; /* set the index value 1 */
    if (packageOrder % 2 == 0) {
        pos = packageOrder * 3 / 2;
        g_packData[pos] = Ai;
        g_packData[pos + 1] = g_packData[pos + 1] | (Bi << 4);
    } else {
        pos = (packageOrder + 1) * 3 / 2 - 2;
        g_packData[pos] = g_packData[pos] | Bi;
        g_packData[pos + 1] = Ai;
    }
    
    JudgePackOrder(0, Alen);
    
    return 0;
}



static void channel_mutex_sem_init()
{
   	g_mutexChannelLock = xSemaphoreCreateMutex();
    return;
}



unsigned char CheckSum(char *buf, int len)
{
    unsigned char ch = 0;
    for (int i = 0; i < len; i++) {
        ch ^= buf[i];
    }
    return ch;
}

static void hisen_promisc_callback(unsigned char *buf, unsigned int len, void* userdata)
{
	int ret;
	int offset;
	int ret1 = 0;
	int ret2 = 0;
	int i;

    if (!xSemaphoreTake(g_mutexChannelLock, 0)) {
        printf("now is switch channel, so return\n");
        return;
    }

//    print_buf2hex(buf);

	memcpy(da, buf, 6);
	memcpy(sa, buf+6, 6);
	frame_len = len;
	printf("\n\rDA:");
	for(i = 0; i < 6; i ++)
		printf(" %02x", da[i]);
	printf(", SA:");
	for(i = 0; i < 6; i ++)
		printf(" %02x", sa[i]);
	printf(", len=%d", frame_len);	

	base_len = 38;
	base_len_x = 42;
#if 1
	if((len > base_len) && (len < base_len_x + 5))
	{
		if((da[0] == 0x01) && (da[1] == 0) && (da[2] == 0x5e))
		{
			if(len > base_len_x)
			{
				ret2 = MulticastProtocolAnalysis(da[3], da[4], da[5], len - base_len_x);
				if (!lock_channel && ((ret2 == 0) || (ret2 == 1))) {
					lock_channel = 1;
					printf("begin lock channel\n");
				}
			}
			else if(len > base_len)
			{
				ret1 = MulticastProtocolAnalysis(da[3], da[4], da[5], len - base_len);
				if (!lock_channel && ((ret1 == 0) || (ret1 == 1))) {
					lock_channel = 1;
					printf("begin lock channel\n");
            	}
			}

			if((ret1 == 1) || ((ret2 == 1)))
			{
				config_finish = 1;
/* 				print_hex(g_packData, g_packDataLen); 
				offset = g_packData[2];
                uint8 ch = CheckSum(g_packData, g_packDataLen);
                printf("check sum ch is:%2x\n", ch);
				hex_2_bit(&g_packData[3], g_packDataLen - 3, offset);
				printf("switch data: \n");
				print_hex(g_packData, g_packDataLen);
				wifi_set_promisc(RTW_PROMISC_DISABLE, NULL, 0);
				ret = router_info_get(g_packData, 0); */
				
			}
		}
	}
#endif

    xSemaphoreGive(g_mutexChannelLock);
    return;
}
 
 
static void hisen_set_sniffer_config_mode(int duration, unsigned char len_used)
{
	int ch;
	unsigned int start_time;
	wifi_enter_promisc_mode();
	wifi_set_promisc(RTW_PROMISC_ENABLE, hisen_promisc_callback, len_used);
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



int config_passwd_len = 0;
unsigned char config_bssid[HISEN_SNIFFER_BSSID_LEN] = {0};
unsigned char config_passwd[HISEN_SNIFFER_PASSWORD_LEN] = {0};

int router_info_get(unsigned char *data, int flag)
{
  	int ret;
	int pos = data[2];
	unsigned char bssid[17] = {0};
	int bssid_len = 17;
	t_HISEN_ROUTER_INFO vl_router_info;

	memcpy(bssid, &data[4], bssid_len);
	config_passwd_len = data[21];
	//printf("passwd_len: %d\n", config_passwd_len);
	translate_to_hex_bssid(bssid, 17, config_bssid);
	//print_hex(config_bssid, HISEN_SNIFFER_BSSID_LEN);
	if(config_passwd_len > 0)
	{
		memset(config_passwd, 0, 32);
		memcpy(config_passwd, &data[22], config_passwd_len);
		//print_hex(config_passwd, config_passwd_len);
		config_passwd[config_passwd_len] = '\0';
		WAPI_DUMP_HEX(config_bssid,HISEN_SNIFFER_BSSID_LEN,"bssid:");
		printf("pwd: %s\n", config_passwd);

		hisen_init_wifi_struct(&vl_router_info);
		memcpy(vl_router_info.pwd, config_passwd, config_passwd_len);
		vl_router_info.pwd_len = config_passwd_len;
		memcpy(vl_router_info.bssid, config_bssid, HISEN_SNIFFER_BSSID_LEN);
		vl_router_info.bssid_len = HISEN_SNIFFER_BSSID_LEN;
		
		config_passwd_len = 0;

		s_sniffer_config_cb(0, &vl_router_info);

	}
}



static void hisen_sniffer_channel_control(void *para)
{
	int offset;
	int ret;
	unsigned int start_time;
	int ch_idx = 0;
	hisen_set_sniffer_config_mode(30, 1);
    channel_mutex_sem_init();
	timeout_time++;
	start_time = xTaskGetTickCount();
	while(1)
	{
		xSemaphoreTake(g_mutexChannelLock, portMAX_DELAY);
		unsigned int current_time = xTaskGetTickCount();
		if((current_time - start_time) > (27 * configTICK_RATE_HZ))
		{
			goto CONFIG_TIMEOUT;
		}
		if(config_finish)
		{
			goto CONFIG_FINISH;
		}
		if (!lock_channel) 
		{
			//if(switch_config_mode == SMART_LINK_CONFIG)
			{
				if(ch_idx >= sizeof(simple_config_promisc_channel_tbl)/sizeof(simple_config_promisc_channel_tbl[0]))
				{
					ch_idx = 0;
				}

				if (wifi_set_channel(simple_config_promisc_channel_tbl[ch_idx]) == 0) 
				{	
					printf("CH %d\n", simple_config_promisc_channel_tbl[ch_idx]);
				}

                ch_idx++;
			}	
		}
        xSemaphoreGive(g_mutexChannelLock);
        vTaskDelay(150);
	}
CONFIG_TIMEOUT:	
	wifi_set_promisc(RTW_PROMISC_DISABLE, NULL, 0);
	//rlt_msg_queue_send(status_queue, SOFTAP_CONFIG_MODE, NULL, 0);
	//softap_flag = 1;
	s_sniffer_config_cb(-1, NULL);
	vTaskDelete(switch_channel_task);
        switch_channel_task = NULL;
	return;

CONFIG_FINISH:
	wifi_set_promisc(RTW_PROMISC_DISABLE, NULL, 0);
	print_hex(g_packData, g_packDataLen); 
	offset = g_packData[2];
    uint8 ch = CheckSum(g_packData, g_packDataLen);
    printf("check sum ch is:%2x\n", ch);
	hex_2_bit(&g_packData[3], g_packDataLen - 3, offset);
	printf("switch data: \n");
	print_hex(g_packData, g_packDataLen);
	ret = router_info_get(g_packData, 0);
	vTaskDelete(switch_channel_task);
	switch_channel_task = NULL;
	return;
}




int channel_control_entry()
{
	if(xTaskCreate(hisen_sniffer_channel_control, ((const char*)"hisen_sniffer_channel_control"), 1024, NULL, tskIDLE_PRIORITY + 1, switch_channel_task) != pdPASS)
		printf("\n\r%s xTaskCreate(hisen_sniffer_channel_control) failed", __FUNCTION__); 
	printf("smart config channel change:start\n",__FUNCTION__);
	return 0;
}


int sniffer_func_entry(hisen_sniffer_config_callback pp_func)
{
	s_sniffer_config_cb = pp_func;
	channel_control_entry();
	return 0;
}


//////////////////////////////////////////////test


int hisen_test_connect_router_cb_1(int vl_result, int vl_reason)
{

}


int hisen_sniffer_config_callback_x(int result, void *pp_ctx)
{
	t_HISEN_ROUTER_INFO* pp_router_info = (t_HISEN_ROUTER_INFO*)pp_ctx;
	if (NULL != pp_router_info)
	{
		printf("PWD: %s\n", pp_router_info->pwd);
		WAPI_DUMP_HEX(pp_router_info->bssid,pp_router_info->bssid_len,"BSSID:");
		hisen_connect_ap_1(pp_router_info, hisen_test_connect_router_cb_1);
	}
	else
	{
		printf("hisen sniffer config timeout!\n");
	}
}


void test_hisen_snifffer_config()
{
	sniffer_func_entry(hisen_sniffer_config_callback_x);
}




