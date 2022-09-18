#include "hisen_common.h"


#include <platform_opts.h>
#include "FreeRTOS.h"
#include "task.h"
#include <platform/platform_stdlib.h>
#include "semphr.h"
#include "device.h"
#include "serial_api.h"
#include "at_cmd/log_service.h"
#include "uart_atcmd/example_uart_atcmd.h"
#include "flash_api.h"
#include "device_lock.h"
#if defined(configUSE_WAKELOCK_PMU) && (configUSE_WAKELOCK_PMU == 1)
#include "freertos_pmu.h"
#endif
#include "osdep_service.h"
#include "serial_ex_api.h"
#include "at_cmd/atcmd_wifi.h"
#include "at_cmd/atcmd_lwip.h"
#include "pinmap.h"

#include "uart_socket.h"



typedef struct {
	A_UINT32	v_seq; //流水号
	bool		v_wait_flag;
	A_UINT32	v_who;
	A_UINT32	v_flag;
	A_UINT8		v_msgtype;
	A_UINT8		a_reserve[3];

} t_UART_PACKET_UNIQUE;


t_UART_PACKET_UNIQUE s_pkt_unq;
static xTimerHandle s_pkt_unique_timer; // the timer handle of created FreeRTOS soft-timer

extern void stop_pkt_unique_timer();
void unique_timer_callback(TimerHandle_t xTimer)
{
	//A_PRINTF("clr wt:%d,%d,%d\n", uart_receive_state, uart_receive_buff_pos, pkt_len);
	printf("clr wt\n");
	stop_pkt_unique_timer();
	//bapi_midea_uart_reset_state();
	s_pkt_unq.v_wait_flag = false;
}

void start_pkt_unique_timer()
{
	s_pkt_unique_timer = xTimerCreate("pkt_unique_timer", 1000,
		pdFALSE, (void *)0, unique_timer_callback);
	xTimerStart(s_pkt_unique_timer, 0);
}

void stop_pkt_unique_timer()
{
	xTimerStop(s_pkt_unique_timer, 0);
	xTimerDelete(s_pkt_unique_timer, 0);
}



bool init_unique(A_UINT8 vp_msg_type, A_UINT32 vp_seq, A_UINT32 vp_who, A_UINT32 vp_flag)
{
	bool bl_ret = false;
	if (false == s_pkt_unq.v_wait_flag)
	{
		s_pkt_unq.v_wait_flag = true;
		s_pkt_unq.v_seq = vp_seq;
		s_pkt_unq.v_who = vp_who;
		s_pkt_unq.v_msgtype = vp_msg_type;
		s_pkt_unq.v_flag = vp_flag;
		start_pkt_unique_timer();
		//printf("Swho:%d,msgtype:%x,v_seq:%x\n", s_pkt_unq.v_who, s_pkt_unq.v_msgtype, s_pkt_unq.v_seq);
		bl_ret = true;
	}
	else
	{
		printf("waiting:%d\n", s_pkt_unq.v_wait_flag);
	}

	return bl_ret;
}

bool check_unique(A_UINT8 vp_msgtype, A_UINT32* pp_seq, A_UINT32* pp_who, A_UINT32* pp_flag)
{
	bool bl_ret = false;
	if (true == s_pkt_unq.v_wait_flag)
	{
		//if (vp_msgtype == s_pkt_unq.v_msgtype)
        if(1)
		{
			printf("clr 1\n");
			stop_pkt_unique_timer();
			*pp_seq = s_pkt_unq.v_seq;
			*pp_who = s_pkt_unq.v_who;
			*pp_flag = s_pkt_unq.v_flag;
			//printf("Rwho:%d,msgtype:%x,v_seq:%x\n", s_pkt_unq.v_who, s_pkt_unq.v_msgtype, s_pkt_unq.v_seq);
			bl_ret = true;
			s_pkt_unq.v_wait_flag = false;
		}
		else
		{
			printf("not wait msgtype:%x,%x\n", vp_msgtype, s_pkt_unq.v_msgtype);
		}
	}
	else
	{
		printf("not wait:%d\n", s_pkt_unq.v_wait_flag);
	}

	return bl_ret;

}

///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////





static uart_socket_t *sp_uart_socket = NULL;
static uart_recv_callback sp_uart_recv_cb = NULL;
static A_UINT8 sa_rx_buf[UART_RECV_BUFFER_LEN];
static xQueueHandle s_handle_mq_uart_send;

