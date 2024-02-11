#pragma once

#include <Arduino.h>
#include "FS.h"
#include "SD.h"
#include <SPI.h>
#include "../config.hpp"

class SDManager {
private:
    const uint8_t cardReaderPin;
    bool isSDInitialized;
    SPIClass *spi;
    bool readFile(fs::FS &fs, const char *path, String &contents);
public:
    SDManager(int cardReaderPin);
    ~SDManager();

    void initializeSD();

    bool readFileContents(const char* path, String &contents);
    
    bool fileExists(const char* path);

    template<typename Callback>
    void readFileLineByLine(const char* path, Callback callback) {
        if (!isSDInitialized) {
            initializeSD();
        }

        File file = SD.open(path);
        if (!file) {
            Serial.println("Failed to open file for reading");
            return;
        }

        while (file.available()) {
            String line = file.readStringUntil('\n');
            line.trim(); // Remove any trailing newline characters
            callback(line); // Call the callback function with the line as argument
        }

        file.close();
    }
};