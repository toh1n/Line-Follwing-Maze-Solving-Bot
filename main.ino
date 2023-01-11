#include "defines.h"

void setup() {
  pinAsOutput(rightMotor1);
  pinAsOutput(rightMotor2);
  pinAsOutput(rightMotorPWM);
  pinAsOutput(leftMotor1);
  pinAsOutput(leftMotor2);
  pinAsOutput(leftMotorPWM);
  pinAsOutput(led);

  delay(2000);
  Serial.begin(9600);
}

void loop() {

  // int pos = readLine();
  //  for(int i=0;i<100;i++){
  //  Serial.println("pos");
  //  }
  Serial.println("Hello Tohin!");
  Serial.println("Now Finding the sortest path!!!");
  MazeSolve();

  Serial.print("Sortest path : ");
  Serial.print(" ");
  for (int i = 0; i < path_length; i++) {
    Serial.print(path[i]);
    Serial.print("  ");
  }
  Serial.println();
  follow_path();
}
