/*
 * @Description: In User Settings Edit
 * @Author: your name
 * @Date: 2019-08-05 08:48:44
 * @LastEditTime: 2019-10-29 16:23:00
 * @LastEditors: Please set LastEditors
 */

/* FreeRTOS includes. */
#include "hsn_common.h"


extern unsigned char wifi_router_connect_status;
extern unsigned char wifi_status;
extern unsigned char router_cloud_connect_status;
extern unsigned char bluetooth_state;



void ilife_watchdog_irq_handler(uint32_t id)
{
    printf("!!!!!!watchdog barks!!!!!!\r\n");
	t_WIFI_GLOBAL* pl_wg = MC_WIFI_GLOBAL_PTR();
	t_CONFIG_TABLE_BODY* pl_cfg = MC_WG_CONFIG_TABLE_PTR();
	
	printf("m:%d,%d,%d,mo:%d,%d,s:%d,%d,%d,%d,%d,wg:%d,%d,%d,%d,p:%d,%d,%d\n"
					, xPortGetFreeHeapSize(), wapi_get_rssi(), wapi_get_wifi_mode()
					, pl_cfg->v_cur_mode, pl_cfg->v_bt_mode
					, pl_wg->v_router_sta, pl_wg->v_cloud_login_sta
					, pl_wg->v_sniffer_sta, pl_wg->v_ap_sta, pl_wg->v_bt_sta
					, pl_wg->v_router_reconnect_flag, pl_wg->v_router_reconnect_cnt
					, pl_wg->v_cloud_reconnect_flag, pl_wg->v_cloud_reconnect_cnt
					, pl_wg->v_param_hb_time, pl_wg->v_param_rp_time, pl_wg->v_param_retry_time);
	//vTaskDelay(800);
	vTaskDelay(500);
	sys_reset();
}


void dev_id_init(unsigned char *model_mac, unsigned char vp_dev_type)
{
	t_WIFI_GLOBAL* pl_wg = MC_WIFI_GLOBAL_PTR();
	int len;
	extern struct netif xnetif[NET_IF_NUM]; 
	model_mac = LwIP_GetMAC(&xnetif[0]);

	if (HSN_DEVICE_TYPE_ICEBOX == vp_dev_type)
	{
		sprintf(pl_wg->wifi_id, "%s%02x%02x%02x%02x%02x%02x", pl_wg->v_featurecode, model_mac[0], model_mac[1], model_mac[2], model_mac[3], model_mac[4], model_mac[5]);
		pl_wg->wifi_id[36] = '\0';
	}
	else
	{
		sprintf(pl_wg->wifi_id, "%s%02x%02x%02x%02x", pl_wg->v_featurecode, model_mac[2], model_mac[3], model_mac[4], model_mac[5]);
		pl_wg->wifi_id[32] = '\0';
	}
	
	printf("wifi_id:%s\n", pl_wg->wifi_id);


	int ret = mbedtls_base64_encode_x(pl_wg->wifi_id_base64, sizeof(pl_wg->wifi_id_base64), &len, pl_wg->wifi_id,strlen(pl_wg->wifi_id));
	if(ret == 0)
	{
		printf("wifi_id_base64: %s\n", pl_wg->wifi_id_base64);
	}
}

void mac_str_init(unsigned char *model_mac)
{
	t_WIFI_GLOBAL* pl_wg = MC_WIFI_GLOBAL_PTR();
	
	extern struct netif xnetif[NET_IF_NUM]; 
	model_mac = LwIP_GetMAC(&xnetif[0]);
	sprintf(pl_wg->mac_str, "%02x%02x%02x%02x%02x%02x",  model_mac[0], model_mac[1], model_mac[2], model_mac[3], model_mac[4], model_mac[5]);
	pl_wg->mac_str[12] = '\0';
	printf("mac str:%s\n", pl_wg->mac_str);
}


int wapi_get_rssi()
{
	int vl_rssi = 0;
	wifi_get_rssi(&vl_rssi);

	return vl_rssi;
}


void hsn_sys_reset(int num)
{
	vTaskDelay(100);
	vTaskDelay(100);
	vTaskDelay(100);
	printf("\n\r hsn_sys_reset: %d \n", num);
	vTaskDelay(100);
	vTaskDelay(100);
	vTaskDelay(100);
	sys_reset();
}


#if 0
void rlt_example_thread(int argc, char *argv[])
{
	int ret;
	unsigned char *model_mac;
	//set_log_printf_level(3);
	printf("module version: %s\n", CInfo);
#if 0
	if(rtl_cryptoEngine_init()!=0)
	{
		printf("crypto engine init failed\r\n");
	}
	else
	{
		printf("crypto engine init ok\r\n");
	}
#endif
	mac_str_init(model_mac);
	dev_id_init(model_mac);
	cJSON_Hooks_int();
    rlk_net_task_init();
	rlk_uart_task_init();

	watchdog_init(8000);	
	watchdog_irq_init(ilife_watchdog_irq_handler, 0);
	watchdog_start();
	
	while(1)
	{
		watchdog_refresh();
		vTaskDelay(3000);
		printf("m:%d,r:%d\n", xPortGetFreeHeapSize(), wapi_get_rssi());	
	}
}

