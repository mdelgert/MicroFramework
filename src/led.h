#pragma once

#ifndef ENABLE_LED
#define ENABLE_LED 1
#endif

#if ENABLE_LED

#include <FastLED.h>
#define NUM_LEDS 1
#define LED_TYPE APA102
#define COLOR_ORDER BGR

class Led
{
public:
    static void init();
    static void flash();
    static void off();

private:
    static CRGB leds[NUM_LEDS];
};

#else

class Led
{
public:
    static void init() {}
    static void flash() {}
    static void off() {}
};

#endif

// Global reference
extern Led& led;