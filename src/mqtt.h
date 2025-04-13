#pragma once

#ifndef ENABLE_MQTT
#define ENABLE_MQTT 1
#endif

#if ENABLE_MQTT

#include "globals.h"

class Mqtt
{
public:
    static void init();
    static void update();
    static void sendMessage(const char* topic, const char* message);
    static void logMessage(const char* topic, const char* message);

private:
    static void connectToMQTT();
    static void mqttCallback(char *topic, byte *payload, unsigned int length);
};

#else

class Mqtt
{
public:
    static void init() {}
    static void update() {}
    static void sendMessage(const char* topic, const char* message) {}
    static void logMessage(const char* topic, const char* message) {}
};

#endif

// Global reference
extern Mqtt mqtt;