#pragma once

#ifndef ENABLE_MQTT
#define ENABLE_MQTT 1
#endif

#if ENABLE_MQTT

class Mqtt
{
public:
    static void init();
    static void update();

private:

};

#else

class Mqtt
{
public:
    static void init() {}
    static void update() {}
};

#endif