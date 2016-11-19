#define pin_echo 6
#define pin_trig 7
#define led 13
long duracion, distancia;
void setup() {
  Serial.begin(9600);
  pinMode(pin_echo, INPUT);
  pinMode(pin_trig, OUTPUT);
  pinMode(led,OUTPUT);
}

void loop() {
  digitalWrite(pin_trig, LOW);
  delayMicroseconds(2);
  digitalWrite(pin_trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pin_trig, LOW);
  duracion = pulseIn(pin_echo,HIGH);
  distancia = (duracion/2)/29; //la distancia esta en centimetros
  if(distancia <= 10 && distancia >= 1){ // si distancia es mayor a 500 cm o menor a 0, no hace nada    
    Serial.println("Alarma...");
    Serial.print(distancia);
    Serial.println(" cm");
    digitalWrite(led,1);
  }else{
    Serial.println("---");
    Serial.print(distancia);
    Serial.println(" cm");
    digitalWrite(led,0); 
  }
  delay(400);
}
