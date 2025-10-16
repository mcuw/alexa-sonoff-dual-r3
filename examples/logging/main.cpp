#include "Arduino.h"

// doc: https://docs.platformio.org/en/latest/platforms/espressif32.html#debug-level
// activate in platformio.ini under build_flags, e.g. for verbose
// - DCORE_DEBUG_LEVEL=5

static const char *MODULE_NAME = "MyModule";

void setup() {
  Serial.begin(115200);
}

void loop() {
  Serial.println("ESP_LOGE...");
  ESP_LOGE(MODULE_NAME, "Error log");

  Serial.println("ESP_LOGW...");
  ESP_LOGW(MODULE_NAME, "Warning log");

  Serial.println("ESP_LOGI...");
  ESP_LOGI(MODULE_NAME, "Info log");

  Serial.println("ESP_LOGD...");
  ESP_LOGD(MODULE_NAME, "Debug log");

  Serial.println("ESP_LOGV...");
  ESP_LOGV(MODULE_NAME, "Verbose log");

  Serial.println();
  delay(1000);
}