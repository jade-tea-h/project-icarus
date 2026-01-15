#include <Arduino.h>
#include <math.h>

class HBridgeMotor {
public:
  enum Direction {
    FORWARD = 1,
    BACKWARD = -1,
    STOPPED = 0,
  };

  HBridgeMotor(uint8_t forward_pin, uint8_t backward_pin, uint8_t pwm_pin) : pin_forward(forward_pin), pin_backward(backward_pin), pin_pwm(pwm_pin),
      current_velocity(0) {}

  void setup();

  const int16_t get_velocity() { return current_velocity; }
  const float get_velocity_percentage() { return current_velocity / 255.0; }
  const uint8_t get_speed() { return abs(current_velocity); }
  const float get_speed_percentage() { return abs(current_velocity) / 255.0; }
  const Direction get_direction();

  void set_velocity(Direction direction, uint8_t duty_cycle);
  void set_velocity(int16_t velocity);
  void set_direction(Direction direction);
  void set_speed(uint8_t duty_cycle);
  void set_speed(float percentage);
  void reverse();
  void stop();

  void flip_direction();

private:
  uint8_t pin_forward;
  uint8_t pin_backward;
  uint8_t pin_pwm;

  int16_t current_velocity;
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
