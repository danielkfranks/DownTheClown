#ifndef DTC_SERVO_H
#define DTC_SERVO_H

#include <Servo.h>

int ResetRow(Servo servoArray[6], int rowNumber) {
	int upPosition = 35, downPosition = 180; // TODO tune these PLEASE
	int idx1 = 0, idx2 = 0;

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
		default:
			return -1;
			break;
	}

	servoArray[idx1].write(upPosition);
	servoArray[idx2].write(upPosition);
	delay(15);
	servoArray[idx1].write(downPosition);
	servoArray[idx2].write(downPosition);

	return 0;
}

#endif
