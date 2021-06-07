/*
 * CAPÍTULO 5: FUNCIONES ESPECÍFICAS
 * CODIGO 25: Creación de funciones en RTOS
 * OBJETIVO: Ejecutar tareas directamente en el Kernel del uC.
 * NOMBRE: Lizbeth Espinoza
 */
 
#include <Arduino_FreeRTOS.h> // librería de RTOS
// LEDS EN ARDUINO PARA SIMULACIÓN DE PROCESOS
 
#define RED 8
#define YELLOW 7
#define BLUE 6
//objeto del gestor tareas
typedef int TaskProfiler;
//definir las tareas
TaskProfiler redLEDProfiler;
TaskProfiler yellowLEDProfiler;
TaskProfiler blueLEDProfiler;

void setup() {
Serial.begin(9600);
//crear las rutinas de cada tarea
xTaskCreate(redLedControllerTask,"Red LED Task",100,NULL,1,NULL); //rutina,nombre,memoria,NULL,prioridad,NULL
xTaskCreate(blueLedControllerTask,"Blue LED Task",100,NULL,1,NULL); //rutina,nombre,memoria,NULL,prioridad,NULL
xTaskCreate(yellowLedControllerTask,"Yellow LED Task",100,NULL,1,NULL); //rutina,nombre,memoria,NULL,prioridad,NULL
}

void redLedControllerTask(void *pvParameters){//tarea 1
  pinMode(RED,OUTPUT);
  while(1){
      //Serial.println("Proceso led rojo");
      redLEDProfiler++;
      Serial.print("RED TASK:");
      Serial.println(redLEDProfiler);
      digitalWrite(RED,digitalRead(RED)^1);
      vTaskDelay(50);
    }
}
void blueLedControllerTask (void *pvParameters){
 pinMode(BLUE,OUTPUT);
  while(1){
    //Serial.println("Proceso led azul");
      blueLEDProfiler++;
      Serial.print("BLUE TASK:");
      Serial.println(blueLEDProfiler);
      digitalWrite(BLUE,digitalRead(BLUE)^1);
      vTaskDelay(50);
    } 
 }
void yellowLedControllerTask (void *pvParameters){
 pinMode(YELLOW,OUTPUT);
 while(1){
    //Serial.println("Proceso led amarillo");
      yellowLEDProfiler++;
      Serial.print("YELLOW TASK:");
      Serial.println(yellowLEDProfiler);
      digitalWrite(YELLOW,digitalRead(YELLOW)^1);
     vTaskDelay(50);
  } 
 }
void loop() {
}
