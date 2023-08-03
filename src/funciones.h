int distancia_filtrado = 0;
int adc_raw = 0;
#define alpha 0.03   //Alpha


//Funcion de lectura
long lect_Ultrasonico()
{
    long duracion, distancia;

    /* Hacer el disparo */
    digitalWrite(pinTrig, LOW);
    delayMicroseconds(2);
    digitalWrite(pinTrig, HIGH); // Flanco ascendente
    delayMicroseconds(10);       // Duracion del pulso
    digitalWrite(pinTrig, LOW);  // Flanco descendente

    /* Recepcion del eco de respuesta */
    duracion = pulseIn(pinEcho, HIGH);

    /* Calculo de la distancia efectiva */
    distancia = (duracion / 2) / 29;
    if (distancia > 500)
    {
        distancia = 500;
    }

    adc_raw = distancia;
   distancia_filtrado = (alpha*adc_raw) + ((1-alpha)*distancia_filtrado);
   
    Serial.println(distancia_filtrado);
    return distancia_filtrado;
}

void on()
{
    digitalWrite(pinRele_1, ON);
    delay(500);
    digitalWrite(pinRele_1, OFF);
    delay(500);
}

void off()
{
    digitalWrite(pinRele_2, ON);
    delay(500);
    digitalWrite(pinRele_2, OFF);
    delay(500);
}

int calculoTrimpot(){
    return (analogRead(pinTrimpot)*500)/1023;
}