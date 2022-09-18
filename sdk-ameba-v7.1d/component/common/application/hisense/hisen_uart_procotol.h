#ifndef __HISEN_UART_PROCOTOL_H__
#define __HISEN_UART_PROCOTOL_H__


typedef int(*uart_pack_handle_callback)(A_UINT8 *pp_msg, A_UINT32 vp_msg_len);

//链路层
#define UartSOP_1  		(0)   //0xF4
#define UartSOP_2  		(1)   //0xF5
#define DATA_FLAG		(2)   //0x01
#define BYTE_40     	(3)   //0x40
#define UartLEN  		(4)   //packet length
//网络层
#define BYTE_01_1		(5)	  //0x01
#define UartRESV_1		(6)
#define BYTE_ADDR1_H    (7)   //0xEF
#define BYTE_ADDR1_L	(8)	  //0x01
#define BYTE_ADDR2_H	(9)  //0x02
#define BYTE_ADDR2_L	(10)  //0x01
//传输层
#define BYTE_01_4		(11)  //0x01
#define UartRESV_2		(12)  //0x00

//应用层
#define BYTE_A	    	(13)	  
#define BYTE_B	    	(14)
#define BYTE_01_5		(15)  //0x01
#define UartDATA 		(16) 

//链路层校验
#define UartCRC  		(17)

//链路层结束标记
#define SYNC_END_1  	(18)  //0xf4
#define SYNC_END_2  	(19)  //0xfb

#define FAC_CHECK_2  21
#define FAC_CHECK_3  22
#define FAC_CHECK_4  23
#define FAC_CHECK_5  24
#define FAC_CHECK_6  25
#define FAC_CHECK_7  26




#define RECV_MAX_LEN 255
#define RECV_BODY_MAX_LEN 200
#define DEV_SN_LEN 28
#define DEV_VER_LEN 9

#define SYNC_1 0xF4
#define SYNC_2 0xF5
#define SYNC_3 0xFB

//洗碗机-->>wifi模组
#define DATA_FLAG_VALUE		0x01
#define BYTE_40_VALUE		0x40
#define BYTE_01_1_VALUE		0x01
#define UartRESV_1_VALUE	0x00

#define DISHWASHER_ADDR1_H	0x07 	//目的地址
#define DISHWASHER_ADDR1_L	0x01
#define DISHWASHER_ADDR2_H	0xFE	//源地址
#define DISHWASHER_ADDR2_L	0x01

#define BYTE_01_4_VALUE		0x01
#define UartRESV_2_VALUE	0x00




#define PACKET_LEN_WITHOUT_MSGBODY 	20
#define PACKET_LEN_WITH_MSGBODY 	28
#define PACKET_LEN_INCLUDE_SYNC 	16
#define PACKET_LEN_INCLUDE_SYNC_EX 	18
#define PACKET_LEN_ExCLUDE_SYNC 	11


#define BYTE_A_POS 13
#define BYTE_B_POS 14
#define BYTE_MSG_POS 16

//7-1
#define CMD_M_GET_VERSION			7
#define CMD_S_GET_VERSION_0			1
//10-4
#define CMD_M_GET_DEV_ADDR			10
#define CMD_S_GET_DEV_ADDR_4		4

//30-0
#define CMD_M_COMMUNICATION			30
#define CMD_S_COMMUNICATION_0		0
//30-3
#define CMD_S_COMMUNICATION_3		3


//101-0
#define CMD_M_SET_STATE				101
#define CMD_S_SET_STATE_0			0

//102-0
#define CMD_M_GET_STATE				102
#define CMD_S_GET_STATE_0			0
//102-64
#define CMD_S_GET_STATE_64			64




#define CMD_DEVICE_CONTROL 0x02
#define CMD_GET_DEVICE_STATUS 0x03
#define CMD_UPGRADE_ONLINE 0x04
#define CMD_REQUEST_NET_STATUS 0x06
#define CMD_GET_SN 0x07
#define CMD_REQUEST_WIFI_REBOOT 0x08
#define CMD_GET_MCU_VERSION 0x09
#define CMD_NET_STATUS_DOWNLOAD 0x0A
#define CMD_DEVICE_STATUS_UPLOAD 0x0B
#define CMD_REQUEST_WIFI_CONFIG 0x0C
#define CMD_REQUEST_SN_WRITE 0x11


