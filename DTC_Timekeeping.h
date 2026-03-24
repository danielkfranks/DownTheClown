#ifndef DTC_TIMEKEEPING_H
#define DTC_TIMEKEEPING_H

// DEPRECIATED

// code here
static long startTime;

void initTimer() {
	startTime = millis();
}

long checkTimer() {
	long timeDiff = millis() - startTime; // how much time passed since we started?
  long timeTotal = 30*1000; // one minute
  timeTotal *= 2*minutes; // has to be done as two seperate calculations to avoid overflow
	long timeRemaining = timeDiff - timeTotal; // how does that compare to 3 minutes?
	return timeRemaining;
}

void displayTimeRemaining(long timeRemaining) {
	// LCD code here
	
}

#endif