#else

#define WLAN0_NAME_0		"wlan0"
int wapi_get_wifi_mode()
{
	int vl_mode = IW_MODE_INFRA;// 2 sta mode IW_MODE_INFRA
	
	wext_get_mode(WLAN0_NAME_0, &vl_mode);
	return vl_mode;
}




static xQueueHandle s_handle_mq_host_entry;
t_WAPI_MSG g_hostentry_msg;
A_UINT8	 g_hostentry_msgtype;
void* g_hostentry_callback;
A_UINT8  g_hostentry_header_len = 0;
A_UINT16 g_hostentry_msgbody_len = 0;
A_UINT8* gp_hostentry_msgheader = NULL;
A_UINT8* gp_hostentry_msgbody = NULL;
static A_UINT32 s_hostentry_statue_log = 0;
static A_UINT32 s_hostentry_statue_change = 0;
t_WIFI_GLOBAL* gp_hostentry_wg = MC_WIFI_GLOBAL_PTR();
t_CONFIG_TABLE_BODY* gp_hostentry_cfg = MC_WG_CONFIG_TABLE_PTR();


static xTimerHandle s_1hz_timer; // the timer handle of created FreeRTOS soft-timer



int wapi_send_mq_host_entry(A_UINT8 vp_msgtype, A_UINT8* pp_data, A_UINT32 vp_len, void* pp_callbak)
{
    int vl_ret = -1;
    t_WAPI_MSG vl_msg;
	A_UINT8* pl_data1 = NULL;
    memset(&vl_msg, 0, sizeof(vl_msg));
    
    vl_msg.v_msgtype = vp_msgtype;
	vl_msg.vp_callback = pp_callbak;
    
    if (NULL != pp_data && vp_len > 0)
    {
        A_UINT8* pl_data1 = (A_UINT8* )malloc(vp_len);
        if (NULL != pl_data1)
        {
            memcpy(pl_data1, pp_data, vp_len);
            vl_msg.p_msgbody = pl_data1;
            vl_msg.v_msgbody_len = vp_len; 
        }
    }
	SC_MSG_taskENTER_CRITICAL();
	//printf("www 1\n");
    //if (pdTRUE == xQueueSendToBackFromISR(s_handle_mq_host_entry, (void* )&vl_msg, 0))
	if (pdTRUE == xQueueSendToBack(s_handle_mq_host_entry, (void* )&vl_msg, 0))
    {
        vl_ret = 0;
    }
	else
	{
		if (NULL != pl_data1)
		{
			free(pl_data1);
		}	
	}
	SC_MSG_taskEXIT_CRITICAL();
	SC_SURREND_TASK();
    
    return vl_ret;
}

int wapi_send_mq_host_entry_isr(A_UINT8 vp_msgtype, A_UINT8* pp_data, A_UINT32 vp_len, void* pp_callbak)
{
    int vl_ret = -1;
    t_WAPI_MSG vl_msg;
	A_UINT8* pl_data1 = NULL;
    memset(&vl_msg, 0, sizeof(vl_msg));
    
    vl_msg.v_msgtype = vp_msgtype;
	vl_msg.vp_callback = pp_callbak;
    
    if (NULL != pp_data && vp_len > 0)
    {
        A_UINT8* pl_data1 = (A_UINT8* )malloc(vp_len);
        if (NULL != pl_data1)
        {
            memcpy(pl_data1, pp_data, vp_len);
            vl_msg.p_msgbody = pl_data1;
            vl_msg.v_msgbody_len = vp_len; 
        }
    }
	SC_MSG_taskENTER_CRITICAL();
	//printf("www 1\n");
    if (pdTRUE == xQueueSendToBackFromISR(s_handle_mq_host_entry, (void* )&vl_msg, 0))
	//if (pdTRUE == xQueueSendToBack(s_handle_mq_host_entry, (void* )&vl_msg, 0))
    {
        vl_ret = 0;
    }
	else
	{
		if (NULL != pl_data1)
		{
			free(pl_data1);
		}	
	}
	SC_MSG_taskEXIT_CRITICAL();
	SC_SURREND_TASK();
    
    return vl_ret;
}





static xTimerHandle s_get_dev_addr_timer; // the timer handle of created FreeRTOS soft-timer
void wapi_get_dev_addr_timer_cb(TimerHandle_t xTimer)
{
	//wapi_send_mq_host_entry(HOST_ENTRY_MSG_GET_DEV_ADDR, NULL, 0, NULL);
	cmd_0A_get_dev_addr_timer_handler();
	
}

