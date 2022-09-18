#include "hisen_common.h"


static xQueueHandle s_handle_mq_host_entry;

t_WAPI_MSG g_hostentry_msg;

A_UINT8	 g_hostentry_msgtype;
A_UINT32 g_hostentry_para;
A_UINT8  g_hostentry_header_len = 0;
A_UINT16 g_hostentry_msgbody_len = 0;
A_UINT8* gp_hostentry_msgheader = NULL;
A_UINT8* gp_hostentry_msgbody = NULL;
A_UINT32 g_hostentry_seq = 0;
A_UINT32 g_hostentry_para2 = 0;

static A_UINT32 s_hostentry_statue_log = 0;
static A_UINT32 s_hostentry_statue_change = 0;
t_WIFI_GLOBAL* gp_hostentry_wg = MC_WIFI_GLOBAL_PTR();
t_CONFIG_TABLE_BODY* gp_hostentry_cfg = MC_WG_CONFIG_TABLE_PTR();


void wapi_sys_reboot()
{
	printf("reboot...\r\n");
	vTaskDelay(100);
	vTaskDelay(100);
	vTaskDelay(100);
	vTaskDelay(100);
	vTaskDelay(100);
	sys_reset();
}



static xTimerHandle s_1hz_timer; // the timer handle of created FreeRTOS soft-timer

int wapi_send_mq_host_entry(A_UINT8 vp_msgtype, A_UINT8* pp_data, A_UINT32 vp_len)
{
    int vl_ret = -1;
    t_WAPI_MSG vl_msg;
	A_UINT8* pl_data1 = NULL;
    memset(&vl_msg, 0, sizeof(vl_msg));
    
    vl_msg.v_msgtype = vp_msgtype;
    
    if (NULL != pp_data && vp_len > 0)
    {
        A_UINT8* pl_data1 = (A_UINT8* )malloc(vp_len);
        if (NULL != pl_data1)
        {
            memcpy(pl_data1, pp_data, vp_len);
            vl_msg.p_msgbody = pl_data1;
            vl_msg.v_msgbody_len = vp_len; 
        }
    }
	SC_MSG_taskENTER_CRITICAL();
    if (pdTRUE == xQueueSend(s_handle_mq_host_entry, (void* )&vl_msg, 0))
    {
        vl_ret = 0;
    }
	else
	{
		if (NULL != pl_data1)
		{
			free(pl_data1);
		}
		
	}
	SC_MSG_taskEXIT_CRITICAL();
	SC_SURREND_TASK();
    
    return vl_ret;
}


void wapi_uart_cmd_test()
{
	static int flag = 0;
	A_UINT8 packet[80] = {0};
	A_UINT8 vl_len = 0;

	//printf("start test uart..\n");
	if (flag == 0)
	{
		flag = 1;
		//7-1
		A_UINT8 al_buf7[2] = {0};
		vl_len = sc_uart_pack(0x07, 0x01, al_buf7, 0, packet);
		//WAPI_DUMP_HEX(packet,vl_len,"7-1:");
		wapi_uart_send_direct(packet, vl_len, NULL);
		vTaskDelay(1000);

		//10-4
		A_UINT8 al_buf10[2] = {0};
		vl_len = sc_uart_pack(10, 4, al_buf10, 0, packet);
		//WAPI_DUMP_HEX(packet,vl_len,"10-4:");
		wapi_uart_send_direct(packet, vl_len, NULL);
		vTaskDelay(1000);

		//101-0
		A_UINT8 al_buf101[32] = {0x00, 0x03, 0x02, 0x5F, 0xF5, 0xF5, 0x5F, 0x03, 0x00, 0x00, 0x5F, 0xF5, 0x03, 0x98, 0x00, 0xC0, 0x3C, 0x99, 0x00, 0x8A, 0x8A, 0x8A, 0x8A, 0x8A, 0x8A, 0x8A, 0x8A, 0x8A, 0x8A, 0x00, 0x00, 0xF4};
		vl_len = sc_uart_pack(101, 0, al_buf101, 32, packet);
		//WAPI_DUMP_HEX(packet,vl_len,"101-0:");
		wapi_uart_send_direct(packet, vl_len, NULL);
		vTaskDelay(1000);

		//102-0
		A_UINT8 al_buf102[2] = {0};
		vl_len = sc_uart_pack(102, 0, al_buf102, 1, packet);
		//WAPI_DUMP_HEX(packet,vl_len,"102-0:");
		wapi_uart_send_direct(packet, vl_len, NULL);
		vTaskDelay(1000);

		//102-64
		A_UINT8 al_buf10264[2] = {0};
		vl_len = sc_uart_pack(102, 64, al_buf10264, 0, packet);
		//WAPI_DUMP_HEX(packet,vl_len,"102-64:");
		wapi_uart_send_direct(packet, vl_len, NULL);
		vTaskDelay(1000);

		//30-0
		A_UINT8 al_buf30[18] = {0xC0, 0x00, 0x50, 0x00, 0x00, 0x01, 0x00, 0x00};
		vl_len = sc_uart_pack(30, 0, al_buf30, 8, packet);
		//WAPI_DUMP_HEX(packet,vl_len,"30-0:");
		wapi_uart_send_direct(packet, vl_len, NULL);

		//printf("test uart finish..");
		

	}
	
}

