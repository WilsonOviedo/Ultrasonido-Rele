#include <Arduino.h>

#define pinEcho 7
//#define pinTrig 8
#define pinRele_1 2
#define pinRele_2 3
#define pinTrimpot A1

#define ON LOW
#define OFF HIGH

#define distanciaTrig 60

unsigned long timeSaved = 0;
long distAnt[3];
int distanciaMax = 0;

bool flag = true;
#include "funciones.h"

void setup()
{
  //pinMode(pinTrig, OUTPUT);
  pinMode(pinEcho, INPUT);
  pinMode(pinRele_1, OUTPUT);
  digitalWrite(pinRele_1, OFF);
  pinMode(pinRele_2, OUTPUT);
  pinMode(LED_BUILTIN,OUTPUT);
  digitalWrite(pinRele_2, OFF);

while (true)
{
  digitalWrite(pinEcho,HIGH);
  delay(1000);
  digitalWrite(pinEcho,LOW);
  delay(1000);
}


  timeSaved = millis();
  Serial.begin(9600);
  lect_Ultrasonico();


}

void loop()
{
  distanciaMax = calculoTrimpot();
  Serial.print("Trig: ");
  Serial.println(distanciaMax);

  if (lect_Ultrasonico() < distanciaMax)
  {
    timeSaved = millis();
    if (flag == true)
    {
      on();
      flag = false;
    }
  }

  if (((millis() - timeSaved) / 1000) >= 25)
  {
    if (flag == false)
    {
      off();
      flag = true;
    }
  }

  if (timeSaved > millis())
  {
    timeSaved = millis();
  }
}
