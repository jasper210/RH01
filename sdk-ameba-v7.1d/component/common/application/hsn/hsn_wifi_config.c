/*
 * @Description: smart_config_sniffer.c
 * @Author: xuetong
 * @Date: 2019-08-29 09:20:55
 * @LastEditTime: 2019-11-01 18:19:08
 * @LastEditors: Please set LastEditors
 */
#include "hsn_common.h"

unsigned int hsn_softap_config_time = HSN_KITCHE_SOFTAP_CONFIG_TIMEOUT;
unsigned int hsn_ble_config_time = HSN_KITCHE_BLE_CONFIG_TIMEOUT;



#if 0

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
extern uint8 g_packData[512];
extern uint8 g_packOrder[512];
extern int g_isFull;
extern int g_packDataLen ;
int lock_channel = 0;
static int timeout_time = 0;

unsigned char da[6] = {0};
unsigned char sa[6] = {0};
int frame_len = 0;
rlt_ap_setting ap_info;
int softap_flag = 0;

extern int gv_ble_config_finish;


static xSemaphoreHandle g_mutexChannelLock;

static void channel_mutex_sem_init()
{
   	g_mutexChannelLock = xSemaphoreCreateMutex();
    return;
}

void softap_mode_start(rlt_ap_setting *ap_info)
{
	int timeout = 20;
#if CONFIG_LWIP_LAYER 
	struct ip_addr ipaddr;
	struct ip_addr netmask;
	struct ip_addr gw;
	struct netif * pnetif = &xnetif[0];
#endif
	int ret = 0;
#if CONFIG_LWIP_LAYER
	dhcps_deinit();
	IP4_ADDR(&ipaddr, GW_ADDR0, GW_ADDR1, GW_ADDR2, GW_ADDR3);
	IP4_ADDR(&netmask, NETMASK_ADDR0, NETMASK_ADDR1 , NETMASK_ADDR2, NETMASK_ADDR3);
	IP4_ADDR(&gw, GW_ADDR0, GW_ADDR1, GW_ADDR2, GW_ADDR3);
	netif_set_addr(pnetif, &ipaddr, &netmask,&gw);
#endif
	wifi_off();
	//vTaskDelay(20);
	wifi_on(RTW_MODE_AP);
	ret = wifi_start_ap((char*)ap_info->ssid, ap_info->security_type, NULL, strlen(ap_info->ssid), 0, ap_info->channel);
	if(ret >= 0)
	{
		printf("ssid: %s.\n", ap_info->ssid);
	}
	dhcps_init(&xnetif[0]);
}

void softap_func(void *param)
{
	unsigned int start_time;
	start_time = xTaskGetTickCount();
	rlt_generate_ap_name(ap_info.ssid);
	ap_info.security_type = RTW_SECURITY_OPEN;
	ap_info.channel = 6;
	softap_mode_start(&ap_info);
	while(1)
	{
		unsigned int current_time = xTaskGetTickCount();
		if((current_time - start_time) > (60 * 4 * configTICK_RATE_HZ))
		{
			goto CONFIG_TIMEOUT;
		}
		vTaskDelay(1500);
	}
CONFIG_TIMEOUT:
    hsn_sys_reset(13);
   
}    

unsigned char hsn_checkSum(unsigned char *buf, int len)
{
    unsigned char ch = 0;
    for (int i = 0; i < len; i++) {
        ch ^= buf[i];
    }
    return ch;
}


static void promisc_callback(unsigned char *buf, unsigned int len, void* userdata)
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
 
 
static void smart_config_mode_entry(int duration, unsigned char len_used)
{
	int ch;
	unsigned int start_time;
	wifi_enter_promisc_mode();
	wifi_set_promisc(RTW_PROMISC_ENABLE, promisc_callback, len_used);
}


