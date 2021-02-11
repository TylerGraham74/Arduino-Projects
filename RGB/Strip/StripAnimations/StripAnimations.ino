//Top of door is 62-89

#include <FastLED.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LED_PIN     7
#define NUM_LEDS    86
CRGB leds[NUM_LEDS];

void setup()
{
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  srand(time(NULL));
  Serial.begin(9600);
  clearAll();
}

void loop()
{
  clearAll();
}

void HSVBlink()
{
  int pos = getRand(0, 155);
  int color = getRand(0, 255);
  leds[pos] = CHSV(color, 230, 255);
  FastLED.show();
}

void lightBounce()
{
  for (int i = 0; i <= 150; i++)
  {
    leds[i] = CRGB(255, 0, 0);
    if (i > 2)
    {
      leds[i - 3] = CRGB::Black;
    }
    if (i > 0)
    {
      leds[i - 1] = CRGB(255, 0, 75);
    }
    if (i > 1)
    {
      leds[i - 2] = CRGB(238, 0, 255);
    }
    if (i < 147)
    {
      leds[i + 1] = CRGB(255, 0, 75);
    }
    if (i < 146)
    {
      leds[i + 2] = CRGB(238, 0, 255);
    }
    FastLED.show();
    delay(20);
  }
  for (int i = 150; i >= 0; i--)
  {
    leds[i] = CRGB(255, 0, 0);
    if (i < 153)
    {
      leds[i + 3] = CRGB::Black;
    }
    if (i < 150)
    {
      leds[i + 1] = CRGB(255, 0, 75);
    }
    if (i < 149)
    {
      leds[i + 2] = CRGB(238, 0, 255);
    }
    if (i > 2)
    {
      leds[i - 1] = CRGB(255, 0, 75);
    }
    if (i > 3)
    {
      leds[i - 2] = CRGB(238, 0, 255);
    }
    FastLED.show();
    delay(20);
  }
}

void shuffle(int r, int g, int b)
{
  for (int i = 0; i <= 150; i++)
  {
    if (i % 2 == 0)
    {
      leds[i] = CRGB(r, g, b);
    }
    else
    {
      leds[i] = CRGB::Black;
    }

  }
  FastLED.show();
  delay(300);
  for (int i = 0; i <= 150; i++)
  {
    if (i % 2 == 1)
    {
      leds[i] = CRGB(r, g, b);
    }
    else
    {
      leds[i] = CRGB::Black;
    }

  }
  FastLED.show();
  delay(300);
}

void strobe(int first, int last)
{
  for (int i = first; i <= last; i++)
  {
    leds[i] = CRGB:: White;
  }
  FastLED.show();
  delay(5);
  for (int i = first; i <= last; i++)
  {
    leds[i] = CRGB:: Black;
  }
  FastLED.show();
  delay(90);
}

void candyCane()
{
  for (int i = 0; i < 150; i += 4)
  {
    leds[i] = CHSV(3, 250, 100); //red
    leds[i + 1] = CHSV(3, 250, 100); //red
    leds[i + 2] = CHSV(0, 0, 100); //white
    leds[i + 3] = CHSV(0, 0, 100); //white
  }
  FastLED.show();
  delay(150);
  for (int i = 0; i < 150; i += 4)
  {
    leds[i] = CHSV(3, 250, 100); //red
    leds[i + 1] = CHSV(0, 0, 100); //white
    leds[i + 2] = CHSV(0, 0, 100); //white
    leds[i + 3] = CHSV(3, 250, 100); //red
  }
  FastLED.show();
  delay(150);
  for (int i = 0; i < 150; i += 4)
  {
    leds[i] = CHSV(0, 0, 100); //white
    leds[i + 1] = CHSV(0, 0, 100); //white
    leds[i + 2] = CHSV(3, 250, 100); //red
    leds[i + 3] = CHSV(3, 250, 100); //red
  }
  FastLED.show();
  delay(150);
  for (int i = 0; i < 150; i += 4)
  {
    leds[i] = CHSV(0, 0, 100); //white
    leds[i + 1] = CHSV(3, 250, 100); //red
    leds[i + 2] = CHSV(3, 250, 100); //red
    leds[i + 3] = CHSV(0, 0, 100); //white
  }
  FastLED.show();
  delay(150);
}

void christmasShow()
{
  for (int x = 0; x < 3; x++)
  {
    for (int i = 0; i < NUM_LEDS; i++)
    {
      leds[i] = CRGB(0, 255, 0);
      FastLED.show();
      delay(2);
    }
    delay(1000);
    for (int i = 0; i < NUM_LEDS; i++)
    {
      leds[i] = CRGB(255, 0, 0);
      FastLED.show();
      delay(2);
    }
    delay(1000);
    for (int i = 0; i < NUM_LEDS; i++)
    {
      leds[i] = CRGB(50, 100, 50);
      FastLED.show();
      delay(2);
    }
    delay(1000);
  }
  for(int x = 0; x < 25; x++)
  {
    candyCane();
  }
}

void lightFill(int hue, int sat, int val, boolean back, double halt) //negative halt will have it forever
{
  for (int i = 0; i < NUM_LEDS; i++)
  {
    leds[i] = CHSV(hue, sat, val);
    FastLED.show();
    delay(1);
  }
  if (back)
  {
    leds[149] = CHSV(hue, sat, val);
    FastLED.show();
    for (int i = NUM_LEDS; i >= 0; i--)
    {
      leds[i] = CHSV(hue, 230, 150);
      FastLED.show();
      delay(1);
    }
  }
  if (halt > 0)
  {
    delay(halt * 1000);
    clearAll();
  }
}

int getRand(int low, int high)
{
  int n = rand() % (high + 1 - low) + low;
  return n;
}

void clearAll()
{
  for (int i = 150; i > -1; i--)
  {
    leds[i] = CRGB::Black;
  }
  FastLED.show();
}

void showAll()
{
  for (int i = 0; i < 150; i++)
  {
    leds[i] = CRGB::White;
  }
  FastLED.show();
}
