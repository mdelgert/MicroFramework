#pragma once

#ifndef ENABLE_BUTTON
#define ENABLE_BUTTON 1
#endif

#if ENABLE_BUTTON

#include "OneButton.h"

class Button
{
public:
    static void update();
    static void init();

private:
    static void singleClick();
    static void doubleClick();
    static void longPressStart();
};

#else

class Button
{
public:
    static void update() {}
    static void init() {}
};

#endif

// Global reference
extern Button& button;