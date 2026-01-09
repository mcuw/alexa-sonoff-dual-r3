#include "Arduino.h"

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, HIGH); // off
}

void loop() {
    digitalWrite(LED_BUILTIN, LOW); // on
    delay(200);
    digitalWrite(LED_BUILTIN, HIGH); // off
    delay(200);
}