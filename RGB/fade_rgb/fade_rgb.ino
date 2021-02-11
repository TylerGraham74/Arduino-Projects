int redPin = 11;
int greenPin = 10;
int bluePin = 9;
double r = 0;
double g = 0;
double b = 0;
int autoStep = 0;

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
  if (autoStep == 0)
  {
    for (int i = 0; i < 100; i++)
    {
      r += 225.0 / 100;
      setColor(r, g, b);
      printColor();
      delay(5);
    }
    autoStep++;
  }
  else if (autoStep == 1)
  {
    for (int i = 0; i < 100; i++)
    {
      r -= 225.0 / 100;
      b += 130.0 / 100;
      setColor(r, g, b);
      printColor();
      delay(5);
    }
    autoStep++;
  }
  else if (autoStep == 2)
  {
    for (int i = 0; i < 100; i++)
    {
      b -= 130.0 / 100;
      g += 150.0 / 100;
      setColor(r, g, b);
      printColor();
      delay(5);
    }
    autoStep++;
  }
  else if (autoStep == 3)
  {
    for (int i = 0; i < 100; i++)
    {
      g -= 150.0 / 100;
      r += 225.0 / 100;
      setColor(r, g, b);
      printColor();
      delay(5);
    }
    autoStep = 1;
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
