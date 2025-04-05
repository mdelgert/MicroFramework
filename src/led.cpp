#include "led.h"
#include "globals.h"

#if ENABLE_LED

// Define static members
CRGB Led::leds[NUM_LEDS];

void Led::init()
{
    FastLED.addLeds<LED_TYPE, LED_DI_PIN, LED_CI_PIN, COLOR_ORDER>(leds, NUM_LEDS);
    FastLED.setBrightness(25); // Set initial brightness (0-255)
    debugI("Led initialized with %d LED(s)", NUM_LEDS);
}

void Led::update()
{
    // Currently no update logic needed for LED
    // This can be used to implement animations or effects in the future
    // For now, we just keep it empty
    debugI("Led update called, but no action taken.");
}

void Led::flash()
{
    leds[0] = CRGB::GreenYellow; // Set the first LED to GreenYellow
    FastLED.show();
    delay(500);
    leds[0] = CRGB::Black;
    FastLED.show();
    delay(500);
}

#endif