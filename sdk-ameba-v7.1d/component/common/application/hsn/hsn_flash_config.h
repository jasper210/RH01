#ifndef __HISEN_PARAM_CONFIG_H__
#define __HISEN_PARAM_CONFIG_H__



//----------------------------------
typedef enum {
	CONFIG_TABLE_RW_ERROR = -1,
	CONFIG_TABLE_OK = 0,             /* success */
	CONFIG_TABLE_CHECKSUM_FAIL

} e_CONFIG_TABLE_STATUS;

#define BAPI_CONFIG_TABLE_VERSION_0001         0x0001
#define BAPI_TABLE_MAX_LEN              512
#define BAPI_CONFIG_TABLE_HEADER1       0x55
#define BAPI_CONFIG_TABLE_HEADER2       0xAA
#define BAPI_FLAG_SAVED                 0xBB
#define BAPI_FLAG_NOT_SAVED             0xAA

typedef struct tagCONFIG_TABLE_HEADER {
	A_UINT8 v_header1;//0x55
	A_UINT8 v_header2;//0xAA
	A_UINT8 v_saved_flag;//暂时保留BAPI_FLAG_SAVED
	A_UINT8 v_checksum;//校验, 从v_save_fla开始计算

	A_UINT16 v_version;//0x0001，从version开始校验
	A_UINT16 v_len;//0配置总长度，包括头、flag, 校验、长度和配置  暂时保留  

	A_UINT8 a_reverse[8];//0


} t_CONFIG_TABLE_HEADER;




//----------------------------------

typedef enum E_GET_DEV_ADDR_STATUE
{
	GET_DEV_ADDR_STATUE_IDLE = 0L,
	GET_DEV_ADDR_STATUE_FINISH,
	GET_DEV_ADDR_STATUE_START,
		

	//
	GET_DEV_ADDR_STATUE_MAX
} e_GET_DEV_ADDR_STATUE;

typedef enum E_BT_CONFIG_STATUE
{
	BT_CONFIG_STATUE_IDLE = 0L,
	BT_CONFIG_STATUE_FINISH,
	BT_CONFIG_STATUE_START,	
		
	//
	BT_CONFIG_STATUE_MAX
} e_BT_CONFIG_STATUE;


typedef enum E_DEV_UNBIND_STATUE
{
	DEV_UNBIND_STATUE_IDLE = 0L,
	DEV_UNBIND_STATUE_FINISH,
	DEV_UNBIND_STATUE_START,
		
	//
	DEV_UNBIND_STATUE_MAX
} e_DEV_UNBIND_STATUE;

typedef enum E_WIFI_CONFIG_STATUE
{
	WIFI_CONFIG_STATUE_IDLE = 0L,
	WIFI_CONFIG_STATUE_FINISH,
	WIFI_CONFIG_STATUE_START,
		
	//
	WIFI_CONFIG_STATUE_MAX
} e_WIFI_CONFIG_STATUE;


typedef enum E_SMART_CONFIG_STATUE
{
	SMART_CONFIG_STATUE_IDLE = 0L,
	SMART_CONFIG_STATUE_FINISH,
	SMART_CONFIG_STATUE_START,
		
	//
	SMART_CONFIG_STATUE_MAX
} e_SMART_CONFIG_STATUE;



typedef enum E_WIFI_MODE
{
	WIFI_MODE_IDLE = 0x00,
	WIFI_MODE_STA = 1,
	WIFI_MODE_AP = 2,
	WIFI_MODE_SNIFFER = 3,
	WIFI_MODE_NETCONFIG = 4,

	//----------	 
	WIFI_MODE_MAX
} e_WIFI_MODE;

typedef enum E_BT_MODE
{
	BT_MODE_IDLE = 0x00,
	BT_MODE_ON = 1,

	//----------	 
	BT_MODE_MAX
} e_BT_MODE;


typedef enum E_ENVIRONMENT
{
	ENVIRONMENT_RELEASE = 0L,
	ENVIRONMENT_TESTING,
	ENVIRONMENT_DEVELOP,

	//
	ENVIRONMENT_MAX
} e_ENVIRONMENT;





//----------------------------------


#define MC_DEV_SN_LENGTH        32//28
#define WAPI_SSID_MAX_LEN       64
#define WAPI_PASSWORD_MAX_LEN   64

#define JOYLINK_TARGET_SSID_FLAG        0xEF
#define LIAN_TEST_FLAG					0xFE

#define CHIGO_TEST_TIMEOUT				0xFE
#define CHIGO_TEST_KEY_PRESS			0xFD
#define CHIGO_TEST_MANAGER_FLOW			0xFB


