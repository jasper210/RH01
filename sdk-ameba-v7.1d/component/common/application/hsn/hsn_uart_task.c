/*
 * @Description: hisense_uart_task.c
 * @Author: xuetong
 * @Date: 2019-08-05 08:48:44
 * @LastEditTime: 2019-11-14 18:00:27
 * @LastEditors: Please set LastEditors
 */

#include "hsn_common.h"

#include "serial_ex_api.h"
#include "at_cmd/atcmd_wifi.h"

#ifdef HSN_UART_SELECT
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

#endif //HSN_UART_SELECT


extern int fac_finish_flag;
extern unsigned short module_status;
extern unsigned char wifi_uart_recv_status;
extern unsigned char router_cloud_connect_status;
extern unsigned char wifi_status;

unsigned char msg_data_1e[8];
gtimer_t cmd_07_timer;
gtimer_t check_ox1E_timer;


serial_t sobj;
unsigned char recv_char_temp = 0;
unsigned char uart_rx_Ok_Flag = 0;
unsigned char uart_status = UartNOP;
unsigned int  uart_recv_len = 0;
static unsigned char recv_buffer[RECV_MAX_LEN] = {0};
unsigned int sn_get_success = 0;
unsigned int ver_get_success = 0;

unsigned char uart_recv_ok_flag = 0;

unsigned char hsn_dev_addr_H = 0x00;
unsigned char hsn_dev_addr_L = 0x00;


unsigned short get_checksum(unsigned char *data, unsigned int len)
{
	int i;
	unsigned short temp_checksum = 0;
	for(i = 0; i < len; i++)
	{	
		temp_checksum += data[i];
	}
	return temp_checksum;
}
//F4 F5 01 40 13 01 00 FE 01 02 01 01 00 1E 00 01 90 00 00 02 15 00 00 00 02 1E F4 FB  //28
unsigned int uart_packet_build(unsigned char a, unsigned char b, unsigned char *msg_body, unsigned int msg_body_len, unsigned char *packet, int flag)
{
	t_WIFI_GLOBAL* pl_wg = MC_WIFI_GLOBAL_PTR();
	int i;
	unsigned char Result_CRC16_H;
	unsigned char Result_CRC16_L;
	unsigned int temp_crc16;
	//log_printf_d("[%s]\n",__FUNCTION__);
	packet[0] = SYNC_1;
	packet[1] = SYNC_2;
	packet[2] = 0x00;
	packet[3] = 0x40;
	packet[4] = msg_body_len + PACKET_LEN_ExCLUDE_SYNC;
	packet[5] = 0;
	packet[6] = 0;
	if(!flag)
	{
		packet[7] = pl_wg->v_dev_addr_H;
		packet[8] = pl_wg->v_dev_addr_L;
	}
	packet[9] = HSN_WIFI_ADDR_H;
	packet[10] = HSN_WIFI_ADDR_L;
	packet[11]= 0;
	packet[12]= 0;
	packet[13] = a;
	packet[14] = b;
	packet[15]= 0;
	if(msg_body != NULL)
	{
		memcpy(&packet[16], msg_body, msg_body_len);
	}
	temp_crc16 = get_checksum(&packet[2], PACKET_LEN_INCLUDE_SYNC + msg_body_len - 2);
	packet[PACKET_LEN_INCLUDE_SYNC + msg_body_len] = temp_crc16 >> 8;
	packet[PACKET_LEN_INCLUDE_SYNC + msg_body_len + 1] = temp_crc16;
	packet[PACKET_LEN_INCLUDE_SYNC + msg_body_len + 2] = SYNC_1;
	packet[PACKET_LEN_INCLUDE_SYNC + msg_body_len + 3] = SYNC_3;
	return PACKET_LEN_INCLUDE_SYNC_EX + msg_body_len + 2;
}

#ifdef HSN_UART_SELECT
extern int wapi_uart_send_direct(A_UINT8* pp_data, A_UINT8 vp_len, void* pp_ctx);
int uart_data_send(unsigned char *buff, unsigned int len)
{
	printf("U<-:0x%02X(%d_%d)\n", *(buff + BYTE_A_POS), *(buff + BYTE_A_POS), *(buff + BYTE_B_POS));
#if (HSN_DEBUG_UART==1)
	WAPI_DUMP_HEX(buff,len,"UART SEND:");
#endif
	wapi_uart_send_direct(buff, len, NULL);
}

#else

int uart_data_send(unsigned char *buff, unsigned int len)
{
	acquirewakelock();
	//log_printf_d("[%s]\n",__FUNCTION__);
	int i;

	printf("U<-:0x%02X(%d_%d)\n", *(buff + BYTE_A_POS), *(buff + BYTE_A_POS), *(buff + BYTE_B_POS));
	WAPI_DUMP_HEX(buff,len,"UART SEND:");

	for(i = 0; i < len; i++)
	{
		serial_putc(&sobj, *(buff + i));
	}
	return 1;
}



#endif




void cmd_0A_get_dev_addr_timer_handler()
{
	unsigned char tdata[PACKET_LEN_WITHOUT_MSGBODY] = {0};
	unsigned int tdata_len;
	memset(tdata, 0, PACKET_LEN_WITHOUT_MSGBODY);
	tdata_len = uart_packet_build(CMD_A_GET_DEV_ADDR, CMD_B_GET_DEV_ADDR, NULL, 0, tdata, 1);
	uart_data_send(tdata, tdata_len);
}


