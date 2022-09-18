///////////////////////////////////////////////////////////////////////////////
//
// IAR ANSI C/C++ Compiler V8.30.1.114/W32 for ARM        24/Sep/2021  15:45:03
// Copyright 1999-2018 IAR Systems AB.
//
//    Cpu mode     =  thumb
//    Endian       =  little
//    Source file  =  
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\component\common\bluetooth\realtek\sdk\example\ble_peripheral\peripheral_app.c
//    Command line =  
//        -f C:\Users\ADMINI~1\AppData\Local\Temp\EWB8FF.tmp
//        (F:\lxd\src2\hisen\sdk-ameba-v7.1d\component\common\bluetooth\realtek\sdk\example\ble_peripheral\peripheral_app.c
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
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\Debug\List\peripheral_app.s
//
///////////////////////////////////////////////////////////////////////////////

        #define SHT_PROGBITS 0x1

        EXTERN bas_set_parameter
        EXTERN ble_peripheral_app_handle_at_cmd
        EXTERN le_adv_start
        EXTERN le_adv_stop
        EXTERN le_bond_get_display_key
        EXTERN le_bond_just_work_confirm
        EXTERN le_bond_passkey_display_confirm
        EXTERN le_get_conn_addr
        EXTERN le_get_conn_param
        EXTERN memcpy
        EXTERN printf
        EXTERN simp_ble_service_set_parameter
        EXTERN trace_bdaddr
        EXTERN trace_log_buffer

        PUBLIC app_gap_callback
        PUBLIC app_handle_authen_state_evt
        PUBLIC app_handle_conn_mtu_info_evt
        PUBLIC app_handle_conn_param_update_evt
        PUBLIC app_handle_conn_state_evt
        PUBLIC app_handle_dev_state_evt
        PUBLIC app_handle_gap_msg
        PUBLIC app_handle_io_msg
        PUBLIC app_profile_callback
        PUBLIC bas_srv_id
        PUBLIC gap_conn_state
        PUBLIC gap_dev_state
        PUBLIC simp_srv_id


        SECTION `.bss`:DATA:REORDER:NOROOT(0)
        DATA
simp_srv_id:
        DS8 1

        SECTION `.bss`:DATA:REORDER:NOROOT(0)
        DATA
bas_srv_id:
        DS8 1

        SECTION `.bss`:DATA:REORDER:NOROOT(0)
        DATA
gap_dev_state:
        DS8 1

        SECTION `.bss`:DATA:REORDER:NOROOT(0)
        DATA
