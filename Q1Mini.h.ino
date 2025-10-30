#ifndef Q1Mini_h
#define Q1Mini_h

#include <Arduino.h>
#include <Servo.h>

class Q1Mini {
public:
  Q1Mini();
  void begin();

  // Movement functions
  void forward();
  void backward();
  void left();
  void right();
  void hi();
  void pushUp();
  void dance();
  void fight();

private:
  static const int numberOfServos = 8;
  static const int numberOfACE = 9;
  int servoCal[numberOfServos];
  Servo servo[numberOfServos];

  void runServoPrg(const int prg[][numberOfACE], int steps);
};

#endif
