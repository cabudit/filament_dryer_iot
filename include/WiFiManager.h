#ifndef WIFI_MANAGER_H
#define WIFI_MANAGER_H

#include <WiFi.h>

class WiFiManager {
  private:
    const char* ssid;
    const char* password;
    int maxRetries;

  public:
    WiFiManager(const char* ssid, const char* password, int maxRetries = 20);
    void connect();
    bool isConnected();
    IPAddress getIPAddress();
};

#endif
