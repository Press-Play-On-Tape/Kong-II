#include "EEPROM_Utils.h"
#include "Arduboy2Ext.h"
#include "Enums.h"

#include <avr/eeprom.h>

/* ----------------------------------------------------------------------------
 *   Is the EEPROM initialised?
 *
 *   Looks for the characters 'D' and 'K' in the first two bytes of the EEPROM
 *   memory range starting from byte EEPROM_STORAGE_SPACE_START.  If not found,
 *   it resets the settings ..
 */

constexpr uint8_t letter1 = 'D';
constexpr uint8_t letter2 = 'K';

namespace EEPROM_Utils {

    void initialiseEEPROM() {

        uint8_t * const eepromStartChar1 = reinterpret_cast<uint8_t *>(eepromStart_C1);
        uint8_t * const eepromStartChar2 = reinterpret_cast<uint8_t *>(eepromStart_C2);

        const byte c1 = eeprom_read_byte(eepromStartChar1);
        const byte c2 = eeprom_read_byte(eepromStartChar2);

        if ((c1 != letter1) || (c2 != letter2)) {

            clearEEPROM();

        }

    }

    void clearEEPROM() {

        uint8_t * const eepromStartChar1 = reinterpret_cast<uint8_t *>(eepromStart_C1);
        uint8_t * const eepromStartChar2 = reinterpret_cast<uint8_t *>(eepromStart_C2);

        uint16_t * const eepromEasyLoc = reinterpret_cast<uint16_t *>(eepromEasy);
        uint16_t * const eepromHardLoc = reinterpret_cast<uint16_t *>(eepromHard);

        eeprom_update_byte(eepromStartChar1, letter1);
        eeprom_update_byte(eepromStartChar2, letter2);

        uint16_t highScore = 0;

        eeprom_update_word(eepromEasyLoc, highScore);
        eeprom_update_word(eepromHardLoc, highScore);

    }

    void saveScore(GameMode gameMode, uint16_t newScore) {

        uint16_t * const eepromLoc = reinterpret_cast<uint16_t *>(gameMode == GameMode::Easy ? eepromEasy : eepromHard);
        eeprom_update_word(eepromLoc, newScore);

    }

    uint16_t readSaveScore(GameMode gameMode) {

        uint16_t * const eepromLoc = reinterpret_cast<uint16_t *>(gameMode == GameMode::Easy ? eepromEasy : eepromHard);
        return eeprom_read_word(eepromLoc);

    }

}