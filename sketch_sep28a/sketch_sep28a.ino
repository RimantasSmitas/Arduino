/*
DONE
attach a button
attach a LED
Check that LED will be able to turn on
Check that Button will be readable
TODO  simons game

expand to 4 coloured lEDs
    test
    program
    test
    refactor 

expand to 4 buttons

find out about the random function

increase speed during game 

increase the number of "blinks"

some kind of a way to store the sequence of random "colours"

build the  sound generator


*/

int Level = 0;
int lights[10];

#define YELLOW 0
#define GREEN 1
#define RED 2
#define INFRARED 3

#define BUTTON1 13
#define BUTTON2 12
#define BUTTON3 11
#define BUTTON4 10

void testLed(void)//function to test LED by turning it on 
{
  digitalWrite(YELLOW,HIGH);
}

void testbutton(void)  //tests button by turning of the yellow LED when the button is activated
{
  while (1 == digitalRead(BUTTON1))
  {
  }
  digitalWrite(YELLOW,LOW);
}

void blink(int i){
  digitalWrite(i,HIGH);
  delay(500);
  digitalWrite(i,LOW);
  
}

void Testfunction(void)
{
   testLed();
  testbutton(); 
}


void setup() 
{
  pinMode(YELLOW,OUTPUT);
  pinMode(GREEN,OUTPUT);
  pinMode(RED,OUTPUT);
  pinMode(INFRARED,OUTPUT);

  pinMode(BUTTON1,INPUT_PULLUP); // button is connected to ground
  pinMode(BUTTON2,INPUT_PULLUP); // button is connected to ground
  pinMode(BUTTON3,INPUT_PULLUP); // button is connected to ground
  pinMode(BUTTON4,INPUT_PULLUP); // button is connected to ground
  
 /* Testfunction(); // may be removed when the code is finished
  blink(YELLOW);
  blink(GREEN);
  blink(RED);
  blink(INFRARED);*/
}

void randomlight()
{
lights[Level] = random(0,4);
}

void CheckForInput(){
 int light = 0;
 while (light <=Level){
   if (1 == digitalRead(lights[light]+10))
  {light++;
  }
  else{
    Level = 0; 
    light = 0; 
   for(int i = 0; i < sizeof(lights); i++) 
  {
    lights[i]=0;
    } 
  }
  
 }
 Level++;
  
  }



void loop() {
randomlight();
 for(int i = 0; i < sizeof(lights); i++) 
  {
    blink(lights[i]);
  }
CheckForInput();
  }









  
