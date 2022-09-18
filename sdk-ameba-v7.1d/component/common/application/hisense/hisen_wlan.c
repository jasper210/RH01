#include "hisen_common.h"

#if 1
extern unsigned char *security_key ;
extern int jd_smnt_timeout;
rtw_security_t securitytype;
TaskHandle_t connect_ap;
TimerHandle_t conectap;
connect_router_callback connectap_cb;
static char  conect_ap_flag = 0 ;
static char  conect_ap_timer_flag = 0 ;
static int connect_ap_sta = 0;

typedef struct{
	char ssid[33];
    char  pwd[65];
	rtw_security_t v_security;
}target_ap_info_t;


static void connect_ap_process(void *param )
{
		int ret ;		
		target_ap_info_t *ap =(target_ap_info_t *)param ;
		
		
		if( ap->v_security == RTW_SECURITY_WEP_PSK )
		{
			int key_id = 0 ; 
			do{
				ret = wifi_connect(ap->ssid, ap->v_security, ap->pwd, strlen(ap->ssid), strlen(ap->pwd), key_id, NULL);
				key_id += 1; 
			}while((ret != RTW_SUCCESS)&&(key_id < 4));
		}
		else
		{
			ret = wifi_connect(ap->ssid, ap->v_security, ap->pwd, strlen(ap->ssid), strlen(ap->pwd), 0, NULL);
		}

		if(ret== RTW_SUCCESS)
		{
			if(LwIP_DHCP(0, DHCP_START) == DHCP_ADDRESS_ASSIGNED)
			{
				ret = RTW_SUCCESS;
				conect_ap_flag = 1 ;
				
				if(conectap !=NULL)
					xTimerDelete(conectap,0) ;
				   /*associate success, get ip success*/
				   connectap_cb(0, 0);
			}
			else
			{
				ret = RTW_ERROR;
				/*associate success, get ip failed*/
				connectap_cb(0, 1);
			}
		}  
		else
		   /*associate failed, get ip failed*/
		   connectap_cb(1, 1);
		
		connect_ap_sta = 0;
		free(ap);
		ap=NULL; 
		vTaskDelete(NULL); 

}



static void connect_ap_timer(TimerHandle_t xTimer)
{
	if(conect_ap_timer_flag == 0)
		 conect_ap_timer_flag = 1; 
	else
	{
		if(conect_ap_flag != 1)
		{
			/*associate failed, get ip failed*/
			connectap_cb(1, 1) ;
			if(connect_ap !=NULL)
				vTaskDelete(connect_ap) ;
			if(conectap !=NULL)
				xTimerDelete(conectap,0) ;
		}
	}	
}

int wapi_connect_router(
	char* pp_ssid					//路由名称
	, char* pp_pwd					//路由密码
	, rtw_security_t vp_security	// RTW_SECURITY_WPA2_AES_PSK
	, unsigned int vl_timeout_ms	//连接超时，一般会设置为1分钟，30秒连接路由，30秒获取IP
	, connect_router_callback pp_fn	//连接路由过程状态变化的回调，包括断开连接/连接成功等，视情况定义
	)
{		
		int ret  = 0;
		unsigned int timeout , starttime, current_time;
		target_ap_info_t *ap=NULL;
		if (0 == connect_ap_sta)
		{
			connect_ap_sta = 1;
			ap = (target_ap_info_t *)malloc(sizeof(target_ap_info_t));
			if(ap == NULL)
			{
				//printf(" target_ap_info malloc fail\n");
				return  RTW_ERROR;
			}
			memset(ap, 0x00, sizeof(target_ap_info_t)) ;
			
			memcpy(ap->ssid, pp_ssid, strlen(pp_ssid)) ;
			memcpy(ap->pwd,  pp_pwd, strlen(pp_pwd)) ;
			ap->v_security = vp_security;
			
			connectap_cb = pp_fn ;
			timeout = vl_timeout_ms ;
			starttime = xTaskGetTickCount() ;
			if(xTaskCreate(connect_ap_process, "conect_ap", 512, (void *)ap, tskIDLE_PRIORITY + 3, connect_ap) != pdPASS)
				printf("conect_ap task create error\n");

			conectap = xTimerCreate("conectap",vl_timeout_ms, pdTRUE ,(void *)0,connect_ap_timer) ;
			if(conectap == NULL)
			{  
				//printf("conect_ap timer create error\r\n");
			}
			else
			{
				xTimerStart(conectap, 0) ;
			}
		}
		
		
		return ret ;
}

	
int wapi_disconnect_router()
{
	return wifi_disconnect();
}





