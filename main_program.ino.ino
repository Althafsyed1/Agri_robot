#define BLYNK_TEMPLATE_ID "TMPL3W8pUZFJc"
#define BLYNK_TEMPLATE_NAME "AGRI ROBOT"
#define BLYNK_AUTH_TOKEN "rJI6E5GDFlM1DQtaL8rseDgvElvKGS95"

char auth[] = BLYNK_AUTH_TOKEN;
char ssid [] = "Althafsyed";
char pass [] = "Smart.23";

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include<Servo.h>              //Servo library
Servo servo; 
int angle=0;

 

//BlynkTimer timer;

BLYNK_WRITE(V0)
{
  int value1 = param.asInt();
  if(value1 == 1)
  {
    Serial.println("FORWAD");
    digitalWrite(D5, HIGH);
    digitalWrite(D6, LOW);
    digitalWrite(D7, HIGH);
    digitalWrite(D8, LOW);
 
  }
  else
  {
     Serial.println("STOP");
     digitalWrite(D5, HIGH);
     digitalWrite(D6, HIGH);
     digitalWrite(D7, HIGH);
     digitalWrite(D8, HIGH);
   }
  }
  BLYNK_WRITE(V1)
{
  int value2 = param.asInt();
  if(value2 == 1)
  {
    Serial.println("BACK");
    digitalWrite(D5, LOW);
    digitalWrite(D6, HIGH);
    digitalWrite(D7, LOW);
    digitalWrite(D8, HIGH);
 
  }
  else
  {
   Serial.println("STOP");
   digitalWrite(D5, HIGH);
   digitalWrite(D6, HIGH);
   digitalWrite(D7, HIGH);
   digitalWrite(D8, HIGH);
   }
  }
    BLYNK_WRITE(V2)
{
  int value3 = param.asInt();
  if(value3 == 1)
  {
    Serial.println("RIGHT");
    digitalWrite(D5, HIGH);
    digitalWrite(D6, LOW);
    digitalWrite(D7, LOW);
    digitalWrite(D8, HIGH);
  }
  else
  {
   Serial.println("STOP");
   digitalWrite(D5, HIGH);
   digitalWrite(D6, HIGH);
   digitalWrite(D7, HIGH);
   digitalWrite(D8, HIGH);
   }
  }
  BLYNK_WRITE(V3)
{
  int value4 = param.asInt();
  if(value4 == 1)
  {
    Serial.println("LEFT");
    digitalWrite(D5, LOW);
    digitalWrite(D6, HIGH);
    digitalWrite(D7, HIGH);
    digitalWrite(D8, LOW);
  }
  else
  {
   Serial.println("STOP");
   digitalWrite(D5, HIGH);
   digitalWrite(D6, HIGH);
   digitalWrite(D7, HIGH);
   digitalWrite(D8, HIGH);
   }
  }
 BLYNK_WRITE(V4)
{
  int value4 = param.asInt();
  if(value4 == 1)
  {
    Serial.println("STOP");
    digitalWrite(D1,LOW);
   }
  else
  {
    Serial.println("STOP");
   digitalWrite(D1,HIGH);
      }
  }
void setup(){
  Blynk.begin(auth, ssid, pass);
     servo.attach(D3);
     
     pinMode(D0,OUTPUT);   //buzzer

     pinMode(D1,OUTPUT);
     pinMode(D2,INPUT);
     
     pinMode(D5,OUTPUT);
     pinMode(D6,OUTPUT);
     pinMode(D7,OUTPUT);
     pinMode(D8,OUTPUT);
   Serial.begin(115200);

digitalWrite(D0,HIGH);
delay(700);
digitalWrite(D0,LOW);
delay(700); 
digitalWrite(D0,HIGH);
delay(700);
digitalWrite(D0,LOW);
delay(700); 
digitalWrite(D0,HIGH);
delay(700);
digitalWrite(D0,LOW);
delay(700); 
}

void loop()
{
  Blynk.run();
  int S;
  S=digitalRead(D2);
  if (S==0)            
  { 
    servo.write(50);
    delay(3000);
    servo.write(0);
    delay(3000);                                                    
  }
  else
  {
    servo.write(0);
  }
}
