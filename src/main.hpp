#include "config.hpp"
#include "display/DisplayManager.hpp"
#include "eeprom/EEpromManager.hpp"
#include "motion/MotionController.hpp"
#include "task/TaskManager.hpp"

// Define pins for the stepper motor
#define STEPPER_EN_PIN 13
#define STEPPER_SLP_PIN 26

#define STEP_PIN 12
#define DIR_PIN 14

// Define pins for DRV8825 modules
#define DRV8825_DIR_PIN_1 4
#define DRV8825_DIR_PIN_2 17
#define DRV8825_STP_PIN_1 16
#define DRV8825_STP_PIN_2 18
#define DRV8825_EN_PIN 27

// Define pins for the OLED screen
#define OLED_SDA_PIN 21
#define OLED_SCL_PIN 22

// Define pins for buttons
#define BUTTON_PIN_1 32
#define BUTTON_PIN_2 33

// Define motor parameters
#define MOTOR_SPEED 500.0 
#define MOTOR_ACCEL 5000.0 

#define GEAR_RATIO 6.0
constexpr float stepsPerDegree = (200 / 360.0) * GEAR_RATIO;
