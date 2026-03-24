#ifndef DTC_SENSING_H
#define DTC_SENSING_H

// code here

// for scoring:
int checkClownsDown(int pins[8]) {
  // hoping the digitalRead threshold is reasonable
  // that being said, bool to int conversion is implicit
  int score = 0; // we'll count it from the start every time
  score += digitalRead(pins[0]);
  score += digitalRead(pins[1]);
  score += digitalRead(pins[2]);
  score += digitalRead(pins[3]);
  score += digitalRead(pins[4]);

  return score;
}

// for auto row reset:
bool checkRowDown(int pins[5], int row) {
	bool rowDown = false;
	if(row == 3) {
		// top row
		rowDown = digitalRead(pins[4]);
	} else if(row == 2) {
		rowDown = digitalRead(pins[2]) && digitalRead(pins[3]);
	} else if(row == 1) {
		rowDown = digitalRead(pins[0]) && digitalRead(pins[1]);
	} else {
		rowDown = false; // error state but how dare we log it
	}
	return rowDown;
}

#endif
