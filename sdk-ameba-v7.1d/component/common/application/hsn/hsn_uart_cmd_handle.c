/*
 * @Description: hisense_uart_cmd_handle.c
 * @Author: your name
 * @Date: 2019-08-05 08:48:44
 * @LastEditTime: 2019-10-29 16:47:44
 * @LastEditors: Please set LastEditors
 */
#include "hsn_common.h"


//byte1
unsigned char wifi_turn_on_status           = 0;
unsigned char wifi_uart_recv_status         = 0;
unsigned char wifi_router_connect_status    = WIFI_NET_STABLE;    //0:与路由器和网络连接正常 1：不能与路由器连接 2：不能与云端连接 3：网络不稳定 
unsigned char wifi_led_status               = 0;
unsigned char wifi_direct_connect_status    = 0;
unsigned char wifi_register_status          = 0;
unsigned char wifi_exit_control_status      = 0;

//byte2
unsigned char ask_mcu_for_wifi_led          = 1;
unsigned char wifi_bind_status              = 0;
unsigned char wifi_self_check_status        = 0;
unsigned char wifi_fault_status             = 0;
unsigned char wifi_config_mode              = 0;
unsigned char dev_powersave_mode			= 0;
unsigned char wifi_connect_status           = 0;         //长连接、短连接
unsigned char wifi_smart_config_mode        = 1;         //udp广播还是组播


//byte3
unsigned char wifi_status                   = WAITTING_NORMAL_CONNECT;
unsigned char router_cloud_connect_status   = ROUTER_DISCONNECT;
unsigned char electricity_metering_function = 0;

//byte6
unsigned char authorized_to_run 			= 0;
unsigned char wifi_powersave_mode 			= 0;
unsigned char authorized_status 			= 0;
unsigned char bluetooth_fault_statue 		= 0;
unsigned char bluetooth_state				= 0;








extern unsigned int sn_get_success;
extern unsigned int ver_get_success;
extern unsigned char wifi_status;
unsigned char cloud_status =0;

extern struct netif xnetif[NET_IF_NUM]; 




unsigned char get_wifi_connect_status()
{
	return wifi_status;
}

void set_wifi_connect_status(unsigned char flag)
{
	wifi_status = flag;
}

unsigned char get_cloud_connect_status()
{
	return cloud_status;
}

void set_cloud_connect_status(unsigned char flag)
{
	cloud_status = flag;
}




void bluetooth_config_byte_statue_set(int value)
{
	bluetooth_state = value;
}

// 指定的某一位数置1
#define SetBit(x, y)   ((x) |= (1<<(y)))
//指定的某一位数置0
#define ClearBit(x, y) ((x) &= ~(1<<(y)))
//指定的某一位数取反
#define ReverseBit(x,y) ((x)^=(1<<(y)))
//获取的某一位的值
#define GetBit(x, y)   (((x)>>(y)) & 1)


