#include "wifi_manager.h"

// const char* WifiSSID = "CNT_PALADINES";
// const char* WifiPassword = "Javi_07091999";
// const char* WifiSSID = "Telnet_Mia";
// const char* WifiPassword = "07122012";
const char* WifiSSID = "TESIS2.0";
const char* WifiPassword = "12345678@";

void connectWifi()
{
  Serial.println("Connecting to WIFI");
  WiFi.begin(WifiSSID, WifiPassword);
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }

  Serial.println("Wifi Connected");
  Serial.println(WiFi.SSID());
  Serial.println(WiFi.RSSI());
  Serial.println(WiFi.macAddress());
  Serial.println(WiFi.localIP());
  Serial.println(WiFi.gatewayIP());
  Serial.println(WiFi.dnsIP());
}

// void connectWifi() {
//   Serial.println("Connecting to WIFI");

//   // Configuración para WPA2 Enterprise
//   WiFi.disconnect(true);
//   WiFi.mode(WIFI_STA);
//   esp_wifi_sta_wpa2_ent_set_identity((uint8_t *)eap_identity, strlen(eap_identity));
//   esp_wifi_sta_wpa2_ent_set_username((uint8_t *)eap_identity, strlen(eap_identity));
//   esp_wifi_sta_wpa2_ent_set_password((uint8_t *)eap_password, strlen(eap_password));

//   // Habilita WPA2 Enterprise y comienza la conexión
//     esp_wifi_sta_wpa2_ent_enable();
//   WiFi.begin(WifiSSID.c_str());

//   while (WiFi.status() != WL_CONNECTED) {
//     Serial.print(".");
//     delay(500);
//   }

//   Serial.println("Wifi Connected");
//   Serial.println(WiFi.SSID());
//   Serial.println(WiFi.RSSI());
//   Serial.println(WiFi.macAddress());
//   Serial.println(WiFi.localIP());
//   Serial.println(WiFi.gatewayIP());
//   Serial.println(WiFi.dnsIP());
//  }