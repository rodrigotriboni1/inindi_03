#include <Arduino.h>
#include "inindThread.h"
#define ledPin 3 // the number of the LED pin
#define analogPin A5
#define LED_INTERVAL 500  // interval at which to blink (milliseconds)
#define ANALOG_INTERVAL 1 // analog read interval (milliseconds)

unsigned long previousMillisLED = 0;    // will store last time LED was updated
unsigned long previousMillisAnalog = 0; // will store last time LED was updated
unsigned long count = 0;

void ledFunc() // Faz a leitura do sinal Analogico
{
  digitalWrite(ledPin, !digitalRead(ledPin));
}

void analogReadFunc() // Faz a leitura do sinal Analogico
{
  count += ANALOG_INTERVAL;
  Serial.print(">amp:");
  Serial.print(count);  
  Serial.print(":");  
  Serial.print(analogRead(analogPin));
  Serial.println("§Volts|g");
}

void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(analogPin, INPUT);
  Serial.begin(115200);
  //threadSetup(ledFunc, LED_INTERVAL, analogReadFunc, ANALOG_INTERVAL, NULL);
}

/* void loop()
{
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillisAnalog >= ANALOG_INTERVAL)
  {
    previousMillisAnalog = currentMillis;
    analogReadFunc();
  }
  if (currentMillis - previousMillisLED >= LED_INTERVAL)
  {
    previousMillisLED = currentMillis;
    ledFunc();
  }
} */

void loop()
{
    count++;
    analogReadFunc();
    ledFunc();
    delay(LED_INTERVAL);
    if(count % 100 == 0) delay(LED_INTERVAL);
}
