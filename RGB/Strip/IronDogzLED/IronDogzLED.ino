//Tyler Graham
//IRONDOGZ 2773
//Last edited  1/19/19
//IRONDOGZ LED

#include <FastLED.h>
#include <time.h>
#include <stdlib.h>

#define LED_PIN     7
#define NUM_LEDS    86
int autoStep = 0;
double r = 0;
double g = 0;
double b = 0;
int star1Bright;
int star2Bright;
int star3Bright;
boolean star1Direction = true; //true for forward
boolean star2Direction = true;
boolean star3Direction = true;
int starIterations = 0;
int sDel = 100;
int gHue = 0;
int GLOBAL_BRIGHTNESS = 200;
CRGB leds[NUM_LEDS];
int stars[NUM_LEDS];

#define max1Bright   50
#define max2Bright   120
#define max3Bright   250

const TProgmemRGBPalette16 RippleRed_p FL_PROGMEM =
{  CRGB::Red,CRGB::Red,CRGB::Black, CRGB::Black,
   CRGB::Black, CRGB::Red, CRGB::Black, CRGB::Black, 
   CRGB::Red,CRGB::Black, CRGB::Red, CRGB::Black, 
   CRGB::Black, CRGB::Black, CRGB::Red, CRGB::Black };

void setup() {
  //pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setMaxPowerInVoltsAndMilliamps(5, 1000);
  srand(time(NULL));
  clearAll();
  //assignStarVals();
}

void loop()
{
  int i=0;
  for(int i; i<NUM_LEDS; i++){              
  CRGBPalette16 palette = RippleRed_p;LINEARBLEND;   // moving backgrounds
  leds[i] += ColorFromPalette(palette,gHue+(i*8),GLOBAL_BRIGHTNESS);
}
  int j=0;
  for(int j; j<NUM_LEDS; j++){              
  CRGBPalette16 palette = RippleRed_p;LINEARBLEND;   // moving backgrounds

  leds[j] += ColorFromPalette(palette,gHue-(j*8),GLOBAL_BRIGHTNESS);
  }
  /*RGBAll(255, 0, 0);
  delay(500);
  RGBAll(0, 255, 0);
  delay(500);
  RGBAll(0, 255, 255);
  delay(500);
  RGBAll(0, 0, 255);
  delay(500);
  RGBAll(255, 0, 255);
  delay(500);*/
  /*for(int i = 0; i < 255; i++)
  {
    HSVAll(0, 0, i);
    delay(10);
  }
  delay(50);
  clearAll();
  for (int i = 0; i < 5; i++)
  {
    strobe(sDel);
  }
  for (int i = 0; i < 5; i++)
  {
    RGBAll(255, 0, 0);
    delay(150);
    RGBAll(255, 128, 0);
    delay(150);
    RGBAll(251, 255, 0);
    delay(150);
    RGBAll(55, 255, 0);
    delay(150);
    RGBAll(0, 255, 255);
    delay(150);
    RGBAll(0, 0, 255);
    delay(150);
    RGBAll(242, 0, 255);
    delay(150);
  }
  RGBAll(255, 255, 255);
  delay(50);
  coolRainbow(1, 4, 255, 600);
  clearAll();
  for(int i = 0; i < 16; i++)
  {
    everyOtherRGB(0, 255, 0, false);
    delay(150);
    everyOtherRGB(0, 255, 0, true);
    delay(150);
  }
  RGBAll(0, 255, 0);
  delay(300);
  fillToMiddle(0, 0, 0);
  delay(1000);*/
  }

void clearAll()
{
  for (int i = 0; i < NUM_LEDS; i++)
  {
    leds[i] = CRGB:: Black;
  }
  FastLED.show();
}

void RGBAll(int r, int g, int b)
{
  for (int i = 0; i < NUM_LEDS; i++)
  {
    leds[i] = CRGB(r, g, b);
    delay(0);
  }
  FastLED.show();
}

void HSVAll(int h, int s, int v)
{
  for (int i = 0; i < NUM_LEDS; i++)
  {
    leds[i] = CHSV(h, s, v);
    delay(0);
  }
  FastLED.show();
}

void everyOtherRGB(int r, int g, int b, boolean odd)
{
  for(int i = 0; i < NUM_LEDS; i++)
  {
    if(odd)
    {
      if(i % 2 == 1)
      {
        leds[i] = CRGB(r, g, b);
      }
      else
      {
        leds[i] = CRGB(0, 0, 0);
      }
    }
    else
    {
      if(i % 2 == 0)
      {
        leds[i] = CRGB(r, g, b);
      }
      else
      {
        leds[i] = CRGB(0, 0, 0);
      }
    }
  }
  FastLED.show();
}

