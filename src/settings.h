#pragma once

#include <Preferences.h>

class Settings {
public:
    static void init();
    static void setDeviceName(const char* name);
    static void setDevicePassword(const char* pass);
    static void setWifiSSID(const char* ssid);
    static void setWifiPassword(const char* pass);
    static void setMqttServer(const char* server);
    static void setMqttPort(uint16_t port);
    static const char* getDeviceName();
    static const char* getDevicePassword();
    static const char* getWifiSSID();
    static const char* getWifiPassword();
    static const char* getMqttServer();
    static uint16_t getMqttPort();
private:
    static Preferences prefs;
    static char deviceName[32];
    static char devicePassword[64];
    static char wifiSSID[32];
    static char wifiPassword[64];
    static char mqttServer[64];
    static uint16_t mqttPort;
};

// External references for the settings
extern Settings& settings;