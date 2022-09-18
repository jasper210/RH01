///////////////////////////////////////////////////////////////////////////////
//
// IAR ANSI C/C++ Compiler V8.30.1.114/W32 for ARM        24/Sep/2021  15:44:12
// Copyright 1999-2018 IAR Systems AB.
//
//    Cpu mode     =  thumb
//    Endian       =  little
//    Source file  =  
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\component\common\bluetooth\realtek\sdk\example\ble_peripheral\ble_peripheral_at_cmd.c
//    Command line =  
//        -f C:\Users\ADMINI~1\AppData\Local\Temp\EWF112.tmp
//        (F:\lxd\src2\hisen\sdk-ameba-v7.1d\component\common\bluetooth\realtek\sdk\example\ble_peripheral\ble_peripheral_at_cmd.c
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
//        F:\lxd\src2\hisen\sdk-ameba-v7.1d\project\realtek_amebaz2_v0_example\EWARM-RELEASE\Debug\List\ble_peripheral_at_cmd.s
//
///////////////////////////////////////////////////////////////////////////////

        #define SHT_PROGBITS 0x1

        EXTERN __aeabi_memclr4
        EXTERN atoi
        EXTERN bond_storage_num
        EXTERN evt_queue_handle
        EXTERN gap_dev_state
        EXTERN gap_set_pairable_mode
        EXTERN gap_set_param
        EXTERN io_queue_handle
        EXTERN le_adv_set_param
        EXTERN le_bond_clear_all_keys
        EXTERN le_bond_pair
        EXTERN le_bond_passkey_input_confirm
        EXTERN le_bond_set_param
        EXTERN le_bond_user_confirm
        EXTERN le_find_key_entry_by_idx
        EXTERN le_update_conn_param
        EXTERN os_msg_send_intern
        EXTERN parse_param
        EXTERN printf
        EXTERN strcmp
        EXTERN strlen
        EXTERN vTaskDelay

        PUBLIC ble_peripheral_app_handle_at_cmd
        PUBLIC ble_peripheral_at_cmd_auth
        PUBLIC ble_peripheral_at_cmd_bond_information
        PUBLIC ble_peripheral_at_cmd_send_msg
        PUBLIC ble_peripheral_at_cmd_send_userconf
        PUBLIC ble_peripheral_at_cmd_set_adv_int
        PUBLIC ble_peripheral_at_cmd_update_conn_request


        SECTION `.text`:CODE:NOROOT(1)
        THUMB
