#include "main.hpp"

DisplayManager displayManager;

ComManager comManager("ESP32", displayManager);
ComManager* ComManager::instance = nullptr;

StepperController stepperX(
  DRV8825_STP_PIN_1,
  DRV8825_DIR_PIN_1,
  STEPPER_SLP_PIN,
  DRV8825_EN_PIN,
  MOTOR_SPEED,
  MOTOR_ACCEL,
  stepsPerDegree
);
StepperController stepperY(
  DRV8825_STP_PIN_2,
  DRV8825_DIR_PIN_2,
  STEPPER_SLP_PIN,
  DRV8825_EN_PIN,
  MOTOR_SPEED,
  MOTOR_ACCEL,
  stepsPerDegree
);
MotionController motionController(stepperX, stepperY, displayManager);

SDManager sdManager;
SDProgramManager sdProgramManager(sdManager, motionController, displayManager);

bool microstepToggleState = HIGH;

void checkMicroStepToggle();
void setupButtons();

void setup() {
  #if LOG == 1
  Serial.begin(9600);
  while (!Serial);
  #endif

  // Initialize Display Manager
  displayManager.setup();
  delay(500);

  setupButtons();

  // Initialize Communication Manager
  comManager.setup();
  comManager.bindAction(MSG_UP, [&]() { motionController.moveUp(); });
  comManager.bindAction(MSG_DOWN, [&]() { motionController.moveDown(); });
  comManager.bindAction(MSG_LEFT, [&]() { motionController.moveLeft(); });
  comManager.bindAction(MSG_RIGHT, [&]() { motionController.moveRight(); });
  comManager.bindAction(MSG_STOP, [&]() { motionController.stopImmediately(); });
  comManager.bindAction(MSG_BTN1, [&]() { motionController.increaseMotorSpeed(); });
  comManager.bindAction(MSG_BTN2, [&]() { motionController.decreaseMotorSpeed(); });
  
  // Initialize motion controller
  displayManager.displayStatus("Initializing motion controller");
  LOG_PRINTLN("Initializing motion controller");
  motionController.begin();
  delay(500);
  displayManager.displayStatus("Motion controller initialized");
  LOG_PRINTLN("Motion controller initialized");

  checkMicroStepToggle();

  motionController.testMotion();
}

void checkMicroStepToggle() {
  int state = digitalRead(MICROSTEP_TOGGLE_BTN);
  if (state != microstepToggleState) {
    microstepToggleState = state;
    if (state == LOW) {
      motionController.setStepsPerDegree(stepsPerDegree / 16);
    } else {
      motionController.setStepsPerDegree(stepsPerDegree);
    }
  }
}

void setupButtons() {
  pinMode(BUTTON_PIN_1, INPUT_PULLUP);
  pinMode(BUTTON_PIN_2, INPUT_PULLUP);
  pinMode(MICROSTEP_TOGGLE_BTN, INPUT_PULLUP);
}

void loop() {
  checkMicroStepToggle();
  motionController.processMovement();
  motionController.sleepIfIdle();
}
