#ifndef __HISEN_DEFINE_H__
#define __HISEN_DEFINE_H__


#define MSMART
//#define WAPI_MD_POLL
#define WAPI_MD_MSG
//#define WAPI_WATCHDOG_ON
#define WAPI_APP_CONNECTED_UPLOAD

#define LOG_TRACE
#define LOG_WARN
#define LOG_ERROR

#define LOG_DEBUG
#define LOG_INFO
#define WAPI_DEBUG_DUMP_HEX

#define GOLBAL
#define STATIC static

#define WAPI_PRODUCTION_TEST_ROUTER		"chigo-facture"

#define WAPI_CHIGO_VERSION		"0.1"

#define JD_VERSION_HW_FUNC					0x20
#define JD_VERSION_HW_PARA					0x70
#define JD_VERSION_MIDEA_PROTOCAL_VER		0x16
#define JD_VERSION_SW_VER					0x01
#define JD_VERSION_YEAR						0x16
#define JD_VERSION_WEEK						0x52

#define VERSION_SW_INTERNAL_VER				0x01
#define VERSION_SW_INTERNAL_VER_SHOW		(VERSION_SW_INTERNAL_VER + 1)





typedef char                A_CHAR;
typedef signed char         A_INT8;
typedef unsigned char       A_UINT8;
typedef unsigned char       A_UCHAR;
typedef short               A_INT16;
typedef unsigned short      A_UINT16;
typedef int                 A_INT32;
typedef unsigned int        A_UINT32;
typedef long long           A_INT64;
typedef unsigned long long  A_UINT64;
typedef int                 A_BOOL;
typedef unsigned int        A_ULONG;
typedef A_ULONG             A_ADDR;






#endif//__HISEN_DEFINE_H__
