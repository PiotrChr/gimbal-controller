#include "stepper/StepperController.hpp"
#include "../display/DisplayManager.hpp"
#include "../config.hpp"

class MotionController {
public:
    MotionController(StepperController& xController, StepperController& yController, DisplayManager& displayManager )
        : xController(xController), yController(yController), displayManager(displayManager) {}

    void begin();

    void moveToAngle(float angleX, float angleY);

    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();

    void setStepsPerDegree(float stepsPerDegree);

    void stopImmediately();
    void sleep();
    void wakeUp();

    void increaseMotorSpeed();
    void decreaseMotorSpeed();

    void processMovement();
    void sleepIfIdle();
    void testMotion();

private:
    StepperController& xController;
    StepperController& yController;

    int determineDirection(float angle);
    DisplayManager& displayManager;

    long lastMovementTime = 0;
    long sleepTime = 10000;
    bool idle = true;
    bool sleeping = false;
};