void wapi_get_dev_addr_timer_init()
{
	s_get_dev_addr_timer = xTimerCreate("get_dev_addr_timer", 1000,
		pdTRUE, (void *)0, wapi_get_dev_addr_timer_cb);
	xTimerStart(s_get_dev_addr_timer, 0);
}

void wapi_get_dev_addr_timer_uninit()
{
	if (NULL != s_get_dev_addr_timer)
	{
		xTimerStop(s_get_dev_addr_timer, 0);
		xTimerDelete(s_get_dev_addr_timer, 0);
		s_get_dev_addr_timer = NULL;
	}
	
}


void wapi_1HZ_timer_cb(TimerHandle_t xTimer)
{   
    wapi_send_mq_host_entry(HOST_ENTRY_MSG_TIMER, NULL, 0, NULL);
}


extern unsigned int hsn_softap_config_time;
extern unsigned int hsn_ble_config_time;


int hsn_negotiate_featurecode()
{
	int ret = 0;
	t_WIFI_GLOBAL* pl_wg = MC_WIFI_GLOBAL_PTR();
	t_CONFIG_TABLE_BODY* pl_cfg = MC_WG_CONFIG_TABLE_PTR();
	unsigned char *model_mac;

	memset(pl_wg->v_featurecode, 0, sizeof(pl_wg->v_featurecode));
	memset(pl_wg->v_featurecode_aeskey, 0, sizeof(pl_wg->v_featurecode_aeskey));
	memset(pl_wg->v_cinfo_version, 0, sizeof(pl_wg->v_cinfo_version));
	
	if (HSN_DEVICE_TYPE_HEATING_STOVE == pl_wg->v_device_type
		|| HSN_DEVICE_TYPE_RANGE_HOOD == pl_wg->v_device_type
		|| HSN_DEVICE_TYPE_STOVE == pl_wg->v_device_type
		|| HSN_DEVICE_TYPE_WATER_HEATER_ELECTIC == pl_wg->v_device_type
		|| HSN_DEVICE_TYPE_WATER_HEATER_GAS == pl_wg->v_device_type
		|| HSN_DEVICE_TYPE_OVEN_1 == pl_wg->v_device_type
		|| HSN_DEVICE_TYPE_DISHWASHER == pl_wg->v_device_type)
	{
		memcpy(pl_wg->v_featurecode, HSN_FEATURECODE_KITCHEN, strlen(HSN_FEATURECODE_KITCHEN));
		if (ENVIRONMENT_RELEASE == pl_cfg->v_environment)
		{
			memcpy(pl_wg->v_featurecode_aeskey, HSN_RELEASE_KITCHEN_DEV_KEY, strlen(HSN_RELEASE_KITCHEN_DEV_KEY));
			memcpy(pl_wg->v_cinfo_version, HSN_RELEASE_CInfo, strlen(HSN_RELEASE_CInfo));
		}
		else if (ENVIRONMENT_TESTING == pl_cfg->v_environment)
		{
			memcpy(pl_wg->v_featurecode_aeskey, HSN_TESTING_KITCHEN_DEV_KEY, strlen(HSN_TESTING_KITCHEN_DEV_KEY));
			memcpy(pl_wg->v_cinfo_version, HSN_TESTING_CInfo, strlen(HSN_TESTING_CInfo));
		}
		else if (ENVIRONMENT_DEVELOP == pl_cfg->v_environment)
		{
			memcpy(pl_wg->v_featurecode_aeskey, HSN_DEVELOP_KITCHEN_DEV_KEY, strlen(HSN_DEVELOP_KITCHEN_DEV_KEY));
			memcpy(pl_wg->v_cinfo_version, HSN_DEVELOP_CInfo, strlen(HSN_DEVELOP_CInfo));
		}		
	}
	else if (HSN_DEVICE_TYPE_ICEBOX == pl_wg->v_device_type)
	{
		memcpy(pl_wg->v_featurecode, HSN_FEATURECODE_ICEBOX, strlen(HSN_FEATURECODE_ICEBOX));
		if (ENVIRONMENT_RELEASE == pl_cfg->v_environment)
		{
			memcpy(pl_wg->v_featurecode_aeskey, HSN_RELEASE_ICEBOX_DEV_KEY, strlen(HSN_RELEASE_ICEBOX_DEV_KEY));
			memcpy(pl_wg->v_cinfo_version, HSN_RELEASE_CInfo, strlen(HSN_RELEASE_CInfo));
		}
		else if (ENVIRONMENT_TESTING == pl_cfg->v_environment)
		{
			memcpy(pl_wg->v_featurecode_aeskey, HSN_TESTING_ICEBOX_DEV_KEY, strlen(HSN_TESTING_ICEBOX_DEV_KEY));
			memcpy(pl_wg->v_cinfo_version, HSN_TESTING_CInfo, strlen(HSN_TESTING_CInfo));
		}
		else if (ENVIRONMENT_DEVELOP == pl_cfg->v_environment)
		{
			memcpy(pl_wg->v_featurecode_aeskey, HSN_DEVELOP_ICEBOX_DEV_KEY, strlen(HSN_DEVELOP_ICEBOX_DEV_KEY));
			memcpy(pl_wg->v_cinfo_version, HSN_DEVELOP_CInfo, strlen(HSN_DEVELOP_CInfo));
		}
	}
	else if (HSN_DEVICE_TYPE_WASHING == pl_wg->v_device_type
		|| HSN_DEVICE_TYPE_DRYER == pl_wg->v_device_type
		)
	{
		memcpy(pl_wg->v_featurecode, HSN_FEATURECODE_WASHING, strlen(HSN_FEATURECODE_WASHING));
		if (ENVIRONMENT_RELEASE == pl_cfg->v_environment)
		{
			memcpy(pl_wg->v_featurecode_aeskey, HSN_RELEASE_WASHING_DEV_KEY, strlen(HSN_RELEASE_WASHING_DEV_KEY));
			memcpy(pl_wg->v_cinfo_version, HSN_RELEASE_CInfo, strlen(HSN_RELEASE_CInfo));
		}
		else if (ENVIRONMENT_TESTING == pl_cfg->v_environment)
		{
			memcpy(pl_wg->v_featurecode_aeskey, HSN_TESTING_WASHING_DEV_KEY, strlen(HSN_TESTING_WASHING_DEV_KEY));
			memcpy(pl_wg->v_cinfo_version, HSN_TESTING_CInfo, strlen(HSN_TESTING_CInfo));
		}
		else if (ENVIRONMENT_DEVELOP == pl_cfg->v_environment)
		{
			memcpy(pl_wg->v_featurecode_aeskey, HSN_DEVELOP_WASHING_DEV_KEY, strlen(HSN_DEVELOP_WASHING_DEV_KEY));
			memcpy(pl_wg->v_cinfo_version, HSN_DEVELOP_CInfo, strlen(HSN_DEVELOP_CInfo));
		}
	}	
	else
	{
		ret = -1;
		printf("unkown device type: %x\n", pl_wg->v_device_type);
	}

	

	printf("Featurecode: %s, dev_type:0x%02X\n", pl_wg->v_featurecode, pl_wg->v_device_type);
	printf("CInfo: %s EVN:%d\n", pl_wg->v_cinfo_version, pl_cfg->v_environment);
	//printf("featurecode_key: %s\n", pl_wg->v_featurecode_aeskey);

	if (0 == ret)
	{
		dev_id_init(model_mac, pl_wg->v_device_type);
	}

	return ret;
}




