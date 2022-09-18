#ifndef __HISEN_UART_H__
#define __HISEN_UART_H__



enum E_UART_SEND_MSG {
	UART_SEND_MSG_PASSTHROUGH = 0x01,
	UART_SEND_MSG_DIRECT,

	//---------------------------
	UART_SEND_MSG_MAX
};




typedef void(*uart_recv_callback)(A_UINT8* pp_data, int vp_len, void* pp_ctx);

void wapi_uart_comm_init(uart_recv_callback pp_func);
int wapi_uart_send_direct(A_UINT8* pp_data, A_UINT8 vp_len, void* pp_ctx);


#define WAPI_CHIGO_MSG_TYPE_CTRL	0x02
#define WAPI_CHIGO_MSG_TYPE_INQUIRE	0x03
#define WAPI_CHIGO_MSG_TYPE_REPORT	0x04
bool init_unique(A_UINT8 vp_msg_type, A_UINT32 vp_seq, A_UINT32 vp_who, A_UINT32 vp_flag);
bool check_unique(A_UINT8 vp_msgtype, A_UINT32* pp_seq, A_UINT32* pp_who, A_UINT32* pp_flag);

void xxxx_yyy();



#endif//__HISEN_UART_H__
