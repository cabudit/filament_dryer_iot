#ifndef RELAYCONTROLLER_H
#define RELAYCONTROLLER_H

#include <Arduino.h>

class RelayController {
public:
    RelayController(uint8_t pins[], uint8_t relayCount);
    void begin();
    void on(uint8_t relayIndex);   // Aktifkan relay
    void off(uint8_t relayIndex);  // Nonaktifkan relay
    bool isOn(uint8_t relayIndex); // Cek status relay
    void allOff();
    void allOn();

private:
    uint8_t* _pins;
    uint8_t _count;
    bool* _status;
};

#endif
