#include <Arduino.h>
#include "InIndKit.h"

void setup()
{
    InIndKit.setup("Wokwi-GUEST", "", "inindkit10");
}

void loop()
{
    InIndKit.loop();
}