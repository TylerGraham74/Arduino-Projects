//Include the .zip library and initialize rtc object
#include <DS3231.h>
DS3231  rtc(SDA, SCL);
Time t;

void setup() {
  Serial.begin(115200);
  rtc.begin();
  
  // The following lines can be uncommented to set the date and time
  //rtc.setDOW(SATURDAY);     // Can also use 1-7
  //rtc.setTime(4, 50, 0);     // hour:minute:second (24 hour)
  //rtc.setDate(29, 12, 2018);   // dd/mm/yyyy
}

void loop() {
  // Send Day-of-Week
  Serial.print(rtc.getDOWStr());
  Serial.print(" ");
  
  // Send date
  Serial.print(rtc.getDateStr(FORMAT_LONG, FORMAT_MIDDLEENDIAN)); //outputs as mm/dd/yyyy
  Serial.print(" -- ");
  // Send time
  Serial.println(rtc.getTimeStr());
  
  // Wait one second before repeating
  delay (1000);
}
