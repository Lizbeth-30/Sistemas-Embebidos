/*
* DEBER 4.3
* CAPITULO: PERIFERICOS ESPECIALES
* CODIGO 18: TIMER 2
* OBJETIVO: Realizar la modificación correspondiente en el código 18 que se utilizó en clase, 
* trabajando con una LCD 20x4, en donde en la primera fila se observe un mensaje de bienvenida,  
* en la segunda línea se visualice su nombre y apellido, en la tercera línea se observe "Horas : minutos : segundos"; 
* y en la última fila se visualice los valores asignados a las variables del timer2, centradas.
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
int valor=10;                 //variable del valor timer2 a 1 mseg
void setup() {
  lcd.begin(20,4);     //inicia la LCD
  MsTimer2::set(valor,reloj); //configura el timer 2 a 1 segundo
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
  lcd.setCursor(5,0);  //ubicacion de LCD
  lcd.print("BIENVENIDOS");
  lcd.setCursor(2,1);  //ubicacion de LCD
  lcd.print("Lizbeth Espinoza");
  lcd.setCursor(7,2);  //ubicacion de LCD
  lcd.print(String(horas)+String(":")+String(minutos)+String(":")+String(segundos));
  lcd.setCursor(3,3);  //ubicacion de LCD
  lcd.print(String("Valor Timer2: ")+String(valor));
}
