#pragma once

#include "../config.hpp"
#include <EEPROM.h>


class EEPROMManager
{
public:
    EEPROMManager(int eepromSize);

    void begin();
    void writeString(int addrOffset, const char *strToWrite);
    void readString(int addrOffset, char *output, size_t maxLen);

private:
    const int EEPROM_SIZE;
};