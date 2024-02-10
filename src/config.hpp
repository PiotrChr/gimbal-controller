#pragma once

#define LOG 0

#include <Arduino.h>
#if LOG == 1
  #define LOG_PRINT(x) Serial.print(x)
  #define LOG_PRINTLN(x) Serial.println(x)
#else
  #define LOG_PRINT(x) 
  #define LOG_PRINTLN(x) 
#endif

// Motor parameters
#define MOTOR_SPEED 600.0 
#define MOTOR_ACCEL 2000.0 

#define GEAR_RATIO 6.0
#define MICROSTEPS 16.0
constexpr float stepsPerDegree = (200 / 360.0) * GEAR_RATIO * MICROSTEPS;


// Communication
#define COM_CHANNEL 6
#define MSG_UP "u"
#define MSG_DOWN "d"
#define MSG_LEFT "l"
#define MSG_RIGHT "r"
#define MSG_BTN1 "b1"
#define MSG_BTN2 "b2"
#define MSG_STOP "s"


// Movement Program commands
#define PROG_START "START"
#define PROG_END "END"
#define PROG_MOVE_ANGLE "A"
#define PROG_MOVE_RELATIVE 'R'
#define PROG_MOVE_ABSOLUTE 'A'
#define PROG_MOVE_SPEED 'S'
#define PROG_MOVE_X 'X'
#define PROG_MOVE_Y 'Y'
#define PROG_DELAY "DELAY"
#define PROG_RESTART "RESTART"


#define PROGRAM_FILE_PATH "/program.txt"

#define STEPS_PER_STEP_ACTION 200

#define MAX_SPEED 1500.0
#define MIN_SPEED 50.0
