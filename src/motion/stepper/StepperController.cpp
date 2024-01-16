#include "StepperController.hpp"

void StepperController::begin() {
    stepper.connectToPins(stepPin, dirPin);
    pinMode(sleepPin, OUTPUT);
    pinMode(enablePin, OUTPUT);
    digitalWrite(sleepPin, HIGH); // Wake up the stepper driver
    digitalWrite(enablePin, LOW); // Enable the stepper driver
    
    currentSpeed = motorSpeed;
    stepper.setSpeedInStepsPerSecond(motorSpeed); // Adjust speed
    stepper.setAccelerationInStepsPerSecondPerSecond(motorAcceleration); // Adjust acceleration
    stepper.setDecelerationInStepsPerSecondPerSecond(motorAcceleration);

    stepper.setCurrentPositionAsHomeAndStop();
}

void StepperController::setStepsPerDegree(float stepsPerDegree) {
    this->stepsPerDegree = stepsPerDegree;
}

void StepperController::startMovingToAngle(float angle) {
    int steps = static_cast<int>(angle * this->stepsPerDegree);
    stepper.setTargetPositionInSteps(stepper.getCurrentPositionInSteps() + steps);
}

void StepperController::step(int dir, int steps) {
    float targetPos = (stepper.getTargetPositionInSteps() != 0
        ? stepper.getTargetPositionInSteps()
        : stepper.getCurrentPositionInSteps()) + (dir * steps);
    stepper.setTargetPositionInSteps(targetPos);
}

float StepperController::getCurrentAngle() {
    return stepper.getCurrentPositionInSteps() / this->stepsPerDegree;
}

bool StepperController::reachedTarget() {
    return stepper.getTargetPositionInSteps() == stepper.getCurrentPositionInSteps();
}

bool StepperController::isMotionComplete() {
    return stepper.motionComplete();
}

void StepperController::processMovement() {
    currentAngle = stepper.getCurrentPositionInSteps();
    stepper.processMovement();
}

void StepperController::enable() {
    digitalWrite(enablePin, LOW); // Enable the stepper driver
}

void StepperController::stopImmediately() {
    stepper.setTargetPositionToStop();
    // stepper.setTargetPositionInSteps(stepper.getCurrentPositionInSteps());
}

void StepperController::increaseMotorSpeed() {
    float newSpeed = currentSpeed + 100.0 > MAX_SPEED
        ? MAX_SPEED
        : currentSpeed + 100.0;
    stepper.setSpeedInStepsPerSecond(newSpeed);
    currentSpeed = newSpeed;
}

void StepperController::decreaseMotorSpeed() {
    float newSpeed = currentSpeed - 100.0 < MIN_SPEED
        ? MIN_SPEED
        : currentSpeed - 100.0;
    stepper.setSpeedInStepsPerSecond(newSpeed);
    currentSpeed = newSpeed;
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
