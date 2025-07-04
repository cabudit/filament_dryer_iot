// FanControl.cpp
#include "FanControl.h"

FanControl::FanControl(RelayController& relay, uint8_t relayIndex, float onRH, float offRH)
  : _relay(relay), _index(relayIndex), _onRH(onRH), _offRH(offRH), _state(false) {}

void FanControl::update(float humidity) {
  if (!_state && humidity > _onRH) {
    _relay.on(_index);
    _state = true;
  } else if (_state && humidity < _offRH) {
    _relay.off(_index);
    _state = false;
  }
}
