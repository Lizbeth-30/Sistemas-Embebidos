// RETO N°3
// NOMBRE: Lizbeth Espinoza
 
import processing.serial.*;
Serial Puerto;

boolean b = false;

void setup() {
  size(400, 400);
  Puerto = new Serial(this,"COM8",9600);
}

void draw() {
  if (b == false) {
    background(#D0D8D7);
    fill(#18FA05);
    stroke(#18FA05);
    ellipse(200, 200, 100, 100);
    fill(#0A0A0A);
    textSize(20);
    textAlign(CENTER);
    text("EL BOTON NO ESTA PRESIONADO", 200, 70);
  }
  
  if (b == true) {
    background(#D0D8D7);
    fill(#FF0026);
    stroke(#FF0026);
    ellipse(200, 200, 100, 100);
    fill(#0A0A0A);
    textSize(20);
    textAlign(CENTER);
    text("EL BOTON SI ESTA PRESIONADO", 200, 70);
  }
}

void serialEvent(Serial p){
  while(Puerto.available() == 1){
   char letra = Puerto.readChar();  
   print(letra);
   if (letra == 'H') {
     b = true;
    
   }
   if(letra == 'L'){
     b = false;
   }
  }
}