static void simple_config_channel_control(void *para)
{
	LOGT("start sniffer config1..\n");
	int offset;
	int ret;
	unsigned int start_time;
	int ch_idx = 0;
	smart_config_mode_entry(30, 1);
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
					printf("\n\rSwitch to channel(%d)\n", simple_config_promisc_channel_tbl[ch_idx]);
				}

                ch_idx++;
			}	
		}
        xSemaphoreGive(g_mutexChannelLock);
        vTaskDelay(150);
	}

CONFIG_TIMEOUT:	
	wifi_set_promisc(RTW_PROMISC_DISABLE, NULL, 0);
	printf("start ap config\n");
	wapi_send_net_msg(SOFTAP_CONFIG_MODE, NULL, 0, NULL);
	softap_flag = 1;
	vTaskDelete(switch_channel_task);
	switch_channel_task = NULL;
	return; 
CONFIG_FINISH:
	wifi_set_promisc(RTW_PROMISC_DISABLE, NULL, 0);
	print_hex(g_packData, g_packDataLen); 
	offset = g_packData[2];
    uint8 ch = hsn_checkSum(g_packData, g_packDataLen);
    printf("check sum ch is:%2x\n", ch);
	hex_2_bit(&g_packData[3], g_packDataLen - 3, offset);
	printf("switch data: \n");
	print_hex(g_packData, g_packDataLen);
	ret = router_info_get(g_packData, 0);
	
	vTaskDelete(switch_channel_task);
	switch_channel_task = NULL;
	return;
}


void config_mode_timeout()
{
	if(softap_flag == 0)
	{
		// quit config, start ap config
		t_CONFIG_TABLE_BODY* pl_cfg = MC_WG_CONFIG_TABLE_PTR();
		pl_cfg->v_cur_mode = WIFI_MODE_IDLE;
		bapi_set_write_config_flag();
			
		wapi_send_net_msg(SOFTAP_CONFIG_MODE, NULL, 0, NULL);
		softap_flag = 1;
	}
/* 	else
	{
		if (xTimerStop(config_timer, 0) != pdPASS)
		{
			printf("stop timer error\n");
			xTimerDelete(config_timer, 0);
		}
		else
		{
			printf("stop timer ok\n");
			xTimerDelete(config_timer, 0);
		}
	} */
	
}


int set_smrtlink_timer_init()
{
	gtimer_init(&config_timer, TIMER1);
	gtimer_start_periodical(&config_timer, 30 * 1000000, (void*)config_mode_timeout, NULL);
/* 	config_timer = xTimerCreate("config timer", 60 * 1000, pdTRUE, NULL, config_mode_timeout);
	xTimerStart(config_timer, 0); */
	return 1;
}

int channel_control_entry()
{
	if(xTaskCreate(simple_config_channel_control, ((const char*)"simple_config_channel_control"), 1024, NULL, tskIDLE_PRIORITY + 3, switch_channel_task) != pdPASS)
		printf("\n\r%s xTaskCreate(simple_config_channel_control) failed", __FUNCTION__); 
	printf("smart config channel change:start,%s\n",__FUNCTION__);
	return 0;
}


int sniffer_func_entry()
{
	channel_control_entry();
	return 0;
}


int softap_config_entry()
{
	if(xTaskCreate(softap_func, ((const char*)"softap "), 1024, NULL, tskIDLE_PRIORITY + 1, softap_task) != pdPASS)
		printf("\n\r%s xTaskCreate(simple_config_channel_control) failed", __FUNCTION__); 
	printf("smart config channel change:start\n",__FUNCTION__);
	return 0;
}

int softap_func_entry()
{
	softap_config_entry();
	return 0;
}


#else
xTaskHandle switch_channel_task = NULL;
xTaskHandle softap_task = NULL;
xTaskHandle xd_netconfig_task = NULL;
extern struct netif xnetif[NET_IF_NUM]; 
static int simple_config_promisc_channel_tbl[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,1,2,3,4,5,6,7,8,9,10,11,12,13};
int base_len = 0;
int base_len_x = 0;
xQueueHandle config_queue;
static int mode_change_cnt = 0;
gtimer_t config_timer;
//TimerHandle_t config_timer;
int sniffer_config_finish = 0;


