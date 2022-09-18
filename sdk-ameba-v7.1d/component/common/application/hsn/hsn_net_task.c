/*
 * @Description: rlt_net_task.c
 * @Author: xuetong
 * @Date: 2019-08-05 08:48:44
 * @LastEditTime: 2019-11-01 18:24:54
 * @LastEditors: Please set LastEditors
 */
#include "hsn_common.h"



xQueueHandle s_net_queue;
extern unsigned char uart_recv_ok_flag;
extern gtimer_t config_timer;

extern struct netif xnetif[NET_IF_NUM]; 
unsigned char config_bssid[6] = {0};
unsigned char config_passwd[65] = {0};
int config_passwd_len = 0;
extern unsigned char wifi_status;  
extern int tcp_socket_fd;




int wapi_send_net_msg(int msg_flag,unsigned char *data,unsigned int data_len, void* pp_callback)
{
	return rlt_msg_queue_send(s_net_queue, msg_flag, data, data_len, pp_callback);
}

int wapi_send_net_msg_isr(int msg_flag,unsigned char *data,unsigned int data_len, void* pp_callback)
{
	return rlt_msg_queue_send_isr(s_net_queue, msg_flag, data, data_len, pp_callback);
}






static void wifi_no_network_cb(char* buf, int buf_len, int flags, void* userdata)
{
	log_printf_w("[%s]no network\n",__FUNCTION__);
}

static void wifi_connected_cb( char* buf, int buf_len, int flags, void* userdata)
{
	log_printf_d("[%s]wifi connect\n",__FUNCTION__);
	t_WIFI_GLOBAL* pl_wg = MC_WIFI_GLOBAL_PTR();
}

static void wifi_disconn_cb( char* buf, int buf_len, int flags, void* userdata)
{
	log_printf_w("[%s]wifi disconnect\n",__FUNCTION__);
	t_WIFI_GLOBAL* pl_wg = MC_WIFI_GLOBAL_PTR();
	t_CONFIG_TABLE_BODY* pl_cfg = MC_WG_CONFIG_TABLE_PTR();

	pl_wg->v_router_sta = HSN_ROUTER_STATE_DISCONNET;
	pl_wg->v_cloud_login_sta = HSN_LOGIN_STATE_DISCONNET;

	if (WIFI_MODE_STA == pl_cfg->v_cur_mode)
	{
		printf("wifi disconn, start reconnect\n");
		pl_wg->v_router_reconnect_flag = 1;
	}
}

#if 0

typedef struct tagHisenRouterInfo {
	char ssid[33];
	unsigned char ssid_len;
	
	char pwd[65];
	unsigned char pwd_len;
	
	unsigned char bssid[6];
	unsigned char bssid_len;
	
	unsigned long security_type;
	int key_id;

} t_HISEN_ROUTER_INFO;




