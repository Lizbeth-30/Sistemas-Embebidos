
#include <MsTimer2.h>  
#include <avr/power.h> 
#include <avr/sleep.h>  
#include<avr/wdt.h>

int mq135=0;
int mq7=0;
int aireLimpio=8;
int aireConta=9;

int tiempo=300; 
int cont=0; 

void setup() {
  Serial.begin(9600);
  MsTimer2::set(1000, reloj);
  power_adc_disable(); 
  MsTimer2::start();
  pinMode(aireLimpio, OUTPUT);
  pinMode(aireConta, OUTPUT);
  Serial.println("Recoleccion de datos");
  digitalWrite(aireLimpio, LOW);
  digitalWrite(aireConta, LOW);
}

void loop() {
  delay(500);
  mq135=analogRead(A0);
  mq7=analogRead(A1);
 
  delay(500);
  if(mq135>60 && mq135<200){
    digitalWrite(aireLimpio, HIGH);
    digitalWrite(aireConta, LOW);
    }
   if(mq135>200){
    digitalWrite(aireLimpio, LOW);
    digitalWrite(aireConta, HIGH);
    }
    if(mq7>130 && mq7<300){
    digitalWrite(aireLimpio, HIGH);
    digitalWrite(aireConta, LOW);
    }
    if(mq135>300){
    digitalWrite(aireLimpio, LOW);
    digitalWrite(aireConta, HIGH);
    }
}
void reloj(){  
   cont++; // cuenta cada segundo
   if(cont==tiempo){ 
       power_adc_enable(); 
       delay(10);
       Serial.println(String(mq135)+String(", ")+String(mq7));  
       cont=0; 
    }
}