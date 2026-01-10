/*
  This example demonstrates how to use WiFiManager to start a configuration portal
  on demand when a button is pressed. It also prints the active firmware version.
  No need for credentials stored in the code.
  The configuration portal will create an access point with the name "SonOffAP" and save the credentials in flash.
*/
#include <Arduino.h>
#include <WiFi.h>
#include <HTTPUpdate.h>
#include <WiFiClientSecure.h>
#include <WiFiManager.h>

#define FirmwareVersion 8
#define BUTTON GPIO_NUM_0

WiFiManager wifiManager;
bool connected = false;

const char *AP_NAME = "SonOffAP";
const char *AP_PASS = "esp32ota";

void setup()
{
  Serial.begin(115200);

  pinMode(BUTTON, INPUT);

  Serial.print(F("Active firmware version: "));
  Serial.println(FirmwareVersion);

  wifiManager.autoConnect(AP_NAME, AP_PASS);
}

void loop()
{
  Serial.print(F("Active firmware version: "));
  Serial.println(FirmwareVersion);

  uint8_t state = digitalRead(BUTTON);
  if (state == LOW)
  {
    Serial.println("Button pushed");
    // wifiManager.setDebugOutput(false);
    connected = wifiManager.startConfigPortal(AP_NAME, AP_PASS);
  }

  if (WiFi.status() == WL_CONNECTED)
  {
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
    Serial.println();
  }

  delay(2000);
}