void wapi_host_entry_poll_init()
{
	t_WIFI_GLOBAL* pl_wg = MC_WIFI_GLOBAL_PTR();
	t_CONFIG_TABLE_BODY* pl_cfg = MC_WG_CONFIG_TABLE_PTR();
	int ret = 0;
	unsigned char *model_mac;
	
	memset(pl_wg, 0, sizeof(t_WIFI_GLOBAL));
	mac_str_init(model_mac);
	pl_wg->v_param_hb_time = 60;
	pl_wg->v_param_rp_time = 60;
	pl_wg->v_param_retry_time = 60;
	
	s_1hz_timer = xTimerCreate("1hz_timer", 1000, 
			pdTRUE, (void *)0, wapi_1HZ_timer_cb);
	xTimerStart(s_1hz_timer, 0);
	s_handle_mq_host_entry = xQueueCreate(MSG_COUNT, MSG_SIZE);
	memset(&g_hostentry_msg, 0, sizeof(g_hostentry_msg));
#if 1
	ret = bapi_config_read(pl_cfg);
	if (CONFIG_TABLE_OK == ret)
	{
		LOGT("Reboot flag:%d\n", pl_cfg->v_promise_reboot);
		LOGT("BT_MODE:%d\n", pl_cfg->v_bt_mode);
		LOGT("WIFI_MODE:%d\n", pl_cfg->v_cur_mode);
		LOGT("LAST_MODE:%d\n", pl_cfg->v_last_mode);
		WAPI_DUMP_HEX(pl_cfg->v_wifi_setting.ssid, 6, "router bssid:");
		LOGT("router pwd:%s\n", pl_cfg->v_wifi_setting.password);

		if (1 == pl_cfg->v_promise_reboot)
		{
			hsn_softap_config_time = HSN_KITCHE_SOFTAP_CONFIG_TIMEOUT_M;
			hsn_ble_config_time = HSN_KITCHE_BLE_CONFIG_TIMEOUT_M;
	
			pl_cfg->v_promise_reboot = 0;
			pl_wg->v_wifi_config_on = 1;
			bapi_set_write_config_flag();
		}
		else
		{
			hsn_softap_config_time = HSN_KITCHE_SOFTAP_CONFIG_TIMEOUT;
			hsn_ble_config_time = HSN_KITCHE_BLE_CONFIG_TIMEOUT;
		}

		if (WIFI_MODE_NETCONFIG == pl_cfg->v_cur_mode)
		{
			// ignore
		}
		else if (WIFI_MODE_STA == pl_cfg->v_cur_mode)
		{
			//ignore
		}
		else
		{
			hsn_reset_config_table(0);
			bapi_set_write_config_flag();
		}
	}
	else
	{
		hsn_reset_config_table(0);
		bapi_set_write_config_flag();
	}	



	
#if (HSN_ENFORE_EVN==1)
	pl_cfg->v_environment = HSS_DEAULT_ENVIRONMENT;
#endif
	LOGT("Environment(0:online,1:test,2:develop): %d\n", pl_cfg->v_environment);

	memset(pl_wg->v_cinfo_version, 0, sizeof(pl_wg->v_cinfo_version));
	if (ENVIRONMENT_RELEASE == pl_cfg->v_environment)
	{
		memcpy(pl_wg->v_cinfo_version, HSN_RELEASE_CInfo, strlen(HSN_RELEASE_CInfo));
	}
	else if (ENVIRONMENT_TESTING == pl_cfg->v_environment)
	{
		memcpy(pl_wg->v_cinfo_version, HSN_TESTING_CInfo, strlen(HSN_TESTING_CInfo));
	}
	else if (ENVIRONMENT_DEVELOP == pl_cfg->v_environment)
	{
		memcpy(pl_wg->v_cinfo_version, HSN_DEVELOP_CInfo, strlen(HSN_DEVELOP_CInfo));
	}

#else
	hsn_reset_config_table(0);
	bapi_set_write_config_flag();
	wapi_send_mq_host_entry(HOST_ENTRY_MSG_BT_START, NULL, 0, NULL);
	
	pl_cfg->v_environment = HSS_DEAULT_ENVIRONMENT;
	LOGT("Environment(0:online,1:test,2:develop): %d\n", pl_cfg->v_environment);
#endif
}



