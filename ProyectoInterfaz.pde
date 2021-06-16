import processing.serial.*;
Serial Port; 
int al=170;
int r;
int r2,r3,r4;
int aux=0;
float x,y;
int resultado;
PImage aireLImg;
PImage aireSImg;
void setup(){
Port =new Serial(this,"COM4",9600);
aireLImg=loadImage("airelimpio.png");//carga de imagenes
aireSImg=loadImage("airesucio.png");
  size(1200,800);
  background(255,255,255);
  
}

void draw(){
    
  strokeWeight(3);
  stroke(#DBD9D9);
  line(0,220,1200,220);
  //linea de separacion
  strokeWeight(3);
  stroke(#DBD9D9);
  line(300,220,300,800);
  background(255);
  fill(0);
  textSize(20);
  text("DATOS SENSORES",75,450);
  text("MQ135: "+r+" ppm",75,500);
  text("MQ7: "+r2+" ppm",75,550);
  
   //linea de separacion
  strokeWeight(3);
  stroke(#DBD9D9);
  line(0,220,1200,220);
  //linea de separacion
  strokeWeight(3);
  stroke(#DBD9D9);
  line(300,220,300,800);
  
  fill(0,0,255);
  textSize(45);
  text("UNIVERSIDAD TECNICA DEL NORTE",180,60);
  
  fill(0);
  textSize(35);
  text("LIZBETH ESPINOZA - FERNANDA CHIQUITO",200,120);
  
  if(r<200){
    imageMode(CORNER);
    image(aireLImg, 500,300 ,350,350);
    fill(0);
  textSize(20);
  text("AIRE LIMPIO",600,300);
  }else{
    imageMode(CORNER);
    image(aireSImg,500,300 ,350,350);
    fill(0);
  textSize(20);
  text("AIRE CONTAMINADO",600,300);
  }
  
  //  if(r2<200){
  //  imageMode(CORNER);
  //  image(aireLImg, 500,300 ,350,350);
  //  fill(0);
  //textSize(20);
  //text("AIRE LIMPIO",600,300);
  //}else{
  //  imageMode(CORNER);
  //  image(aireSImg,500,300 ,350,350);
  //  fill(0);
  //textSize(20);
  //text("AIRE CONTAMINADO",600,300);
  //}
  
  //if(r3<200){
  //  imageMode(CORNER);
  //  image(aireLImg, 500,300 ,350,350);
  //  fill(0);
  //textSize(20);
  //text("AIRE LIMPIO",600,300);
  //}else{
  //  imageMode(CORNER);
  //  image(aireSImg,500,300 ,350,350);
  //  fill(0);
  //textSize(20);
  //text("AIRE CONTAMINADO",600,300);
  //}
  
  stroke (0,0,0);
  fill (255,255,255);
  rect(350,290,80,500);
  stroke (255,255,255);
  fill (255,0,255);
  rect(350,500+r,80,290-r);
  
}


void serialEvent(Serial port){
 if(aux==0){
      r=port.read();
      println(r);
      aux++;
    }
    else if(aux==1){
      r2=port.read();
      println(r2);      
      aux++;
    }else if(aux==2){
      r3=port.read();
      println(r3);
      aux=0;
    }
}
