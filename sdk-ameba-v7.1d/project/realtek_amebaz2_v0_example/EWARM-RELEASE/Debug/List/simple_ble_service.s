///////////////////////////////////////////////////////////////////////////////
//
// IAR ANSI C/C++ Compiler V8.30.1.114/W32 for ARM        24/Sep/2021  15:45:10
// Copyright 1999-2018 IAR Systems AB.
//
//    Cpu mode     =  thumb
//    Endian       =  little
//    Source file  =  
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\component\common\bluetooth\realtek\sdk\src\ble\profile\server\simple_ble_service.c
//    Command line =  
//        -f C:\Users\ADMINI~1\AppData\Local\Temp\EWD5DC.tmp
//        (F:\lxd\src2\hisen\sdk-ameba-v7.1d\component\common\bluetooth\realtek\sdk\src\ble\profile\server\simple_ble_service.c
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
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\Debug\List\simple_ble_service.s
//
///////////////////////////////////////////////////////////////////////////////

        #define SHT_PROGBITS 0x1

        EXTERN memcpy
        EXTERN server_add_service
        EXTERN server_send_data
        EXTERN trace_log_buffer

        PUBLIC simp_ble_service_add_service
        PUBLIC simp_ble_service_attr_read_cb
        PUBLIC simp_ble_service_attr_write_cb
        PUBLIC simp_ble_service_cbs
        PUBLIC simp_ble_service_cccd_update_cb
        PUBLIC simp_ble_service_send_v3_notify
        PUBLIC simp_ble_service_send_v4_indicate
        PUBLIC simp_ble_service_set_parameter
        PUBLIC simp_service_id
        PUBLIC simple_ble_service_tbl
        PUBLIC simple_write_post_callback
        PUBLIC v1_user_descr


        SECTION `.bss`:DATA:REORDER:NOROOT(0)
        DATA
simp_service_id:
        DS8 1

        SECTION `.bss`:DATA:REORDER:NOROOT(2)
        DATA
simple_char_read_value:
        DS8 300

        SECTION `.data`:DATA:REORDER:NOROOT(1)
        DATA
simple_char_read_len:
        DC16 1

        SECTION `.data`:DATA:REORDER:NOROOT(2)
        DATA
v1_user_descr:
        DC8 "V1 read characteristic"
        DC8 0

        SECTION `.bss`:DATA:REORDER:NOROOT(2)
        DATA
pfn_simp_ble_service_cb:
        DS8 4

        SECTION `.rodata`:CONST:REORDER:NOROOT(2)
        DATA
