
#ifndef _HSN_BT_CONFIG_H_
#define _HSN_BT_CONFIG_H_



//int hsn_bt_config_app_init(void);
//void hsn_bt_config_app_deinit(void);



//TAG define
//0001
#define HSN_TAG_BT_CMD_SCAN				0x0001
#define HSN_TAG_BT_CMD_REPLY_SCAN		(HSN_TAG_BT_CMD_SCAN | 0x8000)
//0002
#define HSN_TAG_BT_CMD_CONNECT			0x0002
#define HSN_TAG_BT_CMD_REPLY_CONNECT	(HSN_TAG_BT_CMD_CONNECT | 0x8000)
//0003
#define HSN_TAG_BT_CMD_STATUE			0x0003
#define HSN_TAG_BT_CMD_REPLY_STATUE		(HSN_TAG_BT_CMD_STATUE | 0x8000)
//0004
#define HSN_TAG_BT_CMD_GET_WLAN_BAND	0x0004
#define HSN_TAG_BT_CMD_REPLY_WLAN_BAND	(HSN_TAG_BT_CMD_GET_WLAN_BAND | 0x8000)
//0005
#define HSN_TAG_BT_CMD_GET_WIFI_ID		0x0005
#define HSN_TAG_BT_CMD_REPLY_WIFI_ID	(HSN_TAG_BT_CMD_GET_WIFI_ID | 0x8000)
//0006
#define HSN_TAG_BT_CMD_GET_DEV_ID		0x0006
#define HSN_TAG_BT_CMD_REPLY_DEV_ID		(HSN_TAG_BT_CMD_GET_DEV_ID | 0x8000)

//0007
#define HSN_TAG_BT_CMD_SSID_CONNECT			0x0007
#define HSN_TAG_BT_CMD_REPLY_SSID_CONNECT	(HSN_TAG_BT_CMD_SSID_CONNECT | 0x8000)

//0008
#define HSN_TAG_BT_CMD_START_SCAN			0x0008
#define HSN_TAG_BT_CMD_REPLY_ START_SCAN	(HSN_TAG_BT_CMD_START_SCAN | 0x8000)



//error
#define HSN_TAG_BT_CMD_REPLY_FAIL		0xFFFF


//VALUE define


// 4 REPLY_GET_STATUE
typedef enum{
	HSN_WIFI_STATE_DISABLED			= 0X00, 
	HSN_WIFI_STATE_IDLE				= 0X01, 
	HSN_WIFI_STATE_SCANNING			= 0X02, 
	HSN_WIFI_STATE_STARTED			= 0X03, 
	HSN_WIFI_STATE_CONNECTED		= 0X04, 
	HSN_WIFI_STATE_WAITFORKEY		= 0X05, 
	HSN_WIFI_STATE_WRONG_PASSWORD	= 0XFF, 
} hsn_bt_config_wifi_staus;

typedef enum {
	HSN_CLOUD_STATE_DISABLED		= 0X00, 
	HSN_CLOUD_STATE_IDLE			= 0X01, 
	HSN_CLOUD_STATE_STARTED			= 0X03, 
	HSN_CLOUD_STATE_CONNECTED		= 0X04, 
	HSN_CLOUD_STATE_WAITFORKEY		= 0X05, 
	HSN_CLOUD_STATE_WRONG_PASSWORD	= 0XFF, 	
} hsn_bt_config_cloud_staus;

//5 REPLY_WIFI_BAND
#define HSN_BT_CONFIG_WIFI_BAND_24G		0
#define HSN_BT_CONFIG_WIFI_BAND_5G		1



//8
#define HSN_BT_CONFIG_AP_INFO_MAX_SIZE 	20
#define HSN_BTCONFIG_MAX_APNUM_FOR_ONETIME	5
typedef struct{
	unsigned char bssid_octer[6];
	unsigned char rssi;
	unsigned char secuity;
	unsigned char ssid_len;
	unsigned char ssid[33];
	
} t_HSN_BT_CONFIG_AP_INFO;

typedef enum{
	HSN_BTCONFIG_SCAN_STATE_IDLE			= 0X00, 
	HSN_BTCONFIG_SCAN_STATE_SCANNING		= 0X01, 

} eHSN_BTCONFIG_SCAN_STATE;






void hsn_ble_config_tlv_write_parse(unsigned char *pp_data, unsigned int pv_data_len);
void hsn_ble_config_tlv_read_reply(unsigned char *pp_out_data, unsigned int *pv_data_len, unsigned short read_offset);
unsigned short hsn_ble_config_tlv_packet(unsigned short vp_tag, unsigned char* pp_value, unsigned short vp_value_len, unsigned char* pp_out_packet);
void hsn_test_bt_cmd_parse();



#endif//_HSN_BT_CONFIG_H_
