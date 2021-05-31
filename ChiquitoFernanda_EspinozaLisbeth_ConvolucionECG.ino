#define tam_sig 100 //tamaño de la señal
#define tam_imp 21
extern double ecg[tam_sig];
extern double Impulse_response[tam_imp];
double output[tam_sig+tam_imp];
double senialNR[tam_sig];
void convolucion(double *sig_in,double *sig_out, double *imp, int sig_tam, int imp_tam);
void plot_signal(void);

void setup() {
  
  Serial.begin(9600);

}

void loop() {
  convolucion((double *)&ecg[0], (double *)&output[0], (double *)&Impulse_response[0],
              (int) tam_sig, (int) tam_imp);
 sruido();
 plot_signal();

}
void convolucion(double *sig_in,double *sig_out, double *imp, int sig_tam, int imp_tam){
  int i,j;
  
  for(i=0;i<(sig_tam+imp_tam);i++){
    sig_out[i]=0;
  }
  for(i=0;i<sig_tam;i++){
    for(j=0;j<imp_tam;j++){
      sig_out[i+j]=sig_out[i+j]+sig_in[i]*imp[j];
    }
  }
}
void sruido(){
  double ru1 [tam_sig];
  double ru2 [tam_sig];
  for(int i=0;i<tam_sig;i++){
    ru1[i]=pow(ecg[i],2);
    ru2[i]=pow((ecg[i]-output[i]),2);
    senialNR[i]=10*log(ru1[i]/ru2[i]); 
    }
  }

void plot_signal(void){  
  int i;
  for(i=0;i<tam_sig;i++){
    Serial.print(ecg[i]+10);
    Serial.print(",");
    Serial.print(output[i]+5);
    Serial.print(",");
    Serial.println(senialNR[i]-10);
    delay(5);
  }}
