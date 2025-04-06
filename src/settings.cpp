#include "settings.h"
#include "globals.h"
#include <string.h>

Preferences Settings::prefs;
char Settings::deviceName[32] = DEFAULT_DEVICE_NAME;
char Settings::devicePassword[64] = DEFAULT_DEVICE_PASSWORD;
char Settings::timezone[64] = DEFAULT_TIMEZONE;
char Settings::wifiSSID[32] = DEFAULT_WIFI_SSID;
char Settings::wifiPassword[64] = DEFAULT_WIFI_PASSWORD;
char Settings::mqttServer[64] = DEFAULT_MQTT_SERVER;
uint16_t Settings::mqttPort = DEFAULT_MQTT_PORT;

void Settings::init() {
    prefs.begin("microframework", false);

    // Load from NVS; if nothing is stored, use defaults from secrets.h
    if (prefs.getString("device_name", deviceName, sizeof(deviceName)) == 0) {
        strncpy(deviceName, DEFAULT_DEVICE_NAME, sizeof(deviceName) - 1);
        deviceName[sizeof(deviceName) - 1] = '\0';
    }
    if (prefs.getString("device_password", devicePassword, sizeof(devicePassword)) == 0) {
        strncpy(devicePassword, DEFAULT_DEVICE_PASSWORD, sizeof(devicePassword) - 1);
        devicePassword[sizeof(devicePassword) - 1] = '\0';
    }
    if (prefs.getString("timezone", timezone, sizeof(timezone)) == 0) {
        strncpy(timezone, DEFAULT_TIMEZONE, sizeof(timezone) - 1);
        timezone[sizeof(timezone) - 1] = '\0';
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

    debugI("Settings initialized");
}

// Getters
const char* Settings::getDeviceName() { return deviceName; }
const char* Settings::getDevicePassword() { return devicePassword; }
const char* Settings::getTimezone() { return timezone; }
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

void Settings::setDevicePassword(const char* pass) {
    strncpy(devicePassword, pass, sizeof(devicePassword) - 1);
    devicePassword[sizeof(devicePassword) - 1] = '\0';
    prefs.putString("device_password", devicePassword);
}

void Settings::setTimezone(const char* tz) {
    strncpy(timezone, tz, sizeof(timezone) - 1);
    timezone[sizeof(timezone) - 1] = '\0';
    prefs.putString("timezone", timezone);
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