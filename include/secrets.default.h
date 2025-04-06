#pragma once

#include <Arduino.h>

#ifndef SECRETS_H
#define SECRETS_H

// Default values for GitHub/public use
#define DEFAULT_DEVICE_NAME "micro"
#define DEFAULT_DEVICE_PASSWORD "password"
#define DEFAULT_TIMEZONE "America/New_York"
#define DEFAULT_WIFI_SSID "MyWiFi"
#define DEFAULT_WIFI_PASSWORD "password123"
#define DEFAULT_MQTT_SERVER "mqtt.example.com"
#define DEFAULT_MQTT_PORT 1883
#define DEFAULT_MQTT_SSL false
#define DEFAULT_MQTT_USERNAME "youruser"
#define DEFAULT_MQTT_PASSWORD "yourpassword"
#define DEFAULT_MQTT_SUB_TOPIC "microframework/in"
#define DEFAULT_MQTT_PUB_TOPIC "microframework/out"

#endif // SECRETS_H