int wapi_uart_send_direct(A_UINT8* pp_data, A_UINT8 vp_len, void* pp_ctx)
{
    int vl_ret = -1;
    t_WAPI_MSG vl_msg;
	memset(&vl_msg, 0, sizeof(vl_msg));
    
    A_UINT8* pl_data = (A_UINT8* )malloc(vp_len);
    if (NULL != pl_data)
    {
        memcpy(pl_data, pp_data, vp_len);
        
        vl_msg.v_msgtype = UART_SEND_MSG_DIRECT;
        vl_msg.v_msgbody_len = vp_len;
        vl_msg.p_msgbody = pl_data;
		SC_MSG_taskEXIT_CRITICAL();
        if (pdTRUE == xQueueSend(s_handle_mq_uart_send, (void* )&vl_msg, 0))
        {
            vl_ret = 0;
        }
		else
		{
			if (NULL != pl_data)
			{
				free(pl_data);
			}
		}
		SC_MSG_taskEXIT_CRITICAL();
		SC_SURREND_TASK();
    }
    
    return vl_ret;
}

int wapi_send_to_uartsend_msg_ex(A_UINT8 vp_cmd, A_UINT32 vp_para, A_UINT32 vp_seq, A_UINT8* pp_msgbody, A_UINT32 vp_msgbody_len)
{
	int vl_ret = -1;
	t_WAPI_MSG vl_msg;
	memset(&vl_msg, 0, sizeof(vl_msg));

	vl_msg.v_msgtype = vp_cmd;
	vl_msg.v_para = vp_para;
	vl_msg.v_seq = vp_seq;

	A_UINT8* pl_data = (A_UINT8*)malloc(vp_msgbody_len);
	if (NULL != pl_data)
	{
		memcpy(pl_data, pp_msgbody, vp_msgbody_len);
		
		vl_msg.v_msgbody_len = vp_msgbody_len;
		vl_msg.p_msgbody = pl_data;
		SC_MSG_taskENTER_CRITICAL();
		if (pdTRUE == xQueueSend(s_handle_mq_uart_send, (void*)&vl_msg, 0))
		{
			vl_ret = 0;
		}
		else
		{
			if (NULL != pl_data)
			{
				free(pl_data);
			}
		}
		SC_MSG_taskEXIT_CRITICAL();
		SC_SURREND_TASK();
	}

	return vl_ret;
}

#define CHIGO_UART_CTRL_BIT_T13		0x70
#define CHIGO_UART_CTRL_BIT_T14		0x38	//0xC0
#define CHIGO_UART_CTRL_BIT_T16		0xE0
#define CHIGO_UART_CTRL_BIT_T17		0x01


static void wapi_uart_send_thread(void *param)
{
	vTaskDelay(500);
    printf("uart send thread run...\n"); 
    t_WAPI_MSG vl_msg;
    memset(&vl_msg, 0, sizeof(vl_msg));
	A_UINT8	 vl_msgtype;
	A_UINT32 vl_para;
	A_UINT8  vl_header_len = 0;
	A_UINT16 vl_msgbody_len = 0;
	A_UINT8* pl_msgheader = NULL;
	A_UINT8* pl_msgbody = NULL;
	A_UINT32 vl_seq = 0;
	A_UINT32 vl_para2 = 0;

	bool bl_ret = false;
	A_UINT32 vl_flag = 0;
    
    int uart_fd = sp_uart_socket->fd;
    
    if (uart_fd < 0)
    {
        printf("uart fd <0\n");
        goto Exit;
    }
    
    s_handle_mq_uart_send = xQueueCreate(MSG_COUNT , MSG_SIZE);
    
    
    while(1)
    {
        if( xQueueReceive(s_handle_mq_uart_send, &vl_msg, 1000/portTICK_RATE_MS) == pdPASS)
        {
			vl_msgtype = vl_msg.v_msgtype;
			vl_para = vl_msg.v_para;
			vl_header_len = vl_msg.v_header_len;
			vl_msgbody_len = vl_msg.v_msgbody_len;
			pl_msgheader = vl_msg.p_msgheader;
			pl_msgbody = vl_msg.p_msgbody;
			vl_seq = vl_msg.v_seq;

			if (UART_SEND_MSG_PASSTHROUGH == vl_msgtype)
			{
				while (true == s_pkt_unq.v_wait_flag)
				{
					//同步等待
					vTaskDelay(10);
				}

				if (0 != vl_flag)
				{
					bl_ret = init_unique(pl_msgbody[12], vl_seq, vl_para, vl_flag);
					if (true == bl_ret)
					{
						//printf("U<--%02X\n", pl_msgbody[2]);
						uart_write(sp_uart_socket, pl_msgbody, vl_msgbody_len);
					}
				}
			}
			else if (UART_SEND_MSG_DIRECT == vl_msgtype)
			{
				printf("U<--W(%d)\n", vl_msgbody_len);
				uart_write(sp_uart_socket, pl_msgbody, vl_msgbody_len);
			}
            
            ////////////////////////////////////
			if (NULL != pl_msgheader)
			{
				free(pl_msgheader);
				pl_msgheader = NULL;
			}

			if (NULL != pl_msgbody)
			{
				free(pl_msgbody);
				pl_msgbody = NULL;
			}
			memset(&vl_msg, 0, sizeof(vl_msg));
			//vTaskDelay(160/portTICK_RATE_MS);
        }      
    }
Exit:
	vTaskDelete(NULL);
}