void cmd_check_ox1E_timer_handler(TimerHandle_t xTimer)//30
{
	unsigned char tdata[PACKET_LEN_WITH_MSGBODY] = {0};
	unsigned int tdata_len;
	unsigned char msg_body[8] = {0};
	msg_body_build_func(msg_body);
	memset(tdata, 0, PACKET_LEN_WITHOUT_MSGBODY);
	tdata_len = uart_packet_build(CMD_A_GET_WORKING_STATUS, CMD_B_GET_WORKING_STATUS, msg_body, 8, tdata, 0);
	uart_data_send(tdata, tdata_len);
}


#ifdef HSN_UART_SELECT
static xTimerHandle s_07cmd_timer; // the timer handle of created FreeRTOS soft-timer

void cmd_0A_timeout_handler(TimerHandle_t xTimer)
{
	if(uart_recv_ok_flag)
	{
		xTimerStop(s_07cmd_timer, 0);
		xTimerDelete(s_07cmd_timer, 0);
	}
	else
	{
		cmd_0A_get_dev_addr_timer_handler();
	}
}
#else
void cmd_0A_timeout_handler(unsigned int TimeOut)
{
	if(uart_recv_ok_flag)
	{
		gtimer_stop(&cmd_07_timer);
	}
	else
	{
		cmd_0A_get_dev_addr_timer_handler();
	}
}
#endif


#ifdef HSN_07CMD_TIMER
static xTimerHandle s_check_ox1E_timer; // the timer handle of created FreeRTOS soft-timer

void cmd_check_0x1E_timeout_handler(unsigned int TimeOut)
{
	cmd_check_0x1E_timer_handler();
}

void start_check_0x1E_func()
{
	s_check_ox1E_timer = xTimerCreate("check_ox1E_timer", 3000,
		pdFALSE, (void *)0, cmd_check_ox1E_timer_handler);
	xTimerStart(s_check_ox1E_timer, 0);
}

#else

void cmd_check_0x1E_timeout_handler(unsigned int TimeOut)
{
	cmd_check_0x1E_timer_handler();
}

void start_check_0x1E_func()
{
	gtimer_init(&check_ox1E_timer, TIMER3);
	gtimer_start_periodical(&check_ox1E_timer, 3000000, (void*)cmd_check_ox1E_timer_handler, NULL);
}



#endif


void byte_a_0x1e_handle(unsigned char *data)
{
	t_WIFI_GLOBAL* pl_wg = MC_WIFI_GLOBAL_PTR();
	
	memset(msg_data_1e, 0, 8);
	memcpy(msg_data_1e, data, 8);
	unsigned char temp_byte;
	
	unsigned char vl_wifi_config_flag = 0;
	unsigned char vl_wifi_config_mode = 0;
	unsigned char vl_dev_unbind = 0;
/*******************************************byte 0************************************/ 
	//ignore
	
/*******************************************byte 1************************************/	
	temp_byte = data[1];
	//printf("temp_byte:%02X\r\n", temp_byte);
	if((temp_byte >> 7)& 0x01)  //请求休眠
	{
		//to do
	}
	else
	{
		/* code */
	}

	if((temp_byte >> 6)& 0x01)  //LED灯控
	{
		//to do
	}
	else
	{
		/* code */
	}

	if((temp_byte >> 5)& 0x01)  //进行WiFi配置
	{
		printf("enter on config mode...\n");
		vl_wifi_config_flag = 1;
		pl_wg->v_wifi_config_on = 1;
		//hsn_config_mode();
		//enter_on_config_mode_handle();
		wapi_send_mq_host_entry(HOST_ENTRY_MSG_CONFIG_WIFI, NULL, 0, NULL);
		cmd_check_ox1E_timer_handler(NULL);
		
	}


	if((temp_byte >> 4)& 0x01) //配置模式选择
	{
		vl_wifi_config_mode = 1;
#if 0
		if (vl_wifi_config_flag == 1)
		{
			if(wifi_status != WIFI_CONNECTING)
			{
				printf("enter on smart link mode...\n");
				//enter_smart_link_config_mode_handle();
				wapi_send_mq_host_entry(HOST_ENTRY_MSG_SMART_CONFIG, NULL, 0, NULL);
			}
		}
#endif
	}


	if((temp_byte >> 3)& 0x01) 
	{
		//device_unbind_handle();
		vl_dev_unbind = 1;
		printf("device unbind0\n");
		wapi_send_mq_host_entry(HOST_ENTRY_MSG_UNBIND_DEV, NULL, 0, NULL);
	}

	

	if((temp_byte >> 2)& 0x01) //家电上电时间
	{
		//to do 
	}
	else
	{
		/* code */
	}

	if((temp_byte >> 1)& 0x01) //是否退出智能模式
	{
		//to do
	}
	else
	{
		/* code */
	}

	if((temp_byte >> 0)& 0x01)  //请求获取状态
	{
		mcu_status_check();
	}


/*******************************************byte 2************************************/	
	temp_byte = data[2];
	if((temp_byte >> 7)& 0x01)  //通知休眠
	{
		//to do
	}
	else
	{
		/* code */
	}

	if((temp_byte >> 6)& 0x01)  //请求自检和扫描
	{
		enter_self_check_scan_mode_handle();
	}
	else
	{
		/* code */
	}

	if((temp_byte >> 5)& 0x01)  //请求WiFi按照默认配置进行连接
	{
		enter_default_config_config_handle();
	}
	else
	{
		/* code */
	}


	if((temp_byte >> 4)& 0x01) //请求校准时间
	{
		if (HSN_LOGIN_STATE_HB == pl_wg->v_cloud_login_sta)
		{
			wapi_send_tcpsend_msg(CALIBRATE_TIME, NULL, 0, NULL);
		}
		
	}
	else
	{
		//to do
	}

	if((temp_byte >> 3)& 0x01) //请求上传1min/5min电量
	{
		//to do
	}

	if((temp_byte >> 2)& 0x01) //请求上传整点电量
	{
		//to do 
	}
	else
	{
		/* code */
	}


	if((temp_byte >> 1)& 0x01) //请求上传电量模块异常
	{
		//to do
	}
	else
	{
		/* code */
	}

	if((temp_byte >> 0)& 0x01)  //请求WiFi下发电量数据
	{
		//to do
	}	

/*******************************************byte 3************************************/	
/*******************************************byte 4************************************/	


	
/*******************************************byte 5************************************/	
	temp_byte = data[5];
	if((temp_byte >> 7)& 0x01)  //请求采用的连接方式
	{
		//to do
	}
	else
	{
		/* code */
	}


	if((temp_byte >> 5)& 0x01)  //请求下发路由信息
	{
		//to do
	}
	else
	{
		/* code */
	}



}

