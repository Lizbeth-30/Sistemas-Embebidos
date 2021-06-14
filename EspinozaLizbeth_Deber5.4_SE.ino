
int verde=3;
int ama=5;
int rojo=7;

void setup() // Metodo de configuraciones
{
//Declaramos los pines de salida (uno por cada led)
  pinMode(verde,OUTPUT);
  pinMode(ama,OUTPUT);
  pinMode(rojo,OUTPUT);
}

void loop() //Bucle de iteraciones (por defecto)
{
  digitalWrite(verde,HIGH);//Encendemos luz verde
  delay(4000);//Pasan 4 segundos
  digitalWrite(verde,LOW);//Apagamos luz verde
  delay(500); //Pasa medio segundo
  digitalWrite(verde,HIGH);//Se enciende luz verde (1er parpadeo)
  delay(500); //Pasa medio segundo
  digitalWrite(verde,LOW);//Apagamos luz verde
  delay(500); //Pasa medio segundo
  digitalWrite(verde,HIGH);//Se enciende luz verde (2ndo parpadeo)
  delay(500); //Pasa medio segundo
  digitalWrite(verde,LOW);//Apagamos luz verde
  digitalWrite(ama,HIGH); //Encendemos luz amarilla
  delay(2000);//Pasan 2 segundos
  digitalWrite(ama,LOW);//Apagamos luz amarilla
  digitalWrite(rojo,HIGH);//Encendemos Luz Roja
  delay(4000); //Pasan 4 segundos
  digitalWrite(rojo,LOW);//Apagamos Luz roja
  //Vuelve a repetirse todo desde el inicio ya que es un bucle
}
