//=================================================================
// sdr1k_pcf.h
//=================================================================

#ifndef SDR1K_PCF_H
#define SDR1K_PCF_H

	static const int PCF_ADDR = 0x20;

  static const int PO0 = 0x00;
  static const int PO1 = 0x01;
  static const int PO2 = 0x02;
  static const int PO3 = 0x03;
  static const int PO4 = 0x04;
  static const int PO5 = 0x05;
  static const int PO6 = 0x06;
  static const int PO7 = 0x07;
  static const int PI0 = 0x08;
  static const int PI1 = 0x09;
  static const int PI2 = 0x0A;
  static const int PI3 = 0x0B;
  static const int PI4 = 0x0C;
  static const int PI5 = 0x0D;
  static const int PI6 = 0x0E;
  static const int PI7 = 0x0F;

	//SDR	PCF
	static const int C0	= PI0;	// PIO - X2 output / also K2 TRX gain
	static const int D0 =	PO0;
	static const int D1 = PO1;
	static const int D2 = PO2;
	static const int D3 = PO3;
	static const int D4 = PO4;
	static const int D5 = PO5;
	static const int D6 = PO6;
	static const int D7 = PO7;
	
	static const int C1 = PI1;	// BPF PIO
	static const int C2 = PI2;	// DAT - DDS0 / IC11
	static const int C3 = PI3;	// ADR - DDS1 / IC8

  //these are all input
 	static const int S3 = PI6;  // EXT X2-12 -- maybe input for ADC, etc?
 	static const int S4 = PI4;	// dash
 	static const int S5 = PI7;	// dot / ptt
  //no S6 -- is logic S4 || S5 -- for parallel interupt -- I don't care
	static const int S7 = PI5;	// EXT X2-11 -- maybe input for ADC, etc?




	
	
	
	
	
#endif
