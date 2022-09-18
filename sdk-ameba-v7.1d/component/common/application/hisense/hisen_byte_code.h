#ifndef __HISEN_BYTE_CODE_H__
#define __HISEN_BYTE_CODE_H__


unsigned char char_to_hex(unsigned char ch);
void hex_2_bit(unsigned char *buff, unsigned int buff_len, int offset_cnt);
int bit_2_hex(unsigned char *bit_buff, unsigned char *hex_buff, int bit_len, int hex_len);
int mbedtls_base64_encode_x(unsigned char *dst, size_t dlen, size_t *olen,const unsigned char *src, size_t slen);
int xt_mbedtls_base64_decode( unsigned char *dst, size_t dlen, size_t *olen,const unsigned char *src, size_t slen );
int multibyte_aes_decode(unsigned char *dst, int dst_len, int *len, unsigned char *src, int src_len);



#endif//__HISEN_BYTE_CODE_H__
