//Random number tester

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.print("Serial Monitor Test\n");
  srand(time(NULL));
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(getRand(0, 100));
  Serial.print("\n");
  delay(1000);
  srand(time(NULL));
}

int getRand(int low, int high)
{
  int n = rand() % 100 + 1;
  return n;
}
