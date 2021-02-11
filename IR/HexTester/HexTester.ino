//Just run and press each button and the hex code will show in the serial monitor

#include <IRremote.h>

const int RECV_PIN = 7;
IRrecv irrecv(RECV_PIN); //must have to receive data
decode_results results; //creates an object called results

void setup(){
  Serial.begin(9600);
  irrecv.enableIRIn(); //starts IR receiver
  irrecv.blink13(true); //makes it so the little LED on the thing blinks
}

void loop(){
  if (irrecv.decode(&results)){ //irrecv.decode turns true if code is received
        Serial.println(results.value, HEX); //prints the results in HEX form
        irrecv.resume();
  }
}
