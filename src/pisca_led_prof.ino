#include <Arduino.h>
#define ledPin 3                   // the number of the LED pin
#define analogPin A5 

unsigned long previousMillis = 0;  // will store last time LED was updated
const long interval = 500;         // interval at which to blink (milliseconds)

void ledFunc()                     // Faz a leitura do sinal Analogico
{ 
  digitalWrite(ledPin,!digitalRead(ledPin));
}

void analogReadFunc()              // Faz a leitura do sinal Analogico
{ 
  unsigned int amplitude = (unsigned int)(1000.0*((float)analogRead(analogPin))/1023.0);
  Serial.println(amplitude);
}

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(analogPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  unsigned long currentMillis = millis();
  analogReadFunc();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    ledFunc();
  }
}