find_router_callback g_find_router_cb = NULL;
char g_find_ssid[SC_SSID_MAX_LEN + 1] = { 0 };

static void print_scan_result(rtw_scan_result_t* record)
{
#if 0
	RTW_API_INFO(("%s\t ", (record->bss_type == RTW_BSS_TYPE_ADHOC) ? "Adhoc" : "Infra"));
	RTW_API_INFO((MAC_FMT, MAC_ARG(record->BSSID.octet)));
	RTW_API_INFO((" %d\t ", record->signal_strength));
	RTW_API_INFO((" %d\t  ", record->channel));
	RTW_API_INFO((" %d\t  ", record->wps_type));
	RTW_API_INFO(("%s\t\t ", (record->security == RTW_SECURITY_OPEN) ? "Open" :
		(record->security == RTW_SECURITY_WEP_PSK) ? "WEP" :
		(record->security == RTW_SECURITY_WPA_TKIP_PSK) ? "WPA TKIP" :
		(record->security == RTW_SECURITY_WPA_AES_PSK) ? "WPA AES" :
		(record->security == RTW_SECURITY_WPA2_AES_PSK) ? "WPA2 AES" :
		(record->security == RTW_SECURITY_WPA2_TKIP_PSK) ? "WPA2 TKIP" :
		(record->security == RTW_SECURITY_WPA2_MIXED_PSK) ? "WPA2 Mixed" :
		(record->security == RTW_SECURITY_WPA_WPA2_MIXED) ? "WPA/WPA2 AES" :
		"Unknown"));

	RTW_API_INFO((" %s ", record->SSID.val));
	RTW_API_INFO(("\r\n"));
#endif
}

static bool sb_found_flag = false;

static rtw_result_t scan_router_result_handler(rtw_scan_handler_result_t* malloced_scan_result)
{
	
	if (malloced_scan_result->scan_complete != RTW_TRUE) 
	{
		rtw_scan_result_t* record = &malloced_scan_result->ap_details;
		record->SSID.val[record->SSID.len] = 0; /* Ensure the SSID is null terminated */

		//print_scan_result(record);
		if (0 == memcmp(record->SSID.val, g_find_ssid, strlen(g_find_ssid)))
		{
			g_find_router_cb(0, record->SSID.val, NULL);
			sb_found_flag = true;
		}
	}
	else
	{
		if (false == sb_found_flag)
		{
			g_find_router_cb(-1, NULL, NULL);
		}
		sb_found_flag = false;
	}

	return RTW_SUCCESS;
}


int wapi_find_router(char* pp_ssid, find_router_callback pp_fn)
{
	int ret = RTW_SUCCESS;
	wifi_set_promisc(RTW_PROMISC_DISABLE, NULL, 0);
	sb_found_flag = false;
	
	LOGT("Find:%s\n\r", pp_ssid);
	memset(g_find_ssid, 0, SC_SSID_MAX_LEN + 1);
	memcpy(g_find_ssid, pp_ssid, strlen(pp_ssid));
	g_find_router_cb = pp_fn;

	ret = wifi_scan_networks(scan_router_result_handler, NULL);
	if (RTW_SUCCESS != ret)
	{
		LOGE("scan ap list fail:%d\n", ret);
	}

	return ret;
}




A_UINT8* gp_aplist_out = NULL;
A_UINT32 gv_aplist_len = 0;
A_UINT32 gv_out_max_len = 0;
A_UINT8* gp_tmp_buf = NULL;
A_UINT8 gv_real_ap_cnt = 0;


