#pragma once  // Using #pragma once instead of #ifndef guard

#include <Preferences.h>

class Settings {
public:
    static void init();
    static void setDeviceName(const char* name);  // Added setter
    static void setWifiSSID(const char* ssid);    // Added setter
    static void setWifiPassword(const char* pass); // Added setter
    static void setMqttServer(const char* server); // Added setter
    static void setMqttPort(uint16_t port);       // Added setter

    static const char* getDeviceName();
    static const char* getWifiSSID();
    static const char* getWifiPassword();
    static const char* getMqttServer();
    static uint16_t getMqttPort();

private:
    static Preferences prefs;
    static char deviceName[32];
    static char wifiSSID[32];
    static char wifiPassword[64];
    static char mqttServer[64];
    static uint16_t mqttPort;
};