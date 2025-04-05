#pragma once

#ifndef ENABLE_LED
#define ENABLE_LED 1
#endif

#if ENABLE_LED

class Led
{
public:
    static void init();
    static void update();

private:
    static void flash();
};

#else

class Example
{
public:
    static void init() {}
    static void update() {}
};

#endif

// Global reference
extern Led& led;