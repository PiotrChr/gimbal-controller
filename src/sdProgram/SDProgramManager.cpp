#include "SDProgramManager.hpp"

SDProgramManager::SDProgramManager(SDManager& sdManager, MotionController& motionController, DisplayManager& displayManager)
    : sdManager(sdManager), motionController(motionController), displayManager(displayManager) {}

void SDProgramManager::executeProgram() {
    if (!sdManager.fileExists(PROGRAM_FILE_PATH)) {
        LOG_PRINTLN("Program file not found");
        displayManager.displayStatus("Program file not found");
        delay(2000);
        return;
    }

    sdManager.readFileLineByLine(PROGRAM_FILE_PATH, [this](const String& line) {
        if (line.length() > 0) { // Ignore empty lines
            parseAndExecuteCommand(line);
        }
    });
}

void SDProgramManager::parseAndExecuteCommand(const String& commandLine) {
    LOG_PRINTLN(commandLine);
    displayManager.displayStatus(commandLine.c_str());
    delay(5);

    if (commandLine.startsWith(PROG_START)) {
        handleStartCommand();
    } else if (commandLine.startsWith(PROG_END)) {
        handleEndCommand();
    } else if (commandLine.startsWith(PROG_RESTART)) {
        handleRestartCommand();
    } else if (commandLine.startsWith(PROG_DELAY)) {
        handleDelayCommand(commandLine);
    } else if (commandLine.startsWith(PROG_MOVE_ANGLE)) {
        handleMovementCommand(commandLine);
    }
}

void SDProgramManager::handleMovementCommand(const String& command) {
    char type = command.charAt(0);
    char mode = command.charAt(2);
    int xIndex = command.indexOf(PROG_MOVE_X);
    int yIndex = command.indexOf(PROG_MOVE_Y);
    int sIndex = command.indexOf(PROG_MOVE_SPEED);

    float x = parseCoordinate(command.substring(xIndex + 1, yIndex));
    float y = parseCoordinate(command.substring(yIndex + 1, sIndex));
    float speed = parseSpeed(command.substring(sIndex + 1));

    if (mode == PROG_MOVE_ABSOLUTE) {
        motionController.moveToAngle(x, y); // Add speed handling
    } else if (mode == PROG_MOVE_RELATIVE) {
        // TODO
    }
}

void SDProgramManager::handleDelayCommand(const String& command) {
    int delayTime = command.substring(2).toInt();
    delay(delayTime);
}

void SDProgramManager::handleStartCommand() {
    isProgramRunning = true;
}

void SDProgramManager::handleEndCommand() {
    isProgramRunning = false;
}

void SDProgramManager::handleRestartCommand() {
    executeProgram();
}

float SDProgramManager::parseCoordinate(const String& coordinatePart) {
    return coordinatePart.toFloat();
}

float SDProgramManager::parseSpeed(const String& speedPart) {
    return speedPart.toFloat();
}
