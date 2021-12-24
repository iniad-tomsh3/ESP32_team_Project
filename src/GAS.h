#include <Arduino.h>
#include <HTTPClient.h>
#include <WiFiClientSecure.h>
WiFiClientSecure client;

void GAS_Send(float val1, float val2) {
    HTTPClient http;
    String URL = "https://script.google.com/macros/s/AKfycbxftrqKGNCJMbzxhFCqnj08o-dd_Sg7DkGu-AAbk9g-1RfkqfI8aTdZ5HbAf8NdF4uo/exec?";
    URL+="val1=";
    URL+=(String)val1;

    URL+="&";

    URL+="val2=";
    URL+=(String)val2;
    




    //Serial.println("[HTTP] begin...");
    //Serial.println(URL);
    // access to your Google Sheets
    //Serial.println();
    // configure target server and url
    http.begin(URL);
    Serial.println(URL);
    //Serial.println("[HTTP] GET...");
    // start connection and send HTTP header
    int httpCode = http.GET();

    // httpCode will be negative on error
    if(httpCode > 0) {
        // HTTP header has been send and Server response header has been handled
        //Serial.print("[HTTP] GET... code: ");
        //Serial.println(httpCode);

        // file found at server
        if(httpCode == HTTP_CODE_OK) {
            String payload = http.getString();
            //Serial.println(payload);
        }
    } else {
        Serial.print("[HTTP] GET... failed, error: ");
        Serial.println(http.errorToString(httpCode).c_str());
    }
}
