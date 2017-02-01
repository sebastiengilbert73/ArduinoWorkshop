#include <NewPing.h>
#include <NewTone.h>

const int sonarTrigPin = 13;
const int sonarEchoPin = 12; 


const int buzzerPin = 8; // La broche connectée au signal du buzzer
const int minFrequency = 30; // La fréquence minimale (en Hz);
const int maxFrequency = 5000; // La fréquence minimale (en Hz);
const int minDistance_cm = 3; // La distance minimale en cm
const int maxDistance_cm = 50; // La distance maximale en cm


NewPing sonar(sonarTrigPin, sonarEchoPin, maxDistance_cm);

void setup() 
{
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() 
{ 
  //delay(50);
  int sonarDistance = sonar.ping_cm();
  Serial.println(sonarDistance);
  // Convertis la distance en une fréquence
  int frequency = map(sonarDistance, minDistance_cm, maxDistance_cm, 
    minFrequency, maxFrequency);
  // Commande au buzzer d'émettre un court son a la fréquence calculée
  NewTone(buzzerPin, frequency, 50);
}
