/*
 * RETO N°4
 * NOMBRE: Lizbeth Espinoza
 */

import processing.serial.*;
Serial puerto;

void setup() {
  size(400, 400);
  puerto = new Serial(this,"COM8",9600);

  background(#D0D8D7);
  fill(#FF0313);
  stroke(#FF0313);
  ellipse(200, 200, 100, 100);
  fill(#0A0A0A);
  textSize(20);
  textAlign(CENTER);
  text("PRESIONE EL BOTON \n PARA ENCENDER LED", 200, 70);
  fill(#FAFFFE);
  textSize(15);
  text("¡APAGADO!", 200, 200);
}

void draw() {
}

void mousePressed() {
  if (mouseButton == RIGHT) {
    background(#D0D8D7);
    fill(#18FA05);
    stroke(#18FA05);
    ellipse(200, 200, 100, 100);
    fill(#0A0A0A);
    textSize(20);
    textAlign(CENTER);
    text("PRESIONE EL BOTON \n PARA APAGAR LED", 200, 70);
    fill(#FAFFFE);
    textSize(15);
    text("¡ENCENDIDO!", 200, 200);
    puerto.write('H');
  }
  
  if(mouseButton == LEFT){
    background(#D0D8D7);
    fill(#FF0313);
    stroke(#FF0313);
    ellipse(200, 200, 100, 100);
    fill(#0A0A0A);
    textSize(20);
    textAlign(CENTER);
    text("PRESIONE EL BOTON \n PARA ENCENDER LED", 200, 70);
    fill(#FAFFFE);
    textSize(15);
    text("¡APAGADO!", 200, 200);
    puerto.write('L');
  }
}
