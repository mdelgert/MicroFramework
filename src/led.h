#pragma once

#include <FastLED.h>

#ifndef ENABLE_LED
#define ENABLE_LED 1
#define NUM_LEDS 1
#define LED_TYPE APA102
#define COLOR_ORDER BGR
#endif

#if ENABLE_LED

class Led
{
public:
    static void init();
    static void update();
    static void flash();

private:
    static CRGB leds[NUM_LEDS];
};

#else

class Example
{
public:
    static void init() {}
    static void update() {}
    static void flash() {}
};

#endif

// Global reference
extern Led& led;