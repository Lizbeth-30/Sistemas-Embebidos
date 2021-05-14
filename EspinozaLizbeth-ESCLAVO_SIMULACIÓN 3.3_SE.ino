
//////////////////////////ESCLAVO////////////////////////
#include <Wire.h>

void setup() {
  Wire.begin(4);                 //id de esclavo
  Wire.onReceive(receiveEvent);  //evento de recepcion de mensajes
  Serial.begin(9600);            //comuniación serial
}

void loop() {
  delay(100);                    //tiempo de espera
}

void receiveEvent(int bytes){    //evento I2C
  while(Wire.available()){       //Verifica si existe un mensaje por leer
  Serial.print("mensaje recibido ");
  int c=Wire.read();             //recibe el dato
  Serial.println(c);             //imprime por comunicación serial
  }
}