void uart_msg_parse(unsigned char *data, unsigned int data_len)
{
	t_WIFI_GLOBAL* pl_wg = MC_WIFI_GLOBAL_PTR();
	int post_rawdata_flag = 0;
	unsigned char byte_a;
	unsigned char byte_b;
	byte_a = data[BYTE_A_POS];
	byte_b = data[BYTE_B_POS];

	//WAPI_DUMP_HEX(data,data_len,"UART RECV:");
	printf("U->:0x%02X(%d_%d)\n", byte_a, byte_a, byte_b);
	
	
	switch (byte_a)
	{
		case 0x01:
			break;

		case 0x0A://10
			if(byte_b == 0x04)
			{
				uart_recv_ok_flag = 1;
				wifi_uart_recv_status = 1;
				//hsn_config_mode();
				//printf("0A0A\n");
				wapi_send_mq_host_entry(HOST_ENTRY_MSG_GET_DEV_ADDR_FINISH, data, data_len, NULL);
				//cmd_check_ox1E_timer_handler(NULL);
				//start_check_0x1E_func();
			}
			break;
		
		case 0x1E://30
			if (0 == byte_b)
			{
				byte_a_0x1e_handle(&data[BYTE_MSG_POS]);
			}
			else
			{
				printf("unkonw cmd:%d_%d\r\n", byte_a, byte_b);
			}
			break;

		case 0x65://101 下行控制
			post_rawdata_flag = 1;
			break;

		case 0x66://102 上报状态
			post_rawdata_flag = 1;
			break;

		default:
			printf("unknow byte_a:%d\n", byte_a);
			break;
	}

	if(post_rawdata_flag == 1)
	{
		if (HSN_LOGIN_STATE_HB == pl_wg->v_cloud_login_sta)
		{
			//printf("cloud connect\n");
			wapi_send_tcpsend_msg(DATA_FROM_UART, data, data_len, NULL);
		}
	}
}

#ifdef HSN_UART_SELECT
void uart_irq(uint32_t id, SerialIrq event)
{
}


extern int s_bt_test_scan_timeout;
extern int g_if_test_bt;

void sc_uart_unpack_for_factory(A_UINT8* pp_in_buf, A_UINT32 vp_len)
{
	int fac_flag = 0;

	A_UINT32 vl_len = vp_len;
	A_UINT8 vl_buf_cnt = 0;

	static unsigned char recv_char_temp_f = 0;
	static unsigned char uart_status_f = FAC_CHECK_1;
	
	
	while(0 != vl_len)
	{
		vl_len--;
		recv_char_temp_f = *(pp_in_buf + vl_buf_cnt);
		vl_buf_cnt++;

		switch(uart_status_f)
        {
        	case FAC_CHECK_1:
			{
				if(recv_char_temp_f == 'a')
				{
					uart_status_f = FAC_CHECK_2;
				}
				break;
			}
			case FAC_CHECK_2:
			{
				if(recv_char_temp_f == 'b')
				{
					uart_status_f = FAC_CHECK_3;
				}
				break;
			}
			case FAC_CHECK_3:
			{
				if(recv_char_temp_f == 'c')
				{
					uart_status_f = FAC_CHECK_4;
				}
				break;
			}
			case FAC_CHECK_4:
			{
				if(recv_char_temp_f == 'd')
				{
					uart_status_f = FAC_CHECK_5;
				}
				break;
			}
			case FAC_CHECK_5:
			{
				if(recv_char_temp_f == 'e')
				{
					uart_status_f = FAC_CHECK_6;
				}
				break;
			}
			case FAC_CHECK_6:
			{
				if(recv_char_temp_f == 'f')
				{
					uart_status_f = FAC_CHECK_7;
				}
				break;
			}
			case FAC_CHECK_7:
			{
				if(recv_char_temp_f == 'g')
				{
					s_bt_test_scan_timeout = 6;
					g_if_test_bt = 0;
					printf("goto fac check....");
					extern void wapi_get_dev_addr_timer_uninit();
					wapi_get_dev_addr_timer_uninit();
					if(0 == fac_finish_flag)
					{						
						if(0 == fac_flag)
						{
							rlk_fac_check_init();
						}
					}
					fac_flag = 1;
					uart_status_f = FAC_CHECK_1;
				}
				else if(recv_char_temp_f == 'h')
				{
					s_bt_test_scan_timeout = 11;
					g_if_test_bt = 1;
					printf("goto fac check....");
					extern void wapi_get_dev_addr_timer_uninit();
					wapi_get_dev_addr_timer_uninit();
					if(0 == fac_finish_flag)
					{						
						if(0 == fac_flag)
						{
							rlk_fac_check_init();
						}
					}
					fac_flag = 1;
					uart_status_f = FAC_CHECK_1;
				}
				else 
				{//switch env
					hsn_factory_switch_evn(recv_char_temp_f);
					uart_status_f = FAC_CHECK_1;
				}
				break;
			}
			default:
				break;
		}
		
	}
}



