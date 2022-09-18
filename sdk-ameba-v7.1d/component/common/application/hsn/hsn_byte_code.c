/*
 * @Description: byte_code.c
 * @Author: xuetong
 * @Date: 2019-08-22 13:30:19
 * @LastEditTime: 2019-09-02 17:04:09
 * @LastEditors: Please set LastEditors
 */
#include "hsn_common.h"

unsigned char server_aes_key[16] = {0};

int bit_2_hex(unsigned char *bit_buff, unsigned char *hex_buff, int bit_len, int hex_len)
{
    for(int j = 0; j < hex_len; j++)
    {
        hex_buff[j] = bit_buff[j * 8];
        for (int i = 1; i < 8; i++)
        {
            hex_buff[j] = (hex_buff[j] << 1) | bit_buff[8 * j + i];
        }
    }
    return 0;
}

void Reverse(unsigned char *buff,int from,int to)
{
    unsigned char temp;//辅助变量
    for(int i = from;i<(from+to)/2+1;i++)
	{
        temp = buff[i];
        buff[i] = buff[from+to-i];
        buff[from+to-i] = temp;
    }
}

void buffer_left_move(unsigned char *buff,int buff_len,int pos)
{
    Reverse(buff,0,pos-1);
    Reverse(buff,pos,buff_len-1);
    Reverse(buff,0,buff_len-1);
}

void buffer_right_move(unsigned char *buff,int buff_len,int pos)
{
    Reverse(buff, 0, buff_len - pos - 1);
    Reverse(buff, buff_len - pos, buff_len - 1);
    Reverse(buff, 0, buff_len -1);
}

void hex_2_bit(unsigned char *buff, unsigned int buff_len, int offset_cnt)
{
    int offset = 0;
    unsigned char ch;
    unsigned char temp_buff[8];
    unsigned char *bit_buff;
    unsigned int bit_buff_len = buff_len * 8;
	if (bit_buff_len > 512)
		return;
    bit_buff = malloc(bit_buff_len);
    if(bit_buff == NULL)
    {
		log_printf_w("[%s]malloc error\n",__FUNCTION__);
		return;
	}
    for(int j = 0; j < buff_len; j++)
    {
        ch = buff[j];
        for (int i = 0; i < 8; i++)
        {
            temp_buff[8 - 1 - i] = ch % 2;
            ch /= 2;
        }
        memcpy(bit_buff + offset, temp_buff, 8);
        offset += 8;
    }
    buffer_right_move(bit_buff, bit_buff_len, offset_cnt);    //bit移位
    bit_2_hex(bit_buff, buff, bit_buff_len, buff_len);
	
	if (NULL != bit_buff)
	{
		free(bit_buff);
		bit_buff = NULL;
	}
}

unsigned char char_to_hex(unsigned char ch)
{
	unsigned char value = 0;
    if(ch >= 0x30 && ch <=0x39)
    {
        value = ch - 0x30;
    }
    else if(ch >= 0x41 && ch <= 0x46)
    {
        value = ch - 0x37;
    }
    else if(ch >= 0x61 && ch <= 0x66)
    {
        value = ch - 0x57;
    }
    return value;
}


static const unsigned char base64_enc_map_x[64] =
{
	'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
	'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
	'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd',
	'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
	'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
	'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7',
	'8', '9', '+', '/'
};


typedef unsigned int size_t;
#define BASE64_SIZE_T_MAX_X   ( (size_t) -1 ) /* SIZE_T_MAX is not standard */

int mbedtls_base64_encode_x(unsigned char *dst, size_t dlen, size_t *olen,
	const unsigned char *src, size_t slen)
{
	size_t i, n;
	int C1, C2, C3;
	unsigned char *p;

	if (slen == 0)
	{
		*olen = 0;
		return(0);
	}

	n = slen / 3 + (slen % 3 != 0);

	if (n > (BASE64_SIZE_T_MAX_X - 1) / 4)
	{
		*olen = BASE64_SIZE_T_MAX_X;
		return(-1);
	}

	n *= 4;

	if (dlen < n + 1)
	{
		*olen = n + 1;
		return(-1);
	}

	n = (slen / 3) * 3;

	for (i = 0, p = dst; i < n; i += 3)
	{
		C1 = *src++;
		C2 = *src++;
		C3 = *src++;

		*p++ = base64_enc_map_x[(C1 >> 2) & 0x3F];
		*p++ = base64_enc_map_x[(((C1 & 3) << 4) + (C2 >> 4)) & 0x3F];
		*p++ = base64_enc_map_x[(((C2 & 15) << 2) + (C3 >> 6)) & 0x3F];
		*p++ = base64_enc_map_x[C3 & 0x3F];
	}

	if (i < slen)
	{
		C1 = *src++;
		C2 = ((i + 1) < slen) ? *src++ : 0;

		*p++ = base64_enc_map_x[(C1 >> 2) & 0x3F];
		*p++ = base64_enc_map_x[(((C1 & 3) << 4) + (C2 >> 4)) & 0x3F];

		if ((i + 1) < slen)
			*p++ = base64_enc_map_x[((C2 & 15) << 2) & 0x3F];
		else *p++ = '=';

		*p++ = '=';
	}

	*olen = p - dst;
	*p = 0;

	return(0);
}


