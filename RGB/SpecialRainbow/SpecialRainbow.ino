#include <FastLED.h>
#include <SoftwareSerial.h>

#define LED_PIN     7
#define NUM_LEDS    150

CRGB leds[NUM_LEDS];
SoftwareSerial EEBlue(10, 11); // RX | TX

int btVal;
boolean go;
int RGBSpeed;
int RGBSpread;
int RGBBright;

void setup() {
  Serial.begin(9600);
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  EEBlue.begin(9600);
  btVal = 1;
  go = false;
  RGBSpeed = 1;
  RGBSpread = 4;
  RGBBright = 100;
  clearAll();
  Serial.print("Setup done.");
  Serial.print("\n");
}

void loop()
{
  if (EEBlue.available())
  {
    btVal = EEBlue.read();
    Serial.print(btVal);
    Serial.print("\n");
    checkVals();
  }
}

void rainbow()
{
  int x = 0;
  while (x < 999999)
  {
    if (go)
    {
      for (int i = 0; i < 150; i++)
      {
        leds[i] = CHSV((i + x) * RGBSpread, 230, RGBBright);
        delay(RGBSpeed);
        btVal = EEBlue.read();
        if (btVal == 50)
        {
          go = false;
        }
      }
      FastLED.show();
      x++;
    }
    else
    {
      checkVals();
      break;
    }
  }
}

void clearAll()
{
  for (int i = 0; i < 150; i++)
  {
    leds[i] = CRGB::Black;
  }
  FastLED.show();
}

void checkVals()
{
  if (btVal == 49)
  {
    go = true;
    rainbow();
  }
  if (btVal == 50 || btVal == -1)
  {
    clearAll();
  }
}
