// PSUProtection.h
#ifndef PSU_PROTECTION_H
#define PSU_PROTECTION_H

#include <Arduino.h>
#include "RelayController.h"

class PSUProtection {
  public:
    PSUProtection(RelayController& relay, uint8_t relayIndex, float lowThresh = 45.0, float highThresh = 50.0);
    void update(float tsupply);

  private:
    RelayController& _relay;
    uint8_t _index;
    float _lowThresh;
    float _highThresh;
    bool _state;
};

#endif