simple_ble_service_tbl:
        DC16 2050
        DC8 0, 40, 10, 160, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
        DC16 2
        DC32 0H, 1
        DC16 2
        DC8 3, 40, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
        DC16 1
        DC32 0H, 1
        DC16 4
        DC8 1, 176, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
        DC16 0
        DC32 0H, 1
        DC16 8
        DC8 1, 41, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
        DC16 22
        DC32 v1_user_descr, 1
        DC16 2
        DC8 3, 40, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
        DC16 1
        DC32 0H, 1
        DC16 4
        DC8 2, 176, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
        DC16 0
        DC32 0H, 16
        DC16 2
        DC8 3, 40, 16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
        DC16 1
        DC32 0H, 1
        DC16 4
        DC8 3, 176, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
        DC16 0
        DC32 0H, 0
        DC16 18
        DC8 2, 41, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
        DC16 2
        DC32 0H, 17
        DC16 2
        DC8 3, 40, 32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
        DC16 1
        DC32 0H, 1
        DC16 4
        DC8 4, 176, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
        DC16 0
        DC32 0H, 0
        DC16 18
        DC8 2, 41, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
        DC16 2
        DC32 0H, 17

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
simp_ble_service_set_parameter:
        PUSH     {R3-R5,LR}
        MOV      R4,R1
        MOVS     R5,#+1
        MOV      R1,R2
        CMP      R0,#+1
        BNE.N    ??simp_ble_service_set_parameter_0
        MOVW     R2,#+301
        CMP      R4,R2
        BGE.N    ??simp_ble_service_set_parameter_0
        MOV      R2,R4
        LDR.N    R0,??DataTable7
        BL       memcpy
        LDR.N    R1,??DataTable7_1
        STRH     R4,[R1, #+0]
        B.N      ??simp_ble_service_set_parameter_1
??simp_ble_service_set_parameter_0:
        MOVS     R2,#+0
        LDR.N    R1,??DataTable7_2
        LDR.N    R0,??DataTable7_3  ;; 0x3f103000
        MOVS     R5,#+0
        BL       trace_log_buffer
??simp_ble_service_set_parameter_1:
        MOV      R0,R5
        POP      {R1,R4,R5,PC}    ;; return

        SECTION `.BTTRACE`:CONST:REORDER:NOROOT(2)
        DATA
`simp_ble_service_set_parameter{4}{5}{6}{7}::format`:
        DC8 "!!!simp_ble_service_set_parameter failed"
        DC8 0, 0, 0

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
simp_ble_service_attr_read_cb:
        PUSH     {R0-R4,LR}
        MOVS     R4,#+0
        MOV      R3,R1
        CMP      R2,#+2
        BEQ.N    ??simp_ble_service_attr_read_cb_0
        MOV      R3,R2
        MOVS     R2,#+1
        LDR.N    R1,??DataTable7_4
        LDR.N    R0,??DataTable7_3  ;; 0x3f103000
        BL       trace_log_buffer
        MOVW     R4,#+1034
        B.N      ??simp_ble_service_attr_read_cb_1
??simp_ble_service_attr_read_cb_0:
        STRB     R2,[SP, #+1]
        MOVS     R2,#+1
        STRB     R0,[SP, #+0]
        STRB     R2,[SP, #+4]
        LDR.N    R0,??DataTable7_5
        LDR      R2,[R0, #+0]
        CBZ.N    R2,??simp_ble_service_attr_read_cb_2
        MOV      R1,SP
        MOV      R0,R3
        BLX      R2
??simp_ble_service_attr_read_cb_2:
        LDR      R1,[SP, #+28]
        LDR      R0,[SP, #+24]
        LDR.N    R2,??DataTable7
        STR      R2,[R1, #+0]
        LDR.N    R1,??DataTable7_1
        LDRH     R3,[R1, #+0]
        STRH     R3,[R0, #+0]
??simp_ble_service_attr_read_cb_1:
        MOV      R0,R4
        ADD      SP,SP,#+16
        POP      {R4,PC}          ;; return

        SECTION `.BTTRACE`:CONST:REORDER:NOROOT(2)
        DATA
`simp_ble_service_attr_read_cb{1}{2}{3}{4}::format`:
        DC8 21H, 21H, 21H, 73H, 69H, 6DH, 70H, 5FH
        DC8 62H, 6CH, 65H, 5FH, 73H, 65H, 72H, 76H
        DC8 69H, 63H, 65H, 5FH, 61H, 74H, 74H, 72H
        DC8 5FH, 72H, 65H, 61H, 64H, 5FH, 63H, 62H
        DC8 2CH, 20H, 41H, 74H, 74H, 72H, 20H, 6EH
        DC8 6FH, 74H, 20H, 66H, 6FH, 75H, 6EH, 64H
        DC8 2CH, 20H, 69H, 6EH, 64H, 65H, 78H, 20H
        DC8 25H, 64H, 0
        DC8 0

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
simple_write_post_callback:
        PUSH     {R5-R7,LR}
        STR      R3,[SP, #+8]
        STR      R2,[SP, #+4]
        STR      R1,[SP, #+0]
        MOV      R3,R0
        MOVS     R2,#+4
        LDR.N    R1,??DataTable7_6
        LDR.N    R0,??DataTable7_7  ;; 0x3f103002
        BL       trace_log_buffer
        POP      {R0-R2,PC}       ;; return

        SECTION `.BTTRACE`:CONST:REORDER:NOROOT(2)
        DATA
`simple_write_post_callback{1}{2}::format`:
        DC8 21H, 2AH, 2AH, 73H, 69H, 6DH, 70H, 6CH
        DC8 65H, 5FH, 77H, 72H, 69H, 74H, 65H, 5FH
        DC8 70H, 6FH, 73H, 74H, 5FH, 63H, 61H, 6CH
        DC8 6CH, 62H, 61H, 63H, 6BH, 3AH, 20H, 63H
        DC8 6FH, 6EH, 6EH, 5FH, 69H, 64H, 20H, 25H
        DC8 64H, 2CH, 20H, 73H, 65H, 72H, 76H, 69H
        DC8 63H, 65H, 5FH, 69H, 64H, 20H, 25H, 64H
        DC8 2CH, 20H, 61H, 74H, 74H, 72H, 69H, 62H
        DC8 5FH, 69H, 6EH, 64H, 65H, 78H, 20H, 30H
        DC8 78H, 25H, 78H, 2CH, 20H, 6CH, 65H, 6EH
        DC8 67H, 74H, 68H, 20H, 25H, 64H, 0
        DC8 0

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
simp_ble_service_attr_write_cb:
        PUSH     {R0-R10,LR}
        MOV      R10,R0
        MOV      R9,R1
        MOV      R4,R2
        MOV      R8,R3
        LDR      R5,[SP, #+48]
        LDR      R7,[SP, #+56]
        MOVS     R2,#+1
        LDR.N    R1,??DataTable7_8
        LDR.N    R0,??DataTable7_7  ;; 0x3f103002
        BL       trace_log_buffer
        MOVS     R6,#+0
        LDR.N    R1,??DataTable7_9
        STR      R1,[R7, #+0]
        CMP      R4,#+5
        BNE.N    ??simp_ble_service_attr_write_cb_0
        LDR      R0,[SP, #+52]
        CBNZ.N   R0,??simp_ble_service_attr_write_cb_1
        MOVW     R6,#+1037
        B.N      ??simp_ble_service_attr_write_cb_2
??simp_ble_service_attr_write_cb_1:
        MOVS     R2,#+3
        STRB     R2,[SP, #+5]
        MOVS     R2,#+1
        STR      R0,[SP, #+12]
        STRB     R2,[SP, #+8]
        LDR.N    R0,??DataTable7_5
        LDR      R2,[R0, #+0]
        STRB     R10,[SP, #+4]
        STRB     R8,[SP, #+9]
        STRH     R5,[SP, #+10]
        CBZ.N    R2,??simp_ble_service_attr_write_cb_2
        MOV      R0,R9
        ADD      R1,SP,#+4
        BLX      R2
        B.N      ??simp_ble_service_attr_write_cb_2
??simp_ble_service_attr_write_cb_0:
        STR      R5,[SP, #+0]
        MOV      R3,R4
        MOVS     R2,#+2
        LDR.N    R1,??DataTable7_10
        LDR.N    R0,??DataTable7_3  ;; 0x3f103000
        BL       trace_log_buffer
        MOVW     R6,#+1034
??simp_ble_service_attr_write_cb_2:
        MOV      R0,R6
        ADD      SP,SP,#+16
        POP      {R4-R10,PC}      ;; return

        SECTION `.BTTRACE`:CONST:REORDER:NOROOT(2)
        DATA
`simp_ble_service_attr_write_cb{2}{3}::format`:
        DC8 21H, 2AH, 2AH, 73H, 69H, 6DH, 70H, 5FH
        DC8 62H, 6CH, 65H, 5FH, 73H, 65H, 72H, 76H
        DC8 69H, 63H, 65H, 5FH, 61H, 74H, 74H, 72H
        DC8 5FH, 77H, 72H, 69H, 74H, 65H, 5FH, 63H
        DC8 62H, 20H, 77H, 72H, 69H, 74H, 65H, 5FH
        DC8 74H, 79H, 70H, 65H, 20H, 3DH, 20H, 30H
        DC8 78H, 25H, 78H, 0

        SECTION `.BTTRACE`:CONST:REORDER:NOROOT(2)
        DATA
`simp_ble_service_attr_write_cb{4}{9}{10}{11}::format`:
        DC8 21H, 21H, 21H, 73H, 69H, 6DH, 70H, 5FH
        DC8 62H, 6CH, 65H, 5FH, 73H, 65H, 72H, 76H
        DC8 69H, 63H, 65H, 5FH, 61H, 74H, 74H, 72H
        DC8 5FH, 77H, 72H, 69H, 74H, 65H, 5FH, 63H
        DC8 62H, 20H, 45H, 72H, 72H, 6FH, 72H, 3AH
        DC8 20H, 61H, 74H, 74H, 72H, 69H, 62H, 5FH
        DC8 69H, 6EH, 64H, 65H, 78H, 20H, 30H, 78H
        DC8 25H, 78H, 2CH, 20H, 6CH, 65H, 6EH, 67H
        DC8 74H, 68H, 20H, 25H, 64H, 0
        DC8 0, 0

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
simp_ble_service_send_v3_notify:
        PUSH     {R1-R7,LR}
        BL       ?Subroutine1
??CrossCallReturnLabel_0:
        LDR.N    R1,??DataTable7_11
        LDR.N    R0,??DataTable7_7  ;; 0x3f103002
        BL       trace_log_buffer
        MOVS     R1,#+0
        STR      R1,[SP, #+4]
        STR      R7,[SP, #+0]
        MOV      R3,R6
        MOVS     R2,#+7
        B.N      ?Subroutine0

        SECTION `.BTTRACE`:CONST:REORDER:NOROOT(2)
        DATA
`simp_ble_service_send_v3_notify{1}{2}::format`:
        DC8 "!**simp_ble_service_send_v3_notify"
        DC8 0

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
simp_ble_service_send_v4_indicate:
        PUSH     {R1-R7,LR}
        BL       ?Subroutine1
??CrossCallReturnLabel_1:
        LDR.N    R1,??DataTable7_12
        LDR.N    R0,??DataTable7_7  ;; 0x3f103002
        BL       trace_log_buffer
        MOVS     R1,#+0
        STR      R1,[SP, #+4]
        STR      R7,[SP, #+0]
        MOV      R3,R6
        MOVS     R2,#+10
        REQUIRE ?Subroutine0
        ;; // Fall through to label ?Subroutine0

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
?Subroutine0:
        MOV      R1,R5
        MOV      R0,R4
        BL       server_send_data
        POP      {R1-R7,PC}       ;; return

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
?Subroutine1:
        MOV      R4,R0
        MOV      R5,R1
        MOV      R6,R2
        MOV      R7,R3
        MOVS     R2,#+0
        BX       LR

        SECTION `.BTTRACE`:CONST:REORDER:NOROOT(2)
        DATA
`simp_ble_service_send_v4_indicate{1}{2}::format`:
        DC8 "!**simp_ble_service_send_v4_indicate"
        DC8 0, 0, 0

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
simp_ble_service_cccd_update_cb:
        PUSH     {R3-R7,LR}
        SUB      SP,SP,#+16
        STRB     R0,[SP, #+4]
        MOVS     R0,#+1
        MOV      R4,R1
        MOV      R6,R2
        MOV      R7,R3
        STRB     R0,[SP, #+5]
        STR      R3,[SP, #+0]
        MOV      R3,R6
        MOVS     R2,#+2
        LDR.N    R1,??DataTable7_13
        LDR.N    R0,??DataTable7_7  ;; 0x3f103002
        MOVS     R5,#+0
        BL       trace_log_buffer
        CMP      R6,#+8
        BEQ.N    ??simp_ble_service_cccd_update_cb_0
        CMP      R6,#+11
        BEQ.N    ??simp_ble_service_cccd_update_cb_1
        B.N      ??simp_ble_service_cccd_update_cb_2
??simp_ble_service_cccd_update_cb_0:
        LSLS     R0,R7,#+31
        IT       MI 
        MOVMI    R1,#+1
        BMI.N    ??simp_ble_service_cccd_update_cb_3
        MOVS     R0,#+2
        B.N      ??simp_ble_service_cccd_update_cb_4
??simp_ble_service_cccd_update_cb_1:
        LSLS     R0,R7,#+30
        BPL.N    ??simp_ble_service_cccd_update_cb_5
        MOVS     R1,#+3
??simp_ble_service_cccd_update_cb_3:
        STRB     R1,[SP, #+8]
        B.N      ??simp_ble_service_cccd_update_cb_6
??simp_ble_service_cccd_update_cb_5:
        MOVS     R0,#+4
??simp_ble_service_cccd_update_cb_4:
        STRB     R0,[SP, #+8]
??simp_ble_service_cccd_update_cb_6:
        MOVS     R5,#+1
??simp_ble_service_cccd_update_cb_2:
        LDR.N    R0,??DataTable7_5
        LDR      R2,[R0, #+0]
        CMP      R2,#+0
        IT       NE 
        CMPNE    R5,#+0
        BEQ.N    ??simp_ble_service_cccd_update_cb_7
        ADD      R1,SP,#+4
        MOV      R0,R4
        BLX      R2
??simp_ble_service_cccd_update_cb_7:
        ADD      SP,SP,#+20
        POP      {R4-R7,PC}       ;; return

        SECTION `.BTTRACE`:CONST:REORDER:NOROOT(2)
        DATA
`simp_ble_service_cccd_update_cb{2}{3}::format`:
        DC8 21H, 2AH, 2AH, 73H, 69H, 6DH, 70H, 5FH
        DC8 62H, 6CH, 65H, 5FH, 73H, 65H, 72H, 76H
        DC8 69H, 63H, 65H, 5FH, 63H, 63H, 63H, 64H
        DC8 5FH, 75H, 70H, 64H, 61H, 74H, 65H, 5FH
        DC8 63H, 62H, 3AH, 20H, 69H, 6EH, 64H, 65H
        DC8 78H, 20H, 3DH, 20H, 25H, 64H, 2CH, 20H
        DC8 63H, 63H, 63H, 62H, 69H, 74H, 73H, 20H
        DC8 30H, 78H, 25H, 78H, 0
        DC8 0, 0, 0

        SECTION `.rodata`:CONST:REORDER:NOROOT(2)
        DATA
simp_ble_service_cbs:
        DC32 simp_ble_service_attr_read_cb, simp_ble_service_attr_write_cb
        DC32 simp_ble_service_cccd_update_cb

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
simp_ble_service_add_service:
        PUSH     {R1-R5,LR}
        LDR.N    R3,??DataTable7_14
        MOV      R5,R0
        SUB      SP,SP,#+4
        LDM      R3!,{R1,R2}
        MOV      R0,SP
        LDR.N    R4,??DataTable7_15
        STM      R0!,{R1,R2}
        LDR      R1,[R3, #+0]
        MOV      R2,#+336
        STR      R1,[R0, #+0]
        POP      {R3}
        LDR.N    R1,??DataTable7_16
        MOV      R0,R4
        BL       server_add_service
        CBNZ.N   R0,??simp_ble_service_add_service_0
        MOVS     R2,#+0
        LDR.N    R1,??DataTable7_17
        LDR.N    R0,??DataTable7_3  ;; 0x3f103000
        BL       trace_log_buffer
        MOVS     R0,#+255
        STRB     R0,[R4, #+0]
        POP      {R1-R5,PC}
??simp_ble_service_add_service_0:
        LDR.N    R1,??DataTable7_5
        STR      R5,[R1, #+0]
        LDRB     R0,[R4, #+0]
        POP      {R1-R5,PC}       ;; return

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable7:
        DC32     simple_char_read_value

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable7_1:
        DC32     simple_char_read_len

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable7_2:
        DC32     `simp_ble_service_set_parameter{4}{5}{6}{7}::format`

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable7_3:
        DC32     0x3f103000

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable7_4:
        DC32     `simp_ble_service_attr_read_cb{1}{2}{3}{4}::format`

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable7_5:
        DC32     pfn_simp_ble_service_cb

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable7_6:
        DC32     `simple_write_post_callback{1}{2}::format`

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable7_7:
        DC32     0x3f103002

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable7_8:
        DC32     `simp_ble_service_attr_write_cb{2}{3}::format`

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable7_9:
        DC32     simple_write_post_callback

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable7_10:
        DC32     `simp_ble_service_attr_write_cb{4}{9}{10}{11}::format`

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable7_11:
        DC32     `simp_ble_service_send_v3_notify{1}{2}::format`

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable7_12:
        DC32     `simp_ble_service_send_v4_indicate{1}{2}::format`

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable7_13:
        DC32     `simp_ble_service_cccd_update_cb{2}{3}::format`

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable7_14:
        DC32     simp_ble_service_cbs

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable7_15:
        DC32     simp_service_id

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable7_16:
        DC32     simple_ble_service_tbl

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable7_17:
        DC32     `simp_ble_service_add_service{1}{2}{3}{4}::format`

        SECTION `.BTTRACE`:CONST:REORDER:NOROOT(2)
        DATA
`simp_ble_service_add_service{1}{2}{3}{4}::format`:
        DC8 "!!!simp_ble_service_add_service: fail"
        DC8 0, 0

        SECTION `.iar_vfe_header`:DATA:NOALLOC:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
        DC32 0

        END
// 
// 496 bytes in section .BTTRACE
// 305 bytes in section .bss
//  26 bytes in section .data
// 348 bytes in section .rodata
// 562 bytes in section .text
// 
// 562 bytes of CODE  memory
// 844 bytes of CONST memory
// 331 bytes of DATA  memory
//
//Errors: none
//Warnings: none
