#include <Arduino.h>

#include "teensy_pins.h"
#include "h_bridge.h"

HBridgeMotor motor(TeensyPins::HBRIDGE_IN1, TeensyPins::HBRIDGE_IN2, TeensyPins::HBRIDGE_ENA);

void setup() {
    Serial.begin(9600);
    motor.setup();
}

void loop() {
    Serial.println("FORWARD");
    motor.set_velocity(255);
    delay(2000);

    Serial.println("LOW-SPEED");
    motor.set_velocity(200);
    delay(2000);

    Serial.println("OFF");
    motor.stop();
    delay(2000);

    Serial.println("BACKWARD");
    motor.set_velocity(-255);
    delay(2000);

    Serial.println("LOW-SPEED");
    motor.set_velocity(-200);
    delay(2000);

    Serial.println("OFF");
    motor.stop();
    delay(2000);
}
