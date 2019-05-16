#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
char auth[] = "df52a1ea23e04d4292b3fc528a8652d6";

char ssid[] = "DirectoMX";
char pass[] = "qwerty1979";

BLYNK_WRITE(V0)  // this function is called when a widget, like a button, is pressed
{
  int pinValue = param.asInt();
  Serial.println(pinValue);
}

void setup() {
Serial.begin(9600);
Blynk.begin(auth, ssid, pass, IPAddress(138,128,124,188),8080);
}

void loop() {
Blynk.run();
}
