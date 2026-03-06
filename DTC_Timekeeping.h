#ifndef DTC_TIMEKEEPING_H
#define DTC_TIMEKEEPING_H

// code here
static long startTim;

void initTimer() {
	startTime = millis();
}

long checkTimer() {
	long timeDiff = millis() - startTime; // how much time passed since we started?
	long timeRemaining = timeDiff - 3*60*1000; // how does that compare to 3 minutes?
	return timeRemaining;
}

void displayTimeRemaining(long timeRemaining) {
	// LCD code here
	
}

#endif
