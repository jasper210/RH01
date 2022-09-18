/*
 * @Description: rlt_net_data_process.h
 * @Author:xuetong
 * @Date: 2019-08-05 08:48:44
 * @LastEditTime: 2019-09-09 10:05:59
 * @LastEditors: Please set LastEditors
 */
#ifndef RLT_NET_DATA_PROCESS__H
#define RLT_NET_DATA_PROCESS__H

enum{
	WIFI_CONNECT = 0,
	WIFI_DISCONN,
	WIFI_NO_NETWORK,
	CLOUD_CONNECT,
	CLOUD_DISCONNECT,
};

typedef enum {
    HSN_LOGIN_STATE_DISCONNET = 0x00,
	HSN_LOGIN_STATE_HB,
	HSN_LOGIN_STATE_START_REGISTER,
	HSN_LOGIN_STATE_REGISTER,
	HSN_LOGIN_STATE_DYNAMIC_KEY,
	HSN_LOGIN_STATE_SYSTEM_PARAM,

	//----------------
	HSN_LOGIN_STATE_MAX
} e_HSN_LOGIN_STATE;

typedef enum {
    HSN_ROUTER_STATE_DISCONNET = 0x00,
	HSN_ROUTER_STATE_CONNECTED,
	HSN_ROUTER_STATE_CONNECTING,

	//----------------
	HSN_ROUTER_STATE_MAX
} e_HSN_ROUTER_STATE;


typedef enum {
    HSN_SNIFFER_STATE_IDLE = 0x00,
	HSN_SNIFFER_STATE_STARTED,
	HSN_SNIFFER_STATE_START,

	//----------------
	HSN_SNIFFER_STATE_MAX
} e_HSN_SNIFFER_STATE;

typedef enum {
    HSN_AP_STATE_IDLE = 0x00,
	HSN_AP_STATE_STARTED,
	HSN_AP_STATE_START,

	//----------------
	HSN_AP_STATE_MAX
} e_HSN_AP_STATE;

typedef enum {
    HSN_BT_STATE_IDLE = 0x00,
	HSN_BT_STATE_STARTED,
	HSN_BT_STATE_STARTING,

	//----------------
	HSN_BT_STATE_MAX
} e_HSN_BT_STATE;

typedef enum {
    HSN_BT_OPEN_SOURCE_NETCONFIG = 0x00,
	HSN_BT_OPEN_SOURCE_ONLY_BT,

	//----------------
	HSN_BT_OPEN_SOURCE_MAX
} e_HSN_BT_OPEN_SOURCE;

typedef enum {
    HSN_CONNECT_ROUTER_FROM_DEFAULT_SSID = 0x00,
	HSN_CONNECT_ROUTER_FROM_NETCONFIG,

	//----------------
	HSN_CONNECT_ROUTER_FROM_MAX
} e_HSN_CONNECT_ROUTER_FROM;










typedef struct net_packet_seq{
	int msg_type;
	int msg_seq;
}t_net_packet_param;


#define NET_PACKET_HEAD 27  //no msg body
#define PACKET_MD5_LEN 16

void hsn_entry_bt_config();


void cJSON_Hooks_int();
int json_net_packet_build();
//int json_net_packet_parse();
int bc_wifi_msg_packet_build(unsigned char *packet);
int discover_send_offline_notify(unsigned char *packet);
void udp_net_data_parse(struct sockaddr_in from_addr, unsigned char *rxbuf);
int device_register_request(unsigned int socket);
int device_aes_key_request(unsigned char *token, unsigned int socket);
int hb_request();
void lan_net_data_parse(unsigned char *data, unsigned int data_len, unsigned int socket_fd);
void cloud_data_parse(unsigned char *data, int data_len, unsigned int socket_fd);
void test_mbedtls_base64_decode(unsigned char *encode_str);
void data_uart2net_handle(unsigned char *data, unsigned int data_len);
void updata_aes_key(unsigned char *key);
int router_info_get(unsigned char *data, int flag);
int hsn_get_router_info(unsigned char *pp_data, unsigned char vp_data_len);
int hsn_get_router_info_ex(unsigned char *pp_data, unsigned char vp_data_len);

void set_hb_flag(int flag);
rtw_result_t app_scan_result_handler( rtw_scan_handler_result_t* malloced_scan_result);

int hsn_tcp_client_send(char *pl_data, int vp_data_len);

int set_heartbeat_init(unsigned int vp_hb_time);
int set_heartbeat_uninit();

int set_dataresp_timer_init(unsigned int vp_rp_time);
int set_dataresp_timer_uninit();

#endif
