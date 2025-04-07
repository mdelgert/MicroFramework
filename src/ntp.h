/*
#pragma once

#ifndef ENABLE_NTP
#define ENABLE_NTP 1
#endif

#if ENABLE_NTP

#include <time.h>

class Ntp
{
private:
    static void logCurrentTime(const struct tm &timeInfo);

public:
    static void init();
    static void update();
};

#else

class Ntp
{
public:
    static void init() {}
    static void update() {}
};

#endif

// Global reference
extern Ntp &ntp;
*/