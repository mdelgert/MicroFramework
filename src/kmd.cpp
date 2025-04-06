#include "kmd.h"
#include "globals.h"

#if ENABLE_KMD

#include "descriptor.h"
#include <USB.h>
#include <USBHIDKeyboard.h>
#include <USBHIDMouse.h>

USBHIDKeyboard keyboard;
USBHIDMouse mouse;

void Kmd::init()
{
    USB.begin();
    keyboard.begin();
    mouse.begin();
    debugI("KMD initialized: USB, Keyboard, Mouse ready");
}

void Kmd::keyboardTest()
{
    keyboard.println("Hello from KMD!");
    debugI("KMD: Sent hello message to USB host.");
}

void Kmd::mouseTest()
{
    mouse.move(100, 100);
    debugI("KMD: Mouse test completed.");
}

#endif