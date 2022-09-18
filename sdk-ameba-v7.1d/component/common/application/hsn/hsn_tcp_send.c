/*
 * @Description: rlt_tcp_send.c
 * @Author: xuetong
 * @Date: 2019-08-05 08:48:44
 * @LastEditTime: 2019-10-21 17:22:49
 * @LastEditors: Please set LastEditors
 */

#include "hsn_common.h"

//#define HISENSE_IP "219.147.31.38"
#define HISENSE_IP "27.223.99.153"
#define HISENSE_PORT 8088

#define HISENSE_HOST "ns.wg.hismarttv.com"

xQueueHandle s_tcp_send_queue;


int register_flag = 0;

extern TimerHandle_t heartbeat_timer;
extern TimerHandle_t dataresp_timer;
int tcp_socket_fd = -1;
int server_link = -1;


int http_status = 0;
int m2m_status = 0;
int heartbeat_miss = 0;
int get_heartbeat = 1;

int heartbeat_send_tick;
int heartbeat_wait_tick;
int heartbeat_miss_cnt = 0;

static int m2m_port;
static char m2m_server[16] = {0};

void set_http_status(int flag)
{
	http_status = flag;
}

void set_m2m_status(int flag)
{
	m2m_status = flag;
}

int get_heartbeat_res()
{
	return get_heartbeat;
}

void set_heartbeat_res(int flag)
{
	get_heartbeat = flag;
}

void start_response_tick()
{
	heartbeat_send_tick = xTaskGetTickCount();
}

unsigned char ip_host[64] = {0};


int wapi_send_tcpsend_msg(int msg_flag,unsigned char *data,unsigned int data_len, void* pp_callback)
{
	return rlt_msg_queue_send(s_tcp_send_queue, msg_flag, data, data_len, pp_callback);
}


static char mdm_str[32];
A_CHAR * mdm_inet_ntoa(unsigned int ip)
{
	memset(mdm_str, 0, sizeof(mdm_str));
	sprintf(mdm_str, "%u.%u.%u.%u", (unsigned)(ip & 0xff), (unsigned)((ip >> 8) & 0xff)
		, (unsigned)((ip >> 16) & 0xff), (unsigned)(ip >> 24));
	return mdm_str;
}




