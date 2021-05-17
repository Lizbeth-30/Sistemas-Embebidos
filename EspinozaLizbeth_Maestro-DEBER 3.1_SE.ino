/*
* CAPÍTULO III: MÓDULOS DE COMUNICACIÓN I2C
* DEBER 3.1
* CÓDIGO 13: Envió y recpeción de datos complejos por comunicación I2C
* OBJETIVO: Mediante comunicación I2C configurar 1 maestro y 3 esclavos. 
* Cada esclavo tendrá conectados 3 leds en sus salidas digitales, 
* los cuales deberán encenderse de forma síncrona y ordenada. 
* Los leds del primer esclavo deberán entran en funcionamiento cuando se ingrese 'Cualquier caracter', 
* luego cuando se ingrese otro 'Cualquier caracter 2' entrará en funcionamiento el esclavo 2, y después 
* cuando se ingrese otro 'Cualquier caracter 3' entrará en funcionamiento el esclavo 3. 
* Nombre: Lizbeth Espinoza
*/

///////////////////////MASTER//////////////////////

#include <Wire.h>               //libreria I2C

char dato;                      //variable de almacenanmiento de datos

void setup() {
  Wire.begin();                 //inicia comunicación I2C
  Serial.begin(9600);           //inicia comunicación serial
}

void loop() {
  if(Serial.available()>0){     //verifica que exista datos
    dato=Serial.read();         //almacena el dato en la variable
    Wire.beginTransmission(1);  //empieza la comunicación I2C
    Wire.write(dato);           //envio dato
    Wire.endTransmission();     //termina la comunicación I2C
  } 
    if(Serial.available()>0){     //verifica que exista datos
    dato=Serial.read();         //almacena el dato en la variable
    Wire.beginTransmission(2);  //empieza la comunicación I2C
    Wire.write(dato);           //envio dato
    Wire.endTransmission();     //termina la comunicación I2C
  } 
   if(Serial.available()>0){     //verifica que exista datos
    dato=Serial.read();         //almacena el dato en la variable
    Wire.beginTransmission(3);  //empieza la comunicación I2C
    Wire.write(dato);           //envio dato
    Wire.endTransmission();     //termina la comunicación I2C
  } 

}
