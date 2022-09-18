#ifndef __HISEN_FLASH_H__
#define __HISEN_FLASH_H__


void wapi_flash_erase_user_data();
int wapi_flash_read_user_data(A_UINT8* pp_data, A_UINT32 vp_data_len);
int wapi_flash_write_user_data(A_UINT8* pp_data, A_UINT32 vp_data_len);

void tes_flash_user_data();



#endif//__HISEN_FLASH_H__
