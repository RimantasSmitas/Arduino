int i=1 ; 
void setup() {pinMode(3,OUTPUT);
Serial.begin(9600);
}

void loop() {
analogWrite(3,250);
//delay(2000);
//analogWrite(3,0);
//delay(2000);
 
  for (i;i<250;i++){
  analogWrite(3,i);
  delay(50);
  Serial.println(i);
  }
  for (i;i>0;i--){
  analogWrite(3,i);
  delay(50);
  Serial.println(i);
  }

}
