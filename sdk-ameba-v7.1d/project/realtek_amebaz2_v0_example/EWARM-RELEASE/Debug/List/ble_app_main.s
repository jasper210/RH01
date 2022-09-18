///////////////////////////////////////////////////////////////////////////////
//
// IAR ANSI C/C++ Compiler V8.30.1.114/W32 for ARM        24/Sep/2021  15:44:10
// Copyright 1999-2018 IAR Systems AB.
//
//    Cpu mode     =  thumb
//    Endian       =  little
//    Source file  =  
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\component\common\bluetooth\realtek\sdk\example\ble_peripheral\ble_app_main.c
//    Command line =  
//        -f C:\Users\ADMINI~1\AppData\Local\Temp\EWE930.tmp
//        (F:\lxd\src2\hisen\sdk-ameba-v7.1d\component\common\bluetooth\realtek\sdk\example\ble_peripheral\ble_app_main.c
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
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\Debug\List\ble_app_main.s
//
///////////////////////////////////////////////////////////////////////////////

        #define SHT_PROGBITS 0x1

        EXTERN __aeabi_memcpy4
        EXTERN app_gap_callback
        EXTERN app_profile_callback
        EXTERN app_task_deinit
        EXTERN app_task_init
        EXTERN bas_add_service
        EXTERN bas_srv_id
        EXTERN bt_coex_init
        EXTERN bt_trace_init
        EXTERN bt_trace_uninit
        EXTERN bte_deinit
        EXTERN bte_init
        EXTERN gap_config_hci_task_secure_context
        EXTERN gap_config_max_le_link_num
        EXTERN gap_dev_state
        EXTERN gap_set_param
        EXTERN le_adv_set_param
        EXTERN le_bond_set_param
        EXTERN le_gap_init
        EXTERN le_get_gap_param
        EXTERN le_register_app_cb
        EXTERN le_set_gap_param
        EXTERN memset
        EXTERN printf
        EXTERN server_init
        EXTERN server_register_app_cb
        EXTERN simp_ble_service_add_service
        EXTERN simp_srv_id
        EXTERN vTaskDelay
        EXTERN wifi_btcoex_set_bt_on
        EXTERN wifi_is_up

        PUBLIC app_le_gap_init
        PUBLIC app_le_profile_init
        PUBLIC ble_app_deinit
        PUBLIC ble_app_init
        PUBLIC ble_app_main
        PUBLIC board_init
        PUBLIC bt_stack_config_init
        PUBLIC driver_init
        PUBLIC pwr_mgr_init
        PUBLIC task_init


        SECTION `.rodata`:CONST:REORDER:NOROOT(2)
        DATA
?_0:
        DC8 "BLE_PERIPHERAL"
        DC8 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
        DC8 0, 0, 0, 0, 0, 0, 0, 0, 0

        SECTION `.rodata`:CONST:REORDER:NOROOT(2)
        DATA
        DC8 0, 0, 0, 0, 0, 0, 0, 0

        SECTION `.rodata`:CONST:REORDER:NOROOT(2)
        DATA
?_2:
        DC8 "[BLE Peripheral]BT Stack already on\012\015"
        DC8 0, 0

        SECTION `.rodata`:CONST:REORDER:NOROOT(2)
        DATA
?_3:
        DC8 "[BLE Peripheral]BT Stack is not running\012\015"
        DC8 0, 0

        SECTION `.rodata`:CONST:REORDER:NOROOT(2)
        DATA
?_4:
        DC8 "[BLE Peripheral]BT Stack deinitalized\012\015"

        SECTION `.rodata`:CONST:REORDER:NOROOT(2)
        DATA
scan_rsp_data:
        DC8 3, 25, 0, 0

        SECTION `.rodata`:CONST:REORDER:NOROOT(2)
        DATA
