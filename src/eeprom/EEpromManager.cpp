#include "EEPROMManager.hpp"

EEPROMManager::EEPROMManager(int eepromSize)
    : EEPROM_SIZE(eepromSize)
{
}

void EEPROMManager::begin()
{
    LOG_PRINTLN("Initializing EEPROM with size: ");
    LOG_PRINTLN(EEPROM_SIZE);

    EEPROM.begin(EEPROM_SIZE);
}

void EEPROMManager::writeString(int addrOffset, const char *strToWrite)
{
    byte len = strlen(strToWrite);
    EEPROM.write(addrOffset, len);
    for (int i = 0; i < len; i++)
    {
        EEPROM.write(addrOffset + 1 + i, strToWrite[i]);
    }

    EEPROM.commit();
}

void EEPROMManager::readString(int addrOffset, char *output, size_t maxLen)
{
    int newStrLen = EEPROM.read(addrOffset);
    newStrLen = newStrLen < maxLen ? newStrLen : maxLen - 1; // prevent buffer overflow

    if (newStrLen <= 0)
    {
        output[0] = '\0';
        return;
    }

    for (int i = 0; i < newStrLen; i++)
    {
        output[i] = EEPROM.read(addrOffset + 1 + i);
    }
    output[newStrLen] = '\0';
}
