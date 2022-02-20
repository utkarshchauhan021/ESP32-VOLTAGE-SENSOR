int value = 0;
float R1 = 10000;
float R2 = 4700;
float voltage;
int PIN = 35;
int led1 = 16;
int led2 = 17;
int led3 = 5;
void setup(){
  pinMode(PIN, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  value = analogRead(PIN);
  voltage = value * (3.3/4095) * ((R1 + R2)/R2);
  Serial.print("Voltage= ");
  Serial.println(voltage);
  delay(500);
  if(voltage>5){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);}
  if((voltage<5)&&(voltage>2)){
    digitalWrite(led2, HIGH);
    digitalWrite(led1, LOW);
    digitalWrite(led3, LOW);}
  if(voltage<2){
    digitalWrite(led3, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led1, LOW);    
    }
}
