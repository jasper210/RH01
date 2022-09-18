#ifndef __HISEN_COMMON_H__
#define __HISEN_COMMON_H__

/////////////////////////////////

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include <stdlib.h>
#include "timers.h"
#include "serial_api.h"
#include "timer_api.h"
#include "wifi_structures.h"
#include "wifi_conf.h"
#include "lwip_netconf.h"
#include "platform/platform_stdlib.h"
#include "lwip/sockets.h"
#include "netdb.h"
#include <platform/platform_stdlib.h>
#include "main.h"
#include "mbedtls/aes.h"
#include "gpio_irq_api.h"
#include <flash_api.h>
#include "device_lock.h"





/////////////////////////////////
#include "hisen_define.h"
#include "hisen_flash.h"
#include "hisen_local.h"
#include "hisen_msg_queue.h"
#include "hisen_net_procotol.h"
#include "hisen_ota.h"
#include "hisen_config_sniffer.h"
#include "hisen_config_softap.h"
#include "hisen_config_bt.h"
#include "hisen_config_wifi.h"
#include "hisen_tcp.h"
#include "hisen_uart.h"
#include "hisen_uart_procotol.h"
#include "hisen_wlan.h"
#include "hisen_param_config.h"
#include "hisen_net_utils.h"
#include "hisen_main.h"
#include "hisen_byte_code.h"
#include "hisen_cJSON.h"
#include "hisen_md5.h"
#include "hisen_aes.h"





#define SC_MSG_taskENTER_CRITICAL()     //taskENTER_CRITICAL()
#define SC_MSG_taskEXIT_CRITICAL()	    //taskEXIT_CRITICAL()

#define SC_SOCKET_taskENTER_CRITICAL()     //taskENTER_CRITICAL()
#define SC_SOCKET_taskEXIT_CRITICAL()	    //taskEXIT_CRITICAL()
#define SC_SURREND_TASK()					vTaskDelay(1)




///////////////////////////////////
#define X_ERROR           0
#define X_WARNING      1
#define X_INFO               2
#define X_DEBUG           3
#define X_NONE             0xff
#define DEBUG_LEVEL X_DEBUG

#define x_printf(level, fmt, arg...)     \
do {\
        if (level <= DEBUG_LEVEL) {\
                if (level <= X_ERROR) {\
                        taskENTER_CRITICAL();\
                        printf("\r\nERROR: " fmt, ##arg);\
                        taskEXIT_CRITICAL();\
                } \
                else {\
                        taskENTER_CRITICAL();\
                        printf("\r\n"fmt, ##arg);\
                        taskEXIT_CRITICAL();\
                } \
        }\
}while(0)

#define X_PRINTF(fmt, arg...)  x_printf(X_INFO, fmt, arg...)


#define A_PRINTF    printf
#define time_ms()	xTaskGetTickCount()


#ifdef WIN32 
typedef enum boolean{
	false = 0L,
	true
} bool;
#else
#define false	0
#define true	1
#endif


#if 1

#define WAPI_TRACE_HEX(PTR, LEN)   \
do {\
	int i; \
    for (i = 0; i < (LEN); i++)\
    {\
    	taskENTER_CRITICAL();\
		printf("%02X ", (*(((A_INT8*)(PTR)) + i)) & 0xff); \
		taskEXIT_CRITICAL();\
    }\
    taskENTER_CRITICAL();\
	printf("\n"); \
	taskEXIT_CRITICAL();\
} while (0)


//#ifdef WAPI_DEBUG_DUMP_HEX
#if 1
#define WAPI_DUMP_HEX(PTR, LEN, STR)   \
do {\
	int i; \
	taskENTER_CRITICAL();\
	printf("%s", (STR)); \
    for(i = 0; i < (LEN); i++)\
    {\
        if( (i%16) == 0 )\
        {\
			printf("\n"); \
        }\
		printf("%02X ", (*(((A_INT8*)(PTR)) + i)) & 0xff); \
    }\
	printf("\n"); \
	taskEXIT_CRITICAL();\
} while (0)
#else
#define WAPI_DUMP_HEX(PTR, LEN, STR)
#endif



#define LOG_TRACE

#define LOGT(fmt,...)   \
do {\
	taskENTER_CRITICAL();\
	printf(fmt, ##__VA_ARGS__); \
	taskEXIT_CRITICAL();\
} while (0)


#define LOGD(fmt,...)   \
do {\
	taskENTER_CRITICAL();\
	printf("#D[%s]-%d, ", __FUNCTION__, __LINE__); \
	printf(fmt, ##__VA_ARGS__); \
	taskEXIT_CRITICAL();\
} while (0)


#define LOGW(fmt,...)   \
do {\
	taskENTER_CRITICAL();\
	printf("#W[%s]-%d, ", __FUNCTION__, __LINE__); \
	printf(fmt, ##__VA_ARGS__); \
	taskEXIT_CRITICAL();\
} while (0)


#define LOGE(fmt,...)   \
do {\
	taskENTER_CRITICAL();\
	printf("#E[%s]-%d, ", __FUNCTION__, __LINE__); \
	printf(fmt, ##__VA_ARGS__); \
	taskEXIT_CRITICAL();\
} while (0)

#else
#define WAPI_TRACE_HEX(PTR, LEN)
#define WAPI_DUMP_HEX(PTR, LEN, STR)
#define LOGT(fmt,...)
#define LOGD(fmt,...)
#define LOGW(fmt,...)
#define LOGE(fmt,...)  

#endif

#define WAPI_CLR_BUF(ptr, size)    memset(ptr, 0, sizeof(size))


#define WAPI_POP_U32(ptr)	((A_UINT32)( (((A_UINT32)(*(ptr + 0))) << 24) + (((A_UINT32)(*(ptr + 1))) << 16) + (((A_UINT32)(*(ptr + 2))) << 8) + ((A_UINT32)(*(ptr + 3))) ))
#define WAPI_POP_U16(ptr)	((A_UINT16)( (((A_UINT16)(*(ptr + 0))) << 8) + ((A_UINT16)(*(ptr + 1))) ))
#define WAPI_POP_U8(ptr)	((A_UINT8)( (A_UINT8)(*(ptr + 0)) ))

#define WAPI_BCD2HEX(a) (((a) & 0x0F) + 10*((a)>>4))
#define WAPI_HEX2BCD(a) ((((a)%100)/10)<<4 | ((a)%10))


#if 0
void timerReset(A_UINT32 *timestamp);
int isTimeOut(A_UINT32 timestamp, A_UINT32 timeout);
#endif


#define HISEN_PASSWORD_LEN		65
#define HISEN_SSID_LEN			33



#endif//__HISEN_COMMON_H__

