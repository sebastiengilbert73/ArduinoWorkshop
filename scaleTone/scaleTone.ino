#include "/usr/share/doc/arduino-core/examples/02.Digital/toneKeyboard/pitches.h" // Permet d'utiliser les noms des notes (ex.: NOTE_A4) plutot que la fréquence
#include <NewTone.h>

// Note d'une gamme
int scaleNotes[] = {NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5}; // <<<
const int buzzerPin = 8; // La broche connectée au signal du buzzer 
const int buttonPin = 7; // La broche connectée au bouton du joystick

int numberOfButtonPresses = 0; // <<<

void setup() 
{
  pinMode(buzzerPin, OUTPUT); // Déclare la broche connectée au signal du buzzer comme une sortie
  pinMode(buttonPin, INPUT); // Déclare la broche connectée au signal du bouton comme une entrée
}

void loop() 
{
  bool buttonIsPressed = false;
  while (digitalRead(buttonPin) == LOW) // Afin de ne compter l'événement qu'une fois, attends 
  {                                     // que le bouton soit relaché avant de poursuivre
    buttonIsPressed = true;
    delay(1); // Attend 1 ms...
  }
  if (buttonIsPressed)
  {
    int noteIndex = numberOfButtonPresses % 8; // Modulo 8: on aura toujours un nombre compris entre [0, 7]
    NewTone(buzzerPin, scaleNotes[noteIndex], 200); // Joue la note de la gamme pendant 200 ms
    numberOfButtonPresses++; // Incrémente le nombre d'événements de bouton
  }
  
}
