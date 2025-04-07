#pragma once

#ifndef ENABLE_OTA
#define ENABLE_OTA 1
#endif

#if ENABLE_OTA

class Ota
{
public:
    static void init();
    static void update();

private:

};

#else

class Ota
{
public:
    static void init() {}
    static void update() {}
};

#endif

// Global reference
extern Ota& ota;