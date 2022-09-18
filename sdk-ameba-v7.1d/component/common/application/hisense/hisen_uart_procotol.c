#include "hisen_common.h"


unsigned short get_checksum(unsigned char *data, unsigned int len)
{
	int i;
	unsigned short temp_checksum = 0;
	for(i = 0; i < len; i++)
	{	
		temp_checksum += data[i];
	}
	return temp_checksum;
}


unsigned int sc_uart_pack(unsigned char a, unsigned char b, unsigned char *msg_body, unsigned int msg_body_len, unsigned char *packet)
{
	unsigned short temp_crc16;

	packet[UartSOP_1] = SYNC_1;
	packet[UartSOP_2] = SYNC_2;
	packet[DATA_FLAG] = 0x00;
	packet[BYTE_40] = 0x40;
	packet[UartLEN] = msg_body_len + PACKET_LEN_ExCLUDE_SYNC;
	packet[BYTE_01_1] = 0x00;
	packet[UartRESV_1] = 0x00;
	
	packet[BYTE_ADDR1_H] = DISHWASHER_ADDR1_H;
	packet[BYTE_ADDR1_L] = DISHWASHER_ADDR1_L;
	
	packet[BYTE_ADDR2_H] = DISHWASHER_ADDR2_H;
	packet[BYTE_ADDR2_L] = DISHWASHER_ADDR2_L;
	
	packet[BYTE_01_4]= 0x00;
	packet[UartRESV_2]= 0x00;
	
	packet[BYTE_A] = a;
	packet[BYTE_B] = b;
	packet[BYTE_01_5]= 0x00;
	if((msg_body != NULL) && (msg_body_len > 0) )
	{
		memcpy(&packet[UartDATA], msg_body, msg_body_len);
	}
	temp_crc16 = get_checksum(&packet[DATA_FLAG], packet[UartLEN]+3);
	packet[PACKET_LEN_INCLUDE_SYNC + msg_body_len + 0] = temp_crc16 >> 8;
	packet[PACKET_LEN_INCLUDE_SYNC + msg_body_len + 1] = temp_crc16;
	packet[PACKET_LEN_INCLUDE_SYNC + msg_body_len + 2] = SYNC_1;
	packet[PACKET_LEN_INCLUDE_SYNC + msg_body_len + 3] = SYNC_3;
	return PACKET_LEN_INCLUDE_SYNC + msg_body_len + 4;
}



static A_UINT8 ga_uart_tf_pack_buf[RECV_MAX_LEN];