int hisen_connect_ap_1(t_HISEN_ROUTER_INFO *pp_router_info)
{
	int mode, ret = 0;
	unsigned long tick1 = xTaskGetTickCount();
	unsigned long tick2, tick3;
	char empty_bssid[6] = {0}, assoc_by_bssid = 0;	
	int dhcp_retry = 1;	
	unsigned char *ip_str[16] = {0};
	unsigned char *ip;
	
	if(memcmp (pp_router_info->bssid, empty_bssid, 6))
		assoc_by_bssid = 1;
	else if(pp_router_info->ssid[0] == 0){
		printf("SSID can't be empty\n\r");
		ret = RTW_BADARG;
		goto EXIT;
	}
	if(pp_router_info->pwd_len != 0){
		if((pp_router_info->key_id >= 0)&&(pp_router_info->key_id <= 3)) {
			pp_router_info->security_type = RTW_SECURITY_WEP_PSK;
		}
		else{
			pp_router_info->security_type = RTW_SECURITY_WPA2_AES_PSK;
		}
	}
	else{
		pp_router_info->security_type = RTW_SECURITY_OPEN;
	}
	//Check if in AP mode
	wext_get_mode(WLAN0_NAME, &mode);
	if(mode == IW_MODE_MASTER) {
		dhcps_deinit();
#if defined(CONFIG_PLATFORM_8710C) && (defined(CONFIG_BT) && CONFIG_BT)
		if (wifi_set_mode(RTW_MODE_STA) < 0){
		    printf("\n\rERROR: Wifi on failed!");
		    ret = RTW_ERROR;
		    goto EXIT;
		}
#else	
		wifi_off();
		vTaskDelay(20);
		if (wifi_on(RTW_MODE_STA) < 0){
		    printf("\n\rERROR: Wifi on failed!");
		    ret = RTW_ERROR;
		    goto EXIT;
		}	
#endif
	}

#if 0 //get security mode from scan list
	u8 connect_channel;
	u8 pscan_config;
	//the keyID may be not set for WEP which may be confued with WPA2 
	if((pp_router_info->security_type == RTW_SECURITY_UNKNOWN)||(pp_router_info->security_type == RTW_SECURITY_WPA2_AES_PSK))
	{
		int security_retry_count = 0;
		while (1) {
			if (_get_ap_security_mode((char*)pp_router_info->ssid.val, &pp_router_info->security_type, &connect_channel))
				break;
			security_retry_count++;
			if(security_retry_count >= 3){
				printf("Can't get AP security mode and channel.\n");
				ret = RTW_NOTFOUND;
				goto EXIT;
			}
		}
		if(pp_router_info->security_type == RTW_SECURITY_WEP_PSK || pp_router_info->security_type == RTW_SECURITY_WEP_SHARED)
			pp_router_info->key_id = (pp_router_info->key_id <0 || pp_router_info->key_id >3)?0:pp_router_info->key_id;
	}
        pscan_config = PSCAN_ENABLE;
	if(connect_channel > 0 && connect_channel < 14)
		wifi_set_pscan_chan(&connect_channel, &pscan_config, 1);
#endif

	wifi_reg_event_handler(WIFI_EVENT_NO_NETWORK,wifi_no_network_cb,NULL);
	wifi_reg_event_handler(WIFI_EVENT_CONNECT, wifi_connected_cb, NULL);
	wifi_reg_event_handler(WIFI_EVENT_DISCONNECT, wifi_disconn_cb, NULL);

	if(assoc_by_bssid){
		printf("\n\rJoining BSS by BSSID "MAC_FMT" ...\n\r", MAC_ARG(pp_router_info->bssid));
		ret = wifi_connect_bssid(pp_router_info->bssid, (char*)pp_router_info->ssid, pp_router_info->security_type, (char*)pp_router_info->pwd, 
						ETH_ALEN, pp_router_info->ssid_len, pp_router_info->pwd_len, pp_router_info->key_id, NULL);		
	} else {
		printf("\n\rJoining BSS by SSID %s...\n\r", (char*)pp_router_info->ssid);
		ret = wifi_connect((char*)pp_router_info->ssid, pp_router_info->security_type, (char*)pp_router_info->pwd, pp_router_info->ssid_len,
						pp_router_info->pwd_len, pp_router_info->key_id, NULL);
	}
	
	if(ret!= RTW_SUCCESS){
		if(ret == RTW_INVALID_KEY)
			printf("\n\rERROR:Invalid Key ");
		
		printf("\n\rERROR: Can't connect to AP");
		goto EXIT;
	}
	tick2 = xTaskGetTickCount();
	printf("\r\nConnected after %dms.\n", (tick2-tick1));

Try_again:	
	printf("Start DHCPClient\n");
	ret = LwIP_DHCP(0, DHCP_START);	
	if(ret == DHCP_ADDRESS_ASSIGNED) 
	{
		tick3 = xTaskGetTickCount();
		printf("\r\n\nGot IP after %dms.\n", (tick3-tick1));
		ip = LwIP_GetIP(&xnetif[0]);	
		sprintf((char *)ip_str,"%d.%d.%d.%d",ip[0],ip[1],ip[2],ip[3]);
		log_printf_d("[%s]IP:%s\n",__FUNCTION__,ip_str);
		return 0;
	} 
	else 
	{
		if(dhcp_retry)
		{
			log_printf_w("[%s]dhcp error,retry\n",__FUNCTION__);
			dhcp_retry--;
			goto Try_again;
		} 
		else 
		{
			log_printf_w("[%s]dhcp error\n",__FUNCTION__);
			goto EXIT;
		}
	}
		
EXIT:
	return -1;
}


void hisen_init_wifi_struct(t_HISEN_ROUTER_INFO *pp_router_info)
{
	unsigned char al_bssid[6] = {0};
	memset(pp_router_info, 0, sizeof(t_HISEN_ROUTER_INFO));
	pp_router_info->bssid_len = 6;
	pp_router_info->key_id = -1;
	pp_router_info->security_type = -1;
}


typedef struct rtw_wifi_setting {
	rtw_mode_t		mode;
	unsigned char 		ssid[33];
	unsigned char		channel;
	rtw_security_t		security_type;
	unsigned char 		password[65];
	unsigned char		key_idx;
}rtw_wifi_setting_t;



