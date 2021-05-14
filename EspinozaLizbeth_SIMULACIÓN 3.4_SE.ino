/*
* CAPÍTULO III: MÓDULOS DE COMUNICACIÓN I2C
* CÓDIGO 13: Envió y recpeción de datos complejos por comunicación I2C
* OBJETIVO: El usuario envía caracteres por comunicación serial, el master lo recibe, y envia por I2C hacia el esclavo y segun el dato
*           enviado enciende un determinado led 
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
    Wire.beginTransmission(4);  //empieza la comunicación I2C
    Wire.write(dato);           //envio dato
    Wire.endTransmission();     //termina la comunicación I2C
  } 

}
