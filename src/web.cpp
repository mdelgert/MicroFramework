#include "web.h"
#include "globals.h"

#if ENABLE_WEB

#include <WiFi.h>
#include <LittleFS.h>
#include <ArduinoJson.h>

AsyncWebServer server(80);

// Simple session storage (in-memory, not persistent across reboots)
struct Session {
    String sessionId;
    bool isAuthenticated;
};
static Session sessions[10]; // Support up to 10 concurrent sessions
static int sessionCount = 0;

// Generate a simple session ID (for demo purposes)
String generateSessionId() {
    String id = "";
    for (int i = 0; i < 16; i++) {
        id += (char)random(65, 90); // Random chars A-Z
    }
    return id;
}

// Check if session is valid
bool isSessionValid(String sessionId) {
    for (int i = 0; i < sessionCount; i++) {
        if (sessions[i].sessionId == sessionId && sessions[i].isAuthenticated) {
            return true;
        }
    }
    return false;
}

void Web::notFound(AsyncWebServerRequest *request) {
    request->send(404, "text/plain", "Not found");
}

void Web::registerFileServer() {
    server.serveStatic("/", LittleFS, "/").setDefaultFile("index.html");
}

void Web::init() {
    if (WiFi.status() != WL_CONNECTED) {
        debugW("WiFi not connected, web server not started.");
        return;
    }

    debugI("Starting web server.");

    registerSettingsEndpoint();
    registerFileServer();
    registerAuthEndpoints();
    registerSecureEndpoint();

    server.onNotFound(notFound);
    server.begin();

    debugI("Web server started.");
}

void Web::registerSettingsEndpoint() {
    server.on("/settings", HTTP_GET, [](AsyncWebServerRequest *request) {
        JsonDocument doc;
        doc["deviceName"] = Settings::getDeviceName();
        doc["devicePassword"] = Settings::getDevicePassword();
        doc["timezone"] = Settings::getTimezone();
        doc["wifiSSID"] = Settings::getWifiSSID();
        doc["mqttServer"] = Settings::getMqttServer();
        doc["mqttUsername"] = Settings::getMqttUsername();
        doc["mqttPubTopic"] = Settings::getMqttPubTopic();
        doc["mqttSubTopic"] = Settings::getMqttSubTopic();
        doc["mqttPort"] = Settings::getMqttPort();

        String jsonResponse;
        serializeJsonPretty(doc, jsonResponse);
        request->send(200, "application/json", jsonResponse);
    });
}

void Web::registerAuthEndpoints() {
    // Serve login page
    server.on("/login", HTTP_GET, [](AsyncWebServerRequest *request) {
        if (LittleFS.exists("/login.html")) {
            request->send(LittleFS, "/login.html", "text/html");
        } else {
            String html = "<html><body><h2>Login</h2>";
            html += "<form action='/login' method='POST'>";
            html += "Username: <input type='text' name='username'><br>";
            html += "Password: <input type='password' name='password'><br>";
            html += "<input type='submit' value='Login'>";
            html += "</form></body></html>";
            request->send(200, "text/html", html);
        }
    });

    // Handle login POST request
    server.on("/login", HTTP_POST, [](AsyncWebServerRequest *request) {
        if (request->hasParam("username", true) && request->hasParam("password", true)) {
            String username = request->getParam("username", true)->value();
            String password = request->getParam("password", true)->value();

            // Hardcoded credentials for simplicity (replace with secure storage)
            if (username == "admin" && password == "admin") {
                String sessionId = generateSessionId();
                if (sessionCount < 10) {
                    sessions[sessionCount].sessionId = sessionId;
                    sessions[sessionCount].isAuthenticated = true;
                    sessionCount++;
                }
                AsyncWebServerResponse *response = request->beginResponse(302);
                response->addHeader("Location", "/secure");
                response->addHeader("Set-Cookie", "sessionId=" + sessionId);
                request->send(response);
            } else {
                request->send(401, "text/plain", "Invalid credentials");
            }
        } else {
            request->send(400, "text/plain", "Missing credentials");
        }
    });

    // Logout endpoint
    server.on("/logout", HTTP_GET, [](AsyncWebServerRequest *request) {
        if (request->hasHeader("Cookie")) {
            String cookie = request->getHeader("Cookie")->value();
            String sessionId = cookie.substring(cookie.indexOf("sessionId=") + 10);
            for (int i = 0; i < sessionCount; i++) {
                if (sessions[i].sessionId == sessionId) {
                    sessions[i].isAuthenticated = false;
                    // Shift sessions to remove
                    for (int j = i; j < sessionCount - 1; j++) {
                        sessions[j] = sessions[j + 1];
                    }
                    sessionCount--;
                    break;
                }
            }
        }
        AsyncWebServerResponse *response = request->beginResponse(302);
        response->addHeader("Location", "/login");
        response->addHeader("Set-Cookie", "sessionId=; expires=Thu, 01 Jan 1970 00:00:00 GMT");
        request->send(response);
    });
}

