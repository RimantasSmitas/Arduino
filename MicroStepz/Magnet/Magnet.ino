void setup() {
  // put your setup code here, to run once:
pinMode(A0, INPUT);
Serial.begin(9600);
}

void loop() {
  Serial.println( analogRead(A0));
  delay(500);
  // put your main code here, to run repeatedly:

}
