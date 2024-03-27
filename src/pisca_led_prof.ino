#include <Arduino.h>
#define NUMTHREADS 2 //Deve-se sempre declarar o NUMTHREADS antes de "inindThread.h"
#include "inindThread.h"

unsigned long count = 0;

#define LEDPIN 3 // the number of the LED pin
#define LED_INTERVAL 500  // interval at which to blink (milliseconds)
void ledFunc() // Faz a leitura do sinal Analogico
{
  digitalWrite(LEDPIN, !digitalRead(LEDPIN));
}

#define ANALOGPIN A5
#define ANALOG_INTERVAL 1 // analog read interval (milliseconds)
void analogReadFunc() // Faz a leitura do sinal Analogico
{
  count += ANALOG_INTERVAL;
  Serial.print(">amp:");
  Serial.print(count);  
  Serial.print(":");  
  Serial.print(analogRead(ANALOGPIN));
  Serial.println("§Volts|g");
}

void setup()
{
  pinMode(LEDPIN, OUTPUT);
  pinMode(ANALOGPIN, INPUT);
  Serial.begin(115200);
  threadSetup(ledFunc, LED_INTERVAL, analogReadFunc, ANALOG_INTERVAL);
}

void loop() {}

