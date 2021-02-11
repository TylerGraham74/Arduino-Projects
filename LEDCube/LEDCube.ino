//LED Cube
//Jul 28, 2019
//Tyler Graham

/* Notes
   Layers are HIGH/1 for on
   Columns are LOW/0 for on
*/

#include <time.h>
#define BUTTONPIN   A7

int layer[4] = {A0, A1, A2, A3}; //Horizontal layers
int column[16] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 1, 0, A4, A5}; //Columns

int randomRain[5]; //Randomly generated columns for rain
int s = 300;
int xCor = 0;
int yCor = 0;
int zCor = 0;

int mode = 4;
int buttonState;

void setup()
{
  //pinMode(0, OUTPUT);
  pinMode(A7, INPUT);
  srand(time(NULL));
  for (int i = 0; i < 4; i++)
  {
    pinMode(layer[i], OUTPUT); //sets layers to output
  }
  for (int i = 0; i < 16; i++)
  {
    pinMode(column[i], OUTPUT); //sets columns to output
  }
  allOff();
}

void loop()
{
  checkButton();
  s = 300;
  if (mode == 0)
  {
    allOn();
  }
  else if (mode == 1)
  {
    lightShow();
  }
  else if (mode == 2)
  {
    wander();
  }
  else if (mode == 3)
  {
    generateRainArr(5);
    checkButton();
    rain(randomRain, 5);
    checkButton();
  }
  else
  {
    allOff();
  }
}



//Turns all LEDs off
void allOff()
{
  for (int i = 0; i < 4; i++)
  {
    digitalWrite(layer[i], 0);
  }
  for (int i = 0; i < 16; i++)
  {
    digitalWrite(column[i], 1);
  }
}

//Turns all LEDs on
void allOn()
{
  for (int i = 0; i < 4; i++)
  {
    digitalWrite(layer[i], 1);
  }
  for (int i = 0; i < 16; i++)
  {
    digitalWrite(column[i], 0);
  }
  digitalWrite(0, LOW);
}

//turns a layer on with a given parameter
void layerOn(int lay)
{
  digitalWrite(layer[lay], 1);
  for (int i = 0; i < 16; i++)
  {
    digitalWrite(column[i], 0);
  }
}

//turns a layer off with a given parameter
void layerOff(int lay)
{
  digitalWrite(layer[lay], 0);
}

//Turns a row on
void rowOn(int row)
{
  for (int i = 0; i < 4; i++)
  {
    digitalWrite(layer[i], 1);
  }
  if (row == 0)
  {
    /*digitalWrite(column[0], 1);
      digitalWrite(column[4], 1);
      digitalWrite(column[8], 1);
      digitalWrite(column[12], 1);*/
    for (int i = 0; i < 16; i += 4)
    {
      digitalWrite(column[i], 0);
    }
  }
  else if (row == 1)
  {
    for (int i = 1; i < 16; i += 4)
    {
      digitalWrite(column[i], 0);
    }
  }
  else if (row == 2)
  {
    for (int i = 2; i < 16; i += 4)
    {
      digitalWrite(column[i], 0);
    }
  }
  else
  {
    for (int i = 3; i < 16; i += 4)
    {
      digitalWrite(column[i], 0);
    }
  }
}

//Turns a row off
void rowOff(int row)
{
  if (row == 0)
  {
    for (int i = 0; i < 16; i += 4)
    {
      digitalWrite(column[i], 1);
    }
  }
  else if (row == 1)
  {
    for (int i = 1; i < 16; i += 4)
    {
      digitalWrite(column[i], 1);
    }
  }
  else if (row == 2)
  {
    for (int i = 2; i < 16; i += 4)
    {
      digitalWrite(column[i], 1);
    }
  }
  else
  {
    for (int i = 3; i < 16; i += 4)
    {
      digitalWrite(column[i], 1);
    }
  }
}

//Turns designated column on
void colOn(int col)
{
  for (int i = 0; i < 4; i ++)
  {
    digitalWrite(layer[i], 1);
  }
  digitalWrite(column[col], 0);
}

//Turns designated column off
void colOff(int col)
{
  digitalWrite(column[col], 1);
}

//Finna be lit (t is time in milliseconds)
void strobe(int t)
{
  checkButton();
  if ((t > 0) && mode == 1)
  {
    allOff();
    checkButton();
    delay(t);
    checkButton();
    allOn();
    checkButton();
    delay(t);
    checkButton();

  }
}

//Turns on each layer going up (only one at a time)
void layUp()
{
  layerOn(0);
  delay(100);
  allOff();
  layerOn(1);
  delay(100);
  allOff();
  layerOn(2);
  delay(100);
  allOff();
  layerOn(3);
  delay(100);
  allOff();
}

//Turns on each layer going down (only one at a time)
void layDown()
{
  layerOn(3);
  delay(100);
  allOff();
  layerOn(2);
  delay(100);
  allOff();
  layerOn(1);
  delay(100);
  allOff();
  layerOn(0);
  delay(100);
  allOff();
}

//Makes layers turn on and off in an up and down pattern
void layUpDown()
{
  layUp();
  layDown();
}

//Turns on each row starting at the left and moving right (only one at a time)
void rowRight()
{
  rowOn(0);
  delay(100);
  allOff();
  rowOn(1);
  delay(100);
  allOff();
  rowOn(2);
  delay(100);
  allOff();
  rowOn(3);
  delay(100);
  allOff();
}

