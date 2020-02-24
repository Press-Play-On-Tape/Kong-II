#pragma once

#include "../utils/Arduboy2Ext.h"
#include "../Utils/Enums.h"
#include "Clapper.h"

class Clappers {

    public:

        Clappers();

        Clapper & getClapper(uint8_t index);

        void updatePositions();
        void setDelayMax(uint16_t delayMax, bool updateDelay);
        void launchClapper();
        void reset(uint8_t y);

    protected:

        Clapper clappers[4];
        uint16_t delay;
        uint16_t delayMax;

};

