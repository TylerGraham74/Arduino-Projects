int redPin = 11;
int greenPin = 10;
int bluePin = 9;
double r = 0;
double g = 0;
double b = 0;
boolean red = true;
boolean green = true;
boolean blue = true;

void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  Serial.begin(9600);
  Serial.print("Serial Monitor Test\n");
}

void loop()
{
  if (blue)
  {
    r++;
    printColor();
    setColor(r, g, b);
    if (r >= 100.0 / 3)
      red = false;
    if (r >= 100)
      r = 0;
    delay(5);
  }
  if (!red)
  {
    g++;
    printColor();
    setColor(r, g, b);
    if (g >= 100.0 / 3)
      green = false;
    if (g >= 100)
      g = 0;
    delay(5);
  }
  if (!green)
  {
    b++;
    printColor();
    setColor(r, g, b);
    if (b >= 100)
      b = 0;
    delay(5);
  }
}

void printColor()
{
  Serial.print("Red: ");
  Serial.print(r);
  Serial.print("  Green: ");
  Serial.print(g);
  Serial.print("  Blue: ");
  Serial.print(b);
  Serial.print("\n");
}

void setColor(int red, int green, int blue)
{
#ifdef COMMON_ANODE
  red = 255 - red;
  green = 255 - green;
  blue = 255 - blue;
#endif
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}
