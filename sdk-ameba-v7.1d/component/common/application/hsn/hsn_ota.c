/*
 * @Description: rlt_ota.c
 * @Author: xuetong
 * @Date: 2019-09-05 15:23:16
 * @LastEditTime: 2019-09-06 15:24:45
 * @LastEditors: Please set LastEditors
 */

#include "hsn_common.h"


#define PORT	80
#define HOST	"10.18.210.20"  //"m-apps.oss-cn-shenzhen.aliyuncs.com"
#define RESOURCE "Content/WifiDeviceVersionFile/156922055594100820.bin"     //"051103061600.bin"

//char *URL = "https://download.xyz2013.com/My/5201449.shtml";  

//#define HSN_OTA_URL "http://api.wg.hismarttv.com/agw/ota/app/confirmUpgrade"  


int ota_info_parse(unsigned char *para, char *host, char *resource)
{
	char *start;
	char *s_host;
	int host_len;
	start = para + strlen("http") + 3;
	s_host = strchr(start, '/');
	host_len = s_host - start;
	memcpy(host, start, host_len);
	strcpy(resource, s_host);
	return 1;
}

void update_ota_task(void *param)
{
	LOGT("entry ota update...\n");
	char host[64] = {0};
	char resouce[128] = {0};
	ota_info_parse((char *)param, host, resouce);
	printf("host: %s, resouce: %s\n", host, resouce);
	int ret = -1;	
	ret = http_update_ota(host, PORT, resouce);
	//ret = http_update_ota(HOST, PORT, RESOURCE);
exit:	
	printf("\n\r[%s] Update task exit", __FUNCTION__);
	if(!ret){
		printf("\n\r[%s] Ready to reboot", __FUNCTION__);	
		ota_platform_reset();
	}
	vTaskDelete(NULL);	
}


void ota_entry(unsigned char *addr)
{
		if(xTaskCreate(update_ota_task, (char const *)"update_ota_task", 1024, addr, tskIDLE_PRIORITY + HSN_TSK_PRIORITY, NULL) != pdPASS){
		printf("\n\r[%s] Create update task failed", __FUNCTION__);
	}
}
