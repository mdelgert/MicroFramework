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
    // If WiFi is not connected, do not start the web server to avoid issues
    if (WiFi.status() != WL_CONNECTED) {
        debugW("WiFi not connected, web server not started.");
        return;
    }

    debugI("Starting web server...");
    registerSettingsEndpoint();
    registerFileServer();
    //registerRootEndpoint();
    server.onNotFound(notFound);
    server.begin();
    debugI("Web server started.");
}

void Web::registerSettingsEndpoint()
{
    server.on("/settings", HTTP_GET, [](AsyncWebServerRequest *request) {
        JsonDocument doc;

        // Populate JSON with settings values
        doc["deviceName"] = Settings::getDeviceName();
        doc["devicePassword"] = Settings::getDevicePassword();
        doc["timezone"] = Settings::getTimezone();
        doc["wifiSSID"] = Settings::getWifiSSID();
        doc["mqttServer"] = Settings::getMqttServer();
        doc["mqttUsername"] = Settings::getMqttUsername();
        doc["mqttPubTopic"] = Settings::getMqttPubTopic();
        doc["mqttSubTopic"] = Settings::getMqttSubTopic();
        doc["mqttPort"] = Settings::getMqttPort();

        // Serialize JSON to a string
        String jsonResponse;

        //serializeJson(doc, jsonResponse);
        serializeJsonPretty(doc, jsonResponse);

        // Send JSON response
        request->send(200, "application/json", jsonResponse);
    });
}

void Web::registerFileServer()
{
    // Serve files from LittleFS at the root path
    server.serveStatic("/", LittleFS, "/").setDefaultFile("index.html");
    //server.serveStatic("/", LittleFS, "/www").setDefaultFile("index.html");
}

/*
void Web::registerRootEndpoint()
{
    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
        request->send(200, "text/plain", "{ \"message\": \"Hello, world\" }");
    });
}
*/
#endif