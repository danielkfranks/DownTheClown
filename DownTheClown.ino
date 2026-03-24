/* DownTheClown - a Through The Looking Glass game
 * This is for the "Wing" microcontroller, so it has no timing requirements
 * its responsibilities are:
 * - sensing when clowns get knocked down
 * - updating and displaying the score accordingly
 * - setting clowns back up (manually and automatically) for one side
 */


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
  servos[0].attach(servoPins[0]);  // do I need to pinMode these? the example code doesn't.
  servos[1].attach(servoPins[1]);  // the arrays are from DTC_PinsConsts.h
  servos[2].attach(servoPins[2]);
  servos[3].attach(servoPins[3]);
  servos[4].attach(servoPins[4]);
  servos[5].attach(servoPins[5]);

  // configure sensors:
  // I hope I don't have to pinMode them
  
  // start LCD
  lcd.begin(16, 2);
  lcd.print("Welcome!");
  
  // start serial for manual/debug use
  Serial.begin(9600);
  Serial.println("           "); // purge garbage so it looks cool
  Serial.println("DownTheClown initialized, awaiting instructions...");
}

void loop() {
  // game logic goes here pretty much
  clownState = checkClownsDown(sensors);            // from DTC_Sensing.h
  if(clownState > oldClownState) {
    score += (clownState - oldClownState);
  }
  if(clownState < oldClownState) {
    // clowns got set back up but honestly don't do anything here I think
  }
  oldClownState = clownState;

  printScore(score);                           // from DTC_Scorekeeping.h
  if(DEBUG_LEVEL >= 2){
    Serial.print("Current score: "); Serial.print(score);
  }

  
  for(int i = 1; i <= 3; i++) {
    if(checkRowDown(sensors, i)) {                 // from DTC_Sensing.h
      resetRow(servos, i);                         // from DTC_Servos.h
      if(DEBUG_LEVEL) {
        Serial.print("Automatically raised servo bank, row ");
        Serial.println(i);
      }
    }
  }

  serialManage(); // check for a manual override (from DTC_Manual.h)

  if(digitalRead(timePin) == LOW) {
    // game is over
    score = 0;
    if(DEBUG_LEVEL) {
      Serial.println("Game over!");
    }
    //return; // return doesn't even do anything on an Arduino
  }
  

}
