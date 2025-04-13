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
char Settings::mqttUsername[32] = DEFAULT_MQTT_USERNAME;
char Settings::mqttPassword[64] = DEFAULT_MQTT_PASSWORD;
char Settings::mqttPubTopic[64] = DEFAULT_MQTT_PUB_TOPIC;
char Settings::mqttSubTopic[64] = DEFAULT_MQTT_SUB_TOPIC;
uint16_t Settings::mqttPort = DEFAULT_MQTT_PORT;
bool Settings::mqttSSL = DEFAULT_MQTT_SSL;

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
    if (prefs.getString("mqtt_user", mqttUsername, sizeof(mqttUsername)) == 0) {
        strncpy(mqttUsername, DEFAULT_MQTT_USERNAME, sizeof(mqttUsername) - 1);
        mqttUsername[sizeof(mqttUsername) - 1] = '\0';
    }
    if (prefs.getString("mqtt_pass", mqttPassword, sizeof(mqttPassword)) == 0) {
        strncpy(mqttPassword, DEFAULT_MQTT_PASSWORD, sizeof(mqttPassword) - 1);
        mqttPassword[sizeof(mqttPassword) - 1] = '\0';
    }
    if (prefs.getString("mqtt_pub_topic", mqttPubTopic, sizeof(mqttPubTopic)) == 0) {
        strncpy(mqttPubTopic, DEFAULT_MQTT_PUB_TOPIC, sizeof(mqttPubTopic) - 1);
        mqttPubTopic[sizeof(mqttPubTopic) - 1] = '\0';
    }
    if (prefs.getString("mqtt_sub_topic", mqttSubTopic, sizeof(mqttSubTopic)) == 0) {
        strncpy(mqttSubTopic, DEFAULT_MQTT_SUB_TOPIC, sizeof(mqttSubTopic) - 1);
        mqttSubTopic[sizeof(mqttSubTopic) - 1] = '\0';
    }
    mqttPort = prefs.getUShort("mqtt_port", DEFAULT_MQTT_PORT);
    mqttSSL = prefs.getBool("mqtt_ssl", DEFAULT_MQTT_SSL);

    debugI("Settings initialized");
}

// Getters
const char* Settings::getDeviceName() { return deviceName; }
const char* Settings::getDevicePassword() { return devicePassword; }
const char* Settings::getTimezone() { return timezone; }
const char* Settings::getWifiSSID() { return wifiSSID; }
const char* Settings::getWifiPassword() { return wifiPassword; }
const char* Settings::getMqttServer() { return mqttServer; }
const char* Settings::getMqttUsername() { return mqttUsername; }
const char* Settings::getMqttPassword() { return mqttPassword; }
const char* Settings::getMqttPubTopic() { return mqttPubTopic; }
const char* Settings::getMqttSubTopic() { return mqttSubTopic; }
uint16_t Settings::getMqttPort() { return mqttPort; }
bool Settings::getMqttSSL() { return mqttSSL; }

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

void Settings::setMqttUsername(const char* user) {
    strncpy(mqttUsername, user, sizeof(mqttUsername) - 1);
    mqttUsername[sizeof(mqttUsername) - 1] = '\0';
    prefs.putString("mqtt_user", mqttUsername);
}

void Settings::setMqttPassword(const char* pass) {
    strncpy(mqttPassword, pass, sizeof(mqttPassword) - 1);
    mqttPassword[sizeof(mqttPassword) - 1] = '\0';
    prefs.putString("mqtt_pass", mqttPassword);
}

void Settings::setMqttPubTopic(const char* topic) {
    strncpy(mqttPubTopic, topic, sizeof(mqttPubTopic) - 1);
    mqttPubTopic[sizeof(mqttPubTopic) - 1] = '\0';
    prefs.putString("mqtt_pub_topic", mqttPubTopic);
}

void Settings::setMqttSubTopic(const char* topic) {
    strncpy(mqttSubTopic, topic, sizeof(mqttSubTopic) - 1);
    mqttSubTopic[sizeof(mqttSubTopic) - 1] = '\0';
    prefs.putString("mqtt_sub_topic", mqttSubTopic);
}

void Settings::setMqttPort(uint16_t port) {
    mqttPort = port;
    prefs.putUShort("mqtt_port", mqttPort);
}

void Settings::setMqttSSL(bool ssl) {
    mqttSSL = ssl;
    prefs.putBool("mqtt_ssl", mqttSSL);
}

void Settings::clear() {
    prefs.clear();
    prefs.end();
    debugI("Preferences wiped. Resetting to defaults.");
    init();
}

void Settings::setDefaults() {
    debugI("Setting all preferences to default values...");

    // Set and save each preference to its default value
    setDeviceName(DEFAULT_DEVICE_NAME);
    setDevicePassword(DEFAULT_DEVICE_PASSWORD);
    setTimezone(DEFAULT_TIMEZONE);
    setWifiSSID(DEFAULT_WIFI_SSID);
    setWifiPassword(DEFAULT_WIFI_PASSWORD);
    setMqttServer(DEFAULT_MQTT_SERVER);
    setMqttUsername(DEFAULT_MQTT_USERNAME);
    setMqttPassword(DEFAULT_MQTT_PASSWORD);
    setMqttPubTopic(DEFAULT_MQTT_PUB_TOPIC);
    setMqttSubTopic(DEFAULT_MQTT_SUB_TOPIC);
    setMqttPort(DEFAULT_MQTT_PORT);
    setMqttSSL(DEFAULT_MQTT_SSL);

    debugI("All preferences have been reset to defaults and saved.");
}