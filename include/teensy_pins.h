class TeensyPins {
  public:
    static const unsigned int HBRIDGE_ENA = 4;
    static const unsigned int HBRIDGE_IN1 = 3;
    static const unsigned int HBRIDGE_IN2 = 2;
    static const unsigned int HBRIDGE_IN3 = 9;
    static const unsigned int HBRIDGE_IN4 = 10;
    static const unsigned int HBRIDGE_ENB = 11;

    // Forward and backward will depend on wiring
    static const unsigned int MOTOR_RIGHT_FORWARD = HBRIDGE_IN1;
    static const unsigned int MOTOR_RIGHT_BACKWARD = HBRIDGE_IN2;
    static const unsigned int MOTOR_RIGHT_PWM = HBRIDGE_ENA;

    static const unsigned int MOTOR_LEFT_FORWARD = HBRIDGE_IN4;
    static const unsigned int MOTOR_LEFT_BACKWARD = HBRIDGE_IN3;
    static const unsigned int MOTOR_LEFT_PWM = HBRIDGE_ENB;

    static const unsigned int ULTRASONIC_CENTER_TRIGGER = 14;
    static const unsigned int ULTRASONIC_CENTER_ECHO = 13;
    static const unsigned int ULTRASONIC_LEFT_TRIGGER = 0;
    static const unsigned int ULTRASONIC_LEFT_ECHO = 0;
    static const unsigned int ULTRASONIC_RIGHT_TRIGGER = 0;
    static const unsigned int ULTRASONIC_RIGHT_ECHO = 0;
};
