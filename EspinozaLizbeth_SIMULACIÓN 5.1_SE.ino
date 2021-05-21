/*
 * CAPITULO V: FUNCIONES ESPECIFICAS
 * CODIGO 19: Lectura y escritura en la memoria EEPROM
 * Objetivo: Almacenar un valor del conversor AD si se encuntra dentro de un rango establecido
 * Funciones: EEPROM.write(dir,valor);
 *            EEPROM.read(dir);
 *            EEPROM.update(dir,valor);
 *                   dir -0-1023
 *                   valor-> 8 bits
 *NOMBRE: Lizbeth Espinoza
 */

 #include <EEPROM.h>
 #include <LiquidCrystal.h>

 LiquidCrystal lcd(13,12,11,10,9,8);

 int i=0;            //ubicacion de la memoria 
 int valor_cad;     //variable para la conversion
 int val_max;       //valor maximo de rango
 int val_min;       //valor minimo de rango 
 
void setup() {
  lcd.begin(16,2);            //inicializa lcd
  valor_cad=EEPROM.read(0);  //leer el valor de la memoria 
  val_max=valor_cad+5;       //rango de error
  val_min=valor_cad-5;       //rango de error 
}

void loop() {
  if((analogRead(0)/4)>val_max||(analogRead(0)/4)<val_min){   //condicion de salida del rango        
    valor_cad=analogRead(0)/4;                                //actualizar el valor en la variable 
    EEPROM.write(0,valor_cad);                                //escribir dato en la memoria
    val_max=valor_cad+5;                                      //reango maximo de error
    val_min=valor_cad+5;                                      //reango maximo de error  
  }
  lcd.setCursor(0, 0);           //ubicacion en LCD
  lcd.print(String("Memoria: ")+String(valor_cad));     //imprime dato y mensaje
  lcd.setCursor(0, 1);           //ubicacion en LCD
  lcd.print(String("CAD: ")+String(analogRead(0)/4));   //imprime dato y mensaje
  delay(300);                    //tiempo de espera
  lcd.clear();                  //limpiar lcd
}