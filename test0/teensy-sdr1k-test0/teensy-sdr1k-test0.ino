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

  //power on test
  PowerOn();
}



void loop() {
  //Serial.print("S3/PI6:");
  //Serial.println(PCF.readButton(S3));
  //delay(1000);
}


//==============================================================================
// PowerOn
//  copied from hardware_v2.cs 
//==============================================================================
void PowerOn() {
  ResetDDS();
  //DDSTuningWord = dds_tuning_word;
  //dds_tuning_word has an accessor function in hardware_v2 but looks to call 
  //dds_write -- so maybe by just setting the dds_tuning_word -- frequency is changed.
  //well -- now that will be interesting...comment out for now

  //pio_ic1.ForceUpdate();
  //pio_ic3.ForceUpdate();

  //rfe_ic7.ForceUpdate();
  //rfe_ic9.ForceUpdate();
  //rfe_ic10.ForceUpdate();
  //rfe_ic11.ForceUpdate();
  //UpdateHardware = true;
}





//==============================================================================
// ResetDDS
// first thing called under PowerOn() -- so I guess...
// mostly copied from hardware_v2.cs
//   does the following:
//   addr 0x08 is PIO_IC8 -- 8 lines control
//   addr 0x0F is PIO_IC11 -- 8 lines frequency
//     IC8/IC11 both 74LCX574S connected to the 16 lines on the DDS
//      addr-data
//outport: 0x03-0xC0/11000000 - DDSRESET | DDSWRB
//outport: 0x03-0x40/01000000 - DDSWRB
//   DDSWrite COMP_PD, 0x1D
//     outport: 0x0F-0x10/00010000 -- set up data bits
//     outport: 0x03-0x5D/01011101 -- set up address bits with WRB high
//     outport: 0x03-0x1D/00011101 -- send write command with WRB low
//     outport: 0x03-0x5D/01011101 -- Return WRB high
//   DDSWrite BYPASS_PLL, 0x1E
//     outport: 0x0F-0x20/00100000 
//     outport: 0x03-0x5E/01011110
//     outport: 0x03-0x1E/00011110
//     outport: 0x03-0x5E/01011110
//==============================================================================
void ResetDDS() {
  int lpt_addr; //whatever - remove later
	LatchRegister(lpt_addr, PIO_IC8, DDSRESET | DDSWRB);    // Reset the DDS chip
	LatchRegister(lpt_addr, PIO_IC8, DDSWRB);         
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
  Serial.print("outport: 0x0");
  Serial.print(addr,HEX);
  Serial.print("-0x");
  Serial.println(data,HEX);

	//Parallel.outport(lpt, data);
	//Parallel.outport((ushort)(lpt+2), addr);
	//Parallel.outport((ushort)(lpt+2), PIO_NONE);

  //              public static void outport(ushort addr, byte val) 
  //              {
  //                      outport_dll(addr, val);
  //              }
}




//==============================================================================
// DDSWrite
//==============================================================================
void DDSWrite(byte data, byte addr) {
  int lpt_addr = 0; //remove later
	//Set up data bits
	LatchRegister(lpt_addr, PIO_IC11, data);
	//Set up address bits with WRB high
	LatchRegister(lpt_addr, PIO_IC8, (byte)(addr | DDSWRB));
	//Send write command with WRB low
	LatchRegister(lpt_addr, PIO_IC8, addr);
	//Return WRB high
	LatchRegister(lpt_addr, PIO_IC8, (byte)(addr | DDSWRB));
}
