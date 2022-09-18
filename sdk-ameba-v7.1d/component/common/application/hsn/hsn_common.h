
#ifndef _COMMON_H
#define _COMMON_H

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

#include "gpio_irq_api.h"
#include "PinNames.h"
#include "device_lock.h"
#include "flash_api.h"





////////////////////////////////////////


#include <ota_http/example_ota_http.h>
/////////////////////////////////////////
#define HSN_PLATFORM_8720CF		1
#define HSN_BLE_CONFIG			1
#define HSN_UART_SELECT 		1
//#define HSN_07CMD_TIMER 		1
#define HSN_UPDATE_20210924		1
//#define HSN_UPDATE_20210926		0


///
//#define HSN_TEST_MAC			1
#define HSN_MAC0 	0x5c
#define HSN_MAC1 	0xc3
#define HSN_MAC2 	0x36
#define HSN_MAC3 	0x19
#define HSN_MAC4 	0x4a
#define HSN_MAC5 	0x70
//

#define HSN_ICEBOX				1
#define HSN_DISHWASHER			1

/////////////////////////////////////////
#include "hsn_define.h"


#include "hsn_cJSON.h"
#include "hsn_md5.h"



#ifdef HSN_UART_SELECT

#define SC_MSG_taskENTER_CRITICAL()     //taskENTER_CRITICAL()
#define SC_MSG_taskEXIT_CRITICAL()	    //taskEXIT_CRITICAL()

#endif
#define SC_SURREND_TASK()					//vTaskDelay(1)

#include "hsn_uart_protocol.h"
#include "hsn_net_data_process.h"
#include "hsn_data_type_def.h"
#include "hsn_log_level_print.h"
#include "hsn_uart_task.h"
#include "hsn_uart_cmd_handle.h"
#include "hsn_queue_func.h"
//#include "cattsoft.h"
#include "hsn_flash_config.h"

#include "hsn_softap_config.h"
#include "hsn_net_data_process.h"
#include "hsn_net_task.h"
#include "hsn_main_task.h"

#include "hsn_lan.h"
#include "hsn_byte_code.h"
#include "hsn_wifi_config.h"
#include "hsn_multicast_protocol_Analysis.h"
#include "hsn_bt_config.h"

#include "hsn_ble_peripheral_app.h"
#include "hsn_ble_app_task.h"
#include "hsn_ble_app_flags.h"
#include "hsn_ble_simple_ble_service.h"
#include "hsn_ble_profile_server.h"
#include "hsn_ble_app_main.h"

//#include "polarssl/aes.h"
//#include "polarssl/md5.h"
//#include "mbedtls/base64.h"
#include "mbedtls/aes.h"



#define HSS_DEAULT_ENVIRONMENT	 0 // 0 for release, 1 for testing, 2, for develop
#define HSN_ENFORE_EVN			1
#define HSN_WATCHDOW_CONFIG		1

#define HSN_DEBUG_UART			0
#define HSN_DEBUG_NET			0

#define HSN_START_SOFTAP		0

#define HSN_TSK_PRIORITY        (1)

#if 0
// for release
#if (HSS_DEAULT_ENVIRONMENT==0)
#define CInfo 		"IM20C.HXX.7.01.01.CW" 

#define FEATURE_CODE_FOR_DASHWASHER ""//"86100c00fffe00b000000040"
#define DEV_KEY_FOR_DASHWASHER      ""//"7d70ebf71d98d29f"

#define FEATURE_CODE_FOR_OTHER ""//"86100c009002002000000202"
#define DEV_KEYFOR_FOR_OTHER      ""//"7d70ebf71d98d29f"


#define FEATURE_CODE_FOR_ICEBOX "86100c00fffe01000000fffe"//"86100c00fffe012000000206"
#define DEV_KEY__FOR_ICEBOX      "f9b9852ec2b76f7b"//"22e7ce23535249b5"//"efb5b0a3d34e40f6"


//for testing
#elif (HSS_DEAULT_ENVIRONMENT==1)
#define CInfo 		"IM20C.HXX.0.01.01.CW" 

#define FEATURE_CODE_FOR_DASHWASHER "86100c00fffe00b000000040"//"86100c00fffe00b000000040"
#define DEV_KEY_FOR_DASHWASHER      "8161c9ad3c92e40b"//"7d70ebf71d98d29f"

#define FEATURE_CODE_FOR_OTHER "86100c00fffe00b000000040"//"86100c009002002000000202"
#define DEV_KEYFOR_FOR_OTHER      "8161c9ad3c92e40b"//"7d70ebf71d98d29f"

#define FEATURE_CODE_FOR_ICEBOX ""//"86100c00fffe012000000206"
#define DEV_KEY__FOR_ICEBOX      ""//"22e7ce23535249b5"//"efb5b0a3d34e40f6"


//for develop
#elif (HSS_DEAULT_ENVIRONMENT==2)
#define CInfo 		"IM20C.HXX.1.01.01.CW" 

#define FEATURE_CODE_FOR_DASHWASHER "86100c00fffe00b000000040"//"86100c00fffe00b000000040"
#define DEV_KEY_FOR_DASHWASHER      "7d70ebf71d98d29f"//"7d70ebf71d98d29f"

#define FEATURE_CODE_FOR_OTHER "86100c00fffe00b000000040"//"86100c009002002000000202"
#define DEV_KEYFOR_FOR_OTHER      "7d70ebf71d98d29f"//"7d70ebf71d98d29f"

