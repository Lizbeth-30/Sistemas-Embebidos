import processing.serial.*;
import ddf.minim.*;
import controlP5.*;

ControlP5 cp5;
Serial port;
Nave nve = new Nave();
//contenedor
ArrayList<Bala> balas = new ArrayList<Bala>();
ArrayList<Bomba> bombas = new ArrayList<Bomba>();
ArrayList<Enemigo> enemigos = new ArrayList<Enemigo >();

int puntos=0;
int puntos1=0;
int ene=10;
int level=1;

char dato;
int code;

boolean titulo = true;
boolean pausa = false;
boolean start = false;
boolean ganar = false;

PImage imgNave;
PImage imgBala;
PImage imgBomba;
PImage imgNaveE;

boolean Sonido1 = true;

boolean Musica2= true;

// Iniciar biblioteca y se define sonidos a usar en el juego
Minim minim;
AudioPlayer sonido_musica;
AudioPlayer disparo;
AudioPlayer estrello;
AudioPlayer perder;

void setup() {
  size(600, 600);
  background(0);
  fill(255);
  stroke(255);
  port= new Serial(this, "COM4", 9600);
  //
  imgNave = loadImage("nave.png");
  imgBomba = loadImage("bomba.png");
  imgBala = loadImage("bala.png");
  imgNaveE = loadImage("navee1.png");
  imageMode(CENTER);

  minim = new Minim(this);
  sonido_musica = minim.loadFile("musica.mp3");
  disparo = minim.loadFile("disparo.mp3");
  estrello = minim.loadFile("estrellonave.mp3");
  perder = minim.loadFile("perder.mp3");

  cp5=new ControlP5(this);
  //boton
  cp5.addButton("Musica")
    .setPosition(width/2-60, height -15)
    .setSize(55, 15)
    .setColorBackground(#A99BFF) //color azul     #F51111
    .setColorActive(#FF9BAF)//color rojo     #E39595
    .setColorForeground(#9BFFB6)//color verde
    ;
  cp5.addButton("Sonido")
    .setPosition(width/2+5, height-15)
    .setSize(55, 15)
    .setColorBackground(#A99BFF) //color azul     #F51111
    .setColorActive(#FF9BAF)//color rojo     #E39595
    .setColorForeground(#9BFFB6)//color verde
    ;
}


void draw() {

  if (!pausa) {
    if (ganar) {
      stroke(0);
      strokeWeight(2);
      fill(255);
      textAlign(CENTER, CENTER);
      textSize(100);
      text("Ganó", width/2, height/2);
      textSize(70);
      strokeWeight(2);
    }
    if (titulo) {
      background(#CDEEF5);//color PP  #FFCC00
      pantalla_titulo();
      fill(255);
    } 
    if (start) {
      background(0);
      nve.avanzar();
      nve.dibujar();
      for (Bala x : balas) {
        x.avanzar();
        x.dibujar();
      }
      for (Enemigo x : enemigos) {
        x.avanzar();
        x.dibujar();
      }
      for (Bomba x : bombas) {
        x.avanzar();
        x.dibujar();
      }
      colisionBalaEnemigo();
      colisionBombaBala();

      colisionBombaNave();
      //colisionEnemigoNave();

      eliminarBalasPerdidas();
      eliminarBombasPerdidas();

      puntaje();
      //
      if (Musica2) {
        if (sonido_musica.isPlaying()) {
        } else { 
          sonido_musica.rewind();
          sonido_musica.play();
        }
      }
    }
  }
}
void keyPressed() {


  nve.teclaApretad(keyCode);
  if (keyCode== 69 ) {
    bombas.removeAll(bombas);
    balas.removeAll(balas);
    enemigos.removeAll(enemigos);
    ene=10;
  }
  if (keyCode== 82 ) {
    for (int i =0; i<ene; i++) {
      Enemigo nvoEnemigo = new Enemigo(i*15+10);
      enemigos.add(nvoEnemigo);
    }
    level=1;
    puntos=0;
    puntos1=0;
  }
  if ((keyCode == 10 && !pausa)||(keyCode == 10 && !pausa)) {
    start = !start;
    titulo = !titulo;
  }
  if (ganar) {
    ganar = false;
    start = false;
    titulo = true;
  }
  if ((keyCode == 80 && start)||(keyCode == 80 && !pausa)) {
    pausa = !pausa;
    sonido_musica.pause();
  }
}

void keyReleased() {
  nve.teclaSoltada(keyCode);
}
//------------------------------------
//Eliminar Balas y Bombas
void eliminarBalasPerdidas() {
  ArrayList<Bala> balasElim = new ArrayList<Bala>();
  for (Bala b : balas) {
    if (b.y <0) {
      balasElim.add(b);
    }
  }
  balas.removeAll(balasElim);
}

void eliminarBombasPerdidas() {
  ArrayList<Bomba> bombasElim = new ArrayList<Bomba>();
  for (Bomba b : bombas) {
    if (b.y > 590) {
      bombasElim.add(b);
    }
  }
  bombas.removeAll(bombasElim);
}
//Colision Balas Bombas
void colisionBalaEnemigo() {
  ArrayList<Bala> balasElim = new ArrayList<Bala>();
  ArrayList<Enemigo> enemigosElim = new ArrayList<Enemigo>();
  for (Bala b : balas) {
    for (Enemigo e : enemigos) {
      float dist =sqrt(pow(b.x-e.x, 2) + pow(b.y - e.y, 2));// formula de distancia
      if (dist<20) {
        balasElim.add(b);
        enemigosElim.add(e);
        puntos= puntos+10;
        puntos1=puntos1+1;
        if (Sonido1) {
          estrello.play();
          estrello.rewind();
        }
      }
    }
  }
  balas.removeAll(balasElim);
  enemigos.removeAll(enemigosElim);
}

void colisionBombaBala() {
  ArrayList<Bala> balasElim = new ArrayList<Bala>();
  ArrayList<Bomba> bombasElim = new ArrayList<Bomba>();
  for (Bala ba : balas) {
    for (Bomba bo : bombas) {
      float dist =sqrt(pow(bo.x-ba.x, 2) + pow(bo.y - ba.y, 2));// formula de distancia
      if (dist<10) {
        balasElim.add(ba);
        bombasElim.add(bo);
      }
    }
  }
  balas.removeAll(balasElim);
  bombas.removeAll(bombasElim);
}

// choque con la nave
void colisionBombaNave() {
  for (Bomba b : bombas) {
    float dist=sqrt(pow(b.x-nve.x, 2)+pow(b.y - nve.y, 2));
    if (dist <15) {
      perder();
      sonido_musica.pause();
      println("hasta luego");
      if (Sonido1) {   
        perder.play();
        perder.rewind();
      }
    }
    //else {
    //  if (sonido_musica.isPlaying()) {
    //  } else { 
    //    sonido_musica.rewind();
    //    sonido_musica.play();
    //  }
    //}
  }
}

void colisionEnemigoNave() {
  for (Enemigo e : enemigos) {
    float dist=sqrt(pow(e.x-nve.x, 2)+pow(e.y - nve.y, 2));
    if (dist <15) {
      perder();
      sonido_musica.pause();
      if (Sonido1) {    
        perder.play();
        perder.rewind();
      }
      //exit();
    }
  }
}
//------------------------------------

class Nave {
  int x=300;
  int y=560;
  boolean derecha = false;
  boolean izquierda = false;
  void dibujar() {
    //ellipse(x, y, 10, 10);
    image(imgNave, x, y);
  }
  void avanzar() {
    if (dato == '0') {
      derecha=false;
      izquierda=false;
    }
    if (dato == '1') {
      izquierda=true;
    }    
    if (dato == '2') {
      derecha=true;
    }
    if (dato=='3') {
      Bala aux = new Bala(x, y);
      balas.add(aux);
       if (Sonido1) {
        disparo.play();
        disparo.rewind();
      }
    }
    //avance
    if (derecha) {
      x=x+3;
    }
    if (izquierda) {
      x=x-3;
    }
    if (x >600) {
      izquierda =true;
    }
    if (x<0) {
      derecha= true;
    }
  }
  void teclaApretad(int code) {

    if (code == 39) {
      derecha=true;
    } 
    if (code ==37) {
      izquierda=true;
    }
    if (code ==32) {
      //disparar
      Bala aux = new Bala(x, y);
      balas.add(aux);
      if (Sonido1) {
        disparo.play();
        disparo.rewind();
      }
    }
  }
  void teclaSoltada(int code) {
    if (code ==39) {
      derecha=false;
    } 
    if (code ==37) {
      izquierda=false;
    }
  }
}
class Bomba {
  int x=0;
  int y=0;
  //constructor
  Bomba(int px, int py) {
    x=px;
    y=py;
  }
  void dibujar() {

    image(imgBomba, x, y);
    //ellipse(x, y, 5, 5);
  }
  void avanzar() {
    y= y+3;
  }
}

class Bala {
  int x=0;
  int y=0;
  //constructor
  Bala(int px, int py) {
    x=px;
    y=py;
  }
  void dibujar() {
    image(imgBala, x, y);
    //ellipse(x, y, 5, 5);
  }
  void avanzar() {
    y= y-4;
  }
}

class Enemigo {

  int x=0;
  int y=0;
  int oldy=0;
  boolean derecha=true;
  boolean atqPicada= false;
  //constructor
  Enemigo(int py) {
    y=py;
    x= int(random(10, 590));
    int coin = int(random(0, 10));
    if (coin <5) {
      derecha=true;
    } else {
      derecha=false;
    }
  }
  void dibujar() {
    image(imgNaveE, x, y);
    //ellipse(x, y, 15, 15);
  }
  void avanzar() {
    if (atqPicada) {
      y= y+4;
      //perseguir a la nave
      if (nve.x > x) {
        x = x +2;
      } else {
        x=x-2;
      }
      //se pone arriba la nave enemiga
      if (y >590) {
        y=5;
      }
      if (y < oldy+3 && y >oldy -2) {
        atqPicada=false;
      }
    } else
    {
      if (derecha) {
        x= x+2;
      } else {
        x=x-2;
      }
      if (x >590) {
        derecha =false;
      }
      if (x<10) {
        derecha= true;
      }
    }
    int moneda = int(random(0, 300));
    if (moneda ==5) {
      Bomba nvaBomba = new Bomba(x, y);
      bombas.add(nvaBomba);
    }
    // ---
    int coin = int (random(0, 800));
    if (coin ==7) {
      oldy= y;
      atqPicada=true;
    }
    //----
  }
}
//puntaje
void puntaje() {
  textSize(20);
  fill(#FCAD85);
  text("Puntos: "+puntos, width-60, 590);
  textSize(20);
  fill(#91D4D6);
  text("Level: "+level, 50, 590);
  if (puntos1==ene) {
    ene= ene+5;
    level++;
    puntos1=0;
    println(ene);
    println(puntos1);
    for (int i =0; i<ene; i++) {
      Enemigo nvoEnemigo = new Enemigo(i*15+10);
      enemigos.add(nvoEnemigo);
    }
    if (level == 3) {
      ganar = true;
      start = false;
    }
  }
}
//puerto serial
void serialEvent(Serial port) {
  dato=port.readChar();
}

//pantala 
void pantalla_titulo() {
  background(0);
  stroke(0);
  fill(0);
  PFont font;
  font =loadFont("CopperplateGothic-Bold-48.vlw");
  textFont(font);
  textAlign(CENTER, CENTER);
  textSize(40);
  fill(#91D4D6);
  text("BIENVENIDOS", width/2, height*0.2);
  text("¿LISTOS PARA JUGAR?", width/2, height*0.35);
  fill(#FCAD85);
  text("Here we go again", width/2, height*0.55);
  PFont font1;
  font1 =loadFont("ComicSansMS-BoldItalic-48.vlw");
  textFont(font1);
  textSize(25);
  fill(255);
  text("JUGAR ->Enter                   PAUSE ->P", width/2, height*0.8);
  textSize(20);
  fill(#F6FF7C);
  text("@Copyright", width/2, height*0.95);
}
void perder() {
  stroke(0);
  strokeWeight(2);
  fill(255);
  textAlign(CENTER, CENTER);
  textSize(100);
  text("Game Over", width/2, height/2);
  textSize(70);
  strokeWeight(2);
  start = false;
}

public void Musica() {
  Musica2 = !Musica2;
 sonido_musica.pause();
}

public void Sonido() {
  Sonido1= !Sonido1;
}