int hsn_bt_config_sta_change_cb(int vp_sta_type, int vp_sta, void* pp_ctx)
{
	printf("sta_change_cb: %d, %d\n", vp_sta_type, vp_sta);
	switch (vp_sta_type)
	{
		case HOST_ENTRY_MSG_BT_START:
			{
				if (1 == vp_sta)
				{
					//bt on 
					wapi_send_mq_host_entry(HOST_ENTRY_MSG_BT_FINISH, NULL, 0, NULL);

				}
				else if (0 == vp_sta)
				{
					//bt off

				}
				else
				{

				}
			}
			break;
		case HOST_ENTRY_MSG_UNBIND_DEV:
			{
				wapi_send_mq_host_entry(HOST_ENTRY_MSG_UNBIND_DEV_FINISH, NULL, 0, NULL);
			}
			break;
		case HOST_ENTRY_MSG_CONFIG_WIFI:
			{
				printf("start net config 00\r\n");
				wapi_send_mq_host_entry(HOST_ENTRY_MSG_CONFIG_WIFI_FINISH, NULL, 0, NULL);
			}
			break;
		case HOST_ENTRY_MSG_SMART_CONFIG:
			{
				wapi_send_mq_host_entry(HOST_ENTRY_MSG_SMART_CONFIG_FINISH, NULL, 0, NULL);
			}
			break;
		default:
			break;
	}
	
}



