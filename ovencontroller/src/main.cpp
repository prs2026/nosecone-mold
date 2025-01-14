#include <Arduino.h>


//voltage divider values
int r1 = 1000;
int vs = 5;


//ntc cal values
float a = 1.394e-3;
float b = 1.766e-4;
float c = 4.214e-7;


void setup() {
  // put your setup code here, to run once:
  pinMode(A1,INPUT);
  Serial.begin(115200);
}

void loop() {
  int value = analogRead(A1);
  int resistance = r1*((vs/value)-1);
  float temp = pow(a+b*log(resistance)+c*(pow(log(resistance),3)),-1);
  printf("value: %d, resistance: %d, temp: %f",value,resistance,temp);
  

  // put your main code here, to run repeatedly:
}

