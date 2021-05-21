/*
* CAPÍTULO V: FUNCIONES ESPECIALES
* CÓDIGO 21: Rutina de reinicio
* OBJETIVO: Reiniciar en un determinado tiempo por medio de WDT y memoria EEPROM
* NOMBRE: Lizbeth Espinoza 
*/

#include <avr/wdt.h>       //libreria wdt
#include <EEPROM.h>        //libreria EEPROM

int i;                    //variable de conteo

void setup() {
  Serial.begin(9600);    //Inicia comunicación serial
  Serial.println("DESPIERTO");    //mensaje desde setup
  attachInterrupt(0,activacion,LOW); //Configuración de la interrupcion
  i=EEPROM.read(0);                  // lectura de dato desde EEPROM
}

void loop() {
  Serial.println(i++);      //aumento de valor en la variable
  if(i<255){
    EEPROM.write(0, i);     //almacenamiento en EEPROM
  }
  else
  i=0;                      //reinicia la variable
  delay(300);               //espero 300ms
}

void activacion(){
  wdt_disable();       //deshabilitar el wdt
  wdt_enable(WDTO_4S); //reiniciar en 4S
}
