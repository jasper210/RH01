#ifndef __HISEN_WLAN_H__
#define __HISEN_WLAN_H__


#define SC_SSID_MAX_LEN		32
#define SC_PWD_MAX_LEN		64


typedef int(*find_router_callback)(int result, char* pp_ssid, void *pp_ctx);
int wapi_find_router(char* pp_ssid, find_router_callback pp_fn);
void wapi_start_ap(char* pp_ssid, char* pp_pwd);
char* wapi_get_ap_ssid_name(A_UINT8* pp_data, A_UINT8 vp_len);
#define wapi_get_ap_pwd()		"4009696236"

A_UINT32 wapi_get_ip();

int wapi_get_ap_list_20_ex(unsigned char* pp_out, unsigned int* pp_out_len, unsigned int vp_max_out);



////////////////////////////连接路由接口//////////////////////////////
typedef int(*connect_router_callback)(
	int vl_result		//0-连上路由并成功获取IP  ; 1-连接路由失败
	, int vl_reason		//0-默认成功；1-获取ip失败，其他值连接ap视情况定义
	);

int wapi_connect_router(
	char* pp_ssid					//路由名称
	, char* pp_pwd					//路由密码
	, rtw_security_t vp_security	//
	, unsigned int vl_timeout_ms	//连接超时，一般会设置为1分钟，30秒连接路由，30秒获取IP
	, connect_router_callback pp_fn	//连接路由过程状态变化的回调，包括断开连接/连接成功等，视情况定义
	);

//断开路由连接
int wapi_disconnect_router();


void hisen_test_connect_ap();

void hise_disconnect_from_ap(void);
int hisen_connect_ap_1(t_HISEN_ROUTER_INFO *pp_router_info, connect_router_callback pp_fn);
void hisen_init_wifi_struct(t_HISEN_ROUTER_INFO *pp_router_info);




#endif//__HISEN_WLAN_H__