#define MBEDTLS_ERR_BASE64_BUFFER_TOO_SMALL               -0x002A  /**< Output buffer too small. */
#define MBEDTLS_ERR_BASE64_INVALID_CHARACTER              -0x002C  /**< Invalid character in input. */

static const unsigned char base64_dec_map[128] =
{
    127, 127, 127, 127, 127, 127, 127, 127, 127, 127,
    127, 127, 127, 127, 127, 127, 127, 127, 127, 127,
    127, 127, 127, 127, 127, 127, 127, 127, 127, 127,
    127, 127, 127, 127, 127, 127, 127, 127, 127, 127,
    127, 127, 127,  62, 127, 127, 127,  63,  52,  53,
     54,  55,  56,  57,  58,  59,  60,  61, 127, 127,
    127,  64, 127, 127, 127,   0,   1,   2,   3,   4,
      5,   6,   7,   8,   9,  10,  11,  12,  13,  14,
     15,  16,  17,  18,  19,  20,  21,  22,  23,  24,
     25, 127, 127, 127, 127, 127, 127,  26,  27,  28,
     29,  30,  31,  32,  33,  34,  35,  36,  37,  38,
     39,  40,  41,  42,  43,  44,  45,  46,  47,  48,
     49,  50,  51, 127, 127, 127, 127, 127
};

int xt_mbedtls_base64_decode( unsigned char *dst, size_t dlen, size_t *olen,
                   const unsigned char *src, size_t slen )
{
    size_t i, n;
    uint32_t j, x;
    unsigned char *p;

    /* First pass: check for validity and get output length */
    for( i = n = j = 0; i < slen; i++ )
    {
        /* Skip spaces before checking for EOL */
        x = 0;
        while( i < slen && src[i] == ' ' )
        {
            ++i;
            ++x;
        }

        /* Spaces at end of buffer are OK */
        if( i == slen )
            break;

        if( ( slen - i ) >= 2 &&
            src[i] == '\r' && src[i + 1] == '\n' )
            continue;

        if( src[i] == '\n' )
            continue;

        /* Space inside a line is an error */
        if( x != 0 )
            return( MBEDTLS_ERR_BASE64_INVALID_CHARACTER );

        if( src[i] == '=' && ++j > 2 )
            return( MBEDTLS_ERR_BASE64_INVALID_CHARACTER );

        if( src[i] > 127 || base64_dec_map[src[i]] == 127 )
            return( MBEDTLS_ERR_BASE64_INVALID_CHARACTER );

        if( base64_dec_map[src[i]] < 64 && j != 0 )
            return( MBEDTLS_ERR_BASE64_INVALID_CHARACTER );

        n++;
    }

    if( n == 0 )
    {
        *olen = 0;
        return( 0 );
    }

    n = ( ( n * 6 ) + 7 ) >> 3;
    n -= j;

    if( dst == NULL || dlen < n )
    {
        *olen = n;
        return( MBEDTLS_ERR_BASE64_BUFFER_TOO_SMALL );
    }

   for( j = 3, n = x = 0, p = dst; i > 0; i--, src++ )
   {
        if( *src == '\r' || *src == '\n' || *src == ' ' )
            continue;

        j -= ( base64_dec_map[*src] == 64 );
        x  = ( x << 6 ) | ( base64_dec_map[*src] & 0x3F );

        if( ++n == 4 )
        {
            n = 0;
            if( j > 0 ) *p++ = (unsigned char)( x >> 16 );
            if( j > 1 ) *p++ = (unsigned char)( x >>  8 );
            if( j > 2 ) *p++ = (unsigned char)( x       );
        }
    }

    *olen = p - dst;

    return( 0 );
}

void updata_aes_key(unsigned char *key)
{
    memcpy(server_aes_key, key, strlen((char*)key));
    printf("aes key: %s\n", server_aes_key);
}

int remove_pkcs5padding(unsigned char *input, unsigned int input_len)
{
	unsigned char padding_len;
	int data_len;

	if ((0 == input) || (0 == input_len))
	{
		printf("remove pkcs5padding input error!\n");
		return -1;
	}
	if ((input_len%16) != 0)
	{
		printf("remove pkcs5padding input data length error!\n");
		return -1;
	}
	padding_len = input[input_len - 1];
	//A_PRINTF("remove_pkcs5padding: get padding len is %d\n",padding_len);
	if (padding_len > 16)
	{
		printf("remove pkcs5padding padding length error1!\n");
		return -1;
	}
	data_len = input_len - padding_len;

	if ((padding_len > input_len) || (padding_len == 0))
	{
		printf("remove pkcs5padding padding length error2!\n");
		return -1;
	}

	return data_len;
}




