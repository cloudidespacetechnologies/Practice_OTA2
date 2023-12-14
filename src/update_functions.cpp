#include <ArduinoJson.h>
#include <HTTPClient.h>
#include <ESP32httpUpdate.h>
#include "wifi_manager.h"
#include "update_manager.h"

void checkUpdate()
{

    Serial.println("Checking Update");
    HTTPClient http;
    String response;
    String url = updateUrl;
    http.begin(url);
    http.GET();

    response = http.getString();
    Serial.println(response);

    StaticJsonDocument<1024> doc;
    deserializeJson(doc, response);
    JsonObject obj = doc.as<JsonObject>();

    String version = obj[String("version")];
    String url_update = obj[String("url")];

    Serial.println(version);
    Serial.println(url_update);

    if (version.toDouble() != firmwareVersion)
    {

        Serial.println("Update Available");
        if (updateFirmware(url_update) == HTTP_UPDATE_OK)
        {
            Serial.println("Updated Success");
            if (isBlinkingTaskRunning)
            {
                Serial.println("Deleting blinking task...");
                vTaskDelete(task0);
                Serial.println("Blinking task deleted.");
            }
            ESP.restart();
        }

        Serial.println("Update Failed");
    }
    else
    {
        Serial.println("Latest version already installed");
    }
}

t_httpUpdate_return updateFirmware(String url_update)
{
    t_httpUpdate_return ret;

    if (WiFi.status() == WL_CONNECTED)
    {
        ret = ESPhttpUpdate.update(url_update);
        switch (ret)
        {
        case HTTP_UPDATE_FAILED:
            Serial.printf("[Update] Update failed.Error (%d): %s\n", ESPhttpUpdate.getLastError(), ESPhttpUpdate.getLastErrorString().c_str());

            return ret;
            break;

        case HTTP_UPDATE_NO_UPDATES:
            Serial.println("[Update] Update No updates");

            return ret;
            break;

        case HTTP_UPDATE_OK:
            Serial.println("[Update] Update OK");

            return ret;
            break;
        }
    }
    Serial.println("[Update] No entró al if ni al switch.");

    return HTTP_UPDATE_FAILED;
}