int connect_wifi_config(rtw_wifi_setting_t *wifi_info)
{
	t_HISEN_ROUTER_INFO vl_router_info;
	hisen_init_wifi_struct(&vl_router_info);
	
	if(wifi_info == NULL)
	{
		memcpy(vl_router_info.pwd, config_passwd, 65);
		vl_router_info.pwd_len = config_passwd_len;
		
		memcpy(vl_router_info.bssid, config_bssid, 6);
		vl_router_info.bssid_len = 6;
	}
	else
	{
		memcpy(vl_router_info.bssid, config_bssid, 6);
		vl_router_info.bssid_len = 6;

		vl_router_info.pwd_len = (int)strlen((char const *)wifi_info->password);
		memcpy(vl_router_info.pwd, wifi_info->password, vl_router_info.pwd_len);
	}
	
	
	return hisen_connect_ap_1(&vl_router_info);
}


#else

#define XT_SSID "ant_wifi"
#define XT_PASSWD "12345678"
unsigned char bssid_temp[6] = {0x00, 0x1c, 0xa3, 0x1c, 0xac, 0x98};
int connect_wifi_config(rtw_wifi_setting_t *wifi_info, unsigned char vp_flag_ssid)
{
 	unsigned long tick1;
	unsigned long tick2, tick3;

	unsigned int start_time;
	unsigned int current_time;
	int mode;
	
	int passwd_len = 0;
	unsigned char bssid_buff[6] = {0};
	unsigned char passwd_buff[65] = {0};
	unsigned char *ip_str[16] = {0};
	unsigned char *ip;
	int ret;
	int dhcp_retry = 1;	
	int timeout = 20;
	char essid[33] = {0};
	char al_ssid_buff[33] = {0};
	unsigned char vl_ssid_len = 0;

	if (0 == vp_flag_ssid)
	{		
		char empty_bssid[6] = {0};
		ret = memcmp(wifi_info->ssid, empty_bssid, 6);
		if(0 == ret)
		{
			printf("Error: SSID can't be empty\n\r");
			return -1;
		}
	}
	else
	{
		if (strlen(wifi_info->ssid) <= 0)
		{
			printf("Error: SSID can't be empty\n\r");
			return -1;
		}
	}

	//Check if in AP mode
	wext_get_mode(WLAN0_NAME, &mode);
	if(mode == IW_MODE_MASTER) {
#if CONFIG_LWIP_LAYER
		dhcps_deinit();
#endif
#if defined(CONFIG_PLATFORM_8710C) && (defined(CONFIG_BT) && CONFIG_BT)
		if (wifi_set_mode(RTW_MODE_STA) < 0){
		    printf("\n\rERROR: Wifi on failed!");
		    ret = RTW_ERROR;
		    return -1;
		}
#else	
		wifi_off();
		vTaskDelay(20);
		if (wifi_on(RTW_MODE_STA) < 0){
		    printf("\n\rERROR: Wifi on failed!");
		    ret = RTW_ERROR;
		    return -1;
		}	
#endif
	}
#if 0	
	if(wext_get_ssid(WLAN0_NAME, (unsigned char *) essid) < 0) {
		printf("\n\rnot connected yet");
	}
	else
	{
		printf("\n\rxx connected xxxxx\n");
		if((ret = wifi_disconnect()) < 0) {
			printf("\n\rERROR: Operation failed!");
			return -1;
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
	}
#endif
	
	
	wifi_reg_event_handler(WIFI_EVENT_NO_NETWORK,wifi_no_network_cb,NULL);
	wifi_reg_event_handler(WIFI_EVENT_CONNECT, wifi_connected_cb, NULL);
	wifi_reg_event_handler(WIFI_EVENT_DISCONNECT, wifi_disconn_cb, NULL);

	if (0 == vp_flag_ssid)
	{
		memcpy(bssid_buff, wifi_info->ssid, 6);
	}
	else
	{
		vl_ssid_len = strlen(wifi_info->ssid);
		memset(al_ssid_buff, 0, sizeof(al_ssid_buff));
		memcpy(al_ssid_buff, wifi_info->ssid, vl_ssid_len);
	}
	
	
	passwd_len = (int)strlen((char const *)wifi_info->password);
	memcpy(passwd_buff, wifi_info->password, passwd_len);
	passwd_buff[passwd_len] = '\0';

#if 0
	passwd_len = 0;
	printf("set passwd null\n");
#endif
	printf("router info:");
	if (0 == vp_flag_ssid)
	{
		print_hex(bssid_buff, 6);
	}
	else
	{
		printf("ssid: %s\n", al_ssid_buff);
	}
	
	printf("passwd: %s\n", passwd_buff);

	//wifi_set_autoreconnect(0);

	start_time = xTaskGetTickCount();
	tick1 = xTaskGetTickCount();
	while(1)
	{
		current_time = xTaskGetTickCount();
		if((current_time - start_time) > (30 * configTICK_RATE_HZ))
		{
			printf("connect_wifi timeout\n");
			return -1;
		}

		if (0 == vp_flag_ssid)
		{
			if(passwd_len == 0)
			{
				ret = wifi_connect_bssid((char*)bssid_buff,  NULL,  RTW_SECURITY_OPEN, 
				NULL,  6,  0,  0,  0,  NULL);
			}
			else
			{
				if(passwd_len > 64)
				{
					bapi_set_reboot_flag(8);
				}
				ret = wifi_connect_bssid((char*)bssid_buff,  NULL,  RTW_SECURITY_WPA2_AES_PSK, 
				(char*)passwd_buff,  6,  0,  passwd_len,  0,  NULL);
			}
		}
		else
		{
			if(passwd_len == 0)
			{
				ret = wifi_connect((char*)al_ssid_buff, RTW_SECURITY_OPEN, NULL, vl_ssid_len, 0, 0, NULL);
			}
			else
			{
				if(passwd_len > 64)
				{
					bapi_set_reboot_flag(8);
				}

				ret = wifi_connect((char*)al_ssid_buff, RTW_SECURITY_WPA2_AES_PSK, (char*)passwd_buff, vl_ssid_len,
						passwd_len, 0, NULL);
			}
			
		}	
		
		
		if(ret!= RTW_SUCCESS)
		{
			printf("\n\rERROR: Can't connect to AP %dms.\n", (tick2-tick1));
		}
		else
		{
			tick2 = xTaskGetTickCount();
			printf("\r\nConnected1 after %dms.\n", (tick2-tick1));
			break;
		}
		vTaskDelay(1500);
	}
Try_again:	
	vTaskDelay(100);
	printf("start getting ip\n");
	ret = LwIP_DHCP(0, DHCP_START);	
	if(ret != DHCP_ADDRESS_ASSIGNED) 
	{
		if(dhcp_retry)
		{
			log_printf_w("[%s]dhcp error,retry\n",__FUNCTION__);
			dhcp_retry--;
			goto Try_again;
		} 
		else 
		{
			log_printf_w("[%s]dhcp error\n",__FUNCTION__);
			return -1;
		}
	} 
	else 
	{
		ip = LwIP_GetIP(&xnetif[0]);	
		sprintf((char *)ip_str,"%d.%d.%d.%d",ip[0],ip[1],ip[2],ip[3]);
		log_printf_d("[%s]IP:%s\n",__FUNCTION__,ip_str);
		return 0;
	}
}
#endif


extern int fATWC_ex(void *arg);
extern void fATW0(void *arg);
extern void fATW1(void *arg);
extern void fATW6(void *arg);


int connect_wifi_config_ex(rtw_wifi_setting_t *wifi_info, unsigned char vp_flag_ssid)
{
	char al_mac_str[13];
	memset(al_mac_str, 0, 13);
	sprintf(al_mac_str, "%02X:%02X:%02X:%02X:%02X:%02X", wifi_info->ssid[0]
														, wifi_info->ssid[1]
														, wifi_info->ssid[2]
														, wifi_info->ssid[3]
														, wifi_info->ssid[4]
														, wifi_info->ssid[5]);
	printf("router: %s,%s \r\n", al_mac_str, wifi_info->password);
	fATW6(al_mac_str);
	fATW1(wifi_info->password);
	return fATWC_ex(NULL);
}


#if 0
int connect_wifi_config_ex(rtw_wifi_setting_t *wifi_info, unsigned char vp_flag_ssid)
{	
	int mode, ret;
	unsigned long tick1 = xTaskGetTickCount();
	unsigned long tick2, tick3;
	char empty_bssid[6] = {0}, assoc_by_bssid = 0;	

	rtw_network_info_t wifi = {0};
	memset(&wifi, 0, sizeof(rtw_network_info_t));
	
	//wifi.ssid
	memcpy(wifi.bssid.octet, wifi_info->ssid, 6);
	wifi.security_type = wifi_info->security_type;
	wifi.password = wifi_info->password;
	wifi.password_len = strlen(wifi_info->password);
	wifi.key_id = -1;
	
	
	
	printf("[ATWC]: _AT_WLAN_JOIN_NET_\n\r"); 
	if(memcmp (wifi.bssid.octet, empty_bssid, 6))
		assoc_by_bssid = 1;
	else if(wifi.ssid.val[0] == 0){
		printf("[ATWC]Error: SSID can't be empty\n\r");
		ret = RTW_BADARG;
		goto EXIT;
	}
	if(wifi.password != NULL){
		if((wifi.key_id >= 0)&&(wifi.key_id <= 3)) {
			wifi.security_type = RTW_SECURITY_WEP_PSK;
		}
		else{
			wifi.security_type = RTW_SECURITY_WPA2_AES_PSK;
		}
	}
	else{
		wifi.security_type = RTW_SECURITY_OPEN;
	}
	//Check if in AP mode
	wext_get_mode(WLAN0_NAME, &mode);
	if(mode == IW_MODE_MASTER) {
#if CONFIG_LWIP_LAYER
		dhcps_deinit();
#endif
#if defined(CONFIG_PLATFORM_8710C) && (defined(CONFIG_BT) && CONFIG_BT)
		if (wifi_set_mode(RTW_MODE_STA) < 0){
		    printf("\n\rERROR: Wifi on failed!");
		    ret = RTW_ERROR;
		    goto EXIT;
		}
#else	
		wifi_off();
		vTaskDelay(20);
		if (wifi_on(RTW_MODE_STA) < 0){
		    printf("\n\rERROR: Wifi on failed!");
		    ret = RTW_ERROR;
		    goto EXIT;
		}	
#endif
	}

#if CONFIG_INIC_EN //get security mode from scan list
	u8 connect_channel;
	u8 pscan_config;
	//the keyID may be not set for WEP which may be confued with WPA2 
	if((wifi.security_type == RTW_SECURITY_UNKNOWN)||(wifi.security_type == RTW_SECURITY_WPA2_AES_PSK))
	{
		int security_retry_count = 0;
		while (1) {
			if (_get_ap_security_mode((char*)wifi.ssid.val, &wifi.security_type, &connect_channel))
				break;
			security_retry_count++;
			if(security_retry_count >= 3){
				printf("Can't get AP security mode and channel.\n");
				ret = RTW_NOTFOUND;
				goto EXIT;
			}
		}
		if(wifi.security_type == RTW_SECURITY_WEP_PSK || wifi.security_type == RTW_SECURITY_WEP_SHARED)
			wifi.key_id = (wifi.key_id <0 || wifi.key_id >3)?0:wifi.key_id;
#if 0 //implemented in wifi_connect()
		//hex to ascii conversion
		if(wifi.security_type == RTW_SECURITY_WEP_PSK)
		{
			if(wifi.password_len == 10)
			{
				u32 p[5];
				u8 pwd[6], i = 0; 
				sscanf((const char*)wifi.password, "%02x%02x%02x%02x%02x", &p[0], &p[1], &p[2], &p[3], &p[4]);
				for(i=0; i< 5; i++)
					pwd[i] = (u8)p[i];
				pwd[5] = '\0';
				memset(wifi.password, 0, 65);
				strcpy((char*)wifi.password, (char*)pwd);
				wifi.password_len = 5;
			}else if(wifi.password_len == 26){
				u32 p[13];
				u8 pwd[14], i = 0;
				sscanf((const char*)wifi.password, "%02x%02x%02x%02x%02x%02x%02x"\
				"%02x%02x%02x%02x%02x%02x", &p[0], &p[1], &p[2], &p[3], &p[4],\
				&p[5], &p[6], &p[7], &p[8], &p[9], &p[10], &p[11], &p[12]);
				for(i=0; i< 13; i++)
					pwd[i] = (u8)p[i];
				pwd[13] = '\0';
				memset(wifi.password, 0, 65);
				strcpy((char*)wifi.password, (char*)pwd);
				wifi.password_len = 13;
			}
		}
#endif
	}
        pscan_config = PSCAN_ENABLE;
	if(connect_channel > 0 && connect_channel < 14)
		wifi_set_pscan_chan(&connect_channel, &pscan_config, 1);
#endif

	if(assoc_by_bssid){
		printf("\n\rJoining BSS by BSSID "MAC_FMT" ...\n\r", MAC_ARG(wifi.bssid.octet));
		ret = wifi_connect_bssid(wifi.bssid.octet, (char*)wifi.ssid.val, wifi.security_type, (char*)wifi.password, 
						ETH_ALEN, wifi.ssid.len, wifi.password_len, wifi.key_id, NULL);		
	} else {
		printf("\n\rJoining BSS by SSID %s...\n\r", (char*)wifi.ssid.val);
		ret = wifi_connect((char*)wifi.ssid.val, wifi.security_type, (char*)wifi.password, wifi.ssid.len,
						wifi.password_len, wifi.key_id, NULL);
	}
	
	if(ret!= RTW_SUCCESS){
		if(ret == RTW_INVALID_KEY)
			printf("\n\rERROR:Invalid Key ");
		
		printf("\n\rERROR: Can't connect to AP");
		goto EXIT;
	}
	tick2 = xTaskGetTickCount();
	printf("\r\nConnected after %dms.\n", (tick2-tick1));
#if CONFIG_LWIP_LAYER
		/* Start DHCPClient */
		LwIP_DHCP(0, DHCP_START);
	tick3 = xTaskGetTickCount();
	printf("\r\n\nGot IP after %dms.\n", (tick3-tick1));
#endif
	printf("\n\r");
EXIT:
	printf("exit\r\n");
}
#endif



void net_cloud_init()
{
	rlk_tcp_send_entry();
	rlk_tcp_recv_entry();
}

void net_lan_init()
{
	rlt_udp_recv_func_entry();
	rlt_tcp_server_entry();
} 

extern int softap_flag;

#if 1

static xTimerHandle s_bt_config_timer =  NULL;
void wapi_bt_config_cb(TimerHandle_t xTimer)
{   
    wapi_send_net_msg(HSN_BLE_CONFIG_STOP, NULL, 0, NULL);
}

extern unsigned int hsn_ble_config_time;


void wapi_bt_config_timer_oneshot_init()
{
	s_bt_config_timer = xTimerCreate("bt_config_timer", hsn_ble_config_time,
		pdFALSE, (void *)0, wapi_bt_config_cb);
	xTimerStart(s_bt_config_timer, 0);
}

void wapi_bt_config_timer_uninit()
{
	if (NULL != s_bt_config_timer)
	{
		xTimerStop(s_bt_config_timer, 0);
		xTimerDelete(s_bt_config_timer, 0);
	}
	s_bt_config_timer = NULL;
}








void rlk_net_task(void *para)
{
	t_WIFI_GLOBAL* pl_wg = MC_WIFI_GLOBAL_PTR();
	t_CONFIG_TABLE_BODY* pl_cfg = MC_WG_CONFIG_TABLE_PTR();
	int flag = 0;
	int ret;
	int cloud_init = 0;
	t_queue_msg que_msg;

	hsn_sta_change_cb vp_func;
	
	cJSON_Hooks_int();
	
				
	while(1)
	{
		//ret = xQueueReceiveFromISR(s_net_queue, &que_msg, 0);//lxd123
		ret = xQueueReceive(s_net_queue, &que_msg, 10000);	
		if(ret == pdPASS)
		{
			printf("get msg_flag: %d\n", que_msg.msg_flag);
			vp_func = (hsn_sta_change_cb)que_msg.vp_callback;
			switch(que_msg.msg_flag)
			{
#if 1	
				case SMART_CONFIG_MODE:
					pl_wg->v_sniffer_sta = HSN_SNIFFER_STATE_STARTED;
					pl_cfg->v_cur_mode = WIFI_MODE_SNIFFER;
					bapi_set_write_config_flag();
					sniffer_func_entry();	
					break;		
			
				case SOFTAP_CONFIG_MODE:
					printf("SOFTAP_CONFIG_MODE\n");
					pl_cfg->v_cur_mode = WIFI_MODE_AP;
					pl_wg->v_ap_sta = HSN_AP_STATE_STARTED;
					bapi_set_write_config_flag();
					softap_func_entry();
					//wapi_send_net_msg(CONNECT_CLOUD, NULL, 0, NULL);
					rlt_tcp_server_entry();
						
#if (HSN_START_SOFTAP==1)
					//rlt_tcp_server_entry();
					rlt_udp_recv_func_entry();
#endif
					break;
				case HSN_NET_CONFIG:
					printf("HSN_NET_CONFIG\n");

					softap_func_entry();
					vTaskDelay(2000);
					
					//hsn_set_sta_change_cb(hsn_bt_config_sta_change_cb);
					//hsn_ble_app_deinit();
					hsn_ble_app_init();
					wapi_bt_config_timer_oneshot_init();
					pl_wg->v_bt_sta = HSN_BT_STATE_STARTED;
					pl_wg->v_bt_start_source = HSN_BT_OPEN_SOURCE_NETCONFIG;
						
#if (HSN_START_SOFTAP==1)
					//rlt_tcp_server_entry();
					//rlt_udp_recv_func_entry();
#endif
					break;
				case NET_RECONNECT_ROUTER:
					printf("router disconnect, goto reconnect\n");
					if(tcp_socket_fd >= 0)
					{
						close(tcp_socket_fd);
						tcp_socket_fd = -1;
					}	
					
					pl_wg->v_cloud_login_sta = HSN_LOGIN_STATE_DISCONNET;
					pl_wg->v_router_sta = HSN_ROUTER_STATE_DISCONNET;
					if (pl_cfg->v_router_info_flag == BAPI_CONFIG_FLAG)
					{	
						pl_wg->v_router_sta = HSN_ROUTER_STATE_CONNECTING;
						ret = connect_wifi_config(&pl_cfg->v_wifi_setting, 0);	
						if (ret == 0)
						{
							printf("connected router1\n");
							pl_wg->v_router_reconnect_flag = 0;
							pl_wg->v_router_reconnect_cnt = 0;
							pl_wg->v_router_sta = HSN_ROUTER_STATE_CONNECTED;
							if (1 == cloud_init)
							{
								//wapi_send_tcpsend_msg(SET_TCP_SOCKET, NULL, 0, NULL);
								pl_wg->v_cloud_reconnect_flag = 1;
								printf(" #tttt 3\n");
							}
							else
							{
								wapi_send_net_msg(CONNECT_CLOUD, NULL, 0, NULL);
								printf(" #tttt 4\n");
							}
						}
						else
						{
							printf("reconnect router\n");
							pl_wg->v_router_reconnect_flag = 1;
						}
					}
					else
					{
						printf("Cannot find router info\n");
					}
					
					break;

				case CONNECT_ROUTER:
					printf("CONNECT_ROUTER\n");
					hsn_stop_softap_confg();
					vTaskDelay(3000);
					//wifi_enable_powersave();
					pl_wg->v_router_sta = HSN_ROUTER_STATE_CONNECTING;
					ret = connect_wifi_config_ex(&pl_wg->v_wg_wifi_setting, 0);
					
					//fATW0("XD_24G");
					//fATW6("64:6E:97:EB:EA:A6");
					//fATW1("12345678");
					//fATWC(NULL);
					//softap_flag = 1;
					if(ret == 0)
					{
						pl_wg->v_router_reconnect_flag = 0;
						pl_wg->v_router_reconnect_cnt = 0;
						pl_wg->v_router_sta = HSN_ROUTER_STATE_CONNECTED;
						pl_wg->v_connect_router_from = HSN_CONNECT_ROUTER_FROM_NETCONFIG;
						printf("connected router2, %d\n", pl_wg->v_connect_router_from);
						if((router_info_save2flash()) == 0)
						{
							wapi_send_net_msg(CONNECT_CLOUD, NULL, 0, NULL);
							
							if (1 == cloud_init)
							{
								wapi_send_tcpsend_msg(SET_TCP_SOCKET, NULL, 0, NULL);
								//pl_wg->v_cloud_reconnect_flag = 1;
								printf(" #tttt 9\n");
							}
							else
							{
								wapi_send_net_msg(CONNECT_CLOUD, NULL, 0, NULL);
								printf(" #tttt 5\n");
							}
						}
					}

					break;
				case CONNECT_ROUTER_BY_SSID:
					printf("CONNECT_ROUTER BY SSID\n");
					//wifi_enable_powersave();
					pl_wg->v_router_sta = HSN_ROUTER_STATE_CONNECTING;
					ret = connect_wifi_config(&pl_wg->v_wg_wifi_setting, 1);
					//softap_flag = 1;
					if(ret == 0)
					{
						
						pl_wg->v_router_reconnect_flag = 0;
						pl_wg->v_router_reconnect_cnt = 0;
						pl_wg->v_router_sta = HSN_ROUTER_STATE_CONNECTED;
						pl_wg->v_connect_router_from = HSN_CONNECT_ROUTER_FROM_NETCONFIG;
						printf("connected router2, %d\n", pl_wg->v_connect_router_from);

						if((router_info_save2flash()) == 0)
						{
							wapi_send_net_msg(CONNECT_CLOUD, NULL, 0, NULL);
							
							if (1 == cloud_init)
							{
								wapi_send_tcpsend_msg(SET_TCP_SOCKET, NULL, 0, NULL);
								//pl_wg->v_cloud_reconnect_flag = 1;
								printf(" #tttt 9\n");
							}
							else
							{
								wapi_send_net_msg(CONNECT_CLOUD, NULL, 0, NULL);
								printf(" #tttt 5\n");
							}
						}
					}

					break;

				case CONNECT_ROUTER_DEFALT:
					pl_wg->v_router_sta = HSN_ROUTER_STATE_DISCONNET;
					if (pl_cfg->v_router_info_flag == BAPI_CONFIG_FLAG)
					{
						//wifi_enable_powersave();
						pl_wg->v_router_sta = HSN_ROUTER_STATE_CONNECTING;
						ret = connect_wifi_config(&pl_cfg->v_wifi_setting, 0);
						if(ret == 0)
						{
							printf("connected router3\n");
							pl_wg->v_router_reconnect_flag = 0;
							pl_wg->v_router_reconnect_cnt = 0;
							pl_wg->v_router_sta = HSN_ROUTER_STATE_CONNECTED;
							pl_wg->v_connect_router_from = HSN_CONNECT_ROUTER_FROM_DEFAULT_SSID;
							wapi_send_net_msg(CONNECT_CLOUD, NULL, 0, NULL);
							printf(" #tttt 6\n");
						}
					}
					else
					{
						LOGW("Cannot find router info\n");
					}
					
					break;

				case CONNECT_CLOUD:
					printf("CONNECT_CLOUD:%d\n", cloud_init);
					if (0 == cloud_init)
					{
						printf("connect init\n");
						cloud_init = 1;
						//net_lan_init();
						//net_cloud_init();
						wapi_send_tcpsend_msg(SET_TCP_SOCKET, NULL, 0, NULL);
						//wapi_send_net_msg(STATUS_CHECK, NULL, 0, NULL);
					}
				break;

				case STATUS_CHECK:
					mcu_status_check();
					break;
				case HSN_CONFIG_MODE:
					printf("HSN_CONFIG_MODE\n");
					//cmd_check_ox1E_timer_handler(NULL);
					enter_on_config_mode_handle();
					if (NULL != vp_func)
						vp_func(HOST_ENTRY_MSG_CONFIG_WIFI, 0, NULL);
					break;
#endif

				case HSN_BLE_CONFIG_START:
					hsn_set_sta_change_cb((hsn_sta_change_cb)que_msg.vp_callback);
					pl_wg->v_bt_sta = HSN_BT_STATE_IDLE;
					hsn_ble_app_deinit();
					pl_wg->v_bt_sta = HSN_BT_STATE_STARTING;
					hsn_ble_app_init();
					pl_wg->v_bt_sta = HSN_BT_STATE_STARTED;
					pl_wg->v_bt_start_source = HSN_BT_OPEN_SOURCE_ONLY_BT;
					wapi_bt_config_timer_oneshot_init();
					break;
				case HSN_BLE_CONFIG_STOP:
					printf("stop bt config\n");
					vTaskDelay(3000);
					if (HSN_BT_STATE_STARTED == pl_wg->v_bt_sta)
					{
						pl_wg->v_bt_sta = HSN_BT_STATE_IDLE;
						wapi_bt_config_timer_uninit();
						hsn_set_sta_change_cb((hsn_sta_change_cb)que_msg.vp_callback);
						hsn_ble_app_deinit();						
					}
					
					break;


				default:
					break;
			}
			
			if (NULL != que_msg.data)
			{
				free(que_msg.data);
				que_msg.data = NULL;
			}
		
		}
		//printf("%s runn \n", __FUNCTION__);
		
		if (WIFI_MODE_STA == pl_cfg->v_cur_mode)
		{
			if (pl_wg->v_router_reconnect_flag == 1)
			{
				pl_wg->v_router_reconnect_flag = 0;
				//wapi_send_tcpsend_msg(ROUTER_RECONNECT, NULL, 0, NULL);
				wapi_send_net_msg(NET_RECONNECT_ROUTER, NULL, 0, NULL);
				pl_wg->v_router_reconnect_cnt++;
				printf("router reconnect cnt:%d\n", pl_wg->v_router_reconnect_cnt);
				if (pl_wg->v_router_reconnect_cnt > 10)// 重来太多次连不上，重启, about 5min
				{
					pl_wg->v_router_reconnect_cnt = 0;
					bapi_set_reboot_flag(23);
				}
			}
		}
		
		vTaskDelay(1);
		//LOGW("queue timeout\n");
	}
	
}
#else




#endif

int rlk_net_task_init()
{
	xTaskHandle app_task_handle = NULL;

	net_lan_init();
	net_cloud_init();

	rlt_msg_queue_create(&s_net_queue, 20);
	if(xTaskCreate((TaskFunction_t)rlk_net_task, (char const *)"rlk net task", 1024, NULL, tskIDLE_PRIORITY + HSN_TSK_PRIORITY, &app_task_handle) != pdPASS) {
		printf("xTaskCreate failed\n");	
	}
	return 0;
}
