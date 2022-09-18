/*
 * @Description: lan.h
 * @Author: xuetong
 * @Date: 2019-08-21 09:04:43
 * @LastEditTime: 2019-10-08 14:24:44
 * @LastEditors: Please set LastEditors
 */
#ifndef _LAN_H
#define _LAN_H

#define PHONE_PORT 5010
#define WIFI_PORT 5030
#define PROBE_WIFI_PORT 5020


#define MAX_SOCKETS     10
#define SELECT_TIMEOUT  10
#define SERVER_PORT     5000
#define HSN_LISTEN_QLEN     6

void rlt_broadcast_recv_func();
void rlt_broadcast_func();
void rlt_tcp_server_start(int argc, char *argv[]);
void example_socket_select_thread(void *param);
int rlt_udp_offline_func_entry();


int set_broadcast_init();
int set_broadcast_uninit();

#endif