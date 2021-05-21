/*
* CAPÍTULO V: FUNCIONES ESPECIALES
* CÓDIGO 20: Funciones de put y get con EEPROM
* OBJETIVO: Aplicación de get y put en un contador cada 2 segundos
* NOMBRE: Lizbeth Espinoza 
* FUNCIONES:   EEPROM.put(dir.valor)
*              dir=direccion de memoria, 0-1023
*              valor: valor a escribir
*              EEPROM.get(dir,valor)
*              dir=direccion de memoria, 0-1023
*              valor: nombre de variable para guardar el dato
*/

#include <EEPROM.h>
int var=0;                 //variable de conteo

void setup() {
  Serial.begin(9600);     //inicio comunicación Serial
  EEPROM.get(0, var);     //lee el dato en la EEPROM en la variable var
  Serial.println(String("Valor: ")+String(var));  //Imprime la variable
}

void loop() {
  var++;                 //incremento de la variable
  if(var<255)            //condicion de contador
    EEPROM.put(0, var);  //actualiza valor
  else
  var=0;                 //reinicia variable
  Serial.println(String("Valor: ")+String(var));    //Imprime mensaje por cx serial
  delay(200);            // 2 segundos seria (2000)
  
}
