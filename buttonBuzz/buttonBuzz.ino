#include "/usr/share/doc/arduino-core/examples/02.Digital/toneKeyboard/pitches.h" // Permet d'utiliser les noms des notes (ex.: NOTE_A4) plutot que la fréquence
#include <NewTone.h> // Librairie qui permet de commander au buzzer

const int buzzerPin = 8; // La broche connectée au signal du buzzer 
const int buttonPin = 7; // La broche connectée au bouton du joystick

void setup() 
{
  pinMode(buzzerPin, OUTPUT); // Déclare la broche connectée au signal du buzzer comme une sortie
  pinMode(buttonPin, INPUT); // Déclare la broche connectée au signal du bouton comme une entrée
}

void loop() 
{
  while (digitalRead(buttonPin) == LOW)
  {
    NewTone(buzzerPin, NOTE_A4, 20);
  }
  
}
