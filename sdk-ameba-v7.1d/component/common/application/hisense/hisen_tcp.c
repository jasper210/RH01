#include "hisen_common.h"



#if 0
int device_ask_unbind_to_net()
{
	int ret;
	unsigned char *tdata;
	MD5_CTX md5;
  	unsigned char tmp_16_md5[16];
	unsigned char temp_8_md5[8];
	unsigned char temp_json[128];
	unsigned char key_json_str[160];
	memset(temp_json, 0, 128);
	memset(key_json_str, 0, 160);
	tdata = malloc(150);
	if(tdata == NULL)
	{
		log_printf2("[%s]malloc error\n",__FUNCTION__);
		return 0;
	}
	//sprintf(temp_json, "{\"id\":402,\"token\":\"%s\"}", server_token);
	sprintf(key_json_str, "%s%s", DEV_KEY, temp_json);
	printf("key_json_str: %s\n", key_json_str);
	sprintf(tdata, "HS%s", temp_json);
	MD5Init(&md5);
    MD5Update(&md5, key_json_str, strlen(key_json_str));
    MD5Final(&md5, tmp_16_md5);
	memcpy(temp_8_md5, &tmp_16_md5[4], 8);
	sprintf(tmp_16_md5, "%02x%02x%02x%02x%02x%02x%02x%02x%s", temp_8_md5[0],temp_8_md5[1],temp_8_md5[2],temp_8_md5[3],temp_8_md5[4],temp_8_md5[5],temp_8_md5[6],temp_8_md5[7],"\r\n");
	sprintf(tdata + strlen(tdata), "%s", tmp_16_md5);
		return 0;
}

#endif





