
/*============================================================================*
 *                              Header Files
 *============================================================================*/
#include <platform_opts_bt.h>
#include <os_sched.h>
#include <string.h>
#include <trace_app.h>
#include <gap.h>
#include <gap_adv.h>
#include <gap_bond_le.h>
#include <gap_msg.h>
#include <bas.h>
#include <bte.h>
#include <gap_config.h>
#include <bt_flags.h>
#include "platform_stdlib.h"
#include "wifi_constants.h"
#include <wifi/wifi_conf.h>
#include "rtk_coex.h"

#include "hsn_common.h"


/** @defgroup  PERIPH_DEMO_MAIN Peripheral Main
    * @brief Main file to initialize hardware and BT stack and start task scheduling
    * @{
    */

/*============================================================================*
 *                              Constants
 *============================================================================*/
/** @brief  Default minimum advertising interval when device is discoverable (units of 625us, 160=100ms) */
#define DEFAULT_ADVERTISING_INTERVAL_MIN            352 //220ms
/** @brief  Default maximum advertising interval */
#define DEFAULT_ADVERTISING_INTERVAL_MAX            384 //240ms


/*============================================================================*
 *                              Variables
 *============================================================================*/

/** @brief  GAP - scan response data (max size = 31 bytes) */
#if 0
static const uint8_t scan_rsp_data[] =
{
    0x03,                             /* length */
    GAP_ADTYPE_APPEARANCE,            /* type="Appearance" */
    LO_WORD(GAP_GATT_APPEARANCE_UNKNOWN),
    HI_WORD(GAP_GATT_APPEARANCE_UNKNOWN),
};
#endif
/** @brief  GAP - Advertisement data (max size = 31 bytes, best kept short to conserve power) */


#ifdef HSN_UPDATE_20210924
static uint8_t adv_data[] =
{
    /* Service */
    0x0A,             			//0, length
    GAP_ADTYPE_SERVICE_DATA,	//1, 
    0xFF,	//2, 
    0xFF,	//3,
    0x02,	//4,version
    0x00,	//5,dev type, 0x01�յ�, 0x27����, 0x07ϴ�����0x2A��ů¯, 0x02����
    0x04,	//6,device info, bti4=1
    0x0D,	//7,capacity
    0x00,	//8,device type detail
    0x00,	//9,rssi
    0x00,	//10,rssi
    /* Local name */
    0x09,             			//11, length
    GAP_ADTYPE_LOCAL_NAME_COMPLETE,	//12, local name
    'H', 'I', 'S', '-', 'x', 'x', 'y', 'y',
};


#else
static uint8_t adv_data[] =
{
    /* Service */
    0x09,             			//0, length
    GAP_ADTYPE_SERVICE_DATA,	//1, 
    0x9B,	//2, 
    0x10,	//3,
    0x01,	//4,version
    0x00,	//5,dev type, 0x01�յ�, 0x27����, 0x07ϴ�����0x2A��ů¯, 0x02����
    0x04,	//6,device info, bti4=1
    0x0F,	//7,capacity
    0x00,	//8,device type detail
    0x00,	//9,resrved
    /* Local name */
    0x09,             			//10, length
    GAP_ADTYPE_LOCAL_NAME_COMPLETE,	//11, local name
    'H', 'I', 'S', '-', 'x', 'x', 'y', 'y',
};

#endif

/*============================================================================*
 *                              Functions
 *============================================================================*/
/**
 * @brief  Config bt stack related feature
 *
 * NOTE: This function shall be called before @ref bte_init is invoked.
 * @return void
 */
