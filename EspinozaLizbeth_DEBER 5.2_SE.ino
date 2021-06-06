/*
* DEBER N° 5.2
* NOMBRE: Lizbeth Espinoza
* CAPITULO V: FUNCIONES ESPECIFICAS
* CÓDIGO: MANEJO DE MODOS SLEEP
* OBEJTIVO: Realizar un control de modos sleep por medio de interrupciones
* MODO SLEEP Y DE AHORRO DE BATERIA
* Consumo es de 100-500mA
* Ahorro de bateria es hasta 10mA
* Librerias: avr/sleep.h
*            avr/power.h
*/

#include<avr/power.h>
#include<avr/sleep.h>
#include<avr/wdt.h>
#include <MsTimer2.h>
#include<EEPROM.h>
int dato;
int on=0;
void(* resetFunc) (void) = 0; 
//void on(void);
void setup() {
   dato=EEPROM.read(0);
   Serial.begin(9600);
   Serial.println("SETUP");
   if(dato==0){
    EEPROM.update(0,1);
    wdt_enable(WDTO_4S);
    set_sleep_mode(SLEEP_MODE_STANDBY);
    sleep_enable();
    }
    else{
      sleep_disable();
      EEPROM.update(0,0);
      MsTimer2::set(10000,tiempo); // configura timer 2 a un segundo
      MsTimer2::start();
    }
   attachInterrupt(0,encender,LOW);
}
void loop() {
if(dato==0){
  Serial.println("DORMIDO");
  delay(1000);
 sleep_mode(); 
}
 else{
  Serial.println("DESPIERTO");
  delay(1000);
  }
}
void tiempo(){
  Serial.println("DORMIDO");
  delay(2000);
  sleep_enable();
 }
 
 void encender (){
    resetFunc();  
 }


