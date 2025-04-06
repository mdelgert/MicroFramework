#pragma once

#ifndef ENABLE_WIFI
#define ENABLE_WIFI 1
#endif

#if ENABLE_WIFI

class Wifi
{
public:
    static void init();
    static void update();

private:

};

#else

class Wifi
{
public:
    static void init() {}
    static void update() {}
};

#endif