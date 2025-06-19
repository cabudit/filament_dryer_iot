#include "WiFiManager.h"

WiFiManager::WiFiManager(const char* ssid, const char* password, int maxRetries) {
    this->ssid = ssid;
    this->password = password;
    this->maxRetries = maxRetries;
}

void WiFiManager::connect() {
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
    Serial.print("Connecting to WiFi");

    int retries = 0;
    while (WiFi.status() != WL_CONNECTED && retries < maxRetries) {
        delay(500);
        Serial.print(".");
        retries++;
    }

    if (WiFi.status() == WL_CONNECTED) {
        Serial.println("\nWiFi Connected!");
        Serial.print("IP Address: ");
        Serial.println(WiFi.localIP());
    } else {
        Serial.println("\nFailed to connect to WiFi.");
    }
}

bool WiFiManager::isConnected() {
    return WiFi.status() == WL_CONNECTED;
}

IPAddress WiFiManager::getIPAddress() {
    return WiFi.localIP();
}
