#ifndef __HISEN_MSG_H__
#define __HISEN_MSG_H__

enum E_HOST_ENTRY_MSG {
	HOST_ENTRY_MSG_TIMER = 0x01,
	HOST_ENTRY_MSG_CONNECT_ROUTER_STATA,
	HOST_ENTRY_MSG_GET_SN,
	HOST_ENTRY_MSG_GET_SN_RESULT,
	HOST_ENTRY_MSG_64_MODE_SWITCH,
	HOST_ENTRY_MSG_64_MODE_SWITCH_RESULT,
	HOST_ENTRY_MSG_NETSERV,
	HOST_ENTRY_MSG_SNIFFER,
	HOST_ENTRY_MSG_AP,
	HOST_ENTRY_MSG_STATION,
	HOST_ENTRY_MSG_DNS_GETIP,


	//---------------------------
	HOST_ENTRY_MSG_MAX
};


typedef struct tag_WAPI_MSG{  
    A_UINT8 v_msgtype;
    A_UINT8 v_header_len;
    A_UINT16 v_msgbody_len; 

    A_UINT32 v_para;
    A_UINT8* p_msgheader;
    A_UINT8* p_msgbody;  
	A_UINT32 v_seq;//��Ϣ�����к�
	A_UINT32 v_para2;
	A_UINT32 v_reserve1;
	A_UINT32 v_reserv2;
    
} t_WAPI_MSG;   //TX_8_ULONG

#define EMPTY_MSG_FLAG      0
#define EMPTY_MSG_LEN       0
#define EMPTY_MSG_RESERVE   0
#define EMPTY_MSG_PARA      0
#define EMPTY_MSG_PTR       NULL


#define MSG_COUNT           20//��Ϣ����
#define MSG_SIZE            sizeof(t_WAPI_MSG)//��Ϣ��С=sizeof(t_WAPI_MSG)



#endif//__HISEN_MSG_H__
