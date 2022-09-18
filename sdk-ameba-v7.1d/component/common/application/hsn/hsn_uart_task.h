/*
 * @Description: hisense_uart_task.h
 * @Author: xuetong
 * @Date: 2019-08-08 17:18:00
 * @LastEditTime: 2019-10-25 17:02:58
 * @LastEditors: Please set LastEditors
 */

#ifndef _HISENSE_UART_TASK_H
#define _HISENSE_UART_TASK_H


#define UartNOP  	(0)   
#define UartSOP_1  	(1)   //0xF4
#define UartSOP_2  	(2)   //0xF5
#define DATA_FLAG	(3)   //0x01
#define BYTE_40     (4)   //0x40
#define UartLEN  	(5)   //packet length
#define BYTE_01_1	(6)	  //0x01
#define UartRESV_1	(7)
#define BYTE_FE     (8)   //0xFE 	HSN_WIFI_ADDR_H
#define BYTE_01_2	(9)	  //0x01		HSN_WIFI_ADDR_L
#define BYTE_02		(10)  //0x02		addr_H
#define BYTE_01_3	(11)  //0x01		addr_l
#define BYTE_01_4	(12)  //0x01
#define UartRESV_2	(13)  //0x00
#define BYTE_A	    (14)	  
#define BYTE_B	    (15)
#define BYTE_01_5	(16)  //0x01
#define UartDATA 	(17)      
#define UartCRC  	(18)  
#define SYNC_END_1  (19)  //0xf4
#define SYNC_END_2  (20)  //0xfb

#define FAC_CHECK_1 	21
#define FAC_CHECK_2  	22
#define FAC_CHECK_3  	23
#define FAC_CHECK_4  	24
#define FAC_CHECK_5  	25
#define FAC_CHECK_6  	26
#define FAC_CHECK_7  	27
#define FAC_CHECK_8  	28


int rlk_uart_task_init();
unsigned int uart_packet_build(unsigned char a, unsigned char b, unsigned char *msg_body, unsigned int msg_body_len, unsigned char *packet, int flag);
int uart_data_send(unsigned char *buff, unsigned int len);
void releasewakelock(void);
void acquirewakelock(void);
void sysreleasewakelock(void);
void wake_lock_start();
void rlk_uart_task(void *para);

#ifdef HSN_UART_SELECT
enum E_UART_SEND_MSG {
	UART_SEND_MSG_PASSTHROUGH = 0x01,
	UART_SEND_MSG_DIRECT,

	//---------------------------
	UART_SEND_MSG_MAX
};




typedef void(*uart_recv_callback)(A_UINT8* pp_data, int vp_len, void* pp_ctx);
typedef int(*uart_pack_handle_callback)(A_UINT8 *pp_msg, A_UINT32 vp_msg_len);


void wapi_uart_comm_init(uart_recv_callback pp_func);
int wapi_uart_send_direct(A_UINT8* pp_data, A_UINT8 vp_len, void* pp_ctx);


#define WAPI_CHIGO_MSG_TYPE_CTRL	0x02
#define WAPI_CHIGO_MSG_TYPE_INQUIRE	0x03
#define WAPI_CHIGO_MSG_TYPE_REPORT	0x04
int init_unique(A_UINT8 vp_msg_type, A_UINT32 vp_seq, A_UINT32 vp_who, A_UINT32 vp_flag);
int check_unique(A_UINT8 vp_msgtype, A_UINT32* pp_seq, A_UINT32* pp_who, A_UINT32* pp_flag);
void hsn_entry_uart();


#endif

#endif
