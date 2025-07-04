#include <Arduino.h>
#include "secrets.h"  // Include your secrets.h file for sensitive data
#include "WiFiManager.h"
#include "TelegramManager.h"
#include "RelayController.h"
#include "DS18B20Sensor.h"
#include "DHT.h"

#include "FanControl.h"
#include "PSUProtection.h"
#include "HeaterControl.h"

#define DHTPIN 15
#define DS18B20_PIN 16

#define DHTTYPE DHT22

DS18B20Sensor tempSensor(DS18B20_PIN);



// Inisialisasi pin relay

//relay 1 = GPIO 25 -> PTC
//relay 2 = GPIO 18 -> PTC FAN
//relay 3 = GPIO 19 -> EXHAUST FAN
//relay 4 = GPIO 21 -> OTHER RELAY

uint8_t relayPins[] = {25, 18, 19, 21};
RelayController relay(relayPins, 4);

FanControl fanControl(relay, 1, 15.0, 20.0); // Fan control on relay 2 with RH thresholds
PSUProtection psuProtection(relay, 0, 40.0, 50.0); // PSU protection on relay 1 with temperature thresholds
HeaterControl heaterControl(relay, 0, 70.0, 80.0); // Heater control on relay 1 with temperature thresholds

WiFiManager wifiManager(WIFI_SSID, WIFI_PASSWORD);
WiFiClientSecure secured_client;
TelegramManager telegram(TELEGRAM_BOT_TOKEN, secured_client, relay);
DHT dht(DHTPIN, DHTTYPE);

void setup() {
    Serial.begin(115200);
    wifiManager.connect();  
    secured_client.setInsecure(); 

    telegram.begin();
    dht.begin();
    tempSensor.begin();
    relay.begin();

}

void loop() {
    float tsupply = tempSensor.getTemperatureC();
    float temp = dht.readTemperature();
    float hum = dht.readHumidity();

    if (isnan(temp) && isnan(hum)) {
        temp = 0.0; // Set to 0 if reading fails
        hum = 0.0;  // Set to 0 if reading fails
    }

    // if ((tsupply >= 50.0 && tsupply <= 45.0) or  tsupply != -127.0){
    //     relay.off(0); // Matikan relay 1 jika suhu power supply <= 50°C dan sensor tidak berfungsi
    // } else if (tsupply >= 0 && temp < 80.0) {
    //     relay.on(0); // Nyalakan relay 1 jika suhu power supply < 50°C dan suhu ruangan < 80°C
    // }
    psuProtection.update(tsupply);
    heaterControl.update(temp, tsupply);
    fanControl.update(hum);

    telegram.setSensorData(tsupply, temp, hum);
    Serial.println(tsupply);
    telegram.update();
    delay(1000);
}
