/* DownTheClown - a Through The Looking Glass game
 *  since there's one microcontroller, it runs one program, and well it has to be this one
 *  It has several purposes:
 *  - Track the game time - initiate a timer (displayed on a LCD) and halt the entire game when it reaches idk 3 minutes
 *  - Track the game score - any time a clown is downed, increase the score for that player by a value equivalent to the value of the clown
 *  - Reset clowns based on manual and automatic triggers
 */

// THIS FILE IS DEPRECIATED
// THE PROGRAM IS NOW DESIGNED FOR TWO SEPERATE UNITS

#include <Servo.h>
#include <LiquidCrystal.h>

// internal includes
#include "DTC_PinsConsts.h"
#include "DTC_Timekeeping.h"
#include "DTC_Scorekeeping.h"
#include "DTC_Sensing.h"
#include "DTC_Servos.h"
#include "DTC_LEDs.h"
#include "DTC_Manual.h"

// sketch configuration
#define DEBUG_LEVEL 1

// global variables
// these are in DTC_PinsConsts.h now to keep them seperate from the game logic, look there


void setup() {
  // configure servos:
  rightServos[0].attach(rightServoPins[0]);  // do I need to pinMode these? the example code doesn't.
  rightServos[1].attach(rightServoPins[1]);  // the arrays are from DTC_PinsConsts.h
  rightServos[2].attach(rightServoPins[2]);
  rightServos[3].attach(rightServoPins[3]);
  rightServos[4].attach(rightServoPins[4]);
  rightServos[5].attach(rightServoPins[5]);
  leftServos[0].attach(leftServoPins[0]);
  leftServos[1].attach(leftServoPins[1]);
  leftServos[2].attach(leftServoPins[2]);
  leftServos[3].attach(leftServoPins[3]);
  leftServos[4].attach(leftServoPins[4]);
  leftServos[5].attach(leftServoPins[5]);  // this is the least pretty way possible to do it but it's also not unmaintainable slop like any for loop I wrote would be

  // configure sensors:
  // I hope I don't have to pinMode them
  
  // start keeping time:
  timeRemaining = 1000*30; // one half minute of time, variable from DTC_PinsConsts.h
  timeRemaining *= 2*minutes; // has to be done like this to slip under the int overflow threshold
  initTimer();                                         // from DTC_Timekeeping.h

  // start serial for manual/debug use
  Serial.begin(9600);
  Serial.println("           "); // purge garbage so it looks cool
  Serial.println("DownTheClown initialized, awaiting instructions...");
}

void loop() {
  // game logic goes here pretty much
  leftScore = checkClownsDown(leftSensors);            // from DTC_Sensing.h
  rightScore = checkClownsDown(rightSensors);          // from DTC_Sensing.h
  if(DEBUG_LEVEL >= 2){
    Serial.print("Current score: Right "); Serial.print(rightScore);
    Serial.print(", Left: "); Serial.println(leftScore);
  }

  timeRemaining = checkTimer();                        // from DTC_Timekeeping.h
  displayTimeRemaining(timeRemaining);                 // from DTC_Timekeeping.h
  
  for(int i = 1; i <= 3; i++) {
    if(checkRowDown(leftSensors, i)) {                 // from DTC_Sensing.h
      resetRow(leftServos, i);                         // from DTC_Servos.h
      if(DEBUG_LEVEL) {
        Serial.print("Automatically raised left servo bank, row ");
        Serial.println(i);
      }
    }

    if(checkRowDown(rightSensors, i)) {                // from DTC_Sensing.h
      resetRow(rightServos, i);                        // from DTC_Servos.h
      if(DEBUG_LEVEL) {
        Serial.print("Automatically raised right servo bank, row ");
        Serial.println(i);
      }
    }
  }

  serialManage(); // check for a manual override (from DTC_Manual.h)

  if(DEBUG_LEVEL >= 2){
    // this runs EVERY LOOP until I find a way to delay it so it's at a higher debug
    Serial.println("Current score reading------------------------");
    Serial.print("Right bank: "); Serial.print(rightScore);
    Serial.print(", Left bank: "); Serial.println(leftScore);
  }

  if(timeRemaining <= 0) {
    // game is over
    displayWinner(leftScore, rightScore);              // from DTC_Scorekeeping.h
    return;
  }
  

}
