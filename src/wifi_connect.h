#include <WiFi.h>
#include <WiFiMulti.h>

const char* ssid = "";
const char* password = "";
void wifiConnect() {
  WiFi.disconnect();
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);  // Wi-Fi接続
  while (WiFi.status() != WL_CONNECTED) {  // Wi-Fi 接続待ち
    delay(100);
    Serial.printf(".");
  }
  Serial.println("\nwifi connect ok");
}