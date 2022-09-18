/*
 * @Description: In User Settings Edit
 * @Author: your name
 * @Date: 2019-08-31 09:00:27
 * @LastEditTime: 2019-09-10 15:33:19
 * @LastEditors: Please set LastEditors
 */
#include <stdio.h>
#include <stdlib.h>
#include "hsn_common.h"

typedef unsigned char uint8;
uint8 g_packData[512] = {0};
uint8 g_packOrder[512] = {0};
int g_isFull = 0;
int g_packDataLen = 0;
static void JudgePackOrder(uint8 order, uint8 alen)
{
    int i;
    int totalLen = ((alen * 2) + 2) / 3;

    /* if the first package not come */
    if (alen == 0) {
        return;
    }
    
    for (i = 0; i < totalLen - 1; i++) {
        if (g_packOrder[i] == 0) {
            printf("left package is not full: %d", i);
            return;
        }
    }

    /* if all order have come, set flag */
    g_isFull = 1;
    if (totalLen % 2 == 0) {
        g_packDataLen = totalLen * 3 / 2;
    } else {
        g_packDataLen = totalLen * 3 / 2 + 1;
    }
    return;
}

int base_len_get(uint8 x1, uint8 x2, uint8 x3)
{
    uint8 Ai = 0;
    uint8 Bi = 0;
    uint8 Ci = 0;
    uint8 N2 = 0;

    Ai = (x1 >> 5) << 7;
    Ai = Ai | (x2 & 0x7F);

    Bi = x3 &0x0F;
    Ci = x1 & 0x1F;

    if (((Ai ^ Bi) & 0x1F) != Ci) 
    {
        printf("check code fail \n");
        return -1;
    }

    N2 = (x3 & 0x7F) >> 4;
    /* check code */
    printf("Ai is:%02x, Bi is:%02x, Ci is:%02x, N2 is:%d \n", Ai,Bi,Ci,N2);
    if(N2 == 7)
    {
        return 1;
    }
}

int MulticastProtocolAnalysis(uint8 x1, uint8 x2, uint8 x3, uint8 len)
{
    uint8 Ai = 0;
    uint8 Bi = 0;
    uint8 Ci = 0;
    int N1 =0;
    uint8 N2 = 0;
    int packageOrder;
    int pos;
    static unsigned int Alen = 0;

    if (g_isFull) {
        printf("Pack recv full");
        return 1;
    }

    Ai = (x1 >> 5) << 7;
    Ai = Ai | (x2 & 0x7F);

    Bi = x3 &0x0F;
    Ci = x1 & 0x1F;

    N2 = (x3 & 0x7F) >> 4;
    N1 = len - 1;

    /* check code */
    if (((Ai ^ Bi) & 0x1F) != Ci) {
        printf("check code fail \n");
        return -1;
    }

    printf("Ai is:%02x, Bi is:%02x, Ci is:%02x, N1 is:%d, N2 is:%d \n", Ai,Bi,Ci,N1,N2);

    packageOrder = N1 * 7 + N2;
    if ((N1 == 0) && (N2 == 7)) {
        packageOrder = 0;
        Alen = Ai;
    }

    g_packOrder[packageOrder] = 1; /* set the index value 1 */
    if (packageOrder % 2 == 0) {
        pos = packageOrder * 3 / 2;
        g_packData[pos] = Ai;
        g_packData[pos + 1] = g_packData[pos + 1] | (Bi << 4);
    } else {
        pos = (packageOrder + 1) * 3 / 2 - 2;
        g_packData[pos] = g_packData[pos] | Bi;
        g_packData[pos + 1] = Ai;
    }
    
    JudgePackOrder(0, Alen);
    
    return 0;
}

#if 0
int main(void)
{
    MulticastProtocolAnalysis(0x01, 0x02, 0x73, 1);
    MulticastProtocolAnalysis(0x12, 0x56, 0x14, 1);
    printf("package data is:0x%2x, 0x%02x, 0x%2x \n", g_packData[0], g_packData[1], g_packData[2]);
    printf("isFull:%d, package len:%d", g_isFull, g_packDataLen);
    return 0;
}

#endif
