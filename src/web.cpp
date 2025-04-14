#include "web.h"
#include "globals.h"

#if ENABLE_WEB

#include <WiFi.h>
#include <LittleFS.h>
#include <ArduinoJson.h>

AsyncWebServer server(80);

// simple digest authentication
static AsyncAuthenticationMiddleware digestAuth;
static AsyncAuthenticationMiddleware digestAuthHash;

void Web::notFound(AsyncWebServerRequest *request)
{
    request->send(404, "text/plain", "Not found");
}

void Web::registerFileServer()
{
    server.serveStatic("/", LittleFS, "/").setDefaultFile("index.html");
}

void Web::init()
{
    // If WiFi is not connected, do not start the web server to avoid issues
    if (WiFi.status() != WL_CONNECTED)
    {
        debugW("WiFi not connected, web server not started.");
        return;
    }
    
    // digest authentication with hash u: admin p: admin
    digestAuthHash.setUsername("admin");
    digestAuthHash.setPasswordHash("529a66ca1e2c4a9575ddde002b645acd"); // MD5(user:realm:pass)
    digestAuthHash.setRealm("microframework");
    digestAuthHash.setAuthFailureMessage("Authentication failed");
    digestAuthHash.setAuthType(AsyncAuthType::AUTH_DIGEST);

    debugI("Starting web server.");

    registerSettingsEndpoint();
    registerFileServer();
    registerSecureEndpoint();

    server.onNotFound(notFound);
    server.begin();

    debugI("Web server started.");
}

void Web::registerSettingsEndpoint()
{
    server.on("/settings", HTTP_GET, [](AsyncWebServerRequest *request){
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
        request->send(200, "application/json", jsonResponse); });
}

void Web::registerSecureEndpoint()
{
    // digest authentication with hash curl -v -u admin:admin --digest  http://192.168.4.1/secure
    server.on("/secure", HTTP_GET, [](AsyncWebServerRequest *request)
              { request->send(200, "text/plain", "Secure accessed!"); })
        .addMiddleware(&digestAuthHash);
}

#endif

/*
server.on("/secure", HTTP_GET, [](AsyncWebServerRequest *request){
    if (!request->authenticate("admin", "password")) {
        return request->requestAuthentication();
    }
    request->send(200, "text/plain", "Secure endpoint accessed"); });
*/