void hsn_state_transition()
{
	t_WIFI_GLOBAL* pl_wg = MC_WIFI_GLOBAL_PTR();
	t_CONFIG_TABLE_BODY* pl_cfg = MC_WG_CONFIG_TABLE_PTR();

	wifi_router_connect_status = WIFI_NET_STABLE;// BYTE1, bit5~bit4
	wifi_config_mode = 0;// BYTE2, bit3
	wifi_status = WAITTING_FAST_CONNECT;// BYTE3, bit7~bit5
	router_cloud_connect_status = ROUTER_DISCONNECT;// BYTE3, bit4~bit1

	//wifi idle
	if (WIFI_MODE_IDLE == pl_cfg->v_cur_mode)
	{
		
	}
	//wifi sta
	else if (WIFI_MODE_STA == pl_cfg->v_cur_mode)
	{
		if (HSN_ROUTER_STATE_DISCONNET == pl_wg->v_router_sta)
		{
			wifi_router_connect_status = CANNOT_CONNECT_ROUTER;
		}
		else if (HSN_ROUTER_STATE_CONNECTED == pl_wg->v_router_sta)
		{
			wifi_router_connect_status = CAN_CONNECT_ROUTER_NO_NET;
			router_cloud_connect_status = ROUTER_CONNECT_CLOUD_DISCONNECT;
			if (HSN_LOGIN_STATE_DISCONNET == pl_wg->v_cloud_login_sta)
			{
				
			}
			else if (HSN_LOGIN_STATE_HB == pl_wg->v_cloud_login_sta)
			{
				wifi_router_connect_status = ROUTER_NET_CONNECT;
				router_cloud_connect_status = ROUTER_CONNECT_CLOUD_CONNECT;
			}
			else if (HSN_LOGIN_STATE_START_REGISTER == pl_wg->v_cloud_login_sta)
			{
				
			}
			else if (HSN_LOGIN_STATE_REGISTER == pl_wg->v_cloud_login_sta)
			{
				
			}
			else if (HSN_LOGIN_STATE_DYNAMIC_KEY == pl_wg->v_cloud_login_sta)
			{
				
			}
			else if (HSN_LOGIN_STATE_SYSTEM_PARAM == pl_wg->v_cloud_login_sta)
			{
				
			}
		}
		else if (HSN_ROUTER_STATE_CONNECTING == pl_wg->v_router_sta)
		{
			wifi_router_connect_status = CANNOT_CONNECT_ROUTER;
		}
	}
	//wifi ap
	else if (WIFI_MODE_NETCONFIG == pl_cfg->v_cur_mode)
	{
		if (1 == pl_wg->v_wifi_config_on)
		{
			wifi_config_mode = 1;
		}
		
		if (HSN_AP_STATE_IDLE == pl_wg->v_ap_sta)
		{
			
		}
		else if (HSN_AP_STATE_STARTED == pl_wg->v_ap_sta)
		{
			wifi_status = WAITTING_NORMAL_CONNECT;
		}
		else if (HSN_AP_STATE_START == pl_wg->v_ap_sta)
		{
			
		}
	}
	//wifi sniffer
	else if (WIFI_MODE_SNIFFER == pl_cfg->v_cur_mode)
	{
		wifi_config_mode = 1;
		if (HSN_SNIFFER_STATE_IDLE == pl_wg->v_sniffer_sta)
		{
			
		}
		else if (HSN_SNIFFER_STATE_STARTED == pl_wg->v_sniffer_sta)
		{
			wifi_status = WAITTING_FAST_CONNECT;
		}
		else if (HSN_SNIFFER_STATE_START == pl_wg->v_sniffer_sta)
		{
			
		}
	}

	//bt on
	if (BT_MODE_ON == pl_cfg->v_bt_mode)
	{

	}
	//bt off
	else if (BT_MODE_IDLE == pl_cfg->v_bt_mode)
	{

	}
	
}