int tcp_socket_set(unsigned char *host, unsigned int server_port, unsigned int reconnect_flag)
{
#if 1
	log_printf_d("[%s]\n",__FUNCTION__);
	t_WIFI_GLOBAL* pl_wg = MC_WIFI_GLOBAL_PTR();

	server_link = -1;

	int ret;
	int  keepalive = 1, keepalive_idle = 3, keepalive_interval = 5, keepalive_count = 3;
	struct sockaddr_in local_addr;
	static struct sockaddr_in remote_addr;
	struct hostent *server;

	static struct hostent  *sev_ip;
	static short sev_port = 0;

	if (tcp_socket_fd >= 0)
	{
		close(tcp_socket_fd);
		tcp_socket_fd = -1;
	}

	if(reconnect_flag == 0)
	{
		server = gethostbyname(host);
		if(server == NULL)
		{ 
			printf("[ERROR] Get host ip failed\n");
			goto EXIT;
		}
		sev_ip = server;
		sev_port = server_port;
	}

	printf("ser_ip: %s, ser_port:%d\n", inet_ntoa(sev_ip->h_addr), sev_port);

	if((tcp_socket_fd = socket(AF_INET, SOCK_STREAM, 0)) >= 0) 
	{
		if(setsockopt(tcp_socket_fd, SOL_SOCKET, SO_KEEPALIVE, &keepalive, sizeof(keepalive)) != 0)
			printf("ERROR: SO_KEEPALIVE\n");
		if(setsockopt(tcp_socket_fd, IPPROTO_TCP, TCP_KEEPIDLE, &keepalive_idle, sizeof(keepalive_idle)) != 0)
			printf("ERROR: TCP_KEEPIDLE\n");
		if(setsockopt(tcp_socket_fd, IPPROTO_TCP, TCP_KEEPINTVL, &keepalive_interval, sizeof(keepalive_interval)) != 0)
			printf("ERROR: TCP_KEEPINTVL\n");
		if(setsockopt(tcp_socket_fd, IPPROTO_TCP, TCP_KEEPCNT, &keepalive_count, sizeof(keepalive_count)) != 0)
			printf("ERROR: TCP_KEEPCNT\n");
		local_addr.sin_family = AF_INET;
		local_addr.sin_port = INADDR_ANY;
		local_addr.sin_addr.s_addr = INADDR_ANY;

		if(bind(tcp_socket_fd, (struct sockaddr *) &local_addr, sizeof(local_addr)) < 0) 
		{
			log_printf_w("[%s]bind error\n",__FUNCTION__);
			goto EXIT;
		} 
		printf("tcp bind ok\n");

	    memset(&remote_addr,0,sizeof(remote_addr));
	    remote_addr.sin_family = AF_INET;
	    remote_addr.sin_port = htons(sev_port);
	    //remote_addr.sin_addr.s_addr = inet_addr(sev_ip);
		memcpy(&remote_addr.sin_addr.s_addr,sev_ip->h_addr,sev_ip->h_length);
		if(connect(tcp_socket_fd, (struct sockaddr *)&remote_addr, sizeof(struct sockaddr)) < 0)
		{
			log_printf_w("[%s]connect error\n",__FUNCTION__);
			goto EXIT;
		}
		
		log_printf_d("[%s]connect OK\n",__FUNCTION__);
		ret = device_register_request(tcp_socket_fd);
		if(ret > 0)
		{
			server_link = 1;
		}
		else
		{
			printf("55555555555\n");
			goto EXIT;
		}
	}
	else
	{
		log_printf_w("[%s]socket error\n",__FUNCTION__);
		goto EXIT;
	}
	
#endif
	return tcp_socket_fd;

EXIT:
	if (tcp_socket_fd >= 0)
	{
		close(tcp_socket_fd);
		tcp_socket_fd = -1;
	}
	server_link = -1;
	
	return -1;
	
}

