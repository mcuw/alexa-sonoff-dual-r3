# Alexa with Sonoff Dual R3

## Description

This project controls a Sonoff Dual R3 switch with Alexa commands. The integrated microcontroller is a espressif [esp32](https://www.espressif.com/en/products/socs/esp32).

## Prerequisites

- [VSCode](https://code.visualstudio.com/) IDE

- [pioarduino IDE](#Pioarduino) for [VSCode](https://code.visualstudio.com/) IDE

- Sonoff Dual R3, 4MB flash, 15A Max, Wi-Fi 2.4 GHz

- Alexa

## Flashing

|Sonoff|Serial adapter|
|---|---|
|VCC| 3.3V|
|TX|RX|
|RX|TX|
|GND|GND|

1. Keep pushing the button on the sonoff then connect the USB Adapter

2. You can release the button again and can start with the flashing

3. After flashing disconnect and connect the Serial adapter again

## Pioarduino

Install the [pioarduino IDE](https://marketplace.visualstudio.com/items?itemName=pioarduino.pioarduino-ide) extension which replaces the [PlatformIO IDE](https://marketplace.visualstudio.com/items?itemName=platformio.platformio-ide) extension.

## Getting started

### Variant A - use VSCode to build and download firmware:

- clone this project
```sh
git clone https://github.com/vanvuongngo/alexa-sonoff-dual-r3.git
```

- open with [VSCode](https://code.visualstudio.com/) IDE

- click on Upload

<img src="assets/upload_option.png" alt="upload icon on the toolbar">


### Variant B - use the precompiled firmware:

- download the firmware see [Releases](#Releases)

- upload the firmware to the Sonoff Dual R3

### Configuration after firmware download

1. Connect the Serial adapter and boot the Sonoff
2. Pressing the button of the Sonoff Dual R3 for a couple of seconds
3. A Wi-Fi AP `OnDemandAP` should be activated and visible; connect it 
4. An UI should shown otherwise open http://192.168.1.4


## Examples

| name | description |
| --- | --- |
| serial | simple app to check that the ESP32 is working and can communicate |
| logging | shows how log level is working  |
| OTA | simple OTA - flashing with WLAN instead of cable |


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

## Create a release

1. Login to github
2. Implement your application in the [src/main.cpp](src/main.cpp)
4. Comment your new change in the [CHANGELOG.md](CHANGELOG.md) file
5. Push your changes
```sh
git add .
```

```sh
git commit -am "my changes ..."
```

```sh
git push -u origin main
```

6. Create a new tag to trigger a release, e.g. for v1.0.0

```sh
git tag v1.0.0
```

```sh
git push origin v1.0.0
```

6. You can find your firmwares under `Releases` after the CI build finished

## CHANGELOG

You can write your changes in the [CHANGELOG.md](CHANGELOG.md) before you create a release. It will be shown under the release page.

## Releases

Firmwares see under [Releases](https://github.com/vanvuongngo/alexa-sonoff-dual-r3/releases) on the right sidemenu.

## Espressif32 platform

The `Espressif32` platform is not supporting the latest microcontroller models. Because of that the new community fork called [Pioarduino](https://github.com/pioarduino/platform-espressif32) started, it is compatible with [Espressif32 for PlatformIO](https://github.com/platformio/platform-espressif32) and supports boards like ESP32-C6, ESP32-H2, and ESP32-P4 and others.
If you want to keep using the old way then switch to the `espressif32-platform` branch:

```sh
git checkout espressif32-platform
```

## Disclaimer

Contribution and help - if you find an issue or wants to contribute then please do not hesitate to create a pull request or an issue.

We provide our build template as is, and we make no promises or guarantees about this code.
