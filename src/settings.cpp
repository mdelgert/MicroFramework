#include "settings.h"
#include "secrets.h"  // Ensure secrets.h defines DEFAULT_* constants
#include <string.h>   // For strncpy()

Preferences Settings::prefs;
char Settings::deviceName[32] = DEFAULT_DEVICE_NAME;
char Settings::wifiSSID[32] = DEFAULT_WIFI_SSID;
char Settings::wifiPassword[64] = DEFAULT_WIFI_PASSWORD;
char Settings::mqttServer[64] = DEFAULT_MQTT_SERVER;
uint16_t Settings::mqttPort = DEFAULT_MQTT_PORT;

void Settings::init() {
    prefs.begin("microframework", false);

    // Load from NVS; if nothing is stored, use defaults from secrets.h
    if (prefs.getString("device_name", deviceName, sizeof(deviceName)) == 0) {
        strncpy(deviceName, DEFAULT_DEVICE_NAME, sizeof(deviceName) - 1);
        deviceName[sizeof(deviceName) - 1] = '\0'; // Ensure null termination
    }
    if (prefs.getString("wifi_ssid", wifiSSID, sizeof(wifiSSID)) == 0) {
        strncpy(wifiSSID, DEFAULT_WIFI_SSID, sizeof(wifiSSID) - 1);
        wifiSSID[sizeof(wifiSSID) - 1] = '\0';
    }
    if (prefs.getString("wifi_pass", wifiPassword, sizeof(wifiPassword)) == 0) {
        strncpy(wifiPassword, DEFAULT_WIFI_PASSWORD, sizeof(wifiPassword) - 1);
        wifiPassword[sizeof(wifiPassword) - 1] = '\0';
    }
    if (prefs.getString("mqtt_server", mqttServer, sizeof(mqttServer)) == 0) {
        strncpy(mqttServer, DEFAULT_MQTT_SERVER, sizeof(mqttServer) - 1);
        mqttServer[sizeof(mqttServer) - 1] = '\0';
    }
    mqttPort = prefs.getUShort("mqtt_port", DEFAULT_MQTT_PORT);

    // Uncomment if Logger is included and working
    // Logger::info("Settings initialized");
}

// Getters
const char* Settings::getDeviceName() { return deviceName; }
const char* Settings::getWifiSSID() { return wifiSSID; }
const char* Settings::getWifiPassword() { return wifiPassword; }
const char* Settings::getMqttServer() { return mqttServer; }
uint16_t Settings::getMqttPort() { return mqttPort; }

// Setters
void Settings::setDeviceName(const char* name) {
    strncpy(deviceName, name, sizeof(deviceName) - 1);
    deviceName[sizeof(deviceName) - 1] = '\0';
    prefs.putString("device_name", deviceName);
}

void Settings::setWifiSSID(const char* ssid) {
    strncpy(wifiSSID, ssid, sizeof(wifiSSID) - 1);
    wifiSSID[sizeof(wifiSSID) - 1] = '\0';
    prefs.putString("wifi_ssid", wifiSSID);
}

void Settings::setWifiPassword(const char* pass) {
    strncpy(wifiPassword, pass, sizeof(wifiPassword) - 1);
    wifiPassword[sizeof(wifiPassword) - 1] = '\0';
    prefs.putString("wifi_pass", wifiPassword);
}

void Settings::setMqttServer(const char* server) {
    strncpy(mqttServer, server, sizeof(mqttServer) - 1);
    mqttServer[sizeof(mqttServer) - 1] = '\0';
    prefs.putString("mqtt_server", mqttServer);
}

void Settings::setMqttPort(uint16_t port) {
    mqttPort = port;
    prefs.putUShort("mqtt_port", mqttPort);
}