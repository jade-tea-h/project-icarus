#include <Arduino.h>

#include "h_bridge.h"

HBridgeMotor::HBridgeMotor(uint8_t forward_pin, uint8_t backward_pin,
                           uint8_t pwm_pin)
    : pin_forward(forward_pin), pin_backward(backward_pin), pin_pwm(pwm_pin),
      current_speed(0), current_direction(FORWARD) {
  pinMode(pin_forward, OUTPUT);
  pinMode(pin_backward, OUTPUT);
  pinMode(pin_pwm, OUTPUT);
}
