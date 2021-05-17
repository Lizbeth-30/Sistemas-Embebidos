/*
* CAPÍTULO V: PERIFÉRICOS ESPECIALES
* CÓDIGO 15: CAD Y SERVO
* OBJETIVO: Realiza el giro de un servo motor hasta el límite ingreesado por comunicación serial
* NOMBRRE: Lizbeth Espinoza
* FUNCIONES:  analogRead(conversor)
*                        conversor -> A0-A5
*             analogWrite(pin,dutty)
*                         pin -> pines con ~, dutty ->0-225
*/

#include <Servo.h>
Servo servo1;           //creacion de objeto para servo 1
Servo servo2;           //creacion de objeto para servo 2
int conversor1;         //variable para conversor 1
int conversor2;         //variable para conversor 2
String dato;            //variable para comunicación serial
int giro=0;         //variable de limite de giro

void setup() {
  Serial.begin(9600);    // Inicio de comunicación serial
  servo1.attach(10);     //configuración de servo1
  servo1.attach(9);      //configuración de servo2
  Serial.println("Ingrese un valor numerico entre 0 y 180");  //mensaje de indicaciones
}

void loop() {
  conversor1=analogRead(0);                  // lectura de conversor1
  conversor1=map(conversor1,0,1023,0,180);   //Función de cambio de limite
  servo1.write(conversor1);                  //impresion del valor en servo1
  delay(50);                                //espera de estabilización
  conversor2=analogRead(1);                 //lectura de conversor2
  if(Serial.available()>0){                 //condicion de recepción de dato
    dato=Serial.readString();               //almacenamiento de dato ingresado a la variable
    giro=dato.toInt();                      //conversion a entero
  }
  if(giro<180){                             //si cumple la condicion maxima de giro
    conversor2=map(conversor2,0,1023,0,giro); //cambio de limites
    servo2.write(conversor2);                 //impresion de valor en seervo2
  }
  else{
  Serial.println("Dato Invalido");          //mensaje de error
  delay(50);  
  }                             //espera de estabilización
}