gap_conn_state:
        DS8 1

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
app_handle_io_msg:
        PUSH     {R0,R1,LR}
        SUB      SP,SP,#+4
        LDRH     R0,[SP, #+4]
        CBZ.N    R0,??app_handle_io_msg_0
        CMP      R0,#+2
        BEQ.N    ??app_handle_io_msg_1
        CMP      R0,#+18
        BEQ.N    ??app_handle_io_msg_2
        POP      {R0-R2,PC}
??app_handle_io_msg_0:
        ADD      R0,SP,#+4
        BL       app_handle_gap_msg
        POP      {R0-R2,PC}
??app_handle_io_msg_2:
        LDRH     R0,[SP, #+6]
        BL       ble_peripheral_app_handle_at_cmd
        POP      {R0-R2,PC}
??app_handle_io_msg_1:
        LDRH     R0,[SP, #+6]
        CMP      R0,#+1
        BNE.N    ??app_handle_io_msg_3
        BL       le_adv_start
        POP      {R0-R2,PC}
??app_handle_io_msg_3:
        CBNZ.N   R0,??app_handle_io_msg_4
        BL       le_adv_stop
??app_handle_io_msg_4:
        POP      {R0-R2,PC}       ;; return

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
app_handle_dev_state_evt:
        PUSH     {R0,R4-R6,LR}
        SUB      SP,SP,#+12
        LDRB     R0,[SP, #+12]
        LDRB     R3,[SP, #+12]
        UXTH     R1,R1
        LDR.W    R4,??DataTable9  ;; 0x3f103002
        UBFX     R5,R0,#+2,#+2
        STR      R1,[SP, #+4]
        STR      R5,[SP, #+0]
        AND      R3,R3,#0x1
        MOVS     R2,#+3
        LDR.W    R1,??DataTable9_1
        MOV      R0,R4
        BL       trace_log_buffer
        LDR.W    R6,??DataTable9_2
        LDRB     R0,[R6, #+0]
        LDRB     R1,[SP, #+12]
        AND      R0,R0,#0x1
        AND      R1,R1,#0x1
        CMP      R0,R1
        BEQ.N    ??app_handle_dev_state_evt_0
        LDRB     R0,[SP, #+12]
        LSLS     R1,R0,#+31
        BPL.N    ??app_handle_dev_state_evt_0
        MOVS     R2,#+0
        LDR.W    R1,??DataTable9_3
        BL       ?Subroutine0
??CrossCallReturnLabel_5:
        LDR.W    R0,??DataTable9_4
        BL       printf
        BL       le_adv_start
??app_handle_dev_state_evt_0:
        LDRB     R0,[R6, #+0]
        UBFX     R0,R0,#+2,#+2
        CMP      R0,R5
        BEQ.N    ??app_handle_dev_state_evt_1
        MOVS     R0,R5
        BNE.N    ??app_handle_dev_state_evt_2
        LDRB     R0,[SP, #+12]
        UBFX     R0,R0,#+1,#+1
        CBZ.N    R0,??app_handle_dev_state_evt_3
        MOVS     R2,#+0
        LDR.W    R1,??DataTable9_5
        BL       ?Subroutine0
??CrossCallReturnLabel_4:
        LDR.W    R0,??DataTable9_6
        B.N      ??app_handle_dev_state_evt_4
??app_handle_dev_state_evt_3:
        MOVS     R2,#+0
        LDR.W    R1,??DataTable9_7
        BL       ?Subroutine0
??CrossCallReturnLabel_3:
        LDR.W    R0,??DataTable9_8
        B.N      ??app_handle_dev_state_evt_4
??app_handle_dev_state_evt_2:
        CMP      R5,#+2
        BNE.N    ??app_handle_dev_state_evt_1
        MOVS     R2,#+0
        LDR.W    R1,??DataTable9_9
        BL       ?Subroutine0
??CrossCallReturnLabel_2:
        LDR.W    R0,??DataTable9_10
??app_handle_dev_state_evt_4:
        BL       printf
??app_handle_dev_state_evt_1:
        LDRB     R0,[SP, #+12]
        STRB     R0,[R6, #+0]
        POP      {R0-R6,PC}       ;; return

        SECTION `.BTTRACE`:CONST:REORDER:NOROOT(2)
        DATA
`app_handle_dev_state_evt{1}{2}::format`:
        DC8 21H, 2AH, 2AH, 61H, 70H, 70H, 5FH, 68H
        DC8 61H, 6EH, 64H, 6CH, 65H, 5FH, 64H, 65H
        DC8 76H, 5FH, 73H, 74H, 61H, 74H, 65H, 5FH
        DC8 65H, 76H, 74H, 3AH, 20H, 69H, 6EH, 69H
        DC8 74H, 20H, 73H, 74H, 61H, 74H, 65H, 20H
        DC8 25H, 64H, 2CH, 20H, 61H, 64H, 76H, 20H
        DC8 73H, 74H, 61H, 74H, 65H, 20H, 25H, 64H
        DC8 2CH, 20H, 63H, 61H, 75H, 73H, 65H, 20H
        DC8 30H, 78H, 25H, 78H, 0
        DC8 0, 0, 0

        SECTION `.BTTRACE`:CONST:REORDER:NOROOT(2)
        DATA
`app_handle_dev_state_evt{3}{4}{5}{6}{7}{8}::format`:
        DC8 "!**GAP stack ready"
        DC8 0

        SECTION `.BTTRACE`:CONST:REORDER:NOROOT(2)
        DATA
`app_handle_dev_state_evt{9}{10}{11}{12}{13}{14}{15}{16}::format`:
        DC8 "!**GAP adv stoped: because connection created"
        DC8 0, 0

        SECTION `.BTTRACE`:CONST:REORDER:NOROOT(2)
        DATA
`app_handle_dev_state_evt{9}{10}{11}{12}{13}{17}{18}{19}::format`:
        DC8 "!**GAP adv stoped"
        DC8 0, 0

        SECTION `.BTTRACE`:CONST:REORDER:NOROOT(2)
        DATA
`app_handle_dev_state_evt{9}{10}{11}{20}{21}{22}{23}{24}::format`:
        DC8 "!**GAP adv start"
        DC8 0, 0, 0

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
app_handle_conn_state_evt:
        PUSH     {R4-R8,LR}
        LDR.W    R6,??DataTable9_11
        LDRSB    R3,[R6, #+0]
        SUB      SP,SP,#+32
        MOV      R5,R0
        MOV      R4,R1
        MOV      R7,R2
        LDR.W    R8,??DataTable9  ;; 0x3f103002
        STR      R3,[SP, #+0]
        STR      R7,[SP, #+8]
        STR      R4,[SP, #+4]
        MOV      R3,R5
        MOVS     R2,#+4
        LDR.W    R1,??DataTable9_12
        MOV      R0,R8
        BL       trace_log_buffer
        CBZ.N    R4,??app_handle_conn_state_evt_0
        CMP      R4,#+2
        BEQ.N    ??app_handle_conn_state_evt_1
        B.N      ??app_handle_conn_state_evt_2
??app_handle_conn_state_evt_0:
        MOVW     R2,#+275
        CMP      R7,R2
        IT       NE 
        CMPNE    R7,#+278
        BEQ.N    ??CrossCallReturnLabel_14
        MOV      R3,R7
        MOVS     R2,#+1
        LDR.W    R1,??DataTable9_13
        BL       ?Subroutine2
??CrossCallReturnLabel_14:
        LDR.W    R0,??DataTable9_14
        BL       printf
        BL       le_adv_start
        B.N      ??app_handle_conn_state_evt_2
??app_handle_conn_state_evt_1:
        MOV      R2,R5
        ADD      R1,SP,#+22
        MOVW     R0,#+626
        BL       le_get_conn_param
        MOV      R2,R5
        ADD      R1,SP,#+20
        MOVW     R0,#+627
        BL       le_get_conn_param
        MOV      R2,R5
        ADD      R1,SP,#+18
        MOV      R0,#+628
        BL       le_get_conn_param
        ADD      R2,SP,#+16
        ADD      R1,SP,#+24
        MOV      R0,R5
        BL       le_get_conn_addr
        ADD      R1,SP,#+24
        LDR.W    R0,??DataTable9_15  ;; 0x3f300000
        BL       trace_bdaddr
        MOV      R3,R0
        LDRH     R0,[SP, #+18]
        LDRH     R1,[SP, #+20]
        STR      R0,[SP, #+12]
        LDRH     R0,[SP, #+22]
        STR      R1,[SP, #+8]
        LDRSB    R1,[SP, #+16]
        STR      R0,[SP, #+4]
        MOVS     R2,#+5
        STR      R1,[SP, #+0]
        LDR.W    R1,??DataTable9_16
        MOV      R0,R8
        BL       trace_log_buffer
        LDR.W    R0,??DataTable9_17
        BL       printf
??app_handle_conn_state_evt_2:
        STRB     R4,[R6, #+0]
        ADD      SP,SP,#+32
        POP      {R4-R8,PC}       ;; return

        SECTION `.BTTRACE`:CONST:REORDER:NOROOT(2)
        DATA
`app_handle_conn_state_evt{1}{2}::format`:
        DC8 21H, 2AH, 2AH, 61H, 70H, 70H, 5FH, 68H
        DC8 61H, 6EH, 64H, 6CH, 65H, 5FH, 63H, 6FH
        DC8 6EH, 6EH, 5FH, 73H, 74H, 61H, 74H, 65H
        DC8 5FH, 65H, 76H, 74H, 3AH, 20H, 63H, 6FH
        DC8 6EH, 6EH, 5FH, 69H, 64H, 20H, 25H, 64H
        DC8 20H, 6FH, 6CH, 64H, 5FH, 73H, 74H, 61H
        DC8 74H, 65H, 20H, 25H, 64H, 20H, 6EH, 65H
        DC8 77H, 5FH, 73H, 74H, 61H, 74H, 65H, 20H
        DC8 25H, 64H, 2CH, 20H, 64H, 69H, 73H, 63H
        DC8 5FH, 63H, 61H, 75H, 73H, 65H, 20H, 30H
        DC8 78H, 25H, 78H, 0

        SECTION `.BTTRACE`:CONST:REORDER:NOROOT(2)
        DATA
`app_handle_conn_state_evt{3}{4}{5}{6}{7}{8}{9}::format`:
        DC8 21H, 21H, 21H, 61H, 70H, 70H, 5FH, 68H
        DC8 61H, 6EH, 64H, 6CH, 65H, 5FH, 63H, 6FH
        DC8 6EH, 6EH, 5FH, 73H, 74H, 61H, 74H, 65H
        DC8 5FH, 65H, 76H, 74H, 3AH, 20H, 63H, 6FH
        DC8 6EH, 6EH, 65H, 63H, 74H, 69H, 6FH, 6EH
        DC8 20H, 6CH, 6FH, 73H, 74H, 20H, 63H, 61H
        DC8 75H, 73H, 65H, 20H, 30H, 78H, 25H, 78H
        DC8 0
        DC8 0, 0, 0

        SECTION `.BTTRACE`:CONST:REORDER:NOROOT(2)
        DATA
`app_handle_conn_state_evt{3}{4}{10}{16}{17}::format`:
        DC8 21H, 2AH, 2AH, 47H, 41H, 50H, 5FH, 43H
        DC8 4FH, 4EH, 4EH, 5FH, 53H, 54H, 41H, 54H
        DC8 45H, 5FH, 43H, 4FH, 4EH, 4EH, 45H, 43H
        DC8 54H, 45H, 44H, 3AH, 72H, 65H, 6DH, 6FH
        DC8 74H, 65H, 5FH, 62H, 64H, 20H, 25H, 73H
        DC8 2CH, 20H, 72H, 65H, 6DH, 6FH, 74H, 65H
        DC8 5FH, 61H, 64H, 64H, 72H, 5FH, 74H, 79H
        DC8 70H, 65H, 20H, 25H, 64H, 2CH, 20H, 63H
        DC8 6FH, 6EH, 6EH, 5FH, 69H, 6EH, 74H, 65H
        DC8 72H, 76H, 61H, 6CH, 20H, 30H, 78H, 25H
        DC8 78H, 2CH, 20H, 63H, 6FH, 6EH, 6EH, 5FH
        DC8 6CH, 61H, 74H, 65H, 6EH, 63H, 79H, 20H
        DC8 30H, 78H, 25H, 78H, 2CH, 20H, 63H, 6FH
        DC8 6EH, 6EH, 5FH, 73H, 75H, 70H, 65H, 72H
        DC8 76H, 69H, 73H, 69H, 6FH, 6EH, 5FH, 74H
        DC8 69H, 6DH, 65H, 6FH, 75H, 74H, 20H, 30H
        DC8 78H, 25H, 78H, 0

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
app_handle_authen_state_evt:
        PUSH     {R2-R5,R7,LR}
        MOV      R3,R0
        MOV      R4,R1
        MOV      R5,R2
        LDR.W    R7,??DataTable9  ;; 0x3f103002
        STR      R5,[SP, #+0]
        MOVS     R2,#+2
        LDR.W    R1,??DataTable9_18
        MOV      R0,R7
        BL       trace_log_buffer
        MOVS     R0,R4
        BEQ.N    ??app_handle_authen_state_evt_0
        CMP      R4,#+1
        BEQ.N    ??app_handle_authen_state_evt_1
        B.N      ??app_handle_authen_state_evt_2
??app_handle_authen_state_evt_0:
        MOVS     R2,#+0
        LDR.W    R1,??DataTable9_19
        B.N      ??app_handle_authen_state_evt_3
??app_handle_authen_state_evt_1:
        CBNZ.N   R5,??app_handle_authen_state_evt_4
        LDR.W    R0,??DataTable9_20
        BL       printf
        MOVS     R2,#+0
        LDR.W    R1,??DataTable9_21
        B.N      ??app_handle_authen_state_evt_3
??app_handle_authen_state_evt_4:
        MOV      R1,R5
        LDR.W    R0,??DataTable9_22
        BL       printf
        MOVS     R2,#+0
        LDR.W    R1,??DataTable9_23
??app_handle_authen_state_evt_3:
        MOV      R0,R7
        ADD      SP,SP,#+8
        POP      {R4,R5,R7,LR}
        B.W      trace_log_buffer
??app_handle_authen_state_evt_2:
        MOV      R3,R4
        ADD      SP,SP,#+8
        MOVS     R2,#+1
        LDR.W    R1,??DataTable9_24
        LDR.W    R0,??DataTable9_25  ;; 0x3f103000
        POP      {R4,R5,R7,LR}
        B.W      trace_log_buffer

        SECTION `.BTTRACE`:CONST:REORDER:NOROOT(2)
        DATA
`app_handle_authen_state_evt{1}{2}::format`:
        DC8 21H, 2AH, 2AH, 61H, 70H, 70H, 5FH, 68H
        DC8 61H, 6EH, 64H, 6CH, 65H, 5FH, 61H, 75H
        DC8 74H, 68H, 65H, 6EH, 5FH, 73H, 74H, 61H
        DC8 74H, 65H, 5FH, 65H, 76H, 74H, 3AH, 63H
        DC8 6FH, 6EH, 6EH, 5FH, 69H, 64H, 20H, 25H
        DC8 64H, 2CH, 20H, 63H, 61H, 75H, 73H, 65H
        DC8 20H, 30H, 78H, 25H, 78H, 0
        DC8 0, 0

        SECTION `.BTTRACE`:CONST:REORDER:NOROOT(2)
        DATA
`app_handle_authen_state_evt{3}{4}{5}{6}{7}::format`:
        DC8 21H, 2AH, 2AH, 61H, 70H, 70H, 5FH, 68H
        DC8 61H, 6EH, 64H, 6CH, 65H, 5FH, 61H, 75H
        DC8 74H, 68H, 65H, 6EH, 5FH, 73H, 74H, 61H
        DC8 74H, 65H, 5FH, 65H, 76H, 74H, 3AH, 20H
        DC8 47H, 41H, 50H, 5FH, 41H, 55H, 54H, 48H
        DC8 45H, 4EH, 5FH, 53H, 54H, 41H, 54H, 45H
        DC8 5FH, 53H, 54H, 41H, 52H, 54H, 45H, 44H
        DC8 0
        DC8 0, 0, 0

        SECTION `.BTTRACE`:CONST:REORDER:NOROOT(2)
        DATA
`app_handle_authen_state_evt{3}{4}{8}{9}{10}{11}{12}::format`:
        DC8 21H, 2AH, 2AH, 61H, 70H, 70H, 5FH, 68H
        DC8 61H, 6EH, 64H, 6CH, 65H, 5FH, 61H, 75H
        DC8 74H, 68H, 65H, 6EH, 5FH, 73H, 74H, 61H
        DC8 74H, 65H, 5FH, 65H, 76H, 74H, 3AH, 20H
        DC8 47H, 41H, 50H, 5FH, 41H, 55H, 54H, 48H
        DC8 45H, 4EH, 5FH, 53H, 54H, 41H, 54H, 45H
        DC8 5FH, 43H, 4FH, 4DH, 50H, 4CH, 45H, 54H
        DC8 45H, 20H, 70H, 61H, 69H, 72H, 20H, 73H
        DC8 75H, 63H, 63H, 65H, 73H, 73H, 0
        DC8 0

        SECTION `.BTTRACE`:CONST:REORDER:NOROOT(2)
        DATA
`app_handle_authen_state_evt{3}{4}{8}{9}{13}{14}{15}::format`:
        DC8 21H, 2AH, 2AH, 61H, 70H, 70H, 5FH, 68H
        DC8 61H, 6EH, 64H, 6CH, 65H, 5FH, 61H, 75H
        DC8 74H, 68H, 65H, 6EH, 5FH, 73H, 74H, 61H
        DC8 74H, 65H, 5FH, 65H, 76H, 74H, 3AH, 20H
        DC8 47H, 41H, 50H, 5FH, 41H, 55H, 54H, 48H
        DC8 45H, 4EH, 5FH, 53H, 54H, 41H, 54H, 45H
        DC8 5FH, 43H, 4FH, 4DH, 50H, 4CH, 45H, 54H
        DC8 45H, 20H, 70H, 61H, 69H, 72H, 20H, 66H
        DC8 61H, 69H, 6CH, 65H, 64H, 0
        DC8 0, 0

        SECTION `.BTTRACE`:CONST:REORDER:NOROOT(2)
        DATA
`app_handle_authen_state_evt{3}{4}{16}{17}{18}::format`:
        DC8 21H, 21H, 21H, 61H, 70H, 70H, 5FH, 68H
        DC8 61H, 6EH, 64H, 6CH, 65H, 5FH, 61H, 75H
        DC8 74H, 68H, 65H, 6EH, 5FH, 73H, 74H, 61H
        DC8 74H, 65H, 5FH, 65H, 76H, 74H, 3AH, 20H
        DC8 75H, 6EH, 6BH, 6EH, 6FH, 77H, 6EH, 20H
        DC8 6EH, 65H, 77H, 73H, 74H, 61H, 74H, 65H
        DC8 20H, 25H, 64H, 0

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
app_handle_conn_mtu_info_evt:
        PUSH     {R7,LR}
        MOV      R3,R0
        STR      R1,[SP, #+0]
        MOVS     R2,#+2
        LDR.W    R1,??DataTable9_26
        LDR.N    R0,??DataTable9  ;; 0x3f103002
        BL       trace_log_buffer
        POP      {R0,PC}          ;; return

        SECTION `.BTTRACE`:CONST:REORDER:NOROOT(2)
        DATA
`app_handle_conn_mtu_info_evt{1}{2}::format`:
        DC8 21H, 2AH, 2AH, 61H, 70H, 70H, 5FH, 68H
        DC8 61H, 6EH, 64H, 6CH, 65H, 5FH, 63H, 6FH
        DC8 6EH, 6EH, 5FH, 6DH, 74H, 75H, 5FH, 69H
        DC8 6EH, 66H, 6FH, 5FH, 65H, 76H, 74H, 3AH
        DC8 20H, 63H, 6FH, 6EH, 6EH, 5FH, 69H, 64H
        DC8 20H, 25H, 64H, 2CH, 20H, 6DH, 74H, 75H
        DC8 5FH, 73H, 69H, 7AH, 65H, 20H, 25H, 64H
        DC8 0
        DC8 0, 0, 0

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
app_handle_conn_param_update_evt:
        PUSH     {R0-R6,LR}
        MOV      R4,R0
        MOV      R5,R2
        LDR.N    R6,??DataTable9  ;; 0x3f103002
        CBZ.N    R1,??app_handle_conn_param_update_evt_0
        CMP      R1,#+2
        BEQ.N    ??app_handle_conn_param_update_evt_1
        BCC.N    ??app_handle_conn_param_update_evt_2
        POP      {R0-R6,PC}
??app_handle_conn_param_update_evt_0:
        MOV      R2,R4
        ADD      R1,SP,#+12
        MOVW     R0,#+626
        BL       le_get_conn_param
        MOV      R2,R4
        ADD      R1,SP,#+10
        MOVW     R0,#+627
        BL       le_get_conn_param
        MOV      R2,R4
        ADD      R1,SP,#+8
        MOV      R0,#+628
        BL       le_get_conn_param
        LDRH     R0,[SP, #+8]
        LDRH     R1,[SP, #+10]
        LDRH     R3,[SP, #+12]
        STR      R0,[SP, #+4]
        STR      R1,[SP, #+0]
        MOVS     R2,#+3
        LDR.W    R1,??DataTable9_27
        MOV      R0,R6
        BL       trace_log_buffer
        LDRH     R3,[SP, #+8]
        LDRH     R2,[SP, #+10]
        LDRH     R1,[SP, #+12]
        LDR.N    R0,??DataTable9_28
        BL       printf
        POP      {R0-R6,PC}
??app_handle_conn_param_update_evt_2:
        MOV      R3,R5
        MOVS     R2,#+1
        LDR.N    R1,??DataTable9_29
        BL       ?Subroutine2
??CrossCallReturnLabel_13:
        MOV      R1,R5
        LDR.N    R0,??DataTable9_30
        B.N      ??app_handle_conn_param_update_evt_3
??app_handle_conn_param_update_evt_1:
        MOVS     R2,#+0
        LDR.N    R1,??DataTable9_31
        MOV      R0,R6
        BL       trace_log_buffer
        MOV      R1,R4
        LDR.N    R0,??DataTable9_32
??app_handle_conn_param_update_evt_3:
        BL       printf
        POP      {R0-R6,PC}       ;; return

        SECTION `.BTTRACE`:CONST:REORDER:NOROOT(2)
        DATA
`app_handle_conn_param_update_evt{1}{2}{3}{7}{8}::format`:
        DC8 21H, 2AH, 2AH, 61H, 70H, 70H, 5FH, 68H
        DC8 61H, 6EH, 64H, 6CH, 65H, 5FH, 63H, 6FH
        DC8 6EH, 6EH, 5FH, 70H, 61H, 72H, 61H, 6DH
        DC8 5FH, 75H, 70H, 64H, 61H, 74H, 65H, 5FH
        DC8 65H, 76H, 74H, 20H, 75H, 70H, 64H, 61H
        DC8 74H, 65H, 20H, 73H, 75H, 63H, 63H, 65H
        DC8 73H, 73H, 3AH, 63H, 6FH, 6EH, 6EH, 5FH
        DC8 69H, 6EH, 74H, 65H, 72H, 76H, 61H, 6CH
        DC8 20H, 30H, 78H, 25H, 78H, 2CH, 20H, 63H
        DC8 6FH, 6EH, 6EH, 5FH, 73H, 6CH, 61H, 76H
        DC8 65H, 5FH, 6CH, 61H, 74H, 65H, 6EH, 63H
        DC8 79H, 20H, 30H, 78H, 25H, 78H, 2CH, 20H
        DC8 63H, 6FH, 6EH, 6EH, 5FH, 73H, 75H, 70H
        DC8 65H, 72H, 76H, 69H, 73H, 69H, 6FH, 6EH
        DC8 5FH, 74H, 69H, 6DH, 65H, 6FH, 75H, 74H
        DC8 20H, 30H, 78H, 25H, 78H, 0
        DC8 0, 0

        SECTION `.BTTRACE`:CONST:REORDER:NOROOT(2)
        DATA
`app_handle_conn_param_update_evt{1}{2}{9}{10}{11}::format`:
        DC8 21H, 21H, 21H, 61H, 70H, 70H, 5FH, 68H
        DC8 61H, 6EH, 64H, 6CH, 65H, 5FH, 63H, 6FH
        DC8 6EH, 6EH, 5FH, 70H, 61H, 72H, 61H, 6DH
        DC8 5FH, 75H, 70H, 64H, 61H, 74H, 65H, 5FH
        DC8 65H, 76H, 74H, 20H, 75H, 70H, 64H, 61H
        DC8 74H, 65H, 20H, 66H, 61H, 69H, 6CH, 65H
        DC8 64H, 3AH, 20H, 63H, 61H, 75H, 73H, 65H
        DC8 20H, 30H, 78H, 25H, 78H, 0
        DC8 0, 0

        SECTION `.BTTRACE`:CONST:REORDER:NOROOT(2)
        DATA
`app_handle_conn_param_update_evt{1}{2}{12}{13}{14}::format`:
        DC8 21H, 2AH, 2AH, 61H, 70H, 70H, 5FH, 68H
        DC8 61H, 6EH, 64H, 6CH, 65H, 5FH, 63H, 6FH
        DC8 6EH, 6EH, 5FH, 70H, 61H, 72H, 61H, 6DH
        DC8 5FH, 75H, 70H, 64H, 61H, 74H, 65H, 5FH
        DC8 65H, 76H, 74H, 20H, 75H, 70H, 64H, 61H
        DC8 74H, 65H, 20H, 70H, 65H, 6EH, 64H, 69H
        DC8 6EH, 67H, 2EH, 0

        SECTION `.text`:CODE:NOROOT(2)
        THUMB
app_handle_gap_msg:
        PUSH     {R1-R5,LR}
        MOV      R4,R0
        MOVS     R2,#+4
        ADDS     R1,R4,#+4
        MOV      R0,SP
        BL       memcpy
        LDRH     R3,[R4, #+2]
        MOVS     R2,#+1
        LDR.N    R1,??DataTable9_33
        LDR.N    R0,??DataTable9_34  ;; 0x3f103003
        BL       trace_log_buffer
        LDRH     R3,[R4, #+2]
        LDRB     R1,[SP, #+1]
        LDR.N    R4,??DataTable9  ;; 0x3f103002
        SUBS     R0,R3,#+1
        CMP      R0,#+9
        BHI.N    ??app_handle_gap_msg_1
        TBB      [PC, R0]
        DATA
??app_handle_gap_msg_0:
        DC8      0x5,0xC,0x19,0x12
        DC8      0x1E,0x2D,0x50,0x5C
        DC8      0x41,0x23
        THUMB
??app_handle_gap_msg_2:
        LDRH     R1,[SP, #+2]
        LDRB     R0,[SP, #+0]
        BL       app_handle_dev_state_evt
        POP      {R0-R2,R4,R5,PC}
??app_handle_gap_msg_3:
        BL       ?Subroutine3
??CrossCallReturnLabel_15:
        SXTB     R1,R1
        BL       app_handle_conn_state_evt
        POP      {R0-R2,R4,R5,PC}
??app_handle_gap_msg_4:
        LDRH     R1,[SP, #+2]
        LDRB     R0,[SP, #+0]
        BL       app_handle_conn_mtu_info_evt
        POP      {R0-R2,R4,R5,PC}
??app_handle_gap_msg_5:
        BL       ?Subroutine3
??CrossCallReturnLabel_16:
        BL       app_handle_conn_param_update_evt
        POP      {R0-R2,R4,R5,PC}
??app_handle_gap_msg_6:
        BL       ?Subroutine3
??CrossCallReturnLabel_17:
        BL       app_handle_authen_state_evt
        POP      {R0-R2,R4,R5,PC}
??app_handle_gap_msg_7:
        LDRB     R0,[SP, #+0]
        MOVS     R1,#+1
        BL       le_bond_just_work_confirm
        MOVS     R2,#+0
        LDR.N    R1,??DataTable9_35
        BL       ?Subroutine0
??CrossCallReturnLabel_1:
        POP      {R0-R2,R4,R5,PC}
??app_handle_gap_msg_8:
        LDRB     R5,[SP, #+0]
        MOVS     R0,#+0
        STR      R0,[SP, #+4]
        ADD      R1,SP,#+4
        MOV      R0,R5
        BL       le_bond_get_display_key
        LDR      R3,[SP, #+4]
        MOVS     R2,#+1
        LDR.N    R1,??DataTable9_36
        BL       ?Subroutine1
??CrossCallReturnLabel_10:
        MOVS     R1,#+1
        MOV      R0,R5
        BL       le_bond_passkey_display_confirm
        LDR      R1,[SP, #+4]
        LDR.N    R0,??DataTable9_37
        B.N      ??app_handle_gap_msg_9
??app_handle_gap_msg_10:
        MOVS     R0,#+0
        STR      R0,[SP, #+4]
        LDRB     R0,[SP, #+0]
        ADD      R1,SP,#+4
        BL       le_bond_get_display_key
        LDR      R3,[SP, #+4]
        MOVS     R2,#+1
        LDR.N    R1,??DataTable9_38
        BL       ?Subroutine1
??CrossCallReturnLabel_9:
        LDR      R1,[SP, #+4]
        LDR.N    R0,??DataTable9_39
        B.N      ??app_handle_gap_msg_9
??app_handle_gap_msg_11:
        LDRB     R5,[SP, #+0]
        MOVS     R2,#+1
        LDR.N    R1,??DataTable9_40
        MOV      R3,R5
        BL       ?Subroutine1
??CrossCallReturnLabel_8:
        MOV      R1,R5
        LDR.N    R0,??DataTable9_41
??app_handle_gap_msg_9:
        BL       printf
        POP      {R0-R2,R4,R5,PC}
??app_handle_gap_msg_1:
        MOVS     R2,#+1
        LDR.N    R1,??DataTable9_42
        BL       ?Subroutine2
??CrossCallReturnLabel_12:
        POP      {R0-R2,R4,R5,PC}  ;; return

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
?Subroutine3:
        LDRH     R2,[SP, #+2]
        LDRB     R0,[SP, #+0]
        BX       LR

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
?Subroutine2:
        LDR.N    R0,??DataTable9_25  ;; 0x3f103000
        B.W      trace_log_buffer

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
?Subroutine0:
        MOV      R0,R4
        B.W      trace_log_buffer

        SECTION `.BTTRACE`:CONST:REORDER:NOROOT(2)
        DATA
`app_handle_gap_msg{2}{3}::format`:
        DC8 "app_handle_gap_msg: subtype %d"
        DC8 0

        SECTION `.BTTRACE`:CONST:REORDER:NOROOT(2)
        DATA
`app_handle_gap_msg{4}{5}{11}{12}{13}::format`:
        DC8 "!**GAP_MSG_LE_BOND_JUST_WORK"
        DC8 0, 0, 0

        SECTION `.BTTRACE`:CONST:REORDER:NOROOT(2)
        DATA
`app_handle_gap_msg{4}{5}{14}{16}{17}::format`:
        DC8 "!**GAP_MSG_LE_BOND_PASSKEY_DISPLAY:passkey %d"
        DC8 0, 0

        SECTION `.BTTRACE`:CONST:REORDER:NOROOT(2)
        DATA
`app_handle_gap_msg{4}{5}{18}{20}{21}::format`:
        DC8 "!**GAP_MSG_LE_BOND_USER_CONFIRMATION: passkey %d"
        DC8 0, 0, 0

        SECTION `.BTTRACE`:CONST:REORDER:NOROOT(2)
        DATA
`app_handle_gap_msg{4}{5}{22}{23}{24}::format`:
        DC8 "!**GAP_MSG_LE_BOND_PASSKEY_INPUT: conn_id %d"
        DC8 0, 0, 0

        SECTION `.BTTRACE`:CONST:REORDER:NOROOT(2)
        DATA
`app_handle_gap_msg{4}{5}{25}{26}::format`:
        DC8 "!!!app_handle_gap_msg: unknown subtype %d"
        DC8 0, 0

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
app_gap_callback:
        PUSH     {R7,LR}
        MOV      R3,R0
        CMP      R0,#+1
        BNE.N    ??app_gap_callback_0
        LDR      R0,[R1, #+0]
        LDR.N    R1,??DataTable9_43
        LDRH     R2,[R0, #+2]
        STR      R2,[SP, #+0]
        LDRSB    R3,[R0, #+0]
        MOVS     R2,#+2
        LDR.N    R0,??DataTable9  ;; 0x3f103002
        BL       trace_log_buffer
        B.N      ??CrossCallReturnLabel_11
??app_gap_callback_0:
        MOVS     R2,#+1
        LDR.N    R1,??DataTable9_44
        BL       ?Subroutine2
??CrossCallReturnLabel_11:
        MOVS     R0,#+0
        POP      {R1,PC}          ;; return

        SECTION `.BTTRACE`:CONST:REORDER:NOROOT(2)
        DATA
`app_gap_callback{1}{2}{3}{4}::format`:
        DC8 21H, 2AH, 2AH, 47H, 41H, 50H, 5FH, 4DH
        DC8 53H, 47H, 5FH, 4CH, 45H, 5FH, 4DH, 4FH
        DC8 44H, 49H, 46H, 59H, 5FH, 57H, 48H, 49H
        DC8 54H, 45H, 5FH, 4CH, 49H, 53H, 54H, 3AH
        DC8 20H, 6FH, 70H, 65H, 72H, 61H, 74H, 69H
        DC8 6FH, 6EH, 20H, 25H, 64H, 2CH, 20H, 63H
        DC8 61H, 75H, 73H, 65H, 20H, 30H, 78H, 25H
        DC8 78H, 0
        DC8 0, 0

        SECTION `.BTTRACE`:CONST:REORDER:NOROOT(2)
        DATA
`app_gap_callback{1}{2}{5}{6}::format`:
        DC8 "!!!app_gap_callback: unhandled cb_type 0x%x"

        SECTION `.text`:CODE:NOROOT(2)
        THUMB
app_profile_callback:
        PUSH     {R3-R5,LR}
        SUB      SP,SP,#+16
        MOV      R5,R1
        LDR.N    R4,??DataTable9  ;; 0x3f103002
        CMP      R0,#+255
        BNE.N    ??app_profile_callback_1
        LDRSB    R0,[R5, #+0]
        CBZ.N    R0,??app_profile_callback_2
        CMP      R0,#+1
        BEQ.N    ??app_profile_callback_3
        B.N      ??app_profile_callback_4
??app_profile_callback_2:
        LDRSB    R3,[R5, #+2]
        MOVS     R2,#+1
        LDR.N    R1,??DataTable9_45
        BL       ?Subroutine1
??CrossCallReturnLabel_7:
        B.N      ??app_profile_callback_4
??app_profile_callback_3:
        LDRH     R0,[R5, #+2]
        MOVS     R2,#+5
        STR      R0,[SP, #+12]
        LDRH     R1,[R5, #+6]
        STR      R1,[SP, #+8]
        LDRB     R0,[R5, #+5]
        STR      R0,[SP, #+4]
        LDRH     R1,[R5, #+8]
        MOV      R0,R4
        STR      R1,[SP, #+0]
        LDRB     R3,[R5, #+4]
        LDR.N    R1,??DataTable9_46
        BL       trace_log_buffer
        LDRH     R0,[R5, #+8]
        CBNZ.N   R0,??app_profile_callback_5
        MOVS     R2,#+0
        LDR.N    R1,??DataTable9_47
        B.N      ??app_profile_callback_6
??app_profile_callback_5:
        MOVS     R2,#+0
        LDR.N    R1,??DataTable9_48
        LDR.N    R0,??DataTable9_25  ;; 0x3f103000
        B.N      ??app_profile_callback_7
??app_profile_callback_1:
        LDR.N    R2,??DataTable9_49
        LDRB     R3,[R2, #+0]
        CMP      R0,R3
        BNE.N    ??app_profile_callback_8
        LDRSB    R0,[R5, #+1]
        CMP      R0,#+1
        BEQ.N    ??app_profile_callback_9
        BCC.N    ??app_profile_callback_4
        CMP      R0,#+3
        BEQ.N    ??app_profile_callback_10
        BCC.N    ??app_profile_callback_11
        B.N      ??app_profile_callback_4
??app_profile_callback_9:
        LDRB     R1,[R5, #+4]
        SUBS     R1,R1,#+1
        CMP      R1,#+3
        BHI.N    ??app_profile_callback_4
        TBB      [PC, R1]
        DATA
??app_profile_callback_0:
        DC8      0x2,0x5,0x8,0xB
        THUMB
??app_profile_callback_12:
        MOVS     R2,#+0
        LDR.N    R1,??DataTable9_50
        B.N      ??app_profile_callback_6
??app_profile_callback_13:
        MOVS     R2,#+0
        LDR.N    R1,??DataTable9_51
        B.N      ??app_profile_callback_6
??app_profile_callback_14:
        MOVS     R2,#+0
        LDR.N    R1,??DataTable9_52
        B.N      ??app_profile_callback_6
??app_profile_callback_15:
        MOVS     R2,#+0
        LDR.N    R1,??DataTable9_53
        B.N      ??app_profile_callback_6
??app_profile_callback_11:
        LDRB     R0,[R5, #+4]
        CMP      R0,#+1
        BNE.N    ??app_profile_callback_4
        LDR.N    R0,??DataTable9_54
        LDRH     R0,[R0, #+0]
        MOVS     R2,#+0
        LDR.N    R1,??DataTable9_55
        STRH     R0,[SP, #+0]
        BL       ?Subroutine0
??CrossCallReturnLabel_0:
        MOV      R2,SP
        MOVS     R1,#+2
        MOVS     R0,#+1
        BL       simp_ble_service_set_parameter
        B.N      ??app_profile_callback_4
??app_profile_callback_10:
        LDRB     R0,[R5, #+4]
        CMP      R0,#+1
        BNE.N    ??app_profile_callback_4
        LDRH     R0,[R5, #+6]
        MOVS     R2,#+2
        LDR.N    R1,??DataTable9_56
        STR      R0,[SP, #+0]
        LDRSB    R3,[R5, #+5]
        MOV      R0,R4
        BL       trace_log_buffer
        B.N      ??app_profile_callback_4
??app_profile_callback_8:
        LDR.N    R1,??DataTable9_57
        LDRB     R2,[R1, #+0]
        CMP      R0,R2
        BNE.N    ??app_profile_callback_4
        LDRSB    R0,[R5, #+1]
        CMP      R0,#+1
        BEQ.N    ??app_profile_callback_16
        CMP      R0,#+2
        BEQ.N    ??app_profile_callback_17
        B.N      ??app_profile_callback_4
??app_profile_callback_16:
        LDRB     R1,[R5, #+2]
        CMP      R1,#+1
        BEQ.N    ??app_profile_callback_18
        CMP      R1,#+2
        BEQ.N    ??app_profile_callback_19
        B.N      ??app_profile_callback_4
??app_profile_callback_18:
        MOVS     R2,#+0
        LDR.N    R1,??DataTable9_58
        B.N      ??app_profile_callback_6
??app_profile_callback_19:
        MOVS     R2,#+0
        LDR.N    R1,??DataTable9_59
??app_profile_callback_6:
        MOV      R0,R4
??app_profile_callback_7:
        BL       trace_log_buffer
        B.N      ??app_profile_callback_4
??app_profile_callback_17:
        LDRB     R0,[R5, #+2]
        CMP      R0,#+1
        BNE.N    ??app_profile_callback_4
        MOVS     R1,#+90
        STRB     R1,[SP, #+0]
        MOVS     R3,#+90
        MOVS     R2,#+1
        LDR.N    R1,??DataTable9_60
        BL       ?Subroutine1
??CrossCallReturnLabel_6:
        MOV      R2,SP
        MOVS     R1,#+1
        MOVS     R0,#+1
        BL       bas_set_parameter
??app_profile_callback_4:
        MOVS     R0,#+0
        ADD      SP,SP,#+20
        POP      {R4,R5,PC}       ;; return

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable9:
        DC32     0x3f103002

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable9_1:
        DC32     `app_handle_dev_state_evt{1}{2}::format`

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable9_2:
        DC32     gap_dev_state

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable9_3:
        DC32     `app_handle_dev_state_evt{3}{4}{5}{6}{7}{8}::format`

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable9_4:
        DC32     ?_0

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable9_5:
        DC32     `app_handle_dev_state_evt{9}{10}{11}{12}{13}{14}{15}{16}::format`

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable9_6:
        DC32     ?_1

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable9_7:
        DC32     `app_handle_dev_state_evt{9}{10}{11}{12}{13}{17}{18}{19}::format`

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable9_8:
        DC32     ?_2

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable9_9:
        DC32     `app_handle_dev_state_evt{9}{10}{11}{20}{21}{22}{23}{24}::format`

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable9_10:
        DC32     ?_3

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable9_11:
        DC32     gap_conn_state

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable9_12:
        DC32     `app_handle_conn_state_evt{1}{2}::format`

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable9_13:
        DC32     `app_handle_conn_state_evt{3}{4}{5}{6}{7}{8}{9}::format`

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable9_14:
        DC32     ?_4

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable9_15:
        DC32     0x3f300000

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable9_16:
        DC32     `app_handle_conn_state_evt{3}{4}{10}{16}{17}::format`

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable9_17:
        DC32     ?_5

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable9_18:
        DC32     `app_handle_authen_state_evt{1}{2}::format`

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable9_19:
        DC32     `app_handle_authen_state_evt{3}{4}{5}{6}{7}::format`

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable9_20:
        DC32     ?_6

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable9_21:
        DC32     `app_handle_authen_state_evt{3}{4}{8}{9}{10}{11}{12}::format`

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable9_22:
        DC32     ?_7

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable9_23:
        DC32     `app_handle_authen_state_evt{3}{4}{8}{9}{13}{14}{15}::format`

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable9_24:
        DC32     `app_handle_authen_state_evt{3}{4}{16}{17}{18}::format`

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable9_25:
        DC32     0x3f103000

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable9_26:
        DC32     `app_handle_conn_mtu_info_evt{1}{2}::format`

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable9_27:
        DC32     `app_handle_conn_param_update_evt{1}{2}{3}{7}{8}::format`

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable9_28:
        DC32     ?_8

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable9_29:
        DC32     `app_handle_conn_param_update_evt{1}{2}{9}{10}{11}::format`

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable9_30:
        DC32     ?_9

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable9_31:
        DC32     `app_handle_conn_param_update_evt{1}{2}{12}{13}{14}::format`

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable9_32:
        DC32     ?_10

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable9_33:
        DC32     `app_handle_gap_msg{2}{3}::format`

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable9_34:
        DC32     0x3f103003

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable9_35:
        DC32     `app_handle_gap_msg{4}{5}{11}{12}{13}::format`

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable9_36:
        DC32     `app_handle_gap_msg{4}{5}{14}{16}{17}::format`

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable9_37:
        DC32     ?_11

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable9_38:
        DC32     `app_handle_gap_msg{4}{5}{18}{20}{21}::format`

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable9_39:
        DC32     ?_12

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable9_40:
        DC32     `app_handle_gap_msg{4}{5}{22}{23}{24}::format`

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable9_41:
        DC32     ?_13

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable9_42:
        DC32     `app_handle_gap_msg{4}{5}{25}{26}::format`

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable9_43:
        DC32     `app_gap_callback{1}{2}{3}{4}::format`

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable9_44:
        DC32     `app_gap_callback{1}{2}{5}{6}::format`

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable9_45:
        DC32     `app_profile_callback{1}{2}{3}{4}{5}{6}::format`

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable9_46:
        DC32     `app_profile_callback{1}{2}{3}{4}{7}{8}::format`

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable9_47:
        DC32     `app_profile_callback{1}{2}{3}{4}{9}{10}{11}{12}::format`

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable9_48:
        DC32     `app_profile_callback{1}{2}{3}{4}{9}{13}{14}{15}::format`

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable9_49:
        DC32     simp_srv_id

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable9_50:
        DC32     `app_profile_callback{1}{16}{17}{18}{19}{20}{21}{22}{23}{24}{25}{26}::format`

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable9_51:
        DC32     `app_profile_callback{1}{16}{17}{18}{19}{20}{21}{22}{23}{27}{28}{29}::format`

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable9_52:
        DC32     `app_profile_callback{1}{16}{17}{18}{19}{20}{21}{22}{23}{30}{31}{32}::format`

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable9_53:
        DC32     `app_profile_callback{1}{16}{17}{18}{19}{20}{21}{22}{23}{33}{34}{35}::format`

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable9_54:
        DC32     ?_14

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable9_55:
        DC32     `app_profile_callback{1}{16}{17}{18}{19}{20}{36}{37}{38}{40}{41}::format`

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable9_56:
        DC32     `app_profile_callback{1}{16}{17}{18}{19}{20}{42}{43}{44}{45}{46}{47}::format`

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable9_57:
        DC32     bas_srv_id

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable9_58:
        DC32     `app_profile_callback{1}{16}{17}{48}{49}{50}{51}{52}{53}{54}{55}{56}{57}{58}::format`

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable9_59:
        DC32     `app_profile_callback{1}{16}{17}{48}{49}{50}{51}{52}{53}{54}{55}{59}{60}{61}::format`

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable9_60:
        DC32     `app_profile_callback{1}{16}{17}{48}{49}{50}{51}{52}{62}{63}{64}{66}{67}::format`

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
?Subroutine1:
        MOV      R0,R4
        B.W      trace_log_buffer

        SECTION `.BTTRACE`:CONST:REORDER:NOROOT(2)
        DATA
`app_profile_callback{1}{2}{3}{4}{5}{6}::format`:
        DC8 "!**PROFILE_EVT_SRV_REG_COMPLETE: result %d"
        DC8 0

        SECTION `.BTTRACE`:CONST:REORDER:NOROOT(2)
        DATA
`app_profile_callback{1}{2}{3}{4}{7}{8}::format`:
        DC8 21H, 2AH, 2AH, 50H, 52H, 4FH, 46H, 49H
        DC8 4CH, 45H, 5FH, 45H, 56H, 54H, 5FH, 53H
        DC8 45H, 4EH, 44H, 5FH, 44H, 41H, 54H, 41H
        DC8 5FH, 43H, 4FH, 4DH, 50H, 4CH, 45H, 54H
        DC8 45H, 3AH, 20H, 63H, 6FH, 6EH, 6EH, 5FH
        DC8 69H, 64H, 20H, 25H, 64H, 2CH, 20H, 63H
        DC8 61H, 75H, 73H, 65H, 20H, 30H, 78H, 25H
        DC8 78H, 2CH, 20H, 73H, 65H, 72H, 76H, 69H
        DC8 63H, 65H, 5FH, 69H, 64H, 20H, 25H, 64H
        DC8 2CH, 20H, 61H, 74H, 74H, 72H, 69H, 62H
        DC8 5FH, 69H, 64H, 78H, 20H, 30H, 78H, 25H
        DC8 78H, 2CH, 20H, 63H, 72H, 65H, 64H, 69H
        DC8 74H, 73H, 20H, 25H, 64H, 0
        DC8 0, 0

        SECTION `.BTTRACE`:CONST:REORDER:NOROOT(2)
        DATA
`app_profile_callback{1}{2}{3}{4}{9}{10}{11}{12}::format`:
        DC8 "!**PROFILE_EVT_SEND_DATA_COMPLETE success"
        DC8 0, 0

        SECTION `.BTTRACE`:CONST:REORDER:NOROOT(2)
        DATA
`app_profile_callback{1}{2}{3}{4}{9}{13}{14}{15}::format`:
        DC8 "!!!PROFILE_EVT_SEND_DATA_COMPLETE failed"
        DC8 0, 0, 0

        SECTION `.BTTRACE`:CONST:REORDER:NOROOT(2)
        DATA
`app_profile_callback{1}{16}{17}{18}{19}{20}{21}{22}{23}{24}{25}{26}::format`:
        DC8 "!**SIMP_NOTIFY_INDICATE_V3_ENABLE"
        DC8 0, 0

        SECTION `.BTTRACE`:CONST:REORDER:NOROOT(2)
        DATA
`app_profile_callback{1}{16}{17}{18}{19}{20}{21}{22}{23}{27}{28}{29}::format`:
        DC8 "!**SIMP_NOTIFY_INDICATE_V3_DISABLE"
        DC8 0

        SECTION `.BTTRACE`:CONST:REORDER:NOROOT(2)
        DATA
`app_profile_callback{1}{16}{17}{18}{19}{20}{21}{22}{23}{30}{31}{32}::format`:
        DC8 "!**SIMP_NOTIFY_INDICATE_V4_ENABLE"
        DC8 0, 0

        SECTION `.BTTRACE`:CONST:REORDER:NOROOT(2)
        DATA
`app_profile_callback{1}{16}{17}{18}{19}{20}{21}{22}{23}{33}{34}{35}::format`:
        DC8 "!**SIMP_NOTIFY_INDICATE_V4_DISABLE"
        DC8 0

        SECTION `.BTTRACE`:CONST:REORDER:NOROOT(2)
        DATA
`app_profile_callback{1}{16}{17}{18}{19}{20}{36}{37}{38}{40}{41}::format`:
        DC8 "!**SIMP_READ_V1"

        SECTION `.BTTRACE`:CONST:REORDER:NOROOT(2)
        DATA
`app_profile_callback{1}{16}{17}{18}{19}{20}{42}{43}{44}{45}{46}{47}::format`:
        DC8 "!**SIMP_WRITE_V2: write type %d, len %d"

        SECTION `.BTTRACE`:CONST:REORDER:NOROOT(2)
        DATA
`app_profile_callback{1}{16}{17}{48}{49}{50}{51}{52}{53}{54}{55}{56}{57}{58}::format`:
        DC8 "!**BAS_NOTIFY_BATTERY_LEVEL_ENABLE"
        DC8 0

        SECTION `.BTTRACE`:CONST:REORDER:NOROOT(2)
        DATA
`app_profile_callback{1}{16}{17}{48}{49}{50}{51}{52}{53}{54}{55}{59}{60}{61}::format`:
        DC8 "!**BAS_NOTIFY_BATTERY_LEVEL_DISABLE"

        SECTION `.BTTRACE`:CONST:REORDER:NOROOT(2)
        DATA
`app_profile_callback{1}{16}{17}{48}{49}{50}{51}{52}{62}{63}{64}{66}{67}::format`:
        DC8 "!**BAS_READ_BATTERY_LEVEL: battery_level %d"

        SECTION `.iar_vfe_header`:DATA:NOALLOC:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
        DC32 0

        SECTION `.rodata`:CONST:REORDER:NOROOT(2)
        DATA
?_0:
        DC8 "\012\015[BLE peripheral] GAP stack ready\012\015"
        DC8 0, 0, 0

        SECTION `.rodata`:CONST:REORDER:NOROOT(2)
        DATA
?_1:
        DC8 "\012\015GAP adv stoped: because connection created\012\015"
        DC8 0

        SECTION `.rodata`:CONST:REORDER:NOROOT(2)
        DATA
?_2:
        DC8 "\012\015GAP adv stopped\012\015"

        SECTION `.rodata`:CONST:REORDER:NOROOT(2)
        DATA
?_3:
        DC8 "\012\015GAP adv start\012\015"
        DC8 0, 0

        SECTION `.rodata`:CONST:REORDER:NOROOT(2)
        DATA
?_4:
        DC8 "\012\015[BLE peripheral] BT Disconnected, start ADV\012\015"

        SECTION `.rodata`:CONST:REORDER:NOROOT(2)
        DATA
?_5:
        DC8 "\012\015[BLE peripheral] BT Connected\012\015"
        DC8 0, 0

        SECTION `.rodata`:CONST:REORDER:NOROOT(2)
        DATA
?_6:
        DC8 "Pair success\015\012"
        DC8 0

        SECTION `.rodata`:CONST:REORDER:NOROOT(2)
        DATA
?_7:
        DC8 "Pair failed: cause 0x%x\015\012"
        DC8 0, 0

        SECTION `.rodata`:CONST:REORDER:NOROOT(2)
        DATA
?_8:
        DC8 61H, 70H, 70H, 5FH, 68H, 61H, 6EH, 64H
        DC8 6CH, 65H, 5FH, 63H, 6FH, 6EH, 6EH, 5FH
        DC8 70H, 61H, 72H, 61H, 6DH, 5FH, 75H, 70H
        DC8 64H, 61H, 74H, 65H, 5FH, 65H, 76H, 74H
        DC8 20H, 75H, 70H, 64H, 61H, 74H, 65H, 20H
        DC8 73H, 75H, 63H, 63H, 65H, 73H, 73H, 3AH
        DC8 63H, 6FH, 6EH, 6EH, 5FH, 69H, 6EH, 74H
        DC8 65H, 72H, 76H, 61H, 6CH, 20H, 30H, 78H
        DC8 25H, 78H, 2CH, 20H, 63H, 6FH, 6EH, 6EH
        DC8 5FH, 73H, 6CH, 61H, 76H, 65H, 5FH, 6CH
        DC8 61H, 74H, 65H, 6EH, 63H, 79H, 20H, 30H
        DC8 78H, 25H, 78H, 2CH, 20H, 63H, 6FH, 6EH
        DC8 6EH, 5FH, 73H, 75H, 70H, 65H, 72H, 76H
        DC8 69H, 73H, 69H, 6FH, 6EH, 5FH, 74H, 69H
        DC8 6DH, 65H, 6FH, 75H, 74H, 20H, 30H, 78H
        DC8 25H, 78H, 0DH, 0AH, 0
        DC8 0, 0, 0

        SECTION `.rodata`:CONST:REORDER:NOROOT(2)
        DATA
?_9:
        DC8 61H, 70H, 70H, 5FH, 68H, 61H, 6EH, 64H
        DC8 6CH, 65H, 5FH, 63H, 6FH, 6EH, 6EH, 5FH
        DC8 70H, 61H, 72H, 61H, 6DH, 5FH, 75H, 70H
        DC8 64H, 61H, 74H, 65H, 5FH, 65H, 76H, 74H
        DC8 20H, 75H, 70H, 64H, 61H, 74H, 65H, 20H
        DC8 66H, 61H, 69H, 6CH, 65H, 64H, 3AH, 20H
        DC8 63H, 61H, 75H, 73H, 65H, 20H, 30H, 78H
        DC8 25H, 78H, 0
        DC8 0

        SECTION `.rodata`:CONST:REORDER:NOROOT(2)
        DATA
?_10:
        DC8 0AH, 0DH, 62H, 6CH, 65H, 5FH, 63H, 65H
        DC8 6EH, 74H, 72H, 61H, 6CH, 5FH, 61H, 70H
        DC8 70H, 5FH, 68H, 61H, 6EH, 64H, 6CH, 65H
        DC8 5FH, 63H, 6FH, 6EH, 6EH, 5FH, 70H, 61H
        DC8 72H, 61H, 6DH, 5FH, 75H, 70H, 64H, 61H
        DC8 74H, 65H, 5FH, 65H, 76H, 74H, 20H, 75H
        DC8 70H, 64H, 61H, 74H, 65H, 20H, 70H, 65H
        DC8 6EH, 64H, 69H, 6EH, 67H, 3AH, 20H, 63H
        DC8 6FH, 6EH, 6EH, 5FH, 69H, 64H, 20H, 25H
        DC8 64H, 0DH, 0AH, 0

        SECTION `.rodata`:CONST:REORDER:NOROOT(2)
        DATA
?_11:
        DC8 "GAP_MSG_LE_BOND_PASSKEY_DISPLAY:passkey %d"
        DC8 0

        SECTION `.rodata`:CONST:REORDER:NOROOT(2)
        DATA
?_12:
        DC8 "GAP_MSG_LE_BOND_USER_CONFIRMATION: passkey %d"
        DC8 0, 0

        SECTION `.rodata`:CONST:REORDER:NOROOT(2)
        DATA
?_13:
        DC8 "GAP_MSG_LE_BOND_PASSKEY_INPUT: conn_id %d"
        DC8 0, 0

        SECTION `.rodata`:CONST:REORDER:NOROOT(1)
        DATA
?_14:
        DC8 1, 2

        END
// 
// 1 984 bytes in section .BTTRACE
//     4 bytes in section .bss
//   658 bytes in section .rodata
// 1 570 bytes in section .text
// 
// 1 570 bytes of CODE  memory
// 2 642 bytes of CONST memory
//     4 bytes of DATA  memory
//
//Errors: none
//Warnings: none
