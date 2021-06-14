/*
 * RETO N°4
 * NOMBRE: Lizbeth Espinoza
 */

char l1 = ' ';
#define led 7

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop() {
  if (Serial.available()) {
    l1 = Serial.read();
    Serial.print(l1);
    if(l1 == 'H'){
      digitalWrite(led, HIGH);
    }
    else if(l1 == 'L'){
      digitalWrite(led, LOW);
    }
  }
}
