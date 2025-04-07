#include "led.h"
#include "globals.h"

#if ENABLE_LED

// Define static members
CRGB Led::leds[NUM_LEDS];

void Led::init()
{
    FastLED.addLeds<LED_TYPE, LED_DI_PIN, LED_CI_PIN, COLOR_ORDER>(leds, NUM_LEDS);
    FastLED.setBrightness(10);
    leds[0] = CRGB::Black;
    FastLED.show();
    debugI("Led initialized with %d LED(s)", NUM_LEDS);
}

void Led::flash()
{
    // Flash the LED every half second
    if(timer.isOneSecondElapsed()) {
        static bool ledState = false;
        ledState = !ledState;

        if (ledState) {
            leds[0] = CRGB::GreenYellow;
        } else {
            leds[0] = CRGB::Black;
        }
        FastLED.show();
    }
}

void Led::off()
{
    leds[0] = CRGB::Black;
    FastLED.show();
}

#endif