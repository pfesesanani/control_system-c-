#include<Servo.h>
#include<LiquidCrystal.h>
int left =8;
int right=7;
int acceleration=9;

int engine_power=3;
LiquidCrystal lcd(2, 3, 4, 5, 6, 12);


Servo steer;
Servo air_brakes;
void setup(){
 
  steer.attach(11);

  air_brakes.attach(10);
  pinMode(engine_power,OUTPUT);
pinMode(right,INPUT);
pinMode(left,INPUT);
pinMode(acceleration,INPUT);

Serial.begin(9600);
lcd.begin(16,2);

}
void loop(){
if(digitalRead(right)==HIGH){
  lcd.print("right direction");
  steer.write(0);
}
else if(digitalRead(left)==HIGH){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("left diretion");
  steer.write(180);
}
else if(digitalRead(acceleration)==HIGH){
   lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("moving foward");
  analogWrite(engine_power,200);

}
else if(digitalRead(acceleration)==LOW){
   lcd.clear();
  lcd.setCursor(0,0);
  air_brakes.write(180);
  analogWrite(engine_power,0);
  lcd.print("we are slowing down");
}

}

}
