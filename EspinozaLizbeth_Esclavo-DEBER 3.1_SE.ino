///////////////////////ESCLAVO 1//////////////////////
#include <Wire.h>               //libreria I2C
char dato;                      //variable de almacenamiento de dato
const int led1=8;               //led1 en pin8
const int led2=9;               //led1 en pin9
const int led3=10;              //led1 en pin10

void setup() {
  Wire.begin(1);                //id de esclavo
  Wire.onReceive(receiveEvent); //evento de rececpcion
  Serial.begin(9600);
  pinMode(led1,OUTPUT);         //pin8 como salida
  pinMode(led2,OUTPUT);         //pin9 como salida
  pinMode(led3,OUTPUT);         //pin10 como salida
}

void loop() {
  delay(100);
}

void receiveEvent (int bytes){
  while(Wire.available()){
    dato=Wire.read();
    if(dato=='A') {
      digitalWrite(led1,HIGH);
      digitalWrite(led2,LOW);
      digitalWrite(led3,LOW);
      delay(300);
      digitalWrite(led1,LOW);
      digitalWrite(led2,HIGH);
      digitalWrite(led3,LOW);
      delay(300);
      digitalWrite(led1,LOW);
      digitalWrite(led2,LOW);
      digitalWrite(led3,HIGH);
      delay(300);
      digitalWrite(led1,LOW);
      digitalWrite(led2,LOW);
      digitalWrite(led3,LOW);
      delay(300);
    }
  }
}