void wapi_timer_cb(TimerHandle_t xTimer)
{   
    A_UINT8 al_buf[8] = {0, 2, 3, 4, 5, 6, 7, 8};
	A_UINT8 packet[80] = {0};
	A_UINT8 vl_len = 0;
	
	//vl_len = sc_uart_pack(0x07, 0x01, al_buf, 0, packet);
	//vl_len = sc_uart_pack(0x66, 0x00, al_buf, 1, packet);
    //wapi_uart_send_direct(packet, vl_len, NULL);
    
    wapi_send_mq_host_entry(HOST_ENTRY_MSG_TIMER, NULL, 0);
}


int bapi_uart_pack_handle_callback(A_UINT8 *pp_msg, A_UINT32 vp_msg_len)
{
	WAPI_DUMP_HEX(pp_msg, vp_msg_len, "uart_recv2:");
	hisen_uart_msg_handle(pp_msg, vp_msg_len);
	
}


void wapi_uart_recv_cb(A_UINT8* pp_data, int vp_len, void* pp_ctx)
{
	//WAPI_DUMP_HEX(pp_data, vp_len, "uart_recv1:");
	sc_uart_unpack(pp_data, vp_len, bapi_uart_pack_handle_callback);
}


void wapi_sc_version()
{
	printf("SC_VER: %s\nbuilt on %s %s\n", WAPI_CHIGO_VERSION, __DATE__, __TIME__);
}


void cJSON_Hooks_int()
{
	cJSON_Hooks memoryHook;
	memoryHook.malloc_fn = malloc;
	memoryHook.free_fn = free;
	cJSON_InitHooks(&memoryHook);
}


void wapi_init()
{
	vTaskDelay(100);
	vTaskDelay(100);
	printf("HOST_ENTRY\n");
    wapi_sc_version();
    printf("m:%d\n", xPortGetFreeHeapSize());
	printf("MAC:%s\n", wapi_get_mac_str());
	
	wapi_init_wifi_global();
	cJSON_Hooks_int();

	wapi_uart_comm_init(wapi_uart_recv_cb);
}


void wapi_host_entry_poll_init()
{
	s_1hz_timer = xTimerCreate("1hz_timer", 1000, 
			pdTRUE, (void *)0, wapi_timer_cb);
	xTimerStart(s_1hz_timer, 0);
	s_handle_mq_host_entry = xQueueCreate(MSG_COUNT, MSG_SIZE);
	memset(&g_hostentry_msg, 0, sizeof(g_hostentry_msg));
	
}

void ilife_watchdog_irq_handler(uint32_t id)
{
    printf("!!!!!!watchdog barks!!!!!!\r\n");
	vTaskDelay(800);
	sys_reset();
}




