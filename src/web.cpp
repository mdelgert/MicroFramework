#include "web.h"
#include "globals.h"

#if ENABLE_WEB

#include <WiFi.h>
#include <LittleFS.h>
#include <ArduinoJson.h>

AsyncWebServer server(80);

void Web::notFound(AsyncWebServerRequest *request) {
    request->send(404, "text/plain", "Not found");
}

void Web::init()
{
    // If wifi is not connected, do not start the web server or will cause infinit reboot loop
    if (WiFi.status() != WL_CONNECTED) {
        debugW("WiFi not connected, web server not started.");
        return;
    }

    debugI("Starting web server...");

    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send(200, "text/plain", "{ \"message\": \"Hello, world\" }");
    });

    server.onNotFound(notFound);
    server.begin();
}

#endif