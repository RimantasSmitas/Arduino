
#include <Servo.h>
Servo myservo;  // create servo object to control a servo

int sensorPin = A0;    // select the input pin for the potentiometer
int temp = 0;  // variable to store the value coming from the sensor
int inByte = 0; 
int pos = 0;    // variable to store the servo position

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);
  myservo.write(0);
  analogReference(EXTERNAL);
}

void loop() {
  delay(1000);
  if (Serial.available() > 0) {
    // get incoming byte:
    inByte = Serial.read();
    if (inByte == 'A')
    {
      myservo.write(0);
    }
    if (inByte == 'B')
    {
      myservo.write(180);
    }
    if (inByte == 'C')
    {
      for (pos=0;pos<=180;pos++)
      {
      myservo.write(pos);
      delay(17);
      }
    }
  }
  
  temp = analogRead(sensorPin);
  Serial.print("analogread");
  Serial.println(temp);
  int y=0;
  int newnumber = temp*0.322 ;
  Serial.print("temperature");
  Serial.println(newnumber);
  y = map(newnumber, 0, 45, 180, 0);
  Serial.print("angle");
  Serial.println(y);
  myservo.write(y);
}

