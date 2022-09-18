#ifndef __HISEN_CONFIG_SNIFFER_H__
#define __HISEN_CONFIG_SNIFFER_H__


#define HISEN_SNIFFER_PASSWORD_LEN		65
#define HISEN_SNIFFER_SSID_LEN			33
#define HISEN_SNIFFER_BSSID_LEN			6


typedef struct tagHisenRouterInfo {
	char ssid[33];
	unsigned char ssid_len;
	
	char pwd[65];
	A_UINT8 pwd_len;
	
	unsigned char bssid[6];
	unsigned char bssid_len;
	
	unsigned long security_type;
	int key_id;

} t_HISEN_ROUTER_INFO;



typedef int(*hisen_sniffer_config_callback)(int result, void *pp_ctx);


typedef unsigned char uint8;


int sniffer_func_entry(hisen_sniffer_config_callback pp_func);

void test_hisen_snifffer_config();



#endif//__HISEN_CONFIG_SNIFFER_H__
