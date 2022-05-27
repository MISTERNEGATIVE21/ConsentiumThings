#ifndef ConsentiumThings_h
#define ConsentiumThings_h

#include <Arduino.h>  
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>        


class ConsentiumThings{
    public:
        ConsentiumThings();
        void begin();
        void loop_delay(long);
        void initWiFi(const char*, const char*);
        void sendREST(const char*, int, String[], float[], long);       
};

#endif