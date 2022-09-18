
#ifndef _HSN_NET_TASK_H_
#define _HSN_NET_TASK_H_

void wapi_bt_config_timer_oneshot_init();
void wapi_bt_config_timer_uninit();


int wapi_send_net_msg(int msg_flag,unsigned char *data,unsigned int data_len, void* pp_callback);
int wapi_send_tcpsend_msg(int msg_flag,unsigned char *data,unsigned int data_len, void* pp_callback);



#endif
