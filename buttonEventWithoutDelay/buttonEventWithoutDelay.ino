// Bouton
int buttonPin = 8;
// Leds
int greenLedPin = 11;
int redLedPin = 10; 

// Parametres de clignotement
int blinkPeriodInMilliseconds = 200;
int numberOfBlinks = 10;

void setup()
{
  // Le bouton est une entrée
  pinMode(buttonPin, INPUT);
  // Les leds sont des sorties
  pinMode(greenLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
  // Prépare le port USB pour envoyer du texte à l'ordinateur, 9600 bauds
  Serial.begin(9600);
  Serial.println("buttonEventWithoutDelay");
}

void loop()
{
  
}
