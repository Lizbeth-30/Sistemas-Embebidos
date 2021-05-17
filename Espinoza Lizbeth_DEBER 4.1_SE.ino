/*
* CAPITULO IV: PERIFERICOS ESPECIALES
* DEBER 4.1: CAD Y PWM
* Nombre: Lizbeth Espinoza
*/

#include <LiquidCrystal.h>
LiquidCrystal lcd(13,12,7,6,5,4);              //seleccion de pines para la LCD
int conversor;                                 //variable para adquirir datos del conversor entre 0 - 1023
float voltaje;                                 //variable de conversion de conversor a voltaje
int dutty;                                     //variable para el uso de pwm
LiquidCrystal lcd1(9,8,3,2,1,0); 
int conversor1;                                 //variable para adquirir datos del conversor entre 0 - 1023
float voltaje1;                                 //variable de conversion de conversor a voltaje
int dutty1; 
#define sw 10
#define boton 11


void setup() {
  lcd.begin(16,2);                      //inicializa la LCD
  pinMode(boton,INPUT);     
  pinMode(sw,INPUT);        
}

void loop() {
  if(digitalRead(boton)==LOW){
  conversor=analogRead(A0);            //lectura del canal A0-0-14
  voltaje=(conversor*5.0)/1023.0;      //conversor de voltaje
  dutty=conversor/4;                   //cambio la escala para el dutty cicle
  analogWrite(11,dutty);               //envio de valor al pin 11
  lcd.setCursor(0,0);                  //posición
  lcd.print("CAD:");
  lcd.setCursor(5,0);
  lcd.print(conversor);
  lcd.setCursor(0,1);
  lcd.print("V:");
  lcd.setCursor(3,1);
  lcd.print(voltaje);
  lcd.setCursor(9,1);
  lcd.print("PWM:");
  lcd.setCursor(13,1);
  lcd.print((dutty*100)/255);
  delay(300);
  lcd.clear();
  }
  if(digitalRead(sw)==HIGH){
  conversor1=analogRead(A1);            //lectura del canal A0-0-14
  voltaje1=(conversor1*5.0)/1023.0;      //conversor de voltaje
  dutty1=conversor1/4;                   //cambio la escala para el dutty cicle
  analogWrite(10,dutty1);               //envio de valor al pin 11
  lcd1.setCursor(0,0);                  //posición
  lcd1.print("CAD:");
  lcd1.setCursor(5,0);
  lcd1.print(conversor1);
  lcd1.setCursor(0,1);
  lcd1.print("V:");
  lcd1.setCursor(3,1);
  lcd1.print(voltaje1);
  lcd1.setCursor(9,1);
  lcd1.print("PWM:");
  lcd1.setCursor(13,1);
  lcd1.print((dutty1*100)/255);
  delay(300);
  lcd1.clear();
  }
}