void fillUp(int r, int g, int b)
{
  for (int i = 0; i < NUM_LEDS; i++)
  {
    leds[i] = CRGB(r, g, b);
    delay(1000 / NUM_LEDS);
    FastLED.show();
  }
}

void cycleBack()
{
  for (int i = NUM_LEDS; i >= 0; i--)
  {
    leds[i] = CRGB(0, 0, 0);
    delay(100);
    FastLED.show();
  }
}

void assignStarVals()
{
  for (int i = 0; i < NUM_LEDS; i++)
  {
    stars[i] = (rand() % 4);
    Serial.println(stars[i]);
  }
  fixStarVals();
}

void fixStarVals()
{
  for (int i = 0; i < NUM_LEDS - 1; i += 2)
  {
    if (stars[i] == stars[i + 1] || stars[i] == stars[i - 1])
      stars[i] = 0;
  }
}

//Robot LED methods
void countDown(boolean red)
{
  if (red)
  {
    //RGBAll(255, 227, 4);
    RGBAll(0, 255, 0);
    delay(1000);
    RGBAll(0, 0, 255);
    delay(1000);
    RGBAll(255, 0, 0);
  }
  else
  {
    RGBAll(0, 255, 0);
    delay(1000);
    RGBAll(255, 0, 0);
    delay(1000);
    RGBAll(0, 0, 255);
  }
}

void countDown2(boolean red)
{
  if (red)
  {
    fillUp(0, 255, 0);
    fillUp(0, 0, 255);
    fillUp(255, 0, 0);
  }
  else
  {
    fillUp(0, 255, 0);
    fillUp(255, 0, 0);
    fillUp(0, 0, 255);
  }
}

void move(boolean forward)
{
  if (forward)
  {

  }
  else
  {
    RGBAll(255, 0, 0);
    delay(20);
    RGBAll(0, 0, 0);
    delay(20);
  }
}

void shoot(boolean shoot)
{
  if (shoot)
  {
    for (int i = 0; i < NUM_LEDS; i++)
    {
      leds[i] = CRGB(255, 180, 4);
      delay(100);
      FastLED.show();
    }
    cycleBack();
    for (int i = 0; i < NUM_LEDS; i++)
    {
      leds[i] = CRGB(255, 0, 0);
      delay(100);
      FastLED.show();
    }
    cycleBack();
  }
}

void starLights(int h)
{
  for (int i = 0; i < NUM_LEDS; i++)
  {
    if (stars[i] != 0)
    {
      if (stars[i] == 1)
      {
        if (star1Direction)
        {
          star1Bright += 1;
          if (star1Bright > max1Bright)
            star1Direction = false;
        }
        else
        {
          star1Bright -= 1;
          if (star1Bright <= 0)
            star1Direction = true;
        }
        if (h == 0)
          leds[i] = CHSV(0, 0, star1Bright);
        else
          leds[i] = CHSV(h, 250, star1Bright);
      }
      if (stars[i] == 2)
      {
        if (star2Direction)
        {
          star2Bright += 1;
          if (star2Bright > max2Bright)
            star2Direction = false;
        }
        else
        {
          star2Bright -= 1;
          if (star2Bright <= 0)
            star2Direction = true;
        }
        if (h == 0)
          leds[i] = CHSV(0, 0, star2Bright);
        else
          leds[i] = CHSV(h, 250, star2Bright);
      }
      if (stars[i] == 3)
      {
        if (star3Direction)
        {
          star3Bright += 1;
          if (star3Bright > max3Bright)
            star3Direction = false;
        }
        else
        {
          star3Bright -= 1;
          if (star3Bright <= 0)
            star3Direction = true;
        }
        if (h == 0)
          leds[i] = CHSV(0, 0, star3Bright);
        else
          leds[i] = CHSV(h, 250, star3Bright);
      }
    }
  }
  FastLED.show();
  delay(75);
  starIterations += 1;
}

void oneByOne()
{
  Serial.println("1x1");
  for (int i = 0; i < NUM_LEDS; i++)
  {
    leds[i] = CRGB(255, 0, 0);
    FastLED.show();
    delay(1000);
    clearAll();
  }
}

void coolRainbow(int RGBSpeed, int RGBSpread, int RGBBright, int len) //1, 4, 100
{
  int x = 0;
  while (x < len)
  {
    for (int i = 0; i < NUM_LEDS; i++)
    {
      leds[i] = CHSV((i + x) * RGBSpread, 230, RGBBright);
      delay(RGBSpeed);
    }
    FastLED.show();
    x++;
  }
}

void fillToMiddle(int r, int g, int b)
{
  for (int i = 0; i < NUM_LEDS / 2; i++)
  {
    leds[i] = CRGB(r, g, b);
    leds[NUM_LEDS - 1 - i] = CRGB(r, g, b);
    FastLED.show();
    delay(50);
  }
}

