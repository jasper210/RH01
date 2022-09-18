/*
 * @Description: fac_check.h
 * @Author:xuetong
 * @Date: 2019-09-19 17:13:51
 * @LastEditTime: 2019-11-14 18:11:59
 * @LastEditors: Please set LastEditors
 */

#include "hsn_common.h"
xTaskHandle fac_func = NULL;
int fac_finish_flag = 0;

#include "gap_msg.h"
#include "gap_le_types.h"
#include "gap_scan.h"
#include "ble_central_app_flags.h"
#include "ble_central_at_cmd.h"

extern void *ble_central_evt_queue_handle;
extern void *ble_central_io_queue_handle;


#define HSN_WIFI_TEST_THRESHOLD		(-70)
#define HSN_BT_TEST_THRESHOLD		(-100)



unsigned char bssid_param[17] = {0};
#define TEST_HEAD  "====================TEST MODE start==================\r\n"
#define TEST_END  "====================TEST MODE end==================\r\n"
#define TEST_USURT "===================>USART TEST 0K\r\n"
#define TEST_RF_OK    "===================>RF TEST OK\r\n"
#define TEST_RF_FAIL    "===================>RF TEST FAIL!!!\r\n"
#define VER_HEAD  "WIFI MODULE VER:   "
#define MAC_HEAD  "MAC ADDR:   "
#define AP_HEAD   "Scan AP success: \r\n"

#define HSN_BT_HEAD  "BT ADDR:   "
#define HSN_BT_SCAN_START  "Scan BT success:\r\n"
#define TEST_BT_OK    "===================>BT TEST OK\r\n"
#define TEST_BT_FAIL    "===================>BT TEST FAIL!!!\r\n"






#define HSN_EVN_START  "====================EVN start==================\r\n"
#define HSN_EVN_END  "====================EVN end==================\r\n"
#define HSN_EVN_USE  "abcdef0/1/2/3/4, (0:oneline,1:test,2:develop,3:reset,4:info)\r\n"

#define HSN_EVN_FEATURE_CODE 	"Feature code: "
#define HSN_EVN_RELEASE			"EVN for online...\r\n"
#define HSN_EVN_TESTING			"EVN for testing...\r\n"
#define HSN_EVN_DEVELOP			"EVN for develop...\r\n"
#define HSN_EVN_RESET			"EVN reset to factory...\r\n"

#define HSN_ATHS_EVN_USE  "ATHS=0/1/2/3/4, (0:oneline,1:test,2:develop,3:reset,4:info)\r\n"







int wifi_test_ok_flag = 0;
int bt_test_ok_flag = 0;
int s_bt_test_scan_timeout = 6;
int g_if_test_bt = 0;

extern struct netif xnetif[NET_IF_NUM]; 
static void print_scan_result( rtw_scan_result_t* record )
{
    unsigned char temp_buff[256] = {0};

	if (0 == wifi_test_ok_flag)
	{
		sprintf((char* )temp_buff, "%s: %-20.20s         %s: %d%s", "SSID", record->SSID.val, "RSSI", record->signal_strength,"\r\n");
    	uart_data_send(temp_buff, strlen((char* )temp_buff));
		vTaskDelay(10);
	}
	
    if(record->signal_strength > HSN_WIFI_TEST_THRESHOLD)
    {
        wifi_test_ok_flag = 1;
    }

	
    
#if 0
    RTW_API_INFO( ( "%s\t ", ( record->bss_type == RTW_BSS_TYPE_ADHOC ) ? "Adhoc" : "Infra" ) );
    RTW_API_INFO( ( MAC_FMT, MAC_ARG(record->BSSID.octet) ) );
    RTW_API_INFO( ( " %d\t ", record->signal_strength ) );
    RTW_API_INFO( ( " %d\t  ", record->channel ) );
    RTW_API_INFO( ( " %d\t  ", record->wps_type ) );
    RTW_API_INFO( ( "%s\t\t ", ( record->security == RTW_SECURITY_OPEN ) ? "Open" :
                                 ( record->security == RTW_SECURITY_WEP_PSK ) ? "WEP" :
                                 ( record->security == RTW_SECURITY_WPA_TKIP_PSK ) ? "WPA TKIP" :
                                 ( record->security == RTW_SECURITY_WPA_AES_PSK ) ? "WPA AES" :
                                 ( record->security == RTW_SECURITY_WPA2_AES_PSK ) ? "WPA2 AES" :
                                 ( record->security == RTW_SECURITY_WPA2_TKIP_PSK ) ? "WPA2 TKIP" :
                                 ( record->security == RTW_SECURITY_WPA2_MIXED_PSK ) ? "WPA2 Mixed" :
                                 ( record->security == RTW_SECURITY_WPA_WPA2_MIXED ) ? "WPA/WPA2 AES" :
                                 "Unknown" ) );

    RTW_API_INFO( ( " %s ", record->SSID.val ) );
    RTW_API_INFO( ( "\r\n" ) );
#endif
}

