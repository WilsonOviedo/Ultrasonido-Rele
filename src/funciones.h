int distancia_filtrado = 320;

int adc_raw = 0;
//#define alpha 0.015   //Alpha
//#define alpha 1   //Alpha
#define alpha 0.5   //Alpha



//Funcion de lectura
int lect_Sensor()
{
    long duracion=0, distancia=0;
    long resultado=800;

    /* Hacer el disparo */
    //digitalWrite(pinTrig, LOW);
    //delayMicroseconds(2);
    //digitalWrite(pinTrig, HIGH); // Flanco ascendente
    //delayMicroseconds(10);       // Duracion del pulso
    //digitalWrite(pinTrig, LOW);  // Flanco descendente

    /* Recepcion del eco de respuesta */
    for (int i = 0; i < 1; i++)
    {
        duracion = pulseIn(pinEcho, HIGH);
         distancia = (duracion / 2) / 29;
        if (distancia<resultado)
        {
            resultado=distancia;
        }
        
    }
    

    /* Calculo de la distancia efectiva */
    


    adc_raw = resultado;
   //distancia_filtrado = (alpha*adc_raw) + ((1-alpha)*distancia_filtrado);
   distancia_filtrado = distancia;
   
    Serial.print(distancia_filtrado);
    return distancia_filtrado;
}

void on()
{
    digitalWrite(pinRele_1, ON);
    delay(200);
    digitalWrite(pinRele_1, OFF);
    delay(200);
    digitalWrite(LED_BUILTIN,HIGH);
}

void off()
{
    digitalWrite(pinRele_2, ON);
    delay(200);
    digitalWrite(pinRele_2, OFF);
    delay(200);
    digitalWrite(LED_BUILTIN,LOW);
}

int calculoTrimpot(){
    return (analogRead(pinTrimpot)/2);
}