void sc_uart_unpack(A_UINT8* pp_in_buf, A_UINT32 vp_len, uart_pack_handle_callback pp_callback)
{
	int fac_flag = 0;
	unsigned int temp_crc16;
	int i = 0;
	int j = 0;
    static int msg_len = 0;
	static int temp_msg_len = 0;
	static int crc_len = 0;
	static unsigned char Result_CRC16_H;
	static unsigned char Result_CRC16_L;
	BaseType_t xHigherPriorityTaskWoken = pdFALSE;

	A_UINT32 vl_len = vp_len;
	A_UINT8 vl_temp = 0;
	A_UINT8 vl_buf_cnt = 0;
	
	while(0 != vl_len)
	{
		vl_len--;
		recv_char_temp = *(pp_in_buf + vl_buf_cnt);
		vl_buf_cnt++;

		switch(uart_status)
        {
			case UartNOP:
			{
				if(uart_rx_Ok_Flag == 1)
				{
					break;
				}else{
					uart_status = UartSOP_1;
				}
			}
			
			case UartSOP_1:
			{
				if(recv_char_temp == SYNC_1)
				{
					recv_buffer[uart_recv_len++] = recv_char_temp;
					uart_status = UartSOP_2;
				}
				else
				{
					uart_status = UartNOP;
					uart_recv_len = 0;
				}
				break;
			}

			case UartSOP_2:
			{
				if(recv_char_temp == SYNC_2)
				{
					recv_buffer[uart_recv_len++] = recv_char_temp;
					uart_status = DATA_FLAG;
				}
				else
				{
					uart_status = UartNOP;
					uart_recv_len = 0;
				}
				break;
			}

			case DATA_FLAG:
			{
				recv_buffer[uart_recv_len++] = recv_char_temp;
				uart_status = BYTE_40;
				break;
			}

            case BYTE_40:
            {
                recv_buffer[uart_recv_len++] = recv_char_temp;
                uart_status = UartLEN;
                break;
            }

            
            case UartLEN:
            {
                recv_buffer[uart_recv_len++] = recv_char_temp;
				msg_len = recv_char_temp;
                uart_status = BYTE_01_1;
                break;
            }

			case BYTE_01_1:
			{
				recv_buffer[uart_recv_len++] = recv_char_temp;
				uart_status = UartRESV_1;
				break;
			}

			case UartRESV_1:
			{
				recv_buffer[uart_recv_len++] = recv_char_temp;
				uart_status = BYTE_FE;
				break;
			}

            case BYTE_FE:
            {
                recv_buffer[uart_recv_len++] = recv_char_temp;
                uart_status = BYTE_01_2;
                break;
            }
            
            case BYTE_01_2:
            {
                recv_buffer[uart_recv_len++] = recv_char_temp;
                uart_status = BYTE_02;
                break;
            }

            case BYTE_02:
            {
                recv_buffer[uart_recv_len++] = recv_char_temp;
                uart_status = BYTE_01_3;
                break;
            }
            
			case BYTE_01_3:
			{
				recv_buffer[uart_recv_len++] = recv_char_temp;
				uart_status = BYTE_01_4;
				break;
			}

			case BYTE_01_4:
			{
				recv_buffer[uart_recv_len++] = recv_char_temp;
				uart_status = UartRESV_2;
				break;
			}

			case UartRESV_2:
			{
				recv_buffer[uart_recv_len++] = recv_char_temp;
				uart_status = BYTE_A;
				break;
			}

			case BYTE_A:
			{
				recv_buffer[uart_recv_len++] = recv_char_temp;
				uart_status = BYTE_B;
				break;
			}

			case BYTE_B:
			{
				recv_buffer[uart_recv_len++] = recv_char_temp;
				uart_status = BYTE_01_5;
				break;
			}

			case BYTE_01_5:
			{
				recv_buffer[uart_recv_len++] = recv_char_temp;
				uart_status = UartDATA;
				break;
			}

			case UartDATA:
			{
                if(msg_len > PACKET_LEN_ExCLUDE_SYNC)
                {
   	                recv_buffer[uart_recv_len++] = recv_char_temp;
                    msg_len--;
					if(msg_len == PACKET_LEN_ExCLUDE_SYNC)
					{
						uart_status = UartCRC;
					}
                    break;
                }
			}

			case UartCRC:
			{
				if(crc_len == 0)
				{
					recv_buffer[uart_recv_len++] = recv_char_temp;
					Result_CRC16_H = recv_char_temp;
					crc_len++;
					break;
				}
				else if(crc_len == 1)
				{
					recv_buffer[uart_recv_len++] = recv_char_temp;
					crc_len = 0;
					uart_status = SYNC_END_1;
					break;
#if 0
					Result_CRC16_L = recv_char_temp;
					printf("Result_CRC16_H: %02x, Result_CRC16_L:%02x\n", Result_CRC16_H, Result_CRC16_L);
					//temp_crc16 = get_checksum(&recv_buffer[2], 2 + PACKET_LEN_INCLUDE_SYNC - 2);
					temp_crc16 = get_checksum(&recv_buffer[2], recv_buffer[4] + 3);
					unsigned char p_crc1 = temp_crc16 >> 8;
					unsigned char p_crc2 = temp_crc16;
					if((Result_CRC16_H != p_crc1) || (Result_CRC16_L != p_crc2))
					{
						printf("1: %02x,2 : %02x\n", p_crc1, p_crc2);
						log_printf_d("CRC: error\n");
                		uart_rx_Ok_Flag = 0;
						uart_recv_len = 0;
						msg_len = 0;
						crc_len = 0;
						uart_status = UartNOP;
						break;
					}
		
					else
					{
						crc_len = 0;
						uart_status = SYNC_END_1;
						break;
					}
#endif
				}
			}

			case SYNC_END_1:
			{
				if(recv_char_temp == SYNC_1)
				{
					recv_buffer[uart_recv_len++] = recv_char_temp;
					uart_status = SYNC_END_2;
				}
				break;
			}

			case SYNC_END_2:
			{
				if(recv_char_temp == SYNC_3)
				{
					recv_buffer[uart_recv_len++] = recv_char_temp;
					//WAPI_DUMP_HEX(recv_buffer,uart_recv_len,"UART RECV1:");
					//uart_msg_parse(recv_buffer, uart_recv_len);//lxd123
					pp_callback(recv_buffer, uart_recv_len);
					uart_rx_Ok_Flag = 0;
					uart_recv_len = 0;
					msg_len = 0;
					uart_status = UartNOP;
					vl_buf_cnt = 0;
					releasewakelock();
					//uart_status = UartSOP_2;
				}
				break;
			}

		}
		
	}
}

