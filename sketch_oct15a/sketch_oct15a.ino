#define YELLOW 0
#define GREEN 1
#define RED 2
#define BLUE 3

#define BUTTON1 13
#define BUTTON2 12
#define BUTTON3 11
#define BUTTON4 10
#define SPEAKER 9

int numTones = 10;
int tones[] = {261, 277, 294, 311, 330, 349, 370, 392, 415, 440};
//            mid C  C#   D    D#   E    F    F#   G    G#   A

int nrOfLightsOn = 0;

struct gamePadType {
  int PinNrLed;
  int Frequency;
  int PinNrButton;
};

gamePadType Yellow = {0, 440, 10};
gamePadType Green = {1, 392, 11};
gamePadType Red = {2, 349, 12};
gamePadType Blue = {3, 330 , 13};
gamePadType GamePad[] = {Yellow, Green, Red, Blue};

void setup() {

  // put your setup code here, to run once:
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(RED, OUTPUT);
  pinMode(BLUE, OUTPUT);

  pinMode(BUTTON1, INPUT_PULLUP); // button is connected to ground
  pinMode(BUTTON2, INPUT_PULLUP); // button is connected to ground
  pinMode(BUTTON3, INPUT_PULLUP); // button is connected to ground
  pinMode(BUTTON4, INPUT_PULLUP); // button is connected to ground

//  Testfunction();
}

void PlaySoundOn(gamePadType i) {
  tone(SPEAKER, i.Frequency);
}

void PlaySoundOff(gamePadType i) {
  noTone(SPEAKER);
}

void TurnLighOn(gamePadType i) {
  digitalWrite(i.PinNrLed, HIGH);
}

void TurnLighOff(gamePadType i) {
  digitalWrite(i.PinNrLed, LOW);
}

void BlinkAndBuzz(gamePadType i) {
  delay(500);
  tone(SPEAKER, i.Frequency);
  digitalWrite(i.PinNrLed, HIGH);
  delay(500);
  noTone(SPEAKER);
  digitalWrite(i.PinNrLed, LOW);
}


void blink(int i) {
  digitalWrite(i, HIGH);
  delay(500);
  digitalWrite(i, LOW);
  delay(500);
  digitalWrite(i, HIGH);
  delay(500);
  digitalWrite(i, LOW);
}

void BilnkAllSeries() {
  blink(YELLOW);
  delay(500);
  blink(GREEN);
  delay(500);
  blink(RED);
  delay(500);
  blink(BLUE);
}
void BilnkAll() {
  delay(500);
//  LightsOn();
  delay(500);
 // LightsOff();
  delay(500);
//  LightsOn();
  delay(500);
//  LightsOff();
  delay(500);
}
void Hello(){
    digitalWrite(YELLOW, HIGH);
  digitalWrite(GREEN, HIGH);
  digitalWrite(RED, HIGH);
  digitalWrite(BLUE, HIGH);
  }


void LightsOff() {
  digitalWrite(YELLOW, LOW);
  digitalWrite(GREEN, LOW);
  digitalWrite(RED, LOW);
  digitalWrite(BLUE, LOW);
}
  
void Testfunction() {
  delay(500);
  BilnkAll();
  BilnkAllSeries();
  delay(500);

}
void loop() {
  // put your main code here, to run repeatedly:

}