int multibyte_aes_decode(unsigned char *dst, int dst_len, int *len, unsigned char *src, int src_len)
{ 
    unsigned char temp_buff[16] = {0};
    mbedtls_aes_context aes_ctx;
	int vl_len = 0;
    if((src_len % 16) != 0)
    {
        printf("error\n");
        return -1;
    }
    mbedtls_aes_init(&aes_ctx);
	mbedtls_aes_setkey_dec(&aes_ctx, server_aes_key, 128);
    for(int i = 0; i < (src_len/16); i++)
    {
        memcpy(temp_buff, &src[i * 16], 16);
        mbedtls_aes_crypt_ecb(&aes_ctx, MBEDTLS_AES_DECRYPT, temp_buff, temp_buff);
        memcpy(&dst[16 * i], temp_buff, 16);
        vl_len += 16;
        //print_hex(temp_buff, 16);
    }
	*len = remove_pkcs5padding(dst, vl_len);
	//mbedtls_aes_crypt_ecb(&aes_ctx, MBEDTLS_AES_DECRYPT, temp_key_buff, temp_key_buff);
    return 0;
}

/*
int aes_ecb_decryption(u8 *arg,u8 *arv,u16 argc,u8 flag) 
{

    unsigned char Aes_Message_Buffer[1024];

    short ecb_time, ct_remain, ct_cover, ct_all;
    int ret = -1;
    //memset(Aes_Final_Message, 0,sizeof(Aes_Final_Message));
    memset(Aes_Message_Buffer, 0,sizeof(Aes_Message_Buffer));
    memset(ecb_key, 0,sizeof(ecb_key));
    u16 ct_len = argc; //    ?   
    //printf("\nct_len %d argc%d \n",ct_len,argc);
    for(int i=0;i < ct_len;i++) 
    {
        Aes_Message_Buffer[i] = arv[i];
    }
    strcpy(ecb_key, arg);
    ecb_time = ct_len / AES_ECB_BLOCKS;
    ct_remain = ct_len % AES_ECB_BLOCKS;
    ct_cover = AES_ECB_BLOCKS - ct_remain;
    device_mutex_lock(RT_DEV_LOCK_CRYPTO);
    ret = rtl_crypto_aes_ecb_init(ecb_key,16);
    device_mutex_unlock(RT_DEV_LOCK_CRYPTO);
    if (ret != 0) 
    {
        DiagPrintf("\naes_ecb init failed.");
        return ret;
    }

    if((ct_len < AES_ECB_BLOCKS) && (ct_len != 0)) 
    {
        DiagPrintf("\n[decrypt] pt_len <16 and >0 return -1");
        return ret;
    }
    else
    {
        #if 0
        if(flag==0){????
        memset(ecb_outbuf, 0,sizeof(ecb_outbuf));
        for(int j = 0; j<ecb_time; j++){
        device_mutex_lock(RT_DEV_LOCK_CRYPTO);
        //ret = rtl_crypto_aes_ecb_decrypt(&Aes_Message_Buffer[16*j], AES_ECB_BLOCKS, NULL, 0, &ecb_outbuf[16*j]);
        ret = rtl_crypto_aes_ecb_decrypt(&Aes_Message_Buffer[16*j], AES_ECB_BLOCKS, NULL, 0, &arv[16*j]);
        device_mutex_unlock(RT_DEV_LOCK_CRYPTO);
        }
        }
        else if(flag==1){
        memset(cloud_ecb_outbuf, 0,sizeof(cloud_ecb_outbuf));
        for(int j = 0; j<ecb_time; j++){
        device_mutex_lock(RT_DEV_LOCK_CRYPTO);
        //ret = rtl_crypto_aes_ecb_decrypt(&Aes_Message_Buffer[16*j], AES_ECB_BLOCKS, NULL, 0, &cloud_ecb_outbuf[16*j]);
        ret = rtl_crypto_aes_ecb_decrypt(&Aes_Message_Buffer[16*j], AES_ECB_BLOCKS, NULL, 0, &arv[16*j]);
        device_mutex_unlock(RT_DEV_LOCK_CRYPTO);
        }
        }
        #else
        for(int j = 0; j<ecb_time; j++)
        {
            device_mutex_lock(RT_DEV_LOCK_CRYPTO);
            //ret = rtl_crypto_aes_ecb_decrypt(&Aes_Message_Buffer[16*j], AES_ECB_BLOCKS, NULL, 0, &ecb_outbuf[16*j]);
            ret = rtl_crypto_aes_ecb_decrypt(&Aes_Message_Buffer[16*j], AES_ECB_BLOCKS, NULL, 0, &arv[16*j]);
            device_mutex_unlock(RT_DEV_LOCK_CRYPTO);
        }
    #endif
    }
    return 1;
}
*/

