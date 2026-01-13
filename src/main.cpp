#include <Arduino.h>

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    Serial.println("ON");
    digitalWrite(LED_BUILTIN, HIGH);
    delay(500);

    Serial.println("OFF");
    digitalWrite(LED_BUILTIN, LOW);
    delay(500);
}
