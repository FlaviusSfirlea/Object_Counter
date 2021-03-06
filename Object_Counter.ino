#include <LiquidCrystal.h>

#define trigPin 9
#define echoPin 8

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
int counter = 0;
int currentState = 0;
int previousState = 0;
int led =10;


void setup (){
 lcd.begin(16,2);
 Serial.begin (9600);
 pinMode(led, OUTPUT);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
}

void loop(){
  long duration,distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  if (distance <= 20) {
    currentState =1;
    digitalWrite(led, LOW);
  }
  else {
    currentState = 0;
    digitalWrite(led, HIGH);
  }
  delay(400);
  if (currentState != previousState){
 if(currentState ==1){
  counter = counter + 1;
  Serial.println(counter);
  lcd.setCursor(0,0);
  lcd.print(counter);
  lcd.print(" Pachete");
  delay(10);
 }
  }
  previousState = currentState;
delay(250);

   
}
  

