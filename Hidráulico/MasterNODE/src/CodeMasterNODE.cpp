#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "5beccd0045514ba7acecef46f2556d3c";

char ssid[] = "DirectoMX";
char pass[] = "qwerty1979";

long durationMS;
int returnCM;
int distanceCM;
const int trigPin = 4;  // Tigger va en Puerto D2
const int echoPin = 5;  // Echo va en Puerto D1
BlynkTimer timer;
// This function sends Arduino's up time every second to Virtual Pin (5).
// In the app, Widget's reading frequency should be set to PUSH. This means
// that you define how often to send data to Blynk App.
void myTimerEvent()
{
  // You can send any value at any time.
  Blynk.virtualWrite(V5, distanceCM);
  Serial.print("Distancia: ");
  Serial.println(distanceCM);
}

void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT_PULLUP); // Sets the echoPin as an Input
//Serial.begin(9600); // Starts the serial communication
// Debug console
Serial.begin(9600);
Blynk.begin(auth, ssid, pass, IPAddress(138,128,124,188),8080);
timer.setInterval(2000L, myTimerEvent);
delay(6000); // Pausa antes de sensar

}

void loop() {

distanceCM = 0;
durationMS = 0;
// Clear the trigger pin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigger on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// wait for the echo
durationMS = pulseIn(echoPin, HIGH);
// Calculating the distance
distanceCM = (((int) durationMS * 0.034) / 2);
// Pause between soundings at least60 ms
delay(1000);
// End of Main Loop
Blynk.run();
timer.run();
}
