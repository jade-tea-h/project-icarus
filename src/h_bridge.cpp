#include <Arduino.h>
#include <math.h>

#include "h_bridge.h"

void HBridgeMotor::setup() {
  pinMode(this->pin_forward, OUTPUT);
  pinMode(this->pin_backward, OUTPUT);
  pinMode(this->pin_pwm, OUTPUT);
}

const HBridgeMotor::Direction HBridgeMotor::get_direction() {
  if (this->current_velocity > 0) {
    return FORWARD;
  } else if (this->current_velocity < 0) {
    return BACKWARD;
  } else {
    return STOPPED;
  }
}

void HBridgeMotor::set_velocity(int16_t velocity) {
  this->set_speed(uint8_t(abs(velocity)));

  if (velocity > 0) {
    this->set_direction(FORWARD);
  } else if (velocity < 0) {
    this->set_direction(BACKWARD);
  } else {
    this->stop();
  }
}

void HBridgeMotor::set_velocity(Direction direction, uint8_t duty_cycle) {
  this->set_direction(direction);

  analogWrite(this->pin_pwm, duty_cycle);

  this->current_velocity = duty_cycle * direction;
}

void HBridgeMotor::set_direction(Direction direction) {
  switch (direction) {
  case FORWARD:
    digitalWrite(this->pin_forward, HIGH);
    digitalWrite(this->pin_backward, LOW);
    break;
  case BACKWARD:
    digitalWrite(this->pin_backward, HIGH);
    digitalWrite(this->pin_forward, LOW);
    break;
  case STOPPED:
    digitalWrite(this->pin_backward, LOW);
    digitalWrite(this->pin_forward, LOW);
    break;
  }

  this->current_velocity = abs(this->current_velocity) * direction;
}

void HBridgeMotor::set_speed(uint8_t duty_cycle) {
  analogWrite(this->pin_pwm, duty_cycle);

  if (this->current_velocity == 0) {
    this->current_velocity = duty_cycle;
    this->set_direction(FORWARD);
  } else {
    this->current_velocity =
        (this->current_velocity / abs(this->current_velocity)) * duty_cycle;
  }
}

void HBridgeMotor::stop() {
  digitalWrite(this->pin_forward, LOW);
  digitalWrite(this->pin_backward, LOW);

  analogWrite(this->pin_pwm, 0);

  this->current_velocity = 0;
}

void HBridgeMotor::flip_direction() {
  uint8_t temp = this->pin_forward;
  this->pin_forward = this->pin_backward;
  this->pin_backward = temp;
}
