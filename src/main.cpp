#include <Arduino.h>
#include "WiFiManager.h"
#include "TelegramManager.h"
#include "RelayController.h"
#include "DHT.h"

#define DHTPIN 15
#define DHTTYPE DHT22

const char* ssid = "mboed";
const char* password = "mboed123";
const char* botToken = "7987528842:AAGijy7HF-B8sZUwvxGTniDshVqcAXlwHIQ";

// Inisialisasi pin relay
//relay 1 = GPIO 25 -> PTC
//relay 2 = GPIO 18 -> PTC FAN
//relay 3 = GPIO 19 -> EXHAUST FAN
//relay 4 = GPIO 21 -> OTHER RELAY

uint8_t relayPins[] = {25, 18, 19, 21};
RelayController relay(relayPins, 4);

WiFiManager wifiManager(ssid, password);
WiFiClientSecure secured_client;
TelegramManager telegram(botToken, secured_client, relay);
DHT dht(DHTPIN, DHTTYPE);

void setup() {
    Serial.begin(115200);
    wifiManager.connect();  

    secured_client.setInsecure(); // Gunakan ini jika tidak pakai SSL cert
    telegram.begin();
    dht.begin();
    relay.begin();

}

void loop() {
    float temp = dht.readTemperature();
    float hum = dht.readHumidity();

    if (!isnan(temp) && !isnan(hum)) {
        telegram.setSensorData(temp, hum);
    }

    telegram.update();
    delay(1000);
}
