#include "network.h"
#include "globals.h"

#if ENABLE_NETWORK

#include <WiFi.h>
#include <ESPmDNS.h>

void Network::init()
{
    debugI("Initializing WiFi connection...");
    WiFi.disconnect();
    WiFi.mode(WIFI_STA);
    WiFi.setHostname(settings.getDeviceName());
    WiFi.begin(settings.getWifiSSID(), settings.getWifiPassword());

    // Use timer for a 30-second timeout
    while (WiFi.status() != WL_CONNECTED && !timer.isThirtySecondsElapsed()) {
        if (timer.isHalfSecondElapsed()) {
            debugI("Attempting to connect to WiFi...");
        }
    }

    if (WiFi.status() == WL_CONNECTED) {
        debugI("WiFi connected, IP address: %s", WiFi.localIP().toString().c_str());
        if (!MDNS.begin(settings.getDeviceName())) {
            debugE("Error starting mDNS responder!");
        } else {
            debugI("mDNS responder started with hostname: %s.local", settings.getDeviceName());
            MDNS.addService("_http", "_tcp", 80);
        }
    } else {
        debugE("Failed to connect to WiFi within the timeout period.");
    }
}

void Network::update()
{
    // Periodically check WiFi connection status
    if (timer.isOneMinuteElapsed()) {
        if (WiFi.status() != WL_CONNECTED) {
            debugW("WiFi disconnected, attempting to reconnect...");
            init(); // Reuse the init() method for reconnection
        }
    }
}

#endif