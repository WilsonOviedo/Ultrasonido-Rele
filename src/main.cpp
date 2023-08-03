#include <Arduino.h>

#define pinEcho 7
#define pinTrig 8
#define pinRele_1 2
#define pinRele_2 3
#define pinTrimpot A1

#define ON HIGH
#define OFF LOW

#define distanciaTrig 60

unsigned long timeSaved = 0;
long distAnt[3];
int distanciaMax = 0;

bool flag = true;
#include "funciones.h"

void setup()
{
  pinMode(pinTrig, OUTPUT);
  pinMode(pinEcho, INPUT);
  pinMode(pinRele_1, OUTPUT);
  digitalWrite(pinRele_1, OFF);
  pinMode(pinRele_2, OUTPUT);
  digitalWrite(pinRele_2, OFF);

  timeSaved = millis();
  Serial.begin(9600);
  lect_Ultrasonico();
}

void loop()
{
  distanciaMax = calculoTrimpot();

  if (lect_Ultrasonico() < distanciaMax)
  {
    timeSaved = millis();
    if (flag == true)
    {
      on();
      flag = false;
    }
  }
  // Serial.println((((millis()-timeSaved)/1000)));

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