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
    //Serial.println(distancia);
    return distancia;
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