/*
 * @Description: hisense_uart_protocol.h
 * @Author: xuetong
 * @Date: 2019-08-05 08:48:44
 * @LastEditTime: 2019-08-28 10:41:04
 * @LastEditors: Please set LastEditors
 */


#ifndef _HISENSE_UART_PROTOCOL_H
#define _HISENSE_UART_PROTOCOL_H

//#define UART_TX    PA_7
//#define UART_RX    PA_6

//#define UART_TX    PA_23
//#define UART_RX    PA_18

#define UART_TX			PA_14
#define UART_RX			PA_13
#define UART_RTS			NC
#define UART_CTS			NC



#define RECV_MAX_LEN 128
#define DEV_SN_LEN 28
#define DEV_VER_LEN 9

#define SYNC_1 0xF4
#define SYNC_2 0xF5
#define SYNC_3 0xFB

#define PACKET_LEN_WITHOUT_MSGBODY 20
#define PACKET_LEN_WITH_MSGBODY 28
#define PACKET_LEN_INCLUDE_SYNC 16
#define PACKET_LEN_INCLUDE_SYNC_EX 18
#define PACKET_LEN_ExCLUDE_SYNC 11
#define BYTE_A_POS 13
#define BYTE_B_POS 14
#define BYTE_MSG_POS 16
#define BYTE_DEV_ADDR_H_POS 9
#define BYTE_DEV_ADDR_L_POS 10


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


#define CMD_A_GET_DEV_ADDR		 			10
#define CMD_B_GET_DEV_ADDR		 			4

#define CMD_A_GET_WORKING_STATUS		 	30
#define CMD_B_GET_WORKING_STATUS		 	0






#define HSN_WIFI_ADDR_H			0xFE	//wifi module address
#define HSN_WIFI_ADDR_L			0x01


#define HSN_ICEBOX_ADDR_H		0x02	// icebox address
#define HSN_ICEBOX_ADDR_L		0x01


#define HSN_DISHWASHER_ADDR_H	0x07 	//dishwasher address
#define HSN_DISHWASHER_ADDR_L	0x01



#endif