#else

void uart_irq(uint32_t id, SerialIrq event)
{
	int fac_flag = 0;
    serial_t    *sobj = (void*)id;
	unsigned int temp_crc16;
	int i = 0;
	int j = 0;
    static int msg_len = 0;
	static int temp_msg_len = 0;
	static int crc_len = 0;
	static unsigned char Result_CRC16_H;
	static unsigned char Result_CRC16_L;
	BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    if(event == RxIrq)
	{
        recv_char_temp = serial_getc(sobj);
        switch(uart_status)
        {
			case UartNOP:
			{
				if(uart_rx_Ok_Flag == 1)
				{
					break;
				}else{
					uart_status = UartSOP_1;
				}
			}
			
			case UartSOP_1:
			{
				if(recv_char_temp == SYNC_1)
				{
					recv_buffer[uart_recv_len++] = recv_char_temp;
					uart_status = UartSOP_2;
				}
				else if(recv_char_temp == 'a')
				{
					uart_status = FAC_CHECK_2;
				}
				break;
			}

			case UartSOP_2:
			{
				if(recv_char_temp == SYNC_2)
				{
					recv_buffer[uart_recv_len++] = recv_char_temp;
					uart_status = DATA_FLAG;
				}
				break;
			}

			case DATA_FLAG:
			{
				recv_buffer[uart_recv_len++] = recv_char_temp;
				uart_status = BYTE_40;
				break;
			}

            case BYTE_40:
            {
                recv_buffer[uart_recv_len++] = recv_char_temp;
                uart_status = UartLEN;
                break;
            }

            
            case UartLEN:
            {
                recv_buffer[uart_recv_len++] = recv_char_temp;
				msg_len = recv_char_temp;
                uart_status = BYTE_01_1;
                break;
            }

			case BYTE_01_1:
			{
				recv_buffer[uart_recv_len++] = recv_char_temp;
				uart_status = UartRESV_1;
				break;
			}

			case UartRESV_1:
			{
				recv_buffer[uart_recv_len++] = recv_char_temp;
				uart_status = BYTE_FE;
				break;
			}

            case BYTE_FE:
            {
                recv_buffer[uart_recv_len++] = recv_char_temp;
                uart_status = BYTE_01_2;
                break;
            }
            
            case BYTE_01_2:
            {
                recv_buffer[uart_recv_len++] = recv_char_temp;
                uart_status = BYTE_02;
                break;
            }

            case BYTE_02:
            {
                recv_buffer[uart_recv_len++] = recv_char_temp;
                uart_status = BYTE_01_3;
                break;
            }
            
			case BYTE_01_3:
			{
				recv_buffer[uart_recv_len++] = recv_char_temp;
				uart_status = BYTE_01_4;
				break;
			}

			case BYTE_01_4:
			{
				recv_buffer[uart_recv_len++] = recv_char_temp;
				uart_status = UartRESV_2;
				break;
			}

			case UartRESV_2:
			{
				recv_buffer[uart_recv_len++] = recv_char_temp;
				uart_status = BYTE_A;
				break;
			}

			case BYTE_A:
			{
				recv_buffer[uart_recv_len++] = recv_char_temp;
				uart_status = BYTE_B;
				break;
			}

			case BYTE_B:
			{
				recv_buffer[uart_recv_len++] = recv_char_temp;
				uart_status = BYTE_01_5;
				break;
			}

			case BYTE_01_5:
			{
				recv_buffer[uart_recv_len++] = recv_char_temp;
				uart_status = UartDATA;
				break;
			}

			case UartDATA:
			{
                if(msg_len > PACKET_LEN_ExCLUDE_SYNC)
                {
   	                recv_buffer[uart_recv_len++] = recv_char_temp;
                    msg_len--;
					if(msg_len == PACKET_LEN_ExCLUDE_SYNC)
					{
						uart_status = UartCRC;
					}
                    break;
                }
			}

			case UartCRC:
			{
				if(crc_len == 0)
				{
					recv_buffer[uart_recv_len++] = recv_char_temp;
					Result_CRC16_H = recv_char_temp;
					//printf("Result_CRC16_H: %02X, %d\n", Result_CRC16_H, crc_len);
					crc_len++;
				}
				else if(crc_len == 1)
				{
					//printf("uart_status1: %d, %d, %02X\n", uart_status, uart_recv_len, recv_char_temp);
					recv_buffer[uart_recv_len++] = recv_char_temp;
					crc_len = 0;
					uart_status = SYNC_END_1;
					
					//break;
#if 0
					Result_CRC16_L = recv_char_temp;
					printf("Result_CRC16_L: %02X, %d\n", Result_CRC16_L, crc_len);

					printf("uart_status2: %d, %d\n", uart_status, uart_recv_len);
					printf("Result_CRC16_L: %02X\n", Result_CRC16_L);

					printf("Result_CRC16_H: %02x, Result_CRC16_L:%02x\n", Result_CRC16_H, Result_CRC16_L);
					temp_crc16 = get_checksum(&recv_buffer[2], 2 + PACKET_LEN_INCLUDE_SYNC - 2);
					//temp_crc16 = get_checksum(&recv_buffer[2], recv_buffer[4] + 3);
					unsigned char p_crc1 = temp_crc16 >> 8;
					unsigned char p_crc2 = temp_crc16;
					printf("CRC: %02x,2 : %02x\n", p_crc1, p_crc2);
					if((Result_CRC16_H != p_crc1) || (Result_CRC16_L != p_crc2))
					{
						printf("1: %02x,2 : %02x\n", p_crc1, p_crc2);
						log_printf_d("CRC: error\n");
                		uart_rx_Ok_Flag = 0;
						uart_recv_len = 0;
						msg_len = 0;
						crc_len = 0;
						uart_status = UartNOP;
					}
		
					else
					{
						crc_len = 0;
						uart_status = SYNC_END_1;
						
					}
#endif
				}
				break;
			}

			case SYNC_END_1:
			{
				if(recv_char_temp == SYNC_1)
				{
					recv_buffer[uart_recv_len++] = recv_char_temp;
					uart_status = SYNC_END_2;
				}
				break;
			}

			case SYNC_END_2:
			{
				if(recv_char_temp == SYNC_3)
				{
					recv_buffer[uart_recv_len++] = recv_char_temp;
					WAPI_DUMP_HEX(recv_buffer,uart_recv_len,"UART RECV:");
					uart_msg_parse(recv_buffer, uart_recv_len);//lxd123
					uart_rx_Ok_Flag = 0;
					uart_recv_len = 0;
					msg_len = 0;
					uart_status = UartNOP;
					releasewakelock();
					//uart_status = UartSOP_2;
				}
				break;
			}

			case FAC_CHECK_2:
			{
				if(recv_char_temp == 'b')
				{
					uart_status = FAC_CHECK_3;
				}
				break;
			}
			case FAC_CHECK_3:
			{
				if(recv_char_temp == 'c')
				{
					uart_status = FAC_CHECK_4;
				}
				break;
			}
			case FAC_CHECK_4:
			{
				if(recv_char_temp == 'd')
				{
					uart_status = FAC_CHECK_5;
				}
				break;
			}
			case FAC_CHECK_5:
			{
				if(recv_char_temp == 'e')
				{
					uart_status = FAC_CHECK_6;
				}
				break;
			}
			case FAC_CHECK_6:
			{
				if(recv_char_temp == 'f')
				{
					uart_status = FAC_CHECK_7;
				}
				break;
			}
			case FAC_CHECK_7:
			{
				if(recv_char_temp == 'g')
				{
					//uart_status = FAC_CHECK_8;
					printf("goto fac check....");
					gtimer_stop(&cmd_07_timer);
					if(!fac_finish_flag)
					{
						if(!fac_flag)
						{
						rlk_fac_check_init();
						}
					}

					fac_flag = 1;
					uart_rx_Ok_Flag = 0;
					uart_recv_len = 0;
					msg_len = 0;
					uart_status = UartNOP;
					releasewakelock();
				}
				break;
			}
		}
    }
}
#endif