#ifdef HSN_BLE_CONFIG
extern struct netif xnetif[NET_IF_NUM];
void hsn_bt_config_app_set_adv_data(void)
{
	/* Modify Device name according to BD addr*/
	t_WIFI_GLOBAL* pl_wg = MC_WIFI_GLOBAL_PTR();
	t_CONFIG_TABLE_BODY* pl_cfg = MC_WG_CONFIG_TABLE_PTR();

	uint8_t  device_name[GAP_DEVICE_NAME_LEN] = "HIS-xxyy";
	unsigned char* pl_wifi_mac = LwIP_GetMAC(&xnetif[0]);
	//uint8_t bt_addr[6];
	//gap_get_param(GAP_PARAM_BD_ADDR, bt_addr);
	WAPI_DUMP_HEX(pl_wifi_mac,6,"wifi addr:");
	
	sprintf((char *)device_name,"HIS-%02X%02X",pl_wifi_mac[4],pl_wifi_mac[5]);
#ifdef HSN_UPDATE_20210924
	memcpy(adv_data+13,device_name,strlen((char const*)device_name));
#else
	memcpy(adv_data+12,device_name,strlen((char const*)device_name));
#endif

	
	if (pl_wg->v_device_type == HSN_DEVICE_TYPE_ICEBOX
		|| pl_wg->v_device_type == HSN_DEVICE_TYPE_DISHWASHER
		|| pl_wg->v_device_type == HSN_DEVICE_TYPE_HEATING_STOVE
		|| pl_wg->v_device_type == HSN_DEVICE_TYPE_RANGE_HOOD	
		|| pl_wg->v_device_type == HSN_DEVICE_TYPE_STOVE
		|| pl_wg->v_device_type == HSN_DEVICE_TYPE_WATER_HEATER_ELECTIC
		|| pl_wg->v_device_type == HSN_DEVICE_TYPE_WATER_HEATER_GAS
		|| pl_wg->v_device_type == HSN_DEVICE_TYPE_OVEN_1
		|| pl_wg->v_device_type == HSN_DEVICE_TYPE_WASHING
		|| pl_wg->v_device_type == HSN_DEVICE_TYPE_DRYER
		)
	{
		adv_data[5] = pl_wg->v_device_type;
		printf("device type: %d(%02XH)", adv_data[5], adv_data[5]);
	}	
#ifdef HSN_UPDATE_20210924
	if (WIFI_MODE_IDLE == pl_cfg->v_cur_mode)
	{
		adv_data[6] = 0x04;
	}
	else
	{
		adv_data[6] = 0x00;
	}

	adv_data[7] = 0x0D;
#endif
	

	le_set_gap_param(GAP_PARAM_DEVICE_NAME, GAP_DEVICE_NAME_LEN, device_name);
	le_adv_set_param(GAP_PARAM_ADV_DATA, sizeof(adv_data), (void *)adv_data);
}
#endif


extern void gap_config_hci_task_secure_context(uint32_t size);
void bt_stack_config_init(void)
{
    gap_config_max_le_link_num(APP_MAX_LINKS);
    gap_config_max_le_paired_device(APP_MAX_LINKS);
    gap_config_hci_task_secure_context (280);
}

/**
  * @brief  Initialize peripheral and gap bond manager related parameters
  * @return void
  */
