/*
 * CAPÍTULO 6: DISEÑO DE INTERFACES
 * PROGRAMA 28: Manejo de funciones generales en PROCESSING
 * OBJETIVO: Mostrar Texto y funciones de teclado y mouse
 */

 

int i=0;
void setup(){
size(700,500); // tamaño de la interfaz
background(0); // 0 -> negro , 255-> blanco
}

 

void draw(){
  //background(0); // 0 -> negro , 255-> blanco
  textSize(30); // tamañao del texto 
  text("   ",315,60); // ubicación de mensaje vacíos
  text("   ",395,60);
  fill(0,255,0);
  text("INTERFAZ",280,35); //texto
  textSize(20);  
  text("CX:",280,60); 
  text(mouseX,315,60); // muestra coordenada de mouse X
  text("CY:",360,60); 
  text(mouseY,395,60); // muestra coordenada de mouse Y
  stroke(255,0,0);
  line(0,0,mouseX,mouseY); //Genera una línea desde vértice hasta ubicación de mouse
}
void mouseClicked(){ // evento si usuario presion click derecho
  if(mouseButton==LEFT){ // confirma si presiona el botón izquierdo
    fill(255,255,0);
    ellipse(mouseX,mouseY,10,10); // muestra esfera
  }
}
void keyPressed(){ // evento de presión de tecla
 if(key=='A'){ // is presiona A
    background(0); /// borra interfaz
  }
}
