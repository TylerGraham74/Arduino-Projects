#include <FastLED.h>
#define LED_PIN     5
#define NUM_LEDS    150

int autoStep = 0;
double r = 0;
double g = 0;
double b = 0;

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  clearAll();
}

void loop() 
{
  if (autoStep == 0)
  {
    for (int i = 0; i < 100; i++)
    {
      r += 255.0 / 100;
      RGBAll(r, g, b);
      delay(25);
    }
    autoStep++;
  }
  else if (autoStep == 1)
  {
    for (int i = 0; i < 100; i++)
    {
      r -= 255.0 / 100;
      b += 130.0 / 100;
      RGBAll(r, g, b);
      delay(25);
    }
    autoStep++;
  }
  else if (autoStep == 2)
  {
    for (int i = 0; i < 100; i++)
    {
      b -= 130.0 / 100;
      g += 255.0 / 100;
      RGBAll(r, g, b);
      delay(20);
    }
    autoStep++;
  }
  else if (autoStep == 3)
  {
    for (int i = 0; i < 100; i++)
    {
      g -= 255.0 / 100;
      r += 255.0 / 100;
      RGBAll(r, g, b);
      delay(25);
    }
    autoStep = 1;
  }
}
void clearAll()
{
  for(int i = 0; i < NUM_LEDS; i++)
  {
    leds[i] = CRGB(0, 0, 0);
    delay(0);
  }
  FastLED.show();
}

void cycleBack()
{
  for(int i = NUM_LEDS; i >= 0; i--)
   {
    leds[i] = CRGB(0, 0, 0);
    delay(10);
    FastLED.show();
   }
}

void RGBAll(int r, int g, int b)
{
  for(int i = 0; i < NUM_LEDS; i++)
  {
    leds[i] = CRGB(r, g, b);
    delay(0);
  }
  FastLED.show();
}
