#include "DHTManager.h"

DHTManager::DHTManager(uint8_t pin, uint8_t type) : dht(pin, type) {}

void DHTManager::begin() {
    dht.begin();
}

bool DHTManager::readSensor() {
    float h = dht.readHumidity();
    float t = dht.readTemperature();

    if (isnan(h) || isnan(t)) {
        return false;
    }

    humidity = h;
    temperature = t;
    return true;
}

float DHTManager::getTemperature() {
    return temperature;
}

float DHTManager::getHumidity() {
    return humidity;
}
