#include "DualVNH5019MotorShield.h"

DualVNH5019MotorShield md;

void setup() {
  Serial.begin(115200);
  Serial.println("Dual VNH5019 Motor Shield");
  md.init();
}

void loop() {
  md.setM1Speed(1);
  checkFault();
}

void checkFault()
{
  if (md.getM1Fault() == 1)
  {
    Serial.println("M1 fault");
    while (1);
  }
  if (md.getM2Fault() == 1)
  {
    Serial.println("M2 fault");
    while (1);
  }
}