extern TimerHandle_t broadcast_timer;
extern unsigned int s_check_cloud_login_statue;
void rlk_tcp_send_func(void *para)
{
	log_printf_d("[%s]\n",__FUNCTION__);
	t_WIFI_GLOBAL* pl_wg = MC_WIFI_GLOBAL_PTR();
	t_CONFIG_TABLE_BODY* pl_cfg = MC_WG_CONFIG_TABLE_PTR();
	unsigned int payload_len;
	unsigned char payload[80] = {0};
	unsigned char mqtt_msg_type;
	int response_code;
	int server_ip;
	int ret;
	t_queue_msg que_msg;

	static unsigned int s_cloud_reconnet_statue = 0;
	
	hsn_sta_change_cb vp_func;
	rlt_msg_queue_create(&s_tcp_send_queue, 20);
	//wapi_send_tcpsend_msg(SET_TCP_SOCKET, NULL, 0, NULL);

	while(1)
	{
		//ret = xQueueReceiveFromISR(s_tcp_send_queue, &que_msg, NULL);
		ret = xQueueReceive(s_tcp_send_queue, &que_msg,10000);	
		if(ret == pdPASS)
		{
			vp_func = (hsn_sta_change_cb)que_msg.vp_callback;
			switch(que_msg.msg_flag)
			{
				case SET_TCP_SOCKET:
					log_printf_d("[%s]tcp socket create\n",__FUNCTION__);
					if (HSN_ROUTER_STATE_CONNECTED == pl_wg->v_router_sta)
					{
						pl_wg->v_cloud_login_sta = HSN_LOGIN_STATE_DISCONNET;
						set_heartbeat_uninit();
						set_dataresp_timer_uninit();
						
						ret = tcp_socket_set(HISENSE_HOST, HISENSE_PORT,0);
						if(ret >= 0)
						{
							printf("tcp_socket_set ok\n");
							timerReset(&s_cloud_reconnet_statue);
							timerReset(&s_check_cloud_login_statue);
							pl_wg->v_cloud_login_sta = HSN_LOGIN_STATE_START_REGISTER;
						}
						else
						{
							printf("tcp_socket_set fail\n");
							pl_wg->v_cloud_reconnect_flag = 1;
						}
					}
					else
					{
						printf("router disconnect, wait to tcp serv\n");
						pl_wg->v_cloud_reconnect_cnt = 0;
					}
					
					break;

				case DEVICE_LOGOUT:
					printf("DEVICE_LOGOUT\n");
					set_broadcast_uninit();
					if (HSN_LOGIN_STATE_HB == pl_wg->v_cloud_login_sta)
					{
						ret = device_ask_unbind_to_net();	
					}
					
					if (NULL != vp_func)
						vp_func(HOST_ENTRY_MSG_UNBIND_DEV, ret, NULL);
					
					if (0 == pl_wg->v_wifi_config_on)
					{
						hsn_reset_config_table(0);
						bapi_set_write_config_flag();
						bapi_set_reboot_flag(38);
					}
					break;


				case LAN_LOGOUT:
					printf("LAN_LOGOUT\n");
					if(tcp_socket_fd >= 0)
					{
						close(tcp_socket_fd);
						tcp_socket_fd = -1;
					}	
					pl_wg->v_cloud_login_sta = HSN_LOGIN_STATE_DISCONNET;
					set_broadcast_uninit();	
					
					printf("xTimerStop heartbeat_timer\n");
					set_heartbeat_uninit();
					printf("xTimerStop dataresp_timer\n");
					set_dataresp_timer_uninit();
					printf("rlt_udp_offline_func_entry\n");
					rlt_udp_offline_func_entry();
				break;
				
				case DATA_FROM_UART:
					//log_printf_d("[%s]data from uart\n",__FUNCTION__);
					data_uart2net_handle(que_msg.data, que_msg.data_len);
					if (que_msg.data != NULL)
					{
						free(que_msg.data);
						que_msg.data = NULL;
					}
					break;
				case CALIBRATE_TIME:
					device_system_param_request(0);
					break;
				default:
					break;
			}
		}

		//printf("%s runn \n", __FUNCTION__);
		
		if (isTimeOut(s_cloud_reconnet_statue, 10000))
		{
			timerReset(&s_cloud_reconnet_statue);
			if (HSN_ROUTER_STATE_CONNECTED == pl_wg->v_router_sta)
			{
				if(pl_wg->v_cloud_reconnect_flag == 1)
				{
					printf(" #tttt 2\n");
					pl_wg->v_cloud_reconnect_cnt++;
					if (pl_wg->v_cloud_reconnect_cnt > 30)//
					{
						printf("clound connect try to reboot\n");
						pl_wg->v_cloud_reconnect_cnt = 0;
						bapi_set_reboot_flag(34);
					}
					else
					{
						printf("cloud reconnect:%d\n", pl_wg->v_cloud_reconnect_cnt);
						wapi_send_tcpsend_msg(SET_TCP_SOCKET, NULL, 0, NULL);
					}
				}
			}
			else
			{
				pl_wg->v_cloud_reconnect_flag = 0;
				pl_wg->v_cloud_reconnect_cnt = 0;
				printf("wait for router connected...\n");
			}
		}
	
		vTaskDelay(1);
		//LOGW("queue timeout\n");
	}
}


int rlk_tcp_send_entry()
{
	xTaskHandle app_task_handle = NULL;
	if(xTaskCreate((TaskFunction_t)rlk_tcp_send_func, (char const *)"rlk tcp send task", 1024*2, NULL, tskIDLE_PRIORITY + HSN_TSK_PRIORITY, &app_task_handle) != pdPASS) {
		printf("xTask send func Create failed\n");	
	}
	return 0;
}

