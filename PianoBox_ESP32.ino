/*
 * Project : PianoBox
 * Made by : izma_eknom
 * Started : ??/3~4/2022
 * Redone : 28/06/2022
 * Finished : -/-/-
 * Quick descrption :
 *  This is a recreation of a small piano with 8 keys,
 *  a potentiometer that controls the pitch and a located
 *  next to the potentiometer made for right-handed people.
*/

#include "pitches.h"
#include "ESP32Tone.h"

int potentiometerVar = 0;

int pins[] = {36, 39, 34, 35, 32, 33, 25, 26, 14, 15, 22};

int keyTones[] = {NOTE_A2, NOTE_B2, NOTE_C3, NOTE_D3, NOTE_E3, 
                  NOTE_F3, NOTE_G3, NOTE_A3, NOTE_B3, NOTE_C4, 
                  NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, 
                  NOTE_B4, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, 
                  NOTE_G5, NOTE_A5, NOTE_B5, NOTE_C6, NOTE_D6, 
                  NOTE_E6, NOTE_F6, NOTE_G6, NOTE_A6, NOTE_B6, 
                  NOTE_C7, NOTE_D7, NOTE_E7, NOTE_F7, NOTE_G7, 
                  NOTE_A7 ,NOTE_B7 ,NOTE_C8, NOTE_D8}; 

bool all_pins_zero() {
  int sum = 0;
  for (int j = 0; j < 8; j++) {
    if (digitalRead(pins[j]) == LOW) {
      sum += 1;
    } else {
      sum += 0;
      break;
    }
  }
  if (sum == 8) {
    return true;
  } else {
    return false;
  }
}

void setup() {
  Serial.begin(9600);

  pinMode(16, OUTPUT);

  for (int i = 0; i < 10; i++) {
    pinMode(pins[i], INPUT);
  }
}

void loop() {

  potentiometerVar = analogRead(pins[9]);

  potentiometerVar = map(potentiometerVar, 0, 4095, 0, 6);
  
  for (int i = 0; i < 8; i++) {
     if (digitalRead(pins[i]) == HIGH) {
      tone(16, keyTones[i + potentiometerVar]);
    } else if (all_pins_zero() == true) {
      noTone(16);
    }
  }

}
