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



////////////////////////////����·�ɽӿ�//////////////////////////////
typedef int(*connect_router_callback)(
	int vl_result		//0-����·�ɲ��ɹ���ȡIP  ; 1-����·��ʧ��
	, int vl_reason		//0-Ĭ�ϳɹ���1-��ȡipʧ�ܣ�����ֵ����ap���������
	);

int wapi_connect_router(
	char* pp_ssid					//·������
	, char* pp_pwd					//·������
	, rtw_security_t vp_security	//
	, unsigned int vl_timeout_ms	//���ӳ�ʱ��һ�������Ϊ1���ӣ�30������·�ɣ�30���ȡIP
	, connect_router_callback pp_fn	//����·�ɹ���״̬�仯�Ļص��������Ͽ�����/���ӳɹ��ȣ����������
	);

//�Ͽ�·������
int wapi_disconnect_router();


void hisen_test_connect_ap();

void hise_disconnect_from_ap(void);
int hisen_connect_ap_1(t_HISEN_ROUTER_INFO *pp_router_info, connect_router_callback pp_fn);
void hisen_init_wifi_struct(t_HISEN_ROUTER_INFO *pp_router_info);




#endif//__HISEN_WLAN_H__
