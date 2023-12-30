#pragma once
#include <Arduino.h>
#include "state.cpp"

class Controller {
public:
    Controller() {};
    ~Controller() {};


    private:
        void deserializeControllerState(const uint8_t* buffer, ControllerState& state);
};