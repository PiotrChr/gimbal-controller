#pragma once

#include <Arduino.h>
#include "SDManager.hpp"
#include "../motion/MotionController.hpp"
#include "../display/DisplayManager.hpp"
#include "../config.hpp"

class SDProgramManager {
public:
    SDProgramManager(SDManager& sdManager, MotionController& motionController, DisplayManager& displayManager);

    // Initiates the reading and execution of the movement program
    void executeProgram();

private:
    SDManager& sdManager;
    MotionController& motionController;
    DisplayManager& displayManager;

    // Parses a single line of the program and executes the corresponding command
    void parseAndExecuteCommand(const String& commandLine);

    // Movement command handlers
    void handleMovementCommand(const String& command);
    void handleDelayCommand(const String& command);
    void handleStartCommand();
    void handleEndCommand();
    void handleRestartCommand();

    // Utility methods for parsing command components
    float parseCoordinate(const String& coordinatePart);
    float parseSpeed(const String& speedPart);

    // Status flags
    bool isProgramRunning = false;
};