bool g_scaning = false;
static rtw_result_t wapi_scan_router_result_handler(rtw_scan_handler_result_t* malloced_scan_result)
{
	bool vl_flg = false;
	if (malloced_scan_result->scan_complete != RTW_TRUE) {
		rtw_scan_result_t* record = &malloced_scan_result->ap_details;
		record->SSID.val[record->SSID.len] = 0; /* Ensure the SSID is null terminated */

		print_scan_result(record);

		if ((NULL != gp_aplist_out) && (0 != gv_out_max_len))
		{
			A_UINT8* pl_buf = gp_tmp_buf;
			gp_tmp_buf += 2 + record->SSID.len;
			if (gp_tmp_buf - gp_aplist_out < gv_out_max_len)
			{
				//SSID_LEN
				*(pl_buf + 0) = record->SSID.len;

				//AP_TYPE
				if (RTW_SECURITY_OPEN == record->security)
				{
					*(pl_buf + 1) = 0;
				}
				else
				{
					if ((RTW_SECURITY_WEP_PSK == record->security)
						|| (RTW_SECURITY_WEP_SHARED == record->security))
					{
						*(pl_buf + 1) = 1;
					}
					else
					{
						*(pl_buf + 1) = 2;
					}
				}

				//SSID
				memcpy(pl_buf + 2, record->SSID.val, record->SSID.len);

				gv_real_ap_cnt++;
				if (gv_real_ap_cnt > 20)
				{
					gv_out_max_len = 0;
				}
			}
			else
			{
				gv_out_max_len = 0;
			}
		}
	}
	else
	{
		g_scaning = false;
	}

	return RTW_SUCCESS;
}


int wapi_get_ap_list_20_ex(unsigned char* pp_out, unsigned int* pp_out_len, unsigned int vp_max_out)
{
	A_UINT8 vl_real_ap_num = 0;
	gp_aplist_out = pp_out;
	gv_aplist_len = *pp_out_len;
	gv_out_max_len = vp_max_out;
	gp_tmp_buf = gp_aplist_out;
	gv_real_ap_cnt = 0;
	g_scaning = true;
	static A_UINT8 s_cnt = 50;
	
	int ret = RTW_SUCCESS;
	ret = wifi_scan_networks(wapi_scan_router_result_handler, NULL);
	if (RTW_SUCCESS != ret)
	{
		LOGE("scan ap list fail:%d\n", ret);
	}

	while(g_scaning && (s_cnt > 0))
	{
		vTaskDelay(500);
		s_cnt--;
	}
	
	vl_real_ap_num = gv_real_ap_cnt;
	*pp_out_len = gp_tmp_buf - gp_aplist_out;

	gp_aplist_out = NULL;
	gv_aplist_len = 0;
	gv_out_max_len = 0;
	gp_tmp_buf = gp_aplist_out;
	gv_real_ap_cnt = 0;
	s_cnt = 50;

	return vl_real_ap_num;
	
}



int wapi_hex2bcd(A_UINT8* pp_dest, A_UINT8* pp_src, int vp_len)
{
	int i = 0;
	for (i = 0; i < vp_len; i++)
	{
		*(pp_dest + i) = ((*(pp_src + i)) / 10 * 16 + (*(pp_src + i)) % 10); 
	}

	return vp_len;
}

void HexToStr(unsigned char *pbDest, unsigned char *pbSrc, int nLen)
{
	char	ddl, ddh;
	int i;

	for (i = 0; i<nLen; i++)
	{
		ddh = 48 + pbSrc[i] / 16;
		ddl = 48 + pbSrc[i] % 16;
		if (ddh > 57) ddh = ddh + 7;
		if (ddl > 57) ddl = ddl + 7;
		pbDest[i * 2] = ddh;
		pbDest[i * 2 + 1] = ddl;
	}

	pbDest[nLen * 2] = '\0';
}

char* wapi_get_ap_ssid_name(A_UINT8* pp_data, A_UINT8 vp_len)
{
	static char s_str[16];
	if (vp_len > 8)
		return NULL;
	memset(s_str, 0, 16);
	A_UINT8 al_tmp[8] = { 0 };

	wapi_hex2bcd(al_tmp, pp_data, vp_len);
	HexToStr(s_str, al_tmp, vp_len);

	return s_str;
}




