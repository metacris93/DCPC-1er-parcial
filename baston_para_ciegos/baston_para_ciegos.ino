#include <SoftwareSerial.h>

#define pin_echo1 6
#define pin_trig1 7
#define pin_echo2 3
#define pin_trig2 4
#define led 13
SoftwareSerial B(10, 11); // RX, TX
long duracion1, distancia1, duracion2, distancia2;
int flag=0, estado;

void setup() {
  Serial.begin(9600);
  B.begin(9600);
  pinMode(pin_echo1, INPUT);
  pinMode(pin_trig1, OUTPUT);
  pinMode(pin_echo2, INPUT);
  pinMode(pin_trig2, OUTPUT);
  pinMode(led,OUTPUT);
}

void primer_sensor(){
  int duracion1, distancia1;
  digitalWrite(pin_trig1,HIGH);
  delayMicroseconds(10);
  digitalWrite(pin_trig1,LOW);
  duracion1 = pulseIn(pin_echo1,HIGH);
  distancia1 = (duracion1/2)/29; //la distancia esta en centimetros 
  if( distancia1 <= 70 && distancia1 > 10){
      Serial.println("Sensor1...");
      Serial.print(distancia1);
      Serial.println(" cm");
      flag = 1;
      digitalWrite(led,HIGH);
      B.println(1);
  }else if(flag != 2){
      Serial.println("...x1");
      Serial.print(distancia1);
      Serial.println(" cm");
      flag = 0;
      digitalWrite(led,LOW);
      B.println(0);
  }
}

void segundo_sensor(){
  int duracion2, distancia2;
  digitalWrite(pin_trig2,HIGH);
  delayMicroseconds(10);
  digitalWrite(pin_trig2,LOW);
  duracion2 = pulseIn(pin_echo2,HIGH);
  distancia2 = (duracion2/2)/29; //la distancia esta en centimetros 
  
   if( distancia2 > 20){
      Serial.println("Sensor2...");
      Serial.print(distancia2);
      Serial.println(" cm");
      flag =2;
      digitalWrite(led,HIGH);
      B.println(2);
  }else if(flag != 1){
      Serial.println("...x2");
      Serial.print(distancia2);
      Serial.println(" cm");
      flag = 0;
      digitalWrite(led,LOW);
      B.println(0);
  }
}

void loop() {
  Serial.println("\n");
  primer_sensor();
  delay(1000);
  segundo_sensor();  
  delay(400);
}
