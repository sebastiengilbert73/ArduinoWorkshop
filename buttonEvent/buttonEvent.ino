
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
  Serial.println("buttonEvent");
}

void loop()
{
  // Vérifie si le bouton a été pressé:
  // Si il a été pressé, digitalRead() retourne LOW.
  // Sinon, digitalRead() retournera HIGH.
  if (digitalRead(buttonPin) == LOW)
  {
    Serial.println("On a cliqué sur le bouton!");
    BlinkLeds(blinkPeriodInMilliseconds, numberOfBlinks);
  }
}

void BlinkLeds(int blinkPeriodInMilliseconds, int numberOfBlinks)
{
  // Boucle: Fais une action un certain nombre de fois
  for (int blinkIndex = 0; blinkIndex < numberOfBlinks; blinkIndex++)
  {
    // blinkIndex prend la valeur 0 au 1er passage dans la boucle,
    // puis 1, puis 2, ... (numberOfBlinks - 1)
    
    // Allume la led verte
    digitalWrite(greenLedPin, HIGH);
    // Attend la moitié d'une période
    delay(blinkPeriodInMilliseconds/2);
    // Éteins la led verte
    digitalWrite(greenLedPin, LOW);
    // Allume la led rouge
    digitalWrite(redLedPin, HIGH);
    // Attend la moitié d'une période
    delay(blinkPeriodInMilliseconds/2);
    // Éteins la led rouge
    digitalWrite(redLedPin, LOW);
  }
}