typedef unsigned char uint8;
extern uint8 g_packData[512];
extern uint8 g_packOrder[512];
extern int g_isFull;
extern int g_packDataLen ;
int lock_channel = 0;
static int timeout_time = 0;

unsigned char da[6] = {0};
unsigned char sa[6] = {0};
int frame_len = 0;
rlt_ap_setting ap_info;
int softap_flag = 0;

int gv_smart_confg_timeout = 27;//27;

static xSemaphoreHandle g_mutexChannelLock;

static void channel_mutex_sem_init()
{
   	g_mutexChannelLock = xSemaphoreCreateMutex();
    return;
}

void softap_mode_start(rlt_ap_setting *ap_info)
{
	int timeout = 20;
#if CONFIG_LWIP_LAYER 
	struct ip_addr ipaddr;
	struct ip_addr netmask;
	struct ip_addr gw;
	struct netif * pnetif = &xnetif[0];
#endif
	int ret = 0;
#if CONFIG_LWIP_LAYER
	dhcps_deinit();
	IP4_ADDR(&ipaddr, GW_ADDR0, GW_ADDR1, GW_ADDR2, GW_ADDR3);
	IP4_ADDR(&netmask, NETMASK_ADDR0, NETMASK_ADDR1 , NETMASK_ADDR2, NETMASK_ADDR3);
	IP4_ADDR(&gw, GW_ADDR0, GW_ADDR1, GW_ADDR2, GW_ADDR3);
	netif_set_addr(pnetif, &ipaddr, &netmask,&gw);
#endif
	wifi_off();
	vTaskDelay(20);
	wifi_on(RTW_MODE_AP);
	ret = wifi_start_ap((char*)ap_info->ssid, ap_info->security_type, NULL, strlen(ap_info->ssid), 0, ap_info->channel);
	if(ret >= 0)
	{
		printf("ssid: %s.\n", ap_info->ssid);
	}
	dhcps_init(&xnetif[0]);
}


int hsn_softap_stop_run_flag = 0;
void hsn_stop_softap_confg()
{
	hsn_softap_stop_run_flag = 1;
}


extern void fATWD(void *arg);
void softap_func(void *param)
{
	printf("entry softap func\n");
	hsn_softap_stop_run_flag = 0;
	t_WIFI_GLOBAL* pl_wg = MC_WIFI_GLOBAL_PTR();
	t_CONFIG_TABLE_BODY* pl_cfg = MC_WG_CONFIG_TABLE_PTR();
	unsigned int start_time;
	unsigned int current_time;
	
	rlt_generate_ap_name(ap_info.ssid);
	ap_info.security_type = RTW_SECURITY_OPEN;
	ap_info.channel = 6;
	softap_mode_start(&ap_info);

	start_time = xTaskGetTickCount();
	while(1)
	{
		if (1 == hsn_softap_stop_run_flag)
		{
			goto CONFIG_STOP;
		}
		current_time = xTaskGetTickCount();
		if((current_time - start_time) > (hsn_softap_config_time))
		{
			goto CONFIG_TIMEOUT;
		}
		vTaskDelay(1000);
	}
	
CONFIG_TIMEOUT:
	printf("softap timeout 1\n");
	fATWD(NULL);
CONFIG_STOP:
	printf("softap stop 1\n");
	
	vTaskDelete(NULL);

}    




unsigned char hsn_checkSum(unsigned char *buf, int len)
{
    unsigned char ch = 0;
    for (int i = 0; i < len; i++) {
        ch ^= buf[i];
    }
    return ch;
}

static void promisc_callback(unsigned char *buf, unsigned int len, void* userdata)
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
	printf(", len=%d ", frame_len);	

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
				sniffer_config_finish = 1;
				//uint8 ch = hsn_checkSum(g_packData, g_packDataLen);
				//printf("check sum ch is:%2x\n", ch);
				//WAPI_DUMP_HEX(g_packData,g_packDataLen,"RDATA:");
