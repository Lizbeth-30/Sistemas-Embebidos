/*
* CAPÍTULO V: FUNCIONES ESPECIALES
* CÓDIGO 19.1: Lectura y escritura de datos en la memoria EEPROM
* OBJETIVO: Almacenar 10 valores del conversor analogo digital, luego visualizar con comunicación serial
* NOMBRE: Lizbeth Espinoza 
*/

#include <EEPROM.h>
 const int led1=13;
 const int sw=7;
 
void setup() {
  Serial.begin(9600);     //inicio de comunicacion
  pinMode(led1,OUTPUT);
  pinMode(sw,INPUT);

  if(digitalRead(7)==0){
    Serial.println("Lectura de Memoria: ");             //imprimir mensaje 
    for(int i=0;i<=9;i++){
      Serial.println(EEPROM.read(i));                 //imprimir el dato
      delay(100);
    }
  }
else{
  Serial.println("Almacenando 10 datos: ");             //texto cuando escribe datos
  for(int i=0;i<=9;i++){
  digitalWrite(led1,HIGH);
  delay(1000);
  int dato=analogRead(0);
  dato=map(dato,0,1023,0,255);
  EEPROM.write(i,dato);
  Serial.println(dato);
  digitalWrite(led1,LOW);        // envio 0voltios a pin  13
  delay(1000);                        
    }
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}






