#include "RelayController.h"

RelayController::RelayController(uint8_t pins[], uint8_t relayCount)
    : _pins(pins), _count(relayCount) {
    _status = new bool[_count]{false};
}

void RelayController::begin() {
    for (uint8_t i = 0; i < _count; ++i) {
        pinMode(_pins[i], OUTPUT);
        digitalWrite(_pins[i], HIGH);  // Matikan relay awal (aktif LOW)
        _status[i] = false;
    }
}

void RelayController::on(uint8_t relayIndex) {
    if (relayIndex < _count) {
        digitalWrite(_pins[relayIndex], LOW);  // Aktifkan (aktif LOW)
        _status[relayIndex] = true;
        //test led
        Serial.print("Relay ");
        Serial.print(relayIndex);
        Serial.println(" OFF");
    }
}

void RelayController::off(uint8_t relayIndex) {
    if (relayIndex < _count) {
        digitalWrite(_pins[relayIndex], HIGH);  // Nonaktifkan
        _status[relayIndex] = false;

        //test led
        Serial.print("Relay ");
        Serial.print(relayIndex);
        Serial.println(" ON");
    }
}

bool RelayController::isOn(uint8_t relayIndex) {
    return (relayIndex < _count) ? _status[relayIndex] : false;
}

void RelayController::allOff() {
    for (uint8_t i = 0; i < _count; ++i) {
        off(i);
    }
}

void RelayController::allOn() {
    for (uint8_t i = 0; i < _count; ++i) {
        on(i);
    }
}
