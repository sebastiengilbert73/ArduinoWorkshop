// Joystick
int joystickYPin = A5;
int joystickYValue = 0;

// Leds
int veryNegativeLedPin = 2;
int moderatelyNegativeLedPin = 3;
int zeroLedPin = 4;
int moderatelyPositiveLedPin = 5;
int veryPositiveLedPin = 6;

void setup()
{
  // Déclare la broche de sortie en Y du joystick comme une entrée
  pinMode(joystickYPin, INPUT);
  // Déclare toutes les broches des leds commme des sorties
  pinMode(veryNegativeLedPin, OUTPUT);
  pinMode(moderatelyNegativeLedPin, OUTPUT);
  pinMode(zeroLedPin, OUTPUT);
  pinMode(moderatelyPositiveLedPin, OUTPUT);
  pinMode(veryPositiveLedPin, OUTPUT);
  
  // Prépare le port USB pour envoyer du texte à l'ordinateur, 9600 bauds
  Serial.begin(9600);
}

void loop()
{
  // Lis la valeur (0 à 1023) du joystick en Y
  joystickYValue = analogRead(joystickYPin);
  // Transforme la valeur [0, 1023] en [0, 4]
  int joystickYValue0to4 = map(joystickYValue, 0, 980, 0, 4);
  String message = String(joystickYValue) + String(" -> ") + String(joystickYValue0to4);
  Serial.println(message);
  
  digitalWrite(veryNegativeLedPin, LOW);
  digitalWrite(moderatelyNegativeLedPin, LOW);
  digitalWrite(zeroLedPin, LOW);
  digitalWrite(moderatelyPositiveLedPin, LOW);
  digitalWrite(veryPositiveLedPin, LOW);
  // Allume la led appropriée
  switch (joystickYValue0to4)
  {
    case 0:
      digitalWrite(veryNegativeLedPin, HIGH);
      break;
     case 1:
      digitalWrite(moderatelyNegativeLedPin, HIGH);
      break;
     case 2:
      digitalWrite(zeroLedPin, HIGH);
      break;
     case 3:
      digitalWrite(moderatelyPositiveLedPin, HIGH);
      break;
     case 4:
      digitalWrite(veryPositiveLedPin, HIGH);
      break;
  }
}
