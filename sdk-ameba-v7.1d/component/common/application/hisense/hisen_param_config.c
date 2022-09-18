#include "hisen_common.h"

GOLBAL t_WIFI_GLOBAL g_wifi_global;

STATIC bool s_config_changed_flag = false;//0δ???1???
void bapi_set_write_config_flag()
{
	s_config_changed_flag = true;
}

void bapi_clear_write_config_flag()
{
	s_config_changed_flag = false;
}

bool bapi_config_is_writed()
{
	return s_config_changed_flag;
}

STATIC bool s_reboot_flag = false;
void bapi_set_reboot_flag()
{
	s_reboot_flag = true;
}

void bapi_clear_reboot_flag()
{
	s_reboot_flag = false;
}

bool bapi_get_reboot_flag()
{
	return s_reboot_flag;
}



A_UINT8 wapi_bcc_calulate(A_UINT8 *pp_buf, A_UINT16 vp_len)
{
#define WAPI_BCC_VALUE  0x20
	A_UINT8 vl_sum = 0;

	while (vp_len--)
	{
		vl_sum ^= *pp_buf++;
	}
	vl_sum |= WAPI_BCC_VALUE;

	return vl_sum;
}


static int bapi_config_pack(t_CONFIG_TABLE_BODY* pp_cfg_bdy, A_UINT8* pp_out, A_UINT32* pp_out_len)
{
	t_CONFIG_TABLE_HEADER* pl_hrd = (t_CONFIG_TABLE_HEADER*)pp_out;
	t_CONFIG_TABLE_BODY* pl_bdy = (t_CONFIG_TABLE_BODY*)(pp_out + sizeof(t_CONFIG_TABLE_HEADER));

	memset(pl_hrd, 0, sizeof(t_CONFIG_TABLE_HEADER));
	pl_hrd->v_header1 = BAPI_CONFIG_TABLE_HEADER1;
	pl_hrd->v_header2 = BAPI_CONFIG_TABLE_HEADER2;
	pl_hrd->v_saved_flag = BAPI_FLAG_SAVED;

	pl_hrd->v_version = BAPI_CONFIG_TABLE_VERSION_0001;
	pl_hrd->v_len = sizeof(t_CONFIG_TABLE_BODY);

	memcpy(pl_bdy, pp_cfg_bdy, sizeof(t_CONFIG_TABLE_BODY));

	*pp_out_len = sizeof(t_CONFIG_TABLE_HEADER)+sizeof(t_CONFIG_TABLE_BODY);

	pl_hrd->v_checksum = wapi_bcc_calulate((A_UINT8*)&pl_hrd->v_version, *pp_out_len - 4);

	return CONFIG_TABLE_OK;

}

static int bapi_config_unpack(A_UINT8* pp_in, t_CONFIG_TABLE_BODY* pp_out)
{
	A_UINT8 vl_chksum = 0;
	t_CONFIG_TABLE_HEADER* pl_hrd = (t_CONFIG_TABLE_HEADER*)pp_in;
	t_CONFIG_TABLE_BODY* pl_bdy = (t_CONFIG_TABLE_BODY*)(pp_in + sizeof(t_CONFIG_TABLE_HEADER));

	printf("config:%d\n", sizeof(t_CONFIG_TABLE_HEADER)+sizeof(t_CONFIG_TABLE_BODY)-4);
	vl_chksum = wapi_bcc_calulate((A_UINT8*)&pl_hrd->v_version, sizeof(t_CONFIG_TABLE_HEADER)+sizeof(t_CONFIG_TABLE_BODY)-4);
	if (vl_chksum == pl_hrd->v_checksum)
	{
		printf("\n");
		memcpy(pp_out, pl_bdy, sizeof(t_CONFIG_TABLE_BODY));
		return CONFIG_TABLE_OK;
	}
	else
	{
		printf("config unpack checksum error\n");
		return CONFIG_TABLE_CHECKSUM_FAIL;
	}
}

void bapi_config_init(t_CONFIG_TABLE_BODY* pp_cfg_bdy)
{
	memset(pp_cfg_bdy, 0, sizeof(t_CONFIG_TABLE_BODY));
	bapi_clear_write_config_flag();
}


