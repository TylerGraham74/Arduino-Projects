// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;
const int LEDPin = 7;

// defines variables
long duration;
int distance;
void setup()
{
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(LEDPin, OUTPUT);
  Serial.begin(9600); // Starts the serial communication
}

void loop()
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
  // Prints the distance on the Serial Monitor
  if (distance <= 200) //triggers LED if object is within 30 cm
  {
    digitalWrite(LEDPin, HIGH);
    delay(100);
  }
  else
    digitalWrite(LEDPin, LOW);
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
}
