// This scipt is made by Rodrigo Torres rodrigo@zirian.com
// to make a perfect WIFI connection from the NodeMCU v3
// Using WiFiAutoSelector.h from Andreas Schaefer to determine which Wifi Network has better Signal
// If connection fails, loop keeps trying for the next avaliable WiFi Network (they must be listed)
// Library to use ok
#include <ESP8266WiFi.h>
#include "WiFiAutoSelector.h"
// Timeout for the WiFi connection
#define WIFI_CONNECT_TIMEOUT 8000
WiFiAutoSelector wifiAutoSelector(WIFI_CONNECT_TIMEOUT);
// Start the NodeMCU routine
void setup() {
   Serial.begin(9600);
   wifiAutoSelector.add("DirectoMX", "qwerty1979");
   wifiAutoSelector.add("Invitados", "rodrigo79");
 }
// Start the NodeMCU loop
 void loop() {
   if(WiFi.status() != WL_CONNECTED) {
     Serial.print("Conectando WIFI ");
     if(-1 < wifiAutoSelector.scanAndConnect()) {
       int connectedIndex = wifiAutoSelector.getConnectedIndex();
       Serial.print("a '");
       Serial.print(wifiAutoSelector.getSSID(connectedIndex));
       Serial.println("'. Listo.");
     }else{
       Serial.println("falló.");
     }
   }
   delay(1000);
 }