static void wapi_uart_recv_thread(void *param)
{
	vTaskDelay(1000);
    printf("uart recv thread run...\n");
    
	uart_set_str uartset;
	struct timeval tv;
	fd_set readfds;
    
	int read_len = 0, count = 0;
	int ret = 0;
	int uart_fd = sp_uart_socket->fd;
    
    if (uart_fd < 0)
    {
        printf("uart fd <0\n");
        goto Exit;
    }
    
	while(1)
	{
		FD_ZERO(&readfds);
		FD_SET(uart_fd, &readfds);
		tv.tv_sec = 10;
		tv.tv_usec = 0;
		ret = select(uart_fd + 1, &readfds, NULL, NULL, &tv);
		if(ret > 0)
		{
			if(FD_ISSET(uart_fd, &readfds))
			{
				read_len = uart_read(sp_uart_socket, sa_rx_buf, UART_RECV_BUFFER_LEN);
				if(read_len > 0)
				{
                    //WAPI_TRACE_HEX(sa_rx_buf, read_len);
                    sp_uart_recv_cb(sa_rx_buf, read_len, NULL);
					SC_SURREND_TASK();
				}
			}
			//else for other sockets
		}
	}
    
	//printf("Exit uart recv!\n");
	//uart_close(sp_uart_socket);
Exit:
	vTaskDelete(NULL);
}

void wapi_uart_comm_init(uart_recv_callback pp_func)
{   
#if 1
    uart_set_str uartset;
	
	uartset.BaudRate = 9600;
	uartset.number = 8;
	uartset.StopBits = 1;
	uartset.FlowControl = 0;
	uartset.parity = 0;
	strcpy(uartset.UartName, "uart1");

	sp_uart_socket = uart_open(&uartset);
	if(sp_uart_socket == NULL)
	{
		printf("Init uart socket failed!\n");
	} 

    sp_uart_recv_cb = pp_func;
   
#define BAPI_UART_SEND_THREAD_STACK_SIZE        512//1024
#define BAPI_UART_SEND_THREAD_PRIORITY		    (tskIDLE_PRIORITY + 2)     
    if(xTaskCreate(wapi_uart_send_thread, "uart_send", BAPI_UART_SEND_THREAD_STACK_SIZE, NULL, BAPI_UART_SEND_THREAD_PRIORITY, NULL) != pdPASS)
		printf("xTaskCreate failed");
    
    
#define BAPI_UART_RECV_THREAD_STACK_SIZE        512//1024
#define BAPI_UART_RECV_THREAD_PRIORITY		    (tskIDLE_PRIORITY + 2)    
    if(xTaskCreate(wapi_uart_recv_thread, "uart_recv", BAPI_UART_RECV_THREAD_STACK_SIZE, NULL, BAPI_UART_RECV_THREAD_PRIORITY, NULL) != pdPASS)
		printf("xTaskCreate failed");
#endif   
}


void xxxx_yyy()
{
	if(sp_uart_recv_cb == NULL)
	{
		printf("Init uart socket failed!\n");
	} 
}


