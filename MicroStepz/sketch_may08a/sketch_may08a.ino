#include <Arduino.h>

// this pin should connect to Ground when want to stop the motor
#define STOPPER_PIN 4

// Motor steps per revolution. Most steppers are 200 steps or 1.8 degrees/step
#define MOTOR_STEPS 200
#define RPM 5
// Microstepping mode. If you hardwired it to save pins, set to the same value here.
#define MICROSTEPS 1

#define DIR 8
#define STEP 9
#define SLEEP 13 

 #include "DRV8825.h"
 #define MODE0 10
 #define MODE1 11
 #define MODE2 12
 DRV8825 stepper(MOTOR_STEPS, DIR, STEP, SLEEP, MODE0, MODE1, MODE2);


void setup() {
  // put your setup code here, to run once:


 pinMode(STOPPER_PIN, INPUT_PULLUP);

    stepper.begin(RPM, MICROSTEPS);
    // if using enable/disable on ENABLE pin (active LOW) instead of SLEEP uncomment next line
    // stepper.setEnableActiveState(LOW);
    stepper.enable();

  //   stepper.setMicrostep(1);  // Set microstep mode to 1:1
 //   stepper.setRPM(1);  // Set microstep mode to 1:1



//stepper.startMove(100 * MOTOR_STEPS * MICROSTEPS);  
}

void loop() {
  // put your main code here, to run repeatedly:
//if (digitalRead(STOPPER_PIN) == LOW){
 // stepper.stop();
 stepper.rotate(360); 




}
