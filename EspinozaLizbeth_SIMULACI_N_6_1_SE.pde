/*
* CAPÍTULO 6: DISEÑO DE INTERFACES
* EJERCICIOS: EN CLASE PROCESSING
* OBJETIVO: Mostrar el funcionamiento de algunas funciones
*/

//EJERCICIOS DE CLASE #1
/*
void setup(){
 size(500,500); 
}

void draw(){  
}
*/

//EJERCICIO DE CLASE #2
/*
void setup(){
  size(500,500);
  background(280,20,100);   //CAMBIA DE COLOR
}

void draw(){
}

void setup(){
size(500,500);
background(#0071c5);
}
void draw(){
}
*/

// EJERCICIO DE CLASE #3
/*
void setup(){
  size(500,500);
  background(#0071c5);
}

void draw(){
  line(50,50,20,200);
  rect(300,200,100,100);
  ellipse(100,400,100,100);
}
*/

// EJERCICIO DE CLASE #4
/*
void setup(){
size(500,500);
background(#0071c5);
}
void draw(){
fill(255,0,0);
stroke(0,255,0);
strokeWeight(3);
line(50,50,200,200);
stroke(255,255,255);
rect(300,200,100,100);
fill(#009383);
ellipse(100,400,100,100);
}
*/

// EJERCICIO DE CLASE #4 VECTOR
/*
int i;
void setup(){
size(300,300);
background(0,0,0);
smooth(); //dibuja la geometría con bordes suaves
}
void draw(){
fill(100,10,10);
beginShape();
vertex(70,30);
vertex(110,50);
vertex(170,50);
vertex(210,30);
vertex(200, 60);
vertex(190, 130);
vertex(160, 170);
vertex(120, 170);
vertex(90,130);
vertex(80,60);
endShape();
if(i<255){
fill(0,0,i);
i++;
}
else
i=0;
triangle(100,70,100,90,130,90);
triangle(180,70,150,90,180,90);
fill(25,25,25);
beginShape();
vertex(110,120);
vertex(170,120);
vertex(170,140);
vertex(160,160);
vertex(120, 160);
vertex(110, 140);
vertex(110, 120);
endShape();
fill(255,255,255);
line(120,120,120,160);
line(130,120,130,160);
line(140,120,140,160);
line(150,120,150,160);
line(160,120,160,160);
}
*/

// EJERCICIO DE CLASE #5
/*
void setup(){
size(500,500);
background(0,113,197);
text("Este es mi primer texto",0,200);
}
void draw(){
}
*/

// EJERCICIO DE CLASE #6
/*
void setup(){
size(500,500);
background(0,113,197);
text("Este es mi primer texto",100,100);
textSize(30);
text("Ahora el tamaño es de 30",20,150);
fill(255,255,0);
text("Y ahora con color",50,200);
textAlign(CENTER);
text("Este texto esta centrado",width/2,width/2);
}
void draw(){
}
*/

// EJERCICIO DE CLASE #7
/*
void setup(){
size(500,500);
background(0,0,0);
}
void draw(){
line(0,0,mouseX,mouseY);
stroke(0,255,0);
}
*/

// EJERCICIO DE CLASE #8
/*
int i=250;
void setup(){
size(400,400);
background(50,50,50);
smooth();
}
void draw(){
noStroke();
fill(0,i,i);
ellipse(100,100,200,200);
}
void mouseClicked(){
if(mouseButton == LEFT&&mouseX>0&&mouseX<200&&mouseY>0&&mouseY<200){
i=80;
}
else
i=250;
}
*/

// EJERCICIO DE CLASE #9
/*
void setup() {
size(500, 500);
background(0);
textAlign(CENTER);
textSize(24);
fill(255);
text("El mouse no está haciendo nada",
width/2, height/2);
}
void draw() {
}
void mousePressed() {
background(100, 100, 0);
text("El mouse fue presionado",
width/2, height/2);
if ( mouseButton == LEFT) {
text("y fue el botón izquierdo",
width/2, height/2 + 40);
}
if (mouseButton == RIGHT) {
text("y fue el boton derecho",
width/2, height/2 + 40);
}
}
void mouseReleased() {
background(100, 0, 100);
text("el botón fue soltado",
width/2, height/2);
}
void mouseMoved() {
background(150, 10, 70);
text("El mouse fue movido",
width/2, height/2);
}
void mouseDragged() {
background(10, 70, 100);
text("Se está arrastrando el mouse",
width/2, height/2);
}
*/

// EJERCICIO DE CLASE #10
/*
int
r,g,b;
void setup(){
size
(600
,
600);
r=0;g=0;b=0;
}
void draw(){
background
(r,g,b);
}
void keyPressed(){ r = int(random(256))
;
g = int(random(256));
b = int(random(256));
}
*/

// EJERCICIO DE CLASE #11
/*
void setup(){
}
void draw(){
}
void keyPressed(){
println(key);
}
*/

// EJERCICIO DE CLASE #12
/*
int r,g,b; 
void setup(){
size(600,600);
r=0;
g=0;
b=0;
}
void draw(){
background(r,g,b);
}
void keyPressed(){
switch(key){
case 'r': 
r=255; 
g=0; 
b=0;
break;
case 'g':
r=0;
g=255;
b=0;
break;
case 'b':
r=0;
g=0;
b=255;
break;
default:
break;
}
}
*/

// EJERCICIO DE CLASE #13
/*
int r,g,b; 
void setup(){
size(600,600);
r = 0;
g = 0;
b = 0;
}
void draw(){
background(r,g,b);
}
void keyPressed(){
switch (keyCode){
case 37:
r=255;
g=0;
b=255;
break;
case 38:
r=255;
g=255;
b=0;
break;
case 39:
r=0;
g=255;
b=255;
break;
default:
break;
}
}
*/

// EJERCICIO DE CLASE #14

import processing.serial.*;
Serial miPuerto;
void setup(){
miPuerto = new Serial(this,"COM5",9600);
}
void draw(){
if (miPuerto.available() > 0){
int dato = miPuerto.read();
println(dato);
}
}
