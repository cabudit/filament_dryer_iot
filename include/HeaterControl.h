// HeaterControl.h
#ifndef HEATER_CONTROL_H
#define HEATER_CONTROL_H

#include <Arduino.h>
#include "RelayController.h"

class HeaterControl {
  public:
    HeaterControl(RelayController& relay, uint8_t relayIndex, float onThresh = 65.0, float offThresh = 75.0);
    void update(float roomTemp, float psuTemp);

  private:
    RelayController& _relay;
    uint8_t _index;
    float _onThresh;
    float _offThresh;
    bool _state;
};

#endif