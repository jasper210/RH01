/*
 * @Description: _HSN_DEFINE_H_.h
 * @Author: xuetong
 * @Date: 2019-08-05 08:48:44
 * @LastEditTime: 2019-11-18 14:49:28
 * @LastEditors: Please set LastEditors
 */

#ifndef _HSN_DEFINE_H_
#define _HSN_DEFINE_H_

#define GOLBAL
#define STATIC static

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


#if 1

#ifndef bool
typedef unsigned char           bool;
#endif

#else
#define false	0
#define true	1
#endif

typedef int(*hsn_sta_change_cb)(int vp_sta_type, int vp_sta, void* pp_ctx);
enum E_CALLBACK_STA_TYPE {
	CALLBACK_STA_TYPE_BT = 0x00,
	CALLBACK_STA_TYP_UNBIND_DEV,

	//---------------------------
	CALLBACK_STA_TYPE_MAX
};



#endif//_HSN_DEFINE_H_