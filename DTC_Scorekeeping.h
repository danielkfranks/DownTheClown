#ifndef DTC_SCOREKEEPING_H
#define DTC_SCOREKEEPING_H

// code here
void printScore(int score) {
  lcd.setCursor(1, 1);
  lcd.print("Score: ");
  lcd.print(score); // I'm sure this will Just Work
}

#endif
