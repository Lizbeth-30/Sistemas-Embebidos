
#define tam_sig 100 //tamaño de la señal

extern double ecg[tam_sig];
double output_signal[tam_sig];
double senialNR[tam_sig];

void mean (double *sig_in, double *output_signal, int sig_tam, int filter);
void plot_signal(void);

void setup() {
  Serial.begin(9600);

}

void loop() {
  mean ((double *)&ecg[0], (double *)&output_signal[0], (int) tam_sig,9);
  sruido();
  plot_signal();
  delay(100);

}

//////SUAVIZADO DE  LA SEÑAL ////////////////////////////
void mean (double *sig_in, double *output_signal, int sig_tam, int filter){
  int i,j;
  for(i=(filter/2);i<sig_tam-(filter/2)-1;i++){
    output_signal[i]=0;
    for(j=-(filter/2);j<(filter/2);j++){
        output_signal[i]=output_signal[i]+sig_in[i+j];
      }
      output_signal[i]=output_signal[i]/filter;
    }
  }

void sruido(){
  double ru1 [tam_sig];
  double ru2 [tam_sig];
  for(int i=0;i<tam_sig;i++){
    ru1[i]=pow(ecg[i],2);
    ru2[i]=pow((ecg[i]-output_signal[i]),2);
    senialNR[i]=10*log(ru1[i]/ru2[i]); 
    }
  }

void plot_signal(void){ //puede ir sin void pero se pone para una manera mejor estrutura 
  int i;
  for(i=0;i<tam_sig;i++){
    Serial.print(ecg[i]);
    Serial.print(",");
    Serial.print(output_signal[i]);
    Serial.print(",");
    Serial.println(senialNR[i]);
    delay(5);
  }
}