void wapi_host_entry_poll(void *param)
{
	if(pdPASS == xQueueReceive(s_handle_mq_host_entry, &g_hostentry_msg, ( ( TickType_t ) 0 )))
	{
		g_hostentry_msgtype = g_hostentry_msg.v_msgtype;
		g_hostentry_para = g_hostentry_msg.v_para;
		g_hostentry_header_len = g_hostentry_msg.v_header_len;
		g_hostentry_msgbody_len = g_hostentry_msg.v_msgbody_len;
		gp_hostentry_msgheader = g_hostentry_msg.p_msgheader;
		gp_hostentry_msgbody = g_hostentry_msg.p_msgbody;
		g_hostentry_seq = g_hostentry_msg.v_seq;

		

		switch (g_hostentry_msgtype)
		{
		case HOST_ENTRY_MSG_TIMER:

			if (isTimeOut(s_hostentry_statue_log, 5000))
			{
				timerReset(&s_hostentry_statue_log);
				printf("m:%d,r:%d\n", xPortGetFreeHeapSize(), wapi_get_rssi());
				
			}
#if 1
			bapi_config_write(gp_hostentry_cfg);
			if (true == bapi_get_reboot_flag())
			{
				wapi_sys_reboot();
				bapi_clear_reboot_flag();
			}
#endif	
			break;
		case HOST_ENTRY_MSG_CONNECT_ROUTER_STATA://2
			break;
		case HOST_ENTRY_MSG_SNIFFER:
			break;
		case HOST_ENTRY_MSG_AP:
			break;
		case HOST_ENTRY_MSG_STATION:
			break;
		case HOST_ENTRY_MSG_DNS_GETIP:
			break;
		default:
			break;
		} 
		////////////////////////////////////
		if (NULL != gp_hostentry_msgheader)
		{
			free(gp_hostentry_msgheader);
			gp_hostentry_msgheader = NULL;
		}

		if (NULL != gp_hostentry_msgbody)
		{
			free(gp_hostentry_msgbody);
			gp_hostentry_msgbody = NULL;
		}
		memset(&g_hostentry_msg, 0, sizeof(g_hostentry_msg));
	}       
}


typedef int (*init_done_ptr)(void);
init_done_ptr init_done_ptr_1 = NULL;


void xxxx_yyy1()
{
	if(init_done_ptr_1 != NULL)
	{
		LOGE("Init uart socket failed!\n");
	} 
}

int wapi_connect_router_callback(int result, int reason)
{
	//printf("router_cb:%d,%d\n", result, reason);
	if ((0 == result) && (0 == reason))
	{
		
	}
	else if (1 == result)
	{
		//wapi_send_to_hostentry_msg_ex(HOST_ENTRY_MSG_STATION, 1, NULL, 0);
	}
		
	
	
	return 0;
}



static xTimerHandle s_1hz_timer; // the timer handle of created FreeRTOS soft-timer

void wapi_host_entry(void *param)
{
#if 1
	wapi_init();
	wapi_host_entry_poll_init();
	test_hisen_snifffer_config();
	//hisen_test_connect_ap();
	vTaskDelay(2000);
	//wapi_uart_cmd_test();
	//wapi_connect_router("NEW", "12345678", RTW_SECURITY_WPA2_AES_PSK, 1000*2, wapi_connect_router_callback);
	while(1)
	{
		wapi_host_entry_poll(NULL);
		vTaskDelay(1000);
	}
#else
	int vl_sta = 0;
	xxxx_yyy1();
	while(1)
	{
		switch (vl_sta)
		{
		case 0:
			printf("m:%d,r:%d\n", xPortGetFreeHeapSize(), wapi_get_rssi());
			break;
		case 1://2
			printf("xxxx1\n");
			break;
		default:
			break;
		} 
	}
#endif	

}



extern init_done_ptr p_wlan_init_done_callback;



int start_hisense()
{
	//xTaskHandle app_task_handle = NULL;
	//p_wlan_init_done_callback = NULL;

	#define 	HOST_ENTRY_STACK_SIZE		512
	#define 	HOST_ENTRY_PRIORITY			5
	if(xTaskCreate(wapi_host_entry, "wapi_host_entry", HOST_ENTRY_STACK_SIZE, NULL, HOST_ENTRY_PRIORITY, NULL) != pdPASS)
		printf("%s xTaskCreate failed", __FUNCTION__);

	return 0;
}



void hisen_main(void)
{
	p_wlan_init_done_callback = start_hisense;
}