/* 				print_hex(g_packData, g_packDataLen); 
				offset = g_packData[2];
                uint8 ch = hsn_checkSum(g_packData, g_packDataLen);
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
 
 
static void smart_config_mode_entry(int duration, unsigned char len_used)
{
	int ch;
	unsigned int start_time;
	wifi_enter_promisc_mode();
	wifi_set_promisc(RTW_PROMISC_ENABLE, promisc_callback, len_used);
}





static void hsn_channel_control(void *para)
{
	LOGT("start sniffer config..\n");
	t_WIFI_GLOBAL* pl_wg = MC_WIFI_GLOBAL_PTR();
	int offset;
	int ret;
	unsigned int start_time;
	int ch_idx = 0;
	smart_config_mode_entry(30, 1);
    channel_mutex_sem_init();
	timeout_time++;
	start_time = xTaskGetTickCount();
	sniffer_config_finish = 0;
	
#if (HSN_WATCHDOW_CONFIG==1)	
	watchdog_refresh();
#endif

	while(1)
	{
		xSemaphoreTake(g_mutexChannelLock, portMAX_DELAY);
		unsigned int current_time = xTaskGetTickCount();
		if((current_time - start_time) > (gv_smart_confg_timeout * configTICK_RATE_HZ))
		{
			goto CONFIG_TIMEOUT;
		}
		if(sniffer_config_finish)
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
					printf("\n\rSwitch to channel(%d)\n", simple_config_promisc_channel_tbl[ch_idx]);
				}

                ch_idx++;
			}	
		}
        xSemaphoreGive(g_mutexChannelLock);
        vTaskDelay(105);
	}
CONFIG_TIMEOUT:	
	#if 0
	//bapi_set_reboot_flag(14);
	vTaskDelay(3000);
	sys_reset();
	#else 
	
	wifi_set_promisc(RTW_PROMISC_DISABLE, NULL, 0);
	pl_wg->v_sniffer_sta = HSN_SNIFFER_STATE_IDLE;
	
	printf("start ap config\n");
	wapi_send_net_msg(SOFTAP_CONFIG_MODE, NULL, 0, NULL);
	softap_flag = 1;
	vTaskDelete(switch_channel_task);
	switch_channel_task = NULL;
	return;
	#endif 
CONFIG_FINISH:
	pl_wg->v_sniffer_sta = HSN_SNIFFER_STATE_STARTED;
	wifi_set_promisc(RTW_PROMISC_DISABLE, NULL, 0);
	pl_wg->v_sniffer_sta = HSN_SNIFFER_STATE_IDLE;
	
	print_hex(g_packData, g_packDataLen); 
	ret = hsn_get_router_info(g_packData, g_packDataLen);
	if (0 != ret)
	{
		wapi_send_net_msg(CONNECT_ROUTER, NULL, 0, NULL);
	}
	else
	{
		printf("start ap config1\n");
		wapi_send_net_msg(SOFTAP_CONFIG_MODE, NULL, 0, NULL);
		softap_flag = 1;
	}

	vTaskDelete(switch_channel_task);
	switch_channel_task = NULL;
	return;
}


void config_mode_timeout()
{
	if(softap_flag == 0)
	{
		// quit config, start ap config
		t_CONFIG_TABLE_BODY* pl_cfg = MC_WG_CONFIG_TABLE_PTR();
		pl_cfg->v_cur_mode = WIFI_MODE_IDLE;
		bapi_set_write_config_flag();
			
		wapi_send_net_msg(SOFTAP_CONFIG_MODE, NULL, 0, NULL);
		softap_flag = 1;
	}
/* 	else
	{
		if (xTimerStop(config_timer, 0) != pdPASS)
		{
			printf("stop timer error\n");
			xTimerDelete(config_timer, 0);
		}
		else
		{
			printf("stop timer ok\n");
			xTimerDelete(config_timer, 0);
		}
	} */
	
}

