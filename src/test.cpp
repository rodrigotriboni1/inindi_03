#include <math.h>
#include <Arduino.h>
#include "Teleplot.h"
Teleplot teleplot("127.0.0.1");

void setup() {
    Serial.begin(115200); 
    delay(500);

    
}

void loop() {
    // Send the sine and tangent values to Teleplot
    for (float i = 0; i < 1000; i += 0.1) {
        // Use instantiated object
        teleplot.update("sin", sin(i));
        Teleplot::localhost().update("tan", tan(i));
        
        delay(10);  // delay in milliseconds
    }
}
