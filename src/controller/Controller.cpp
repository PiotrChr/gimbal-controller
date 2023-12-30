#include "Controller.hpp"

void Controller::deserializeControllerState(const uint8_t* buffer, ControllerState& state) {
    uint8_t buffer[sizeof(ControllerState)];

    memcpy(&state, buffer, sizeof(ControllerState));
}