int set_smrtlink_timer_init()
{
	gtimer_init(&config_timer, TIMER1);
	gtimer_start_periodical(&config_timer, 30 * 1000000, (void*)config_mode_timeout, NULL);
/* 	config_timer = xTimerCreate("config timer", 60 * 1000, pdTRUE, NULL, config_mode_timeout);
	xTimerStart(config_timer, 0); */
	return 1;
}

int channel_control_entry()
{
	if(xTaskCreate(hsn_channel_control, ((const char*)"hsn_channel_control"), 1024, NULL, tskIDLE_PRIORITY + HSN_TSK_PRIORITY, switch_channel_task) != pdPASS)
		printf("\n\r%s xTaskCreate(hsn_channel_control) failed", __FUNCTION__); 
	printf("smart config channel change:start,%s\n",__FUNCTION__);
	return 0;
}


int sniffer_func_entry()
{
	char essid[33];
	int ret;
	int timeout = 20;
	if(wext_get_ssid(WLAN0_NAME, (unsigned char *) essid) < 0) {
		printf("\n\rnot connected yet");
	}
	else
	{
		if((ret = wifi_disconnect()) < 0) 
		{
			printf("\n\rERROR: Operation failed!");
		}
		while(1) {
			if(wext_get_ssid(WLAN0_NAME, (unsigned char *) essid) < 0) {
				printf("\n\rWIFI disconnect succeed");
				break;
			}

			if(timeout == 0) {
				printf("\n\rERROR: Deassoc timeout!");
				ret = RTW_TIMEOUT;
				break;
			}

			vTaskDelay(1 * configTICK_RATE_HZ);
			timeout --;
		}
		printf("\n\r");

		LwIP_ReleaseIP(WLAN0_IDX);
	}

	
	
	channel_control_entry();
	return 0;
}


int softap_config_entry()
{
	if(xTaskCreate(softap_func, ((const char*)"softap "), 1024, NULL, tskIDLE_PRIORITY + HSN_TSK_PRIORITY, softap_task) != pdPASS)
		printf("\n\r%s xTaskCreate(softap_config_entry) failed", __FUNCTION__); 
	printf("softap_config_entry start\n",__FUNCTION__);
	return 0;
}

int softap_func_entry()
{
	softap_config_entry();
	return 0;
}

#endif

void test_smart_config()
{
	sniffer_func_entry();
}




void xd_netconfig_func(void *param)
{
	printf("entry softap func\n");
	t_WIFI_GLOBAL* pl_wg = MC_WIFI_GLOBAL_PTR();
	t_CONFIG_TABLE_BODY* pl_cfg = MC_WG_CONFIG_TABLE_PTR();
	unsigned int start_time;
	start_time = xTaskGetTickCount();
	rlt_generate_ap_name(ap_info.ssid);
	ap_info.security_type = RTW_SECURITY_OPEN;
	ap_info.channel = 6;
	softap_mode_start(&ap_info);
	
	while(1)
	{
		vTaskDelay(1500);
		unsigned int current_time = xTaskGetTickCount();
		if((current_time - start_time) > (60 * 30 * configTICK_RATE_HZ))
		{
			goto CONFIG_TIMEOUT;
		}
		
	}
CONFIG_TIMEOUT:
	printf("softap timeout 1\n");
	
   
}    


int xd_net_config_entry()
{
	if(xTaskCreate(xd_netconfig_func, ((const char*)"netconfig"), 1024, NULL, tskIDLE_PRIORITY + HSN_TSK_PRIORITY, xd_netconfig_task) != pdPASS)
		printf("\n\r%s xTaskCreate(xd_net_config_entry) failed", __FUNCTION__); 
	printf("xd_net_config_entry start\n",__FUNCTION__);
	return 0;
}





