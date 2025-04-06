#pragma once

#ifndef ENABLE_WIFI_MANAGER
#define ENABLE_WIFI_MANAGER 1
#endif

#if ENABLE_WIFI_MANAGER

class WiFiManager
{
public:
    static void init();
    static void update();

private:

};

#else

class WiFiManager
{
public:
    static void init() {}
    static void update() {}
};

#endif