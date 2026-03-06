/* DownTheClown - a Through The Looking Glass game
 *  since there's one microcontroller, it runs one program, and well it has to be this one
 *  It has several purposes:
 *  - Track the game time - initiate a timer (displayed on a LCD) and halt the entire game when it reaches idk 3 minutes
 *  - Track the game score - any time a clown is downed, increase the score for that player by a value equivalent to the value of the clown
 *  - Reset clowns based on manual and automatic triggers
 */

#include <Servo.h>
#include <LiquidCrystal.h>

// maybe I hate global variables but I can't redefine setup() and loop() so here we are
int downPosition = 180, upPosition = 35; // can't know these until we build the physical thingy so TODO set these

Servo[6] rightServos;
Servo[6] leftServos;

// the LED needs to be handled in discrete circuitry here - with a real switch this should be ezpz

int ResetRow(char side, int rowNumber){
  Servo[6] servoArray;
  int idx1 = 0, idx2 = 0; // initialize values for safety :)
  
  if(side == 'r') {
    servoArray = rightServos;
  } else if(side == 'l') {
    servoArray = leftServos;
  } else return -1; // error condition
  
  switch(rowNumber) {
    case 1:
      idx1 = 0;
      idx2 = 1;
      break;
    case 2:
      idx1 = 2;
      idx2 = 3;
      break;
    case 3:
      idx1 = 4;
      idx2 = 5;
      break;
    default:     // also an error condition
      return -1;
      break; // pretty sure this line is irrelevant but good coding practice
  }

  // finally do actual work
  servoArray[idx1].write(upPosition);
  servoArray[idx2].write(upPosition);
  delay(15);                            // might have to tune this idk
  servoArray[idx1].write(downPosition); // set them back down so the clowns can be knocked down again
  servoArray[idx2].write(downPosition); 

  return 0; // success !!
}

void setup() {
  // put your setup code here, to run once:
  rightServos[0].attach(1);  // do I need to pinMode these? the example code doesn't.
  rightServos[1].attach(2);
  rightServos[2].attach(3);
  rightServos[3].attach(4);
  rightServos[4].attach(5);
  rightServos[5].attach(6);
  leftServos[0].attach(7);
  leftServos[1].attach(8);
  leftServos[2].attach(9);
  leftServos[3].attach(10);
  leftServos[4].attach(11);
  leftServos[5].attach(12);  // this is the least pretty way possible to do it but it's also not unmaintainable slop like any for loop I wrote would be

}

void loop() {
  // put your main code here, to run repeatedly:

}
