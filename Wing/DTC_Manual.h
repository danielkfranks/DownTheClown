#ifndef DTC_MANUAL_H
#define DTC_MANUAL_H

void serialManage() {
  int incomingByte = 0;
  //Serial.println("Manually reset banks (h for help)");
  // resetRow(leftServos, i);

  if(Serial.available() > 0) {
    incomingByte = Serial.read();\
    switch(incomingByte) {
      case 49: // '1' in ASCII
        Serial.println("Resetting top right bank.");
        resetRow(rightServos, 1);
        break;
      case 50: // '2' in ASCII. not writing every single one, you get the idea
        Serial.println("Resetting center right bank.");
        resetRow(rightServos, 2);
        break;
      case 51:
        Serial.println("Resetting bottom right bank.");
        resetRow(rightServos, 3);
        break;
      case 52:
        Serial.println("Resetting top left bank.");
        resetRow(leftServos, 1);
        break;
      case 53:
        Serial.println("Resetting center left bank.");
        resetRow(leftServos, 2);
        break;
      case 54:
        Serial.println("Resetting bottom left bank.");
        resetRow(leftServos, 3);
        break;
      case 55:
        Serial.println("Resetting all right banks.");
        resetRow(rightServos, 1);
        resetRow(rightServos, 2);
        resetRow(rightServos, 3);
        break;
      case 56:
        Serial.println("Resetting all left banks.");
        resetRow(leftServos, 1);
        resetRow(leftServos, 2);
        resetRow(leftServos, 3);
        break;
      case 104: // 'h' in ASCII
      case 72:  // 'H' in ASCII. the switch case falls through so it's case insensitive
        Serial.println("Reset clown banks with the following schema:");
        Serial.println("top right | center right | bottom right | top left | center left | bottom left | all right | all left");
        Serial.println("    1     |       2      |      3       |    4     |       5     |      6      |      7    |     8   ");
        break;
      default:
        Serial.println("h for help");
        break;
    }
  }
}

#endif