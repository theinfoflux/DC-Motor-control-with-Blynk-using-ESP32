#define BLYNK_PRINT Serial

#define BLYNK_TEMPLATE_ID "TMPL6kBHSRfJC"
#define BLYNK_TEMPLATE_NAME "DC motor control"
#define BLYNK_AUTH_TOKEN "8DLyurd86BtRAn9En0A-kB3S4TfM5xDG"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char auth[] = BLYNK_AUTH_TOKEN;

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "theinfoflux";
char pass[] = "12345678";

int Speed_Pin ; 
//Motor Driver Pins
const int IN1 = 2;
const int IN2 = 4;
const int ENA = 22;
 
void setup ()  
{
Serial.begin(115200);
  // Motor
  pinMode(IN1, OUTPUT);  // Set the pin as OUTPUT 
  pinMode(IN2, OUTPUT);  // Set the pin as OUTPUT 
  pinMode(ENA, OUTPUT);  
    Blynk.begin(auth, ssid, pass);

}  
void loop ()  
{
   Blynk.run();
 
}

BLYNK_WRITE(V0)
{
  int pinValue1=param.asInt();
if (pinValue1==HIGH)
{
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
  }
  if (pinValue1==LOW)
{
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
  }
 }

 
 BLYNK_WRITE(V1)
{
  int pinValue2=param.asInt();
if (pinValue2==HIGH)
{
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
  }
  if (pinValue2==LOW)
{
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
  }
  }

BLYNK_WRITE(V3)
{
 int Motor_Speed=param.asInt();
 Serial.println(Motor_Speed);
 analogWrite(ENA, Motor_Speed); //PWM Signal to control the speed of motor. (0 - 255)
  }

  BLYNK_WRITE(V2)
{
  int pinValue3=param.asInt();
  if(pinValue3==HIGH){
   digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
  }
}
