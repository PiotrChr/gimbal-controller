#include "ESP_FlexyStepper.h"
#include <Arduino.h>

class StepperController {
public:
    StepperController(int stepPin, int dirPin, int sleepPin, int enablePin, float motorSpeed, float motorAcceleration)
        : stepPin(stepPin), dirPin(dirPin), sleepPin(sleepPin), enablePin(enablePin), motorSpeed(motorSpeed), motorAcceleration(motorAcceleration) {}

    void begin();
    void moveToAngle(float angle, float stepsPerDegree);
    void startMovingToAngle(float angle, float stepsPerDegree);

    bool isMotionComplete();
    void processMovement();

    void enable();
    void disable();
    void sleep();
    void wakeUp();

private:
    int stepPin, dirPin, sleepPin, enablePin;
    ESP_FlexyStepper stepper;
    float motorSpeed, motorAcceleration;
};
