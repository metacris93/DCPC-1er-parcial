#define pin_echo1 6
#define pin_trig1 7
#define pin_echo2 3
#define pin_trig2 4
#define led 13
long duracion1, distancia1, duracion2, distancia2;
int flag=0;
void setup() {
  Serial.begin(9600);
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
  if( distancia1 <= 50 && distancia1 > 10){
    Serial.println("Sensor1...");
    Serial.print(distancia1);
    Serial.println(" cm");
    flag = 1;
      digitalWrite(led,HIGH);
  }else if(flag != 2){
      Serial.println("...x1");
    Serial.print(distancia1);
    Serial.println(" cm");
    flag = 0;
    digitalWrite(led,LOW);
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
  }else if(flag != 1){
      Serial.println("...x2");
    Serial.print(distancia2);
    Serial.println(" cm");
    flag = 0;
    digitalWrite(led,LOW);
  }
}
void loop() {
  Serial.println("\n");
  primer_sensor();
  delay(500);
  segundo_sensor();
 /* //digitalWrite(pin_trig1, LOW);
  //delayMicroseconds(2);
  digitalWrite(pin_trig2, LOW);
  delayMicroseconds(2);
  //digitalWrite(pin_trig1, HIGH);
  //delayMicroseconds(10);
  digitalWrite(pin_trig2, HIGH);
  delayMicroseconds(10);
  //digitalWrite(pin_trig1, LOW);
  digitalWrite(pin_trig2, LOW);
  
  //duracion1 = pulseIn(pin_echo1,HIGH);
  //distancia1 = (duracion1/2)/29; //la distancia esta en centimetros
  
  duracion2 = pulseIn(pin_echo2,HIGH);
  distancia2 = (duracion2/2)/29; //la distancia esta en centimetros
  //Serial.println("Sensor 1:");
  //Serial.println(duracion1);
  Serial.println("Sensor 2:");
  Serial.println(distancia2);*/
  /*if( distancia1 <= 50 && distancia1 > 10 && distancia2 < 20 ){ // si distancia es mayor a 500 cm o menor a 0, no hace nada    
    Serial.println("Alarma1...");
    Serial.print(distancia1);
    Serial.println(" cm");
    digitalWrite(led,HIGH);
  }
  if(distancia2 > 20 && !(distancia1 <= 50 && distancia1 > 10)){
    Serial.println("Alarma2...");
    Serial.print(distancia2);
    Serial.println(" cm");
    digitalWrite(led,HIGH);
  }
  if( distancia2 < 20 && !(distancia1 <= 50 && distancia1 > 10) ){
    Serial.println("...");
    Serial.print(distancia2);
    Serial.println(" cm");
    digitalWrite(led,LOW); 
  }*/
  
  /*else if(distancia2 >=20){
    Serial.println("Alarma2...");
    Serial.print(distancia2);
    Serial.println(" cm");
    digitalWrite(led,HIGH);  
  }else if (distancia2 < 20){
    Serial.println("...x2");
    Serial.print(distancia2);
    Serial.println(" cm");
    digitalWrite(led,LOW);
  }else if (distancia1<= 10 || distancia1 > 50){
    //Serial.println("---");
    //Serial.print(distancia1);
    //Serial.println(" cm");
    digitalWrite(led,LOW); 
  }*/
  
  delay(400);
}
