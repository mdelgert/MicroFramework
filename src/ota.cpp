/*
#include "ota.h"
#include "globals.h"

#if ENABLE_OTA

#include <WiFi.h>
#include <ArduinoOTA.h>

void Ota::init()
{
    // Initialize OTA
    ArduinoOTA.setHostname(settings.getDeviceName());
    ArduinoOTA.setPassword(settings.getDevicePassword());

    ArduinoOTA.onStart([]() {
        String type = ArduinoOTA.getCommand() == U_FLASH ? "sketch" : "filesystem";
        debugI("OTA Start: Updating %s", type.c_str());
        led.flash();
    });

    ArduinoOTA.onEnd([]() {
        debugI("OTA End");
        led.off();
    });

    ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
        debugI("OTA Progress: %u%%", (progress * 100) / total);
    });

    ArduinoOTA.onError([](ota_error_t error) {
        debugE("OTA Error[%u]: %s", error, 
               error == OTA_AUTH_ERROR ? "Auth Failed" :
               error == OTA_BEGIN_ERROR ? "Begin Failed" :
               error == OTA_CONNECT_ERROR ? "Connect Failed" :
               error == OTA_RECEIVE_ERROR ? "Receive Failed" :
               "End Failed");
    });

    ArduinoOTA.begin();
    
    debugI("OTA setup complete");
}

void Ota::update()
{
    // Only call handle if WiFi is connected to avoid OTA errors
    if (WiFi.status() == WL_CONNECTED) {
        ArduinoOTA.handle();
    } else {
       
        if(timer.isThirtySecondsElapsed()) {
            debugW("WiFi not connected, skipping OTA handle");
        }
    }
}

#endif
*/