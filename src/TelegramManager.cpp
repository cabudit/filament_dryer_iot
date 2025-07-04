#include "TelegramManager.h"
#include "RelayController.h"

TelegramManager::TelegramManager(const char* token, Client& client, RelayController& relayController)
    : _token(token), _bot(client) , _relay(relayController){}

void TelegramManager::begin() {
    _bot.setTelegramToken(_token);
    _bot.begin();
    _bot.setUpdateTime(1000);
}

void TelegramManager::update() {
    TBMessage msg;
    if (_bot.getNewMessage(msg)) {
        handleMessage(msg);
    }
}

void TelegramManager::handleMessage(TBMessage &msg) {
    Serial.print("Pesan masuk: ");
    Serial.println(msg.text); // Debugging

    String command = msg.text;
    command.trim(); // Hapus spasi dan karakter newline

    if (command == "/cek") {
        String status = "*Status Sensor:*\n";
        status += "🌡⚡ Suhu Power Supply: " + String(_tsupply, 1) + " °C\n";
        status += "🌡 Suhu: " + String(_temperature, 1) + " °C\n";
        status += "💧 Kelembaban: " + String(_humidity, 1) + " %\n";

        _bot.sendMessage(msg, status, emptyString);
        
    } else if (command == "/relay1_on") {
        _relay.on(0);
        _bot.sendMessage(msg, "Relay 1 dinyalakan", nullptr);
    } else if (command == "/relay1_off") {
        _relay.off(0);
        _bot.sendMessage(msg, "Relay 1 dimatikan", nullptr);
 
    } else {
        _bot.sendMessage(msg, "Perintah tidak dikenali. Gunakan /cek",nullptr);
    }
}

void TelegramManager::setSensorData(float tsupply, float temperature, float humidity) {
    _tsupply = tsupply;
    _temperature = temperature;
    _humidity = humidity;
}
