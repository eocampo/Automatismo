#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
/// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "5beccd0045514ba7acecef46f2556d3c";
// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "DirectoMX";
char pass[] = "qwerty1979";
// defines variables
long duration;
int distance;
int distance2;
BlynkTimer timer;

// This function sends Arduino's up time every second to Virtual Pin (5).
// In the app, Widget's reading frequency should be set to PUSH. This means
// that you define how often to send data to Blynk App.
void myTimerEvent()
{
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V5, distance);
  Blynk.virtualWrite(V6, distance2);


}

// defines pins numbers
const int trigPin = 2;  //D4
const int echoPin = 0;  //D3



void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
//Serial.begin(9600); // Starts the serial communication
// Debug console
Serial.begin(115200);
Blynk.begin(auth, ssid, pass, IPAddress(138,128,124,188),8080);
timer.setInterval(2000L, myTimerEvent);



}

void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

// Calculating the distance
distance= duration*0.034/2;
distance2=(distance/2)+0.5;
// Prints the distance on the Serial Monitor
//Serial.print("Distance: ");
//Serial.println(distance);
//delay(2000);
Blynk.run();
timer.run();
}
