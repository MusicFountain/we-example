int relay1 = 2;
int relay2 = 3;
void setup(){
   pinMode(relay1,OUTPUT);
   pinMode(relay2,OUTPUT);
}
void loop(){
  digitalWrite(relay1, HIGH); 
  digitalWrite(relay2, HIGH);
  delay(2000);
  digitalWrite(relay1, LOW); 
  digitalWrite(relay2, HIGH);
  delay(2000);
  digitalWrite(relay1, HIGH); 
  digitalWrite(relay2, LOW);
  delay(2000);
}

