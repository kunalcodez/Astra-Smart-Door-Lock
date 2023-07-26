 
//Astra Secure
#define BLYNK_PRINT Serial
#include <gpio.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <WiFiClientSecure.h>

//Wifi & Blynk Auth
 
char auth[] = "_n-PyGiV_7Olapf5S2SqG1PBFaAJcLrG";
char ssid[] = "Astrasecure";
char pass[] = "6uo4Lrxg6*pj";


BLYNK_WRITE(V1)
{
  int value = param.asInt();
  Serial.println(value);
  if(value == 1) // Device ON Unlock
  {
    digitalWrite(D0, LOW); 
    Serial.println("LED ON"); //Setting Digital PIN as LOW to turn ON Device if relay module is "active low"
  }
  if(value == 0) // Device OFF Lock
  {
     digitalWrite(D0, HIGH);
     Serial.println("LED OFF");//Setting Digital PIN as HIGH to turn OFF Device if relay module is "active low" 
  }
}
 
BLYNK_WRITE(V2)
{
  int value = param.asInt();
  Serial.println(value);
  if(value == 1)
  {
    digitalWrite(D1, LOW);
    Serial.println("LED ON");
  }
  if(value == 0)
  {
     digitalWrite(D1, HIGH);  
     Serial.println("LED OFF");
  }
}
 
BLYNK_WRITE(V3)
{
  int value = param.asInt();
  Serial.println(value);
  if(value == 1)
  {
    digitalWrite(D2, LOW);
    Serial.println("LED ON");
  }
  if(value == 0)
  {
     digitalWrite(D2, HIGH);
     Serial.println("LED OFF");
  }
}
 
BLYNK_WRITE(V4)
{
  int value = param.asInt();
  Serial.println(value);
  if(value == 1)
  {
    digitalWrite(D3, LOW);
    Serial.println("LED ON");
  }
  if(value == 0)
  {
     digitalWrite(D3, HIGH);
     Serial.println("LED OFF");
  }
}
 
 
void setup()
{
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  pinMode(D0,OUTPUT);        //GPIO 16 (equivalent to PIN 16 of Arduino)
  pinMode(D1,OUTPUT);          //GPIO 05 (equivalent to PIN 05 of Arduino)
  pinMode(D2,OUTPUT);          //GPIO 04 (equivalent to PIN 16 of Arduino)
  pinMode(D3,OUTPUT);          //GPIO 00 (equivalent to PIN 00 of Arduino)
}
 
void loop()
{
  Blynk.run();
}