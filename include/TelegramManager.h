#ifndef TELEGRAM_MANAGER_H
#define TELEGRAM_MANAGER_H

#include <WiFiClientSecure.h>
#include <AsyncTelegram2.h>
#include "RelayController.h"

class TelegramManager {
public:
    TelegramManager(const char* token, Client& client, RelayController& relayController);
    void begin();
    void update();
    void setSensorData(float temperature, float humidity);

private:
    void handleMessage(TBMessage &msg);

    const char* _token;
    AsyncTelegram2 _bot;
    float _temperature = 0.0;
    float _humidity = 0.0;
    RelayController& _relay;
};

#endif
