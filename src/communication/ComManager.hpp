#pragma once

#include "Arduino.h"
#include <map>
#include <esp_now.h>
#include <WiFi.h>
#include "../config.hpp"
#include "../display/DisplayManager.hpp"

typedef std::function<void()> ActionFunction;

class ComManager {
public:
    ComManager(String name, DisplayManager& displayManager);

    void setup();

    void bindAction(String command, ActionFunction func);

private:
    String name;
    DisplayManager& displayManager;
    static ComManager* instance;
    std::map<String, ActionFunction> actions;
    
    static void onDataReceive(const uint8_t * mac, const uint8_t *incomingData, int len);

    void handleReceivedMessage(String message);

    void attemptReconnect();
};
