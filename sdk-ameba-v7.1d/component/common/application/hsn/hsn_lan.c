/*
 * @Description: lan.c
 * @Author: xuetong
 * @Date: 2019-08-21 09:03:05
 * @LastEditTime: 2019-10-29 15:13:43
 * @LastEditors: Please set LastEditors
 */
#include "hsn_common.h"

xTaskHandle offline_notify_task = NULL;
TimerHandle_t broadcast_timer = NULL;
unsigned char broadcast_packet[256] = {0};
int udp_socket_fd = -1;
struct sockaddr_in to;
struct sockaddr_in from_addr;

void rlt_broadcast_offline_func(void *para)
{
	t_CONFIG_TABLE_BODY* pl_cfg = MC_WG_CONFIG_TABLE_PTR();
	int ret;
	unsigned char *tdata;
	unsigned int tdata_len;
	while(1)
	{
		tdata = malloc(512);
		if(tdata == NULL)
		{
			log_printf_w("[%s]malloc error\n",__FUNCTION__);
			continue;
		}       
		memset(tdata, 0, 512);
		tdata_len = discover_send_offline_notify(tdata);
		if(tdata_len)
		{
			ret = sendto(udp_socket_fd, tdata, tdata_len, 0, (struct sockaddr*)&to, sizeof(struct sockaddr));
			vTaskDelay(500);
			ret = sendto(udp_socket_fd, tdata, tdata_len, 0, (struct sockaddr*)&to, sizeof(struct sockaddr));
			vTaskDelay(500);
			ret = sendto(udp_socket_fd, tdata, tdata_len, 0, (struct sockaddr*)&to, sizeof(struct sockaddr));
			vTaskDelay(500);
			ret = sendto(udp_socket_fd, tdata, tdata_len, 0, (struct sockaddr*)&to, sizeof(struct sockaddr));
			if(ret >= 0)
			{
				//printf("LAN send: %s %s\n", inet_ntoa(to.sin_addr), tdata);
				printf("LAN send offline: %s\n", inet_ntoa(to.sin_addr));
				hsn_reset_config_table(0);
				bapi_set_write_config_flag();
				bapi_set_reboot_flag(3);
			}
		}
		vTaskDelay(300);
	}
} 
int rlt_udp_offline_func_entry()
{
	xTaskHandle app_task_handle = NULL;
	if(xTaskCreate((TaskFunction_t)rlt_broadcast_offline_func, (char const *)"rlt udp send start", 512,  NULL, tskIDLE_PRIORITY + HSN_TSK_PRIORITY, &app_task_handle) != pdPASS) {
		printf("xTaskCreate failed\n");	
		return -1;
	}
	printf("LAN udp send:start\n",__FUNCTION__);
	return 0;
}

void rlt_broadcast_func()
{
	LOGT("start send broadcast...\n");
	t_CONFIG_TABLE_BODY* pl_cfg = MC_WG_CONFIG_TABLE_PTR();
	int ret;
	unsigned char *tdata;
	unsigned int tdata_len;
	unsigned char vl_cnt = 2;

	tdata = malloc(512);
	if(tdata == NULL)
	{
		log_printf_w("[%s]malloc error\n",__FUNCTION__);
		vl_cnt = 0;
	}  
	
	while(vl_cnt)
	{
		vl_cnt--;		     
		memset(tdata, 0, 512);
		
		tdata_len = discover_send_offline_notify(tdata);
		if(tdata_len)
		{
			ret = sendto(udp_socket_fd, tdata, tdata_len, 0, (struct sockaddr*)&to, sizeof(struct sockaddr));
			if(ret >= 0)
			{
				printf("LAN send packet: %s %s, length:%d\n", inet_ntoa(to.sin_addr), tdata, strlen(tdata));
			}
		}
		vTaskDelay(200);
	}
	
	free(tdata);
	vTaskDelete(NULL);
} 

void broadcast_handle(xTimerHandle pxTimer)
{
	int ret;
	static int cnt = 0;
	ret = bc_wifi_msg_packet_build(broadcast_packet);
	ret = sendto(udp_socket_fd, broadcast_packet, ret, 0, (struct sockaddr*)&to, sizeof(struct sockaddr));
	if(ret >= 0)
	{
	}
#if 0
	if(cnt < 30)
	{
		cnt++;
		ret = sendto(udp_socket_fd, broadcast_packet, ret, 0, &to, sizeof(struct sockaddr));
		if(ret >= 0)
		{
			printf("lan send packet:%s, length:%d\n", broadcast_packet, strlen(broadcast_packet));
		}
	}
	else
	{
		xTimerStop(broadcast_timer, 0);
		xTimerChangePeriod(broadcast_timer, 3 * 1000, 0);
	}
#endif
}

int set_broadcast_init()
{
	broadcast_timer = xTimerCreate("broadcast timer", 1500, pdTRUE, NULL, broadcast_handle);
	xTimerStart(broadcast_timer, 0);
	return 1;
}

int set_broadcast_uninit()
{
	if (broadcast_timer != NULL)
	{
		xTimerStop(broadcast_timer, 0);
		xTimerDelete(broadcast_timer, 0);
		broadcast_timer = NULL;		
	}
	return 1;
}



