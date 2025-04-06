#pragma once

#ifndef ENABLE_MQTT
#define ENABLE_MQTT 1
#endif

#if ENABLE_MQTT && ENABLE_NETWORK

#include "globals.h"

class Mqtt
{
public:
    static void init();
    static void update();

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
};

#endif

// Global reference
extern Mqtt mqtt;