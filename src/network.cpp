#include "network.h"
#include "globals.h"

#if ENABLE_NETWORK

#include <WiFi.h>
#include <ESPmDNS.h>

void Network::init()
{
    debugI("Connecting to WiFi...");
    WiFi.disconnect();

    if( WiFi.status() != WL_CONNECTED) {
        WiFi.mode(WIFI_STA);
        WiFi.setHostname(settings.getDeviceName());
        WiFi.begin(settings.getWifiSSID(), settings.getWifiPassword());
        MDNS.begin(settings.getDeviceName());
        MDNS.addService("_http", "_tcp", 80);
    }
}

void Network::update()
{
    // Check if WiFi is connected
    if(timer.isOneMinuteElapsed())
    {
        if (WiFi.status() != WL_CONNECTED) {
            debugW("WiFi not connected, trying to reconnect...");
            init();
        }
    }
}

#endif