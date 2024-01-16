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

// Communication
#define COM_CHANNEL 6
#define MSG_UP "u"
#define MSG_DOWN "d"
#define MSG_LEFT "l"
#define MSG_RIGHT "r"
#define MSG_BTN1 "b1"
#define MSG_BTN2 "b2"
#define MSG_STOP "s"


#define STEPS_PER_STEP_ACTION 200

#define MAX_SPEED 1500.0
#define MIN_SPEED 50.0