void rlt_broadcast_recv_func()
{
	LOGT("start receive broadcast\n");
	int time_cnt = 0;
	static int cnt = 0;
	int ret;
    char host[64];
	unsigned char packet[256] = {0};
	unsigned char rxbuf[128];
	//struct sockaddr_in from_addr;

	int from_addr_len = sizeof(from_addr);
	udp_socket_fd = udp_socket_init(WIFI_PORT);
	if(udp_socket_fd < 0)
	{
		log_printf_w("[%s]udp init error\n",__FUNCTION__);
	}

	to.sin_family = AF_INET;
	to.sin_port = htons(PHONE_PORT);
	to.sin_addr.s_addr = htonl(0xffffffff);

    from_addr.sin_family = AF_INET;
	from_addr.sin_port = htons(PHONE_PORT);
	from_addr.sin_addr.s_addr = INADDR_ANY;
	ret = bc_wifi_msg_packet_build(packet);
	set_broadcast_init();
	while(1) 
	{
		fd_set read_fds;
		struct timeval timeout;

		FD_ZERO(&read_fds);
		FD_SET(udp_socket_fd, &read_fds);
		timeout.tv_sec = SELECT_TIMEOUT;
		timeout.tv_usec = 0;
		memset(rxbuf, 0, 128);
		ret = select(udp_socket_fd + 1, &read_fds, NULL, NULL, &timeout);
		if(ret > 0) 
		{
			int read_size = recvfrom(udp_socket_fd, rxbuf, 128, 0, (struct sockaddr *)&from_addr, &from_addr_len);
			if(read_size > 0)
			{
                //printf("LAN udp recv: %s %s\n", inet_ntoa(from_addr.sin_addr), rxbuf);
                printf("Broadcast recv: %s\n", inet_ntoa(from_addr.sin_addr));
				lan_net_data_parse(rxbuf, read_size, udp_socket_fd);
			}
		}
		else if (ret == 0)
		{
			cnt++;
			if(cnt == 30)
			{
				ret = sendto(udp_socket_fd, packet, ret, 0, (struct sockaddr*)&to, sizeof(struct sockaddr));
				if(ret >= 0)
				{
					printf("lan send packet:%s, length:%d\n", packet, strlen(packet));
				}
				vTaskDelay(300);
				ret = sendto(udp_socket_fd, packet, ret, 0, (struct sockaddr*)&to, sizeof(struct sockaddr));
				if(ret >= 0)
				{
					printf("lan send packet:%s, length:%d\n", packet, strlen(packet));
				}
				cnt = 0;
			}
		}
		else
		{
			LOGW("select error:%d\n", ret);
			vTaskDelay(1000);
		}
		
	}

exit:
	if(udp_socket_fd >= 0)
		close(udp_socket_fd);
	vTaskDelete(NULL);
}


void rlt_tcp_server_start(int argc, char *argv[])
{
	int max_socket_fd = -1;
	struct sockaddr_in server_addr;
	int server_fd = -1;
	int socket_used[MAX_SOCKETS];
	int ret;

	memset(socket_used, 0, sizeof(socket_used));
	if((server_fd = tcp_socket_init(PROBE_WIFI_PORT)) >= 0) 
	{
		if(listen(server_fd, HSN_LISTEN_QLEN) != 0) 
		{
			printf("listen error\n");
			goto exit;
		}
		socket_used[server_fd] = 1;
		if(server_fd > max_socket_fd)
			max_socket_fd = server_fd;
	}
	else
	{
		printf("socket error\n");
		goto exit;
	}
	while(1) 
	{
		int socket_fd;
		fd_set read_fds;
		struct timeval timeout;

		FD_ZERO(&read_fds);
		timeout.tv_sec = SELECT_TIMEOUT;
		timeout.tv_usec = 0;

		for(socket_fd = 0; socket_fd < MAX_SOCKETS; socket_fd ++)
			if(socket_used[socket_fd])
				FD_SET(socket_fd, &read_fds);

		ret = select(max_socket_fd + 1, &read_fds, NULL, NULL, &timeout);
		if(ret > 0) 
		{
			for(socket_fd = 0; socket_fd < MAX_SOCKETS; socket_fd ++) 
			{
				if(socket_used[socket_fd] && FD_ISSET(socket_fd, &read_fds)) 
				{
					if(socket_fd == server_fd) 
					{
						int fd = socket_client_accept(server_fd);
						if(fd >= 0) 
						{
							printf("accept socket fd(%d)\n", fd);
							socket_used[fd] = 1;
							if(fd > max_socket_fd)
								max_socket_fd = fd;
						}
						else 
						{
							printf("accept error\n");
						}
					}
					else 
					{
						int read_size = socket_client_data_read(socket_fd);
						if(read_size > 0) 
						{
							printf("socket fd(%d) read:%d\n", read_size);
						}
						else {
							printf("socket fd(%d) disconnected\n", socket_fd);
							socket_used[socket_fd] = 0;
							close(socket_fd);
						}
					}
				}
			}
		}
		else if (ret == 0)
		{
			printf("LAN tcp server: no data in %d seconds\n", SELECT_TIMEOUT);
		}
		else
		{
			LOGW("select error:%d\n", ret);
			vTaskDelay(1000);
		}
	}

exit:
	if(server_fd >= 0)
		close(server_fd);

	vTaskDelete(NULL);
}


