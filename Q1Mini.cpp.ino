#include "Q1Mini.h"

// =========================================
// Insert your original servo motion arrays here
// Example placeholder (replace with your real arrays)
// =========================================
const int servoPrg02[][9] = { {0,90,90,180,180,90,90,0,500} };
const int servoPrg03[][9] = { {0,90,90,180,180,90,90,0,500} };
const int servoPrg06[][9] = { {0,90,90,180,180,90,90,0,500} };
const int servoPrg07[][9] = { {0,90,90,180,180,90,90,0,500} };
const int servoPrg09[][9] = { {0,90,90,180,180,90,90,0,500} };
const int servoPrg11[][9] = { {0,90,90,180,180,90,90,0,500} };
const int servoPrg08[][9] = { {0,90,90,180,180,90,90,0,500} };
const int servoPrg10[][9] = { {0,90,90,180,180,90,90,0,500} };

const int servoPrg02step = 1;
const int servoPrg03step = 1;
const int servoPrg06step = 1;
const int servoPrg07step = 1;
const int servoPrg09step = 1;
const int servoPrg11step = 1;
const int servoPrg08step = 1;
const int servoPrg10step = 1;
// =========================================

Q1Mini::Q1Mini() {
  int tempCal[numberOfServos] = { -50, 30, -30, -50, 50, -30, 30, -50 };
  memcpy(servoCal, tempCal, sizeof(tempCal));
}

void Q1Mini::begin() {
  int servoPins[numberOfServos] = {2, 3, 4, 5, 6, 7, 8, 9};
  int initPos[numberOfServos] = {0, 90, 90, 180, 180, 90, 90, 0};

  for (int i = 0; i < numberOfServos; i++) {
    servo[i].attach(servoPins[i]);
    servo[i].write(initPos[i] + servoCal[i]);
  }

  Serial.begin(9600);
}

void Q1Mini::runServoPrg(const int prg[][numberOfACE], int steps) {
  for (int i = 0; i < steps; i++) {
    for (int j = 0; j < numberOfServos; j++) {
      servo[j].write(prg[i][j] + servoCal[j]);
    }
    delay(prg[i][8]);
  }
}

// Movement functions
void Q1Mini::forward()  { runServoPrg(servoPrg02, servoPrg02step); }
void Q1Mini::backward() { runServoPrg(servoPrg03, servoPrg03step); }
void Q1Mini::left()     { runServoPrg(servoPrg06, servoPrg06step); }
void Q1Mini::right()    { runServoPrg(servoPrg07, servoPrg07step); }
void Q1Mini::hi()       { runServoPrg(servoPrg09, servoPrg09step); }
void Q1Mini::pushUp()   { runServoPrg(servoPrg11, servoPrg11step); }
void Q1Mini::dance()    { runServoPrg(servoPrg08, servoPrg08step); }
void Q1Mini::fight()    { runServoPrg(servoPrg10, servoPrg10step); }
