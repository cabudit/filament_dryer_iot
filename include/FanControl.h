// FanControl.h
#ifndef FAN_CONTROL_H
#define FAN_CONTROL_H

#include <Arduino.h>
#include "RelayController.h"

class FanControl {
  public:
    FanControl(RelayController& relay, uint8_t relayIndex, float onRH = 30.0, float offRH = 25.0);
    void update(float humidity);

  private:
    RelayController& _relay;
    uint8_t _index;
    float _onRH;
    float _offRH;
    bool _state;
};

#endif