static A_UINT32 wapi_generate_ap_channel_num(void)
{
	A_UINT32 vl_chn = 0;
	char* pl_mac = wapi_get_mac_str();
	A_UINT8 al_mac[12];
	sscanf(pl_mac, "%x:%x:%x:%x:%x:%x", &al_mac[0], &al_mac[1], &al_mac[2], &al_mac[3], &al_mac[4], &al_mac[5]); 

	vl_chn = (A_UINT32)((al_mac[6 - 1] % 13) + 1);
	
	return vl_chn;
}

extern struct netif xnetif[NET_IF_NUM];

void wapi_start_ap(char* pp_ssid, char* pp_pwd)
{
    
	struct netif *pl_netif = &xnetif[0];
	printf("\n\n[WLAN_SCENARIO_EXAMPLE] Wi-Fi example mode switch case 1...\n");
	
	
	/*********************************************************************************
	*	1. Disable Wi-Fi			
	*********************************************************************************/
	printf("\n\r[WLAN_SCENARIO_EXAMPLE] Disable Wi-Fi\n");
	wifi_off();
	vTaskDelay(20);	
	
	
	/*********************************************************************************
	*	2. Enable Wi-Fi with AP mode			
	*********************************************************************************/
	printf("\n\r[WLAN_SCENARIO_EXAMPLE] Enable Wi-Fi with AP mode\n");	
	if(wifi_on(RTW_MODE_AP) < 0){
		printf("\n\r[WLAN_SCENARIO_EXAMPLE] ERROR: wifi_on failed\n");
		return;
	}
	
	
	/*********************************************************************************
	*	3. Start AP			
	*********************************************************************************/
	printf("\n\r[WLAN_SCENARIO_EXAMPLE] Start AP\n");
	rtw_security_t security_type = RTW_SECURITY_WPA2_AES_PSK;
	int channel = wapi_generate_ap_channel_num();
	if(wifi_start_ap(pp_ssid, security_type, pp_pwd, strlen(pp_ssid), strlen(pp_pwd), channel) < 0) {
		printf("\n\r[WLAN_SCENARIO_EXAMPLE] ERROR: wifi_start_ap failed\n");
		return;
	}
	
	
	/*********************************************************************************
	*	4. Check AP running		
	*********************************************************************************/	
	printf("\n\r[WLAN_SCENARIO_EXAMPLE] Check AP running\n");
	int timeout = 20;
	while(1) {
		char essid[33];
		if(wext_get_ssid(WLAN0_NAME, (unsigned char *) essid) > 0) {
			if(strcmp((const char *) essid, (const char *)pp_ssid) == 0) {
				printf("\n\r[WLAN_SCENARIO_EXAMPLE] %s started\n", pp_ssid);
				break;
			}
		}
		if(timeout == 0) {
			printf("\n\r[WLAN_SCENARIO_EXAMPLE] ERROR: Start AP timeout\n");	
			return;
		}
		vTaskDelay(1 * configTICK_RATE_HZ);
		timeout --;
	}
	
	
	/*********************************************************************************
	*	5. Start DHCP server
	*********************************************************************************/	
	printf("\n\r[WLAN_SCENARIO_EXAMPLE] Start DHCP server\n");
	dhcps_deinit();
	vTaskDelay(100);
	// For more setting about DHCP, please reference fATWA in atcmd_wifi.c.
	struct ip_addr ipaddr;
	struct ip_addr netmask;
	struct ip_addr gw;

    IP4_ADDR(&ipaddr, 192, 168, 1, 1);
	IP4_ADDR(&netmask, 255, 255 , 255, 0);
	IP4_ADDR(&gw, 192, 168, 1, 1);
	netif_set_addr(pl_netif, &ipaddr, &netmask,&gw);
	
	//netif_set_hostname(pl_netif, "SC_LB");
	
	dhcps_init(pl_netif);
}


