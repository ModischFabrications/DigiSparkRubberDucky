#include <Arduino.h>
#include "DigiKeyboard.h"

#define ONBOARD 1

void blink(uint8_t number_of_blinks){
  for (uint8_t i=0; i < number_of_blinks; i++){
    digitalWrite(ONBOARD, HIGH);
    DigiKeyboard.delay(100);
    digitalWrite(ONBOARD, LOW);
    DigiKeyboard.delay(100);
  }
}

// ------------------

void setup() {
  pinMode(ONBOARD, OUTPUT);
  // announce user-program
  blink(5); // ~1 second
  DigiKeyboard.delay(5 * 1000);   // give developer enough time to disconnect this device
}

void loop() {
  digitalWrite(ONBOARD, HIGH);
  DigiKeyboard.sendKeyStroke(KEY_L, MOD_GUI_LEFT);
  digitalWrite(ONBOARD, LOW);
  DigiKeyboard.delay(30 * 1000);   // make sure communication is continued
}