static rtw_result_t app_scan_result_handler( rtw_scan_handler_result_t* malloced_scan_result )
{
	static int ApNum = 0;

	if (malloced_scan_result->scan_complete != RTW_TRUE) 
    {
		rtw_scan_result_t* record = &malloced_scan_result->ap_details;
		record->SSID.val[record->SSID.len] = 0; /* Ensure the SSID is null terminated */

#if CONFIG_EXAMPLE_UART_ATCMD || CONFIG_EXAMPLE_SPI_ATCMD
		at_printf("\r\nAP : %d,", ++ApNum);
#else
		//RTW_API_INFO( ( "%d\t ", ++ApNum ) );//lxd123
		ApNum = ++ApNum;
#endif
		print_scan_result(record);
#if CONFIG_INIC_CMD_RSP
		if(malloced_scan_result->user_data)
			memcpy((void *)((char *)malloced_scan_result->user_data+(ApNum-1)*sizeof(rtw_scan_result_t)), (char *)record, sizeof(rtw_scan_result_t));
#endif
	} 
    else
    {
#if CONFIG_INIC_CMD_RSP
		inic_c2h_msg("ATWS", RTW_SUCCESS, (char *)malloced_scan_result->user_data, ApNum*sizeof(rtw_scan_result_t));
		if(malloced_scan_result->user_data)
			free(malloced_scan_result->user_data);
		inic_c2h_msg("ATWS", RTW_SUCCESS, NULL, 0);
#endif
#if CONFIG_EXAMPLE_UART_ATCMD || CONFIG_EXAMPLE_SPI_ATCMD
		at_printf("\r\n[ATWS] OK");
		at_printf(STR_END_OF_ATCMD_RET);
#endif
		ApNum = 0;

		//uart test result
		uart_data_send(TEST_USURT, strlen(TEST_USURT));

		if (1 == g_if_test_bt)
		{
			//bt test result
			if(bt_test_ok_flag == 1)
		    {
		        uart_data_send(TEST_BT_OK, strlen(TEST_BT_OK));
		    }
			else
			{
				uart_data_send(TEST_BT_FAIL, strlen(TEST_BT_FAIL));
			}
		}
		
		//wifi test result 
		if(wifi_test_ok_flag == 1)
	    {
	        uart_data_send(TEST_RF_OK, strlen(TEST_RF_OK));
	    }
		else
		{
			uart_data_send(TEST_RF_FAIL, strlen(TEST_RF_FAIL));
		}

		uart_data_send(TEST_END, strlen(TEST_END));	
	}
/* 	vTaskDelete(fac_func);
	fac_func = NULL; */
	return RTW_SUCCESS;

}



