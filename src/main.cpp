#include <Arduino.h>

/**
 * @Hardwares: M5AtomS3
 * @Platform Version: Arduino M5Stack Board Manager v2.0.9
 * @Dependent Library:
 * M5GFX: https://github.com/m5stack/M5GFX
 * M5Unified: https://github.com/m5stack/M5Unified
 * M5AtomS3: https://github.com/m5stack/M5AtomS3
 */

#include "M5AtomS3.h"

int button_step = 0;

void setup() {
    auto cfg = M5.config();
    AtomS3.begin(cfg);

    AtomS3.Display.setTextColor(GREEN);
    AtomS3.Display.setTextDatum(middle_center);
    AtomS3.Display.setFont(&fonts::Orbitron_Light_24);
    AtomS3.Display.setTextSize(1);
    AtomS3.Display.drawString("Click!", AtomS3.Display.width() / 2,
                              AtomS3.Display.height() / 2);
    Serial.println("Click BtnA to Test");
}

void loop() {
    AtomS3.update();
    if (AtomS3.BtnA.wasPressed()) {
        AtomS3.Display.clear();
        AtomS3.Display.drawString("Pressed", AtomS3.Display.width() / 2,
                                  AtomS3.Display.height() / 2);
        button_step = button_step + 1;
        if (button_step == 5) button_step = 0;                        
        Serial.println("Pressed");
    }
    if (AtomS3.BtnA.wasReleased()) {
        AtomS3.Display.clear();
        //AtomS3.Display.drawString("Released", AtomS3.Display.width() / 2, AtomS3.Display.height() / 2);
        AtomS3.Display.drawString(String(button_step,DEC), AtomS3.Display.width() / 2,
                                  AtomS3.Display.height() / 2);                                  
        Serial.println("Released");
    }
}
