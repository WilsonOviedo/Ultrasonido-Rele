#include <Arduino.h>

#define pinEcho 4
#define pinTrig 5
#define pinRele_1 2
#define pinRele_2 3

#define ON LOW
#define OFF HIGH

#define distanciaTrig 75

unsigned long timeSaved=0;

#include "funciones.h"



void setup() {
  pinMode(pinTrig,OUTPUT);
  pinMode(pinEcho,INPUT);
  pinMode(pinRele_1,OUTPUT);
  digitalWrite(pinRele_1,LOW);
  pinMode(pinRele_2,OUTPUT);
  digitalWrite(pinRele_2,LOW);

  timeSaved = millis();
  Serial.begin(9600);
}

void loop() {

  if (lect_Ultrasonico()<distanciaTrig)
  {
    timeSaved=millis();
    on();

  }
 //Serial.println((((millis()-timeSaved)/1000)));

  if (((millis()-timeSaved)/1000)>=25)
  {
    off();
  }
  
  if (timeSaved > millis())
  {
    timeSaved=millis();
  }
  
}