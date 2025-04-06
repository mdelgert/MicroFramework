#pragma once

#ifndef ENABLE_NTP
#define ENABLE_NTP 1
#endif

#if ENABLE_NTP

class Ntp
{
public:
    static void init();
    static void update();

private:
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