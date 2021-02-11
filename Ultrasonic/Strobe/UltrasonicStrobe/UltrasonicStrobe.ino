//Ultrasonic Strobe Light

const int trigPin = 9;
const int echoPin = 10;
const int LED1 = 5;
const int LED2 = 6;
const int LED3 = 7;

long duration;
int distance;

void setup() {
  Serial.begin(9600); // Starts the serial communication
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
}

void loop() 
{
  readDist();
  if (distance <= 300) //triggers LED if object is within 30 cm
  {
    strobe();
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

void strobe()
{
  for(int i = 0; i < 40; i++)
  {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    delay(15);
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    delay(100);
  }
}
