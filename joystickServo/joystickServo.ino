// Charge la librairie Servo.h qui donne accès aux commandes pour le servo-moteur
#include <Servo.h> // <<<

// Joystick
int joystickYPin = A5;
int joystickYValue = 0;
int joystickXPin = A4; 
int joystickXValue = 0; 

// Led
int greenLedPin = 11;
int redLedPin = 10; 

// Servo-moteur
// Crée un objet Servo, connecté à la broche 9
Servo yServo; // <<<
int yServoPosition = 0; // <<<
int yServoPin = 9; // <<<

void setup()
{
  // Déclare la broche de sortie en Y du joystick comme une entrée
  pinMode(joystickYPin, INPUT);
  // Déclare les broches des leds comme des sorties
  pinMode(greenLedPin, OUTPUT); 
  pinMode(redLedPin, OUTPUT); 
  
  // Déclare les servo-moteurs
  yServo.attach(yServoPin); // <<<
  
  // Prépare le port USB pour envoyer du texte à l'ordinateur, 9600 bauds
  Serial.begin(9600);
}

void loop()
{
  // Lis la valeur (0 à 1023) du joystick en Y
  joystickYValue = analogRead(joystickYPin);
  // Écris la valeur lue dans la console de l'ordinateur
  Serial.println(joystickYValue);
  // Note: la valeur lue par analogRead() va de 0 à 1023. 
  // La valeur acceptée par analogWrite va de 0 à 255.
  // On doit donc diviser la valeur lue par 4 pour donner à analogWrite
  // une valeur dans la fenêtre acceptable.
  analogWrite(greenLedPin, joystickYValue/4); 
  
  joystickXValue = analogRead(joystickXPin); 
  analogWrite(redLedPin, joystickXValue/4); 
  
  // Le servo a besoin d'un angle entre 0 et 180 degrés.
  // Convertis la valeur du joystick [0, 1023] à une valeur
  // d'angle [0, 180]
  yServoPosition = map(joystickYValue, 0, 1023, 0, 180); // <<<
  // Envoie le servo a la position voulue
  yServo.write(yServoPosition); // <<<
}
