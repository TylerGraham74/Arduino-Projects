//This is the final compilation of many LED projects
//WS2812 RGB Strip

#include <FastLED.h>
#include <IRremote.h>

#define LED_PIN     5
#define TRIG_PIN    7
#define ECHO_PIN    9
#define RECV_PIN    3
#define NUM_LEDS    150

CRGB leds[NUM_LEDS];

IRrecv irrecv(RECV_PIN);
decode_results results;

int autoStep = 0;
double r = 0;
double g = 0;
double b = 0;
int h = 0;
int s = 255;
int v = 150;
long duration;
int distance;
int color;
int mode;
boolean power = false;
boolean upArr = false;
boolean dwnArr = false;

void setup() {
  pinMode(TRIG_PIN, OUTPUT); // Sets the TRIG_PIN as an Output
  pinMode(ECHO_PIN, INPUT); // Sets the ECHO_PIN as an Input
  irrecv.enableIRIn();
  irrecv.blink13(true);
  Serial.begin(9600);
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  clearAll();
  Serial.print("Setup done.");
  Serial.print("\n");
}

void loop()
{
  if (irrecv.decode(&results))
  {
    checkIR();
    updateStrip();
    irrecv.resume();
  }
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

void clearAll()
{
  for (int i = 0; i < NUM_LEDS; i++)
  {
    leds[i] = CRGB::Black;
  }
  FastLED.show();
}

void checkIR()
{
  switch (results.value)
  {
    case 0xFFA25D:
      power = !power;
      break;
    case 0xFF6897:
      color = 0;
      break;
    case 0xFF30CF:
      color = 1;
      break;
    case 0xFF18E7:
      color = 2;
      break;
    case 0xFF7A85:
      color = 3;
      break;
    case 0xFF10EF:
      color = 4;
      break;
    case 0xFF38C7:
      color = 5;
      break;
    case 0xFF5AA5:
      color = 6;
      break;
    case 0xFF42BD:
      color = 7;
      break;
    case 0xFF906F:
     upArr = true;
      break;
    case 0xFFE01F:
      dwnArr = true;
      break;
  }
}

void updateStrip()
{
  if (power)
  {
    leds[0] = CRGB(255, 0, 0);
    FastLED.show();
  }
  else
    clearAll();
  if (mode == 0 && power)
  {
    for(int i = 0; i < 8; i++)
    {
      if (i == color)
      {
        h = i * 32;
      }
    }
    if(upArr)
    {
      v += 20;
    }
    if(dwnArr)
    {
      v -= 20;
    }
    FastLED.show();
  }
}

void updateDistance()
{
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2); //delays 2 microseconds
  // Sets the TRIG_PIN on HIGH state for 10 micro seconds
  digitalWrite(TRIG_PIN, HIGH); //sends out signal
  delayMicroseconds(10); //waits 10 microseconds then stops
  digitalWrite(TRIG_PIN, LOW);
  // Reads the ECHO_PIN, returns the sound wave travel time in microseconds
  duration = pulseIn(ECHO_PIN, HIGH); //reads from ECHO_PIN
  // Calculating the distance
  distance = duration * 0.034 / 2; //time * speed of sound / 2
}

//--------------------------
//LED modes
//--------------------------

void allRainbow()
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

void coolRainbow(int RGBSpeed, int RGBSpread, int RGBBright) //1, 4, 100
{
  int x = 0;
  while (x < 999999)
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

void eveningVibes()
{
  for (int i = 0; i < 29; i++)
  {
    leds[i] = CHSV(h, 200, 150 - i * 4.5);
  }
  int x = 0;
  for (int i = NUM_LEDS - 1; i > NUM_LEDS - 28; i--)
  {
    leds[i] = CHSV(h, 200, 150 - x * 4.5);
    x++;
  }
  FastLED.show();
  delay(1000);
  h += 1;
}

void nightLight()
{
  if (distance <= 200)
  {
    for (int i = 0; i < NUM_LEDS; i++)
    {
      leds[i] = CHSV(180, 255, 150);
    }
    FastLED.show();
    delay(30000);
    clearAll();
  }
}
