#include "SDManager.hpp"

SDManager::SDManager() : isSDInitialized(false) {
    initializeSD();
}

void SDManager::initializeSD() {
    if (!SD.begin(SD_CARD_READER_PIN)) {
        LOG_PRINTLN("Card Mount Failed");
        isSDInitialized = false;
        return;
    }
    uint8_t cardType = SD.cardType();

    if (cardType == CARD_NONE) {
        LOG_PRINTLN("No SD card attached");
        isSDInitialized = false;
        return;
    }
    isSDInitialized = true;
}

bool SDManager::readFileContents(const char *path, String &contents) {
    if (!isSDInitialized) {
        return false;
    }
    
    return readFile(SD, path, contents);
}

bool SDManager::readFile(fs::FS &fs, const char *path, String &contents) {
    File file = fs.open(path);
    if (!file || file.isDirectory()) {
        return false;
    }

    // Read contents from the file
    contents = file.readString();
    file.close();
    return true;
}

bool SDManager::fileExists(const char *path) {
    if (!isSDInitialized) {
        return false;
    }
    return SD.exists(path);
}

template<typename Callback>
void SDManager::readFileLineByLine(const char* path, Callback callback) {
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
