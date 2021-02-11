#include <SoftwareSerial.h>
#include <time.h>

/*
  Adafruit Arduino - Lesson 3. RGB LED
*/

int redPin = 11;
int greenPin = 10;
int bluePin = 9;
double r = 0;
double g = 0;
double b = 0;
double red = 0;
double green = 0;
double blue = 0;
int cnt = 1;
boolean x = false;
//int colors[3];
//PWM pin #s

//uncomment this line if using a Common Anode LED
//#define COMMON_ANODE

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
  if (cnt == 0)
  {
    blinker(2, 0);
    blinker(2, 1);
    blinker(2, 2);
    cnt++;
  }
  else if(cnt == 1)
  {
    setRandomColor();
    printColor();
    delay(1000);
  }

}
void blinker(int num, int bSpeed)
{
  for (int i = 0; i < num * 2; i++)
  {
    if (!x)
    {
      for (int i = 0; i < 100; i++)
      {
        if (bSpeed == 0)
        {
          g += 1;
          delay(100);
        }
        else if (bSpeed == 1)
        {
          b += 1;
          delay(50);
        }
        else
        {
          r += 1;
          delay(0);
        }
        setColor(r, g, b);
        printColor();
      }
      x = true;
    }
    else
    {
      for (int i = 0; i < 100; i++)
      {
        if (bSpeed == 0)
        {
          g -= 1;
          delay(100);
        }
        else if (bSpeed == 1)
        {
          b -= 1;
          delay(50);
        }
        else
        {
          r -= 1;
          delay(0);
        }
        setColor(r, g, b);
        printColor();
      }
      x = false;
    }
  }
  setColor(0, 0, 0);
}

void randomBlinker(int num)
{
  setRandomColor();
  printColor();
}

void setRandomColor()
{
  r = random(0,255);
  g = random(0, 255);
  b = random(0, 255);
  setColor(r, g, b);
}

void randomVals()
{
  r = random(0, 255);
  g = random(0, 255);
  b = random(0, 255);
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
