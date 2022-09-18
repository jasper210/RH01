/*
 * @Description: rlt_ota.h
 * @Author: xuetong
 * @Date: 2019-09-06 11:29:11
 * @LastEditTime: 2019-09-06 14:45:13
 * @LastEditors: Please set LastEditors
 */
#ifndef _RLT_OTAL_H
#define _RLT_OTAL_H

void ota_entry(unsigned char *addr);
int ota_info_parse(unsigned char *para, char *host, char *resource);
#endif