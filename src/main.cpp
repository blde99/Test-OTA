#define ESP32_RTOS  // Uncomment this line if you want to use the code with freertos only on the ESP32
                    // Has to be done before including "OTA.h"
#include <Arduino.h>
#include "WiFiCreds.h"
#include "OTA.h"

uint32_t entry;

void setup() {
  Serial.begin(115200);
  Serial.println("Booting");

  setupOTA("TemplateSketch", mySSID, myPASSWORD);
}

void loop() {
  entry = micros();
  TelnetStream.println(micros()-entry);
  TelnetStream.println("Loop");
  delay(1000);
}