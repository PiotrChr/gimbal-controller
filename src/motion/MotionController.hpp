#include "stepper/StepperController.hpp"

class MotionController {
public:
    MotionController(StepperController& xController, StepperController& yController, float stepsPerDegree)
        : xController(xController), yController(yController), stepsPerDegree(stepsPerDegree) {}

    void begin();

    void moveToAngle(float angleX, float angleY);

    void sleep();
    void wakeUp();

    void testMotion();

private:
    StepperController& xController;
    StepperController& yController;
    float stepsPerDegree;

    int determineDirection(float angle);
};