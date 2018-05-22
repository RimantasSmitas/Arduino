
int uvSensor = A2;
int photoCel1 = A1;
int photoCel2 = A0;
int photoCel3 = A3;
int photoCel4 = A4;

void setup() {

pinMode(photoCel1, INPUT);
pinMode(photoCel2, INPUT);

pinMode(photoCel3, INPUT);
pinMode(photoCel4, INPUT);
pinMode(uvSensor, INPUT);
Serial.begin(9600);
  
  // put your setup code here, to run once:

}

void loop() {
  Serial.print("first ");
Serial.println(analogRead(photoCel1));

  Serial.print("second ");
Serial.println(analogRead(photoCel2));

  Serial.print("third ");
Serial.println(analogRead(photoCel3));

  Serial.print("fourth ");
Serial.println(analogRead(photoCel4));

  Serial.print("uv ");
Serial.println(analogRead(uvSensor));
delay(1500);
}
  
  
  // put your main code here, to run repeatedly:


