#include "web.h"
#include "globals.h"

#if ENABLE_WEB

#include <LittleFS.h>
#include <ArduinoJson.h>

AsyncWebServer server(80);

void Web::notFound(AsyncWebServerRequest *request) {
    request->send(404, "text/plain", "Not found");
}

void Web::init()
{
    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send(200, "text/plain", "{ \"message\": \"Hello, world\" }");
    });

    server.onNotFound(notFound);
    server.begin();
}

#endif