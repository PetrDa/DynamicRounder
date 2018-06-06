// **************** Promenlive zaokrouhlovani odesilane hodnoty  ************************************
// ***** a to tak, ze ze zaokrouhli smerem k predchozi odeslane hodnote, aby se tlumilo kmitani *****
// **************************************************************************************************

#ifndef DYNAMIC_ROUNDER_H
#define DYNAMIC_ROUNDER_H

// **************************************************************************************************
// ********************** debug print macro *********************************************************
// **************************************************************************************************
#ifdef DRO_DEBUG
  #define DRO_DEBUG_PRINT(...) Serial.print(__VA_ARGS__)
  #define DRO_DEBUG_PRINTLN(...) Serial.println(__VA_ARGS__)
#else
  #define DRO_DEBUG_PRINT(...)
  #define DRO_DEBUG_PRINTLN(...)
#endif

#if ARDUINO >= 100
	#include "Arduino.h"
#else
	extern "C" {
		#include "WConstants.h"
	}
#endif

// **************************************************************************************************
// ************** Class DynamicRounder **************************************************************
// **************************************************************************************************

class DynamicRounder {
    public:
        DynamicRounder(                         // initiates a new object.
            float _precision = 1.0f             // to what number the data should be rounded, e.g. 0.1, 0.2, 0.5, 1.0, 2.0, 5.0, 10.0, etc.
        );
        float dynamicRound(float value);        // make dynamic rounding
    protected:
        float lastValue;
        float precision;
};

#endif // DYNAMIC_ROUNDER_H