static u8 sv_scan_is_processing = 0;
void hsn_start_bt_scan()
{
	u8 scan_filter_policy = GAP_SCAN_FILTER_ANY;
	uint8_t scan_filter_duplicate = GAP_SCAN_FILTER_DUPLICATE_ENABLE;
	t_WIFI_GLOBAL* pl_wg = MC_WIFI_GLOBAL_PTR();
	
	ble_central_app_init();
	
	unsigned char test_bt_addr[64] = {0};
	unsigned char bt_addr[6];
    gap_get_param(GAP_PARAM_BD_ADDR, bt_addr);
	
	memset(pl_wg->bt_addr, 0, sizeof(pl_wg->bt_addr));
	sprintf(pl_wg->bt_addr, "%02x%02x%02x%02x%02x%02x",  bt_addr[5], bt_addr[4], bt_addr[3], bt_addr[2], bt_addr[1], bt_addr[0]);
	sprintf((char* )test_bt_addr, "%s%s%s", HSN_BT_HEAD, pl_wg->bt_addr,"\r\n");
	uart_data_send(test_bt_addr, strlen((char* )test_bt_addr));

	uart_data_send(HSN_BT_SCAN_START, strlen(HSN_BT_SCAN_START));
	
	if (sv_scan_is_processing) 
	{
		printf("Scan is processing, please stop it first\n\r");
	} 
	else 
	{
		sv_scan_is_processing = 1;
		printf("Start scan, scan_filter_policy = %d, scan_filter_duplicate = %d\n\r", scan_filter_policy, scan_filter_duplicate);
		le_scan_set_param(GAP_PARAM_SCAN_FILTER_POLICY, sizeof(scan_filter_policy), &scan_filter_policy);
		le_scan_set_param(GAP_PARAM_SCAN_FILTER_DUPLICATES, sizeof(scan_filter_duplicate), &scan_filter_duplicate);
		ble_central_at_cmd_send_msg(3);
	}
}

void hsn_stop_bt_scan()
{
	if (sv_scan_is_processing) 
	{
		ble_central_at_cmd_send_msg(2);
		printf("Stop scan\n\r");
		sv_scan_is_processing = 0;
	} 
	else
		printf("There is no scan\n\r");

	ble_central_app_deinit();
}


#define HSN_BD_ADDR_FMT "%02x:%02x:%02x:%02x:%02x:%02x"
#define HSN_BD_ADDR_ARG(x) (x)[5],(x)[4],(x)[3],(x)[2],(x)[1],(x)[0]

void hsn_bt_scan_result(char *adv_type, char* remote_addr_type, unsigned char* bd_addr, signed char bt_rssi)
{
	char al_buf[128] = {0};
	memset(al_buf, 0, sizeof(al_buf));
	if (bt_rssi > HSN_BT_TEST_THRESHOLD)
	{
		bt_test_ok_flag = 1;
	}
	sprintf(al_buf, "%s\t\t"HSN_BD_ADDR_FMT"\t%s %d\n\r", adv_type, HSN_BD_ADDR_ARG(bd_addr), "RSSI:", bt_rssi);
	//sprintf(al_buf, "%s: %-20.20s%s: %s: %-20.20s%d\n\r", "TYPE:", adv_type, "ADDR:", HSN_BD_ADDR_ARG(bd_addr), "RSSI:", bt_rssi);
	
	uart_data_send(al_buf, strlen((char* )al_buf));
}



