///////////////////////////////////////////////////////////////////////////////
//
// IAR ANSI C/C++ Compiler V8.30.1.114/W32 for ARM        24/Sep/2021  15:44:19
// Copyright 1999-2018 IAR Systems AB.
//
//    Cpu mode     =  thumb
//    Endian       =  little
//    Source file  =  
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\component\common\utilities\cJSON.c
//    Command line =  
//        -f C:\Users\ADMINI~1\AppData\Local\Temp\EWB45.tmp
//        (F:\lxd\src2\hisen\sdk-ameba-v7.1d\component\common\utilities\cJSON.c
//        -D __thumb2__ -D CONFIG_PLATFORM_8710C -D __ARM_ARCH_8M_MAIN__=1 -D
//        CONFIG_BUILD_RAM=1 -D _NO_DEFINITIONS_IN_HEADER_FILES -D V8M_STKOVF
//        -lb
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\Debug\List\
//        -o
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\Debug\Obj\application_is
//        --no_clustering --debug --endian=little --cpu=Cortex-M33 --cmse
//        --cmse --no_path_in_file_macros -e --char_is_signed --fpu=None
//        --dlib_config "D:\Program Files (x86)\IAR Systems\Embedded Workbench
//        8.1\arm\inc\c\DLib_Config_Normal.h" -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\inc\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\soc\realtek\8710c\cmsis\rtl8710c\include\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\soc\realtek\8710c\cmsis\rtl8710c\lib\include\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\soc\realtek\8710c\fwlib\include\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\soc\realtek\8710c\fwlib\lib\include\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\soc\realtek\8710c\cmsis\cmsis-core\include\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\soc\realtek\8710c\cmsis\rtl8710c\include\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\soc\realtek\8710c\app\rtl_printf\include\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\soc\realtek\8710c\app\shell\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\soc\realtek\8710c\app\stdio_port\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\soc\realtek\8710c\misc\utilities\include\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\os\freertos\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\os\freertos\freertos_v10.0.1\Source\include\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\os\freertos\freertos_v10.0.1\Source\portable\IAR\ARM_RTL8710C\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\common\api\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\common\api\at_cmd\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\common\api\platform\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\common\api\wifi\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\common\api\network\include\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\common\application\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\common\application\mqtt\MQTTClient\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\common\example\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\common\file_system\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\common\file_system\dct\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\common\file_system\ftl\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\common\utilities\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\common\mbed\hal\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\common\mbed\hal_ext\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\common\mbed\targets\hal\rtl8710c\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\soc\realtek\8710c\mbed-drivers\include\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\os\os_dep\include\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\common\network\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\common\network\coap\include\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\common\network\http2\nghttp2-1.31.0\includes\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\common\network\lwip\lwip_v2.0.2\src\include\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\common\network\lwip\lwip_v2.0.2\src\include\lwip\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\common\network\lwip\lwip_v2.0.2\port\realtek\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\common\network\lwip\lwip_v2.0.2\port\realtek\freertos\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\common\api\wifi\rtw_wpa_supplicant\src\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\common\network\ssl\mbedtls-2.4.0\include\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\common\network\ssl\ssl_ram_map\rom\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\common\drivers\wlan\realtek\include\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\common\drivers\wlan\realtek\src\osdep\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\common\mbed\targets\hal\rtl8710c\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\common\test\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\common\bluetooth\realtek\sdk\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\common\bluetooth\realtek\sdk\inc\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\common\bluetooth\realtek\sdk\inc\app\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\common\bluetooth\realtek\sdk\inc\bluetooth\gap\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\common\bluetooth\realtek\sdk\inc\bluetooth\profile\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\common\bluetooth\realtek\sdk\inc\bluetooth\profile\client\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\common\bluetooth\realtek\sdk\inc\bluetooth\profile\server\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\common\bluetooth\realtek\sdk\inc\os\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\common\bluetooth\realtek\sdk\inc\platform\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\common\bluetooth\realtek\sdk\inc\stack\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\common\bluetooth\realtek\sdk\board\amebaz2\lib\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\common\bluetooth\realtek\sdk\board\amebaz2\src\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\common\bluetooth\realtek\sdk\board\amebaz2\src\data_uart\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\common\bluetooth\realtek\sdk\board\amebaz2\src\hci\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\common\bluetooth\realtek\sdk\board\amebaz2\src\os\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\common\bluetooth\realtek\sdk\board\amebaz2\src\vendor_cmd\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\common\bluetooth\realtek\sdk\example\bt_config\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\common\bluetooth\realtek\sdk\example\ble_central\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\common\bluetooth\realtek\sdk\example\ble_peripheral\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\common\bluetooth\realtek\sdk\example\ble_scatternet\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\common\bluetooth\realtek\sdk\src\mcu\module\data_uart_cmd\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\soc\realtek\8710c\misc\platform\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\common\bluetooth\realtek\sdk\board\common\inc\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\soc\realtek\8710c\misc\driver\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\soc\realtek\8710c\misc\os\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\common\drivers\wlan\realtek\src\core\option\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\common\api\wifi\rtw_wpa_supplicant\src\crypto\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\common\file_system\fatfs\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\common\file_system\fatfs\r0.10c\include\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\common\network\libcoap\include\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\common\bluetooth\realtek\sdk\example\bt_mesh\lib\cmd\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\common\bluetooth\realtek\sdk\example\bt_mesh\lib\common\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\common\bluetooth\realtek\sdk\example\bt_mesh\lib\gap\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\common\bluetooth\realtek\sdk\example\bt_mesh\lib\inc\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\common\bluetooth\realtek\sdk\example\bt_mesh\lib\inc\amebaz2\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\common\bluetooth\realtek\sdk\example\bt_mesh\lib\model\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\common\bluetooth\realtek\sdk\example\bt_mesh\lib\model\realtek\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\common\bluetooth\realtek\sdk\example\bt_mesh\lib\platform\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\common\bluetooth\realtek\sdk\example\bt_mesh\lib\profile\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\common\bluetooth\realtek\sdk\example\bt_mesh\provisioner\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\common\bluetooth\realtek\sdk\example\bt_mesh\device\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\common\bluetooth\realtek\sdk\example\bt_mesh_device_rtk_demo\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\common\bluetooth\realtek\sdk\example\bt_mesh_provisioner_rtk_demo\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\common\bluetooth\realtek\sdk\example\bt_mesh_provisioner_rtk_demo\inc\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\common\bluetooth\realtek\sdk\example\bt_mesh\api\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\common\bluetooth\realtek\sdk\example\bt_mesh\api\device\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\common\bluetooth\realtek\sdk\example\bt_mesh\api\provisioner\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\common\media\rtp_codec\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\common\bluetooth\realtek\sdk\example\bt_airsync_config\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\common\application\airsync\1.0.4\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\common\bluetooth\realtek\sdk\example\bt_mesh_multiple_profile\device_multiple_profile\
//        -I
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\..\..\..\component\common\bluetooth\realtek\sdk\example\bt_mesh_multiple_profile\provisioner_multiple_profile\
//        -Ohz --use_c++_inline)
//    Locale       =  C
//    List file    =  
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\Debug\List\cJSON.s
//
///////////////////////////////////////////////////////////////////////////////

        #define SHT_PROGBITS 0x1

        EXTERN __aeabi_cdcmple
        EXTERN __aeabi_cdrcmple
        EXTERN __aeabi_d2iz
        EXTERN __aeabi_dadd
        EXTERN __aeabi_dmul
        EXTERN __aeabi_dsub
        EXTERN __aeabi_f2d
        EXTERN __aeabi_i2d
        EXTERN __aeabi_memcpy
        EXTERN __aeabi_memset
        EXTERN floor
        EXTERN free
        EXTERN malloc
        EXTERN memcpy
        EXTERN memset
        EXTERN pow
        EXTERN sprintf
        EXTERN strchr
        EXTERN strcpy
        EXTERN strlen
        EXTERN strncmp

        PUBLIC cJSON_AddItemReferenceToArray
        PUBLIC cJSON_AddItemReferenceToObject
        PUBLIC cJSON_AddItemToArray
        PUBLIC cJSON_AddItemToObject
        PUBLIC cJSON_CreateArray
        PUBLIC cJSON_CreateBool
        PUBLIC cJSON_CreateDoubleArray
        PUBLIC cJSON_CreateFalse
        PUBLIC cJSON_CreateFloatArray
        PUBLIC cJSON_CreateIntArray
        PUBLIC cJSON_CreateNull
        PUBLIC cJSON_CreateNumber
        PUBLIC cJSON_CreateObject
        PUBLIC cJSON_CreateString
        PUBLIC cJSON_CreateStringArray
        PUBLIC cJSON_CreateTrue
        PUBLIC cJSON_Delete
        PUBLIC cJSON_DeleteItemFromArray
        PUBLIC cJSON_DeleteItemFromObject
        PUBLIC cJSON_DetachItemFromArray
        PUBLIC cJSON_DetachItemFromObject
        PUBLIC cJSON_Duplicate
        PUBLIC cJSON_GetArrayItem
        PUBLIC cJSON_GetArraySize
        PUBLIC cJSON_GetErrorPtr
        PUBLIC cJSON_GetObjectItem
        PUBLIC cJSON_InitHooks
        PUBLIC cJSON_Minify
        PUBLIC cJSON_Parse
        PUBLIC cJSON_ParseWithOpts
        PUBLIC cJSON_Print
        PUBLIC cJSON_PrintUnformatted
        PUBLIC cJSON_ReplaceItemInArray
        PUBLIC cJSON_ReplaceItemInObject
        PUBLIC parse_number


        SECTION `.bss`:DATA:REORDER:NOROOT(2)
        DATA