void msg_body_build_func(unsigned char *msgbody)
{
	hsn_state_transition();
/*********************************byte 1********************/	
	//BIT7 1
	SetBit(msgbody[0], 7);

	//BIT6 0
	ClearBit(msgbody[0], 6);

	//BIT5~BIT4 0/1
	if(wifi_router_connect_status == 0)
	{
		msgbody[0]  |= 0x00;
	}
	else if(wifi_router_connect_status == 1)
	{
		msgbody[0]  |= 0x10;
	}
	else if(wifi_router_connect_status == 2)
	{
		msgbody[0]  |= 0x20;
	}
	else if(wifi_router_connect_status == 3)
	{
		msgbody[0]  |= 0x30;
	}

	//BIT3 0
	if(wifi_led_status)
	{
		SetBit(msgbody[0], 3);
	}
	//BIT2 0
	if(wifi_direct_connect_status)
	{
		SetBit(msgbody[0], 2);
	}
	//BIT1 0
	if(wifi_register_status)
	{
		SetBit(msgbody[0], 1);
	}
	//BIT0 0
	if(wifi_exit_control_status)
	{
		SetBit(msgbody[0], 0);
	}
/*********************************byte 2********************/	
	//BIT7 1
	if(ask_mcu_for_wifi_led)
	{
		SetBit(msgbody[1], 7);
	}
	//BIT6 0
	if(wifi_bind_status)
	{
		SetBit(msgbody[1], 6);
	}
	//BIT5 0
	if(wifi_self_check_status)
	{
		SetBit(msgbody[1], 5);
	}
	//BIT4 0
	if(wifi_fault_status)
	{
		SetBit(msgbody[1], 4);
	}
	//BIT3 0/1
	if(wifi_config_mode)
	{
		SetBit(msgbody[1], 3);
	}

	//BIT2 0
	if(dev_powersave_mode)
	{
		SetBit(msgbody[1], 2);
	}
	
	//BIT1 0
	if(wifi_connect_status)
	{
		SetBit(msgbody[1], 1);
	}
	//BIT0 1
	if(wifi_smart_config_mode)
	{
		SetBit(msgbody[1], 0);
	}

/*********************************byte 3********************/	
	//BIT7~BIT5
	if(wifi_status == WAITTING_NORMAL_CONNECT)
	{
		msgbody[2]  |= 0x20;
	}
	else if(wifi_status == WIFI_CONNECTING)
	{
		msgbody[2]  |= 0x40;
	}
	else if(wifi_status == WIFI_UPDATE)
	{
		msgbody[2]  |= 0x30;
	}
	else if(wifi_status == ROUTER_FAULT)
	{
		msgbody[2]  |= 0x80;
	}
	else if(wifi_status == WIFI_UNSED)
	{
		msgbody[2]  |= 0xA0;
	}
	else if(wifi_status == WIFI_SELF_CHECK)
	{
		msgbody[2]  |= 0xC0;
	}
	else if(wifi_status == WIFI_SCAN)
	{
		msgbody[2]  |= 0xE0;
	}
	//BIT4~BIT1
    //router_cloud_connect_status
	if(router_cloud_connect_status == ROUTER_DISCONNECT)
	{
		msgbody[2]  |= 0x01;
	}
	else if(router_cloud_connect_status == ROUTER_CONNECT_CLOUD_DISCONNECT)
	{
		msgbody[2]  |= 0x02;
	}
	else if(router_cloud_connect_status == CONFIG_ROUTER_CONNECT_CLOUD_DISCONNECT)
	{
		msgbody[2]  |= 0x04;
	}
	else if(router_cloud_connect_status == SCAN_ROUTER_CONNECT_CLOUD_DISCONNECT)
	{
		msgbody[2]  |= 0x05;
	}
	else if(router_cloud_connect_status == SCAN_NO_WIFI)
	{
		msgbody[2]  |= 0x80;
	}
	else if(router_cloud_connect_status == SCAN_WITHOUT_CONNECT)
	{
		msgbody[2]  |= 0x0A;
	}
	else if(router_cloud_connect_status == ROUTER_CONNECT_CLOUD_CONNECT)
	{
		msgbody[2]  |= 0x0C;
	}
	else if(router_cloud_connect_status == CONFIG_ROUTER_CONNECT_CLOUD_CONNECT)
	{
		msgbody[2]  |= 0x0E;
	}
	else if(router_cloud_connect_status == SCAN_ROUTER_CONNECT_CLOUD_CONNECT)
	{
		msgbody[2]  |= 0x10;
	}

	//BIT0 0
	if (electricity_metering_function)
	{
		SetBit(msgbody[2], 0);
	}
/*********************************byte 4********************/	
/*********************************byte 5********************/

/*********************************byte 6********************/	
	//BIT7 0
	if (authorized_to_run)
	{
		SetBit(msgbody[5], 7);
	}
	//BIT6 0
	if (wifi_powersave_mode)
	{
		SetBit(msgbody[5], 6);
	}
	//BIT5~BIT4 00
	
	
	//BIT3 0
	if (bluetooth_fault_statue)
	{
		SetBit(msgbody[5], 3);
	}
	
	//BIT2~BIT0 0/1
	if(bluetooth_state == BLUETOOTH_STATE_DISCONNECT)
	{
		msgbody[5]  |= 0x00;
	}
	else if(bluetooth_state == BLUETOOTH_STATE_CONNECTED)
	{
		msgbody[5]  |= 0x01;
	}
	else if(bluetooth_state == BLUETOOTH_STATE_CONNECTING)
	{
		msgbody[5]  |= 0x02;
	}
	else if(bluetooth_state == BLUETOOTH_STATE_TRANS_PAUSE)
	{
		msgbody[5]  |= 0x03;
	}
	else if(bluetooth_state == BLUETOOTH_STATE_TRANS_STOP)
	{
		msgbody[5]  |= 0x04;
	}

	
}


