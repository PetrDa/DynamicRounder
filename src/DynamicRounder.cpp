#include "DynamicRounder.h"

// **************** Promenlive zaokrouhlovani odesilane hodnoty  ****************************
// * a to tak, ze ze zaokrouhli smerem k predchozi odeslane hodnote, aby se tlumilo kmitani *
// ******************************************************************************************

#define DR_INIT_NUMBER -200.12345

// **********************************************************************
// ************** Class DynamicRounder **********************************
// **********************************************************************
DynamicRounder::DynamicRounder(
            float _precision                    // to what number the data should be rounded, e.g. 0.1, 0.2, 0.5, 1.0, 2.0, 5.0, 10.0, etc.
    )
{
    precision = _precision;
    lastValue = DR_INIT_NUMBER;
}

// **********************************************************************
float DynamicRounder::dynamicRound(float value)
{
    if (lastValue != DR_INIT_NUMBER) {      // jiz drive neco odeslano
      
        float y = value - lastValue;        // zmena od minule odeslane hodnoty
        
        if (y >= 0) {                       // limitace zmeny hodnoty na posledni prekrocenou jednotku presnosti
                                            // zaokrohleni dolu na jednotku presnosti pri rustu hodnoty
            value = round( value / precision - 0.4999999) * precision;
        } else {
                                            // zaokrohleni nahoru na jednotku presnosti pri klesani hodnoty
            value = round( value / precision + 0.4999999) * precision;
        }
        
    } else {                                // drive neodeslano => prvni mereni jen zaokrouhlit
                                            // zaokrouhleni na jednotku presnosti
        value = round (value / precision) * precision; 
    }
    DRO_DEBUG_PRINT(F("V: "));
    DRO_DEBUG_PRINT(value);
    DRO_DEBUG_PRINT(F(" LV: "));
    DRO_DEBUG_PRINTLN(lastValue);
    lastValue = value;
    return value;
}

