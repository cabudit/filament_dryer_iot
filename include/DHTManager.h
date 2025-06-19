#ifndef DHT_MANAGER_H
#define DHT_MANAGER_H

#include <DHT.h>

class DHTManager {
  private:
    DHT dht;
    float temperature;
    float humidity;

  public:
    DHTManager(uint8_t pin, uint8_t type);
    void begin();
    bool readSensor();
    float getTemperature();
    float getHumidity();
};

#endif
