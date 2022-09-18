you can use tickless roaming when you use tickless.

1.add the "example_tickless_wifi_roaming.c" to the project
2.#define CONFIG_EXAMPLE_WLAN_FAST_CONNECT	1
3.#define CONFIG_EXAMPLE_TICKLESS_WIFI_ROAMING 1

In FreeRTOSConfig.h
4.#define configUSE_TICKLESS_IDLE 1
5.#define configUSE_CUSTOMIZED_TICKLESS_IDLE 1