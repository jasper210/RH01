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
#define BAPI_CONFIG_FLAG        0xEF

#define MC_DEV_SN_LENGTH        32//28
#define WAPI_SSID_MAX_LEN       64
#define WAPI_PASSWORD_MAX_LEN   64

#define JOYLINK_TARGET_SSID_FLAG        0xEF
#define LIAN_TEST_FLAG					0xFE

#define CHIGO_TEST_TIMEOUT				0xFE
#define CHIGO_TEST_KEY_PRESS			0xFD
#define CHIGO_TEST_MANAGER_FLOW			0xFB



typedef struct tagCONFIG_TABLE_BODY{
	A_UINT8 v_cur_mode;	//e_WIFI_MODE
	A_UINT8 v_last_mode;
	A_UINT8 v_target_ssid_flag;	//0xEF表示目标路由已经配置
	A_UINT8 v_ap_type;
	//char a_target_ssid[WAPI_SSID_MAX_LEN + JOYLINK_PADDING_DWORD];
	//char a_target_pwd[WAPI_PASSWORD_MAX_LEN + JOYLINK_PADDING_DWORD];
	//char a_dev_sn[MC_DEV_SN_LENGTH + JOYLINK_PADDING_DWORD]; //家电SN
	//A_UINT8 a_reg_code[SC_LIBING_REGISTRARTTION_CODE_LEN + 1];
	A_UINT8 v_connect_ap_ctrl_pos;
	A_UINT8 v_flag_chigo_test;//TEST_FLAG
	A_UINT8 a_reserve[2];

	//t_JOYLINK_DEV_INFO v_joy_dev;
#ifdef MSMART
	//msmart
	//A_UINT8 a_apln_id[SC_MSMART_APLN_ID_LEN + 2];
	A_UINT32 v_server_ip;
	A_UINT32 v_server_port;
#endif//MSMART

} t_CONFIG_TABLE_BODY;

//----------------------------------
typedef enum E_GET_SN_STATUS
{
	GET_SN_STATUS_DISCONNECT = 0L,
	GET_SN_STATUS_CONNECTED,
	GET_SN_STATUS_CONNECTING,

	//
	GET_SN_STATUS_MAX
} e_GET_SN_STATUS;

typedef enum E_WIFI_MODE
{
	WIFI_MODE_IDLE = 0L,
	WIFI_MODE_STA = 1,
	WIFI_MODE_UNDEFINE = 2,//废弃该模式
	WIFI_MODE_AP = 3,
	WIFI_MODE_SNIFFER = 4,
	WIFI_MODE_COEXIST = 5,
	WIFI_MODE_TEST = 6,


	//----------	 
	WIFI_MODE_MAX
} e_WIFI_MODE;

typedef enum E_SNIFFER_STATUS
{
	SNIFFER_STATUS_DISCONNECT = 0L,
	SNIFFER_STATUS_CONNECTED,
	SNIFFER_STATUS_CONNECTING,

	//
	SNIFFER_STATUS_MAX
} e_SNIFFER_STATUS;

typedef enum E_CONNECT_AP_STATUS
{
	CONNECT_AP_STATUS_DISCONNECT = 0L,
	CONNECT_AP_STATUS_CONNECTED,
	CONNECT_AP_STATUS_CONNECTING,

	//
	CONNECT_AP_STATUS_MAX
} e_CONNECT_AP_STATUS;

typedef enum E_START_AP_STATUS
{
	START_AP_STATUS_DISCONNECT = 0L,
	START_AP_STATUS_CONNECTED,
	START_AP_STATUS_CONNECTING,

	//
	START_AP_STATUS_MAX
} e_START_AP_STATUS;

typedef enum E_DNS_GET_IP_STATUS
{
	DNS_GET_IP_STATUS_DISCONNECT = 0L,
	DNS_GET_IP_STATUS_CONNECTED,
	DNS_GET_IP_STATUS_CONNECTING,

	//
	DNS_GET_IP_STATUS_MAX
} e_DNS_GET_IP_STATUS;

typedef enum E_JD_LAN_STATUS
{
	JD_LAN_STATUS_DISCONNECT = 0L,
	JD_LAN_STATUS_CONNECTED,
	JD_LAN_STATUS_CONNECTING,

	//
	JD_LAN_STATUS_MAX
} e_JD_LAN_STATUS;

typedef enum E_JD_WLAN_STATUS
{
	JD_WLAN_STATUS_DISCONNECT = 0L,
	JD_WLAN_STATUS_CONNECTED,
	JD_WLAN_STATUS_CONNECTING,

	//
	JD_WLAN_STATUS_MAX
} e_JD_WAN_STATUS;

typedef enum E_MD_WLAN_STATUS
{
	MD_WLAN_STATUS_DISCONNECT = 0L,
	MD_WLAN_STATUS_CONNECTED,
	MD_WLAN_STATUS_CONNECTING,

	//
	MD_WLAN_STATUS_MAX
} e_MD_WAN_STATUS;





typedef struct tagWIFI_GLOBAL {
	A_UINT8 wifi_id_base64[50];
	char devid_str[33];
	char mac_str[13];

	//char a_dev_sn[MC_DEV_SN_LENGTH + JOYLINK_PADDING_DWORD]; //家电SN
	//A_UINT8 a_reg_code[SC_LIBING_REGISTRARTTION_CODE_LEN + 1];
	//char a_ssid[WAPI_SSID_MAX_LEN + JOYLINK_PADDING_DWORD];
	//char a_pwd[WAPI_PASSWORD_MAX_LEN + JOYLINK_PADDING_DWORD];
	A_UINT32 v_jdserv_ip;

	e_WIFI_MODE v_mode;

	e_JD_LAN_STATUS v_sta_jdlan;
	e_JD_WAN_STATUS v_sta_jdwan;
	e_MD_WAN_STATUS v_sta_mdwan;

	e_DNS_GET_IP_STATUS v_sta_md_getip;

	e_SNIFFER_STATUS v_sta_sniffer;
	e_CONNECT_AP_STATUS v_sta_connet_ap;
	e_START_AP_STATUS v_sta_start_ap;
	e_DNS_GET_IP_STATUS v_sta_dns_getip;
	bool v_jdauth;

	A_UINT32 v_ap_tick;
	bool v_chigo_test;

	//t_JD_PARAM v_jdparam;
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

extern void bapi_set_reboot_flag();
extern void bapi_clear_reboot_flag();
extern bool bapi_get_reboot_flag();


#endif//__HISEN_PARAM_CONFIG_H__
