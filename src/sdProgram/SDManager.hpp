#pragma once

#include <Arduino.h>
#include "FS.h"
#include "SD.h"
#include "../config.hpp"

class SDManager {
private:
    const uint8_t SD_CARD_READER_PIN = 5;
    bool isSDInitialized;
    
    void initializeSD();
    bool readFile(fs::FS &fs, const char *path, String &contents);
public:
    SDManager();

    bool readFileContents(const char* path, String &contents);

    template<typename Callback>
    void readFileLineByLine(const char* path, Callback callback);

    bool fileExists(const char* path);
};