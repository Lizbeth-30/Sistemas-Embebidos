
/*
 * UNIDAD V: FUNCIONES ESPECÍFICAS
 * CÓDIGO 22 : CAMBIO DE CONFIGURACIÓN DE ARDUINO POR WDT
 * OBJETIVO: Cambiar la configuración de la cx serial y timer 2 en un reinicio de programa (watchdog, sistema de reinicio por software)
 * Nombre: Lizbeth Espinoza
 * Funciones:
 *         wdt_disable(): deshabilita el watchdog
 *         wdt_enable(): habilita la función 
 *         tiempos:WDT0_15MS,WDT0_500MS,...WDT0_8S 
 *         libreria:avr/wdt.h 
 *         wdt_reset(): resetea al contador  
 */
#include<avr/wdt.h>     // librería wdt
#include <EEPROM.h>     // librería EEPROM
#include <MsTimer2.h>   // librería Timer2
int j;                  // varaible de cambio de configuración
void setup() {
    
    attachInterrupt(0,on,LOW);     // habilita interrupcion 0
    MsTimer2::set(9000, conteo);   // timer 2 a 9s period
    j=EEPROM.read(0);              // lectura de dato desde EEPROM
     if(j==1){                     // condición de configuración 
       MsTimer2::start();          // habilita timer
       Serial.begin(19200);        // cx serial 
        }
     else{
       Serial.begin(9600);         // cx serial a diferente velocidad
        wdt_disable();             // deshabilita wdt
        MsTimer2::stop();          // para el timer
        }
   Serial.println("INICIO");       // mensaje
}
void loop() {
  Serial.println(j);               // envía el estado de variable
  delay(200);
}
void on(){                         // interrupción
    MsTimer2::start();             // inicia Timer 2
    j=1-j;                         // cambia de estado para nuevo reset
    EEPROM.update(0,j);            // actualiza valor de variable
    if(j==0)                       // condición de config
    MsTimer2::stop();              // detiene timer
     
  }
void conteo(){                     // rutina de timer
    Serial.println("timer");       // mensaje
    if(j==1){                      // condición de funcionamiento
         wdt_enable(WDTO_1S);      // reinicio de sistema
        }
  }