extern uint32_t sleep_type;

static u32 uart0_suspend(u32 expected_idle_time )
{
	//printf("uart_suspend \n");
	return TRUE;
}

static u32 uart0_resume(u32 expected_idle_time)
{	
	//printf("uart_resume \n");
	//NVIC_SetPriority(UART0_IRQ, 10);
	//NVIC_EnableIRQ(UART0_IRQ);
	//return TRUE;
}

void releasewakelock(void)
{
	//pmu_release_wakelock(BIT(PMU_DEV_USER_BASE));
}

void acquirewakelock(void)
{
	//pmu_acquire_wakelock(BIT(PMU_DEV_USER_BASE));
}

void GpioUartRXIrqCallback (uint32_t id, gpio_irq_event event)
{
	//acquirewakelock();
}

void sysreleasewakelock(void)
{
	// By default tickless is disabled because PMU_OS is locked.
	// Release this wakelock to enable tickless
	//pmu_release_wakelock(BIT(PMU_OS));
}

void wake_lock_start()
{
		//if (sleep_type == SLEEP_CG)
	//pmu_register_sleep_callback(PMU_UART0_DEVICE, (PSM_HOOK_FUN)uart0_suspend, (void*)NULL, (PSM_HOOK_FUN)uart0_resume, (void*)NULL);
	//pmu_sysactive_timer_init();
	//pmu_set_sysactive_time(1000);
	//releasewakelock();
}

