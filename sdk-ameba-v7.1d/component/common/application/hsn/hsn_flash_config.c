#include "hsn_common.h"

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

void hsn_reset_config_table(unsigned char vp_flag)
{
	t_CONFIG_TABLE_BODY* pl_cfg = MC_WG_CONFIG_TABLE_PTR();
	memset(pl_cfg, 0, sizeof(t_CONFIG_TABLE_BODY));
	
	pl_cfg->v_cur_mode = WIFI_MODE_NETCONFIG;

	printf("reset config table\n");
	
	bapi_set_write_config_flag();
	if (1 == vp_flag)
	{
		bapi_config_write(pl_cfg);
	}
}




STATIC bool s_reboot_flag = false;
STATIC unsigned s_reboot_reason = 0;
void bapi_set_reboot_flag(unsigned char vp_reboot_reason)
{
	s_reboot_flag = true;
	s_reboot_reason = vp_reboot_reason;
}

void bapi_clear_reboot_flag()
{
	s_reboot_flag = false;
	s_reboot_reason = 0;
}

int bapi_get_reboot_flag()
{
	return s_reboot_flag;
}

void wapi_sys_reboot()
{
	LOGT("reboot(%d)...\r\n", s_reboot_reason);
	vTaskDelay(100);
	vTaskDelay(100);
	vTaskDelay(100);
	vTaskDelay(100);
	vTaskDelay(100);
	sys_reset();
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

	printf("config size:%d\n", sizeof(t_CONFIG_TABLE_HEADER)+sizeof(t_CONFIG_TABLE_BODY)-4);
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
			printf("config checksum fail.\n");
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





