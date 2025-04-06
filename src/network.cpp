#include "network.h"
#include "globals.h"

#if ENABLE_NETWORK

#include <WiFi.h>
#include <ESPmDNS.h>

void Network::init()
{
    // Connect to WiFi if not already connected
    if (!isConnected()) {
        debugI("Connecting to WiFi...");
        WiFi.mode(WIFI_STA);
        WiFi.disconnect();
        if(timer.isOneSecondElapsed)
        {
            WiFi.begin(settings.getWifiSSID(), settings.getWifiPassword());
            MDNS.begin(settings.getDeviceName());
            MDNS.addService("_http", "_tcp", 80);
        }
    }
}

void Network::update()
{
    // Check if WiFi is connected
    if(timer.isOneMinuteElapsed())
    {
        if(!isConnected()) {
            debugW("WiFi not connected, trying to reconnect...");
            init();
        }
    }
}

bool Network::isConnected()
{
    // Check WiFi connection status
    if (WiFi.status() == WL_CONNECTED) {
        //debugI("Network is connected: %s", WiFi.localIP().toString().c_str());
        return true;
    } else {
        debugW("Network not connected");
        return false;
    }
}

#endif