#include "hisen_common.h"
char str[32];
A_CHAR * _inet_ntoa(A_UINT32 ip)
{
	memset(str, 0, sizeof (str));
	sprintf(str, "%u.%u.%u.%u", (unsigned)(ip & 0xff), (unsigned)((ip >> 8) & 0xff)
		, (unsigned)((ip >> 16) & 0xff), (unsigned)(ip >> 24));
	return str;
}

A_UINT32 wapi_inet_addr(A_CHAR *str)
{
	A_UINT32 ipaddr;
	A_UINT32 data[4];
	A_UINT32 ret;

	ret = sscanf(str, "%3d.%3d.%3d.%3d", data, data + 1, data + 2, data + 3);
	if (ret < 0) {
		return 0;
	}
	else {
		ipaddr = data[0] << 24 | data[1] << 16 | data[2] << 8 | data[3];
	}
	return ipaddr;
}



int wapi_get_rssi()
{
	int vl_rssi = 0;
	wifi_get_rssi(&vl_rssi);

	return vl_rssi;
}


#define WLAN0_NAME_0		"wlan0"
int wapi_get_wifi_mode()
{
	int vl_mode = 0;
	wext_get_mode(WLAN0_NAME_0, &vl_mode);
	return vl_mode;
}

char mac_str[20];
char* wapi_get_mac_str()
{//12:23:34:45:56:67
	memset(mac_str, 0, 20);
	wifi_get_mac_address(mac_str);
    return mac_str;
}


void wapi_HexToStr(unsigned char *pbDest, unsigned char *pbSrc, int nLen)
{
	char	ddl, ddh;
	int i;

	for (i = 0; i<nLen; i++)
	{
		ddh = 48 + pbSrc[i] / 16;
		ddl = 48 + pbSrc[i] % 16;
		if (ddh > 57) ddh = ddh + 7;
		if (ddl > 57) ddl = ddl + 7;
		pbDest[i * 2] = ddh;
		pbDest[i * 2 + 1] = ddl;
	}

	pbDest[nLen * 2] = '\0';
}

char* wapi_get_mac_str_ex()
{//123456789012
	char* pl_mac = wapi_get_mac_str();
	A_UINT8 al_mac[12];
	sscanf(pl_mac, "%x:%x:%x:%x:%x:%x", &al_mac[0], &al_mac[1], &al_mac[2], &al_mac[3], &al_mac[4], &al_mac[5]); 

	memset(mac_str, 0, 20);
	wapi_HexToStr(mac_str, al_mac, 6);
	
    return mac_str;
}

static uint32_t unix_time_value;
static uint32_t getsysms(void)
{
#ifdef QCOM_4004B
	unsigned long ret;
#else
	uint64_t ret;
#endif

#ifdef __MRVL_MW300__
	ret = os_get_timestamp() / 1000UL;
#elif defined(__LINUX__)
	struct timespec monotime;
	clock_gettime(CLOCK_MONOTONIC_RAW, &monotime);
	ret = 1000UL * monotime.tv_sec + (monotime.tv_nsec / 1000000UL);
#elif defined(_WIN32)
	ret = GetTickCount();
#elif defined(QCOM_4004B)
	ret = time_ms();
#else
	ret = time_ms();

#endif
	return ret;
}
void timerReset(uint32_t *timestamp)
{
	unix_time_value = getsysms() & 0xFFFFFFFF;
	*timestamp = unix_time_value;
}

int isTimeOut(uint32_t timestamp, uint32_t timeout)
{
	unix_time_value = getsysms() & 0xFFFFFFFF;
	uint32_t ret = (timestamp + timeout) - unix_time_value;
	return ret & 0x80000000;
}