void example_socket_select_thread(void *param)
{
	printf("entry lan tcp serv\n");
	int max_socket_fd = -1;
	struct sockaddr_in server_addr;
	int server_fd = -1;
	int socket_used[MAX_SOCKETS];
	int ret;

	// Delay to wait for IP by DHCP
	vTaskDelay(10000);
	printf("socket select start\n");

	memset(socket_used, 0, sizeof(socket_used));

	if((server_fd = socket(AF_INET, SOCK_STREAM, 0)) >= 0) {
		server_addr.sin_family = AF_INET;
		server_addr.sin_port = htons(PROBE_WIFI_PORT);
		server_addr.sin_addr.s_addr = INADDR_ANY;

		if(bind(server_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) != 0) {
			printf("bind error\n");
			goto exit;
		}

		if(listen(server_fd, HSN_LISTEN_QLEN) != 0) {
			printf("listen error\n");
			goto exit;
		}

		socket_used[server_fd] = 1;

		if(server_fd > max_socket_fd)
			max_socket_fd = server_fd;
	}
	else {
		printf("socket error\n");
		goto exit;
	}

	while(1) {
		//printf("%s runn \n", __FUNCTION__);
		int socket_fd;
		fd_set read_fds;
		struct timeval timeout;

		FD_ZERO(&read_fds);
		timeout.tv_sec = SELECT_TIMEOUT;
		timeout.tv_usec = 0;

		for(socket_fd = 0; socket_fd < MAX_SOCKETS; socket_fd ++)
			if(socket_used[socket_fd])
				FD_SET(socket_fd, &read_fds);
		
		ret = select(max_socket_fd + 1, &read_fds, NULL, NULL, &timeout);
		if(ret > 0) 
		{
			for(socket_fd = 0; socket_fd < MAX_SOCKETS; socket_fd ++) {
				if(socket_used[socket_fd] && FD_ISSET(socket_fd, &read_fds)) {
					if(socket_fd == server_fd) {
						struct sockaddr_in client_addr;
						unsigned int client_addr_size = sizeof(client_addr);
						int fd = accept(server_fd, (struct sockaddr *) &client_addr, &client_addr_size);

						if(fd >= 0) 
						{
							printf("accept socket fd(%d)\n", fd);
							socket_used[fd] = 1;

							if(fd > max_socket_fd)
								max_socket_fd = fd;
						}
						else 
						{
							printf("accept error\n");
						}
					}
					else 
					{
						int read_size = socket_client_data_read(socket_fd);
						if(read_size > 0) 
						{
							printf("socket1 fd(%d) read1:%d\n", read_size);
						}
						else 
						{
							printf("socket fd(%d) disconnected\n", socket_fd);
							socket_used[socket_fd] = 0;
							close(socket_fd);
						}
					}
				}
			}
		}
		else if (ret == 0)
		{
			//printf("TCP server: no data in %d seconds\n", SELECT_TIMEOUT);
		}
		else 
		{
			LOGW("select error:%d\n", ret);
			vTaskDelay(1000);
		}
		
	}

exit:
	if(server_fd >= 0)
		close(server_fd);

	vTaskDelete(NULL);
}

void rlt_device_discover_func(void *param)
{
	rlt_broadcast_func();
}

void rlt_device_discover_resp_func(void *param)
{
	rlt_broadcast_recv_func();
}


int rlt_udp_send_func_entry()
{
	if(xTaskCreate((TaskFunction_t)rlt_device_discover_func, (char const *)"rlt udp send start", 512,  NULL, tskIDLE_PRIORITY + HSN_TSK_PRIORITY, &offline_notify_task) != pdPASS) {
		printf("xTaskCreate failed\n");	
		return -1;
	}
	printf("LAN udp send:start\n",__FUNCTION__);
	return 0;
}

int rlt_udp_recv_func_entry()
{
	xTaskHandle app_task_handle = NULL;
	if(xTaskCreate((TaskFunction_t)rlt_device_discover_resp_func, (char const *)"rlt udp recv start", 1024,  NULL, tskIDLE_PRIORITY + HSN_TSK_PRIORITY, &app_task_handle) != pdPASS) {
		printf("xTaskCreate failed\n");	
		return -1;
	}
	printf("LAN udp recv:start\n",__FUNCTION__);
	return 0;
}

int rlt_tcp_server_entry()
{
	xTaskHandle app_task_handle = NULL;

	if(xTaskCreate((TaskFunction_t)example_socket_select_thread, (char const *)"rlt tcp server start", 1024, NULL, tskIDLE_PRIORITY + HSN_TSK_PRIORITY, &app_task_handle) != pdPASS) {
		printf("[%s]xTaskCreate failed\n",__FUNCTION__);	
		return -1;
	}
	printf("LAN server:start\n",__FUNCTION__);	
	return 0;
}
