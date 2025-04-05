#pragma once

#ifndef ENABLE_GFX
#define ENABLE_GFX 1
#endif

#if ENABLE_GFX

#include <LovyanGFX.hpp>

class LGFX_LiLyGo_TDongleS3 : public lgfx::LGFX_Device
{
    lgfx::Panel_ST7735S _panel_instance;
    lgfx::Bus_SPI _bus_instance;
    lgfx::Light_PWM _light_instance;

public:
    LGFX_LiLyGo_TDongleS3();
};

class Gfx
{
public:
    static void init();
    static void update();
    static void test();

private:
    static LGFX_LiLyGo_TDongleS3 tft;
    static int counter;
};

#else

class Gfx
{
public:
    static void init() {}
    static void update() {}
    static void test() {}
};

#endif

// Global reference
extern Gfx& gfx;