ep:
        DS8 4

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
cJSON_GetErrorPtr:
        LDR.W    R0,??DataTable12_4
        LDR      R0,[R0, #+0]
        BX       LR               ;; return

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
cJSON_strcasecmp:
        PUSH     {R4,R5,LR}
        CBNZ.N   R0,??cJSON_strcasecmp_0
        CBZ.N    R1,??cJSON_strcasecmp_1
        B.N      ??cJSON_strcasecmp_2
??cJSON_strcasecmp_0:
        CBNZ.N   R1,??cJSON_strcasecmp_3
??cJSON_strcasecmp_2:
        MOVS     R0,#+1
        POP      {R4,R5,PC}
??cJSON_strcasecmp_4:
        ADDS     R1,R1,#+1
??cJSON_strcasecmp_3:
        LDRSB    R2,[R0, #+0]
        LDRSB    R4,[R1, #+0]
        SUB      R3,R2,#+65
        CMP      R3,#+26
        SUB      R5,R4,#+65
        ITE      CC 
        MOVCC    R3,#+32
        MOVCS    R3,#+0
        CMP      R5,#+26
        ITE      CC 
        MOVCC    R5,#+32
        MOVCS    R5,#+0
        ADDS     R2,R3,R2
        ADDS     R4,R5,R4
        CMP      R2,R4
        BNE.N    ??cJSON_strcasecmp_5
        LDRSB    R2,[R0], #+1
        CMP      R2,#+0
        BNE.N    ??cJSON_strcasecmp_4
        MOVS     R0,#+0
        POP      {R4,R5,PC}
??cJSON_strcasecmp_6:
        LDRB     R2,[R1, #+0]
        LDRB     R4,[R0, #+0]
        LDRB     R0,[R1, #+0]
        SUBS     R2,R2,#+65
        CMP      R2,#+26
        ITE      CC 
        MOVCC    R2,#+32
        MOVCS    R2,#+0
        ADDS     R3,R3,R4
        SUBS     R3,R3,R0
        SUBS     R0,R3,R2
??cJSON_strcasecmp_1:
        POP      {R4,R5,PC}       ;; return
??cJSON_strcasecmp_5:
        LDRB     R2,[R0, #+0]
        SUBS     R2,R2,#+65
        CMP      R2,#+26
        ITE      CC 
        MOVCC    R3,#+32
        MOVCS    R3,#+0
        B.N      ??cJSON_strcasecmp_6

        SECTION `.data`:DATA:REORDER:NOROOT(2)
        DATA
cJSON_malloc:
        DC32 malloc

        SECTION `.data`:DATA:REORDER:NOROOT(2)
        DATA
cJSON_free:
        DC32 free

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
cJSON_strdup:
        PUSH     {R4-R6,LR}
        MOV      R5,R0
        BL       strlen
        BL       ?Subroutine3
??CrossCallReturnLabel_0:
        ADDS     R6,R0,#+1
        MOV      R0,R6
        BLX      R2
        MOVS     R4,R0
        BNE.N    ??cJSON_strdup_0
        MOVS     R0,#+0
        POP      {R4-R6,PC}
??cJSON_strdup_0:
        MOV      R2,R6
        MOV      R1,R5
        BL       memcpy
        MOV      R0,R4
        POP      {R4-R6,PC}       ;; return

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
cJSON_InitHooks:
        PUSH     {R4,R5,LR}
        LDR.W    R2,??DataTable13
        LDR.W    R3,??DataTable13_1
        LDR.W    R4,??DataTable13_2
        LDR.W    R5,??DataTable13_3
        CBNZ.N   R0,??cJSON_InitHooks_0
        STR      R5,[R4, #+0]
        B.N      ??cJSON_InitHooks_1
??cJSON_InitHooks_0:
        LDR      R1,[R0, #+0]
        CBZ.N    R1,??cJSON_InitHooks_2
        MOV      R5,R1
??cJSON_InitHooks_2:
        STR      R5,[R4, #+0]
        LDR      R0,[R0, #+4]
        CBZ.N    R0,??cJSON_InitHooks_1
        MOV      R3,R0
??cJSON_InitHooks_1:
        STR      R3,[R2, #+0]
        POP      {R4,R5,PC}       ;; return

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
cJSON_New_Item:
        PUSH     {R4,LR}
        BL       ?Subroutine3
??CrossCallReturnLabel_1:
        MOVS     R0,#+40
        BLX      R2
        MOVS     R4,R0
        BEQ.N    ??cJSON_New_Item_0
        MOVS     R2,#+40
        MOVS     R1,#+0
        BL       memset
??cJSON_New_Item_0:
        MOV      R0,R4
        POP      {R4,PC}          ;; return

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
cJSON_Delete:
        PUSH     {R4-R6,LR}
        MOVS     R5,R0
        LDR.W    R6,??DataTable13
        B.N      ??cJSON_Delete_0
??cJSON_Delete_1:
        LDR      R0,[R5, #+12]
        LDR      R4,[R5, #+0]
        LSLS     R1,R0,#+23
        BMI.N    ??cJSON_Delete_2
        LDR      R0,[R5, #+8]
        CBZ.N    R0,??cJSON_Delete_2
        BL       cJSON_Delete
??cJSON_Delete_2:
        LDR      R0,[R5, #+12]
        LSLS     R1,R0,#+23
        BMI.N    ??cJSON_Delete_3
        LDR      R0,[R5, #+16]
        CBZ.N    R0,??cJSON_Delete_3
        LDR      R1,[R6, #+0]
        BLX      R1
??cJSON_Delete_3:
        LDR      R0,[R5, #+32]
        CBZ.N    R0,??cJSON_Delete_4
        LDR      R1,[R6, #+0]
        BLX      R1
??cJSON_Delete_4:
        LDR      R2,[R6, #+0]
        MOV      R0,R5
        BLX      R2
        MOVS     R5,R4
??cJSON_Delete_0:
        BNE.N    ??cJSON_Delete_1
        POP      {R4-R6,PC}       ;; return

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
parse_number:
        PUSH     {R0,R4-R11,LR}
        MOV      R6,R1
        SUB      SP,SP,#+24
        MOVS     R3,#+0
        MOVS     R1,#+1
        LDR.W    R5,??DataTable13_4  ;; 0xbff00000
        STR      R1,[SP, #+0]
        MOVS     R2,#+0
        STRD     R2,R3,[SP, #+8]
        STRD     R2,R5,[SP, #+16]
        LDRSB    R1,[R6, R2]
        MOVS     R7,#+0
        MOV      R10,R2
        LDR.W    R11,??DataTable14  ;; 0x3ff00000
        CMP      R1,#+45
        ITT      EQ 
        LDRDEQ   R10,R11,[SP, #+16]
        ADDEQ    R6,R6,#+1
        LDRSB    R0,[R6, R2]
        CMP      R0,#+48
        IT       EQ 
        ADDEQ    R6,R6,#+1
        LDRSB    R0,[R6, R2]
        SUBS     R0,R0,#+49
        CMP      R0,#+9
        BCS.N    ??parse_number_0
        MOVS     R0,#+0
        MOVS     R1,#+0
??parse_number_1:
        MOVS     R2,#+0
        LDR.W    R3,??DataTable14_1  ;; 0x40240000
        BL       __aeabi_dmul
        MOV      R4,R0
        LDRSB    R0,[R6, R7]
        MOV      R5,R1
        SUBS     R0,R0,#+48
        BL       __aeabi_i2d
        MOV      R2,R4
        MOV      R3,R5
        BL       __aeabi_dadd
        LDRSB    R4,[R6, #+1]!
        SUBS     R4,R4,#+48
        CMP      R4,#+9
        BLS.N    ??parse_number_1
        MOV      R2,R0
        MOV      R3,R1
??parse_number_0:
        LDRSB    R0,[R6, R7]
        CMP      R0,#+46
        BNE.N    ??parse_number_2
        LDRSB    R0,[R6, #+1]
        SUBS     R0,R0,#+48
        CMP      R0,#+9
        BHI.N    ??parse_number_2
        ADDS     R6,R6,#+1
        MOV      R8,R2
        MOV      R9,R3
        LDRD     R4,R5,[SP, #+8]
??parse_number_3:
        MOVS     R0,#+0
        LDR.W    R1,??DataTable14_1  ;; 0x40240000
        MOV      R2,R8
        MOV      R3,R9
        BL       __aeabi_dmul
        MOV      R8,R0
        LDRSB    R0,[R6, R7]
        MOV      R9,R1
        SUBS     R0,R0,#+48
        BL       __aeabi_i2d
        MOV      R2,R8
        MOV      R3,R9
        BL       __aeabi_dadd
        MOV      R8,R0
        MOV      R9,R1
        LDRD     R0,R1,[SP, #+16]
        MOV      R2,R4
        MOV      R3,R5
        BL       __aeabi_dadd
        MOV      R4,R0
        LDRSB    R0,[R6, #+1]!
        MOV      R5,R1
        SUBS     R0,R0,#+48
        CMP      R0,#+9
        BLS.N    ??parse_number_3
        MOV      R2,R8
        MOV      R3,R9
        STRD     R4,R5,[SP, #+8]
??parse_number_2:
        LDRSB    R0,[R6, R7]
        CMP      R0,#+101
        IT       NE 
        CMPNE    R0,#+69
        BNE.N    ??parse_number_4
        LDRSB    R0,[R6, #+1]!
        CMP      R0,#+43
        BEQ.N    ??parse_number_5
        CMP      R0,#+45
        BNE.N    ??parse_number_6
        MOV      R1,#-1
        STR      R1,[SP, #+0]
??parse_number_5:
        ADDS     R6,R6,#+1
        B.N      ??parse_number_6
??parse_number_7:
        LDRSB    R1,[R6], #+1
        MOVS     R0,#+10
        MLA      R7,R0,R7,R1
        SUBS     R7,R7,#+48
??parse_number_6:
        LDRSB    R0,[R6, #+0]
        SUBS     R0,R0,#+48
        CMP      R0,#+9
        BLS.N    ??parse_number_7
??parse_number_4:
        LDR      R4,[SP, #+24]
        MOV      R0,R10
        MOV      R1,R11
        BL       __aeabi_dmul
        MOV      R5,R0
        LDR      R0,[SP, #+0]
        MOV      R9,R1
        MULS     R0,R0,R7
        BL       __aeabi_i2d
        LDRD     R2,R3,[SP, #+8]
        BL       __aeabi_dadd
        MOV      R2,R0
        MOV      R3,R1
        MOVS     R0,#+0
        LDR.W    R1,??DataTable14_1  ;; 0x40240000
        BL       pow
        MOV      R2,R5
        MOV      R3,R9
        BL       __aeabi_dmul
        STRD     R0,R1,[R4, #+24]
        BL       __aeabi_d2iz
        STR      R0,[R4, #+20]
        MOVS     R0,#+3
        STR      R0,[R4, #+12]
        MOV      R0,R6
        ADD      SP,SP,#+28
        POP      {R4-R11,PC}      ;; return

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
parse_hex4:
        MOV      R1,R0
        LDRSB    R0,[R1, #+0]
        SUB      R2,R0,#+48
        CMP      R2,#+10
        IT       CC 
        SUBCC    R0,R0,#+48
        BCC.N    ??parse_hex4_0
        SUB      R2,R0,#+65
        CMP      R2,#+6
        IT       CC 
        SUBCC    R0,R0,#+55
        BCC.N    ??parse_hex4_0
        SUB      R2,R0,#+97
        CMP      R2,#+6
        BCS.N    ??parse_hex4_1
        SUBS     R0,R0,#+87
??parse_hex4_0:
        LDRSB    R2,[R1, #+1]
        SUB      R3,R2,#+48
        CMP      R3,#+10
        IT       CC 
        SUBCC    R2,R2,#+48
        BCC.N    ??parse_hex4_2
        SUB      R3,R2,#+65
        CMP      R3,#+6
        IT       CC 
        SUBCC    R2,R2,#+55
        BCC.N    ??parse_hex4_2
        SUB      R3,R2,#+97
        CMP      R3,#+6
        BCS.N    ??parse_hex4_1
        SUBS     R2,R2,#+87
??parse_hex4_2:
        ADD      R0,R2,R0, LSL #+4
        LDRSB    R2,[R1, #+2]
        SUB      R3,R2,#+48
        CMP      R3,#+10
        IT       CC 
        SUBCC    R2,R2,#+48
        BCC.N    ??parse_hex4_3
        SUB      R3,R2,#+65
        CMP      R3,#+6
        IT       CC 
        SUBCC    R2,R2,#+55
        BCC.N    ??parse_hex4_3
        SUB      R3,R2,#+97
        CMP      R3,#+6
        BCS.N    ??parse_hex4_1
        SUBS     R2,R2,#+87
??parse_hex4_3:
        LDRSB    R1,[R1, #+3]
        ADD      R0,R2,R0, LSL #+4
        SUB      R2,R1,#+48
        CMP      R2,#+10
        BCS.N    ??parse_hex4_4
        SUBS     R1,R1,#+48
??parse_hex4_5:
        ADD      R0,R1,R0, LSL #+4
        BX       LR               ;; return
??parse_hex4_4:
        SUB      R2,R1,#+65
        CMP      R2,#+6
        IT       CC 
        SUBCC    R1,R1,#+55
        BCC.N    ??parse_hex4_5
        SUB      R2,R1,#+97
        CMP      R2,#+6
        IT       CC 
        SUBCC    R1,R1,#+87
        BCC.N    ??parse_hex4_5
??parse_hex4_1:
        MOVS     R0,#+0
        BX       LR

        SECTION `.rodata`:CONST:REORDER:NOROOT(2)
        DATA
        DC8 "%d"
        DC8 0

        SECTION `.rodata`:CONST:REORDER:NOROOT(2)
        DATA
?_1:
        DC8 "%.0f"
        DC8 0, 0, 0

        SECTION `.rodata`:CONST:REORDER:NOROOT(2)
        DATA
        DC8 "%e"
        DC8 0

        SECTION `.rodata`:CONST:REORDER:NOROOT(2)
        DATA
        DC8 "%f"
        DC8 0

        SECTION `.rodata`:CONST:REORDER:NOROOT(0)
        DATA
        DC8 ""

        SECTION `.rodata`:CONST:REORDER:NOROOT(2)
        DATA
?_5:
        DC8 "\"\\\010\014\012\015\t"

        SECTION `.rodata`:CONST:REORDER:NOROOT(2)
        DATA
?_6:
        DC8 "u%04x"
        DC8 0, 0

        SECTION `.rodata`:CONST:REORDER:NOROOT(2)
        DATA
?_7:
        DC8 "null"
        DC8 0, 0, 0

        SECTION `.rodata`:CONST:REORDER:NOROOT(2)
        DATA
?_8:
        DC8 "false"
        DC8 0, 0

        SECTION `.rodata`:CONST:REORDER:NOROOT(2)
        DATA
?_9:
        DC8 "true"
        DC8 0, 0, 0

        SECTION `.rodata`:CONST:REORDER:NOROOT(2)
        DATA
        DC8 "[]"
        DC8 0

        SECTION `.rodata`:CONST:REORDER:NOROOT(2)
        DATA
firstByteMark:
        DC8 0, 0, 192, 224, 240, 248, 252, 0

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
parse_string:
        PUSH     {R4-R10,LR}
        MOV      R6,R0
        MOV      R4,R1
        MOVS     R1,#+0
        LDRSB    R0,[R4, R1]
        ADDS     R2,R4,#+1
        CMP      R0,#+34
        BEQ.N    ??parse_string_0
        LDR.W    R1,??DataTable12_4
        STR      R4,[R1, #+0]
        B.N      ??parse_string_1
??parse_string_2:
        LDRSB    R0,[R2], #+1
        CMP      R0,#+92
        IT       EQ 
        ADDEQ    R2,R2,#+1
??parse_string_0:
        LDRSB    R0,[R2, #+0]
        CMP      R0,#+34
        IT       NE 
        CMPNE    R0,#+0
        BEQ.N    ??parse_string_3
        ADDS     R1,R1,#+1
        BNE.N    ??parse_string_2
??parse_string_3:
        ADDS     R0,R1,#+1
        BL       ?Subroutine3
??CrossCallReturnLabel_2:
        BLX      R2
        MOVS     R8,R0
        BNE.N    ??parse_string_4
??parse_string_1:
        MOVS     R0,#+0
        B.N      ??parse_string_5
??parse_string_4:
        ADDS     R5,R4,#+1
        MOV      R7,R8
        LDR.W    R9,??DataTable15
        MOVW     R10,#+1023
        B.N      ??parse_string_6
??parse_string_7:
        LDRB     R0,[R5], #+1
        STRB     R0,[R7], #+1
??parse_string_6:
        LDRSB    R0,[R5, #+0]
        CMP      R0,#+34
        IT       NE 
        CMPNE    R0,#+0
        BEQ.N    ??parse_string_8
        CMP      R0,#+92
        BNE.N    ??parse_string_7
        LDRSB    R0,[R5, #+1]!
        CMP      R0,#+98
        BEQ.N    ??parse_string_9
        CMP      R0,#+102
        BEQ.N    ??parse_string_10
        CMP      R0,#+110
        BEQ.N    ??parse_string_11
        CMP      R0,#+114
        BEQ.N    ??parse_string_12
        CMP      R0,#+116
        BEQ.N    ??parse_string_13
        CMP      R0,#+117
        BEQ.N    ??parse_string_14
        B.N      ??parse_string_15
??parse_string_9:
        MOVS     R1,#+8
        B.N      ??parse_string_16
??parse_string_10:
        MOVS     R0,#+12
        B.N      ??parse_string_17
??parse_string_11:
        MOVS     R1,#+10
        B.N      ??parse_string_16
??parse_string_12:
        MOVS     R0,#+13
        B.N      ??parse_string_17
??parse_string_13:
        MOVS     R1,#+9
??parse_string_16:
        STRB     R1,[R7], #+1
        B.N      ??parse_string_18
??parse_string_14:
        ADDS     R0,R5,#+1
        BL       parse_hex4
        MOV      R4,R0
        ADDS     R5,R5,#+4
        SUB      R0,R4,#+56320
        CMP      R0,R10
        BLS.N    ??parse_string_18
        CMP      R4,#+0
        BEQ.N    ??parse_string_18
        SUB      R0,R4,#+55296
        CMP      R0,R10
        BHI.N    ??parse_string_19
        LDRSB    R1,[R5, #+1]
        CMP      R1,#+92
        ITT      EQ 
        LDRSBEQ  R0,[R5, #+2]
        CMPEQ    R0,#+117
        BNE.N    ??parse_string_18
        ADDS     R0,R5,#+3
        BL       parse_hex4
        ADDS     R5,R5,#+6
        SUB      R1,R0,#+56320
        CMP      R1,R10
        BHI.N    ??parse_string_18
        LDR.W    R2,??DataTable15_1  ;; 0xffc00
        AND      R4,R2,R4, LSL #+10
        UBFX     R0,R0,#+0,#+10
        ORRS     R4,R0,R4
        ADD      R4,R4,#+65536
??parse_string_19:
        MOVS     R0,#+4
        CMP      R4,#+128
        BCS.N    ??parse_string_20
        MOVS     R0,#+1
        ADDS     R7,R7,#+1
        B.N      ??CrossCallReturnLabel_17
??parse_string_20:
        CMP      R4,#+2048
        BCS.N    ??parse_string_21
        MOVS     R0,#+2
        ADDS     R7,R7,#+2
        B.N      ??CrossCallReturnLabel_16
??parse_string_21:
        CMP      R4,#+65536
        BCC.N    ??parse_string_22
        BIC      R1,R4,#0x40
        ORN      R1,R1,#+127
        STRB     R1,[R7, #+3]!
        LSRS     R4,R4,#+6
        B.N      ??parse_string_23
??parse_string_22:
        MOVS     R0,#+3
        ADDS     R7,R7,#+3
??parse_string_23:
        BL       ?Subroutine7
??CrossCallReturnLabel_16:
        BL       ?Subroutine7
??CrossCallReturnLabel_17:
        LDRSB    R1,[R9, R0]
        ORRS     R4,R1,R4
        STRB     R4,[R7, #-1]!
        ADDS     R7,R7,R0
        B.N      ??parse_string_18
??parse_string_15:
        LDRB     R0,[R5, #+0]
??parse_string_17:
        STRB     R0,[R7], #+1
??parse_string_18:
        ADDS     R5,R5,#+1
        B.N      ??parse_string_6
??parse_string_8:
        MOVS     R0,#+0
        STRB     R0,[R7, #+0]
        LDRSB    R1,[R5, R0]
        STR      R8,[R6, #+16]
        CMP      R1,#+34
        IT       EQ 
        ADDEQ    R5,R5,#+1
        MOVS     R0,#+4
        STR      R0,[R6, #+12]
        MOV      R0,R5
??parse_string_5:
        POP      {R4-R10,PC}      ;; return

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
?Subroutine7:
        BIC      R1,R4,#0x40
        ORN      R1,R1,#+127
        STRB     R1,[R7, #-1]!
        LSRS     R4,R4,#+6
        BX       LR

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
?Subroutine3:
        LDR.W    R1,??DataTable13_2
        LDR      R2,[R1, #+0]
        BX       LR

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
print_string_ptr:
        PUSH     {R4-R8,LR}
        MOV      R6,R0
        MOVS     R5,#+0
        CBNZ.N   R6,??print_string_ptr_0
        ADR.N    R0,??DataTable8  ;; ""
        POP      {R4-R8,LR}
        B.N      cJSON_strdup
??print_string_ptr_0:
        MOV      R7,R6
        LDR.W    R8,??DataTable15_2
??print_string_ptr_1:
        LDRSB    R4,[R7, #+0]
        UXTB     R4,R4
        CMP      R4,#+0
        BEQ.N    ??print_string_ptr_2
        ADDS     R5,R5,#+1
        BEQ.N    ??print_string_ptr_2
        MOV      R1,R4
        MOV      R0,R8
        BL       strchr
        CBNZ.N   R0,??print_string_ptr_3
        CMP      R4,#+32
        BGE.N    ??print_string_ptr_4
        ADDS     R5,R5,#+5
        B.N      ??print_string_ptr_4
??print_string_ptr_3:
        ADDS     R5,R5,#+1
??print_string_ptr_4:
        ADDS     R7,R7,#+1
        B.N      ??print_string_ptr_1
??print_string_ptr_5:
        MOV      R5,R4
        MOVS     R0,#+34
        STRB     R0,[R5], #+1
        LDR.W    R7,??DataTable15_3
        B.N      ??print_string_ptr_6
??print_string_ptr_7:
        LDRB     R1,[R6], #+1
??print_string_ptr_8:
        STRB     R1,[R5], #+1
??print_string_ptr_6:
        LDRSB    R0,[R6, #+0]
        CMP      R0,#+0
        BEQ.N    ??print_string_ptr_9
        UXTB     R1,R0
        CMP      R1,#+32
        BLT.N    ??print_string_ptr_10
        CMP      R0,#+34
        IT       NE 
        CMPNE    R0,#+92
        BNE.N    ??print_string_ptr_7
??print_string_ptr_10:
        MOVS     R0,#+92
        STRB     R0,[R5], #+1
        LDRSB    R2,[R6], #+1
        UXTB     R2,R2
        CMP      R2,#+8
        BEQ.N    ??print_string_ptr_11
        CMP      R2,#+9
        BEQ.N    ??print_string_ptr_12
        CMP      R2,#+10
        BEQ.N    ??print_string_ptr_13
        CMP      R2,#+12
        BEQ.N    ??print_string_ptr_14
        CMP      R2,#+13
        BEQ.N    ??print_string_ptr_15
        CMP      R2,#+34
        BEQ.N    ??print_string_ptr_16
        CMP      R2,#+92
        BNE.N    ??print_string_ptr_17
        STRB     R2,[R5], #+1
        B.N      ??print_string_ptr_6
??print_string_ptr_16:
        MOVS     R0,#+34
??print_string_ptr_18:
        STRB     R0,[R5], #+1
        B.N      ??print_string_ptr_6
??print_string_ptr_11:
        MOVS     R1,#+98
        B.N      ??print_string_ptr_8
??print_string_ptr_14:
        MOVS     R0,#+102
        B.N      ??print_string_ptr_18
??print_string_ptr_13:
        MOVS     R1,#+110
        B.N      ??print_string_ptr_8
??print_string_ptr_15:
        MOVS     R0,#+114
        B.N      ??print_string_ptr_18
??print_string_ptr_12:
        MOVS     R1,#+116
        B.N      ??print_string_ptr_8
??print_string_ptr_17:
        MOV      R1,R7
        MOV      R0,R5
        BL       sprintf
        ADDS     R5,R5,#+5
        B.N      ??print_string_ptr_6
??print_string_ptr_2:
        BL       ?Subroutine3
??CrossCallReturnLabel_3:
        ADDS     R0,R5,#+3
        BLX      R2
        MOVS     R4,R0
        BNE.N    ??print_string_ptr_5
        MOVS     R0,#+0
        B.N      ??print_string_ptr_19
??print_string_ptr_9:
        MOVS     R0,#+34
        STRB     R0,[R5, #+0]
        MOVS     R1,#+0
        STRB     R1,[R5, #+1]
        MOV      R0,R4
??print_string_ptr_19:
        POP      {R4-R8,PC}       ;; return

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
skip:
??skip_0:
        CBZ.N    R0,??skip_1
        LDRSB    R1,[R0, #+0]
        CBZ.N    R1,??skip_1
        UXTB     R1,R1
        CMP      R1,#+33
        BGE.N    ??skip_1
        ADDS     R0,R0,#+1
        B.N      ??skip_0
??skip_1:
        BX       LR               ;; return

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
cJSON_ParseWithOpts:
        PUSH     {R4-R8,LR}
        MOV      R6,R0
        MOV      R4,R1
        MOV      R8,R2
        BL       cJSON_New_Item
        MOV      R5,R0
        LDR.W    R7,??DataTable15_4
        MOVS     R0,#+0
        STR      R0,[R7, #+0]
        CBZ.N    R5,??cJSON_ParseWithOpts_0
        MOV      R0,R6
        BL       skip
        MOV      R1,R0
        MOV      R0,R5
        BL       parse_value
        MOVS     R6,R0
        BNE.N    ??cJSON_ParseWithOpts_1
        MOV      R0,R5
        BL       cJSON_Delete
        B.N      ??cJSON_ParseWithOpts_2
??cJSON_ParseWithOpts_1:
        CMP      R8,#+0
        BEQ.N    ??cJSON_ParseWithOpts_3
        BL       skip
        MOV      R6,R0
        LDRSB    R0,[R6, #+0]
        CBZ.N    R0,??cJSON_ParseWithOpts_3
        MOV      R0,R5
        BL       cJSON_Delete
        STR      R6,[R7, #+0]
??cJSON_ParseWithOpts_2:
        MOVS     R0,#+0
        B.N      ??cJSON_ParseWithOpts_0
??cJSON_ParseWithOpts_3:
        CBZ.N    R4,??cJSON_ParseWithOpts_4
        STR      R6,[R4, #+0]
??cJSON_ParseWithOpts_4:
        MOV      R0,R5
??cJSON_ParseWithOpts_0:
        POP      {R4-R8,PC}       ;; return

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
cJSON_Parse:
        MOVS     R2,#+0
        MOVS     R1,#+0
        B.N      cJSON_ParseWithOpts

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
cJSON_Print:
        MOVS     R2,#+1
        B.N      ?Subroutine1

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
cJSON_PrintUnformatted:
        MOVS     R2,#+0
        REQUIRE ?Subroutine1
        ;; // Fall through to label ?Subroutine1

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
?Subroutine1:
        MOVS     R1,#+0
        B.N      print_value

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
parse_value:
        PUSH     {R3-R7,LR}
        MOV      R7,R0
        MOVS     R4,R1
        BEQ.N    ??parse_value_0
        MOVS     R2,#+4
        LDR.W    R1,??DataTable15_5
        MOV      R0,R4
        BL       strncmp
        CBNZ.N   R0,??parse_value_1
        MOVS     R0,#+2
        STR      R0,[R7, #+12]
        B.N      ??parse_value_2
??parse_value_1:
        MOVS     R2,#+5
        LDR.W    R1,??DataTable15_6
        MOV      R0,R4
        BL       strncmp
        CBNZ.N   R0,??parse_value_3
        STR      R0,[R7, #+12]
        ADDS     R0,R4,#+5
        POP      {R1,R4-R7,PC}
??parse_value_3:
        MOVS     R2,#+4
        LDR.W    R1,??DataTable15_7
        MOV      R0,R4
        BL       strncmp
        CBNZ.N   R0,??parse_value_4
        MOVS     R0,#+1
        STR      R0,[R7, #+12]
        STR      R0,[R7, #+20]
??parse_value_2:
        ADDS     R0,R4,#+4
        POP      {R1,R4-R7,PC}
??parse_value_4:
        LDRSB    R0,[R4, #+0]
        CMP      R0,#+34
        BNE.N    ??parse_value_5
        MOV      R1,R4
        MOV      R0,R7
        POP      {R2,R4-R7,LR}
        B.N      parse_string
??parse_value_5:
        CMP      R0,#+45
        BEQ.N    ??parse_value_6
        SUB      R1,R0,#+48
        CMP      R1,#+10
        BCS.N    ??parse_value_7
??parse_value_6:
        MOV      R1,R4
        MOV      R0,R7
        POP      {R2,R4-R7,LR}
        B.N      parse_number
??parse_value_7:
        LDR.W    R6,??DataTable15_4
        CMP      R0,#+91
        BNE.N    ??parse_value_8
        BNE.N    ??parse_value_9
        MOVS     R1,#+5
        STR      R1,[R7, #+12]
        BL       ??Subroutine8_0
??CrossCallReturnLabel_21:
        MOV      R4,R0
        LDRSB    R0,[R4, #+0]
        CMP      R0,#+93
        BEQ.N    ??parse_value_10
        BL       cJSON_New_Item
        MOVS     R5,R0
        STR      R5,[R7, #+8]
        BEQ.N    ??parse_value_0
        MOV      R0,R4
        BL       skip
        BL       ?Subroutine5
??CrossCallReturnLabel_11:
        BL       skip
        MOVS     R4,R0
        BEQ.N    ??parse_value_0
??parse_value_11:
        LDRSB    R0,[R4, #+0]
        CMP      R0,#+44
        BNE.N    ??parse_value_12
        BL       cJSON_New_Item
        CBZ.N    R0,??parse_value_0
        BL       ?Subroutine8
??CrossCallReturnLabel_23:
        BL       ?Subroutine5
??CrossCallReturnLabel_10:
        BL       skip
        MOVS     R4,R0
        BNE.N    ??parse_value_11
        B.N      ??parse_value_0
??parse_value_8:
        CMP      R0,#+123
        BNE.N    ??parse_value_9
        MOV      R1,R4
        MOV      R0,R7
        POP      {R2,R4-R7,LR}
        B.N      parse_object
??parse_value_9:
        STR      R4,[R6, #+0]
??parse_value_0:
        MOVS     R0,#+0
        POP      {R1,R4-R7,PC}    ;; return
??parse_value_12:
        CMP      R0,#+93
        BNE.N    ??parse_value_9
??parse_value_10:
        ADDS     R0,R4,#+1
        POP      {R1,R4-R7,PC}

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable8:
        DC8      "",0x0,0x0,0x0

        SECTION `.text`:CODE:NOROOT(2)
        THUMB
print_value:
        PUSH     {R3-R7,LR}
        MOV      R7,R0
        MOVS     R6,#+0
        CMP      R7,#+0
        BEQ.W    ??print_value_1
        LDR      R0,[R7, #+12]
        UXTB     R0,R0
        CMP      R0,#+6
        BHI.N    ??print_value_2
        TBB      [PC, R0]
        DATA
??print_value_0:
        DC8      0x7,0xA,0x4,0xF
        DC8      0x6F,0x73,0x77,0x0
        THUMB
??print_value_3:
        LDR.W    R0,??DataTable15_5
        B.N      ??print_value_4
??print_value_5:
        LDR.W    R0,??DataTable15_6
        B.N      ??print_value_4
??print_value_6:
        LDR.W    R0,??DataTable15_7
??print_value_4:
        BL       cJSON_strdup
        B.N      ??print_value_7
??print_value_8:
        LDR      R0,[R7, #+20]
        LDR.W    R6,??DataTable13_2
        LDRD     R4,R5,[R7, #+24]
        LDR      R6,[R6, #+0]
        BL       __aeabi_i2d
        MOV      R2,R4
        MOV      R3,R5
        BL       __aeabi_dsub
        BL       ?Subroutine9
??CrossCallReturnLabel_24:
        BCS.N    ??print_value_9
        MOV      R0,R4
        MOV      R1,R5
        LDR.W    R2,??DataTable15_8  ;; 0xffc00001
        LDR.W    R3,??DataTable15_9  ;; 0x41dfffff
        BL       __aeabi_cdcmple
        BCS.N    ??print_value_9
        MOVS     R2,#+0
        LDR.W    R3,??DataTable15_10  ;; 0xc1e00000
        BL       __aeabi_cdrcmple
        BHI.N    ??print_value_9
        MOVS     R0,#+21
        BLX      R6
        MOVS     R6,R0
        BEQ.N    ??print_value_10
        LDR      R2,[R7, #+20]
        ADR.N    R1,??DataTable12  ;; 0x25, 0x64, 0x00, 0x00
        BL       sprintf
??print_value_2:
        B.N      ??print_value_10
??print_value_9:
        MOVS     R0,#+64
        BLX      R6
        MOVS     R6,R0
        BEQ.N    ??print_value_10
        MOV      R0,R4
        MOV      R1,R5
        BL       floor
        MOV      R2,R4
        MOV      R3,R5
        BL       __aeabi_dsub
        BL       ?Subroutine9
??CrossCallReturnLabel_25:
        BCS.N    ??print_value_11
        MOV      R0,R4
        BIC      R1,R5,#0x80000000
        LDR.W    R2,??DataTable15_11  ;; 0xe4c2f344
        LDR.W    R3,??DataTable15_12  ;; 0x4c63e9e4
        BL       __aeabi_cdcmple
        BCS.N    ??print_value_11
        MOV      R2,R4
        MOV      R3,R5
        LDR.W    R1,??DataTable15_13
        B.N      ??print_value_12
??print_value_11:
        MOV      R0,R4
        BIC      R1,R5,#0x80000000
        LDR.W    R2,??DataTable15_14  ;; 0xa0b5ed8d
        LDR.W    R3,??DataTable15_15  ;; 0x3eb0c6f7
        BL       __aeabi_cdcmple
        BCC.N    ??print_value_13
        MOVS     R2,#+1
        LDR.W    R3,??DataTable15_16  ;; 0x41cdcd65
        BL       __aeabi_cdrcmple
        BLS.N    ??print_value_13
        MOV      R2,R4
        MOV      R3,R5
        ADR.N    R1,??DataTable12_1  ;; 0x25, 0x66, 0x00, 0x00
        B.N      ??print_value_12
??print_value_13:
        MOV      R2,R4
        MOV      R3,R5
        ADR.N    R1,??DataTable12_2  ;; 0x25, 0x65, 0x00, 0x00
??print_value_12:
        MOV      R0,R6
        BL       sprintf
        B.N      ??print_value_10
??print_value_14:
        LDR      R0,[R7, #+16]
        BL       print_string_ptr
        B.N      ??print_value_7
??print_value_15:
        MOV      R0,R7
        BL       print_array
        B.N      ??print_value_7
??print_value_16:
        MOV      R0,R7
        BL       print_object
??print_value_7:
        MOV      R6,R0
??print_value_10:
        MOV      R0,R6
??print_value_1:
        POP      {R1,R4-R7,PC}    ;; return

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
?Subroutine9:
        BIC      R1,R1,#0x80000000
        MOVS     R2,#+1
        LDR.W    R3,??DataTable15_17  ;; 0x3cb00000
        B.W      __aeabi_cdcmple

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
print_array:
        PUSH     {R1-R11,LR}
        MOV      R4,R0
        LDR      R0,[R4, #+8]
        MOVS     R6,#+0
        MOV      R5,R1
        MOV      R8,R2
        MOVS     R7,#+5
        STR      R6,[SP, #+4]
        STR      R6,[SP, #+0]
        B.N      ??print_array_0
??print_array_1:
        ADDS     R6,R6,#+1
        LDR      R0,[R0, #+0]
??print_array_0:
        CMP      R0,#+0
        BNE.N    ??print_array_1
        LDR.W    R9,??DataTable13_2
        LDR      R1,[R9, #+0]
        CBNZ.N   R6,??print_array_2
        MOVS     R0,#+3
        BLX      R1
        MOVS     R4,R0
        BEQ.N    ??print_array_3
        MOVS     R2,#+3
        ADR.N    R1,??DataTable12_3  ;; 0x5B, 0x5D, 0x00, 0x00
        BL       __aeabi_memcpy
??print_array_3:
        MOV      R0,R4
        B.N      ??print_array_4
??print_array_2:
        LSLS     R0,R6,#+2
        BLX      R1
        MOVS     R11,R0
        BEQ.N    ??print_array_4
        LSLS     R2,R6,#+2
        MOVS     R1,#+0
        BL       memset
        LDR      R4,[R4, #+8]
        STR      R5,[SP, #+8]
        LDR      R10,[SP, #+4]
        LDR      R5,[SP, #+0]
??print_array_5:
        CMP      R4,#+0
        BEQ.N    ??print_array_6
        CMP      R5,#+0
        BNE.N    ??print_array_6
        LDR      R1,[SP, #+8]
        MOV      R2,R8
        MOV      R0,R4
        ADDS     R1,R1,#+1
        BL       print_value
        STR      R0,[R11, R10, LSL #+2]
        ADD      R10,R10,#+1
        CBNZ.N   R0,??print_array_7
        MOVS     R5,#+1
        B.N      ??print_array_8
??print_array_7:
        BL       strlen
        MOVS     R1,R8
        IT       NE 
        MOVNE    R1,#+1
        ADDS     R7,R0,R7
        ADDS     R7,R1,R7
        ADDS     R7,R7,#+2
??print_array_8:
        LDR      R4,[R4, #+0]
        B.N      ??print_array_5
??print_array_9:
        LDR      R0,[R11, R4, LSL #+2]
        CBZ.N    R0,??print_array_10
        BLX      R1
??print_array_10:
        ADDS     R4,R4,#+1
??print_array_11:
        LDR      R1,[R8, #+0]
        CMP      R4,R6
        BLT.N    ??print_array_9
        MOV      R0,R11
        BLX      R1
        MOVS     R0,#+0
        B.N      ??print_array_4
??print_array_12:
        MOVS     R0,#+91
        STRB     R0,[R5, #+0]
        ADDS     R7,R5,#+1
        MOVS     R1,#+0
        STRB     R1,[R7, #+0]
        MOV      R9,R1
        B.N      ??print_array_13
??print_array_14:
        LDR      R1,[R11, R9, LSL #+2]
        MOV      R0,R7
        BL       strcpy
        LDR      R0,[R11, R9, LSL #+2]
        BL       strlen
        ADDS     R7,R7,R0
        SUBS     R0,R6,#+1
        CMP      R9,R0
        BEQ.N    ??print_array_15
        MOVS     R1,#+44
        STRB     R1,[R7], #+1
        CBZ.N    R4,??print_array_16
        MOVS     R0,#+32
        STRB     R0,[R7], #+1
??print_array_16:
        MOVS     R1,#+0
        STRB     R1,[R7, #+0]
??print_array_15:
        LDR      R0,[R11, R9, LSL #+2]
        ADD      R9,R9,#+1
        BLX      R10
??print_array_13:
        LDR      R10,[R8, #+0]
        CMP      R9,R6
        BLT.N    ??print_array_14
        MOV      R0,R11
        BLX      R10
        MOVS     R0,#+93
        STRB     R0,[R7, #+0]
        MOVS     R1,#+0
        STRB     R1,[R7, #+1]
        MOV      R0,R5
??print_array_4:
        POP      {R1-R11,PC}      ;; return
??print_array_6:
        MOV      R4,R8
        MOV      R0,R7
        LDR.W    R8,??DataTable13
        CBNZ.N   R5,??print_array_17
        LDR      R1,[R9, #+0]
        BLX      R1
        MOVS     R5,R0
        BNE.N    ??print_array_12
??print_array_17:
        MOVS     R4,#+0
        B.N      ??print_array_11

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
parse_object:
        PUSH     {R4-R6,LR}
        MOV      R6,R0
        MOV      R4,R1
        LDRSB    R0,[R4, #+0]
        CMP      R0,#+123
        BNE.N    ??parse_object_0
        MOVS     R1,#+6
        STR      R1,[R6, #+12]
        BL       ??Subroutine8_0
??CrossCallReturnLabel_20:
        MOV      R4,R0
        LDRSB    R1,[R4, #+0]
        CMP      R1,#+125
        BEQ.N    ??parse_object_1
        BL       cJSON_New_Item
        MOVS     R5,R0
        STR      R5,[R6, #+8]
        BEQ.N    ??parse_object_2
        MOV      R0,R4
        BL       skip
        MOV      R1,R0
        MOV      R0,R5
        BL       parse_string
        BL       skip
        MOVS     R4,R0
        BEQ.N    ??parse_object_2
        BL       ?Subroutine4
??CrossCallReturnLabel_6:
        BNE.N    ??parse_object_0
        BL       ??Subroutine8_0
??CrossCallReturnLabel_19:
        BL       ?Subroutine5
??CrossCallReturnLabel_9:
        BL       skip
        MOVS     R4,R0
        BEQ.N    ??parse_object_2
??parse_object_3:
        LDRSB    R0,[R4, #+0]
        CMP      R0,#+44
        BNE.N    ??parse_object_4
        BL       cJSON_New_Item
        CBZ.N    R0,??parse_object_2
        BL       ?Subroutine8
??CrossCallReturnLabel_22:
        MOV      R1,R0
        MOV      R0,R5
        BL       parse_string
        BL       skip
        MOVS     R4,R0
        BEQ.N    ??parse_object_2
        BL       ?Subroutine4
??CrossCallReturnLabel_7:
        BNE.N    ??parse_object_0
        BL       ??Subroutine8_0
??CrossCallReturnLabel_18:
        BL       ?Subroutine5
??CrossCallReturnLabel_8:
        BL       skip
        MOVS     R4,R0
        BNE.N    ??parse_object_3
??parse_object_2:
        MOVS     R0,#+0
        POP      {R4-R6,PC}       ;; return
??parse_object_4:
        CMP      R0,#+125
        BNE.N    ??parse_object_0
??parse_object_1:
        ADDS     R0,R4,#+1
        POP      {R4-R6,PC}
??parse_object_0:
        LDR.W    R0,??DataTable15_4
        STR      R4,[R0, #+0]
        B.N      ??parse_object_2

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable12:
        DC8      0x25, 0x64, 0x00, 0x00

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable12_1:
        DC8      0x25, 0x66, 0x00, 0x00

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable12_2:
        DC8      0x25, 0x65, 0x00, 0x00

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable12_3:
        DC8      0x5B, 0x5D, 0x00, 0x00

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable12_4:
        DC32     ep

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
?Subroutine8:
        STR      R0,[R5, #+0]
        STR      R5,[R0, #+4]
        MOV      R5,R0
??Subroutine8_0:
        ADDS     R0,R4,#+1
        B.N      skip

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
?Subroutine5:
        MOV      R1,R0
        MOV      R0,R5
        B.N      parse_value

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
?Subroutine4:
        LDR      R0,[R5, #+16]
        MOVS     R1,#+0
        STR      R1,[R5, #+16]
        STR      R0,[R5, #+32]
        LDRSB    R0,[R4, R1]
        CMP      R0,#+58
        BX       LR

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
print_object:
        PUSH     {R1-R11,LR}
        MOV      R5,R0
        MOVS     R0,#+0
        STR      R0,[SP, #+8]
        LDR      R0,[R5, #+8]
        MOVS     R7,#+0
        MOV      R8,#+7
        STR      R7,[SP, #+4]
        B.N      ??print_object_0
??print_object_1:
        ADDS     R7,R7,#+1
        LDR      R0,[R0, #+0]
??print_object_0:
        CMP      R0,#+0
        BNE.N    ??print_object_1
        LDR.N    R0,??DataTable13_2
        LDR      R3,[R0, #+0]
        MOV      R6,R1
        MOV      R4,R2
        CBNZ.N   R7,??print_object_2
        CMP      R4,#+0
        ITE      NE 
        ADDNE    R0,R6,#+4
        MOVEQ    R0,#+3
        BLX      R3
        MOVS     R5,R0
        BEQ.N    ??print_object_3
        MOV      R9,R5
        MOVS     R0,#+123
        STRB     R0,[R9], #+1
        CBZ.N    R4,??print_object_4
        MOVS     R1,#+10
        SUBS     R6,R6,#+1
        STRB     R1,[R9], #+1
        CMP      R6,#+0
        BLE.N    ??print_object_4
        MOVS     R2,#+9
        MOV      R1,R6
        MOV      R0,R9
        BL       __aeabi_memset
        ADD      R9,R9,R6
??print_object_4:
        MOVS     R0,#+125
        STRB     R0,[R9, #+0]
        MOVS     R1,#+0
        STRB     R1,[R9, #+1]
        MOV      R0,R5
        B.N      ??print_object_5
??print_object_2:
        LSLS     R0,R7,#+2
        BLX      R3
        MOVS     R9,R0
        BNE.N    ??print_object_6
??print_object_3:
        MOVS     R0,#+0
        B.N      ??print_object_5
??print_object_6:
        BL       ?Subroutine3
??CrossCallReturnLabel_4:
        LSLS     R0,R7,#+2
        BLX      R2
        MOVS     R11,R0
        BNE.N    ??print_object_7
        LDR.N    R1,??DataTable13
        MOV      R0,R9
        LDR      R2,[R1, #+0]
??print_object_8:
        BLX      R2
        B.N      ??print_object_3
??print_object_7:
        LSLS     R2,R7,#+2
        MOVS     R1,#+0
        MOV      R0,R9
        BL       memset
        LSLS     R2,R7,#+2
        MOVS     R1,#+0
        MOV      R0,R11
        BL       memset
        LDR      R5,[R5, #+8]
        ADDS     R6,R6,#+1
        CBZ.N    R4,??print_object_9
        ADD      R8,R6,#+7
??print_object_9:
        STR      R6,[SP, #+0]
        LDR      R6,[SP, #+8]
        LDR      R10,[SP, #+4]
        STR      R9,[SP, #+8]
        STR      R11,[SP, #+4]
        B.N      ??print_object_10
??print_object_11:
        MOV      R10,#+1
        B.N      ??print_object_12
??print_object_13:
        ADD      R8,R11,R8
        ADD      R8,R0,R8
        ADD      R8,R1,R8
        ADD      R8,R8,#+2
??print_object_12:
        LDR      R5,[R5, #+0]
??print_object_10:
        CMP      R5,#+0
        BEQ.W    ??print_object_14
        LDR      R0,[R5, #+32]
        MOV      R11,R6
        BL       print_string_ptr
        MOV      R9,R0
        MOV      R2,R4
        LDR      R0,[SP, #+4]
        STR      R9,[R0, R6, LSL #+2]
        LDR      R1,[SP, #+0]
        MOV      R0,R5
        ADD      R6,R11,#+1
        BL       print_value
        LDR      R1,[SP, #+8]
        CMP      R9,#+0
        STR      R0,[R1, R11, LSL #+2]
        IT       NE 
        CMPNE    R0,#+0
        BEQ.N    ??print_object_11
        BL       strlen
        MOV      R11,R0
        MOV      R0,R9
        BL       strlen
        CMP      R4,#+0
        ITTE     NE 
        LDRNE    R1,[SP, #+0]
        ADDNE    R1,R1,#+2
        MOVEQ    R1,#+0
        B.N      ??print_object_13
??print_object_15:
        MOVS     R5,#+0
        LDR.N    R4,??DataTable13
        B.N      ??print_object_16
??print_object_17:
        LDR      R0,[R9, R5, LSL #+2]
        CBZ.N    R0,??print_object_18
        BLX      R1
??print_object_18:
        LDR      R0,[R8, R5, LSL #+2]
        CBZ.N    R0,??print_object_19
        LDR      R1,[R4, #+0]
        BLX      R1
??print_object_19:
        ADDS     R5,R5,#+1
??print_object_16:
        LDR      R1,[R4, #+0]
        CMP      R5,R7
        BLT.N    ??print_object_17
        MOV      R0,R9
        BLX      R1
        MOV      R0,R8
        LDR      R2,[R4, #+0]
        B.N      ??print_object_8
??print_object_20:
        CBZ.N    R4,??print_object_21
        STR      R5,[SP, #+4]
        CMP      R5,#+0
        BLE.N    ??print_object_21
        BL       ?Subroutine10
??CrossCallReturnLabel_26:
        LDR      R0,[SP, #+4]
        ADD      R7,R7,R0
??print_object_21:
        LDR      R1,[R9, R6, LSL #+2]
        MOV      R0,R7
        BL       strcpy
        LDR      R0,[R9, R6, LSL #+2]
        BL       strlen
        ADD      R7,R7,R0
        MOVS     R0,#+58
        STRB     R0,[R7], #+1
        CBZ.N    R4,??print_object_22
        MOVS     R1,#+9
        STRB     R1,[R7], #+1
??print_object_22:
        LDR      R1,[R8, R6, LSL #+2]
        MOV      R0,R7
        BL       strcpy
        LDR      R0,[R8, R6, LSL #+2]
        BL       strlen
        ADD      R7,R7,R0
        LDR      R0,[SP, #+8]
        SUBS     R0,R0,#+1
        CMP      R6,R0
        ITT      NE 
        MOVNE    R1,#+44
        STRBNE   R1,[R7], #+1
        CBZ.N    R4,??print_object_23
        MOVS     R0,#+10
        STRB     R0,[R7], #+1
??print_object_23:
        MOVS     R1,#+0
        STRB     R1,[R7, #+0]
        LDR      R0,[R9, R6, LSL #+2]
        BLX      R10
        LDR      R0,[R8, R6, LSL #+2]
        LDR      R1,[R11, #+0]
        ADDS     R6,R6,#+1
        BLX      R1
??print_object_24:
        LDR      R1,[SP, #+8]
        LDR      R10,[R11, #+0]
        CMP      R6,R1
        BLT.N    ??print_object_20
        MOV      R0,R9
        BLX      R10
        LDR      R3,[R11, #+0]
        MOV      R0,R8
        BLX      R3
        CBZ.N    R4,??print_object_25
        SUBS     R5,R5,#+1
        CMP      R5,#+0
        BLE.N    ??print_object_25
        BL       ?Subroutine10
??CrossCallReturnLabel_27:
        ADD      R7,R7,R5
??print_object_25:
        MOVS     R0,#+125
        STRB     R0,[R7, #+0]
        MOVS     R1,#+0
        STRB     R1,[R7, #+1]
        LDR      R0,[SP, #+0]
??print_object_5:
        POP      {R1-R11,PC}      ;; return
??print_object_14:
        MOV      R0,R8
        LDR      R5,[SP, #+0]
        LDR      R8,[SP, #+8]
        LDR      R9,[SP, #+4]
        CMP      R10,#+0
        BNE.N    ??print_object_15
        BL       ?Subroutine3
??CrossCallReturnLabel_5:
        BLX      R2
        STR      R0,[SP, #+0]
        CMP      R0,#+0
        BEQ.N    ??print_object_15
        MOVS     R1,#+123
        STRB     R1,[R0, #+0]
        LDR      R1,[SP, #+0]
        ADDS     R0,R1,#+1
        CBZ.N    R4,??print_object_26
        MOVS     R1,#+10
        STRB     R1,[R0], #+1
??print_object_26:
        MOVS     R2,#+0
        STRB     R2,[R0, #+0]
        STR      R7,[SP, #+8]
        MOVS     R6,#+0
        MOV      R7,R0
        LDR.W    R11,??DataTable13
        B.N      ??print_object_24

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable13:
        DC32     cJSON_free

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable13_1:
        DC32     free

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable13_2:
        DC32     cJSON_malloc

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable13_3:
        DC32     malloc

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable13_4:
        DC32     0xbff00000

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
?Subroutine10:
        MOVS     R2,#+9
        MOV      R1,R5
        MOV      R0,R7
        B.W      __aeabi_memset

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
cJSON_GetArraySize:
        LDR      R1,[R0, #+8]
        MOVS     R0,#+0
        B.N      ??cJSON_GetArraySize_0
??cJSON_GetArraySize_1:
        ADDS     R0,R0,#+1
        LDR      R1,[R1, #+0]
??cJSON_GetArraySize_0:
        CMP      R1,#+0
        BNE.N    ??cJSON_GetArraySize_1
        BX       LR               ;; return

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
cJSON_GetArrayItem:
        LDR      R0,[R0, #+8]
??cJSON_GetArrayItem_0:
        CBZ.N    R0,??cJSON_GetArrayItem_1
        CMP      R1,#+1
        ITT      GE 
        SUBGE    R1,R1,#+1
        LDRGE    R0,[R0, #+0]
        BGE.N    ??cJSON_GetArrayItem_0
??cJSON_GetArrayItem_1:
        BX       LR               ;; return

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
cJSON_GetObjectItem:
        PUSH     {R3-R5,LR}
        MOV      R5,R1
        LDR      R4,[R0, #+8]
??cJSON_GetObjectItem_0:
        CBZ.N    R4,??cJSON_GetObjectItem_1
        LDR      R0,[R4, #+32]
        MOV      R1,R5
        BL       cJSON_strcasecmp
        CBZ.N    R0,??cJSON_GetObjectItem_1
        LDR      R4,[R4, #+0]
        B.N      ??cJSON_GetObjectItem_0
??cJSON_GetObjectItem_1:
        MOV      R0,R4
        POP      {R1,R4,R5,PC}    ;; return

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
create_reference:
        PUSH     {R3-R5,LR}
        MOV      R5,R0
        BL       cJSON_New_Item
        MOVS     R4,R0
        BNE.N    ??create_reference_0
        MOVS     R0,#+0
        POP      {R1,R4,R5,PC}
??create_reference_0:
        MOVS     R2,#+40
        MOV      R1,R5
        BL       memcpy
        LDR      R1,[R4, #+12]
        MOVS     R0,#+0
        STR      R0,[R4, #+32]
        ORR      R1,R1,#0x100
        STR      R1,[R4, #+12]
        STR      R0,[R4, #+4]
        STR      R0,[R4, #+0]
        MOV      R0,R4
        POP      {R1,R4,R5,PC}    ;; return

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
cJSON_AddItemToArray:
        LDR      R2,[R0, #+8]
        CBZ.N    R1,??cJSON_AddItemToArray_0
        CBNZ.N   R2,??cJSON_AddItemToArray_1
        STR      R1,[R0, #+8]
        BX       LR
??cJSON_AddItemToArray_2:
        MOV      R2,R0
??cJSON_AddItemToArray_1:
        LDR      R0,[R2, #+0]
        CMP      R0,#+0
        BNE.N    ??cJSON_AddItemToArray_2
        STR      R1,[R2, #+0]
        STR      R2,[R1, #+4]
??cJSON_AddItemToArray_0:
        BX       LR               ;; return

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
cJSON_AddItemToObject:
        PUSH     {R4-R6,LR}
        MOV      R5,R0
        MOV      R6,R1
        MOVS     R4,R2
        BEQ.N    ??cJSON_AddItemToObject_0
        LDR      R0,[R4, #+32]
        CBZ.N    R0,??cJSON_AddItemToObject_1
        LDR.N    R1,??DataTable15_18
        LDR      R2,[R1, #+0]
        BLX      R2
??cJSON_AddItemToObject_1:
        MOV      R0,R6
        BL       cJSON_strdup
        STR      R0,[R4, #+32]
        MOV      R1,R4
        MOV      R0,R5
        POP      {R4-R6,LR}
        B.N      cJSON_AddItemToArray
??cJSON_AddItemToObject_0:
        POP      {R4-R6,PC}       ;; return

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable14:
        DC32     0x3ff00000

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable14_1:
        DC32     0x40240000

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
cJSON_AddItemReferenceToArray:
        PUSH     {R4,LR}
        MOV      R4,R0
        MOV      R0,R1
        BL       create_reference
        MOV      R1,R0
        MOV      R0,R4
        POP      {R4,LR}
        B.N      cJSON_AddItemToArray

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
cJSON_AddItemReferenceToObject:
        PUSH     {R3-R5,LR}
        MOV      R4,R0
        MOV      R5,R1
        MOV      R0,R2
        BL       create_reference
        MOV      R2,R0
        MOV      R1,R5
        MOV      R0,R4
        POP      {R3-R5,LR}
        B.N      cJSON_AddItemToObject

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
cJSON_DetachItemFromArray:
        MOV      R2,R0
        LDR      R0,[R2, #+8]
        B.N      ??cJSON_DetachItemFromArray_0
??cJSON_DetachItemFromArray_1:
        CMP      R1,#+1
        BLT.N    ??cJSON_DetachItemFromArray_2
        LDR      R0,[R0, #+0]
        SUBS     R1,R1,#+1
??cJSON_DetachItemFromArray_0:
        CMP      R0,#+0
        BNE.N    ??cJSON_DetachItemFromArray_1
        BX       LR
??cJSON_DetachItemFromArray_2:
        LDR      R1,[R0, #+4]
        CBZ.N    R1,??cJSON_DetachItemFromArray_3
        LDR      R3,[R0, #+0]
        STR      R3,[R1, #+0]
??cJSON_DetachItemFromArray_3:
        LDR      R1,[R0, #+0]
        CBZ.N    R1,??cJSON_DetachItemFromArray_4
        LDR      R3,[R0, #+4]
        STR      R3,[R1, #+4]
??cJSON_DetachItemFromArray_4:
        LDR      R1,[R2, #+8]
        CMP      R0,R1
        ITT      EQ 
        LDREQ    R3,[R0, #+0]
        STREQ    R3,[R2, #+8]
        MOVS     R1,#+0
        STR      R1,[R0, #+0]
        STR      R1,[R0, #+4]
        BX       LR               ;; return

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
cJSON_DeleteItemFromArray:
        PUSH     {R7,LR}
        BL       cJSON_DetachItemFromArray
        B.N      ?Subroutine2

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
cJSON_DetachItemFromObject:
        PUSH     {R3-R7,LR}
        MOV      R5,R0
        MOV      R6,R1
        MOVS     R7,#+0
        LDR      R4,[R5, #+8]
        B.N      ??cJSON_DetachItemFromObject_0
??cJSON_DetachItemFromObject_1:
        ADDS     R7,R7,#+1
        LDR      R4,[R4, #+0]
??cJSON_DetachItemFromObject_0:
        CBZ.N    R4,??cJSON_DetachItemFromObject_2
        LDR      R0,[R4, #+32]
        MOV      R1,R6
        BL       cJSON_strcasecmp
        CMP      R0,#+0
        BNE.N    ??cJSON_DetachItemFromObject_1
        MOV      R1,R7
        MOV      R0,R5
        POP      {R2,R4-R7,LR}
        B.N      cJSON_DetachItemFromArray
??cJSON_DetachItemFromObject_2:
        MOVS     R0,#+0
        POP      {R1,R4-R7,PC}    ;; return

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
cJSON_DeleteItemFromObject:
        PUSH     {R7,LR}
        BL       cJSON_DetachItemFromObject
        REQUIRE ?Subroutine2
        ;; // Fall through to label ?Subroutine2

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
?Subroutine2:
        POP      {R1,LR}
        B.W      cJSON_Delete

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
cJSON_ReplaceItemInArray:
        PUSH     {R4,LR}
        LDR      R3,[R0, #+8]
        B.N      ??cJSON_ReplaceItemInArray_0
??cJSON_ReplaceItemInArray_1:
        CMP      R1,#+1
        BLT.N    ??cJSON_ReplaceItemInArray_2
        LDR      R3,[R3, #+0]
        SUBS     R1,R1,#+1
??cJSON_ReplaceItemInArray_0:
        CMP      R3,#+0
        BNE.N    ??cJSON_ReplaceItemInArray_1
        POP      {R4,PC}
??cJSON_ReplaceItemInArray_3:
        MOVS     R1,#+0
        STR      R1,[R3, #+4]
        STR      R1,[R3, #+0]
        MOV      R0,R3
        POP      {R4,LR}
        B.W      cJSON_Delete
??cJSON_ReplaceItemInArray_2:
        LDR      R1,[R3, #+0]
        STR      R1,[R2, #+0]
        LDR      R4,[R3, #+4]
        STR      R4,[R2, #+4]
        CBZ.N    R1,??cJSON_ReplaceItemInArray_4
        STR      R2,[R1, #+4]
??cJSON_ReplaceItemInArray_4:
        LDR      R1,[R0, #+8]
        CMP      R3,R1
        ITEE     EQ 
        STREQ    R2,[R0, #+8]
        LDRNE    R0,[R2, #+4]
        STRNE    R2,[R0, #+0]
        B.N      ??cJSON_ReplaceItemInArray_3

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
cJSON_ReplaceItemInObject:
        PUSH     {R4-R8,LR}
        MOV      R5,R0
        MOV      R8,R1
        MOV      R7,R2
        MOVS     R6,#+0
        LDR      R4,[R5, #+8]
        B.N      ??cJSON_ReplaceItemInObject_0
??cJSON_ReplaceItemInObject_1:
        ADDS     R6,R6,#+1
        LDR      R4,[R4, #+0]
??cJSON_ReplaceItemInObject_0:
        CBZ.N    R4,??cJSON_ReplaceItemInObject_2
        LDR      R0,[R4, #+32]
        MOV      R1,R8
        BL       cJSON_strcasecmp
        CMP      R0,#+0
        BNE.N    ??cJSON_ReplaceItemInObject_1
        LDR      R0,[R7, #+32]
        CBZ.N    R0,??cJSON_ReplaceItemInObject_3
        LDR.N    R1,??DataTable15_18
        LDR      R2,[R1, #+0]
        BLX      R2
??cJSON_ReplaceItemInObject_3:
        MOV      R0,R8
        BL       cJSON_strdup
        STR      R0,[R7, #+32]
        MOV      R2,R7
        MOV      R1,R6
        MOV      R0,R5
        POP      {R4-R8,LR}
        B.N      cJSON_ReplaceItemInArray
??cJSON_ReplaceItemInObject_2:
        POP      {R4-R8,PC}       ;; return

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable15:
        DC32     firstByteMark

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable15_1:
        DC32     0xffc00

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable15_2:
        DC32     ?_5

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable15_3:
        DC32     ?_6

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable15_4:
        DC32     ep

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable15_5:
        DC32     ?_7

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable15_6:
        DC32     ?_8

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable15_7:
        DC32     ?_9

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable15_8:
        DC32     0xffc00001

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable15_9:
        DC32     0x41dfffff

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable15_10:
        DC32     0xc1e00000

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable15_11:
        DC32     0xe4c2f344

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable15_12:
        DC32     0x4c63e9e4

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable15_13:
        DC32     ?_1

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable15_14:
        DC32     0xa0b5ed8d

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable15_15:
        DC32     0x3eb0c6f7

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable15_16:
        DC32     0x41cdcd65

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable15_17:
        DC32     0x3cb00000

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable15_18:
        DC32     cJSON_free

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
cJSON_CreateNull:
        PUSH     {R7,LR}
        BL       cJSON_New_Item
        CBZ.N    R0,??cJSON_CreateNull_0
        MOVS     R1,#+2
        STR      R1,[R0, #+12]
??cJSON_CreateNull_0:
        POP      {R1,PC}          ;; return

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
cJSON_CreateTrue:
        PUSH     {R7,LR}
        BL       cJSON_New_Item
        CBZ.N    R0,??cJSON_CreateTrue_0
        MOVS     R1,#+1
        STR      R1,[R0, #+12]
??cJSON_CreateTrue_0:
        POP      {R1,PC}          ;; return

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
cJSON_CreateFalse:
        PUSH     {R7,LR}
        BL       cJSON_New_Item
        CBZ.N    R0,??cJSON_CreateFalse_0
        MOVS     R1,#+0
        STR      R1,[R0, #+12]
??cJSON_CreateFalse_0:
        POP      {R1,PC}          ;; return

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
cJSON_CreateBool:
        PUSH     {R4,LR}
        MOV      R4,R0
        BL       cJSON_New_Item
        CBZ.N    R0,??cJSON_CreateBool_0
        MOVS     R1,R4
        IT       NE 
        MOVNE    R1,#+1
        STR      R1,[R0, #+12]
??cJSON_CreateBool_0:
        POP      {R4,PC}          ;; return

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
cJSON_CreateNumber:
        PUSH     {R4-R6,LR}
        MOV      R4,R0
        MOV      R5,R1
        BL       cJSON_New_Item
        MOVS     R6,R0
        BEQ.N    ??cJSON_CreateNumber_0
        MOVS     R2,#+3
        STR      R2,[R6, #+12]
        STRD     R4,R5,[R6, #+24]
        MOV      R0,R4
        MOV      R1,R5
        BL       __aeabi_d2iz
        STR      R0,[R6, #+20]
??cJSON_CreateNumber_0:
        MOV      R0,R6
        POP      {R4-R6,PC}       ;; return

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
cJSON_CreateString:
        PUSH     {R3-R5,LR}
        MOV      R5,R0
        BL       cJSON_New_Item
        MOVS     R4,R0
        BEQ.N    ??cJSON_CreateString_0
        MOVS     R0,#+4
        STR      R0,[R4, #+12]
        MOV      R0,R5
        BL       cJSON_strdup
        STR      R0,[R4, #+16]
??cJSON_CreateString_0:
        MOV      R0,R4
        POP      {R1,R4,R5,PC}    ;; return

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
cJSON_CreateArray:
        PUSH     {R7,LR}
        BL       cJSON_New_Item
        CBZ.N    R0,??cJSON_CreateArray_0
        MOVS     R1,#+5
        STR      R1,[R0, #+12]
??cJSON_CreateArray_0:
        POP      {R1,PC}          ;; return

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
cJSON_CreateObject:
        PUSH     {R7,LR}
        BL       cJSON_New_Item
        CBZ.N    R0,??cJSON_CreateObject_0
        MOVS     R1,#+6
        STR      R1,[R0, #+12]
??cJSON_CreateObject_0:
        POP      {R1,PC}          ;; return

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
cJSON_CreateIntArray:
        PUSH     {R4-R8,LR}
        BL       ?Subroutine6
??CrossCallReturnLabel_15:
        MOVS     R5,R0
        MOV      R4,R7
        BNE.N    ??cJSON_CreateIntArray_0
??cJSON_CreateIntArray_1:
        B.N      ?Subroutine0
??cJSON_CreateIntArray_2:
        LDR      R0,[R6, R4, LSL #+2]
        BL       __aeabi_i2d
        BL       cJSON_CreateNumber
        CMP      R4,#+0
        ITTE     NE 
        STRNE    R0,[R7, #+0]
        STRNE    R7,[R0, #+4]
        STREQ    R0,[R5, #+8]
        MOV      R7,R0
        ADDS     R4,R4,#+1
??cJSON_CreateIntArray_0:
        CMP      R4,R8
        BLT.N    ??cJSON_CreateIntArray_2
        B.N      ??cJSON_CreateIntArray_1

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
cJSON_CreateFloatArray:
        PUSH     {R4-R8,LR}
        BL       ?Subroutine6
??CrossCallReturnLabel_14:
        MOVS     R5,R0
        MOV      R4,R7
        BNE.N    ??cJSON_CreateFloatArray_0
??cJSON_CreateFloatArray_1:
        B.N      ?Subroutine0
??cJSON_CreateFloatArray_2:
        LDR      R0,[R6, R4, LSL #+2]
        BL       __aeabi_f2d
        BL       cJSON_CreateNumber
        CMP      R4,#+0
        ITTE     NE 
        STRNE    R0,[R7, #+0]
        STRNE    R7,[R0, #+4]
        STREQ    R0,[R5, #+8]
        MOV      R7,R0
        ADDS     R4,R4,#+1
??cJSON_CreateFloatArray_0:
        CMP      R4,R8
        BLT.N    ??cJSON_CreateFloatArray_2
        B.N      ??cJSON_CreateFloatArray_1

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
?Subroutine0:
        MOV      R0,R5
        POP      {R4-R8,PC}       ;; return

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
cJSON_CreateDoubleArray:
        PUSH     {R4-R8,LR}
        BL       ?Subroutine6
??CrossCallReturnLabel_13:
        MOVS     R5,R0
        MOV      R4,R7
        BNE.N    ??cJSON_CreateDoubleArray_0
??cJSON_CreateDoubleArray_1:
        B.N      ?Subroutine0
??cJSON_CreateDoubleArray_2:
        ADD      R2,R6,R4, LSL #+3
        LDRD     R0,R1,[R2, #+0]
        BL       cJSON_CreateNumber
        CMP      R4,#+0
        ITTE     NE 
        STRNE    R0,[R7, #+0]
        STRNE    R7,[R0, #+4]
        STREQ    R0,[R5, #+8]
        MOV      R7,R0
        ADDS     R4,R4,#+1
??cJSON_CreateDoubleArray_0:
        CMP      R4,R8
        BLT.N    ??cJSON_CreateDoubleArray_2
        B.N      ??cJSON_CreateDoubleArray_1

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
?Subroutine6:
        MOV      R6,R0
        MOV      R8,R1
        MOVS     R7,#+0
        B.N      cJSON_CreateArray

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
cJSON_CreateStringArray:
        PUSH     {R4-R8,LR}
        BL       ?Subroutine6
??CrossCallReturnLabel_12:
        MOVS     R5,R0
        MOV      R4,R7
        BNE.N    ??cJSON_CreateStringArray_0
??cJSON_CreateStringArray_1:
        B.N      ?Subroutine0
??cJSON_CreateStringArray_2:
        LDR      R0,[R6, R4, LSL #+2]
        BL       cJSON_CreateString
        CMP      R4,#+0
        ITTE     NE 
        STRNE    R0,[R7, #+0]
        STRNE    R7,[R0, #+4]
        STREQ    R0,[R5, #+8]
        MOV      R7,R0
        ADDS     R4,R4,#+1
??cJSON_CreateStringArray_0:
        CMP      R4,R8
        BLT.N    ??cJSON_CreateStringArray_2
        B.N      ??cJSON_CreateStringArray_1

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
cJSON_Duplicate:
        PUSH     {R3-R7,LR}
        MOV      R5,R0
        MOV      R7,R1
        MOVS     R4,#+0
        CBZ.N    R5,??cJSON_Duplicate_0
        BL       cJSON_New_Item
        MOVS     R6,R0
        BNE.N    ??cJSON_Duplicate_1
??cJSON_Duplicate_0:
        MOVS     R0,#+0
        POP      {R1,R4-R7,PC}
??cJSON_Duplicate_1:
        LDR      R0,[R5, #+12]
        BIC      R0,R0,#0x100
        STR      R0,[R6, #+12]
        LDR      R0,[R5, #+20]
        STR      R0,[R6, #+20]
        LDRD     R2,R3,[R5, #+24]
        STRD     R2,R3,[R6, #+24]
        LDR      R0,[R5, #+16]
        CBZ.N    R0,??cJSON_Duplicate_2
        BL       cJSON_strdup
        STR      R0,[R6, #+16]
        CBZ.N    R0,??cJSON_Duplicate_3
??cJSON_Duplicate_2:
        LDR      R0,[R5, #+32]
        CBZ.N    R0,??cJSON_Duplicate_4
        BL       cJSON_strdup
        STR      R0,[R6, #+32]
        CBZ.N    R0,??cJSON_Duplicate_3
??cJSON_Duplicate_4:
        CBZ.N    R7,??cJSON_Duplicate_5
        LDR      R5,[R5, #+8]
        B.N      ??cJSON_Duplicate_6
??cJSON_Duplicate_7:
        CMP      R4,#+0
        ITEE     EQ 
        STREQ    R0,[R6, #+8]
        STRNE    R0,[R4, #+0]
        STRNE    R4,[R0, #+4]
        MOV      R4,R0
        LDR      R5,[R5, #+0]
??cJSON_Duplicate_6:
        CBZ.N    R5,??cJSON_Duplicate_5
        MOVS     R1,#+1
        MOV      R0,R5
        BL       cJSON_Duplicate
        CMP      R0,#+0
        BNE.N    ??cJSON_Duplicate_7
??cJSON_Duplicate_3:
        MOV      R0,R6
        BL       cJSON_Delete
        B.N      ??cJSON_Duplicate_0
??cJSON_Duplicate_5:
        MOV      R0,R6
        POP      {R1,R4-R7,PC}    ;; return

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
cJSON_Minify:
        MOV      R2,R0
        B.N      ??cJSON_Minify_0
??cJSON_Minify_1:
        ADDS     R0,R0,#+1
??cJSON_Minify_0:
        LDRSB    R1,[R0, #+0]
        CMP      R1,#+0
        BEQ.N    ??cJSON_Minify_2
        CMP      R1,#+32
        IT       NE 
        CMPNE    R1,#+9
        BEQ.N    ??cJSON_Minify_1
        CMP      R1,#+13
        IT       NE 
        CMPNE    R1,#+10
        BEQ.N    ??cJSON_Minify_1
        CMP      R1,#+47
        BNE.N    ??cJSON_Minify_3
        LDRSB    R1,[R0, #+1]
        CMP      R1,#+47
        BNE.N    ??cJSON_Minify_4
??cJSON_Minify_5:
        LDRSB    R1,[R0, #+0]
        CMP      R1,#+0
        ITT      NE 
        CMPNE    R1,#+10
        ADDNE    R0,R0,#+1
        BNE.N    ??cJSON_Minify_5
        B.N      ??cJSON_Minify_0
??cJSON_Minify_3:
        CMP      R1,#+34
        BNE.N    ??cJSON_Minify_6
        STRB     R1,[R2], #+1
        ADDS     R0,R0,#+1
        MOV      R3,R2
??cJSON_Minify_7:
        LDRSB    R1,[R0, #+0]
        CBZ.N    R1,??cJSON_Minify_8
        CMP      R1,#+34
        BEQ.N    ??cJSON_Minify_8
        CMP      R1,#+92
        ITT      EQ 
        STRBEQ   R1,[R3], #+1
        ADDEQ    R0,R0,#+1
        LDRB     R2,[R0], #+1
        STRB     R2,[R3], #+1
        B.N      ??cJSON_Minify_7
??cJSON_Minify_4:
        CMP      R1,#+42
        BEQ.N    ??cJSON_Minify_9
??cJSON_Minify_6:
        LDRB     R3,[R0], #+1
        STRB     R3,[R2], #+1
        B.N      ??cJSON_Minify_0
??cJSON_Minify_10:
        CMP      R1,#+42
        ITTE     EQ 
        LDRSBEQ  R1,[R0, #+1]
        CMPEQ    R1,#+47
        ADDNE    R0,R0,#+1
        BNE.N    ??cJSON_Minify_9
        B.N      ??cJSON_Minify_11
??cJSON_Minify_2:
        MOVS     R0,#+0
        STRB     R0,[R2, #+0]
        BX       LR               ;; return
??cJSON_Minify_9:
        LDRSB    R1,[R0, #+0]
        CMP      R1,#+0
        BNE.N    ??cJSON_Minify_10
??cJSON_Minify_11:
        ADDS     R0,R0,#+2
        B.N      ??cJSON_Minify_0
??cJSON_Minify_8:
        LDRB     R1,[R0], #+1
        MOV      R2,R3
        STRB     R1,[R2], #+1
        B.N      ??cJSON_Minify_0

        SECTION `.iar_vfe_header`:DATA:NOALLOC:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
        DC32 0

        END
// 
//     4 bytes in section .bss
//     8 bytes in section .data
//    73 bytes in section .rodata
// 4 288 bytes in section .text
// 
// 4 288 bytes of CODE  memory
//    73 bytes of CONST memory
//    12 bytes of DATA  memory
//
//Errors: none
//Warnings: none
