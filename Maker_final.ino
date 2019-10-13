/**
 * Simple example showing how to toggle a led on click.
 *
 * To use this example, connect a switch between pin 5 and GND.
 * (Or simply use a piece of wire.)
 */

#include <Arduino.h>
#include <IRsend.h>
#include <IRrecv.h>
#include <IRremoteESP8266.h>
#include <IRutils.h>
#include <PinButton.h>

// ==================== start of TUNEABLE PARAMETERS ====================

// The GPIO an IR detector/demodulator is connected to. Recommended: 14 (D5)
const uint16_t kRecvPin = 2;

// GPIO to use to control the IR LED circuit. Recommended: 4 (D2).
const uint16_t kIrLedPin = 4;

// The Serial connection baud rate.
// NOTE: Make sure you set your Serial Monitor to the same speed.
const uint32_t kBaudRate = 115200;

// As this program is a special purpose capture/resender, let's use a larger
// than expected buffer so we can handle very large IR messages.
const uint16_t kCaptureBufferSize = 1024;  // 1024 == ~511 bits

// kTimeout is the Nr. of milli-Seconds of no-more-data before we consider a
// message ended.
const uint8_t kTimeout = 50;  // Milli-Seconds

// kFrequency is the modulation frequency all UNKNOWN messages will be sent at.
const uint16_t kFrequency = 38000;  // in Hz. e.g. 38kHz.

// ==================== end of TUNEABLE PARAMETERS ====================
// The IR transmitter.
IRsend irsend(kIrLedPin);
// The IR receiver.
IRrecv irrecv(kRecvPin, kCaptureBufferSize, kTimeout, false);
// Somewhere to store the captured message.
decode_results results;

// Create a new button object, listening on pin 5.
// You can have as many buttons as you like.
PinButton myButton(D3);

bool ledOn = false;
//uint16_t *btn1_value;
//uint16_t btn1_length ;
uint16_t *raw_array;
uint16_t length;

void setup() {
  irrecv.enableIRIn();  // Start up the IR receiver.
  irsend.begin();       // Start up the IR sender.

  Serial.begin(kBaudRate, SERIAL_8N1);
  while (!Serial)  // Wait for the serial connection to be establised.
    delay(50);
  Serial.println();

  Serial.print("SmartIRRepeater is now running and waiting for IR input "
               "on Pin ");
  Serial.println(kRecvPin);
  Serial.print("and will retransmit it on Pin ");
  Serial.println(kIrLedPin);
  
  //moje
  //pinMode(LED_BUILTIN, OUTPUT);
  //Serial.begin(115200);

}

void loop() {
    int btn_press = 0;
  // Read hardware pin, convert to click events
  myButton.update();
  if (myButton.isSingleClick()) {
    btn_press = 1;
    //results = 0;
  }
  if (myButton.isDoubleClick()) btn_press = 2;
  if (myButton.isLongClick()) btn_press = 3;
  
   // Check if an IR message has been received.
//  if (irrecv.decode(&results) & btn_press != 0) {  // We have captured something.
  if (btn_press == 3) {  // We have captured something.
    delete [] raw_array;

    irrecv.decode(&results);
  // The capture has stopped at this point.
Serial.print(resultToHumanReadableBasic(&results));
    // Convert the results into an array suitable for sendRaw().
    // resultToRawArray() allocates the memory we need for the array.
    raw_array = resultToRawArray(&results);
//    *btn1_value = *raw_array;
    // Find out how many elements are in the array.
    length = getCorrectedRawLength(&results);
//    btn1_length = length;
    // Send it out via the IR LED circuit.
//    delay(3000);
//    irsend.sendRaw(raw_array, length, kFrequency);
    // Resume capturing IR messages. It was not restarted until after we sent
    // the message so we didn't capture our own message.
    irrecv.resume();
    // Deallocate the memory allocated by resultToRawArray().
    //
    // Display a crude timestamp & notification.
    uint32_t now = millis();
    Serial.printf(
        "%06u.%03u: A message that was %d entries long was retransmitted.\n",
        now / 1000, now % 1000, length);
  }

if (  btn_press == 1){
  Serial.print("POSILAM");
  irsend.sendRaw(raw_array, length, kFrequency);
  delay(10);
  irsend.sendRaw(raw_array, length, kFrequency);
      uint32_t now = millis();
    Serial.printf(
        "%06u.%03u: A message that was %d entries long was retransmitted.\n",
        now / 1000, now % 1000, length);
}
yield();
}