//Turns on each row starting at the right and moving left (only one at a time)
void rowLeft()
{
  rowOn(3);
  delay(100);
  allOff();
  rowOn(2);
  delay(100);
  allOff();
  rowOn(1);
  delay(100);
  allOff();
  rowOn(0);
  delay(100);
  allOff();
}

//Turns on rows going back and forth
void rowBackForth()
{
  rowRight();
  rowLeft();
}

//Turns on each layer starting at 0, but leaves layers on
void fillUp()
{
  layerOn(0);
  delay(150);
  layerOn(1);
  delay(150);
  layerOn(2);
  delay(150);
  layerOn(3);
  delay(150);
}

//Turns off each layer starting at 0, but leaves them turned off
void emptyUp()
{
  layerOff(0);
  delay(150);
  layerOff(1);
  delay(150);
  layerOff(2);
  delay(150);
  layerOff(3);
  delay(150);
}

//Turns on each column starting at 0 and moving in sequential order
void colFill()
{
  for (int i = 0; i < 4; i++)
  {
    digitalWrite(layer[i], 1);
  }
  for (int i = 0; i < 16; i++)
  {
    digitalWrite(column[i], 0);
    delay(100);
  }
}

//Turns off each column starting at 0 and moving in sequential order
void colEmpty()
{
  for (int i = 0; i < 16; i++)
  {
    digitalWrite(column[i], 1);
    delay(100);
  }
}

//Turns on the middle 4 LEDs
void midCube()
{
  digitalWrite(layer[1], 1);
  digitalWrite(layer[2], 1);
  digitalWrite(column[5], 0);
  digitalWrite(column[6], 0);
  digitalWrite(column[9], 0);
  digitalWrite(column[10], 0);
}

//Turns on columns to form a checkerboard pattern
void checkers(boolean odd)
{
  allOff();
  for (int i = 0; i < 4; i++)
  {
    digitalWrite(layer[i], 1);
  }
  if (odd)
  {
    digitalWrite(column[0], 0);
    digitalWrite(column[2], 0);
    digitalWrite(column[5], 0);
    digitalWrite(column[7], 0);
    digitalWrite(column[8], 0);
    digitalWrite(column[10], 0);
    digitalWrite(column[13], 0);
    digitalWrite(column[15], 0);
  }
  else
  {
    digitalWrite(column[1], 0);
    digitalWrite(column[3], 0);
    digitalWrite(column[4], 0);
    digitalWrite(column[6], 0);
    digitalWrite(column[9], 0);
    digitalWrite(column[11], 0);
    digitalWrite(column[12], 0);
    digitalWrite(column[14], 0);
  }
}

//Alters the randomRain array given the proper length
void generateRainArr(int len)
{
  for (int i = 0; i < len; i++)
  {
    randomRain[i] = (rand() % 16);
  }
}

//Takes an array of columns and makes rain pattern on specified columns
void rain(int col[], int len)
{
  for (int i = 0; i < len; i++)
  {
    digitalWrite(col[i], 0);
  }
  for (int i = 3; i >= 0; i--)
  {
    digitalWrite(layer[i], 1);
    if (i < 3)
      digitalWrite(layer[i + 1], 0);
    delay(140);
  }
  digitalWrite(layer[0], 0);
  allOff();
}

void wander()
{
  allOff();
  checkButton();
  digitalWrite(column[0], 0);
  int dir = (rand() % 3);
  if (mode == 2)
  {
    if (dir == 0)
    {
      int go = (rand() % 2);
      if (go == 0)
      {
        xCor--;
      }
      else
      {
        xCor++;
      }
    }
    else if (dir == 1)
    {
      int go = (rand() % 2);
      if (go == 0)
      {
        yCor--;
      }
      else
      {
        yCor++;
      }
    }
    else
    {
      int go = (rand() % 2);
      if (go == 0)
      {
        zCor--;
      }
      else
      {
        zCor++;
      }
    }
    /*if (xCor < 0 || xCor > 3 || yCor < 0 || yCor > 3 || zCor < 0 || yCor > 3)
      {
      allOff();
      delay(500);
      xCor = 0;
      yCor = 0;
      zCor = 0;
      }*/
    if (xCor < 0)
    {
      xCor += 2;
    }
    if (xCor > 3)
    {
      xCor -= 2;
    }
    if (yCor < 0)
    {
      yCor += 2;
    }
    if (yCor > 3)
    {
      yCor -= 2;
    }
    if (zCor < 0)
    {
      zCor += 2;
    }
    if (zCor > 3)
    {
      zCor -= 2;
    }
    wanderVisualize();
  }
}

void wanderVisualize()
{
  if(mode == 2)
  {
  checkButton();
  allOff();
  digitalWrite(layer[zCor], 1);
  checkButton();
  digitalWrite(column[xCor + (4 * yCor)], 0);
  checkButton();
  delay(250);
  checkButton();
  }
}

void lightShow()
{
  for (int i = 0; i < 30 && mode == 1; i++)
  {
    strobe(s);
    s -= 10;
    checkButton();
  }
  for (int i = 0; i < 3 && mode == 1; i++)
  {
    layUp();
    rowRight();
    layDown();
    rowLeft();
  }
  if (mode == 1)
  {
    fillUp();
    delay(150);
    emptyUp();
    delay(300);
  }
}

void checkButton()
{
  buttonState = analogRead(A7);
  if (buttonState > 512)
  {
    allOff();
    mode++;
    if (mode > 4)
    {
      mode = 0;
    }
    delay(500);
  }
}
