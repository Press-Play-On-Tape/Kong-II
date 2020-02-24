#pragma once

#include "../utils/Arduboy2Ext.h"
#include "../Utils/Enums.h"
#include "Spark.h"

class Sparks {

    public:

        Sparks();

        Spark & getSpark(uint8_t index);

        void updatePositions();
        void setDelayMax(uint16_t delayMax, bool updateDelay);
        void launchSpark();
        void reset(uint8_t const *path);

    protected:

        Spark sparks[4];
        uint16_t delay;
        uint16_t delayMax;

};