void gpio_uart_rx_irq_callback(uint32_t id, gpio_irq_event event)
{
	//pmu_acquire_wakelock(BIT(PMU_USER_DEVICE));
}

#ifdef HSN_PLATFORM_8720CF

void rlk_uart_task(void *para)
{
	printf("[%s]\n",__FUNCTION__);
	
    //init uart
	serial_init(&sobj,UART_TX,UART_RX);
	serial_baud(&sobj,9600);
	serial_format(&sobj, 8, ParityNone, 1);
	//serial_rx_fifo_level(&sobj, FifoLvHalf);

	//#define rxflow	UART_RTS
	//#define txflow	UART_CTS
	//serial_set_flow_control(&sobj, FlowControlNone, rxflow, txflow);
	
	serial_irq_handler(&sobj, uart_irq, (uint32_t)&sobj);
	serial_irq_set(&sobj, RxIrq, 1);
	serial_irq_set(&sobj, TxIrq, 1);

	gtimer_init(&cmd_07_timer, TIMER2);
	gtimer_start_periodical(&cmd_07_timer, 1000000, (void*)cmd_0A_timeout_handler, NULL);

	//wake_lock_start();

/* 	gpio_irq_t gpio_rx_wake;
	gpio_irq_init(&gpio_rx_wake, UART_RX, gpio_uart_rx_irq_callback, NULL);
	gpio_irq_set(&gpio_rx_wake, IRQ_FALL, 1);   // Falling Edge Trigger
	gpio_irq_enable(&gpio_rx_wake); */

	// By default tickless is disabled because PMU_OS is locked.
	// Release this wakelock to enable tickless
	//pmu_release_wakelock(BIT(PMU_OS));

	// Register pre/post sleep callback. They are called when system automatically enter/leave sleep.
	//pmu_register_sleep_callback(BIT(PMU_USER_DEVICE), pre_sleep_process_callback, NULL, post_sleep_process_callback, NULL);

	while(1)
	{
		vTaskDelay(1000);
	}
}


#else
void rlk_uart_task(void *para)
{
	printf("[%s]\n",__FUNCTION__);
    //init uart
	serial_init(&sobj,UART_TX,UART_RX);
	serial_baud(&sobj,9600);
	serial_format(&sobj, 8, ParityNone, 1);
	
	serial_irq_handler(&sobj, uart_irq, (uint32_t)&sobj);
	serial_irq_set(&sobj, RxIrq, 1);
	//serial_irq_set(&sobj, TxIrq, 1);

	gtimer_init(&cmd_07_timer, TIMER2);
	gtimer_start_periodical(&cmd_07_timer, 1000000, (void*)cmd_0A_timeout_handler, NULL);

	//wake_lock_start();

/* 	gpio_irq_t gpio_rx_wake;
	gpio_irq_init(&gpio_rx_wake, UART_RX, gpio_uart_rx_irq_callback, NULL);
	gpio_irq_set(&gpio_rx_wake, IRQ_FALL, 1);   // Falling Edge Trigger
	gpio_irq_enable(&gpio_rx_wake); */

	// By default tickless is disabled because PMU_OS is locked.
	// Release this wakelock to enable tickless
	//pmu_release_wakelock(BIT(PMU_OS));

	// Register pre/post sleep callback. They are called when system automatically enter/leave sleep.
	//pmu_register_sleep_callback(BIT(PMU_USER_DEVICE), pre_sleep_process_callback, NULL, post_sleep_process_callback, NULL);

	while(1)
	{
		vTaskDelay(1000);
	}
}


#endif

int rlk_uart_task_init()
{
	xTaskHandle app_task_handle = NULL;
	
	if(xTaskCreate((TaskFunction_t)rlk_uart_task, (char const *)"rlk_uart_task", 2*1024, NULL, tskIDLE_PRIORITY + HSN_TSK_PRIORITY, &app_task_handle) != pdPASS) {
		printf("xTaskCreate failed\n");	
	}
	printf("start rlk uart task handle\n");
	return 0;
}








/////////////////////////////////////


#ifdef HSN_UART_SELECT




static uart_socket_t *sp_uart_socket = NULL;
static uart_recv_callback sp_uart_recv_cb = NULL;
static A_UINT8 sa_rx_buf[UART_RECV_BUFFER_LEN];
static xQueueHandle s_handle_mq_uart_send;

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
        //if (pdTRUE == xQueueSendToBackFromISR(s_handle_mq_uart_send, (void* )&vl_msg, 0))
		if (pdTRUE == xQueueSendToBack(s_handle_mq_uart_send, (void* )&vl_msg, 0))
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



