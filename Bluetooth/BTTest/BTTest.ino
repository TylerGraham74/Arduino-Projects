#include <SoftwareSerial.h>
SoftwareSerial EEBlue(10, 11); // RX | TX

int btVal = 0;
int LEDPin = 3;

void setup()
{
  pinMode(LEDPin, OUTPUT);
  Serial.begin(9600);
  EEBlue.begin(9600);  //Default Baud for comm, it may be different for your Module.
  Serial.println("The bluetooth gates are open.\nConnect to HC-05 from any other bluetooth device with 1234 as pairing key!.");
}

void loop()
{

  // Feed any data from bluetooth to Terminal.
  if (EEBlue.available())
  {
    btVal = EEBlue.read();
    Serial.print(btVal);
    Serial.print("\n");
    checkVal();
  }

  //  // Feed all data from termial to bluetooth
  //  if (Serial.available())
  //  {
  //    EEBlue.print(Serial.read());
}

void checkVal()
{
  if (btVal == 49)
  {
    digitalWrite(LEDPin, HIGH);
  }
  if (btVal == 50)
  {
    digitalWrite(LEDPin, LOW);
  }
}
