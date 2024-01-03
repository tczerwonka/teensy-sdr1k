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

int pll_mult = 1;

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



//==============================================================================
// ResetDDS
// first thing called under PowerOn() -- so I guess...
// mostly copied from hardware_v2.cs
//   Looks like I need:
//==============================================================================
void ResetDDS() {

	LatchRegister(lpt_addr, PIO_IC8, DDSRESET | DDSWRB);    // Reset the DDS chip
	LatchRegister(lpt_addr, PIO_IC8, DDSWRB);                                       // Leave WRB high
	DDSWrite(COMP_PD, 0x1D);                //Power down comparator
	if(pll_mult == 1) {
		DDSWrite(BYPASS_PLL, 0x1E);
	} else {
		DDSWrite((byte)pll_mult, 0x1E);
		DDSWrite(BYPASS_SINC, 0x20);
	} //else

}



//==============================================================================
// LatchRegister
//==============================================================================
void LatchRegister(ushort lpt, byte addr, byte data) {
	Parallel.outport(lpt, data);
	Parallel.outport((ushort)(lpt+2), addr);
	Parallel.outport((ushort)(lpt+2), PIO_NONE);
}
//              public static void outport(ushort addr, byte val)
//              {
//                      Debug.WriteLine("outport: "+addr.ToString("X")+"-"+val.ToString("X"));
//                      outport_dll(addr, val);
//              }





//==============================================================================
// DDSWrite
//==============================================================================
void DDSWrite(byte data, byte addr) {
	//Set up data bits
	LatchRegister(lpt_addr, PIO_IC11, data);
	//Set up address bits with WRB high
	LatchRegister(lpt_addr, PIO_IC8, (byte)(addr | DDSWRB));
	//Send write command with WRB low
	LatchRegister(lpt_addr, PIO_IC8, addr);
	//Return WRB high
	LatchRegister(lpt_addr, PIO_IC8, (byte)(addr | DDSWRB));
}
