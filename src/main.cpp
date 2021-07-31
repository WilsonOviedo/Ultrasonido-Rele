#include <Arduino.h>

#define pinEcho 4
#define pinTrig 5
#define pinRele 2

unsigned long timeSaved=0;



long lect_Ultrasonico()
{
  long duracion, distancia;

  /* Hacer el disparo */
  digitalWrite(pinTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(pinTrig, HIGH); // Flanco ascendente
  delayMicroseconds(10);          // Duracion del pulso
  digitalWrite(pinTrig, LOW);  // Flanco descendente

 
  /* Recepcion del eco de respuesta */
  duracion = pulseIn(pinEcho, HIGH);

  /* Calculo de la distancia efectiva */
  distancia = (duracion / 2) / 29;
  if(distancia>500){
    distancia=500;
  }
Serial.println(distancia);
  return distancia;
}

void setup() {
  pinMode(pinTrig,OUTPUT);
  pinMode(pinEcho,INPUT);
  pinMode(pinRele,OUTPUT);
  digitalWrite(pinRele,LOW);
  timeSaved = millis();
  Serial.begin(9600);
}

void loop() {

  if (lect_Ultrasonico()<75)
  {
    timeSaved=millis();
    digitalWrite(pinRele,HIGH);

  }
 //Serial.println((((millis()-timeSaved)/1000)));

  if (((millis()-timeSaved)/1000)>=25)
  {
    digitalWrite(pinRele,LOW);
  }
  
  if (timeSaved > millis())
  {
    timeSaved=millis();
  }
  
}