void wapi_host_entry_poll(void *param)
{
	int ret;
	t_WIFI_GLOBAL* pl_wg = MC_WIFI_GLOBAL_PTR();
	t_CONFIG_TABLE_BODY* pl_cfg = MC_WG_CONFIG_TABLE_PTR();
	t_CONFIG_TABLE_BODY vl_config;

	//ret= xQueueReceiveFromISR(s_handle_mq_host_entry, &g_hostentry_msg, NULL);
	ret = xQueueReceive(s_handle_mq_host_entry, &g_hostentry_msg, 10000);	
	if (pdPASS == ret)
	{
		g_hostentry_msgtype = g_hostentry_msg.v_msgtype;
		g_hostentry_callback = g_hostentry_msg.vp_callback;
		g_hostentry_header_len = g_hostentry_msg.v_header_len;
		g_hostentry_msgbody_len = g_hostentry_msg.v_msgbody_len;
		gp_hostentry_msgheader = g_hostentry_msg.p_msgheader;
		gp_hostentry_msgbody = g_hostentry_msg.p_msgbody;
		//printf("www 2 %d\n", g_hostentry_msgtype);

		switch (g_hostentry_msgtype)
		{
		case HOST_ENTRY_MSG_TIMER:
			if (isTimeOut(s_hostentry_statue_log, 5000))
			{
				timerReset(&s_hostentry_statue_log);
				printf("m:%d,%d,%d,mo:%d,%d,s:%d,%d,%d,%d,%d,wg:%d,%d,%d,%d,p:%d,%d,%d\n"
					, xPortGetFreeHeapSize(), wapi_get_rssi(), wapi_get_wifi_mode()
					, pl_cfg->v_cur_mode, pl_cfg->v_bt_mode
					, pl_wg->v_router_sta, pl_wg->v_cloud_login_sta
					, pl_wg->v_sniffer_sta, pl_wg->v_ap_sta, pl_wg->v_bt_sta
					, pl_wg->v_router_reconnect_flag, pl_wg->v_router_reconnect_cnt
					, pl_wg->v_cloud_reconnect_flag, pl_wg->v_cloud_reconnect_cnt
					, pl_wg->v_param_hb_time, pl_wg->v_param_rp_time, pl_wg->v_param_retry_time);
			}

			if (GET_DEV_ADDR_STATUE_FINISH == pl_wg->v_get_dev_addr_sta)
			{
				if (isTimeOut(s_hostentry_statue_change, 3000))
				{
					timerReset(&s_hostentry_statue_change);
					//watchdog_refresh();
					cmd_check_ox1E_timer_handler(NULL);
				}
			}
#if (HSN_WATCHDOW_CONFIG==1)	
			watchdog_refresh();
#endif
			bapi_config_write(pl_cfg);
			if (true == bapi_get_reboot_flag())
			{
				wapi_sys_reboot();
				//bapi_clear_reboot_flag();
			}
			
			break;
		case HOST_ENTRY_MSG_GET_DEV_ADDR:
			{
				cmd_0A_get_dev_addr_timer_handler();
				pl_wg->v_get_dev_addr_sta = GET_DEV_ADDR_STATUE_START;
			}
			break;
		case HOST_ENTRY_MSG_GET_DEV_ADDR_FINISH:
			{
				//if (GET_DEV_ADDR_STATUE_START == pl_wg->v_get_dev_addr_sta)
				{
					wapi_get_dev_addr_timer_uninit();
				
					//start get dev status
					pl_wg->v_get_dev_addr_sta = GET_DEV_ADDR_STATUE_FINISH;
					
					//start read flash config
					pl_wg->v_dev_addr_H = gp_hostentry_msgbody[BYTE_DEV_ADDR_H_POS];
					pl_wg->v_dev_addr_L = gp_hostentry_msgbody[BYTE_DEV_ADDR_L_POS];
					pl_wg->v_device_type = pl_wg->v_dev_addr_H;
					//pl_wg->v_device_type = 0x2A;
					printf("DEV ADDR: 0x%02X%02X\n", pl_wg->v_dev_addr_H, pl_wg->v_dev_addr_L);
					ret = hsn_negotiate_featurecode();
					if (0 == ret)
					{
						if (WIFI_MODE_STA == pl_cfg->v_cur_mode)
						{
							//wapi_send_net_msg(CONNECT_ROUTER_DEFALT, NULL, 0, NULL);
							wapi_send_mq_host_entry(HOST_ENTRY_MSG_BT_START, NULL, 0, NULL);
						}
						else if (WIFI_MODE_NETCONFIG == pl_cfg->v_cur_mode)
						{
							wapi_send_net_msg(HSN_NET_CONFIG, NULL, 0, NULL);
						}
						else
						{
							LOGW("unknow mode:%x\n", pl_cfg->v_cur_mode);
							hsn_reset_config_table(0);
							bapi_set_reboot_flag(15);
						}
					}
					else
					{
						bapi_set_reboot_flag(20);
					}
					
					//timerReset(&s_hostentry_statue_change);
				}
			}
			break;

		case HOST_ENTRY_MSG_BT_START:
			{
#if 0
				if (WIFI_MODE_SNIFFER == pl_cfg->v_cur_mode)
				{
					pl_wg->v_bt_config_sta = BT_CONFIG_STATUE_START;
					wapi_send_mq_host_entry(HOST_ENTRY_MSG_BT_FINISH, NULL, 0, NULL);
				}
				else if (WIFI_MODE_AP == pl_cfg->v_cur_mode)
				{
					pl_wg->v_bt_config_sta = BT_CONFIG_STATUE_START;
					wapi_send_mq_host_entry(HOST_ENTRY_MSG_BT_FINISH, NULL, 0, NULL);
				}
				else 
				{
					if (BT_MODE_ON == pl_cfg->v_bt_mode)
					{		
#if (HSN_START_SOFTAP==1)
						wapi_send_net_msg(SOFTAP_CONFIG_MODE, NULL, 0, NULL);
#else
						wapi_send_net_msg(SOFTAP_CONFIG_MODE, NULL, 0, NULL);
#endif
						wapi_send_net_msg(HSN_BLE_CONFIG_START, NULL, 0, (void* )hsn_bt_config_sta_change_cb);
					}
					else if (BT_MODE_IDLE == pl_cfg->v_bt_mode)
					{
						wapi_send_mq_host_entry(HOST_ENTRY_MSG_BT_FINISH, NULL, 0, NULL);
						pl_wg->v_bt_config_sta = BT_CONFIG_STATUE_START;
					}
					else
					{
						LOGW("unknow bt mode:%x\n", pl_cfg->v_bt_mode);
						hsn_reset_config_table(0);
						bapi_set_reboot_flag(16);
						//wapi_send_net_msg(HSN_BLE_CONFIG_START, NULL, 0, (void* )hsn_bt_config_sta_change_cb);
						
					}
				}
#else
				wapi_send_net_msg(HSN_BLE_CONFIG_START, NULL, 0, (void* )hsn_bt_config_sta_change_cb);
				pl_wg->v_bt_config_sta = BT_CONFIG_STATUE_START;

				
#if 0
				if (BT_MODE_ON == pl_cfg->v_bt_mode)
				{
					pl_wg->v_bt_config_sta = BT_CONFIG_STATUE_START;
					hsn_set_sta_change_cb(hsn_bt_config_sta_change_cb);
					//hsn_ble_app_deinit();
					pl_wg->v_bt_sta = HSN_BT_STATE_STARTING;
					hsn_ble_app_init();
					pl_wg->v_bt_sta = HSN_BT_STATE_STARTED;
					wapi_bt_config_timer_oneshot_init();
					//wapi_send_net_msg(HSN_BLE_CONFIG_START, NULL, 0, (void* )hsn_bt_config_sta_change_cb);
				}
				else if (BT_MODE_IDLE == pl_cfg->v_bt_mode)
				{
					wapi_send_mq_host_entry(HOST_ENTRY_MSG_BT_FINISH, NULL, 0, NULL);
					pl_wg->v_bt_config_sta = BT_CONFIG_STATUE_START;
				}
				else
				{
					LOGW("unknow bt mode:%x\n", pl_cfg->v_bt_mode);
					hsn_reset_config_table(0);
					bapi_set_reboot_flag(16);
					//wapi_send_net_msg(HSN_BLE_CONFIG_START, NULL, 0, (void* )hsn_bt_config_sta_change_cb);
				}
#endif
#endif
			}
			break;
			
		case HOST_ENTRY_MSG_BT_FINISH:
			{
				printf("bt init finish\n");
				if (BT_CONFIG_STATUE_START == pl_wg->v_bt_config_sta)
				{
					pl_wg->v_bt_config_sta = BT_CONFIG_STATUE_FINISH;
					
					if (WIFI_MODE_STA == pl_cfg->v_cur_mode)
					{
						wapi_send_net_msg(CONNECT_ROUTER_DEFALT, NULL, 0, NULL);
					}
					else if (WIFI_MODE_SNIFFER == pl_cfg->v_cur_mode)
					{
						wapi_send_net_msg(SMART_CONFIG_MODE, NULL, 0, NULL);
					}
					else if (WIFI_MODE_AP == pl_cfg->v_cur_mode)
					{
						wapi_send_net_msg(SOFTAP_CONFIG_MODE, NULL, 0, NULL);
					}
					else if (WIFI_MODE_IDLE == pl_cfg->v_cur_mode)
					{
						// wifi idle
					}
					else
					{
						LOGW("unknow mode:%x\n", pl_cfg->v_cur_mode);
						hsn_reset_config_table(0);
						bapi_set_reboot_flag(15);
					}
				}
			}
			break;
		
		case HOST_ENTRY_MSG_UNBIND_DEV:
			{
				if (pl_wg->v_dev_unbind_sta == DEV_UNBIND_STATUE_IDLE)
				{
					pl_wg->v_dev_unbind_sta = DEV_UNBIND_STATUE_START;

					printf("device unbind1\n");
					wapi_send_tcpsend_msg(DEVICE_LOGOUT, NULL, 0, (void* )hsn_bt_config_sta_change_cb);

				}
			}
			break;
		case HOST_ENTRY_MSG_UNBIND_DEV_FINISH:
			{
				if (pl_wg->v_dev_unbind_sta == DEV_UNBIND_STATUE_START)
				{
					pl_wg->v_dev_unbind_sta = DEV_UNBIND_STATUE_FINISH;
					pl_wg->v_dev_unbind_sta = DEV_UNBIND_STATUE_IDLE;
				}	
			}
			break;
		case HOST_ENTRY_MSG_CONFIG_WIFI:
			{
				printf("start net config 08 %d\r\n", pl_wg->v_wifi_config_sta);
				if (pl_wg->v_wifi_config_sta == WIFI_CONFIG_STATUE_IDLE)
				{
					printf("start net config 07\r\n");
					pl_wg->v_wifi_config_sta == WIFI_CONFIG_STATUE_START;
					wapi_send_net_msg(HSN_CONFIG_MODE, NULL, 0, (void* )hsn_bt_config_sta_change_cb);
				}	
			}
			break;
		case HOST_ENTRY_MSG_CONFIG_WIFI_FINISH:
			{
				printf("start net config 01\r\n");
				//if (pl_wg->v_wifi_config_sta == WIFI_CONFIG_STATUE_START)
				{
					pl_wg->v_wifi_config_sta == WIFI_CONFIG_STATUE_FINISH;
					pl_wg->v_wifi_config_sta == WIFI_CONFIG_STATUE_IDLE;
					printf("start net config 02\r\n");
					wapi_send_mq_host_entry(HOST_ENTRY_MSG_SMART_CONFIG, NULL, 0, NULL);
				}	
			}
			break;
		case HOST_ENTRY_MSG_SMART_CONFIG:
			{
				printf("start net config 03\r\n");
				if (pl_wg->v_smart_config_sta == SMART_CONFIG_STATUE_IDLE)
				{
					printf("start net config 04\r\n");
					pl_wg->v_smart_config_sta = SMART_CONFIG_STATUE_START;
					hsn_reset_config_table(0);
					pl_cfg->v_cur_mode = WIFI_MODE_NETCONFIG;
					pl_cfg->v_promise_reboot = 1;
					bapi_set_write_config_flag();
					bapi_set_reboot_flag(17);
					pl_wg->v_smart_config_sta = SMART_CONFIG_STATUE_FINISH;
					pl_wg->v_smart_config_sta = SMART_CONFIG_STATUE_IDLE;
				}
			}
			break;
		
		default:
			break;
		} 
		////////////////////////////////////
		//printf("%s runn \n", __FUNCTION__);
		
		if (NULL != gp_hostentry_msgheader)
		{
			free(gp_hostentry_msgheader);
			gp_hostentry_msgheader = NULL;
		}

		if (NULL != gp_hostentry_msgbody)
		{
			free(gp_hostentry_msgbody);
			gp_hostentry_msgbody = NULL;
		}
		memset(&g_hostentry_msg, 0, sizeof(g_hostentry_msg));
	} 
	vTaskDelay(1);
	//LOGW("queue timeout\n");
}

