/*
* CAPÍTULO III: MÓDULOS DE COMUNICACIÓN I2C
* CÓDIGO 13: Envió y recpeción de datos complejos por comunicación I2C
* OBJETIVO: El usuario envía caracteres por comunicación serial, el master lo recibe, y envia por I2C hacia el esclavo y segun el dato
*           enviado enciende un determinado led 
* Nombre: Lizbeth Espinoza
*/

///////////////////////ESCLAVO//////////////////////
#include <Wire.h>               //libreria I2C
char dato;                      //variable de almacenamiento de dato
const int led1=8;               //led1 en pin8
const int led2=9;               //led1 en pin9
const int led3=10;              //led1 en pin10

void setup() {
  Wire.begin(4);                //id de esclavo
  Wire.onReceive(receiveEvent); //evento de rececpcion
  Serial.begin(9600);
  pinMode(led1,OUTPUT);         //pin8 como salida
  pinMode(led2,OUTPUT);         //pin9 como salida
  pinMode(led3,OUTPUT);         //pin10 como salida
}

void loop() {
  
}

void receiveEvent (int bytes){
  while(Wire.available()){
    dato=Wire.read();
    switch(dato){
      case 'A':
      digitalWrite(led1,HIGH);
      digitalWrite(led2,LOW);
      digitalWrite(led3,LOW);
      break;
      case 'B':
      digitalWrite(led1,LOW);
      digitalWrite(led2,HIGH);
      digitalWrite(led3,LOW);
      break;
      case 'C':
      digitalWrite(led1,LOW);
      digitalWrite(led2,LOW);
      digitalWrite(led3,HIGH);
      break;
      default:
      digitalWrite(led1,LOW);
      digitalWrite(led2,LOW);
      digitalWrite(led3,LOW);
    }
  }
}