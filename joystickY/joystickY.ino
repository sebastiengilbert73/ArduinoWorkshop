int joystickYPin = A5;
int joystickYValue = 0;

void setup()
{
  // Déclare la broche de sortie en Y du joystick comme une entrée
  pinMode(joystickYPin, INPUT);
  // Prépare le port USB pour envoyer du texte à l'ordinateur, 9600 bauds
  Serial.begin(9600);
}

void loop()
{
  // Lis la valeur (0 à 1023) du joystick en Y
  joystickYValue = analogRead(joystickYPin);
  // Écris la valeur lue dans la console de l'ordinateur
  Serial.println(joystickYValue);
}
