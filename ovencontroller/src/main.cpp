#include <Arduino.h>
//#include <Servo.h>

//voltage divider values
double r2 = 1000.00;
double vin = 5.00;
//float fudgefactor = ;

// //controller values
// int setpoint = 150;
// float kp = 0.1;
// int servomin = 10;
// int servomax = 90;

//ntc cal values
double a = 1.394e-3;
double b = 1.766e-4;
double c = 4.214e-7;

//Servo servo;

void setup() {
  // put your setup code here, to run once:
  pinMode(A1,INPUT);
  //servo.attach(10);
  Serial.begin(9600);
  Serial.print("init");
}

void loop() {
  //read analog input
  int value = analogRead(A1);

  //map the analog to a voltage
  double vout = map(double(value),0,1023,0.00,5000)/1000.00;

  //map the voltage to a resistance
  double resistance = r2*((vin-vout)/vout);

  //map the resistance to temp
  double temp = 1/(a+(b*log(resistance))+(c*(pow(log(resistance),3))));
  temp = ((temp-273)*1.8)+32; // convert to f from k
  //print out value
  // Serial.print("value:");
  // Serial.print(value);
  // Serial.print(" voltage:");
  // Serial.print(vout);
  // Serial.print(" resistance: ");
  // Serial.print(resistance);
  Serial.print(">temp: ");
  Serial.println(temp);
  delay(100);

  //controller
  // float error = setpoint-temp;
  // float output = error*kp;
  // output = constrain(output,10,110);
  // servo.write(output);
}

