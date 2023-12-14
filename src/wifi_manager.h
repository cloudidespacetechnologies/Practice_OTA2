#ifndef WIFI_FUNCTIONS_H
#define WIFI_FUNCTIONS_H

#include <WiFi.h>

// Declaración de las variables externas la red Wi-Fi (SSID) y la contraseña
extern const char* WifiSSID;
extern const char* WifiPassword;

// Credenciales para la conexión WPA2 Enterprise
// const char* eap_identity = "mpaladine5";  // Por lo general, es tu nombre de usuario
// const char* eap_password = "Nacho*07091999"; // Tu contraseña

void connectWifi();

#endif