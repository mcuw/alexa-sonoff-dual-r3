#include "Arduino.h"
#include "pinout.h"

void setup() {
    pinMode(LED, OUTPUT);
    digitalWrite(LED, HIGH); // off
}

void loop() {
    digitalWrite(LED, LOW); // on
    delay(200);
    digitalWrite(LED, HIGH); // off
    delay(200);
}