#if 1
int init_unique(A_UINT8 vp_msg_type, A_UINT32 vp_seq, A_UINT32 vp_who, A_UINT32 vp_flag)
{
	int bl_ret = false;
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

int check_unique(A_UINT8 vp_msgtype, A_UINT32* pp_seq, A_UINT32* pp_who, A_UINT32* pp_flag)
{
	int bl_ret = false;
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

#endif


static void wapi_uart_send_thread(void *param)
{
	vTaskDelay(500);
    printf("uart send thread run...\n"); 
    t_WAPI_MSG vl_msg;
	int ret;
    memset(&vl_msg, 0, sizeof(vl_msg));
	A_UINT8	 vl_msgtype;
	A_UINT16 vl_msgbody_len = 0;
	A_UINT8* pl_msgbody = NULL;
	//A_UINT32 vl_seq = 0;

	int bl_ret = false;
	A_UINT32 vl_flag = 0;
    
    int uart_fd = sp_uart_socket->fd;
    
    if (uart_fd < 0)
    {
        printf("uart fd <0\n");
        goto Exit;
    }
    
    s_handle_mq_uart_send = xQueueCreate(MSG_COUNT , MSG_SIZE);

	//vTaskDelay(100);
	//vTaskDelay(100);
	//vTaskDelay(100);
	//vTaskDelay(100);
	//gtimer_init(&cmd_07_timer, TIMER2);
	//gtimer_start_periodical(&cmd_07_timer, 1000000, (void*)cmd_0A_timeout_handler, NULL);
#if 0
	s_07cmd_timer = xTimerCreate("07_cmd_timer", 1000, 
			pdTRUE, (void *)0, cmd_0A_timeout_handler);
	xTimerStart(s_07cmd_timer, 0);
#endif   
    
    while(1)
    {
        //ret = xQueueReceiveFromISR(s_handle_mq_uart_send, &vl_msg, NULL);
		ret = xQueueReceive(s_handle_mq_uart_send, &vl_msg, 10000);
		if (pdPASS == ret)
        {
			vl_msgtype = vl_msg.v_msgtype;
			vl_msgbody_len = vl_msg.v_msgbody_len;
			pl_msgbody = vl_msg.p_msgbody;
			//vl_seq = vl_msg.v_seq;

			if (UART_SEND_MSG_PASSTHROUGH == vl_msgtype)
			{
				while (true == s_pkt_unq.v_wait_flag)
				{
					//同步等待
					vTaskDelay(10);
				}

				if (0 != vl_flag)
				{
					//bl_ret = init_unique(pl_msgbody[12], vl_seq, 0, vl_flag);
					if (true == bl_ret)
					{
						uart_write(sp_uart_socket, pl_msgbody, vl_msgbody_len);
					}
				}
			}
			else if (UART_SEND_MSG_DIRECT == vl_msgtype)
			{
				//WAPI_DUMP_HEX(pl_msgbody,vl_msgbody_len,"UART SEND:");
				uart_write(sp_uart_socket, pl_msgbody, vl_msgbody_len);
			}
            
            ////////////////////////////////////

			if (NULL != pl_msgbody)
			{
				free(pl_msgbody);
				pl_msgbody = NULL;
			}
			memset(&vl_msg, 0, sizeof(vl_msg));
			vTaskDelay(150/portTICK_RATE_MS);
        }  
		SC_SURREND_TASK();
		//LOGW("queue timeout\n");
    }
Exit:
	vTaskDelete(NULL);
}

static void wapi_uart_recv_thread(void *param)
{
	vTaskDelay(500);
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
#if (HSN_DEBUG_UART==1)
                    WAPI_DUMP_HEX(sa_rx_buf,read_len,"UART RECV:");
#endif
                    sp_uart_recv_cb(sa_rx_buf, read_len, NULL);
					SC_SURREND_TASK();
				}
			}
			//else for other sockets
		}
		SC_SURREND_TASK();
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
#define BAPI_UART_SEND_THREAD_PRIORITY		    (tskIDLE_PRIORITY + HSN_TSK_PRIORITY)     
    if(xTaskCreate(wapi_uart_send_thread, "uart_send", BAPI_UART_SEND_THREAD_STACK_SIZE, NULL, BAPI_UART_SEND_THREAD_PRIORITY, NULL) != pdPASS)
		printf("xTaskCreate failed");
    
    
#define BAPI_UART_RECV_THREAD_STACK_SIZE        512//1024
#define BAPI_UART_RECV_THREAD_PRIORITY		    (tskIDLE_PRIORITY + HSN_TSK_PRIORITY)    
    if(xTaskCreate(wapi_uart_recv_thread, "uart_recv", BAPI_UART_RECV_THREAD_STACK_SIZE, NULL, BAPI_UART_RECV_THREAD_PRIORITY, NULL) != pdPASS)
		printf("xTaskCreate failed");
#endif   
}


int bapi_uart_pack_handle_callback(A_UINT8 *pp_msg, A_UINT32 vp_msg_len)
{
	//WAPI_DUMP_HEX(pp_msg, vp_msg_len, "uart_recv2:");
	uart_msg_parse(pp_msg, vp_msg_len);
	
}


void wapi_uart_recv_cb(A_UINT8* pp_data, int vp_len, void* pp_ctx)
{
	//WAPI_DUMP_HEX(pp_data, vp_len, "uart_recv1:");
	sc_uart_unpack(pp_data, vp_len, bapi_uart_pack_handle_callback);
	sc_uart_unpack_for_factory(pp_data, vp_len);
}

void hsn_entry_uart()
{
	wapi_uart_comm_init(wapi_uart_recv_cb);
}


#endif







