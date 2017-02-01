const int buttonPin = 8;
const int redLedPin = 13;
const int yellowLedPin = 12;
const int greenLedPin  = 7;

int state = 0;

void setup()
{
  pinMode(buttonPin, INPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(yellowLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  
  digitalWrite(greenLedPin, HIGH);
}

void loop()
{
  if (digitalRead(buttonPin) == LOW)
  {
    
    if (state == 0)
    {
      digitalWrite(greenLedPin, LOW); // Éteins la led verte
      digitalWrite(yellowLedPin, HIGH); // Allume la led jaune
      state = 1; // Change d'état
    }
    else if (state == 1)
    {
      digitalWrite(yellowLedPin, LOW); // Éteins la led jaune
      digitalWrite(redLedPin, HIGH); // Allume la led rouge
      state = 2; // Change d'état
    }
    else
    {
      digitalWrite(redLedPin, LOW); // Étiens la led rouge
      digitalWrite(greenLedPin, HIGH); // Allume la led verte
      state = 0; // Change d'état
    }
    
    while (digitalRead(buttonPin) == LOW) // Attends que le bouton soit relaché avant de continuer a boucler
    {
      delay(1); 
    }
  }
}
