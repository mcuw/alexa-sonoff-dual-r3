#ifndef PINOUT_H
#define PINOUT_H

#define LED GPIO_NUM_13
#define BUTTON GPIO_NUM_0

// Relay Module Pins
#define RELAY_LED_1 GPIO_NUM_27
#define RELAY_LED_2 GPIO_NUM_14
#define RELAY_SWITCH_1 GPIO_NUM_32
#define RELAY_SWITCH_2 GPIO_NUM_33

// Power Sensor Pins
// CSE7761 sensor (v1.x), while later versions use the BL0939 sensor (v2.x)
#define POWER_SENSOR_TX GPIO_NUM_25
#define POWER_SENSOR_RX GPIO_NUM_26

#endif