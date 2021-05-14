/*
* CAPITULO IV: PERIFERICOS ESPECIALES
* CODIGO 14: CAD Y PWM
* OBJETIVO: Realizar lecturas del conversor analogo digital para determinar la velocidad de un motor en dc
* Nombre: Lizbeth Espinoza
* FUNCIONES:   analogRead(conversor)
*                         conversor -> A0 - A5
*              analogWrite(pin,dutty)
*                          pin -> pines con ~, dutty -> 0-225
*/

#include <LiquidCrystal.h>
LiquidCrystal lcd(13,12,5,4,3,2);              //seleccion de pines para la LCD
int conversor;                                 //variable para adquirir datos del conversor entre 0 - 1023
float voltaje;                                 //variable de conversion de conversor a voltaje
int dutty;                                     //variable para el uso de pwm
 
void setup() {
  lcd.begin(16,2);                      //inicializa la LCD
}

void loop() {
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
