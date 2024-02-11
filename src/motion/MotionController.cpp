#include "MotionController.hpp"

void MotionController::begin() {
    xController.begin();
    yController.begin();
}

void MotionController::moveToAngle(float angleX, float angleY) {
    // Start moving both motors without waiting for them to complete
    xController.startMovingToAngle(angleX);
    yController.startMovingToAngle(angleY);

    // Wait for both motors to complete their motion
    while (!xController.isMotionComplete() || !yController.isMotionComplete()) {
        xController.processMovement();
        yController.processMovement();
    }
}

int MotionController::getSpeed() {
    return int(xController.getMotorSpeed());
}

void MotionController::setSpeed(int speed) {    
    xController.setMotorSpeed(float(speed));
    yController.setMotorSpeed(float(speed));
}

void MotionController::moveUp() {
    wakeUp();
    displayManager.displayStatus("Moving up");
    yController.step(1, STEPS_PER_STEP_ACTION);
}

void MotionController::moveDown() {
    wakeUp();
    displayManager.displayStatus("Moving down");
    yController.step(-1, STEPS_PER_STEP_ACTION);
}

void MotionController::moveLeft() {
    wakeUp();
    displayManager.displayStatus("Moving left");
    xController.step(-1, STEPS_PER_STEP_ACTION);
}

void MotionController::moveRight() {
    wakeUp();
    displayManager.displayStatus("Moving right");
    xController.step(1, STEPS_PER_STEP_ACTION);
}

void MotionController::stopImmediately() {
    xController.stopImmediately();
    yController.stopImmediately();
}

void MotionController::sleep() {
    xController.sleep();
    yController.sleep();
}

void MotionController::wakeUp() {
    xController.wakeUp();
    yController.wakeUp();
}

void MotionController::setStepsPerDegree(float stepsPerDegree) {
    xController.setStepsPerDegree(stepsPerDegree);
    yController.setStepsPerDegree(stepsPerDegree);
}

void MotionController::increaseMotorSpeed() {
    displayManager.displayStatus("Increasing motor speed");
    xController.increaseMotorSpeed();
    yController.increaseMotorSpeed();
}

void MotionController::decreaseMotorSpeed() {
    displayManager.displayStatus("Decreasing motor speed");
    xController.decreaseMotorSpeed();
    yController.decreaseMotorSpeed();
}

void MotionController::processMovement() {
    if (xController.reachedTarget() && yController.reachedTarget()) {
        idle = true;
    } else {
        if (!xController.isMotionComplete())
            xController.processMovement();

        if (!yController.isMotionComplete())
            yController.processMovement();
        
        lastMovementTime = millis();
        idle = false;
    }
}

void MotionController::sleepIfIdle() {
    if (idle) {
        if (millis() - lastMovementTime > sleepTime) {
            sleep();
        }
    }
}

void MotionController::testMotion() {
    wakeUp();
    delay(2000);

    Serial.println("Testing motion 90 90");
    moveToAngle(90, 90);
    delay(1000);
    Serial.println("Testing motion 0 0");
    moveToAngle(0, 0);
    delay(1000);
    Serial.println("Testing motion -90 -90");
    moveToAngle(-90, -90);
    delay(1000);
    Serial.println("Testing motion 0 0");
    moveToAngle(0, 0);
    delay(1000);

    sleep();
    delay(2000);
}

int MotionController:: determineDirection(float angle) {
    return angle >= 0 ? HIGH : LOW;
}
