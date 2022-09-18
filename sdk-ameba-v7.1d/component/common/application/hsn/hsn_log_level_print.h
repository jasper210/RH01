/*************************************************************************
	> File Name: log_level_print.h
	> Author: 
	> Mail: 
	> Created Time: Tue 24 Apr 2018 11:46:23 AM CST
 ************************************************************************/

#ifndef _LOG_LEVEL_PRINT_H
#define _LOG_LEVEL_PRINT_H

#define __func__ __FUNCTION__

#undef LOG_ALERT
#undef LOG_WARNING
#undef LOG_INFO
#undef LOG_DEBUG
#define LOG_ALERT "<0>"
#define LOG_WARNING "<1>"
#define LOG_INFO "<2>"
#define LOG_DEBUG "<3>"

#define MAX_PRINTF_BUF 256

#define log_printf_a printf
#define log_printf_w printf
#define log_printf_i printf
#define log_printf_d printf



/*If user want to change log-level , use this macro */
#define DEFAULT_LOG_LEVEL 3

/* User should not change this macro */
#define DEFAULT_LOG_PRINTF_LEVEL (DEFAULT_LOG_LEVEL + '0')

#define MAX_LOG_LEVEL 3
#define MAX_LOG_PRINTF_LEVEL (MAX_LOG_LEVEL + '0')

//void set_log_printf_level(int log_level);
//void log_printf(char *format,...);

#define WAPI_TRACE_HEX(PTR, LEN)   \
do {\
	int i; \
    for (i = 0; i < (LEN); i++)\
    {\
		printf("%02X ", (*(((A_INT8*)(PTR)) + i)) & 0xff); \
    }\
	printf("\n"); \
} while (0)


//#ifdef WAPI_DEBUG_DUMP_HEX
#if 1
#define WAPI_DUMP_HEX(PTR, LEN, STR)   \
do {\
	int i; \
	printf("%s", (STR)); \
    for(i = 0; i < (LEN); i++)\
    {\
        if( (i%16) == 0 )\
        {\
			printf("\n"); \
        }\
		printf("%02X ", (*(((unsigned char*)(PTR)) + i)) & 0xff); \
    }\
	printf("\n"); \
} while (0)
#else
#define WAPI_DUMP_HEX(PTR, LEN, STR)
#endif



#define LOG_TRACE

#define LOGT(fmt,...)   \
do {\
	printf(fmt, ##__VA_ARGS__); \
} while (0)


#define LOGD(fmt,...)   \
do {\
	printf("#D[%s]-%d, ", __FUNCTION__, __LINE__); \
	printf(fmt, ##__VA_ARGS__); \
} while (0)


#define LOGW(fmt,...)   \
do {\
	printf("#W[%s]-%d, ", __FUNCTION__, __LINE__); \
	printf(fmt, ##__VA_ARGS__); \
} while (0)


#define LOGE(fmt,...)   \
do {\
	printf("#E[%s]-%d, ", __FUNCTION__, __LINE__); \
	printf(fmt, ##__VA_ARGS__); \
} while (0)


#define WAPI_CLR_BUF(ptr, size)    memset(ptr, 0, sizeof(size))


#define WAPI_POP_U32(ptr)	((A_UINT32)( (((A_UINT32)(*(ptr + 0))) << 24) + (((A_UINT32)(*(ptr + 1))) << 16) + (((A_UINT32)(*(ptr + 2))) << 8) + ((A_UINT32)(*(ptr + 3))) ))
#define WAPI_POP_U16(ptr)	((A_UINT16)( (((A_UINT16)(*(ptr + 0))) << 8) + ((A_UINT16)(*(ptr + 1))) ))
#define WAPI_POP_U8(ptr)	((A_UINT8)( (A_UINT8)(*(ptr + 0)) ))

#define WAPI_BCD2HEX(a) (((a) & 0x0F) + 10*((a)>>4))
#define WAPI_HEX2BCD(a) ((((a)%100)/10)<<4 | ((a)%10))



void timerReset(unsigned int *timestamp);
int isTimeOut(unsigned int timestamp, unsigned int timeout);



#endif
