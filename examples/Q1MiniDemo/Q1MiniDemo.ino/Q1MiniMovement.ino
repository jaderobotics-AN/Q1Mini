#include <Q1Mini.h>

Q1Mini robot;

void setup() {
  robot.begin();
  Serial.begin(9600);
  Serial.println("Q1 Mini Ready. Send commands:");
  Serial.println("F - Forward, B - Backward, L - Left, R - Right, H - Hi, P - Push-up, D - Dance, V - Fight");
}

void loop() {
  if (Serial.available()) {
    char cmd = Serial.read();

    switch (cmd) {
      case 'F': robot.forward(); break;
      case 'B': robot.backward(); break;
      case 'L': robot.left(); break;
      case 'R': robot.right(); break;
      case 'H': robot.hi(); break;
      case 'P': robot.pushUp(); break;
      case 'D': robot.dance(); break;
      case 'V': robot.fight(); break;
      default: Serial.println("Invalid command");
    }
  }
}
