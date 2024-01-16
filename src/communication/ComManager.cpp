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
    ComManager(String name, DisplayManager& displayManager)
        : name(name), displayManager(displayManager) {
            instance = this;
        }

    void setup() {
        WiFi.disconnect(true);
        WiFi.mode(WIFI_STA);
        // WiFi.channel(10);

        delay(1000);
        LOG_PRINTLN("Connecting to WiFi");
        LOG_PRINTLN(WiFi.channel());
        LOG_PRINTLN(WiFi.macAddress().c_str());
        
        if (esp_now_init() != ESP_OK) {
            displayManager.displayStatus("Error initializing ESP-NOW");
            return;
        }

        displayManager.displayStatus("ESP-NOW initialized");
        delay(500);
        displayManager.displayStatus(WiFi.macAddress().c_str());
        delay(2000);

        esp_now_register_recv_cb(onDataReceive);
    }

    void bindAction(String command, ActionFunction func) {
        actions[command] = func;
    }

private:
    String name;
    DisplayManager& displayManager;
    static ComManager* instance;
    std::map<String, ActionFunction> actions;
    
    static void onDataReceive(const uint8_t * mac, const uint8_t *incomingData, int len) {
        char data[len + 1];
        memcpy(data, incomingData, len);
        data[len] = '\0';

        if (instance == nullptr) {
            LOG_PRINTLN("ComManager instance is null");
            return;
        }
        instance->handleReceivedMessage(String(data));
    }

    void handleReceivedMessage(String message) {
        auto it = actions.find(message);
        if (it != actions.end()) {
            displayManager.displayStatus(message.c_str());
            it->second();
        } else {
            displayManager.displayStatus("Unknown command");
        }
    }

    void attemptReconnect() {
        // TODO 
    }
};
