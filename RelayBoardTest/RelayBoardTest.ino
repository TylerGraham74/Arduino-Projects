void setup() {
  // put your setup code here, to run once:
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop() {
  for (int i = 0; i < 8; i++)
  {
    digitalWrite(i + 4, LOW);
    delay(500);
  }
  for (int i = 0; i < 8; i++)
  {
    digitalWrite(i + 4, HIGH);
    delay(500);
  }
}
