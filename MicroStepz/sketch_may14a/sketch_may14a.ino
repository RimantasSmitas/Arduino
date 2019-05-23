#include <AccelStepper.h>

AccelStepper stepper(AccelStepper::DRIVER, 5, 4); // Defaults to AccelStepper::FULL4WIRE (4 pins) on 2, 3, 4, 5

void setup()
{  
   stepper.setMaxSpeed(500);
   stepper.setSpeed(50);  
  // stepper.MicroStepping(1000);

   
   //stepper.setEnablePin(13);
   //stepper.setPinsInverted(true, true, true);

}

void loop()
{  
   stepper.enableOutputs();
   stepper.runSpeed();
}