#define FT_SSID "SNOKEYWIFI"
#define FT_PASSWORD "0x123456"

#define FT_TIMEOUT_CONFIG 2*60*1000

void msg_body_build_func(unsigned char *msgbody);
void uart_cmd_0x06_handle();
void uart_cmd_0x07_handle(unsigned char *data, unsigned int data_len);
void uart_cmd_0x08_handle();
unsigned char wifi_get_signal_level();
void enter_on_config_mode_handle();
void enter_smart_link_config_mode_handle();
void enter_softap_config_mode_handle();
void enter_self_check_scan_mode_handle();
void enter_self_check_scan_mode_handle();
void enter_default_config_config_handle();
void mcu_status_check();
void set_wifi_connect_status_1(int status);
void set_wifi_connect_status_2(int status);
void set_wifi_connect_status_3(int status);

/*
00：与路由器和网络链接正常；
01：不能与路由器链接；
10：能与路由器链接，但不能与云端通信；
11：上网不稳定或网络不稳定（此状态不算故障）。所有中间状态，包括AP模式、自检模式、快连模式等，具体情况由本消息内容的BYTE3确定。
*/
enum {
    ROUTER_NET_CONNECT = 0,
	CANNOT_CONNECT_ROUTER,
	CAN_CONNECT_ROUTER_NO_NET,
	WIFI_NET_STABLE
};
/*
000：等待快连中；
001：等待普通连接中；
010：快连过程中/连接中/掉线重连中；
011：WiFi模块程序升级中；
100：路由器无法连接故障（模块配置成功后，因某种原因无法连接成功。但正常连接过程不在此次体现）；
101：模块处于失效状态（模块上电后，5min不配置，且没有配置文件时进入该状态）；
110：WiFi模块处于自检状态；
111：WiFi模块处于扫描周围路由器状态。
*/
enum {
    WAITTING_FAST_CONNECT = 0,
	WAITTING_NORMAL_CONNECT,
	WIFI_CONNECTING,
	WIFI_UPDATE,
	ROUTER_FAULT,
	WIFI_UNSED,
	WIFI_SELF_CHECK,
	WIFI_SCAN
};
/*
Bit4~Bit1:与路由器连接状况
0000：没有与路由器连接；
0001：与路由器实现了普通情况下的连接，但未连接云端；
0010：配置时按已有的ssid和密码连接路由器成功，但未连接云端；
0011：与扫描到的路由器连接成功，但未连接云端；
0100：没有扫描到周围有路由器；
0101：扫描到周围有路由器，但连接不成功；
0110：与路由器实现了普通情况下的连接，并连接了Wi-Fi指定的云端； NB-IoT时，家电与云端直接连接了；
0111：配置时按已有的ssid和密码连
*/
enum {
    ROUTER_DISCONNECT = 0,
	ROUTER_CONNECT_CLOUD_DISCONNECT,
	CONFIG_ROUTER_CONNECT_CLOUD_DISCONNECT,
	SCAN_ROUTER_CONNECT_CLOUD_DISCONNECT,
	SCAN_NO_WIFI,
	SCAN_WITHOUT_CONNECT,
	ROUTER_CONNECT_CLOUD_CONNECT,
	CONFIG_ROUTER_CONNECT_CLOUD_CONNECT,
	SCAN_ROUTER_CONNECT_CLOUD_CONNECT
};

void wifi_config_byte_status_set(int value) ;
void mcu_status_check();

unsigned int sc_uart_pack(unsigned char a, unsigned char b, unsigned char *msg_body, unsigned int msg_body_len, unsigned char *packet);
void sc_uart_unpack(A_UINT8* pp_in_buf, A_UINT32 vp_len, uart_pack_handle_callback pp_callback);
void hisen_uart_msg_handle(A_UINT8 *pp_msg, A_UINT32 vp_msg_len);



#endif//__HISEN_UART_PROCOTOL_H__
