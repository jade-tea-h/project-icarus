#include <Arduino.h>

class HBridgeMotor {
public:
  enum Direction {
    FORWARD = 1,
    BACKWARD = -1,
  };

  HBridgeMotor(uint8_t pin_forward, uint8_t pin_backward, uint8_t pin_pwm);

private:
  uint8_t pin_forward;
  uint8_t pin_backward;
  uint8_t pin_pwm;

  Direction current_direction;
  uint8_t current_speed;
};

class HBridge {
public:
  HBridge(uint8_t ena, uint8_t in1, uint8_t in2,
          uint8_t in3, uint8_t in4, uint8_t enb)
      : motor_right(in1, in2, ena), motor_left(in3, in4, enb) {}

  HBridge(HBridgeMotor right, HBridgeMotor left) : motor_right(right), motor_left(left) {}
private:
  HBridgeMotor motor_right;
  HBridgeMotor motor_left;
};
