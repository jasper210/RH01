/*
 * @Description: rlt_softap_config.h
 * @Author: xuetong
 * @Date: 2019-09-20 15:09:47
 * @LastEditTime: 2019-10-08 14:20:02
 * @LastEditors: Please set LastEditors
 */

#ifndef _RLT_SOFTAP_CONFIG_H
#define _RLT_SOFTAP_CONFIG_H

#define PASSWD "12345678"
#define AP_SSID_LEN 32
#define AP_PASSWD_LEN 64

#define MAX_SOCKETS     10
#define SELECT_TIMEOUT  10
#define SERVER_PORT     5000
#define LISTEN_QLEN     2

#define SOFTAP_TIMEOUT_CONFIG 90*1000

typedef struct rlt_ap_setting{
	unsigned char 		ssid[AP_SSID_LEN];
	unsigned char		channel;
	rtw_security_t		security_type;
	unsigned char 		password[AP_PASSWD_LEN];
}rlt_ap_setting;
int socket_client_accept(int server_fd);
int socket_client_data_read(int client_fd);
#endif