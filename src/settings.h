#pragma once

#include <Preferences.h>

class Settings
{
private:
    static Preferences prefs;
    static char deviceName[32];
    static char devicePassword[64];
    static char timezone[64];
    static char wifiSSID[32];
    static char wifiPassword[64];
    static char mqttServer[64];
    static char mqttUsername[32];
    static char mqttPassword[64];
    static char mqttPubTopic[64];
    static char mqttSubTopic[64];
    static uint16_t mqttPort;

public:
    static void init();

    // Setters
    static void setDeviceName(const char *name);
    static void setDevicePassword(const char *pass);
    static void setTimezone(const char *tz);
    static void setWifiSSID(const char *ssid);
    static void setWifiPassword(const char *pass);
    static void setMqttServer(const char *server);
    static void setMqttUsername(const char *user);
    static void setMqttPassword(const char *pass);
    static void setMqttPubTopic(const char *topic);
    static void setMqttSubTopic(const char *topic);
    static void setMqttPort(uint16_t port);

    // Getters
    static const char *getDeviceName();
    static const char *getDevicePassword();
    static const char *getTimezone();
    static const char *getWifiSSID();
    static const char *getWifiPassword();
    static const char *getMqttServer();
    static const char *getMqttUsername();
    static const char *getMqttPassword();
    static const char *getMqttPubTopic();
    static const char *getMqttSubTopic();
    static uint16_t getMqttPort();
};

// External references for the settings
extern Settings &settings;