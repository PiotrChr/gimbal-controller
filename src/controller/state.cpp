#include <Arduino.h>

struct ControllerState {
    int16_t joystickX;
    int16_t joystickY;
    uint8_t buttons;
};