void Web::registerSecureEndpoint() {
    server.on("/secure", HTTP_GET, [](AsyncWebServerRequest *request) {
        // Check for session cookie
        if (request->hasHeader("Cookie")) {
            String cookie = request->getHeader("Cookie")->value();
            String sessionId = cookie.substring(cookie.indexOf("sessionId=") + 10);
            if (isSessionValid(sessionId)) {
                request->send(200, "text/plain", "Secure accessed!");
                return;
            }
        }
        // Redirect to login if not authenticated
        AsyncWebServerResponse *response = request->beginResponse(302);
        response->addHeader("Location", "/login");
        request->send(response);
    });
}

#endif

/*

void Web::registerFileServer() {
    // Custom handler for all paths to serve LittleFS files with authentication
    server.on("/*", HTTP_GET, [](AsyncWebServerRequest *request) {
        // Allow /login without authentication
        if (request->url() == "/login") {
            request->redirect("/login"); // Redirect to login endpoint
            return;
        }

        // Check for session cookie
        if (request->hasHeader("Cookie")) {
            String cookie = request->getHeader("Cookie")->value();
            String sessionId = cookie.substring(cookie.indexOf("sessionId=") + 10);
            if (isSessionValid(sessionId)) {
                // Serve file from LittleFS
                String path = request->url();
                if (path == "/") {
                    path = "/index.html"; // Default file
                }
                if (LittleFS.exists(path)) {
                    String contentType = "text/plain"; // Default
                    if (path.endsWith(".html")) contentType = "text/html";
                    else if (path.endsWith(".css")) contentType = "text/css";
                    else if (path.endsWith(".js")) contentType = "application/javascript";
                    else if (path.endsWith(".png")) contentType = "image/png";
                    else if (path.endsWith(".jpg")) contentType = "image/jpeg";
                    else if (path.endsWith(".txt")) contentType = "text/plain";
                    else if (path.endsWith(".json")) contentType = "application/json";
                    request->send(LittleFS, path, contentType);
                    return;
                }
            }
        }

        // Redirect to login if not authenticated or file not found
        AsyncWebServerResponse *response = request->beginResponse(302);
        response->addHeader("Location", "/login");
        request->send(response);
    });
}

void Web::registerSecureEndpoint()
{
    // digest authentication with hash curl -v -u admin:admin --digest  http://192.168.4.1/secure
    server.on("/secure", HTTP_GET, [](AsyncWebServerRequest *request)
              { request->send(200, "text/plain", "Secure accessed!"); })
        .addMiddleware(&digestAuthHash);
}
        
server.on("/secure", HTTP_GET, [](AsyncWebServerRequest *request){
    if (!request->authenticate("admin", "password")) {
        return request->requestAuthentication();
    }
    request->send(200, "text/plain", "Secure endpoint accessed"); });
*/