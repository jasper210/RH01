/*
 * @Description: fac_check.h
 * @Author: xuetong
 * @Date: 2019-09-19 17:14:04
 * @LastEditTime: 2019-09-19 17:19:00
 * @LastEditors: Please set LastEditors
 */
#ifndef _FAC_CHECK_H
#define _FAC_CHECK_H
int rlk_fac_check_init();
int rlk_get_ssid_init(unsigned char *bssid);
int scan_get_ssid_from_bssid(unsigned char *param);
void ssid_save_to_flash(char *ssid);
void hsn_factory_switch_evn(char vp_flag);
#endif