void sc_uart_unpack(A_UINT8* pp_in_buf, A_UINT32 vp_len, uart_pack_handle_callback pp_callback)
{
	static A_UINT32 g_uart_recv_len = 0;
	static int sv_ur_stata = 0;
	static A_UINT8 sv_msg_len = 0;
	static A_UINT8 crc_len = 0;
	static A_UINT8 Result_CRC16_H = 0;
	static A_UINT8 Result_CRC16_L = 0;

	A_UINT32 vl_len = vp_len;
	A_UINT16 temp_crc16 = 0;
	A_UINT8 p_crc1 = 0;
	A_UINT8 p_crc2 = 0;
	A_UINT8 vl_temp = 0;
	A_UINT8 vl_buf_cnt = 0;
	

	while (0 != vl_len)					//接收队列是否有数据
	{

		vl_len--;
		vl_temp = *(pp_in_buf + vl_buf_cnt);
		vl_buf_cnt++;

		if (vl_buf_cnt > vp_len)
		{
			printf("warning: %d", vl_buf_cnt);
			
			vl_buf_cnt = 0;
			g_uart_recv_len = 0;
			sv_ur_stata = 0;
			sv_msg_len = 0;
			crc_len = 0;
			Result_CRC16_H = 0;
			Result_CRC16_L = 0;
		}
			
		switch (sv_ur_stata)
		{
			case UartSOP_1:
			{
				if(vl_temp == SYNC_1)
				{
					ga_uart_tf_pack_buf[g_uart_recv_len++] = vl_temp;
					sv_ur_stata = UartSOP_2;
				}
				else
				{
					sv_ur_stata = 0;
				}
				break;
			}	
			case UartSOP_2:
			{
				if(vl_temp == SYNC_2)
				{
					ga_uart_tf_pack_buf[g_uart_recv_len++] = vl_temp;
					sv_ur_stata = DATA_FLAG;
				}
				else
				{
					sv_ur_stata = 0;
					g_uart_recv_len = 0;
				}
				break;
			}
			case DATA_FLAG:
			{
				ga_uart_tf_pack_buf[g_uart_recv_len++] = vl_temp;
				sv_ur_stata = BYTE_40;
				break;
			}
			case BYTE_40:
			{
				if(vl_temp == BYTE_40_VALUE)
				{
					ga_uart_tf_pack_buf[g_uart_recv_len++] = vl_temp;
					sv_ur_stata = UartLEN;
				}
				else
				{
					sv_ur_stata = 0;
					g_uart_recv_len = 0;
				}
				break;
            }
			case UartLEN:
			{
				if((vl_temp >= PACKET_LEN_ExCLUDE_SYNC) && (vl_temp < RECV_BODY_MAX_LEN))
				{
					ga_uart_tf_pack_buf[g_uart_recv_len++] = vl_temp;
					sv_msg_len = vl_temp - PACKET_LEN_ExCLUDE_SYNC;
	                sv_ur_stata = BYTE_01_1;
					//wapi_uart_send_direct(&sv_msg_len, 1, "len:");
				}
				else
				{
					sv_ur_stata = 0;
					g_uart_recv_len = 0;
					sv_msg_len = 0;
				}
				break;
            }
			case BYTE_01_1:
			{
				ga_uart_tf_pack_buf[g_uart_recv_len++] = vl_temp;
				sv_ur_stata = UartRESV_1;
				break;
			}
			case UartRESV_1:
			{
				ga_uart_tf_pack_buf[g_uart_recv_len++] = vl_temp;
				sv_ur_stata = BYTE_ADDR1_H;
				break;
			}
			case BYTE_ADDR1_H:
			{
                ga_uart_tf_pack_buf[g_uart_recv_len++] = vl_temp;
                sv_ur_stata = BYTE_ADDR1_L;
                break;
            }
			case BYTE_ADDR1_L:
			{
                ga_uart_tf_pack_buf[g_uart_recv_len++] = vl_temp;
                sv_ur_stata = BYTE_ADDR2_H;
                break;
            }
			case BYTE_ADDR2_H:
			{
                ga_uart_tf_pack_buf[g_uart_recv_len++] = vl_temp;
                sv_ur_stata = BYTE_ADDR2_L;
                break;
            }
			case BYTE_ADDR2_L:
			{
				ga_uart_tf_pack_buf[g_uart_recv_len++] = vl_temp;
				sv_ur_stata = BYTE_01_4;
				break;
			}
			case BYTE_01_4:
			{
				ga_uart_tf_pack_buf[g_uart_recv_len++] = vl_temp;
				sv_ur_stata = UartRESV_2;
				break;
			}
			case UartRESV_2:
			{
				ga_uart_tf_pack_buf[g_uart_recv_len++] = vl_temp;
				sv_ur_stata = BYTE_A;
				break;
			}
			case BYTE_A:
			{
				ga_uart_tf_pack_buf[g_uart_recv_len++] = vl_temp;
				sv_ur_stata = BYTE_B;
				break;
			}
			case BYTE_B:
			{
				ga_uart_tf_pack_buf[g_uart_recv_len++] = vl_temp;
				sv_ur_stata = BYTE_01_5;
				break;
			}
			case BYTE_01_5:
			{
				ga_uart_tf_pack_buf[g_uart_recv_len++] = vl_temp;
				sv_ur_stata = UartDATA;
				break;
			}
			case UartDATA:
			{
				if (0 == sv_msg_len)
				{
					sv_ur_stata = UartCRC;
				}
				else if ((sv_msg_len > 0) && (sv_msg_len < RECV_BODY_MAX_LEN))
				{
					ga_uart_tf_pack_buf[g_uart_recv_len++] = vl_temp;
					sv_msg_len--;
					if(sv_msg_len == 0)
					{
						sv_ur_stata = UartCRC;
					}
					break;
				}
				else
				{
					//printf("sv_msg_len error:%d \n", sv_msg_len);
					g_uart_recv_len = 0;
					sv_ur_stata = 0;
					sv_msg_len = 0;
					crc_len = 0;
					Result_CRC16_H = 0;
					Result_CRC16_L = 0;
					break;
				}
			}
			case UartCRC:
			{
				if(crc_len == 0)
				{
					ga_uart_tf_pack_buf[g_uart_recv_len++] = vl_temp;
					Result_CRC16_H = vl_temp;
					crc_len++;
				}
				else if(crc_len == 1)
				{
					ga_uart_tf_pack_buf[g_uart_recv_len++] = vl_temp;
					crc_len = 0;
					sv_ur_stata = SYNC_END_1;
#if 1
					Result_CRC16_L = vl_temp;

					//printf("Result_CRC16_H: %02x, Result_CRC16_L:%02x\n", Result_CRC16_H, Result_CRC16_L);
					temp_crc16 = get_checksum(&ga_uart_tf_pack_buf[DATA_FLAG], ga_uart_tf_pack_buf[UartLEN] + 3);

					p_crc1 = temp_crc16 >> 8;
					p_crc2 = temp_crc16;
					if((Result_CRC16_H == p_crc1) && (Result_CRC16_L == p_crc2))
					{
						//printf("1: %02x,2 : %02x\n", p_crc1, p_crc2);
						crc_len = 0;
						sv_ur_stata = SYNC_END_1;
					}
					else
					{
						printf("Checksum fail!\n");
						sv_ur_stata = 0;
						g_uart_recv_len = 0;
						sv_msg_len = 0;
						crc_len = 0;
						Result_CRC16_H = 0;
						Result_CRC16_L = 0;
					}
#endif
				}
				break;
			}
			case SYNC_END_1:
			{
				if(vl_temp == SYNC_1)
				{
					ga_uart_tf_pack_buf[g_uart_recv_len++] = vl_temp;
					sv_ur_stata = SYNC_END_2;
				}
				break;
			}
			case SYNC_END_2:
			{
				if(vl_temp == SYNC_3)
				{
					ga_uart_tf_pack_buf[g_uart_recv_len++] = vl_temp;

					//WAPI_DUMP_HEX(ga_uart_tf_pack_buf,g_uart_recv_len,"uart recv:");
					pp_callback(ga_uart_tf_pack_buf, g_uart_recv_len);
				}
				
				g_uart_recv_len = 0;
				sv_ur_stata = 0;
				sv_msg_len = 0;
				crc_len = 0;
				Result_CRC16_H = 0;
				Result_CRC16_L = 0;
				
				break;
			}
			default:
				break;
				
		}
	}

}



