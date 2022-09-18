/*
 * @Description: hisense_uart_cmd_handle.h
 * @Author: your name
 * @Date: 2019-08-05 08:48:44
 * @LastEditTime: 2019-09-05 10:50:11
 * @LastEditors: Please set LastEditors
 */

#ifndef _HISENSE_UART_CMD_HANDLE_H
#define _HISENSE_UART_CMD_HANDLE_H

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
void bluetooth_config_byte_statue_set(int value);


void hsn_config_mode();







/*
00：与路由器和网络链接正常；
01：不能与路由器链接；
10：能与路由器链接，但不能与云端通信；
11：上网不稳定或网络不稳定（此状态不算故障）。所有中间状态，包括AP模式、自检模式、快连模式等，具体情况由本消息内容的BYTE3确定。
*/
enum {
    ROUTER_NET_CONNECT = 0,
	CANNOT_CONNECT_ROUTER = 1,
	CAN_CONNECT_ROUTER_NO_NET = 2,
	WIFI_NET_STABLE = 3
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
	WAITTING_NORMAL_CONNECT = 1,
	WIFI_CONNECTING = 2,
	WIFI_UPDATE = 3,
	ROUTER_FAULT = 4,
	WIFI_UNSED = 5,
	WIFI_SELF_CHECK = 6,
	WIFI_SCAN = 7
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
	ROUTER_CONNECT_CLOUD_DISCONNECT = 1,
	CONFIG_ROUTER_CONNECT_CLOUD_DISCONNECT = 2,
	SCAN_ROUTER_CONNECT_CLOUD_DISCONNECT = 3,
	SCAN_NO_WIFI = 4,
	SCAN_WITHOUT_CONNECT = 5,
	ROUTER_CONNECT_CLOUD_CONNECT = 6,
	CONFIG_ROUTER_CONNECT_CLOUD_CONNECT = 7,
	SCAN_ROUTER_CONNECT_CLOUD_CONNECT = 8
};


enum {
    BLUETOOTH_STATE_DISCONNECT 	= 0,
	BLUETOOTH_STATE_CONNECTED 	= 1,
	BLUETOOTH_STATE_CONNECTING 	= 2,
	BLUETOOTH_STATE_TRANS_PAUSE = 3,
	BLUETOOTH_STATE_TRANS_STOP 	= 4,
};


void wifi_config_byte_status_set(int value) ;
void mcu_status_check();

#endif
