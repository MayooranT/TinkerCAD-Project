#define tempPin A1
#define lightPin A0
#define motorPin 13
#include<Servo.h>

Servo Myservo;
int pos;
long Vlight;
long Vtemp;


void setup()
{
  Serial.begin(9600);
  pinMode(tempPin, INPUT);
  pinMode(lightPin, INPUT);
  pinMode(motorPin, OUTPUT);
  Myservo.attach(3);
}

void loop()
{

  //Reading values from sensors.............
  
  Vtemp = analogRead(tempPin);
  Vlight = analogRead(lightPin);
  Serial.print("Value from Temperature : ");
  Serial.print(Vtemp);
  Serial.print("     Value from light : ");
  Serial.print(Vlight);

  //DC Motor................................

  if (Vtemp > 162) digitalWrite(motorPin, HIGH);
  else if (Vtemp <= 162) digitalWrite(motorPin, LOW);
  

  //Servo Motor............................. 
  
  if (Vlight <= 470) {
    if (pos <= 0) {
      for(pos=0;pos<=90;pos++){
        Myservo.write(pos);
        delay(15);
      }
    }
  }
      
  else if (Vlight >= 470) {
    if (pos >= 90) {
        for(pos=90;pos>=0;pos--){
          Myservo.write(pos);
          delay(15);
        }     
    }
  }

  Serial.print("    Postion of servo motor : ");
  Serial.println(pos);
  delay(500);
}
