/*
 * @Description: rlt_queue_func.h
 * @Author: xuetong
 * @Date: 2019-08-05 08:48:44
 * @LastEditTime: 2019-10-21 17:38:48
 * @LastEditors: Please set LastEditors
 */

#ifndef _RLT_QUEUE_FUNC_H
#define _RLT_QUEUE_FUNC_H

typedef struct que_msg{
	unsigned char *data;
	unsigned int data_len;
	unsigned int msg_flag;
	void* vp_callback;
}t_queue_msg;


typedef enum{
	ON_CONFIG_STATUS = 0,
	SMART_CONFIG_MODE = 1,
	SOFTAP_CONFIG_MODE = 2,
	CONNECT_ROUTER = 3,
	CONNECT_ROUTER_DEFALT = 4,
	CONNECT_CLOUD = 5,
	STATUS_CHECK = 6,
	SELF_CHECK_MODE = 7,
	CONNECT_WITH_DEFAULT_CONFIG = 8,
	HSN_CONFIG_MODE,
	HSN_BLE_CONFIG_START,
	HSN_BLE_CONFIG_STOP,
	NET_RECONNECT_ROUTER,
	CONNECT_ROUTER_BY_SSID,
	HSN_NET_CONFIG,

	////////////////
	HSN_CONFIG_MODE_MAX
}t_config_mode;


enum{
	SET_TCP_SOCKET = 0,
	DATA_FROM_UART,
	DATA_FROM_NET,
	DEVICE_LOGOUT,
	CLOUD_RECONNECT,
	ROUTER_RECONNECT,
	LAN_LOGOUT,
	CALIBRATE_TIME,
};

int rlt_msg_queue_create(xQueueHandle *mp_que,int msg_num);
int rlt_msg_queue_send(xQueueHandle que,int msg_flag,unsigned char *data,unsigned int data_len, void* pp_callback);
void rlt_queue_free_msg(t_queue_msg ptr);


#ifdef HSN_UART_SELECT

typedef struct tag_WAPI_MSG{  
    A_UINT8 v_msgtype;
    A_UINT8 v_header_len;
    A_UINT16 v_msgbody_len; 
 
    A_UINT8* p_msgheader;
    A_UINT8* p_msgbody;  
	void* vp_callback;
	    
} t_WAPI_MSG;   //TX_8_ULONG

#define MSG_COUNT           30//消息数量
#define MSG_SIZE            sizeof(t_WAPI_MSG)//消息大小=sizeof(t_WAPI_MSG)



#endif

#endif