//7-1
void hisen_get_version_7_1_handle(A_UINT8 *pp_data, A_UINT32 vp_data_len)
{
	printf("7-1\n");
}

//10-4
void hisen_get_dev_address_10_4_handle(A_UINT8 *pp_data, A_UINT32 vp_data_len)
{
	printf("10-4\n");
}


//30-0
void hisen_communication_30_0_handle(A_UINT8 *pp_data, A_UINT32 vp_data_len)
{
	printf("30-0\n");
}

//30-3
void hisen_communication_30_3_handle(A_UINT8 *pp_data, A_UINT32 vp_data_len)
{
	printf("30-3\n");
}


//101-0
void hisen_set_state_101_0_handle(A_UINT8 *pp_data, A_UINT32 vp_data_len)
{
	printf("101-0\n");
}


//102-0
void hisen_get_state_102_0_handle(A_UINT8 *pp_data, A_UINT32 vp_data_len)
{
	printf("102-0\n");
}

//102-64
void hisen_get_state_102_64_handle(A_UINT8 *pp_data, A_UINT32 vp_data_len)
{
	
	printf("102-64\n");
}



void hisen_uart_msg_handle(A_UINT8 *pp_msg, A_UINT32 vp_msg_len)
{
	int post_rawdata_flag = 0;
	A_UINT8 vl_cmd_a;
	A_UINT8 vl_cmd_b;
	vl_cmd_a = *(pp_msg + BYTE_A);
	vl_cmd_b = *(pp_msg + BYTE_B);

	switch(vl_cmd_a)
	{
		case CMD_M_GET_DEV_ADDR:
		{
			if (vl_cmd_b == CMD_S_GET_DEV_ADDR_4)
			{
				hisen_get_dev_address_10_4_handle(pp_msg + UartDATA, vp_msg_len - PACKET_LEN_ExCLUDE_SYNC);
			}
			break;
		}
		
		case CMD_M_GET_VERSION:
		{
			if (vl_cmd_b == CMD_S_GET_VERSION_0)
			{
				hisen_get_version_7_1_handle(pp_msg + UartDATA, vp_msg_len - PACKET_LEN_ExCLUDE_SYNC);
			}
			break;
		}

		case CMD_M_COMMUNICATION:
		{
			if (vl_cmd_b == CMD_S_COMMUNICATION_0)
			{
				hisen_communication_30_0_handle(pp_msg + UartDATA, vp_msg_len - PACKET_LEN_ExCLUDE_SYNC);
			}
			else if (vl_cmd_b == CMD_S_COMMUNICATION_3)
			{
				hisen_communication_30_3_handle(pp_msg + UartDATA, vp_msg_len - PACKET_LEN_ExCLUDE_SYNC);
			}
			
			break;
		}

		case CMD_M_SET_STATE:
		{
			if (vl_cmd_b == CMD_S_SET_STATE_0)
			{
				hisen_set_state_101_0_handle(pp_msg + UartDATA, vp_msg_len - PACKET_LEN_ExCLUDE_SYNC);
			}
			break;
		}
		case CMD_M_GET_STATE:
		{
			if (vl_cmd_b == CMD_S_GET_STATE_0)
			{
				hisen_get_state_102_0_handle(pp_msg + UartDATA, vp_msg_len - PACKET_LEN_ExCLUDE_SYNC);
			}
			else if (vl_cmd_b == CMD_S_GET_STATE_64)
			{
				hisen_get_state_102_64_handle(pp_msg + UartDATA, vp_msg_len - PACKET_LEN_ExCLUDE_SYNC);
			}
			break;
		}

		default:
			break;
	}
}





