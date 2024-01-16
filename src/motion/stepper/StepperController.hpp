#include "ESP_FlexyStepper.h"
#include <Arduino.h>
#include "../../config.hpp"

class StepperController {
public:
    StepperController(int stepPin, int dirPin, int sleepPin, int enablePin, float motorSpeed, float motorAcceleration, float stepsPerDegree)
        : stepPin(stepPin), dirPin(dirPin), sleepPin(sleepPin), enablePin(enablePin), motorSpeed(motorSpeed), motorAcceleration(motorAcceleration), stepsPerDegree(stepsPerDegree) {}

    void begin();
    void startMovingToAngle(float angle);
    void step(int dir, int steps);

    bool isMotionComplete();
    void processMovement();

    float getCurrentAngle();
    bool reachedTarget();

    void setStepsPerDegree(float stepsPerDegree);

    void increaseMotorSpeed();
    void decreaseMotorSpeed();

    void stopImmediately();

    void enable();
    void disable();
    void sleep();
    void wakeUp();

private:
    int stepPin, dirPin, sleepPin, enablePin;
    ESP_FlexyStepper stepper;
    float motorSpeed, motorAcceleration;
    float targetAngle;
    float currentAngle;
    bool isMoving = false;
    float stepsPerDegree;
    float currentSpeed;
};