extern int need_offline_flag;
void enter_on_config_mode_handle()
{
	log_printf_d("[%s]\n",__FUNCTION__);
	t_WIFI_GLOBAL* pl_wg = MC_WIFI_GLOBAL_PTR();
	t_CONFIG_TABLE_BODY* pl_cfg = MC_WG_CONFIG_TABLE_PTR();

	if (HSN_LOGIN_STATE_HB == pl_wg->v_cloud_login_sta)
	{
		printf("device unbind2\n");
		rlt_udp_send_func_entry();
	}	
}

void enter_smart_link_config_mode_handle()
{
	wapi_send_net_msg(SMART_CONFIG_MODE, NULL, 0, NULL);
}

void hsn_config_mode()
{
	//wapi_send_net_msg(HSN_CONFIG_MODE, NULL, 0, NULL);
}


void enter_softap_config_mode_handle()
{
	log_printf_d("[%s]\n",__FUNCTION__);
	t_CONFIG_TABLE_BODY* pl_cfg = MC_WG_CONFIG_TABLE_PTR();
	
	pl_cfg->v_cur_mode = WIFI_MODE_AP;
	pl_cfg->v_promise_reboot = 1;
	bapi_set_write_config_flag();
	bapi_set_reboot_flag(11);
}


void enter_default_config_config_handle()
{
	log_printf_d("[%s]\n",__FUNCTION__);
	t_CONFIG_TABLE_BODY* pl_cfg = MC_WG_CONFIG_TABLE_PTR();
	pl_cfg->v_cur_mode = WIFI_MODE_STA;
	bapi_set_write_config_flag();
	bapi_set_reboot_flag(12);
}

void cmd_ox1E_status_check() //30
{
	unsigned char tdata[PACKET_LEN_WITH_MSGBODY] = {0};
	unsigned int tdata_len;
	unsigned char msg_body[8] = {0};
	msg_body_build_func(msg_body);
	memset(tdata, 0, PACKET_LEN_WITHOUT_MSGBODY);
	tdata_len = uart_packet_build(0X1E, 0x0, msg_body, 8, tdata, 0);
	uart_data_send(tdata, tdata_len);
}


void cmd_0x66_status_check()//102 上报状态
{
	unsigned char *tdata;
	unsigned int tdata_len;
	tdata_len = PACKET_LEN_WITHOUT_MSGBODY + 1;
	tdata = malloc(tdata_len);
	if(tdata == NULL)
	{
		log_printf_w("[%s]malloc error\n",__FUNCTION__);
		return;
	}
	memset(tdata, 0, tdata_len);
	tdata_len = uart_packet_build(0X66, 0x0, NULL, 1, tdata, 0);
	uart_data_send(tdata, tdata_len);
	free(tdata);
}

void mcu_status_check()
{	
	printf("mcu_102\n");
	set_net_packet_seq(901, 0);
	cmd_0x66_status_check();
}

void device_unbind_handle()
{
	log_printf_d("[%s]\n",__FUNCTION__);
	t_WIFI_GLOBAL* pl_wg = MC_WIFI_GLOBAL_PTR();

	printf("device unbind3\n");
	wapi_send_tcpsend_msg(DEVICE_LOGOUT, NULL, 0, NULL);

}