void bapi_config_table_reset(t_CONFIG_TABLE_BODY* pp_cfg_bdy)
{
	memset(pp_cfg_bdy, 0, sizeof(t_CONFIG_TABLE_BODY));
}


int bapi_config_read(t_CONFIG_TABLE_BODY* pp_cfg_bdy)
{
	int ret = CONFIG_TABLE_RW_ERROR;
	A_UINT8 al_buf[BAPI_TABLE_MAX_LEN];

	A_UINT32 vl_len = sizeof(t_CONFIG_TABLE_HEADER)+sizeof(t_CONFIG_TABLE_BODY);
	ret = wapi_flash_read_user_data(al_buf, vl_len);
	if (0 == ret)
	{
		//WAPI_DUMP_HEX(al_buf, vl_len, "read config:");
		ret = bapi_config_unpack(al_buf, pp_cfg_bdy);
		if (CONFIG_TABLE_OK == ret)
		{
			ret = CONFIG_TABLE_OK;
		}
		else
		{
			ret = CONFIG_TABLE_CHECKSUM_FAIL;
			LOGI("config checksum fail.\n");
		}

	}
	else
	{
		ret = CONFIG_TABLE_RW_ERROR;
		printf("config read error: %d\n", ret);
	}

	return ret;
}

//???д
int bapi_config_write(t_CONFIG_TABLE_BODY* pp_cfg_bdy)
{
	int ret = 0;
	A_UINT8 al_buf[BAPI_TABLE_MAX_LEN];
	A_UINT32 vl_len = 0;
	if (true == bapi_config_is_writed())
	{
		printf("save config...\n");
		bapi_clear_write_config_flag();
		memset(al_buf, 0, BAPI_TABLE_MAX_LEN);
		ret = bapi_config_pack(pp_cfg_bdy, al_buf, &vl_len);
		if (CONFIG_TABLE_OK == ret)
		{
			ret = wapi_flash_write_user_data(al_buf, vl_len);
			if (0 == ret)
			{
				//WAPI_DUMP_HEX(al_buf, vl_len, "write config:");
				//bapi_config_read(pp_cfg_bdy);
				ret = CONFIG_TABLE_OK;
			}
			else
			{
				printf("config write error\n");
				ret = CONFIG_TABLE_RW_ERROR;
			}
		}

	}

	return ret;

}

void hisen_mac_str_init(char* mac_str)
{
	extern struct netif xnetif[NET_IF_NUM]; 
	char* model_mac = NULL;
	model_mac = LwIP_GetMAC(&xnetif[0]);
	sprintf(mac_str, "%02x%02x%02x%02x%02x%02x",  model_mac[0], model_mac[1], model_mac[2], model_mac[3], model_mac[4], model_mac[5]);
	mac_str[12] = '\0';
	printf("mac str:%s\n", mac_str);
}

void hisen_generate_device_id(char* pp_devid_str, char* pp_wifi_id_base64, int vp_wifi_id_len)
{
	extern struct netif xnetif[NET_IF_NUM]; 
	int len = 0;
	char* model_mac = LwIP_GetMAC(&xnetif[0]);
	sprintf(pp_devid_str, "%s%02x%02x%02x%02x", FEATURE_CODE, model_mac[2], model_mac[3], model_mac[4], model_mac[5]);
	pp_devid_str[32] = '\0';
	printf("devid:%s\n", pp_devid_str);
	int ret = mbedtls_base64_encode_x(pp_wifi_id_base64, vp_wifi_id_len, &len, pp_devid_str,strlen(pp_devid_str));
	if(ret == 0)
	{
		printf("wifi_id_base64: %s\n", pp_wifi_id_base64);
	}
}




void wapi_init_wifi_global()
{
	t_WIFI_GLOBAL* pl_wg = MC_WIFI_GLOBAL_PTR();
	memset(pl_wg, 0, sizeof(t_WIFI_GLOBAL));
	hisen_mac_str_init(pl_wg->mac_str);
	hisen_generate_device_id(pl_wg->mac_str, pl_wg->wifi_id_base64, 50);
	
}



