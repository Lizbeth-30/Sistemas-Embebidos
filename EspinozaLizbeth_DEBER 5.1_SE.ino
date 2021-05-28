/*
* CAPITULO V: FUNCIONES ESPECIFICAS
* DEBER N° 5.1
* NOMBRE: Lizbeth Espinoza
*/ 

#include <Keypad.h>
#include <LiquidCrystal.h>   
#include <EEPROM.h>
const byte filas = 4; 
const byte columnas = 4;
int i=0;
int j=0;
int aux=0;
int posi=0;
char key;
byte pinfilas[]  = {7,6,5,4};
byte pincolumnas[] = {3,2,1,0};
char teclas[filas][columnas] = {
  {'7','8','9','A'},
  {'4','5','6','B'},
  {'1','2','3','C'},
  {'*','0','#','E'}};
Keypad teclado = Keypad( makeKeymap(teclas), pinfilas, pincolumnas, filas, columnas); 
LiquidCrystal lcd(13, 12, 11, 10, 9, 8); 

void setup() {
lcd.begin(16, 2);   
teclado.setHoldTime(500); 
lcd.setCursor(1,0);
}

void loop() {
  lcd.setCursor(0,0);
  lcd.println(String("El dato es: "));
  key=teclado.getKey();
  if(key<='9' && key>='0'){
   if(i<6){
    lcd.setCursor(0,1);
    lcd.print(key);
    EEPROM.put(posi,key);
    posi++;
    lcd.setCursor(12,0);
    lcd.println(i);
    delay(500);
    lcd.clear();
    i++;
  } 
  }
  else if(key=='E'){
      char var1 = EEPROM.get(0,key); 
      char var2 = EEPROM.get(1,key);
      char var3 = EEPROM.get(2,key);
      char var4 = EEPROM.get(3,key);
      char var5 = EEPROM.get(2,key);
      char var6 = EEPROM.get(3,key);
      char vector[6] = {var1,var2,var3,var4,var5,var6};
     for(i=0;i<6;i++){
      for(j=i+1;j<6;j++){
        if(vector[i]>vector[j]){
          aux=vector[i];
          vector[i]=vector[j];
          vector[j]=aux;
          }
        }
      }
      
      lcd.clear();
      lcd.home();
      lcd.print(String("1. ")+vector[0]);
      lcd.setCursor(0,1);
      lcd.print(String("2. ")+vector[1]);
      lcd.setCursor(5,0);
      lcd.print(String("3. ")+vector[2]);
      lcd.setCursor(5,1);
      lcd.print(String("4. ")+vector[3]);
      lcd.setCursor(11,0);
      lcd.print(String("5. ")+vector[4]);
      lcd.setCursor(11,1);
      lcd.print(String("6. ")+vector[5]);
      delay(1000);
      lcd.clear(); 
      }
}
