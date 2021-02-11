const int LED0 = 6;
const int LED1 = 2;
const int LED2 = 3;
const int LED3 = 4;
const int LED4 = 5;
const int buttonPin = 8;
bool pressed = false;
int state = 0;

void setup() {
  Serial.begin(9600);
  pinMode(LED0, OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  state = digitalRead(buttonPin);
  /*digitalWrite(LED0, HIGH);
  delay(500);
  digitalWrite(LED0, LOW);
  delay(500);
  digitalWrite(LED1, HIGH);
  delay(500);
  digitalWrite(LED1, LOW);
  delay(500);
  digitalWrite(LED2, HIGH);
  delay(500);
  digitalWrite(LED2, LOW);
  delay(500);
  digitalWrite(LED3, HIGH);
  delay(500);
  digitalWrite(LED3, LOW);
  delay(500);
  digitalWrite(LED4, HIGH);
  delay(500);
  digitalWrite(LED4, LOW);
  delay(500);*/
  if(state == LOW)
  {
    Serial.println("Pressed");
  }
}

void strobe()
{
  for(int i = 2; i < 7; i++)
  {
    digitalWrite(i, HIGH);
  }
  delay(25);
  for(int i = 2; i < 7; i++)
  {
    digitalWrite(i, LOW);
  }
  delay(25);
}