void enter_self_check_scan_mode_handle(void *para)
{
	log_printf_d("[%s]\n",__FUNCTION__);
	t_WIFI_GLOBAL* pl_wg = MC_WIFI_GLOBAL_PTR();
	int ret;
	unsigned char test_mac[64] = {0};
	unsigned char test_ver[64] = {0};
	fac_finish_flag = 1;
#if (HSN_WATCHDOW_CONFIG==1)	
	watchdog_refresh();
#endif
	uart_data_send(TEST_HEAD, strlen(TEST_HEAD));
	sprintf((char* )test_ver, "%s%s%s", VER_HEAD, pl_wg->v_cinfo_version,"\r\n");
	uart_data_send(test_ver, strlen((char* )test_ver));
	sprintf((char* )test_mac, "%s%s%s", MAC_HEAD, pl_wg->mac_str,"\r\n");
	uart_data_send(test_mac, strlen((char* )test_mac));
	
#if 0
#if (HSN_WATCHDOW_CONFIG==1)	
	watchdog_refresh();
#endif
	hsn_ble_init_for_factory();
	//hsn_ble_app_init();

	unsigned char test_bt_addr[64] = {0};
	unsigned char bt_addr[6];
    gap_get_param(GAP_PARAM_BD_ADDR, bt_addr);
	
	memset(pl_wg->bt_addr, 0, sizeof(pl_wg->bt_addr));
	sprintf(pl_wg->bt_addr, "%02x%02x%02x%02x%02x%02x",  bt_addr[0], bt_addr[1], bt_addr[2], bt_addr[3], bt_addr[4], bt_addr[5]);
	sprintf((char* )test_bt_addr, "%s%s%s", HSN_BT_HEAD, pl_wg->bt_addr,"\r\n");
	uart_data_send(test_bt_addr, strlen((char* )test_bt_addr));
#endif	

	if (1 == g_if_test_bt)
	{
		hsn_stop_bt_scan();
		hsn_start_bt_scan();
		
		//int vl_cnt = 11;
		do {
			os_delay(1000);
			s_bt_test_scan_timeout--;
			watchdog_refresh();
			printf("scaning...\n");
		}while(s_bt_test_scan_timeout);

		hsn_stop_bt_scan();
		vTaskDelay(10);
	}
	
	wifi_scan_networks(app_scan_result_handler, NULL);
	{
		uart_data_send(AP_HEAD, strlen(AP_HEAD));
	}

    vTaskDelay(2000);

	wifi_test_ok_flag = 0;
	bt_test_ok_flag = 0;
	fac_finish_flag = 0;

	vTaskDelete(NULL);	
}


int rlk_fac_check_init()
{
	if(xTaskCreate((TaskFunction_t)enter_self_check_scan_mode_handle, (char const *)"rlk fac check task", 1024, NULL, tskIDLE_PRIORITY + 5, fac_func) != pdPASS) {
		printf("xTaskCreate failed\n");	
		bapi_set_reboot_flag(1);
	}
	return 0;
}


