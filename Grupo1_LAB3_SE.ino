/*
 * Laboratorio 3
 * GRUPO 1
 * 
 */
int dato=0;
int led=3;
void setup() {
  Serial.begin(9600);//iniciar puerto serial
  pinMode(7,INPUT);
  pinMode(6,INPUT);
  pinMode(5,INPUT);
  pinMode(4,INPUT);
  pinMode(led,OUTPUT);
}
void loop() {
if(digitalRead(4)==LOW){ //boton de activacion en bajo
if(digitalRead(7)==LOW){// movimiento boton izquierda
  dato=1;
  }
  else{
    dato=0;//no moverse
}
if(digitalRead(6)==LOW){//movimiento boton derecha
  dato=2;
}
if(digitalRead(5)==LOW){//movimiento disparar
dato=3;
}
Serial.println(dato);// enviar dato a processing por el puerto serial
digitalWrite(led,HIGH);// prender led
}
if(digitalRead(4)==HIGH){// condicion para apagar led
   digitalWrite(led,LOW);
}
}
