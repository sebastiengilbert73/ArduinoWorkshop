const int buttonPin = 8; // Le bouton du joystick
const unsigned long maximumTimeInMilliseconds = 5000; // On compte 5 s

int numberOfClicks = 0; // Le nombre de clics
unsigned long delaySinceStartInMilliseconds = 0; // Le temps écoulé depuis le démarrage du microcontroleur
bool timeIsUp = false; // Indique si le temps est écoulé


void setup()
{
  // Déclare la broche du bouton du joystick comme une entrée
  pinMode(buttonPin, INPUT);
  
  // Prépare le port USB pour envoyer du texte à l'ordinateur, 9600 bauds
  Serial.begin(9600);
  Serial.println("setup()");
}

void loop()
{
  delaySinceStartInMilliseconds = millis(); // Nombre de millisecondes écoulées depuis le démarrage du microcontroleur
  if (!timeIsUp) // Si le temps n'est pas encore écoulé...
  {
    // Vérifie si le bouton est enfoncé
    if (digitalRead(buttonPin) == LOW)
    {
      // Ajoute un au compteur
      numberOfClicks++; // On aurait aussi pu écrire numberOfClicks = numberOfClicks + 1;
      // Attends dans une boucle que le bouton soit relaché, afin de ne compter ce clic qu'une seule fois
      while( digitalRead(buttonPin) == LOW )
      {
        delay(1);
      }
    }
    if (delaySinceStartInMilliseconds > maximumTimeInMilliseconds) // Le temps vient d'etre écoulé
    {
      timeIsUp = true;
      // Envoie un message a la console
      Serial.println("Vous avez cliqué " + String(numberOfClicks) + " fois.");    
    }
    
  }

  
}
