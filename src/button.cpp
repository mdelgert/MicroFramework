#include "button.h"
#include "globals.h"

#if ENABLE_BUTTON

static OneButton btn(BUTTON_PIN, true);

void Button::update()
{
    // Update the button state
    btn.tick();

    // If the button is pressed, we can also handle any other logic here if needed
    // For example, you could check for long press duration or other states
    // btn.isLongPressed() can be used to check if it's still pressed after a certain time
    // debugI("Button state updated");
}

void Button::init()
{
    btn.attachClick(singleClick);
    btn.attachDoubleClick(doubleClick);
    btn.attachLongPressStart(longPressStart);
}

void Button::singleClick()
{
    debugI("Button single click detected");
    //kmd.mouseTest();
}

void Button::doubleClick()
{
    debugI("Button double click detected");
    //kmd.keyboardTest();
}

void Button::longPressStart()
{
    debugI("Button long press start detected");
    // debugI("Rebooting the device...");
    // ESP.restart();
}

#endif