/* DownTheClown - a Through The Looking Glass game
 *  since there's one microcontroller, it runs one program, and well it has to be this one
 *  It has several purposes:
 *  - Track the game time - initiate a timer (displayed on a LCD) and halt the entire game when it reaches idk 3 minutes
 *  - Track the game score - any time a clown is downed, increase the score for that player by a value equivalent to the value of the clown
 *  - Reset clowns based on manual and automatic triggers
 */

#include <Servo.h>
#include <LiquidCrystal.h>

// internal includes
#include "DTC_Timekeeping.h"
#include "DTC_Scorekeeping.h"
#include "DTC_Sensing.h"
#include "DTC_Servos.h"
#include "DTC_LEDs.h"


Servo rightServos[6];
Servo leftServos[6];

// the LED needs to be handled in discrete circuitry here - with a real switch this should be ezpz


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
