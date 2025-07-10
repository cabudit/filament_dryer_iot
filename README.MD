## ✅ Revisi Minor (versi yang sudah disempurnakan):

# Filament Dryer ESP32

An intelligent humidity and temperature controller for filament storage, built with **ESP32**.
This project automates fan and heater control based on sensor readings and supports Telegram notifications.

## 🚀 Features

-   Temperature monitoring using **DS18B20**
-   Humidity & temperature monitoring using **DHT22**
-   Relay-controlled **heater and fans**
-   **Telegram Bot** integration for remote control and real-time alerts
-   Hysteresis logic to prevent relay flickering
-   Modular and testable code architecture

## 🔧 Setup

1. Clone this repository to your local machine:

    ```bash
    git clone https://github.com/your-username/filament_dryer_esp32.git
    ```

2. Open the project using **PlatformIO** in VSCode.

3. Create and configure `include/secrets.h` with your credentials:

    ```cpp
    // secrets.h
    #ifndef SECRETS_H
    #define SECRETS_H

    const char* WIFI_SSID = "yourssid";
    const char* WIFI_PASSWORD = "yourpassword";
    const char* TELEGRAM_BOT_TOKEN = "yourtelegrambottoken";

    #endif
    ```

4. Connect your ESP32 board and upload the firmware:

    ```bash
    platformio run --target upload
    ```

5. Open the **Serial Monitor** at `115200 baud` to view logs and status updates:

    ```bash
    platformio device monitor -b 115200
    ```

## 📁 Project Structure

```
filament_dryer_esp32/
├── include/            # Header files, including secrets.h
├── lib/                # Optional libraries (if needed)
├── src/                # Main firmware source (main.cpp)
├── test/               # Test cases
├── platformio.ini      # PlatformIO project configuration
└── README.md           # Project documentation
```

---

## 📚 Modules

You can document modules like `FanControl`, `HeaterControl`, `PSUProtection`, and `TelegramManager` below this section (as done earlier).

---

## 🛠 Dependencies

Automatically installed by PlatformIO via `platformio.ini`:

```ini
lib_deps =
    https://github.com/cotestatnt/AsyncTelegram2.git
    adafruit/DHT sensor library@^1.4.5
    milesburton/DallasTemperature@^4.0.4
```

---

## 📄 License

This project is licensed under the [MIT License](LICENSE).
