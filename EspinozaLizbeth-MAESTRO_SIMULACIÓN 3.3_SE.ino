/*
* CAPÍTULO III: MÓDULOS DE COMUNICACIÓN
* CÓDIGO 12: Recepción y envío de mensajes por comunicación I2C
* OBJETIVO: Enviar mensajes desde un master hacia un esclavo
* Nombre: Lizbeth Espinoza
* Funciones: Wire.begin()   //Inicia el hadware del bus
*            Wire.beginTransmission(adress);    //Comenzar la transmisión
*            Wire.endTransmission(adress);      //Finalizar la transmisión
*            Wire.requestFrom(adress,nBytes);   //Solicita un número de bytes al esclavo en la dirección address
*/

/////////////////////////MASTER///////////////////////////

#include <Wire.h>
int cont=0;

void setup() {
  Wire.begin();
  Serial.begin(9600);
}

void loop() {
  cont++;                       //incremento de la variable
  Wire.beginTransmission(4);    //Configuración del esclavo
  Wire.write(cont);             //envio de mensaje
  Wire.endTransmission();       //Fin de comunicación
  delay(1000);                  //tiempo de espera
  Wire.requestFrom(4,2);
  while (Wire.available()){
    Serial.print("mensaje recibido ");
      char c=Wire.read();
    Serial.println(c);
  }
  Serial.println();
  delay(1000);
}


