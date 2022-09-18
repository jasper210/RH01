#ifndef __HISEN_NET_UTILS_H__
#define __HISEN_NET_UTILS_H__


#define IPv4_STR_PRT(addr) printf("%d.%d.%d.%d\n", (addr)>>24&0xff, (addr)>>16&0xff, (addr)>>8&0xff, (addr)&0xff)
#define MAC_STR_PRT(mac) printf("%02x:%02x:%02x:%02x:%02x:%02x\n", mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);




A_CHAR * _inet_ntoa(A_UINT32 ip);


int wapi_get_rssi();
int wapi_get_wifi_mode();
char* wapi_get_mac_str();
char* wapi_get_mac_str_ex();

A_UINT32 wapi_inet_addr(A_CHAR *str);


void timerReset(uint32_t *timestamp);
int isTimeOut(uint32_t timestamp, uint32_t timeout);





#endif//__HISEN_NET_UTILS_H__
