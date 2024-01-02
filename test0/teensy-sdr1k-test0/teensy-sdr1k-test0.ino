//==============================================================================
// teensy-sdr1k-test0
//==============================================================================
// very basic code to see if I can do anything at all with the PCF8575
// using the following library:
//  https://github.com/RobTillaart/PCF8575
//==============================================================================

#include "hardware_v2.h"
#include "sdr1k_pcf.h"

#include <PCF8575.h>


PCF8575 PCF(PCF_ADDR);

void setup() {
  Serial.begin(115200);
  Serial.println(__FILE__);
  Serial.print("PCF8575_LIB_VERSION:\t");
  Serial.println(PCF8575_LIB_VERSION);

  Wire.begin();

  PCF.begin();

  //test of what is returned by read16
  //appears by default all pins are pulled high
  //without input all are reading 1 -- tied to ground -- read 0
  PCF.selectNone(); // set all pins low
  uint16_t value = PCF.read16();
  Serial.print("#bin:\t");
  Serial.println(value, BIN);
  //PCF8575_LIB_VERSION:	0.2.1
  //#bin:	110111111111111
  //PI7 PI6 PI5...PI0 PO7...PO0



}

void loop() {
  Serial.print("S3/PI6:");
  Serial.println(PCF.readButton(S3));
  delay(1000);
}
