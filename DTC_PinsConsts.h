#ifndef DTC_PINSCONSTS_H
#define DTC_PINSCONSTS_H

#include <Servo.h>
#include <LiquidCrystal.h>

// create the servo objects, but we have to assign the pins in setup()
Servo servos[6];

// Serial communication uses pins 0 and 1

// LCD communication needs six pins
int lcdPins[6] = {13, 12, 11, 10, 9, 8};
LiquidCrystal lcd(lcdPins[0], lcdPins[1], lcdPins[2], lcdPins[3], lcdPins[4], lcdPins[5]);

// need six servos
int servoPins[6] = {2, 3, 4, 5, 6, 7};

// need five sensors, one for each clown
int sensors[5] = {A0, A1, A2, A3, A4};

// need to get the time status from Adri's core Arduino
int timePin = A5;

int score = 0;
int oldClownState = 0;
int clownState = 0;

#endif