A_UINT32 wapi_get_ip()
{
	A_UINT8* ip;
	A_UINT32 vl_ip = 0;
	struct netif *pl_netif = &xnetif[0];
	ip = (A_UINT8* )LwIP_GetIP(&xnetif[0]);
	
	//printf("LOCAL_IP  => %d.%d.%d.%d\n", ip[0], ip[1], ip[2], ip[3]);
    vl_ip = ((u32_t)((ip[0]) & 0xff) << 24) | \
                         ((u32_t)((ip[1]) & 0xff) << 16) | \
                         ((u32_t)((ip[2]) & 0xff) << 8)  | \
                          (u32_t)((ip[3]) & 0xff);
	return vl_ip;
}


#endif




static void hisen_wifi_disconn_hdl( char* buf, int buf_len, int flags, void* userdata)
{
	printf("disconnect ap...\n");
}

static void hisen_wifi_connected_hdl( char* buf, int buf_len, int flags, void* userdata)
{
	printf("connected ap...\n");
}

static void hisen_wifi_no_network_hdl( char* buf, int buf_len, int flags, void* userdata)
{
	printf("no network...\n");
}




int hisen_connect_ap_1(t_HISEN_ROUTER_INFO *pp_router_info, connect_router_callback pp_fn)
{
	int mode, ret = 0;
	unsigned long tick1 = xTaskGetTickCount();
	unsigned long tick2, tick3;
	char empty_bssid[6] = {0}, assoc_by_bssid = 0;	
	
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

	wifi_reg_event_handler(WIFI_EVENT_NO_NETWORK,hisen_wifi_no_network_hdl,NULL);
	wifi_reg_event_handler(WIFI_EVENT_CONNECT, hisen_wifi_connected_hdl, NULL);
	wifi_reg_event_handler(WIFI_EVENT_DISCONNECT, hisen_wifi_disconn_hdl, NULL);

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

	/* Start DHCPClient */
	LwIP_DHCP(0, DHCP_START);
	tick3 = xTaskGetTickCount();
	printf("\r\n\nGot IP after %dms.\n", (tick3-tick1));
	
	pp_fn(0, ret);
	return ret;
	
EXIT:
	pp_fn(-1, ret);
	return ret;
}







void hise_disconnect_from_ap(void)
{	
	int timeout = 20;
	char essid[33];
	volatile int ret = RTW_SUCCESS;
	
	printf("\n\rDeassociating AP ...");

	if(wext_get_ssid(WLAN0_NAME, (unsigned char *) essid) < 0) 
	{
		printf("\n\rnot connected yet");
		goto exit;
	}
	
	wifi_unreg_event_handler(WIFI_EVENT_DISCONNECT, hisen_wifi_disconn_hdl);

	if((ret = wifi_disconnect()) < 0) {
		printf("\n\rERROR: Operation failed!");

		goto exit;
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
exit:
    //init_wifi_struct( );

	return;
}


void hisen_init_wifi_struct(t_HISEN_ROUTER_INFO *pp_router_info)
{
	unsigned char al_bssid[6] = {0};
	memset(pp_router_info, 0, sizeof(t_HISEN_ROUTER_INFO));
	pp_router_info->bssid_len = 6;
	pp_router_info->key_id = -1;
	pp_router_info->security_type = -1;
}


///////////////////////////////////////////////////test

int hisen_test_connect_router_cb(int vl_result, int vl_reason)
{

}


void hisen_test_connect_ap()
{
	unsigned char al_bssid[6] = {0};
	t_HISEN_ROUTER_INFO vl_router_info;

	memset(&vl_router_info, 0, sizeof(vl_router_info));
	memcpy(vl_router_info.bssid, al_bssid, 6);
	vl_router_info.bssid_len = 6;
	memcpy(vl_router_info.ssid, "NEW", strlen("NEW"));
	vl_router_info.ssid_len = strlen("NEW");
	memcpy(vl_router_info.pwd, "12345678", strlen("12345678"));
	vl_router_info.pwd_len = strlen("12345678");
	vl_router_info.key_id = -1;
	vl_router_info.security_type = -1;
	
	hise_disconnect_from_ap();
	hisen_connect_ap_1(&vl_router_info, hisen_test_connect_router_cb);

}