void strobe(int del)
{
  RGBAll(255, 255, 255);
  delay(del);
  clearAll();
  delay(del);
}
/*ossyhhhdddddddddhhyyso+/
  /osyhdmdmmmmmmmmmmmmmmmmmmmmmmmmmdhso+
  +sydmmmmmmdyyyyydmmmmmmmmmmmmmdyyyyhmmmmmmdhs+/
  /oydmmmmmmmmmmmmmmmdsymmmmmmmmmmdsydmmmmmmmmmmmmmmmhs/
  /ohmmmmmmmmmmmmmmmmmmmmmhodmmmmmmmhsdmmmmmmmmmmmmmmmmmmmmds/
  +ydmmmmmmmmmmmmmmmmmmmmmmmmd+yssssssodmmmmmmmmmmmmmmmmmmmmmmmmho
  ohmmmmmmmmmmmmmmmmmmmmmmmmmy+           +hmmmmmmmmmmmmmmmmmmmmmmmmds/
  ohmmmmmmmmmmmmmmmmmmmmmmmmmm+               ommmmmmmmmmmmmmmmmmmmmmmmmds/
  +hmmmmmmmmmmmmmmmmmmmmmmmmmmmd                 mmmmmmmmmmmmmmmmmmmmmmmmmmmdo
  /ymmmmmmmmmmmmmmmmmmmmmmmmmmmmmms               ymmmmmmmmmmmmmmmmmmmmmmmmmmmmmh+
  +dmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmds+        /+sdmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmms
  smmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmdhhhhhdmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmh/
  ymmmmmmmmmmmmmmmmmmmmmmmmmmmmmdhhhhhhhhhhhhhhhhhhhhhhhhhdmmmmmmmmmmmmmmmmmmmmmmmmmmmmd/
  ymmmmmmmmmmmmmmmmmmmmmmmmmmmhs+                           /oymmmmmmmmmmmmmmmmmmmmmmmmmmd/
  ymmmmmmmmmmmmmmmmmmmmmmmmmhs+                                 /ohdmmmmmmmmmmmmmmmmmmmmmmmd/
  ommmmmmmmmmmmmmmmmmmmmmmds/                                       /ohmmmmmmmmmmmmmmmmmmmmmmh
  /dmmmmmmmmmmmmmmmmmmmmmho         /ooooooooooooooooooooooooo+         +ymmmmmmmmmmmmmmmmmmmmms
  hmmmmmmmmmmmmmmmmmmmmdo           ymmmmmmmmmmmmmmmmmmmmmmmmmd           +hmmmmmmmmmmmmmmmmmmmd/
  +mmmmmmmmmmmmmmmmmmmms             ossssssssssssssssssssssssss/            +dmmmmmmmmmmmmmmmmmmy
  ymmmmmmmmmmmmmmmmmmd+                                                       /hmmmmmmmmmmmmmmmmmd/
  dmmmmmmmmmmmmmmmmmd/                                                          hmmmmmmmmmmmmmmmmmo
  +mmmmmmmmmmmmmmmmmd+                                                            hmmmmmmmmmmmmmmmmy
  ommmmmmmmmmmmmmmmmo              oyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy              /dmmmmmmmmmmmmmmmh
  smmmmmmmmmmmmmmmmy              +dmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmms              ommmmmmmmmmmmmmmd
  smmmmmmmmmmmmmmmm/              ///////////////////////////////////               hmmmmmmmmmmmmmmh
  ommmmmmmmmmmmmmmh             //                                    /             ommmmmmmmmmmmmmh
  /mmmmmmmmmmmmmmms            /ho                                   /d+            +mmmmmmmmmmmmmms
  dmmmmmmmmmmmmmmo           /hmh                                   smd+           /mmmmmmmmmmmmmm+
  smmmmmmmmmmmmmmy          /dmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmdo          +mmmmmmmmmmmmmd
  /dmmmmmmmmmmmmmdo       /sdmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmy+       /dmmmmmmmmmmmmmo
  smmmmmmmmmmmmmmmyo+++symmmmmmmmh/                             +dmmmmmmmmhso+++sdmmmmmmmmmmmmmh
  hmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmh/                           +dmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm+
  /dmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmd+                         odmmmmmmmmmmmmmmmmmmmmmmmmmmmmmms
  +dmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmms//////////////////////+ymmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmy
  +dmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmy
  +dmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmms
  /hmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmdo+++smmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmdo
  smmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmo   ymmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmh/
  +hmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmh  /mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmdo
  odmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm+ smmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmdy/
  odmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmy/dmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmdy/
  ohmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmhmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmds/
  +ydmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmho
  +ydmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmho/
  +shmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmdyo/
  +sydmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmdhso/
  /+osyhdmmmmmmmmmmmmmmmmmmmmddhys+/
    /++ooosssssssoo++*/
