// Pin definitions
#include <Servo.h>
#define LEFT_MOTOR_PIN1 2
#define LEFT_MOTOR_PIN2 3
#define RIGHT_MOTOR_PIN1 4
#define RIGHT_MOTOR_PIN2 5
#define SWITCH_PIN A1
#define Jack A3
Servo servo1;
Servo servo2;
void cerise () {
  servo2.attach(7);
  servo1.attach(6);
  servo2.write(90);
  servo1.write(90);
  delay(1000);
  servo1.write(160);
  servo2.write(160);
  delay(1000);
  servo2.detach();
  servo1.detach();
  
}
void Avancer () {
  digitalWrite(LEFT_MOTOR_PIN1, HIGH);
  digitalWrite(LEFT_MOTOR_PIN2, LOW);
  digitalWrite(RIGHT_MOTOR_PIN1, HIGH);
  digitalWrite(RIGHT_MOTOR_PIN2, LOW);   
}
void Reculer () {
  digitalWrite(LEFT_MOTOR_PIN1, LOW);
  digitalWrite(LEFT_MOTOR_PIN2, HIGH);
  digitalWrite(RIGHT_MOTOR_PIN1, LOW);
  digitalWrite(RIGHT_MOTOR_PIN2, HIGH); 
}
void Gauche () { 
  digitalWrite(LEFT_MOTOR_PIN1, LOW);
  digitalWrite(LEFT_MOTOR_PIN2, HIGH);
  digitalWrite(RIGHT_MOTOR_PIN1, HIGH);
  digitalWrite(RIGHT_MOTOR_PIN2, LOW); 
}
void stop () {
  digitalWrite(LEFT_MOTOR_PIN1, LOW);
  digitalWrite(LEFT_MOTOR_PIN2, LOW);
  digitalWrite(RIGHT_MOTOR_PIN1, LOW);
  digitalWrite(RIGHT_MOTOR_PIN2, LOW);
  
  
}
void Droite () {
    digitalWrite(LEFT_MOTOR_PIN1, HIGH);
    digitalWrite(LEFT_MOTOR_PIN2, LOW);
    digitalWrite(RIGHT_MOTOR_PIN1, LOW);
    digitalWrite(RIGHT_MOTOR_PIN2, HIGH);
} 
void setup() {
  // Set up motor pins as outputs
  pinMode(LEFT_MOTOR_PIN1, OUTPUT);
  pinMode(LEFT_MOTOR_PIN2, OUTPUT);
  pinMode(RIGHT_MOTOR_PIN1, OUTPUT);
  pinMode(RIGHT_MOTOR_PIN2, OUTPUT);
  pinMode(SWITCH_PIN, INPUT_PULLUP);
  pinMode(Jack,INPUT);
}
 
void loop() {
  int jackState = digitalRead(Jack);
  int switchState = digitalRead(SWITCH_PIN);
  while (jackState == HIGH) {
   if (switchState == HIGH) {
    Gauche();
    delay(2000);
    Reculer();
    delay(2000);
    Droite();
    delay(2000);
    cerise();
    delay(1000);
  } else {
   Droite();
   delay(2000);
   Reculer();
   delay(2000);
   Gauche();
   delay(2000);
   cerise();
   delay(1000);
  }
  delay (1000);

  stop();
}

