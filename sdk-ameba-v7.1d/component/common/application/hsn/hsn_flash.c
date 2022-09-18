#include "hsn_common.h"


#define HISEN_FLASH_USER_DATA 	(0x200000 - 0x6000)//(0x200000 - 0xAA000)



static flash_t s_flash;
//xQueueSendToBack


void wapi_flash_erase_user_data()
{
	flash_t flash;

	device_mutex_lock(RT_DEV_LOCK_FLASH);
	flash_erase_sector(&flash, HISEN_FLASH_USER_DATA);
	device_mutex_unlock(RT_DEV_LOCK_FLASH);
}

int wapi_flash_read_user_data(A_UINT8* pp_data, A_UINT32 vp_data_len)
{
	flash_t flash;
    int vl_ret = -1;

	device_mutex_lock(RT_DEV_LOCK_FLASH);
    vl_ret = flash_stream_read(&flash, HISEN_FLASH_USER_DATA, vp_data_len, (uint8_t *)pp_data);
	device_mutex_unlock(RT_DEV_LOCK_FLASH);
    if (1 == vl_ret)
    {
        vl_ret = 0;
    }
    else
    {
        printf("read_flash_err:%d\n", vl_ret);
    }

	return vl_ret;
}

int wapi_flash_write_user_data(A_UINT8* pp_data, A_UINT32 vp_data_len)
{
	flash_t flash;
    int vl_ret = -1;

	device_mutex_lock(RT_DEV_LOCK_FLASH);
	flash_erase_sector(&flash, HISEN_FLASH_USER_DATA);
	vl_ret = flash_stream_write(&flash, HISEN_FLASH_USER_DATA, vp_data_len, (uint8_t *)pp_data);
	device_mutex_unlock(RT_DEV_LOCK_FLASH);
    if (1 == vl_ret)
    {
        vl_ret = 0;
    }
    else
    {
        printf("write_flash_err:%d\n", vl_ret);
    }
    
	return vl_ret;
}



void tes_flash_user_data()
{
    A_UINT8 al_in_buf[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    A_UINT8 al_out_buf[8] = {0};
    
    wapi_flash_write_user_data(al_in_buf, 8);
    WAPI_TRACE_HEX(al_out_buf, 8);
    wapi_flash_read_user_data(al_out_buf, 8);
    WAPI_TRACE_HEX(al_out_buf, 8);
    if (0 == memcmp(al_out_buf, al_in_buf, 8))
    {
        printf("flash ok\n");
    }
    else
    {
        printf("flash FAIL\n");
    }
}







