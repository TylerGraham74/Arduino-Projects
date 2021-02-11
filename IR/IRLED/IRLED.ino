#include <IRremote.h>

const int RECV_PIN = 7;
IRrecv irrecv(RECV_PIN);
decode_results results;
const int LED0 = 4;
const int LED1 = 5;
const int LED2 = 6;
const int numLeds = 3;
boolean power = false;
boolean leds [numLeds];
int func = 0;
boolean runFunc = true;

void setup() {
  irrecv.enableIRIn();
  irrecv.blink13(true);
  pinMode(LED0, OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  if (irrecv.decode(&results))
  {
    checkIR();
    updateLeds();
    irrecv.resume();
  }
}

void updateLeds()
{
  for (int i = 0; i < numLeds; i++)
  {
    if (leds[i])
    {
      digitalWrite(i + 4, HIGH);
    }
    else
    {
      digitalWrite(i + 4, LOW);
    }
  }
}

void checkIR()
{
  switch (results.value)
  {
    case 0xFFA25D: //power button
      if (!power)
      {
        for (int i = 0; i < numLeds; i++)
        {
          leds[i] = true;
        }
        power = true;
      }
      else
      {
        for (int i = 0; i < numLeds; i++)
        {
          leds[i] = false;
        }
        power = false;
      }
      break;
    case 0xFF6897: //0 button
      if (power && func == 0)
      {
        leds[0] = !leds[0];
      }
      break;
    case 0xFF30CF: //1 button
      if (power && func == 0)
      {
        leds[1] = !leds[1];
      }
      break;
    case 0xFF18E7: //2 button
      if (power && func == 0)
      {
        leds[2] = !leds[2];
      }
      break;
    case 0xFFE21D: //func button
      if (power && func == 0)
      {
        func++;
      }
      if (func != 0)
      {
        if (func == 1)
        {
          dots();
        }
      }
      break;
  }
}

void allOff()
{
  for (int i = 0; i < numLeds; i++)
  {
    leds[i] = false;
  }
  updateLeds();
}

void dots()
{
  boolean go = true;
  while (go)
  {
    for (int i = 0; i < 3; i++)
    {
      allOff();
      leds[i] = true;
      updateLeds();
      switch (results.value)
      {
        case 0xFFE21D:
          Serial.print("x");
          break;
      }
      delay(500);
    }
  }
}
