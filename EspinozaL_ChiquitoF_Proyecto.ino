#include "DatosSensores.h"

//variables
// datos de prueba

int respuesta;
int MQ135=0;
int MQ7=1;
int knn (int k, int etiquetas, int tam_col, int tam_fil); // definir la funccion

void setup() {
Serial.begin(9600);
}

void loop() {
respuesta=knn(3,2,3,100);
  /////PROCESSING/////////////
Serial.write(respuesta);
delay(2);
Serial.write(MQ135);
delay(2);
Serial.write(MQ7);
delay(2);
   // llamada al metodo 
// switch(respuesta){
//  case 1:
//    Serial.println(MQ135);
//    Serial.println(MQ7);
//    Serial.println("Prediccion KNN: Aire Limpio");
//    Serial.println(respuesta);
//    Serial.println(" ");
   
//  break;
//  case 2:
//    Serial.println(MQ7);
//    Serial.println(MQ135);
//    Serial.println("Prediccion KNN: Aire Contaminado");
//    Serial.println(respuesta);
//    Serial.println(" ");
//  break;
//  }
//  delay(1000);
 }

int knn (int k, int etiquetas, int tam_col, int tam_fil){
MQ135=analogRead(0);
MQ7=analogRead(1);
int col;
int fil=0;
int i=0;
int j;
float aux;
float aux_etiqueta;
float potencia;
float raiz;
int label;
String salida="";
float datos_prueba[2]={MQ135,MQ7};

 float matriz_k [3][k];
 for(;i<k;i++){
  matriz_k[0][i]=i+1.00; 
  matriz_k[1][i]=0; 
  matriz_k[2][i]=2500.0+i; 
  }
  i=0;
 /*
  *  matriz de etiquetas
  *  |1  |2  |3  | -> # de etiquetas
  *  |2  |1  |0  | -> el conteo de cada una de ellas con respecto a matriz k_vecinos   
  */
  float matriz_eti[2][etiquetas];
  for(;i<etiquetas;i++){
      matriz_eti[0][i]=i+1.0; // |  1 |  2 |  3  |
      matriz_eti[1][i]=0.0;   // |  0 |  0 |  0  |
    }

   for(;fil<tam_fil;fil++){
      for(col=0;col<tam_col-1;col++){ // menos la ultima columna que corresponde a la etiqueta
          potencia=potencia+pow(matriz[fil][col]-datos_prueba[col],2);
        }
        raiz=sqrt(potencia);
        potencia=0;
        // comparacion de la nueva distancia con solo la mayor distancia almacenada en matriz_k
        if(raiz<matriz_k[2][k-1]){
          matriz_k[2][k-1]=raiz;
          matriz_k[1][k-1]=matriz[fil][tam_col-1]; 
          // ordenar matriz por metodo de burbuja
          for(i=0;i<k;i++){
             for(j=i+1;j<k;j++){
               if(matriz_k[2][i]>matriz_k[2][j]){
                 // distancia
                  aux=matriz_k[2][i];
                  matriz_k[2][i]=matriz_k[2][j];
                  matriz_k[2][j]=aux;
                  //etiqueta
                  aux_etiqueta=matriz_k[1][i];
                  matriz_k[1][i]=matriz_k[1][j];
                  matriz_k[1][j]=aux_etiqueta;
                }//end if
              } //end for j
            } // end for i
        } // end if
    } // end lectura matriz.h
    //buscar etiqueta con mayor repitencia
    for(i=0;i<etiquetas;i++){
      for(j=0;j<k;j++){
          if(matriz_eti[0][i]==matriz_k[1][j]){
            matriz_eti[1][i]++;
          }
        }
      }
    for(i=0;i<etiquetas-1;i++){
       if(matriz_eti[1][i]<matriz_eti[1][i+1]) // buscar el valor menor entre conteo de etiquetas
        label=(int)matriz_eti[0][i+1];    //asgina a label la etiqueta de mayor valor
        else 
        label=(int)matriz_eti[0][i];      //asgina a label la etiqueta de mayor valor
      }   
 return label;
};

