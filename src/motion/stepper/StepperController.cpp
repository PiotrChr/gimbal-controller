#include "StepperController.hpp"

void StepperController::begin() {
    stepper.connectToPins(stepPin, dirPin);
    pinMode(sleepPin, OUTPUT);
    pinMode(enablePin, OUTPUT);
    digitalWrite(sleepPin, HIGH); // Wake up the stepper driver
    digitalWrite(enablePin, LOW); // Enable the stepper driver

    stepper.setSpeedInStepsPerSecond(motorSpeed); // Adjust speed
    stepper.setAccelerationInStepsPerSecondPerSecond(motorAcceleration); // Adjust acceleration
    stepper.setDecelerationInStepsPerSecondPerSecond(motorAcceleration);

    stepper.setCurrentPositionAsHomeAndStop();
}

void StepperController::startMovingToAngle(float angle, float stepsPerDegree) {
    int steps = static_cast<int>(angle * stepsPerDegree);
    stepper.setTargetPositionInSteps(stepper.getCurrentPositionInSteps() + steps);
}

bool StepperController::isMotionComplete() {
    return stepper.motionComplete();
}

void StepperController::processMovement() {
    stepper.processMovement();
}

void StepperController::enable() {
    digitalWrite(enablePin, LOW); // Enable the stepper driver
}

void StepperController::disable() {
    digitalWrite(enablePin, HIGH); // Disable the stepper driver
}

void StepperController::wakeUp() {
    digitalWrite(sleepPin, HIGH); // Wake up the stepper driver
}

void StepperController::sleep() {
    digitalWrite(sleepPin, LOW); // Put the stepper driver in sleep mode
}
