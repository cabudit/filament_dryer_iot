#include "DS18B20Sensor.h"

DS18B20Sensor::DS18B20Sensor(uint8_t pin) 
  : _pin(pin), _oneWire(pin), _sensors(&_oneWire) {}

void DS18B20Sensor::begin() {
  _sensors.begin();
}

float DS18B20Sensor::getTemperatureC() {
  _sensors.requestTemperatures();
  return _sensors.getTempCByIndex(0);  // get temperature from DS18B20
}
