/*
 * @Description: rlt_tcp_recv.c
 * @Author: your name
 * @Date: 2019-08-05 08:48:44
 * @LastEditTime: 2019-10-08 14:43:20
 * @LastEditors: Please set LastEditors
 */
#include "hsn_common.h"


extern int tcp_socket_fd;
extern int server_link;
unsigned int s_check_cloud_login_statue = 0;
void rlk_tcp_recv_func(void *para)
{
	log_printf_d("[%s]\n",__FUNCTION__);
	t_WIFI_GLOBAL* pl_wg = MC_WIFI_GLOBAL_PTR();
	fd_set read_fds;
	struct timeval timeout;
	unsigned char rx_buff[512] = {0};
	int ret;
	while(1) 
	{
		if(server_link == 1)
		{
			//printf("[%s]socket fd:%d\n",__FUNCTION__,socket_fd);
			FD_ZERO(&read_fds);
			timeout.tv_sec = 5;
			timeout.tv_usec = 0;
			FD_SET(tcp_socket_fd, &read_fds);
			ret = select(tcp_socket_fd + 1, &read_fds, NULL, NULL, &timeout);
			if(ret > 0) 
			{
				if(FD_ISSET(tcp_socket_fd, &read_fds)) 
				{
					memset(rx_buff, 0, 512);
					int read_size = recv(tcp_socket_fd, rx_buff, 512, 0);
					if(read_size > 0)
					{
						//printf("CLOUD RECV: %d\n", read_size);
#if (HSN_DEBUG_NET==1)
						printf("%s\n",rx_buff);
#endif
						cloud_data_parse(rx_buff, read_size, tcp_socket_fd);
					}
					else if (0 == read_size)
					{//go on
						vTaskDelay(1000);
					}
					else
					{
						printf("tcp_socket_fd recv fail:%d\n", read_size);
						//wapi_send_tcpsend_msg(CLOUD_RECONNECT, NULL, 0, NULL);
						vTaskDelay(1000);
						//server_link = -1;
					}
				}
			}
			else if (ret == 0)
			{
				//printf("TCP1 recv: no data in 10 seconds\n");
				vTaskDelay(1000);
			}
			else
			{
				LOGW("select error:%d\n", ret);
				vTaskDelay(1000);
			}
		}
		else
		{
			vTaskDelay(1000);
			//timerReset(&s_check_cloud_login_statue);
		}
		//printf("%s runn \n", __FUNCTION__);
		//check login complete
		if (isTimeOut(s_check_cloud_login_statue, 10000))
		{
			timerReset(&s_check_cloud_login_statue);
			if ((HSN_LOGIN_STATE_START_REGISTER == pl_wg->v_cloud_login_sta)
			|| (HSN_LOGIN_STATE_REGISTER == pl_wg->v_cloud_login_sta)
			|| (HSN_LOGIN_STATE_DYNAMIC_KEY == pl_wg->v_cloud_login_sta) )
			{
				pl_wg->v_cloud_login_sta = HSN_LOGIN_STATE_DISCONNET;
				printf("login not complete, re-login\n");
				pl_wg->v_cloud_reconnect_flag = 1;
			}
		}
	}
}


int rlk_tcp_recv_entry()
{
	log_printf_d("[%s]\n",__FUNCTION__);
	xTaskHandle app_task_handle = NULL;

	if(xTaskCreate((TaskFunction_t)rlk_tcp_recv_func, (char const *)"rlk tcp recv task", 2048, NULL, tskIDLE_PRIORITY + HSN_TSK_PRIORITY, &app_task_handle) != pdPASS) {
		printf("xTask recv func Create failed\n");	
	}
	return 0;
}