#define FEATURE_CODE_FOR_ICEBOX ""//"86100c00fffe012000000206"
#define DEV_KEY__FOR_ICEBOX      ""//"22e7ce23535249b5"//"efb5b0a3d34e40f6"
#endif

#endif




#define HSN_KITCHE_SOFTAP_CONFIG_TIMEOUT			(60*60*1000)
#define HSN_KITCHE_BLE_CONFIG_TIMEOUT				(60*60*1000)

#define HSN_KITCHE_SOFTAP_CONFIG_TIMEOUT_M			(30*60*1000)
#define HSN_KITCHE_BLE_CONFIG_TIMEOUT_M				(30*60*1000)



#define HSN_RELEASE_CInfo 		"IM20C.HXX.7.01.43.CW" 
#define HSN_TESTING_CInfo 		"IM20C.HXX.0.01.43.CW" 
#define HSN_DEVELOP_CInfo 		"IM20C.HXX.1.01.43.CW" 

////////////////////////////////////////////////////////////
#define HSN_DEVICE_TYPE_DISHWASHER				0x07
#define HSN_DEVICE_TYPE_HEATING_STOVE			0x2A
#define HSN_DEVICE_TYPE_RANGE_HOOD				0x23
#define HSN_DEVICE_TYPE_STOVE					0x22
#define HSN_DEVICE_TYPE_WATER_HEATER_ELECTIC	0x04
#define HSN_DEVICE_TYPE_WATER_HEATER_GAS		0x25
#define HSN_DEVICE_TYPE_OVEN_1					0x27	//// 1UK49L00KTPW



#define HSN_FEATURECODE_KITCHEN			"86100c00fffe00b000000040"//"86100c00fffe00b000000040"
#define HSN_RELEASE_KITCHEN_DEV_KEY      "e2e1b29ccb32af34"//"e2e1b29ccb32af34"
#define HSN_TESTING_KITCHEN_DEV_KEY      "8161c9ad3c92e40b"//"8161c9ad3c92e40b"
#define HSN_DEVELOP_KITCHEN_DEV_KEY      "7d70ebf71d98d29f"//"7d70ebf71d98d29f"


////////////////////////////////////////////////////////////
#define HSN_DEVICE_TYPE_ICEBOX					0x02

#define HSN_FEATURECODE_ICEBOX			"86100c00fffe00d000000040"//"86100c00fffe00d000000040"
#define HSN_RELEASE_ICEBOX_DEV_KEY      "2f0ddd404f6cb0de"//""
#define HSN_TESTING_ICEBOX_DEV_KEY      "f3b5eb2d5aca3e3f"//""
#define HSN_DEVELOP_ICEBOX_DEV_KEY      "60fdbd8945aa9618"//""


////////////////////////////////////////////////////////////
#define HSN_DEVICE_TYPE_DRYER					0x08
#define HSN_DEVICE_TYPE_WASHING					0x09

#define HSN_FEATURECODE_WASHING			"86100c00fffe01300000fffe"//"86100c00fffe00d000000040"
#define HSN_RELEASE_WASHING_DEV_KEY      ""//""
#define HSN_TESTING_WASHING_DEV_KEY      ""//""
#define HSN_DEVELOP_WASHING_DEV_KEY      "6f922ac7d67e2393"//""



////////////////////////////////////////////////////////////
#define HSN_DEVICE_TYPE_OVEN		0xFF	//// 1UK49L00KTPW

#define HSN_FEATURECODE_OVEN		"86100c00a008001000000207"
#define HSN_RELEASE_OVEN_DEV_KEY      ""//""
#define HSN_TESTING_OVEN_DEV_KEY      ""//""
#define HSN_DEVELOP_OVEN_DEV_KEY      "5e5e3eec96fecf68"//""




#if 0
#define HSN_FEATURECODE_ICEBOX			"86100c00fffe01000000fffe"//"86100c00fffe01000000fffe"
#define HSN_RELEASE_ICEBOX_DEV_KEY      "f9b9852ec2b76f7b"//"86100c00fffe01000000fffe"
#define HSN_TESTING_ICEBOX_DEV_KEY      ""//""
#define HSN_DEVELOP_ICEBOX_DEV_KEY      ""//""
#endif





#if 0
//icebox release
#define FEATURE_CODE "86100c00fffe01000000fffe"//"86100c00fffe012000000206"
#define DEV_KEY      "f9b9852ec2b76f7b"//"22e7ce23535249b5"//"efb5b0a3d34e40f6"
#else

#define FEATURE_CODE "86100c00fffe00b000000040"//"86100c00fffe00b000000040"

//dashwasher develop
#define DEV_KEY      "7d70ebf71d98d29f"//"8161c9ad3c92e40b"


//dashwasher test
//#define DEV_KEY      "8161c9ad3c92e40b"//"8161c9ad3c92e40b"

//1ux0s100413k+5cc3361d03c2 devid
//#define HSN_DASHWASHER_CODE		"1ux0s100413k"
//#define HSN_DASHWASHER_CODE		"1h2012345678"





#endif




#define RID    		0
#define PLVer 		"2.0"
//#define CInfo 		"IM20C.HXX.0.01.01.CW" 
//#define CInfo 		"IM20C.HXX.7.01.01.CW" 
#define HTYPE 		0
#define HState 		0
#define HCause 		NULL
#define ConnPort 	5020  
#define Uri 		NULL  
#define DevPData 	NULL  
#define DevList 	NULL
#define ExID 		0  


#define PMU_USER_DEVICE  PMU_DEV_USER_BASE

#endif
