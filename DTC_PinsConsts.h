#ifndef DTC_PINSCONSTS_H
#define DTC_PINSCONSTS_H

// create the servo objects, but we have to assign the pins in setup()
Servo rightServos[6];
Servo leftServos[6];

// create some values so I don't have to change setup() if I want to change these
int rightServoPins[6] = {1, 2, 3, 4, 5, 6};
int leftServoPins[6] = {7, 8, 9, 10, 11, 12};

// pins for right and left sensors (photoresistors?)
int rightSensors[8] = {20, 21, 22, 23, 24, 25, 26, 27};
int leftSensors[8] = {30, 31, 32, 33, 34, 35, 36, 37};

int rightScore = 0, leftScore = 0;

long timeRemaining; // this warns about int overflow
// if it was an int it would, but a long holds about a month in milliseconds
#endif
