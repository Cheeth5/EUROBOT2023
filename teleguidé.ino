#include <Servo.h>
#include <PS2X_lib.h>
int clk = 13;
int cmd = 11;
int att = 10;
int dat = 12;
int ad=5;//moteur avant droite
int ag=2;//mouteur avant gauche
int bd=4;//moteur avant droite
int bg=3;
int vit = 70;
bool state=false;
PS2X ps2x;
Servo servo;
Servo servoo;
void Avancer (){
  Serial.println("Avancer");
analogWrite(ad,vit);

analogWrite(ag,vit);

analogWrite(bd,0);

analogWrite(bg,0);}
void stopp () {
    analogWrite(ad,0);

analogWrite(ag,0);

analogWrite(bd,0);

analogWrite(bg,0);
}
void Reculer (){
  Serial.println("Reculer");
  analogWrite(ad,0);

analogWrite(ag,0);

analogWrite(bd,vit);

analogWrite(bg,vit);}
void Gauche (){
  Serial.println("Gauche");
  analogWrite(ad,vit);

analogWrite(ag,0);

analogWrite(bd,0);

analogWrite(bg,vit);}
void Droite (){
  Serial.println("Droite");
  analogWrite(ad,0);

analogWrite(ag,vit);

analogWrite(bd,vit);
analogWrite(bg,0);}


void ouvrir(){
  servo.attach(7);
  servoo.attach(6);
  
  servo.write(85);
  servoo.write(85);
  delay(60);
  servo.write(105);
  servoo.write(105);
  delay(60);
  /*servo.write(120);
  servoo.write(120);*/
  delay(250);
  servo.detach();
  servoo.detach();
}
void setup() {
  
  // put your setup code here, to run once:
Serial.begin(115200);
ps2x.config_gamepad(clk, cmd, att, dat, false, false);
  Serial.println("PS2 controller test sketch");
}
void loop() {
  //put your main code here, to run repeatedly
  ps2x.read_gamepad();
  if((ps2x.Button(PSB_L2))&&(!state)){
  Serial.println("ohio");
  ouvrir();
  state = true;
  //delay(500);
}
else if (!(ps2x.Button(PSB_L2)))
state = false;
  int lx =  ps2x.Analog(PSS_LX);
  int ly =  ps2x.Analog(PSS_LY);
  int rx =  ps2x.Analog(PSS_RX);
  int ry =  ps2x.Analog(PSS_RY);
     Serial.print("Left joystick X: ");
     Serial.println(lx);
     Serial.print("  Left joystick Y: ") ;
     Serial.println (ly);
      Serial.print("Right joystick X: ");
     Serial.println(rx);
     Serial.print(" Right joystick Y: ") ;
     Serial.println (ry);
   
     delay(20);
if (lx < 125) {
  Gauche();   
}
else if (lx > 138) {
  Droite();
}
else if (ly < 126) {
  Avancer();
}
else if (ly > 129){
  Reculer();
  
}
else if (lx == 128 and ly == 127){
  stopp();
}

         

/*#include <PS2X_lib.h>   
PS2X ps2x; 
//right now, the library does NOT support hot-pluggable controllers, meaning 
//you must always either restart your Arduino after you connect the controller, 
//or call config_gamepad(pins) again after connecting the controller.
int error = 0; 
byte type = 0;
byte vibrate = 0;
int trig = 2;
int echo = 3;
int ad=4;//moteur avant droite
int ag=7;//mouteur avant gauche
int bd=5;//moteur avant droite
int bg=6;
long lecture_echo;
long cm;
int  vitesse;
int angle;
int velocity;
int positionn;
String reciveur;
String reciveur2;
int index;

void setup(){
 
pinMode(trig, OUTPUT);
digitalWrite(trig, LOW);
pinMode(ad,OUTPUT);
pinMode(ad,OUTPUT);
pinMode(echo, INPUT);
Serial.begin(9600);
error = ps2x.config_gamepad(13,11,10,12, true, true);   //GamePad(clock, command, attention, data, Pressures?, Rumble?) 
if(error == 0)
{
  Serial.println("Found Controller, configured successful");
  Serial.println("Try out all the buttons, X will vibrate the controller, faster as you press harder;");
  Serial.println("holding L1 or R1 will print out the analog stick values.");
  Serial.println("Go to www.billporter.info for updates and to report bugs.");
}
}

void loop(){

 
digitalWrite(trig, HIGH);
delayMicroseconds(10);
digitalWrite(trig, LOW);
lecture_echo = pulseIn(echo,HIGH);
cm = lecture_echo /58;

delay(15);

if(cm<50){
vitesse=map(cm,1,50,100,60);
  
analogWrite(ag,vitesse);
analogWrite(ad,vitesse);
delay(100);

}
if(cm>50){
  vitesse=0;
    
analogWrite(ag,vitesse);
analogWrite(ad,vitesse);
delay(100);
}


*/
}
