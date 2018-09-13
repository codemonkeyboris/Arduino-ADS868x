/* 
	ADS868x.h - Library for TI 16-Bit, High-Speed, Single-Supply, SAR ADC Data Acquisition System
				with Programmable, Bipolar Input Ranges
	
	Started with ADS8689. The other 2 types will be implemented soon...
		
	version 0.1 (Sep 13, 2018) - Kick off.
	Created by Bohan Zheng, Sep 13, 2018.
	Copyright (c) 2018 Bohan Zheng(codemonkeyboris) under The MIT License (MIT)
	for other librarys and sketches look at https://github.com/codemonkeyboris
*/


#ifndef ADS868x_h
#define ADS868x_h

#include <Arduino.h>

// binary commands
#define CMDBITS_CLEAR_HWORD 	0xc0000000		// 11000_xx_<9-bit address>_<16-bit data>
#define CMDBITS_READ_HWORD 		0xc8000000		// hex(int(11001_xx_<9-bit address>_00000000_00000000 , 2)) in python
#define CMDBITS_READ 			0x48000000 		// 01001_xx_<9-bit address>_00000000_00000000
#define CMDBITS_SET_HWORD		0xd8000000		// 11011_xx_<9-bit address>_<16-bit data>
												



class ADS868x
{
	public:
		//constructor
		ADS868x(int CS);
		// page 42 Table 5
		cmd_CLEAR_HWORD();
		cmd_READ_HWORD();
		cmd_READ();
		cmd_WRITE();
		cmd_SET_HWORD();

	private:
		int _CS;
		int RVS;
};
#endif