// PSUProtection.cpp
#include "PSUProtection.h"

PSUProtection::PSUProtection(RelayController& relay, uint8_t relayIndex, float lowThresh, float highThresh)
  : _relay(relay), _index(relayIndex), _lowThresh(lowThresh), _highThresh(highThresh), _state(false) {}

void PSUProtection::update(float tsupply) {
  if (!_state && tsupply < _lowThresh) {
    _relay.on(_index);
    _state = true;
  } else if (_state && tsupply > _highThresh) {
    _relay.off(_index);
    _state = false;
  }
}
