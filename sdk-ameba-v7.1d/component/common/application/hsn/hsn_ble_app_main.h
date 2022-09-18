
#ifndef _HSN_BLE_APP_MAIN_H_
#define _HSN_BLE_APP_MAIN_H_


int hsn_ble_app_init(void);
void hsn_ble_app_deinit(void);
void hsn_set_sta_change_cb(hsn_sta_change_cb pp_func);

int hsn_ble_init_for_factory(void);



#endif //_HSN_BLE_APP_MAIN_H_
