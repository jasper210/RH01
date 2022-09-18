/*
 * @Description: rlt_softap_config.c
 * @Author: xuetong
 * @Date: 2019-08-05 08:48:44
 * @LastEditTime: 2019-09-03 19:32:51
 * @LastEditors: Please set LastEditors
 */

#include "hsn_common.h"

int recv_0x0082_flag = 0;


extern struct netif xnetif[NET_IF_NUM]; 

int udp_socket_init(unsigned int port)
{
	int socket = -1;
	int broadcast = 1;
	struct sockaddr_in local_addr;
	
	if((socket = socket(AF_INET, SOCK_DGRAM, 0)) < 0) 
	{
		log_printf_w("[%s]socket create error\n",__FUNCTION__);
		return -1;
	}
	
	if(setsockopt(socket, SOL_SOCKET, SO_BROADCAST, &broadcast, sizeof(broadcast)) < 0)
	{
		log_printf_w("[%s]setsockopt failed\n",__FUNCTION__);
		return -1;
	}
	
	memset(&local_addr, 0, sizeof(local_addr));
	local_addr.sin_family = AF_INET;
	local_addr.sin_port = htons(port);
	local_addr.sin_addr.s_addr = INADDR_ANY;
	if(bind(socket, (struct sockaddr *) &local_addr, sizeof(local_addr)) < 0)
	{
		log_printf_w("[%s]bind error\n",__FUNCTION__);
		return -1;
	}
	return socket;
}


int tcp_socket_init(unsigned int port)
{
	int local_fd = -1;
	struct sockaddr_in local_addr;
	if((local_fd = socket(AF_INET, SOCK_STREAM, 0)) >= 0) 
	{
		local_addr.sin_family = AF_INET;
		local_addr.sin_port = htons(port);		
		local_addr.sin_addr.s_addr = INADDR_ANY;

		if(bind(local_fd, (struct sockaddr *) &local_addr, sizeof(local_addr)) != 0) 
		{
			log_printf_w("[%s]bind error\n",__FUNCTION__);
			return -1;
		}
		return local_fd;
	}
	log_printf_w("[%s]socket create error\n",__FUNCTION__);
	return -1;
}


int socket_client_accept(int server_fd)
{
	struct sockaddr_in client_addr;
	unsigned int client_addr_size = sizeof(client_addr);
	int fd;
    fd = accept(server_fd, (struct sockaddr *) &client_addr, &client_addr_size);
	return fd;
}


int socket_client_data_read(int client_fd)
{
	unsigned char buf[512];
	memset(buf, 0, sizeof(buf));
	int read_size = read(client_fd, buf, sizeof(buf));
	if(read_size > 0) 
	{
		printf("LAN recv: %s\n", buf);
		lan_net_data_parse(buf, read_size, client_fd);
	}
    return read_size;
}


void rlt_generate_ap_name(unsigned char *ap_name)
{
	log_printf_d("[%s]system init\n",__func__);
	t_WIFI_GLOBAL* pl_wg = MC_WIFI_GLOBAL_PTR();
	
	unsigned char *model_mac;
	model_mac = LwIP_GetMAC(&xnetif[0]);
#if HSN_TEST_MAC
	model_mac[0] = HSN_MAC0;
	model_mac[1] = HSN_MAC1;
	model_mac[2] = HSN_MAC2;
	model_mac[3] = HSN_MAC3;
	model_mac[4] = HSN_MAC4;
	model_mac[5] = HSN_MAC5;
#endif
	memset(ap_name, 0, AP_SSID_LEN);
#ifdef HSN_UPDATE_20210926
	sprintf(ap_name, "%s%02X%s%02X%02X", "HIS-B2-", pl_wg->v_device_type, "-", model_mac[4], model_mac[5]);
#else
	sprintf(ap_name, "%s%02x%02x", "HIS-",model_mac[4], model_mac[5]);
#endif
	
	log_printf_d("[%s]ap name:%s\n",__FUNCTION__,ap_name);
}

void rlt_softap_start(rlt_ap_setting *ap_info)
{
	int timeout = 20;
#if CONFIG_LWIP_LAYER 
	struct ip_addr ipaddr;
	struct ip_addr netmask;
	struct ip_addr gw;
	struct netif * pnetif = &xnetif[0];
#endif
	int ret = 0;
#if CONFIG_LWIP_LAYER
	log_printf_d("[%s]\n",__FUNCTION__);
	dhcps_deinit();
	IP4_ADDR(&ipaddr, GW_ADDR0, GW_ADDR1, GW_ADDR2, GW_ADDR3);
	IP4_ADDR(&netmask, NETMASK_ADDR0, NETMASK_ADDR1 , NETMASK_ADDR2, NETMASK_ADDR3);
	IP4_ADDR(&gw, GW_ADDR0, GW_ADDR1, GW_ADDR2, GW_ADDR3);
	netif_set_addr(pnetif, &ipaddr, &netmask,&gw);
#endif
	wifi_off();
	vTaskDelay(20);
	if (wifi_on(RTW_MODE_AP) < 0)
	{
		log_printf_w("[%s]Wifi on failed\n",__FUNCTION__);
		ret = RTW_ERROR;
		return;
	}
	log_printf_d("[%s]Starting AP\n",__FUNCTION__);
	ret = wifi_start_ap((char*)ap_info->ssid, ap_info->security_type, NULL, strlen(ap_info->ssid), 0, ap_info->channel);
	if(ret < 0)
	{
		log_printf_w("[%s]ERROR: Operation failed!\n",__FUNCTION__);
		return;
	}
	log_printf_d("[%s]OK: Operation success!\n",__FUNCTION__);
	dhcps_init(&xnetif[0]);

	//rlt_tcp_server_entry();
	while(1)
	{
		vTaskDelay(3000);
	}
}

void rlt_softap_config_mode(void *para)
{
	rlt_ap_setting *ap_info;
	ap_info = (rlt_ap_setting *)malloc(sizeof(rlt_ap_setting));
	if(ap_info == NULL)
	{
		log_printf_w("[%s]malloc error\n",__FUNCTION__);
		return;
	}
	rlt_generate_ap_name(ap_info->ssid);
	ap_info->security_type = RTW_SECURITY_OPEN;
	ap_info->channel = 6;

	rlt_softap_start(ap_info);
}

int rlt_softap_config_entry()
{
	xTaskHandle app_task_handle = NULL;

	if(xTaskCreate((TaskFunction_t)rlt_softap_config_mode, (char const *)"rlt softap config", 1024, NULL, tskIDLE_PRIORITY + HSN_TSK_PRIORITY, &app_task_handle) != pdPASS) {
		printf("xTaskCreate failed\n");	
	}
	return 0;
}



