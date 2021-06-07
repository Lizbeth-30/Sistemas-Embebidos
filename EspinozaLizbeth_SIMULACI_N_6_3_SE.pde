/*
 * CAPÍTULO 6: FUNCIONES ESPECÍFICAS
 * PROGRAMA 29: Uso de eventos mouse y teclado
 * OBJETIVO: Movimiento de esfera por un mapa restringido mediante teclado
 */

 

PImage img; // cargar imagen
int y=0; // movimiento en eje y
int x=0; // movimiento en eje X
int y1=-50; //  variable para cargar imagen en ubicación establecida
int x1=-50; //  variable para cargar imagen en ubicación establecida
int x2=0; // movimiento de esfera
int y2=0; // movimiento de esfera
int x3=0; // comprobar si existe un bloque para caminar
int y3=0; // comprobar si existe un bloque para caminar
// matriz de obstáculos
int vector[][]={
{0,0,1,0,0,1,0,1,0,0,0,0,0,0,0,1},
{1,0,1,0,1,1,0,1,0,0,0,1,1,0,1,1},
{1,0,1,0,0,0,0,0,0,1,0,1,1,0,0,1},
{1,0,0,0,0,1,1,1,0,1,0,1,0,0,0,1},
{1,0,1,1,0,1,1,1,0,1,0,0,1,0,1,1},
{0,0,0,0,0,1,1,1,0,1,1,0,1,0,1,1},
{0,0,0,0,0,1,1,1,0,1,1,0,1,0,1,1},
{1,0,1,0,0,0,0,0,0,1,1,0,0,0,1,1},
{0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,1},
{0,0,1,1,0,1,1,1,0,1,1,0,1,1,0,1},
{1,0,1,0,0,1,1,1,0,0,0,0,0,0,0,0},
{1,0,0,0,0,1,1,1,0,0,0,0,1,1,0,0}
};
void setup(){
  // tamaño de imagen
  size(800,600);
  background(0); // fondo
  img=loadImage("222.PNG"); // carga imagen
  //imageMode(CENTER);
  // rutina que busca donde existe 1 en matriz para cargar imagen
  for(;y<12;y++){
    y1=y1+50;
    for(x=0;x<16;x++){
      x1=x1+50;
      if(vector[y][x]==1){
          image(img,x1,y1,50,50);
      }
    }
    x1=-50;
  }
}
void draw(){
  //movimiento de ellipse
  fill(255,0,0);
 ellipse(25+x2,25+y2,25,25);
}
//evento de teclado
void keyPressed(){
  //recibe el código de tecla presionada
  switch(keyCode){
    case 37: // izquierda
    //se mueve la variable oara verificar si existe bloque caso contrario regresa a posicion anterior
    if(x3>0){
      x3--;
      if(vector[y3][x3]!=1){
        borrar();
        x2=x2-50;
       }
       else
         x3++;
    }   
      print(x3);
    break;
    
    //se mueve la variable para verificar si existe bloque caso contrario regresa a posicion anterior
    case 38: //arriba
    if(y3>0){
      y3--;
      if(vector[y3][x3]!=1){
         borrar();
          y2=y2-50;
      }
      else
        y3++;
    }
     print(y3);
    break;
    
    //se mueve la variable oara verificar si existe bloque caso contrario regresa a posicion anterior
    case 39: //derecha
    if(x3<15){
      x3++;
      if(vector[y3][x3]!=1){
        borrar();
        x2=x2+50;
     }
     else
       x3--;
    }
     print(x3);
    break;
    case 40: //abajo
    if(y3<11){
      y3++;
      if(vector[y3][x3]!=1){
         borrar();
         y2=y2+50; 
     }
     else 
       y3--;
    }  
      print(y3);
    break;
  }
}
//borra ubicación anterior de ellipse
void borrar(){
  fill(0);
 ellipse(25+x2,25+y2,25,25);
}