void test111(void)
{
	extern void uart_socket();
	uart_socket();
	while(1)
	{
		vTaskDelay(5000);
		printf("wait...\n");
	}
	
    uint8_t bt_addr[6];
    gap_get_param(GAP_PARAM_BD_ADDR, bt_addr);
	printf("local bd addr: 0x%2x:%2x:%2x:%2x:%2x:%2x\r\n",
                        bt_addr[5],
                        bt_addr[4],
                        bt_addr[3],
                        bt_addr[2],
                        bt_addr[1],
                        bt_addr[0]);
}




#define HSN_OTA_URL "http://api.wg.hismarttv.com/agw/ota/app/confirmUpgrade"  

extern unsigned char uart_recv_ok_flag;

void rlt_example_thread(void *para)
{
	int ret;
	t_WIFI_GLOBAL* pl_wg = MC_WIFI_GLOBAL_PTR();
	t_CONFIG_TABLE_BODY* pl_cfg = MC_WG_CONFIG_TABLE_PTR();
	
	//test111();
	printf("\r\nHsn Build Date: %s, %s \r\n",__DATE__, __TIME__ );
	
	wapi_host_entry_poll_init();
	rlk_net_task_init();
	hsn_entry_uart();
	
	wapi_get_dev_addr_timer_init();

#if (HSN_WATCHDOW_CONFIG==1)	
	printf("WDT ON...\n");
	watchdog_init(8000);	
	watchdog_irq_init(ilife_watchdog_irq_handler, 0);
	watchdog_start();
#endif
	//sniffer_func_entry();

		
	while(1)
	{
		wapi_host_entry_poll(NULL);
		//watchdog_refresh();
		//vTaskDelay(3000);
	}
}


//if (wifi_is_ready_to_transceive(RTW_STA_INTERFACE)== RTW_SUCCESS)



#endif

typedef int (*init_done_ptr)(void);
extern init_done_ptr p_wlan_init_done_callback;

int start_hisense()
{
	xTaskHandle app_task_handle = NULL;

	p_wlan_init_done_callback = NULL;
	if(xTaskCreate((TaskFunction_t)rlt_example_thread, (char const *)"hisnese_entry", 1024, NULL, tskIDLE_PRIORITY + HSN_TSK_PRIORITY, &app_task_handle) != pdPASS) {
		printf("xTaskCreate failed\n");	
	}
	printf("start hisense task handle\n");
	return 0;
}

void example_hisense(void)
{
	p_wlan_init_done_callback = start_hisense;
	//printf("OTA TEST 3\n");
}

