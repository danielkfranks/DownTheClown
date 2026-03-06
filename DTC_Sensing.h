#ifndef DTC_SENSING_H
#define DTC_SENSING_H

// code here

int checkClownsDown() {
  // hoping the digitalRead threshold is reasonable
  // that being said, bool to int conversion is implicit
  int score = 0; // we'll count it from the start every time
  score += digitalRead();

  return score;
}

#endif