void hsn_factory_switch_evn(char vp_flag)
{//abcdef+r/t/d/i
	t_WIFI_GLOBAL* pl_wg = MC_WIFI_GLOBAL_PTR();
	t_CONFIG_TABLE_BODY* pl_cfg = MC_WG_CONFIG_TABLE_PTR();

	unsigned char al_buf[80] = {0};

	extern void wapi_get_dev_addr_timer_uninit();
	wapi_get_dev_addr_timer_uninit();

	uart_data_send(HSN_EVN_START, strlen(HSN_EVN_START));
	uart_data_send(HSN_EVN_USE, strlen(HSN_EVN_USE));
	
		
	if ('0' == vp_flag)
	{//release
		printf("%s", HSN_EVN_RELEASE);
		uart_data_send(HSN_EVN_RELEASE, strlen(HSN_EVN_RELEASE));
		
		hsn_reset_config_table(0);
		pl_cfg->v_environment = ENVIRONMENT_RELEASE;
		bapi_set_write_config_flag();
	} 
	else if ('1' == vp_flag)
	{//testing
		printf("%s", HSN_EVN_TESTING);
		uart_data_send(HSN_EVN_TESTING, strlen(HSN_EVN_TESTING));
		
		hsn_reset_config_table(0);
		pl_cfg->v_environment = ENVIRONMENT_TESTING;
		bapi_set_write_config_flag();
	}
	else if ('2' == vp_flag)
	{//develop
		printf("%s", HSN_EVN_DEVELOP);
		uart_data_send(HSN_EVN_DEVELOP, strlen(HSN_EVN_DEVELOP));
		
		hsn_reset_config_table(0);
		pl_cfg->v_environment = ENVIRONMENT_DEVELOP;
		bapi_set_write_config_flag();
	}
	else if ('3' == vp_flag)
	{//reset to factory
		printf("%s", HSN_EVN_RESET);
		uart_data_send(HSN_EVN_RESET, strlen(HSN_EVN_RESET));
		
		hsn_reset_config_table(0);
		bapi_set_write_config_flag();
		bapi_set_reboot_flag(40);
	}
	else if ('4' == vp_flag)
	{//version
		memset(al_buf, 0, sizeof(al_buf));
		sprintf((char* )al_buf, "%s%s   %s %s%s", VER_HEAD, pl_wg->v_cinfo_version, __DATE__, __TIME__,"\r\n");
		uart_data_send(al_buf, strlen((char* )al_buf));
		printf("%s", al_buf);

		memset(al_buf, 0, sizeof(al_buf));
		sprintf((char* )al_buf, "%s%s%s", MAC_HEAD, pl_wg->mac_str,"\r\n");
		uart_data_send(al_buf, strlen((char* )al_buf));
		printf("%s", al_buf);
		
		if (ENVIRONMENT_RELEASE == pl_cfg->v_environment)
		{
			printf("%s", HSN_EVN_RELEASE);
			uart_data_send(HSN_EVN_RELEASE, strlen(HSN_EVN_RELEASE));
		}
		else if (ENVIRONMENT_TESTING == pl_cfg->v_environment)
		{
			printf("%s", HSN_EVN_TESTING);
			uart_data_send(HSN_EVN_TESTING, strlen(HSN_EVN_TESTING));
		}
		else if (ENVIRONMENT_DEVELOP == pl_cfg->v_environment)
		{
			printf("%s", HSN_EVN_DEVELOP);
			uart_data_send(HSN_EVN_DEVELOP, strlen(HSN_EVN_DEVELOP));
		}
	}
	else
	{//
		printf("unknow cmd:%c\n", vp_flag);
	}

	uart_data_send(HSN_EVN_END, strlen(HSN_EVN_END));
	
}


// ATHS
void hsn_factory_switch_evn_ex(unsigned char vp_flag)
{//0/1/2/3
	t_WIFI_GLOBAL* pl_wg = MC_WIFI_GLOBAL_PTR();
	t_CONFIG_TABLE_BODY* pl_cfg = MC_WG_CONFIG_TABLE_PTR();

	unsigned char al_buf[80] = {0};

	printf("%s", HSN_ATHS_EVN_USE);
		
	if (0 == vp_flag)
	{//release
		printf("%s", HSN_EVN_RELEASE);
		
		hsn_reset_config_table(0);
		pl_cfg->v_environment = ENVIRONMENT_RELEASE;
		bapi_set_write_config_flag();
	} 
	else if (1 == vp_flag)
	{//testing
		printf("%s", HSN_EVN_TESTING);
		
		hsn_reset_config_table(0);
		pl_cfg->v_environment = ENVIRONMENT_TESTING;
		bapi_set_write_config_flag();
	}
	else if (2 == vp_flag)
	{//develop
		printf("%s", HSN_EVN_DEVELOP);
		
		hsn_reset_config_table(0);
		pl_cfg->v_environment = ENVIRONMENT_DEVELOP;
		bapi_set_write_config_flag();
	}
	else if (3 == vp_flag)
	{//reset to factory
		printf("%s", HSN_EVN_RESET);
		
		hsn_reset_config_table(0);
		bapi_set_write_config_flag();
		bapi_set_reboot_flag(40);
	}
	else if (4 == vp_flag)
	{//info
		memset(al_buf, 0, sizeof(al_buf));
		sprintf((char* )al_buf, "%s%s   %s %s%s", VER_HEAD, pl_wg->v_cinfo_version, __DATE__, __TIME__,"\r\n");
		printf("%s", al_buf);

		memset(al_buf, 0, sizeof(al_buf));
		sprintf((char* )al_buf, "%s%s%s", MAC_HEAD, pl_wg->mac_str,"\r\n");
		printf("%s", al_buf);
		
		if (ENVIRONMENT_RELEASE == pl_cfg->v_environment)
		{
			printf("%s", HSN_EVN_RELEASE);
		}
		else if (ENVIRONMENT_TESTING == pl_cfg->v_environment)
		{
			printf("%s", HSN_EVN_TESTING);
		}
		else if (ENVIRONMENT_DEVELOP == pl_cfg->v_environment)
		{
			printf("%s", HSN_EVN_DEVELOP);
		}
		
	}
	else
	{//
		printf("unknow cmd:%c\n", vp_flag);
	}	
#if 0
	bapi_config_write(pl_cfg);
	if (true == bapi_get_reboot_flag())
	{
		wapi_sys_reboot();
		//bapi_clear_reboot_flag();
	}
#endif
}



