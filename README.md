# ESP32 project template

## Description

Alexa with Sonoff Dual R3.

## Prerequisites

- Platformio

## Requirements

- [platformio](https://platformio.org/)
- Sonoff Dual R3, 4MB flash, 15A Max, Wi-Fi 2.4 GHz

## Flashing

connect with USB to Serial adapter
VCC - 3.3V
TX - RX
RX - TX
GND - GND

Keep pushing the button then insert the USB Adapter.

Now, you can flash the firmware.

## Examples

| example | description |
| --- | --- |
| serial | simple app to check that the ESP32 is working and can communicate |
| OTA | simple OTA - flashing with WLAN instead of cable |

## Supported boards

Buy on AliExpress (affiliate links) ...


## Pinouts

GPIO13: Status LED (blue, inverted)

GPIO00: Push Button (inverted)

GPIO27: Relay 1 / LED 1 (red)

GPIO14: Relay 2 / LED 2 (red)

GPIO32: Switch 1 (inverted)

GPIO33: Switch 2 (inverted)


For the Sonoff Dual R3 (PCB versions 1.x, 2.x), additional pins are used for power monitoring:

GPIO25: Power sensor UART Tx

GPIO26: Power sensor UART Rx

## Power Monitoring

The power monitoring chip differs between versions: earlier versions use the CSE7761 sensor (v1.x), while later versions use the BL0939 sensor (v2.x).

 The pinout for the Sonoff Dual R3 Lite (PCB version 1.x) does not include the power sensor pins.

## Disclaimer

Contribution and help - if you find an issue or wants to contribute then please do not hesitate to create a pull request or an issue.

We provide our build template as is, and we make no promises or guarantees about this code.
