  /*
*  Filtro MQ_7 AIRE LIMPIO
*/

#define tam_sig 100       //tamaño de la señal de entrada
extern double mq_7[tam_sig];//llamar a la señal
int senal;               //variable donde se guarda el resultado del filtro
double promOri;          // variable donde se guarda promedio de la señal original
double promFilt;         //variable donde se guarda promedio de la señal filtrada
double output[tam_sig];  //vector de salida
double vector[5];       //vector que almacenar los datos de filtrado
void mediana_filtro (double *sen_in, double *salida_sen, int sen_tam, int filtro); // define funcion
void plot_signal(void); //metodo para imprimir la señal 
void setup() {
  Serial.begin(9600);  // Comunicación Serial
}
void loop() {
  gauss_filtro ((double *)&mq_7[0], (double *)&output[0], (int) tam_sig,5); //llamar al metodo gauss
  plot_signal(); //metodo para imprimir la señal
  SNR(); //Metodo SNR (ratio de ruido de la señal)
  delay(150);  //temporizador
}
//Filtro gaussiano
void gauss_filtro (double *sig_in, double *output, int sig_tam, int filtrado){//metodo gausssiano
int i,j,k;//variables
  for(k=0;k<sig_tam;k++){ //ciclo para el metodo de gauss
    vector[0]=sig_in[k+0];//remplazo de la señal a la posicion del vector uno
    vector[1]=sig_in[k+1];//remplazo de la señal a la posicion del vector dos
    vector[2]=sig_in[k+2];//remplazo de la señal a la posicion del vector tres
    vector[3]=sig_in[k+3];//remplazo de la señal a la posicion del vector cuatro
    vector[4]=sig_in[k+4];//remplazo de la señal a la posicion del vector cinco
    i=0;//inicio de variable
    while(i<=3){//en la tercera posicion
      i++;//aumento de valor
      j=i+1;//valor de i+1
      while(j<=4){
        j++;
        if(vector[j]<vector[i]){//si la posicion del vector es menor 
          senal=vector[j];//reemplaza el valor de la posicion del vector en la variable senal
            vector[j]=vector[i];//si el vector es igual
            vector[i]=senal;//remplaza el valor de senal en vector[posicion]
        }
      }
    }
    output[k]=vector[1];//salida del resultado
  }
  }
void plot_signal(void){ //metodo para imprimir la señal
  int i; //variable 
  for(i=0;i<tam_sig;i++){//ciclo repetitivo para recorrer la señal
      Serial.print(mq_7[i]);//posicion del dato
      Serial.print(",");
      Serial.print((output[i]));//salida del resultado señal metodo gauss
      Serial.println(",");
    delay(100);//temporizador
  }
}
//Metodo SNR
void SNR(){
  int i;//variable
  for(i=0;i<100;i++){//ciclo reccorre segun el numero de datos de la señal
    promOri=promOri+mq_7[i];//guarda los valores del promedio en cada punto 
    }
   double promOri1 = promOri/100;//lo divide para el numero de datos de la señal
   for(i=0;i<100;i++){
    promFilt=promFilt+output[i];
    }
   double promFilt2 = promFilt/100;// divide para el numero de datos de la señal filtrada
   double vout = (promOri1*5)/1023;// voltaje de salida
   double vfilt = (promFilt2*5)/1023;//voltaje de filtrado
   double snr = 20*log(vfilt/vout);
  Serial.println("");
  Serial.println(String("Promedio señal ingresada: ")+String(promOri1));
  Serial.println(String("Promedio señal filtrada: ")+String(promFilt2));   
  Serial.println(String("Voltaje de salida señal ingresada: ")+String(vout));
  Serial.println(String("Voltaje de salida señal filtrada: ")+String(vfilt)); 
  Serial.println(String("SNR: ")+String(snr)+String(" decibeles"));   
  }