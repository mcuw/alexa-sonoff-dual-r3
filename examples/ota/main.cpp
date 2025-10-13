#include <Arduino.h>
#include <WiFi.h>
#include <HTTPUpdate.h>
#include <WiFiClientSecure.h>
// #include <EspGhOta.h>
#include <WiFiManager.h>
#include <NetworkClientSecure.h>
#include "caCert.h"

#define FirmwareVersion 1
#define REPOSITORY "vanvuongngo/alexa-sonoff-dual-r3" // change to your repository!
#define BUTTON GPIO_NUM_0

#define FW_VERSION_URL "https://github.com/%s/releases/latest"
static const char *MODULE_NAME = "EspGhOta";
// EspGhOta ota(REPOSITORY);
HTTPClient https;
NetworkClientSecure *client = new NetworkClientSecure;
WiFiManager wifiManager;
bool initialized = false;

void setup()
{
  Serial.begin(115200);

  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(BUTTON, INPUT);

  Serial.print(F("Active firmware version: "));
  Serial.println(FirmwareVersion);
}

// activate WiFiManager on demand to setup WiFi
void startOnDemandAP() {
  wifiManager.startConfigPortal("OnDemandAP");
  Serial.println("WiFiManager started: OnDemandAP");
}

void loop()
{
  if (!client)
  {
    Serial.println("Unable to create client. Restarting in 5s ...");
    delay(5000);
    ESP.restart();
  }

  uint8_t state = digitalRead(BUTTON);
  Serial.print("state: ");
  Serial.println(state == HIGH ? "HIGH" : "LOW");

  if (state == LOW)
  {
    Serial.println("Button pushed");
    startOnDemandAP();
    initialized = true;
  }

  if (initialized)
  {
    while (WiFi.status() != WL_CONNECTED)
    {
      Serial.print(".");
      delay(500);
    }

    Serial.println("Wi-Fi is connected");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
    Serial.println();

    client->setCACert(caCert);

    char urlGetLatestRelease[256];
    sprintf(urlGetLatestRelease, FW_VERSION_URL, REPOSITORY);
    if (https.begin(*client, urlGetLatestRelease))
    {
      int httpCode = https.GET();
      if (httpCode == HTTP_CODE_FOUND)
      {
        String location(https.getLocation());
        Serial.print("location: ");
        Serial.println(location);

        String token(location.substring(location.indexOf("/tag/")));
        Serial.print("token: ");
        Serial.println(token);

        if (!token.length())
        {
          ESP_LOGW(MODULE_NAME, "No releases exists yet");
        }
        String latestVersion = token.substring(5); // w/o "/tag/"
        Serial.print("latestVersion: ");
        Serial.println(latestVersion);
      }
      else
      {
        ESP_LOGE(MODULE_NAME, "Failed to get the latest release - HTTP code: %s", httpCode);
      }
      https.end();
    } else {
      ESP_LOGE(MODULE_NAME, "Failed to connect: %s", urlGetLatestRelease);
    }

    // String maybelatestVersion(ota.checkFirmwareVersion(FirmwareVersion));
    // ota.updateFirmware(maybelatestVersion);
  }

  delay(2000);
}