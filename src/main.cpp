#define ESP32_RTOS  // This line allows us to run the OTA handle function on the second core of the ESP32.  Comment this line out if you are not using an ESP32.
#include <Arduino.h>
#include "WiFiCreds.h"
#include "OTA.h"

uint32_t entry;

void setup() {
  Serial.begin(115200);
  Serial.println("Booting");

  setupOTA("TemplateSketch", mySSID, myPASSWORD);
  
  // Insert other setup code here
}

void loop() {
  // Below is demo loop code
  entry = micros();
  
  // TelnetStream is a library that allows you to redirect serial output to a telnet session.
  TelnetStream.println(micros()-entry);
  TelnetStream.println("Loop");
  delay(1000);
}