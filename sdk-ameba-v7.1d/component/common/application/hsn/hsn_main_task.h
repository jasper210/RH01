/*
 * @Description: In User Settings Edit
 * @Author: your name
 * @Date: 2019-10-18 10:21:19
 * @LastEditTime: 2019-10-18 10:21:19
 * @LastEditors: your name
 */
/*************************************************************************
	> File Name: rlt_main_task.h
	> Author: xuetong
	> Mail: 
	> Created Time: Tue 24 Apr 2018 11:44:04 AM CST
 ************************************************************************/

#ifndef _RLT_MAIN_TASK_H
#define _RLT_MAIN_TASK_H







enum E_HOST_ENTRY_MSG {
	HOST_ENTRY_MSG_TIMER = 0x01,
	HOST_ENTRY_MSG_GET_DEV_ADDR,
	HOST_ENTRY_MSG_GET_DEV_ADDR_FINISH,
	HOST_ENTRY_MSG_BT_START,
	HOST_ENTRY_MSG_BT_FINISH,
	HOST_ENTRY_MSG_UNBIND_DEV,
	HOST_ENTRY_MSG_UNBIND_DEV_FINISH,
	HOST_ENTRY_MSG_CONFIG_WIFI,
	HOST_ENTRY_MSG_CONFIG_WIFI_FINISH,
	HOST_ENTRY_MSG_SMART_CONFIG,
	HOST_ENTRY_MSG_SMART_CONFIG_FINISH,
	HOST_ENTRY_MSG_NET_CONFIG,
	



	//---------------------------
	HOST_ENTRY_MSG_MAX
};


void example_snowky(void);
void GpioUartRXIrqCallback (uint32_t id, gpio_irq_event event);
void hsn_sys_reset(int num);



#endif
