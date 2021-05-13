/*
 * DEBER #2.1
 * CAPÍTULO II: PUERTOS DIGITALES 
 * CÓDIGO 1: Manejo de puertos configurados como salidas
 * OBJETIVO: Encender y apagar leds mediante el uso de diferentes tipos de variables
 * NOMBRE: Lizbeth Espinoza
 */

//variables: numéricas enteras (int), decimales (float), caracteres (chart)
const int led1 = 8;   //variable constante, es la recomendable   
const int led2 = 9;   //variable constante, es la recomendable     
const int led3 = 10;  //variable constante, es la recomendable
const int led4 = 11;  //variable constante, es la recomendable
 
void setup() {
  pinMode(led1,OUTPUT);  //declaro el pin 8 como salida
  pinMode(led2,OUTPUT);  //declaro el pin 9 como salida
  pinMode(led3,OUTPUT);  //declaro el pin 10 como salida
  pinMode(led4,OUTPUT);  //declaro el pin 11 como salida
}

void loop() {
  digitalWrite(led1,HIGH);  //Envía 5V al pin8
  delay(500);               //Se detiene el microcontrolador por medio segundo
  digitalWrite(led1,LOW);   //Envía 0V al pin8
  delay(500);               //Se detiene el microcontrolador por medio segundo
  digitalWrite(led2,HIGH);  //Envía 5V al pin9
  delay(500);               //Se detiene el microcontrolador por medio segundo
  digitalWrite(led2,LOW);   //Envía 0V al pin9
  delay(500);               //Se detiene el microcontrolador por medio segundo
  digitalWrite(led3,HIGH);  //Envía 5V al pin10
  delay(500);               //Se detiene el microcontrolador por medio segundo
  digitalWrite(led3,LOW);   //Envía 0V al pin10
  delay(500);               //Se detiene el microcontrolador por medio segundo
  digitalWrite(led4,HIGH);  //Envía 5V al pin11
  delay(500);               //Se detiene el microcontrolador por medio segundo
  digitalWrite(led4,LOW);   //Envía 0V al pin11
  delay(500);               //Se detiene el microcontrolador por medio segundo

}
