#include "main.hpp"


StepperController stepperX(
  DRV8825_STP_PIN_1,
  DRV8825_DIR_PIN_1,
  STEPPER_SLP_PIN,
  DRV8825_EN_PIN,
  MOTOR_SPEED,
  MOTOR_ACCEL
);
StepperController stepperY(
  DRV8825_STP_PIN_2,
  DRV8825_DIR_PIN_2,
  STEPPER_SLP_PIN,
  DRV8825_EN_PIN,
  MOTOR_SPEED,
  MOTOR_ACCEL
);
MotionController motionController(stepperX, stepperY, stepsPerDegree);


void setup() {
  Serial.begin(9600);
  delay(1000);

  Serial.println("Initializing motion controller");
  motionController.begin();
  Serial.println("Motion controller initialized");
}

void loop() {
  
}
