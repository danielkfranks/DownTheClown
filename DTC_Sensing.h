#ifndef DTC_SENSING_H
#define DTC_SENSING_H

// code here

int checkClownsDown(int pins[8]) {
  // hoping the digitalRead threshold is reasonable
  // that being said, bool to int conversion is implicit
  int score = 0; // we'll count it from the start every time
  score += digitalRead(pins[0]);
  score += digitalRead(pins[1]);
  score += digitalRead(pins[2]);
  score += digitalRead(pins[3]);
  score += digitalRead(pins[4]);
  score += digitalRead(pins[5]);
  score += 2*digitalRead(pins[6]);
  score += 2*digitalRead(pins[7]);

  return score;
}

#endif
