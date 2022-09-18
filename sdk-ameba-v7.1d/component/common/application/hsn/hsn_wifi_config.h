/*
 * @Description: smart_config_sniffer.c
 * @Author: xuetong
 * @Date: 2019-08-29 10:07:41
 * @LastEditTime: 2019-10-19 11:51:20
 * @LastEditors: Please set LastEditors
 */

#ifndef WIFI_CONFIG__H
#define WIFI_CONFIG__H

typedef void*	_sema;

enum sc_result {
	SC_ERROR = -1,	/* default error code*/
	SC_NO_CONTROLLER_FOUND = 1, /* cannot get sta(controller) in the air which starts a simple config session */
	SC_CONTROLLER_INFO_PARSE_FAIL, /* cannot parse the sta's info  */
	SC_TARGET_CHANNEL_SCAN_FAIL, /* cannot scan the target channel */
	SC_JOIN_BSS_FAIL, /* fail to connect to target ap */
	SC_DHCP_FAIL, /* fail to get ip address from target ap */
	 /* fail to create udp socket to send info to controller. note that client isolation
		must be turned off in ap. we cannot know if ap has configured this */
	SC_UDP_SOCKET_CREATE_FAIL,
	SC_TERMINATE,
	SC_SUCCESS,	/* default success code */
};

enum{
	SMART_LINK_CONFIG = 0,
	SOFTAP_CONFIG,
	APPPPP,
};


void test_smart_config();
void hsn_stop_softap_confg();



#endif