#if 0
typedef struct rtw_wifi_setting {
	rtw_mode_t		mode;
	unsigned char 		ssid[33];
	unsigned char		channel;
	rtw_security_t		security_type;
	unsigned char 		password[65];
	unsigned char		key_idx;
}rtw_wifi_setting_t;
#endif

#define BAPI_CONFIG_FLAG        0x55

typedef struct tagCONFIG_TABLE_BODY{
	e_ENVIRONMENT v_environment;
	
	e_WIFI_MODE v_cur_mode;	//e_WIFI_MODE
	e_WIFI_MODE v_last_mode;
	e_BT_MODE v_bt_mode;	//e_BT_MODE
	A_UINT8 v_router_info_flag;	//0x55表示目标路由已经配置 HSN_ROUTER_INFO_FLAG_0X55
	
	rtw_wifi_setting_t v_wifi_setting;

	A_UINT8 v_promise_reboot;
	A_UINT8 a_reserve[3];

} t_CONFIG_TABLE_BODY;



#define HSN_PADDING_DWORD      4
#define HSN_ALIGN_WORD         2




typedef struct tagWIFI_GLOBAL {
	char v_featurecode[24+4];
	char v_featurecode_aeskey[16+4];
	char v_cinfo_version[20+4];
	
	A_UINT8 wifi_id_base64[50+2];
	char wifi_id[33+3+4];
	char mac_str[13+3];
	char bt_addr[13+3];

	A_UINT8 v_dev_addr_H;
	A_UINT8 v_dev_addr_L;
	A_UINT8 v_device_type;
	A_UINT8 v_reserve;

	A_UINT8 v_router_reconnect_flag;
	A_UINT8 v_router_reconnect_cnt;
	A_UINT8 v_cloud_reconnect_flag;
	A_UINT8 v_cloud_reconnect_cnt;

	int v_param_hb_time;
	int v_param_rp_time;
	int v_param_retry_time;
	unsigned int v_time;
	unsigned int v_timezone;

	e_GET_DEV_ADDR_STATUE v_get_dev_addr_sta;
	e_BT_CONFIG_STATUE v_bt_config_sta;
	e_DEV_UNBIND_STATUE v_dev_unbind_sta;
	e_WIFI_CONFIG_STATUE v_wifi_config_sta;
	e_SMART_CONFIG_STATUE v_smart_config_sta;

	e_HSN_SNIFFER_STATE v_sniffer_sta;
	e_HSN_AP_STATE v_ap_sta;
	e_HSN_ROUTER_STATE v_router_sta;
	e_HSN_LOGIN_STATE v_cloud_login_sta;
	e_HSN_BT_STATE v_bt_sta;

	e_HSN_BT_OPEN_SOURCE v_bt_start_source;
	e_HSN_CONNECT_ROUTER_FROM v_connect_router_from;

	int v_wifi_config_on;

	
	unsigned char a_router_ssid[32 + 4];
	rtw_wifi_setting_t v_wg_wifi_setting;

	

	t_CONFIG_TABLE_BODY v_config;
	
} t_WIFI_GLOBAL;

//----------------------------------
#define MC_WIFI_GLOBAL_PTR()            (&g_wifi_global)
#define MC_WG_CONFIG_TABLE_PTR()        (&g_wifi_global.v_config)
#define MC_WG_SN_FLAG(flag)					(g_wifi_global.v_sn_flag = (flag))

#define MC_WG_JD_PARAM_PTR()            (&g_wifi_global.v_jdparam)
#define MC_WG_JOYLINK_DEV_INFO_PTR()	(&g_wifi_global.v_jdparam.v_dev_info)


//----------------------------------
extern GOLBAL t_WIFI_GLOBAL g_wifi_global;


extern void wapi_init_wifi_global();
extern void bapi_config_init(t_CONFIG_TABLE_BODY* pp_cfg_bdy);
extern void bapi_config_table_reset(t_CONFIG_TABLE_BODY* pp_cfg_bdy);
extern int bapi_config_read(t_CONFIG_TABLE_BODY* pp_cfg_bdy);
extern int bapi_config_write(t_CONFIG_TABLE_BODY* pp_cfg_bdy);
extern void bapi_config_dump(t_CONFIG_TABLE_BODY* pp_cfg_bdy, char* pp_str);

extern void bapi_set_write_config_flag();
extern void bapi_clear_write_config_flag();

extern void bapi_set_reboot_flag(unsigned char vp_reboot_reason);
extern void bapi_clear_reboot_flag();
extern int bapi_get_reboot_flag();
extern void wapi_sys_reboot();

extern void hsn_reset_config_table(unsigned char vp_flag);





#endif//__HISEN_PARAM_CONFIG_H__
