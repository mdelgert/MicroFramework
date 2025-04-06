#pragma once

#ifndef ENABLE_TFT
#define ENABLE_TFT 1
#endif

#if ENABLE_TFT

#include <LovyanGFX.hpp>

class LGFX_LiLyGo_TDongleS3 : public lgfx::LGFX_Device
{
    lgfx::Panel_ST7735S _panel_instance;
    lgfx::Bus_SPI _bus_instance;
    lgfx::Light_PWM _light_instance;

public:
    LGFX_LiLyGo_TDongleS3();
};

class Tft
{
public:
    static void init();
    static void update();
    static void printHeap();
    static void test();

private:
    static LGFX_LiLyGo_TDongleS3 lcd;
    static int counter;
};

#else

class Tft
{
public:
    static void init() {}
    static void update() {}
    static void printHeap() {}
    static void test() {}
};

#endif

// Global reference
extern Tft& tft;