void app_le_gap_init(void)
{
    /* Device name and device appearance */
#ifdef HSN_BLE_CONFIG
    uint8_t  device_name[GAP_DEVICE_NAME_LEN] = "HIS-xxyy";
#else
	uint8_t  device_name[GAP_DEVICE_NAME_LEN] = "BLE_PERIPHERAL";
#endif
    uint16_t appearance = GAP_GATT_APPEARANCE_UNKNOWN;
#ifdef HSN_UPDATE_20210924
    uint8_t  slave_init_mtu_req = true;
#else
	uint8_t  slave_init_mtu_req = false;
#endif


    /* Advertising parameters */
    uint8_t  adv_evt_type = GAP_ADTYPE_ADV_IND;
    uint8_t  adv_direct_type = GAP_REMOTE_ADDR_LE_PUBLIC;
    uint8_t  adv_direct_addr[GAP_BD_ADDR_LEN] = {0};
    uint8_t  adv_chann_map = GAP_ADVCHAN_ALL;
    uint8_t  adv_filter_policy = GAP_ADV_FILTER_ANY;
    uint16_t adv_int_min = DEFAULT_ADVERTISING_INTERVAL_MIN;
    uint16_t adv_int_max = DEFAULT_ADVERTISING_INTERVAL_MAX;

    /* GAP Bond Manager parameters */
    uint8_t  auth_pair_mode = GAP_PAIRING_MODE_PAIRABLE;
    uint16_t auth_flags = GAP_AUTHEN_BIT_BONDING_FLAG;
    uint8_t  auth_io_cap = GAP_IO_CAP_NO_INPUT_NO_OUTPUT;
#if F_BT_LE_SMP_OOB_SUPPORT
    uint8_t  auth_oob = false;
#endif
    uint8_t  auth_use_fix_passkey = false;
    uint32_t auth_fix_passkey = 0;
    uint8_t  auth_sec_req_enable = false;
    uint16_t auth_sec_req_flags = GAP_AUTHEN_BIT_BONDING_FLAG;

    /* Set device name and device appearance */
    le_set_gap_param(GAP_PARAM_DEVICE_NAME, GAP_DEVICE_NAME_LEN, device_name);
    le_set_gap_param(GAP_PARAM_APPEARANCE, sizeof(appearance), &appearance);
    le_set_gap_param(GAP_PARAM_SLAVE_INIT_GATT_MTU_REQ, sizeof(slave_init_mtu_req),
                     &slave_init_mtu_req);

    /* Set advertising parameters */
    le_adv_set_param(GAP_PARAM_ADV_EVENT_TYPE, sizeof(adv_evt_type), &adv_evt_type);
    le_adv_set_param(GAP_PARAM_ADV_DIRECT_ADDR_TYPE, sizeof(adv_direct_type), &adv_direct_type);
    le_adv_set_param(GAP_PARAM_ADV_DIRECT_ADDR, sizeof(adv_direct_addr), adv_direct_addr);
    le_adv_set_param(GAP_PARAM_ADV_CHANNEL_MAP, sizeof(adv_chann_map), &adv_chann_map);
    le_adv_set_param(GAP_PARAM_ADV_FILTER_POLICY, sizeof(adv_filter_policy), &adv_filter_policy);
    le_adv_set_param(GAP_PARAM_ADV_INTERVAL_MIN, sizeof(adv_int_min), &adv_int_min);
    le_adv_set_param(GAP_PARAM_ADV_INTERVAL_MAX, sizeof(adv_int_max), &adv_int_max);
#ifdef HSN_BLE_CONFIG
	hsn_bt_config_app_set_adv_data();
#else
	le_adv_set_param(GAP_PARAM_ADV_DATA, sizeof(adv_data), (void *)adv_data);
	le_adv_set_param(GAP_PARAM_SCAN_RSP_DATA, sizeof(scan_rsp_data), (void *)scan_rsp_data);
#endif	
    

    /* Setup the GAP Bond Manager */
    gap_set_param(GAP_PARAM_BOND_PAIRING_MODE, sizeof(auth_pair_mode), &auth_pair_mode);
    gap_set_param(GAP_PARAM_BOND_AUTHEN_REQUIREMENTS_FLAGS, sizeof(auth_flags), &auth_flags);
    gap_set_param(GAP_PARAM_BOND_IO_CAPABILITIES, sizeof(auth_io_cap), &auth_io_cap);
#if F_BT_LE_SMP_OOB_SUPPORT
    gap_set_param(GAP_PARAM_BOND_OOB_ENABLED, sizeof(auth_oob), &auth_oob);
#endif
    le_bond_set_param(GAP_PARAM_BOND_FIXED_PASSKEY, sizeof(auth_fix_passkey), &auth_fix_passkey);
    le_bond_set_param(GAP_PARAM_BOND_FIXED_PASSKEY_ENABLE, sizeof(auth_use_fix_passkey),
                      &auth_use_fix_passkey);
    le_bond_set_param(GAP_PARAM_BOND_SEC_REQ_ENABLE, sizeof(auth_sec_req_enable), &auth_sec_req_enable);
    le_bond_set_param(GAP_PARAM_BOND_SEC_REQ_REQUIREMENT, sizeof(auth_sec_req_flags),
                      &auth_sec_req_flags);

    /* register gap message callback */
    le_register_app_cb(app_gap_callback);

#if (F_BT_LE_USE_RANDOM_ADDR==1)
    T_APP_STATIC_RANDOM_ADDR random_addr;
    bool gen_addr = true;
    uint8_t local_bd_type = GAP_LOCAL_ADDR_LE_RANDOM;
    if (ble_peripheral_app_load_static_random_address(&random_addr) == 0)
    {
        if (random_addr.is_exist == true)
        {
            gen_addr = false;
        }
    }
    if (gen_addr)
    {
        if (le_gen_rand_addr(GAP_RAND_ADDR_STATIC, random_addr.bd_addr) == GAP_CAUSE_SUCCESS)
        {
            random_addr.is_exist = true;
            ble_peripheral_app_save_static_random_address(&random_addr);
        }
    }
    le_cfg_local_identity_address(random_addr.bd_addr, GAP_IDENT_ADDR_RAND);
    le_set_gap_param(GAP_PARAM_RANDOM_ADDR, 6, random_addr.bd_addr);
    //only for peripheral,broadcaster
    le_adv_set_param(GAP_PARAM_ADV_LOCAL_ADDR_TYPE, sizeof(local_bd_type), &local_bd_type);
    //only for central,observer
    //le_scan_set_param(GAP_PARAM_SCAN_LOCAL_ADDR_TYPE, sizeof(local_bd_type), &local_bd_type);
#elif (F_BT_LE_USE_RANDOM_ADDR==2) && F_BT_LE_LOCAL_IRK_SETTING_SUPPORT
    uint8_t irk_auto = true;
    le_bond_set_param(GAP_PARAM_BOND_GEN_LOCAL_IRK_AUTO, sizeof(uint8_t), &irk_auto);
#endif
}

