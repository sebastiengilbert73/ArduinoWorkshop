#include <NewPing.h>

const int sonarTrigPin = 13;
const int sonarEchoPin = 12; 
const int maxDistanceIn_cm = 200;

NewPing sonar(sonarTrigPin, sonarEchoPin, maxDistanceIn_cm);

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{ 
  delay(50);
  int sonarDistance = sonar.ping_cm();
  Serial.println(sonarDistance);
}