adv_data:
        DC8 2, 1, 5, 3, 3, 10, 160, 15, 9, 66, 76, 69, 95, 80, 69, 82, 73, 80
        DC8 72, 69, 82, 65, 76, 0

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
bt_stack_config_init:
        PUSH     {R7,LR}
        MOVS     R0,#+1
        BL       gap_config_max_le_link_num
        MOV      R0,#+280
        POP      {R1,LR}
        B.W      gap_config_hci_task_secure_context

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
app_le_gap_init:
        PUSH     {R4,LR}
        SUB      SP,SP,#+72
        ADD      R0,SP,#+32
        LDR.N    R1,??DataTable4
        MOVS     R2,#+40
        BL       __aeabi_memcpy4
        MOVS     R2,#+7
        STRB     R2,[SP, #+5]
        MOV      R2,#+352
        STRH     R2,[SP, #+16]
        MOVS     R2,#+1
        STRB     R2,[SP, #+3]
        STRH     R2,[SP, #+12]
        ADD      R1,SP,#+24
        MOVS     R2,#+3
        STRB     R2,[SP, #+2]
        MOVS     R2,#+1
        MOVS     R4,#+0
        STRD     R4,R4,[R1, #+0]
        MOV      R1,#+384
        STRH     R1,[SP, #+14]
        STRH     R2,[SP, #+10]
        STRH     R4,[SP, #+18]
        STRB     R4,[SP, #+8]
        STRH     R4,[SP, #+6]
        STRB     R4,[SP, #+4]
        STR      R4,[SP, #+20]
        STRH     R4,[SP, #+0]
        ADD      R2,SP,#+32
        MOVS     R1,#+40
        MOVW     R0,#+546
        BL       le_set_gap_param
        ADD      R2,SP,#+18
        MOVS     R1,#+2
        MOVW     R0,#+545
        BL       le_set_gap_param
        ADD      R2,SP,#+8
        MOVS     R1,#+1
        MOVW     R0,#+547
        BL       le_set_gap_param
        ADD      R2,SP,#+7
        MOVS     R1,#+1
        MOVW     R0,#+611
        BL       le_adv_set_param
        ADD      R2,SP,#+6
        MOVS     R1,#+1
        MOV      R0,#+612
        BL       le_adv_set_param
        ADD      R2,SP,#+24
        MOVS     R1,#+6
        MOVW     R0,#+613
        BL       le_adv_set_param
        ADD      R2,SP,#+5
        MOVS     R1,#+1
        MOVW     R0,#+614
        BL       le_adv_set_param
        ADD      R2,SP,#+4
        MOVS     R1,#+1
        MOVW     R0,#+615
        BL       le_adv_set_param
        ADD      R2,SP,#+16
        MOVS     R1,#+2
        MOV      R0,#+616
        BL       le_adv_set_param
        ADD      R2,SP,#+14
        MOVS     R1,#+2
        MOVW     R0,#+617
        BL       le_adv_set_param
        LDR.N    R2,??DataTable4_1
        MOVS     R1,#+23
        MOVW     R0,#+609
        BL       le_adv_set_param
        LDR.N    R2,??DataTable4_2
        MOVS     R1,#+4
        MOVW     R0,#+610
        BL       le_adv_set_param
        ADD      R2,SP,#+3
        MOVS     R1,#+1
        MOVW     R0,#+514
        BL       gap_set_param
        ADD      R2,SP,#+12
        MOVS     R1,#+2
        MOVW     R0,#+515
        BL       gap_set_param
        ADD      R2,SP,#+2
        MOVS     R1,#+1
        MOV      R0,#+516
        BL       gap_set_param
        ADD      R2,SP,#+20
        MOVS     R1,#+4
        MOVW     R0,#+529
        BL       le_bond_set_param
        ADD      R2,SP,#+1
        MOVS     R1,#+1
        MOVW     R0,#+530
        BL       le_bond_set_param
        MOV      R2,SP
        MOVS     R1,#+1
        MOVW     R0,#+531
        BL       le_bond_set_param
        ADD      R2,SP,#+10
        MOVS     R1,#+2
        MOV      R0,#+532
        BL       le_bond_set_param
        LDR.N    R0,??DataTable4_3
        BL       le_register_app_cb
        ADD      SP,SP,#+72
        POP      {R4,PC}          ;; return

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
app_le_profile_init:
        PUSH     {R4,LR}
        MOVS     R0,#+2
        BL       server_init
        LDR.N    R4,??DataTable4_4
        MOV      R0,R4
        BL       simp_ble_service_add_service
        LDR.N    R1,??DataTable4_5
        STRB     R0,[R1, #+0]
        MOV      R0,R4
        BL       bas_add_service
        LDR.N    R2,??DataTable4_6
        STRB     R0,[R2, #+0]
        MOV      R0,R4
        POP      {R4,LR}
        B.W      server_register_app_cb

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
board_init:
        BX       LR               ;; return

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
driver_init:
        BX       LR               ;; return

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
pwr_mgr_init:
        BX       LR               ;; return

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
task_init:
        B.W      app_task_init

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
ble_app_main:
        PUSH     {R7,LR}
        BL       bt_trace_init
        MOVS     R0,#+1
        BL       gap_config_max_le_link_num
        MOV      R0,#+280
        BL       gap_config_hci_task_secure_context
        BL       bte_init
        MOVS     R0,#+1
        BL       le_gap_init
        BL       app_le_gap_init
        BL       app_le_profile_init
        BL       app_task_init
        MOVS     R0,#+0
        POP      {R1,PC}          ;; return

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
ble_app_init:
        PUSH     {R7,LR}
??ble_app_init_0:
        MOVS     R0,#+0
        BL       wifi_is_up
        CBNZ.N   R0,??ble_app_init_1
        MOVS     R0,#+1
        BL       wifi_is_up
        CBNZ.N   R0,??ble_app_init_1
        MOV      R0,#+1000
        BL       vTaskDelay
        B.N      ??ble_app_init_0
??ble_app_init_2:
        BL       ble_app_main
        BL       bt_coex_init
??ble_app_init_3:
        MOVS     R0,#+100
        BL       vTaskDelay
        BL       ?Subroutine0
??CrossCallReturnLabel_2:
        LDRB     R0,[SP, #+0]
        LSLS     R1,R0,#+31
        BPL.N    ??ble_app_init_3
        BL       wifi_btcoex_set_bt_on
??ble_app_init_4:
        MOVS     R0,#+0
        POP      {R1,PC}          ;; return
??ble_app_init_1:
        BL       ?Subroutine0
??CrossCallReturnLabel_1:
        LDRB     R0,[SP, #+0]
        LSLS     R1,R0,#+31
        BPL.N    ??ble_app_init_2
        LDR.N    R0,??DataTable4_7
        BL       printf
        B.N      ??ble_app_init_4

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
ble_app_deinit:
        PUSH     {R7,LR}
        BL       app_task_deinit
        BL       ?Subroutine0
??CrossCallReturnLabel_0:
        LDRB     R0,[SP, #+0]
        LSLS     R1,R0,#+31
        IT       PL 
        LDRPL.N  R0,??DataTable4_8
        BPL.N    ??ble_app_deinit_0
        BL       bte_deinit
        BL       bt_trace_uninit
        MOVS     R2,#+1
        MOVS     R1,#+0
        LDR.N    R0,??DataTable4_9
        BL       memset
        LDR.N    R0,??DataTable4_10
??ble_app_deinit_0:
        BL       printf
        POP      {R0,PC}          ;; return

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable4:
        DC32     ?_0

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable4_1:
        DC32     adv_data

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable4_2:
        DC32     scan_rsp_data

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable4_3:
        DC32     app_gap_callback

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable4_4:
        DC32     app_profile_callback

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable4_5:
        DC32     simp_srv_id

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable4_6:
        DC32     bas_srv_id

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable4_7:
        DC32     ?_2

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable4_8:
        DC32     ?_3

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable4_9:
        DC32     gap_dev_state

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable4_10:
        DC32     ?_4

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
?Subroutine0:
        MOV      R1,SP
        MOV      R0,#+544
        B.W      le_get_gap_param

        SECTION `.iar_vfe_header`:DATA:NOALLOC:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
        DC32 0

        END
// 
// 200 bytes in section .rodata
// 644 bytes in section .text
// 
// 644 bytes of CODE  memory
// 200 bytes of CONST memory
//
//Errors: none
//Warnings: none
