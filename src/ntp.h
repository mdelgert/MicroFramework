#pragma once

#ifndef ENABLE_NTP
#define ENABLE_NTP 1
#endif

#if ENABLE_NTP

class Ntp
{
public:
    static void update();
    static void init();

private:
};

#else

class Ntp
{
public:
    static void update() {}
    static void init() {}
};

#endif

// Global reference
extern Ntp &ntp;