/**
 * @brief  Add GATT services and register callbacks
 * @return void
 */
void app_le_profile_init(void)
{
    server_init(1);

    simp_srv_id = simp_ble_service_add_service((void *)app_profile_callback);
    //bas_srv_id  = bas_add_service((void *)app_profile_callback);
    server_register_app_cb(app_profile_callback);
}

/**
 * @brief    Contains the initialization of pinmux settings and pad settings
 * @note     All the pinmux settings and pad settings shall be initiated in this function,
 *           but if legacy driver is used, the initialization of pinmux setting and pad setting
 *           should be peformed with the IO initializing.
 * @return   void
 */
void board_init(void)
{

}

/**
 * @brief    Contains the initialization of peripherals
 * @note     Both new architecture driver and legacy driver initialization method can be used
 * @return   void
 */
void driver_init(void)
{

}

/**
 * @brief    Contains the power mode settings
 * @return   void
 */
void pwr_mgr_init(void)
{
}

/**
 * @brief    Contains the initialization of all tasks
 * @note     There is only one task in BLE Peripheral APP, thus only one APP task is init here
 * @return   void
 */
void task_init(void)
{
    app_task_init();
}

/**
 * @brief    Entry of APP code
 * @return   int (To avoid compile warning)
 */
int ble_app_main(void)
{

    bt_trace_init();
    bt_stack_config_init();
    bte_init();
    //board_init();
    le_gap_init(APP_MAX_LINKS);
    app_le_gap_init();
    app_le_profile_init();
    //pwr_mgr_init();
    task_init();//lxd123

    return 0;
}

extern void wifi_btcoex_set_bt_on(void);