unsigned char temp_bssid[17] = {0};

void ssid_save_to_flash(char *ssid)
{
	t_CONFIG_TABLE_BODY* pl_cfg = MC_WG_CONFIG_TABLE_PTR();
	int ret;

	memset(pl_cfg->v_wifi_setting.ssid, 0, sizeof(pl_cfg->v_wifi_setting.ssid));
	memcpy(pl_cfg->v_wifi_setting.ssid, ssid, strlen(ssid));
	
	pl_cfg->v_router_info_flag = BAPI_CONFIG_FLAG;
	pl_cfg->v_cur_mode = WIFI_MODE_STA;
	bapi_set_write_config_flag();
	bapi_set_reboot_flag(2);
}


static void my_scan_result( rtw_scan_result_t* record )
{
    //unsigned char temp_buff[256] = {0};
    //sprintf(temp_buff, "%s: %s         %s: %d%s", "SSID", record->SSID.val, "RSSI", record->signal_strength,"\r\n");
    //printf("bssid: %s\n", MAC_ARG(record->BSSID.octet));
	sprintf(temp_bssid,"%02x:%02x:%02x:%02x:%02x:%02x", MAC_ARG(record->BSSID.octet));
	printf("bssid temp:%s\n", temp_bssid);
    printf("bssid param:%s\n", bssid_param);
	if((strcmp(temp_bssid, bssid_param) == 0))
	{
		printf("got it\n");
		printf("ssid: %s\n", record->SSID.val);
		ssid_save_to_flash(record->SSID.val);

	}
}



static rtw_result_t my_scan_result_handler( rtw_scan_handler_result_t* malloced_scan_result )
{
	static int ApNum = 0;

	if (malloced_scan_result->scan_complete != RTW_TRUE) 
    {
		rtw_scan_result_t* record = &malloced_scan_result->ap_details;
		record->SSID.val[record->SSID.len] = 0; /* Ensure the SSID is null terminated */
		my_scan_result(record);
	} 
    else
    {
		ApNum = 0;
	}
	return RTW_SUCCESS;
}


void enter_ssid_get_handle(void *param)
{
	t_CONFIG_TABLE_BODY* pl_cfg = MC_WG_CONFIG_TABLE_PTR();

	printf("bssid param:%s\n", pl_cfg->v_wifi_setting.ssid);
	memcpy(bssid_param, pl_cfg->v_wifi_setting.ssid, 17);
	
	
	wifi_scan_networks(my_scan_result_handler, NULL);
    while (1)
    {
        	vTaskDelay(3000);
    }  
}


int rlk_get_ssid_init(unsigned char *bssid)
{
	xTaskHandle app_task_handle = NULL;

	if(xTaskCreate((TaskFunction_t)enter_ssid_get_handle, (char const *)"rlk fac check task", 1024, bssid, tskIDLE_PRIORITY + 5, &app_task_handle) != pdPASS) {
		printf("xTaskCreate failed\n");	
	}
	printf("rlk_get_ssid_init success\n");
	return 0;
}

