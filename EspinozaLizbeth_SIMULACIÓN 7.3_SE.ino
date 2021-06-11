/*
* CAPÍTULO 7: APRENDIZAJE DE MÁQUINA
* PROGRAMA 32: REGRESIÓN LINEAL
* OBJETIVO: Generar un modelo de regresión lineal estatura -> peso
* NOMBRE: Lizbeth Espinoza
*/
// matriz de datos
int matriz[8][2]={
{173,145},
{167,135},
{158,130},
{167,136},
{180,178},
{175,115},
{174,125},
{160,138},
};
int col=0; // variable que se mueve en filas
int fil=0; // variable que se mueve en columnas
int Ex=0; // sumatoria de X
int Ey=0; // sumatoria de Y
long int Exy=0; // sumatoria de xy
long int Ex2=0; // sumatoria de x^2
long int Ex_2=0; // sumatoria de (Ex)^2
long int n=8; // tamaño de datos
float Bo; // ordenada en el origen
float m; // pendiente
int m1; // auxiliar
String dato; // recibe datos por cx serial
int estatura; // conversión de dato
int respuesta; // responder
void setup() {
Serial.begin(9600);
//creación del modelo
for(;fil<n;fil++){
Ex=Ex+matriz[fil][0];
Ey=Ey+matriz[fil][1];
Exy=Exy+(matriz[fil][0]*matriz[fil][1]);
Ex2=Ex2+pow(matriz[fil][0],2);
}
Ex_2=pow(Ex,2);
// Serial.println(String(Ex)+String(":")+String(Ey)+String(":")+String(Exy)+
//String(":")+String(Ex2)+String(":")+String(Ex_2)+String(":"));
Bo=(float(Ex2*Ey)-float(Ex*Exy))/float(n*Ex2-Ex_2);
// long int m1= float((n*Exy)-(Ex*Ey))/float(n*Ex2-Ex_2);
m1=(n*Exy)-(Ex*Ey);
m=float(m1)/float(n*Ex2-Ex_2);
Serial.println("El modelo es:");
Serial.println(String("y=")+String(Bo)+String("+")+String(m)+String("X"));
Serial.println("Ingrese su estatura:");
}
void loop() {
if(Serial.available()>0){ // revisa dato de entrada
dato=Serial.readString(); // dato en string
estatura= dato.toInt(); // convierte a entero
respuesta=Bo+m*estatura; // genera el pronóstico
Serial.print("su peso es:"); // imprime mensaje
Serial.println(respuesta);
}
}