int hsn_ble_init_for_factory(void)
{
	//int bt_stack_already_on = 0;
	//(void) bt_stack_already_on;
	T_GAP_DEV_STATE new_state;
	
	/*Wait WIFI init complete*/
	//while(!(wifi_is_up(RTW_STA_INTERFACE) || wifi_is_up(RTW_AP_INTERFACE))) {
	//	os_delay(200);
	//}

	//judge BLE central is already on
	le_get_gap_param(GAP_PARAM_DEV_STATE , &new_state);
	if (new_state.gap_init_state == GAP_INIT_STATE_STACK_READY) {
		//bt_stack_already_on = 1;
		printf("BT Stack already on\n\r");
		return 0;
	}
	else
	{
		bt_trace_init();
	    bt_stack_config_init();
	    bte_init();
	    le_gap_init(APP_MAX_LINKS);
	    //app_le_gap_init();
	    task_init();//lxd123
	}
		

	bt_coex_init();

	/*Wait BT init complete*/
	do {
		os_delay(100);
		le_get_gap_param(GAP_PARAM_DEV_STATE , &new_state);
	}while(new_state.gap_init_state != GAP_INIT_STATE_STACK_READY);

	/*Start BT WIFI coexistence*/
	wifi_btcoex_set_bt_on();

	printf("BT WIFI coexistence ok.\n");


	return 0;
}




static hsn_sta_change_cb s_func_sta_change_cb = NULL;
void hsn_set_sta_change_cb(hsn_sta_change_cb pp_func)
{
	s_func_sta_change_cb = pp_func;
}

int hsn_ble_app_init(void)
{
	//int bt_stack_already_on = 0;
	//(void) bt_stack_already_on;
	T_GAP_DEV_STATE new_state;
	
	/*Wait WIFI init complete*/
	while(!(wifi_is_up(RTW_STA_INTERFACE) || wifi_is_up(RTW_AP_INTERFACE))) {
		os_delay(200);
	}

	//judge BLE central is already on
	le_get_gap_param(GAP_PARAM_DEV_STATE , &new_state);
	if (new_state.gap_init_state == GAP_INIT_STATE_STACK_READY) {
		//bt_stack_already_on = 1;
		printf("BT Stack already on\n\r");
		return 0;
	}
	else
		ble_app_main();

	bt_coex_init();

	/*Wait BT init complete*/
	do {
		os_delay(100);
		le_get_gap_param(GAP_PARAM_DEV_STATE , &new_state);
	}while(new_state.gap_init_state != GAP_INIT_STATE_STACK_READY);

	/*Start BT WIFI coexistence*/
	wifi_btcoex_set_bt_on();

	printf("BT WIFI coexistence ok.\n");


	if (NULL != s_func_sta_change_cb)
	{
		s_func_sta_change_cb(HOST_ENTRY_MSG_BT_START, 1, NULL);
	}
	

	return 0;
}

extern void app_task_deinit(void);
extern bool bt_trace_uninit(void);
extern T_GAP_DEV_STATE gap_dev_state;

void hsn_ble_app_deinit(void)
{
	app_task_deinit();
	
	T_GAP_DEV_STATE state;
	le_get_gap_param(GAP_PARAM_DEV_STATE , &state);
	if (state.gap_init_state != GAP_INIT_STATE_STACK_READY) {
		printf("[BLE Peripheral]BT Stack is not running\n\r");
	}
#if F_BT_DEINIT
	else {
		bte_deinit();
		bt_trace_uninit();
		memset(&gap_dev_state, 0, sizeof(T_GAP_DEV_STATE));
		printf("[BLE Peripheral]BT Stack deinitalized\n\r");
	}
#endif
	if (NULL != s_func_sta_change_cb)
	{
		s_func_sta_change_cb(HOST_ENTRY_MSG_BT_START, 0, NULL);
	}
}

/** @} */ /* End of group PERIPH_DEMO_MAIN */

