//=================================================================
// hardware_v2.h
// Definitions, etc from PowerSDR (below) 
//=================================================================
// hardware_v2.cs
//=================================================================
// PowerSDR is a C# implementation of a Software Defined Radio.
// Copyright (C) 2004-2012  FlexRadio Systems
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
//
// You may contact us via email at: gpl@flexradio.com.
// Paper mail may be sent to: 
//    FlexRadio Systems
//    4616 W. Howard Lane  Suite 1-150
//    Austin, TX 78728
//    USA
//=================================================================


#ifndef HARDWARE_V2_H
#define HARDWARE_V2_H


	// Configurations
	static const int PIO = 0;
	static const int RFE = 1;
	static const int RFX = 2;
	
	// PIO IC1 pins
	static const int BPF0		= 0;
	static const int BPF1		= 1;
	static const int BPF3		= 2;
	static const int BPF2		= 3;
	static const int BPF4		= 4;
	static const int BPF5		= 5;
	static const int TR		= 6;
	static const int MUTE		= 7;
	
	// PIO IC3 pins
	static const int X2_1		= 0;
	static const int X2_2		= 1;
	static const int X2_3		= 2;
	static const int X2_4		= 3;
	static const int X2_5		= 4;
	static const int X2_6		= 5;
	static const int X2_7		= 6;
	static const int GAIN		= 7;
	
	// RFE IC7 pins
	static const int AMP2		= 0;	// 1W -- switch together with AMP1
	static const int AMP1		= 1;	// 1W -- switch together with AMP2
	static const int XVTX		= 2;
	static const int XVEN		= 3;
	static const int ATTN		= 4;
	static const int IMPR_EN	= 5;
	static const int PA_BIAS	= 6;
	static const int IMPR		= 7;
	
	// RFE IC9 pins
	static const int LPF0		= 0;
	static const int LPF1		= 1;
	static const int LPF2		= 2;
	static const int LPF3		= 3;
	static const int LPF4		= 4;
	static const int LPF5		= 5;
	static const int LPF6		= 6;
	static const int LPF7		= 7;
	
	// RFE IC10 pins
	static const int LPF8		= 0;
	static const int LPF9		= 1;
	static const int BPF5_PT	= 2;
	static const int BPF4_PT	= 3;
	static const int BPF2_PT	= 4;
	static const int BPF3_PT	= 5;
	static const int BPF1_PT	= 6;
	static const int BPF0_PT	= 7;
	
	// RFE IC11 pins
	static const int PAF0		= 0;
	static const int PAF1		= 1;
	static const int PAF2		= 2;
	static const int ADC_CLK	= 3;
	static const int ADC_DI	= 4;
	static const int ADC_CS_NOT= 5;
	static const int PA_TR		= 6;
	static const int ATU_CTL	= 7;
	
	// Control and data line pins for RFE serial decoders
	static const int RFE_SER		= 0x01;
	static const int RFE_SCK		= 0x02;
	static const int SCLR_NOT	= 0x04;
	static const int DCDR_NE	= 0x20;
	
	// PIO Register Address
	static const int PIO_IC1	= 0x9;
	static const int PIO_IC3	= 0xA;
	static const int PIO_IC8	= 0x3;
	static const int PIO_IC11	= 0xF;
	static const int PIO_NONE	= 0xB;
	
	// RFE 1:4 Decoder (74HC139) values to drive shift register RCK lines
	static const int RFE_IC7	= 0x08;
	static const int RFE_IC9	= 0x18;
	static const int RFE_IC10	= 0x10;
	static const int RFE_IC11	= 0x00;
	
	// PA filter selection
	static const int PA_LPF_OFF	= 0;					// 0
	static const int PA_LPF_12_10	= 1<<PAF0;				// 1
	static const int PA_LPF_17_15	= 1<<PAF1;				// 2
	static const int PA_LPF_30_20	= 1<<PAF0 | 1<<PAF1;	// 3
	static const int PA_LPF_60_40	= 1<<PAF2;				// 4
	static const int PA_LPF_80		= 1<<PAF2 | 1<<PAF0;	// 5
	static const int PA_LPF_160	= 1<<PAF2 | 1<<PAF1;	// 6
	
	// DDS Variables
	static const byte DDSWRB		= 0x40;
	static const byte DDSRESET		= 0x80;
	static const byte COMP_PD		= 0x10;		// DDS Comparator power down
	static const byte BYPASS_PLL	= 0x20;		// Bypass DDS PLL
	static const byte BYPASS_SINC	= 0x40;		// Bypass Inverse Sinc Filter
	
	
	
	
	
#endif
