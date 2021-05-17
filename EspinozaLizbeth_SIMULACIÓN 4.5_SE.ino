/*
* CAPITULO: PERIFERICOS ESPECIALES
* CODIGO 18: USO DE TIMER 2
* OBJETIVO: Reloj con Timer 2
* NOMBRE: Lizbeth Espinoza
* FUNCIONES: MsTimer2::set(1000,flash); //1s periodo
*            MsTimer2::star();
*            MsTimer2::stop();
*/

#include <MsTimer2.h>        //libreria Timer2
#include <LiquidCrystal.h>   //libreria LCD
LiquidCrystal lcd (13,12,11,10,9,8); //Objeto para la libreria de LCD
int segundos=0;               //variable de segundos
int minutos=0;                //variable de minutos
int horas=0;                  //variable de horas
void setup() {
  lcd.begin(16,2);     //inicia la LCD
  MsTimer2::set(10,reloj); //configura el timer 2 a 1 segundo
  MsTimer2::start();
}
void loop() {
}
void reloj(){
  if(segundos<60){          //condicion de segundos
    segundos++;             //incremento variable
  }
  else{
    segundos=0;
    if(minutos<60){         //condicion de minutos
      minutos++;            //incrementar la variable
    }
    else{
      minutos=0;            
      if(horas<24){        //condicion de horas
        horas++;           //incrementar variable
      }
      else{
        horas=0;           
      }
    }
  }
  lcd.clear(); //borrar el anterior mensaje
  lcd.setCursor(0,0);  //ubicacion de LCD
  lcd.print(String(horas)+String(":")+String(minutos)+String(":")+String(segundos));
}