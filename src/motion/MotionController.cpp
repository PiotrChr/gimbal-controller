#include "MotionController.hpp"

void MotionController::begin() {
    xController.begin();
    yController.begin();
}

void MotionController::moveToAngle(float angleX, float angleY) {
    // Start moving both motors without waiting for them to complete
    xController.startMovingToAngle(angleX, stepsPerDegree);
    yController.startMovingToAngle(angleY, stepsPerDegree);

    // Wait for both motors to complete their motion
    while (!xController.isMotionComplete() || !yController.isMotionComplete()) {
        xController.processMovement();
        yController.processMovement();
    }
}

void MotionController::sleep() {
    xController.sleep();
    yController.sleep();
}

void MotionController::wakeUp() {
    xController.wakeUp();
    yController.wakeUp();
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
