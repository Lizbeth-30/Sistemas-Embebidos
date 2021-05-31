#define tam_sig 70
extern double flex_sensor[tam_sig];
double output_signal2[tam_sig];
double senialNR2[tam_sig];
void median(double *sig_in, double *output_signal2, int sig_tam, int num);
void plot_signal(void);

void setup() {
  Serial.begin(9600);

}

void loop() {
  median((double *)&flex_sensor[0], (double *)&output_signal2[0], (int) tam_sig,5);
  sruido2();
  plot_signal();
  delay(100);

}

//////SUAVIZADO DE  LA SEÑAL MEDIANA ////////////////////////////

void median (double *sig_in, double *output_signal2, int sig_tam, int num ) {
int i, j, k, cond=0, senial;
int aux[num];

  while(cond<tam_sig){
   for(k=0;k<num;k++){
     aux[k]=flex_sensor[k+cond];
    }
    for(j=0;j<(num-1);j++){
      for(i=j+1;i<num;i++){
        if(aux[i]<aux[j]){
          senial=aux[i];
          aux[i]=aux[j];
          aux[j]=senial;
        }
        
      }
      
    }
    
    output_signal2[cond]=aux[1];

    cond++;
  }


}

void sruido2(){
    double ru1 [tam_sig];
    double ru2 [tam_sig];
  for(int i=0;i<tam_sig;i++){
    
    ru1[i]=pow(flex_sensor[i],2);
    ru2[i]=pow((flex_sensor[i]-output_signal2[i]),2);
    senialNR2[i]=10*log(ru1[i]/ru2[i]); 
    }
  }

void plot_signal(void){ 
  int i;
  for(i=0;i<tam_sig;i++){
    Serial.print(flex_sensor[i]-50);
    Serial.print(",");
    Serial.print(output_signal2[i]);
    Serial.print(",");
    Serial.println(senialNR2[i]);
    delay(5);
  }
}
