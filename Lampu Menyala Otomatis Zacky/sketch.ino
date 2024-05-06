const int led =5;
const int pir =19;
void setup(){
  pinMode(led,OUTPUT);
  pinMode(pir,INPUT);
  Serial.begin(9600);
}
void loop(){
  const int IP=digitalRead(pir);
  Serial.println(IP);
  delay(100);
  if(IP==1){
    digitalWrite(led,HIGH);
    delay(1000);  
  }
  else{
    digitalWrite(led,LOW);
    delay(1000);  
  
  }

} 