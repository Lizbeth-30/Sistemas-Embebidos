/*
* EVALUACIÓN PARCIAL 1
* NOMBRE: Lizbeth Espinoza
* Se desea implementar un sistema de seguridad similar a “ChevyStar”.
*/
#include <LiquidCrystal.h> //libreria LCD

LiquidCrystal lcd(13,12,11,10,9,8); 
const int led1=3;
const int btnA=7;
const int btn3=6;
const int btn2=5;
const int btn1=4;
int clave=3213;


void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);     
  pinMode(led1,OUTPUT);
  pinMode(btnA,INPUT);
  pinMode(btn3,INPUT);
  pinMode(btn2,INPUT);
  pinMode(btn1,INPUT);
  lcd.setCursor(0, 0);
  lcd.print("SISTEMA DE SEGURIDAD");
  delay(200);
  lcd.clear();
}

void loop() {
     if(digitalRead(btnA)==LOW){
       if(digitalRead(btn3)==LOW && digitalRead(btn2)==LOW && digitalRead(btn1)==LOW && digitalRead(btn2)==LOW){
         digitalWrite(led1,HIGH);
         lcd.setCursor(0, 0);
         lcd.print("DESACTIVADO");
         delay(500);
         lcd.clear();
       }
       else {
         for(int i=0;i>3;i++){
        lcd.setCursor(0, 0);
         lcd.print("Error: Intento "+String(i));
         delay(500);
         lcd.clear();
         }
       }   
     }
}






