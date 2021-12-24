#include <Arduino.h>


#include "wifi_connect.h"
#include "GAS.h"
#include "SenserGet.h"
void setup() {
  Serial.begin(115200);
  wifiConnect();
}
void loop() {
  int v=GetSenserval();
  GAS_Send(v,0);
  Serial.println(v);
  delay(200);
}