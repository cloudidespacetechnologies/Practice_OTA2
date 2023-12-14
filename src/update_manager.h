#ifndef UPDATE_MANAGER_H
#define UPDATE_MANAGER_H

#include <ArduinoJson.h>
#include <HTTPClient.h>
#include <ESP32httpUpdate.h>
#include "wifi_manager.h"

extern const double firmwareVersion;
extern const char* updateUrl;

extern TaskHandle_t task0;
extern bool isBlinkingTaskRunning;

void checkUpdate();
void NameTask(void *pvParameters);
t_httpUpdate_return updateFirmware(String url_update);

#endif