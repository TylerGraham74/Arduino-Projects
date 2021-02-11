//Tyler Graham
//Sep. 15, 2018
//ColorPicker

const int buttonPin = 2;
int buttonState = 0;
int autoStep = 0;
int redPin = 11;
int greenPin = 10;
int bluePin = 9;
double r = 0;
double g = 0;
double b = 0;
int xr = 0;
int rb = 0;
int bg = 0;
int gr = 0;
boolean play = false;
boolean halt = false;
boolean wait = true;
void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  Serial.begin(9600);
  Serial.print("Serial Monitor Test\n");
}

void loop() {
  int sensorVal = digitalRead(buttonPin);
  if (!halt)
  {
    wait = true;
    if (autoStep == 0)
    {
      if (xr < 100)
      {
        if (sensorVal == LOW)
        {
          halt = true;
        }
        r += 225.0 / 100;
        setColor(r, g, b);
        //printColor();
        xr++;
        delay(20);
      }
      if (xr >= 100)
      {
        autoStep++;
      }
    }
    else if (autoStep == 1)
    {
      gr = 0;
      if (rb < 100)
      {
        if (sensorVal == LOW)
        {
          halt = true;
        }
        r -= 225.0 / 100;
        b += 130.0 / 100;
        setColor(r, g, b);
        rb++;
        //printColor();
        delay(20);
      }
      if (rb >= 100)
      {
        autoStep++;
      }
    }
    else if (autoStep == 2)
    {
      rb = 0;
      if (bg < 100)
      {
        if (sensorVal == LOW)
        {
          halt = true;
        }
        b -= 130.0 / 100;
        g += 150.0 / 100;
        setColor(r, g, b);
        bg++;
        //printColor();
        delay(20);
      }
      if (bg >= 100)
      {
        autoStep++;
      }
    }
    else if (autoStep == 3)
    {
      bg = 0;
      if (gr < 100)
      {
        if (sensorVal == LOW)
        {
          halt = true;
        }
        g -= 150.0 / 100;
        r += 225.0 / 100;
        setColor(r, g, b);
        gr++;
        //printColor();
        delay(20);
      }
      if (gr >= 100)
      {
        autoStep = 1;
      }
    }
  }
  else
  {
    if (wait)
    {
      Serial.print("Paused\n");
      Serial.print("Your RGB Values are: ");
      printColor();
      delay(500);
      wait = false;
    }
    else
    {
      if (sensorVal == LOW)
      {
        Serial.print("Resumed\n");
        delay(500);
        halt = false;
      }
    }
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