hex_str_to_int:
        MOV      R2,R0
        PUSH     {R4-R6,LR}
        MOVS     R0,#+0
        LDRSB    R4,[R1, R0]
        MOVS     R3,#+2
        CMP      R4,#+48
        ITTT     NE 
        LDRSBNE  R4,[R1, #+1]
        CMPNE    R4,#+120
        CMPNE    R4,#+88
        BEQ.N    ??hex_str_to_int_0
        MOV      R0,#-1
        POP      {R4-R6,PC}
??hex_str_to_int_1:
        SUB      R5,R4,#+48
        CMP      R5,#+10
        ITE      CS 
        MOVCS    R4,#+255
        SUBCC    R4,R4,#+48
??hex_str_to_int_2:
        MOV      R5,R0
        UXTB     R0,R4
        ORR      R0,R0,R5, LSL #+4
??hex_str_to_int_0:
        CMP      R3,R2
        BCS.N    ??hex_str_to_int_3
        LDRSB    R4,[R1, R3]
        ADDS     R3,R3,#+1
        SUB      R6,R4,#+65
        CMP      R6,#+6
        IT       CC 
        SUBCC    R4,R4,#+55
        BCC.N    ??hex_str_to_int_2
        SUB      R6,R4,#+97
        CMP      R6,#+6
        BCS.N    ??hex_str_to_int_1
        SUBS     R4,R4,#+87
        B.N      ??hex_str_to_int_2
??hex_str_to_int_3:
        POP      {R4-R6,PC}       ;; return

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
ble_peripheral_at_cmd_send_msg:
        PUSH     {R3-R5,LR}
        LDR.N    R4,??DataTable4_1
        SUB      SP,SP,#+16
        STRH     R0,[SP, #+10]
        LDR      R0,[R4, #+0]
        MOVS     R2,#+17
        MOVS     R3,#+2
        CMP      R0,#+0
        STRB     R2,[SP, #+4]
        STRH     R3,[SP, #+8]
        ITTT     NE 
        LDRNE.N  R1,??DataTable4_2
        LDRNE    R0,[R1, #+0]
        CMPNE    R0,#+0
        BEQ.N    ??ble_peripheral_at_cmd_send_msg_0
        MOVS     R3,#+73
        LDR.N    R5,??DataTable4_3
        STR      R3,[SP, #+0]
        MOV      R3,R5
        MOVS     R2,#+0
        ADD      R1,SP,#+8
        BL       os_msg_send_intern
        CBNZ.N   R0,??ble_peripheral_at_cmd_send_msg_1
        LDRH     R1,[SP, #+10]
        LDR.N    R0,??DataTable4_4
        B.N      ??ble_peripheral_at_cmd_send_msg_2
??ble_peripheral_at_cmd_send_msg_1:
        MOVS     R0,#+75
        STR      R0,[SP, #+0]
        LDR      R0,[R4, #+0]
        MOV      R3,R5
        MOVS     R2,#+0
        ADD      R1,SP,#+4
        BL       os_msg_send_intern
        CBNZ.N   R0,??ble_peripheral_at_cmd_send_msg_0
        LDRH     R1,[SP, #+10]
        LDR.N    R0,??DataTable4_5
??ble_peripheral_at_cmd_send_msg_2:
        BL       printf
??ble_peripheral_at_cmd_send_msg_0:
        ADD      SP,SP,#+20
        POP      {R4,R5,PC}       ;; return

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
ble_peripheral_at_cmd_set_adv_int:
        PUSH     {R2-R4,LR}
        MOV      R4,R1
        LDR      R0,[R4, #+4]
        BL       atoi
        STRH     R0,[SP, #+2]
        LDR      R0,[R4, #+8]
        LDR.N    R4,??DataTable4_6
        BL       atoi
        STRH     R0,[SP, #+0]
        MOVS     R0,#+0
        BL       ble_peripheral_at_cmd_send_msg
??ble_peripheral_at_cmd_set_adv_int_0:
        MOVS     R0,#+1
        BL       vTaskDelay
        LDRB     R0,[R4, #+0]
        UBFX     R0,R0,#+2,#+2
        CMP      R0,#+0
        BNE.N    ??ble_peripheral_at_cmd_set_adv_int_0
        ADD      R2,SP,#+2
        MOVS     R1,#+2
        MOVW     R0,#+617
        BL       le_adv_set_param
        MOV      R2,SP
        MOVS     R1,#+2
        MOV      R0,#+616
        BL       le_adv_set_param
        MOVS     R0,#+1
        BL       ble_peripheral_at_cmd_send_msg
        MOVS     R0,#+0
        POP      {R1,R2,R4,PC}    ;; return

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
ble_peripheral_at_cmd_auth:
        PUSH     {R2-R7,R9,LR}
        MOV      R6,R1
        LDR      R7,[R6, #+4]
        MOV      R5,R0
        LDR.N    R1,??DataTable4_7
        MOV      R0,R7
        BL       strcmp
        CBNZ.N   R0,??ble_peripheral_at_cmd_auth_0
        CMP      R5,#+3
        BNE.N    ??ble_peripheral_at_cmd_auth_1
        LDR      R0,[R6, #+8]
        BL       atoi
        UXTB     R0,R0
        BL       le_bond_pair
??ble_peripheral_at_cmd_auth_2:
        MOV      R0,R9
??ble_peripheral_at_cmd_auth_3:
        POP      {R1,R2,R4-R7,R9,PC}  ;; return
??ble_peripheral_at_cmd_auth_0:
        ADR.N    R1,??DataTable4  ;; "KEY"
        MOV      R0,R7
        BL       strcmp
        CBNZ.N   R0,??ble_peripheral_at_cmd_auth_4
        CMP      R5,#+4
        BNE.N    ??ble_peripheral_at_cmd_auth_1
        LDR      R0,[R6, #+8]
        BL       atoi
        LDR      R7,[R6, #+12]
        MOV      R5,R0
        MOV      R0,R7
        BL       strlen
        CMP      R0,#+7
        ITE      CS 
        MOVCS    R6,#+2
        MOVCC    R6,#+1
        MOVS     R4,#+0
        B.N      ??ble_peripheral_at_cmd_auth_5
??ble_peripheral_at_cmd_auth_6:
        LDRSB    R0,[R7, R4]
        CMP      R0,#+48
        BLT.N    ??ble_peripheral_at_cmd_auth_7
        ADDS     R4,R4,#+1
        LDRSB    R0,[R7, R4]
        CMP      R0,#+58
        BGE.N    ??ble_peripheral_at_cmd_auth_7
        ADDS     R4,R4,#+2
??ble_peripheral_at_cmd_auth_5:
        MOV      R0,R7
        BL       strlen
        CMP      R4,R0
        BCC.N    ??ble_peripheral_at_cmd_auth_6
        MOV      R0,R7
        BL       atoi
        MOV      R7,R0
        LDR.N    R0,??DataTable4_8  ;; 0xf4240
        CMP      R7,R0
        BCC.N    ??ble_peripheral_at_cmd_auth_8
        LDR.N    R0,??DataTable4_9
        BL       printf
        MOVS     R6,#+2
??ble_peripheral_at_cmd_auth_8:
        MOV      R2,R6
        MOV      R1,R7
        UXTB     R0,R5
        BL       le_bond_passkey_input_confirm
        B.N      ??ble_peripheral_at_cmd_auth_2
??ble_peripheral_at_cmd_auth_4:
        LDR.N    R1,??DataTable4_10
        MOV      R0,R7
        BL       strcmp
        CMP      R0,#+0
??ble_peripheral_at_cmd_auth_1:
        BNE.N    ??ble_peripheral_at_cmd_auth_7
        MOVS     R1,#+1
        STRB     R1,[SP, #+4]
        STRH     R1,[SP, #+2]
        MOVS     R1,#+3
        STRB     R1,[SP, #+1]
        MOVS     R2,#+0
        MOVS     R1,#+1
        STRB     R2,[SP, #+0]
        STRH     R1,[SP, #+6]
        CMP      R5,#+3
        BLT.N    ??ble_peripheral_at_cmd_auth_9
        LDR      R4,[R6, #+8]
        MOV      R0,R4
        BL       strlen
        MOV      R1,R4
        BL       hex_str_to_int
        STRH     R0,[SP, #+2]
        LDRH     R1,[SP, #+2]
        STRH     R1,[SP, #+6]
??ble_peripheral_at_cmd_auth_9:
        CMP      R5,#+4
        BLT.N    ??ble_peripheral_at_cmd_auth_10
        LDR      R0,[R6, #+12]
        BL       atoi
        STRB     R0,[SP, #+1]
??ble_peripheral_at_cmd_auth_10:
        CMP      R5,#+4
        BLE.N    ??ble_peripheral_at_cmd_auth_11
        LDR      R0,[R6, #+16]
        BL       atoi
        STRB     R0,[SP, #+0]
??ble_peripheral_at_cmd_auth_11:
        ADD      R2,SP,#+4
        MOVS     R1,#+1
        MOVW     R0,#+514
        BL       gap_set_param
        ADD      R2,SP,#+2
        MOVS     R1,#+2
        MOVW     R0,#+515
        BL       gap_set_param
        ADD      R2,SP,#+1
        MOVS     R1,#+1
        MOV      R0,#+516
        BL       gap_set_param
        MOV      R2,SP
        MOVS     R1,#+1
        MOVW     R0,#+531
        BL       le_bond_set_param
        ADD      R2,SP,#+6
        MOVS     R1,#+2
        MOV      R0,#+532
        BL       le_bond_set_param
        BL       gap_set_pairable_mode
        MOVS     R9,R0
        ITE      NE 
        LDRNE.N  R0,??DataTable4_11
        LDREQ.N  R0,??DataTable4_12
        BL       printf
        B.N      ??ble_peripheral_at_cmd_auth_2
??ble_peripheral_at_cmd_auth_7:
        LDR.N    R0,??DataTable4_13
        BL       printf
        MOV      R0,#-1
        B.N      ??ble_peripheral_at_cmd_auth_3

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
ble_peripheral_at_cmd_send_userconf:
        PUSH     {R3-R5,LR}
        MOV      R4,R1
        LDR      R0,[R4, #+4]
        BL       atoi
        MOV      R5,R0
        LDR      R0,[R4, #+8]
        BL       atoi
        UXTB     R0,R0
        CMP      R0,#+0
        UXTB     R0,R5
        POP      {R2,R4,R5,LR}
        ITE      EQ 
        MOVEQ    R1,#+2
        MOVNE    R1,#+1
        B.W      le_bond_user_confirm

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
ble_peripheral_at_cmd_update_conn_request:
        PUSH     {R0-R8,LR}
        MOV      R5,R1
        LDR      R0,[R5, #+4]
        BL       atoi
        LDR      R6,[R5, #+8]
        MOV      R8,R0
        MOV      R0,R6
        BL       strlen
        MOV      R1,R6
        BL       hex_str_to_int
        LDR      R7,[R5, #+12]
        MOV      R6,R0
        MOV      R0,R7
        BL       strlen
        MOV      R1,R7
        BL       hex_str_to_int
        LDR      R4,[R5, #+16]
        MOV      R7,R0
        MOV      R0,R4
        BL       strlen
        MOV      R1,R4
        BL       hex_str_to_int
        LDR      R5,[R5, #+20]
        MOV      R4,R0
        MOV      R0,R5
        BL       strlen
        MOV      R1,R5
        BL       hex_str_to_int
        SUBS     R1,R7,#+1
        SUBS     R2,R6,#+1
        LSLS     R1,R1,#+17
        LSLS     R2,R2,#+17
        LSRS     R1,R1,#+16
        LSRS     R2,R2,#+16
        UXTH     R0,R0
        STR      R1,[SP, #+8]
        STR      R2,[SP, #+4]
        STR      R0,[SP, #+0]
        UXTH     R3,R4
        UXTH     R2,R7
        UXTH     R1,R6
        UXTB     R0,R8
        BL       le_update_conn_param
        ADD      SP,SP,#+16
        POP      {R4-R8,PC}       ;; return

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
ble_peripheral_at_cmd_bond_information:
        PUSH     {R4-R6,LR}
        SUB      SP,SP,#+24
        LDR      R4,[R1, #+4]
        LDR.N    R1,??DataTable4_14
        MOV      R0,R4
        BL       strcmp
        CBNZ.N   R0,??ble_peripheral_at_cmd_bond_information_0
        BL       le_bond_clear_all_keys
??ble_peripheral_at_cmd_bond_information_1:
        MOVS     R0,#+0
??ble_peripheral_at_cmd_bond_information_2:
        ADD      SP,SP,#+24
        POP      {R4-R6,PC}       ;; return
??ble_peripheral_at_cmd_bond_information_0:
        LDR.N    R1,??DataTable4_15
        MOV      R0,R4
        BL       strcmp
        CBNZ.N   R0,??ble_peripheral_at_cmd_bond_information_3
        MOVS     R6,#+0
        LDR.N    R4,??DataTable4_16
        LDR.N    R5,??DataTable4_17
??ble_peripheral_at_cmd_bond_information_4:
        LDRB     R1,[R5, #+0]
        UXTB     R0,R6
        CMP      R0,R1
        BCS.N    ??ble_peripheral_at_cmd_bond_information_1
        BL       le_find_key_entry_by_idx
        CBZ.N    R0,??ble_peripheral_at_cmd_bond_information_5
        LDRH     R1,[R0, #+2]
        STR      R1,[SP, #+20]
        LDRB     R2,[R0, #+14]
        STR      R2,[SP, #+16]
        LDRB     R1,[R0, #+8]
        STR      R1,[SP, #+12]
        LDRB     R2,[R0, #+9]
        STR      R2,[SP, #+8]
        LDRB     R1,[R0, #+10]
        STR      R1,[SP, #+4]
        LDRB     R2,[R0, #+11]
        STR      R2,[SP, #+0]
        LDRB     R3,[R0, #+12]
        LDRB     R2,[R0, #+13]
        LDRB     R1,[R0, #+1]
        MOV      R0,R4
        BL       printf
??ble_peripheral_at_cmd_bond_information_5:
        ADDS     R6,R6,#+1
        B.N      ??ble_peripheral_at_cmd_bond_information_4
??ble_peripheral_at_cmd_bond_information_3:
        MOV      R0,#-1
        B.N      ??ble_peripheral_at_cmd_bond_information_2

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable4:
        DC8      "KEY"

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable4_1:
        DC32     evt_queue_handle

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable4_2:
        DC32     io_queue_handle

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable4_3:
        DC32     `ble_peripheral_at_cmd_send_msg::__func__`

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable4_4:
        DC32     ?_0

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable4_5:
        DC32     ?_1

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable4_6:
        DC32     gap_dev_state

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable4_7:
        DC32     ?_2

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable4_8:
        DC32     0xf4240

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable4_9:
        DC32     ?_5

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable4_10:
        DC32     ?_6

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable4_11:
        DC32     ?_8

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable4_12:
        DC32     ?_7

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable4_13:
        DC32     ?_3

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable4_14:
        DC32     ?_9

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable4_15:
        DC32     ?_10

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable4_16:
        DC32     ?_11

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable4_17:
        DC32     bond_storage_num

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
ble_peripheral_app_handle_at_cmd:
        PUSH     {R4-R6,LR}
        SUB      SP,SP,#+48
        MOV      R5,R0
        MOV      R4,R1
        MOV      R0,SP
        MOVS     R1,#+48
        MOVS     R6,#+0
        BL       __aeabi_memclr4
        CBZ.N    R4,??ble_peripheral_app_handle_at_cmd_0
        MOV      R1,SP
        MOV      R0,R4
        BL       parse_param
        MOV      R6,R0
??ble_peripheral_app_handle_at_cmd_0:
        CMP      R5,#+3
        BEQ.N    ??ble_peripheral_app_handle_at_cmd_1
        CMP      R5,#+6
        BEQ.N    ??ble_peripheral_app_handle_at_cmd_2
        CMP      R5,#+7
        BEQ.N    ??ble_peripheral_app_handle_at_cmd_3
        CMP      R5,#+8
        ITTT     EQ 
        MOVEQ    R1,SP
        MOVEQ    R0,R6
        BLEQ     ble_peripheral_at_cmd_bond_information
        B.N      ??ble_peripheral_app_handle_at_cmd_4
??ble_peripheral_app_handle_at_cmd_1:
        MOV      R1,SP
        MOV      R0,R6
        BL       ble_peripheral_at_cmd_auth
        B.N      ??ble_peripheral_app_handle_at_cmd_4
??ble_peripheral_app_handle_at_cmd_2:
        MOV      R1,SP
        MOV      R0,R6
        BL       ble_peripheral_at_cmd_send_userconf
        B.N      ??ble_peripheral_app_handle_at_cmd_4
??ble_peripheral_app_handle_at_cmd_3:
        MOV      R1,SP
        MOV      R0,R6
        BL       ble_peripheral_at_cmd_update_conn_request
??ble_peripheral_app_handle_at_cmd_4:
        MOVS     R0,#+0
        ADD      SP,SP,#+48
        POP      {R4-R6,PC}       ;; return

        SECTION `.rodata`:CONST:REORDER:NOROOT(2)
        DATA
// __absolute char const __func__[31]
`ble_peripheral_at_cmd_send_msg::__func__`:
        DC8 "ble_peripheral_at_cmd_send_msg"
        DC8 0

        SECTION `.rodata`:CONST:REORDER:NOROOT(2)
        DATA
?_0:
        DC8 "ble peripheral at cmd send msg fail: subtype 0x%x"
        DC8 0, 0

        SECTION `.rodata`:CONST:REORDER:NOROOT(2)
        DATA
?_1:
        DC8 62H, 6CH, 65H, 20H, 70H, 65H, 72H, 69H
        DC8 70H, 68H, 65H, 72H, 61H, 6CH, 20H, 61H
        DC8 74H, 20H, 63H, 6DH, 64H, 20H, 73H, 65H
        DC8 6EH, 64H, 20H, 65H, 76H, 65H, 6EH, 74H
        DC8 20H, 66H, 61H, 69H, 6CH, 3AH, 20H, 73H
        DC8 75H, 62H, 74H, 79H, 70H, 65H, 20H, 30H
        DC8 78H, 25H, 78H, 0

        SECTION `.rodata`:CONST:REORDER:NOROOT(2)
        DATA
?_2:
        DC8 "SEND"
        DC8 0, 0, 0

        SECTION `.rodata`:CONST:REORDER:NOROOT(2)
        DATA
?_3:
        DC8 "ERROR:input parameter error!\012\015"
        DC8 0

        SECTION `.rodata`:CONST:REORDER:NOROOT(2)
        DATA
        DC8 "KEY"

        SECTION `.rodata`:CONST:REORDER:NOROOT(2)
        DATA
?_5:
        DC8 "ERROR:passcode is out of range[0-999999] !\012\015"
        DC8 0, 0, 0

        SECTION `.rodata`:CONST:REORDER:NOROOT(2)
        DATA
?_6:
        DC8 "MODE"
        DC8 0, 0, 0

        SECTION `.rodata`:CONST:REORDER:NOROOT(2)
        DATA
?_7:
        DC8 "\012\015Set pairable mode success!\015\012"
        DC8 0

        SECTION `.rodata`:CONST:REORDER:NOROOT(2)
        DATA
?_8:
        DC8 "\012\015Set pairable mode fail!\015\012"

        SECTION `.rodata`:CONST:REORDER:NOROOT(2)
        DATA
?_9:
        DC8 "CLEAR"
        DC8 0, 0

        SECTION `.rodata`:CONST:REORDER:NOROOT(2)
        DATA
?_10:
        DC8 "INFO"
        DC8 0, 0, 0

        SECTION `.rodata`:CONST:REORDER:NOROOT(2)
        DATA
?_11:
        DC8 62H, 6FH, 6EH, 64H, 5FH, 64H, 65H, 76H
        DC8 5BH, 25H, 64H, 5DH, 3AH, 20H, 62H, 64H
        DC8 20H, 30H, 78H, 25H, 30H, 32H, 78H, 25H
        DC8 30H, 32H, 78H, 25H, 30H, 32H, 78H, 25H
        DC8 30H, 32H, 78H, 25H, 30H, 32H, 78H, 25H
        DC8 30H, 32H, 78H, 2CH, 20H, 61H, 64H, 64H
        DC8 72H, 5FH, 74H, 79H, 70H, 65H, 20H, 25H
        DC8 64H, 2CH, 20H, 66H, 6CH, 61H, 67H, 73H
        DC8 20H, 30H, 78H, 25H, 78H, 0DH, 0AH, 0

        SECTION `.rodata`:CONST:REORDER:NOROOT(2)
        DATA
        DC32 0H
        DC8 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
        DC8 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
        DC8 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0

        SECTION `.iar_vfe_header`:DATA:NOALLOC:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
        DC32 0

        END
// 
//   432 bytes in section .rodata
// 1 020 bytes in section .text
// 
// 1 020 bytes of CODE  memory
//   432 bytes of CONST memory
//
//Errors: none
//Warnings: none
