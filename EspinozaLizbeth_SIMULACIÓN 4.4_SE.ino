/*
* CAPÍTULO V: PERIFÉRICOS ESPECIALES
* CÓDIGO 17: USO DE TIMER 1
* OBJETIVO: Manejo de luces led en diferentes tiempos controlados por el timer 1
* NOMBRRE: Lizbeth Espinoza
* FUNCIONES: Timer1.initializa(1000000)
*            1 segundo segun prescaler y reloj
*            Timer,pwm(pin,dutty);
*            pin 9 0 10, dutty -> 8 y 1023
*            void subrutina(){
*  }
*/

#include <TimerOne.h>
const int led1=8;       //led en pin8
const int led2=9;       //led en pin9
const int led3=10;      //led en pin10
int cont=0;       

void setup() {
  Serial.begin(9600);     // inicia comunicacion serial
  Timer1.initialize(1000000); //configuracion de timer a 1 segundo
  Timer1.attachInterrupt(subrutina);  //Interrupcion en timer
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
}

void loop() {
  Serial.println("PROGRAMA PRINCIPAL"); // simulacion del programa principal
  delay(300);
}

void subrutina(){
  cont++;                  //variable que se incrementa cada segundo
  switch (cont){
    case 8: // En 8s enciende el led 1
      digitalWrite(led1,HIGH);
    break;
    case 10: // En 10s enciende el led 2
      digitalWrite(led2,HIGH);
    break;
    case 12: // En 12s apaga el led 2
      digitalWrite(led2,LOW);
    break;
    case 15: // En 15s enciende el led 3
      digitalWrite(led3,HIGH);
    break;
    case 18: // En 18s apaga el led 1
      digitalWrite(led1,LOW);
    break;
    case 22: // En 22s apaga el led 3
      digitalWrite(led3,LOW);
      cont=0;
    break;
  }
}
