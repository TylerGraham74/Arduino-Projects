// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;
const int LEDPin = 7;

// defines variables
long duration;
int distance;
int expecDist;
void setup()
{
  expecDist = 0;
  Serial.begin(9600); // Starts the serial communication
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(LEDPin, OUTPUT);
  setExpected();
}

void loop()
{
  readDist();
  if (distance <= expecDist + 5) //triggers LED if object is within 30 cm
  {
    digitalWrite(LEDPin, HIGH);
  }
  if (distance > expecDist - 5)
  {
    digitalWrite(LEDPin, LOW);
  }
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
}

void readDist()
{
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2); //delays 2 microseconds
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH); //sends out signal
  delayMicroseconds(10); //waits 10 microseconds then stops
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH); //reads from echoPin
  // Calculating the distance
  distance = duration * 0.034 / 2; //time * speed of sound / 2
}

void setExpected()
{
  int first;
  int second;
  int third;
  delay(1000);
  readDist();
  first = distance;
  delay(1000);
  readDist();
  second = distance;
  delay(1000);
  readDist();
  third = distance;
  distance = 0;
  if ((first - second > -6) && (first - second < 6) && (second - third > -6) && (second - third < 6) && (third - first > -6) && (third - first < 6))
  {
    expecDist = first;
    digitalWrite(LEDPin, HIGH);
    delay(100);
    digitalWrite(LEDPin, LOW);
    delay(100);
    digitalWrite(LEDPin, HIGH);
    delay(100);
    digitalWrite(LEDPin, LOW);
  }
  else
  {
    Serial.println("Test Failed");
    setExpected();
  }
}
