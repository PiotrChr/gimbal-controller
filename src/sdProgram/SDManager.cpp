#include "SDManager.hpp"

SDManager::SDManager(int cardReaderPin) : isSDInitialized(false), cardReaderPin(cardReaderPin), spi(new SPIClass(HSPI)) {
    initializeSD();
}

SDManager::~SDManager() {
    delete spi;
}

void SDManager::initializeSD() {
    if (isSDInitialized) return;

    spi->begin(14, 12, 13, cardReaderPin);

    if (!SD.begin(cardReaderPin, *spi)) {
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

