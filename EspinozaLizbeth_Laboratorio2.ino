/* LABORATORIO N°2
*  NOMBRE: Lizbeth Espinoza
*  Realice un sistema domotico
*/

#include <LiquidCrystal.h>
#include<TimerOne.h>

LiquidCrystal lcd(13,12,11,10,9,8); 
// Definir variables y pin de leds
const int led1=4;
const int led2=5;
const int led3=6;
const int led4=7;

int conversor1; //variable para conversor hora
int conversor2; //variable para conversor minutos

unsigned long timer1=0;
unsigned long timer2=0;
int min=0;    //variables de almacenamiento e incremento
int hora=0;   //variables de almacenamiento e incremento
int horas;
int minutos; 

int on=0; //interrupcion 0
int cont; //interrupcion 1
int incremento=0;
// variables y pin para sensores
const int sw1=A2; 
const int sw2=A3; 
const int sw3=A4; 
const int sw4=A5;
// Sistema randomico
int caso1=0;
int caso2=0;
int caso3=0;
int caso4=0;
 
void setup(){
  lcd.begin(16,2);
  Serial.begin(9600);
  attachInterrupt(0,activacion,LOW);
  attachInterrupt(1,modo,LOW);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  Timer1.initialize(1000000);
  Timer1.attachInterrupt(subrutina);
  caso1=random(1,5);
  caso2=random(6,13);
  caso3=random(14,21);
  caso4=random(22,30);
  pinMode(sw1,INPUT); 
  pinMode(sw2,INPUT); 
  pinMode(sw3,INPUT);
  pinMode(sw4,INPUT); 
}

void loop(){
  if(on==1||on==2){
    timer2=(millis()/1000);    
    if(timer1!=timer2){
      timer1=timer2;
      min++;         
    }     
    contador(); 
    imprimir();  
    cambiarHora();  
  }
  if(cont==3){
    if(digitalRead(sw1)==HIGH){
         digitalWrite(led4,HIGH);
         Serial.println("Activando Sensor 1");
         delay(1000);
       }else digitalWrite(led4,LOW);
       if(digitalRead(sw2)==HIGH){
         digitalWrite(led3,HIGH);
         Serial.println("Activando Sensor 2");
         delay(1000);
       }else digitalWrite(led3,LOW);
       if(digitalRead(sw3)==HIGH){
         digitalWrite(led2,HIGH);
         Serial.println("Activando Sensor 3");
         delay(1000);
       }else digitalWrite(led2,LOW);
       if(digitalRead(sw4)==HIGH){
         digitalWrite(led1,HIGH);
         Serial.println("Activando Sensor 4");
         delay(1000);
       }else digitalWrite(led1,LOW);
  }
}
  void cambiarHora(){    
 if(cont==2){
  conversor1=analogRead(0);//Conversión en la hora
  horas=map(conversor1,0,1023,0,24);
  hora=horas;
  conversor2=analogRead(1);//Conversión en minutos
  minutos=map(conversor2,0,1023,0,60);
  min=minutos;
 }
}
   
void contador(){ //incremento de horas y minutos
  // Minutos
  if(min==60){
    min=00;
    hora++;
  } 
  // Horas
  if(hora==24){
    hora=0; 
  } 
}
   
void imprimir(){ 
  lcd.setCursor(0,1);
  lcd.print("Hora:");
  lcd.setCursor(8,1);
  lcd.print(hora);
  lcd.print(" ");
  lcd.setCursor(10,1);
  lcd.print(":");
  lcd.setCursor(12,1);
  lcd.print(min);
  lcd.print(" ");
}
   

void subrutina(){
  if(cont==1){
      incremento++;
      if(incremento==caso1){
            digitalWrite(led1,HIGH);
            digitalWrite(led3,LOW);
            digitalWrite(led2,LOW);
            digitalWrite(led4,HIGH);
      }
      if(incremento==caso2){
            digitalWrite(led1,LOW);
            digitalWrite(led2,HIGH);
            digitalWrite(led3,HIGH);
            digitalWrite(led4,LOW);
      }
      if(incremento==caso3){
            digitalWrite(led1,HIGH);
            digitalWrite(led2,HIGH);
            digitalWrite(led3,HIGH);
            digitalWrite(led4,HIGH);
            delay(2000);
      }
      if(incremento==caso4){
            digitalWrite(led1,LOW);
            digitalWrite(led2,LOW);
            digitalWrite(led3,LOW);
            digitalWrite(led4,LOW);
            caso1=0;
            caso2=0;
            caso3=0;
            caso4=0;
      }
  }
}

void modo(){
  if(on==2){
    switch(cont){
      case 0:
        Serial.println("Activacion de Luces");
        cont++;
      break;
      case 1:
        Serial.println("Cambio de Hora");
        digitalWrite(led1,LOW);
        digitalWrite(led2,LOW);
        digitalWrite(led3,LOW);
        digitalWrite(led4,LOW);
        cont++;
      break;
      case 2:
        Serial.println("Sistema de seguridad de Sensores");  
       cont++;
      break;
      case 3:
        Serial.println("Reiniciar");
        digitalWrite(led1,LOW);
        digitalWrite(led2,LOW);
        digitalWrite(led3,LOW);
        digitalWrite(led4,LOW);
        caso1=random(1,3);
        caso2=random(6,9);
        caso3=random(11,15);
        caso4=random(18,23);
        incremento=0;
        cont=0;
      break;
    }
  }
}
void activacion(){
  switch(on){
    case 0:
      Serial.println("SISTEMA ENCENDIDO");
      lcd.begin(16,2);
      lcd.setCursor(1,0); 
      lcd.print("Bienvenido");
      on++;
    break;
    case 1:
      Serial.println("Seleccionar modo:");
      Serial.println("Pulse una vez para encender los leds");
      Serial.println("Pulse dos veces para cambiar la hora");
      Serial.println("Pulse tres veces para usar sensores");
      Serial.println(" ");
      on++;
    break;
    case 2:
      Serial.println("SISTEMA APAGADO");
      cont=0;
      on=0;
      min=0;
      hora=0;
      digitalWrite(led1,LOW);
      digitalWrite(led2,LOW);
      digitalWrite(led3,LOW);
      digitalWrite(led4,LOW);
      lcd.noDisplay();
    break;
  }
}

