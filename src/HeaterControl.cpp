// HeaterControl.cpp
#include "HeaterControl.h"

HeaterControl::HeaterControl(RelayController& relay, uint8_t relayIndex, float onThresh, float offThresh)
  : _relay(relay), _index(relayIndex), _onThresh(onThresh), _offThresh(offThresh), _state(false) {}

  // jbagaimana caranya agar suhu ruangan dehumidifier dijaga pada suhu 60-80°C
void HeaterControl::update(float roomTemp, float psuTemp) {
  if (!_state && roomTemp < _onThresh && psuTemp < 50.0) {
    _relay.on(_index);
    _state = true;
  } else if (_state && roomTemp > _offThresh) {
    _relay.off(_index);
    _state = false;
  }
}