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

// register map
#define REG_DEVICE_ID   		0x00
#define REG_RST_PWRCTL  		0x04
#define REG_SDI_CTL     		0x08
#define REG_SDO_CTL     		0x0C
#define REG_DATAOUT_CTL 		0x10
#define REG_RANGE_SEL   		0x14	
#define REG_ALARM      	 		0x20
#define REG_ALARM_H_THG  		0x24
#define REG_ALARM_L_TH  		0x28

/* binary commands
 * - the first 8 bits of a command.
 * - the last bit is the 1st bit of the 9-bit address.
*/
#define CMDBITS_CLEAR_HWORD 	0xc0		// 11000_xx_<9-bit address>_<16-bit data>
#define CMDBITS_READ_HWORD 		0xc8		// hex(int(11001_xx_<9-bit address>_00000000_00000000 , 2)) in python
#define CMDBITS_READ 			0x48 		// 01001_xx_<9-bit address>_00000000_00000000
#define CMDBITS_SET_HWORD		0xd8		// 11011_xx_<9-bit address>_<16-bit data>		


class ADS868x
{
	public:
		//constructor
		ADS868x(int CS);
		
		// page 42 Table 5
		void cmd_CLEAR_HWORD(uint16_t addr , uint16_t data);
		uint16_t cmd_READ_HWORD();		// getting 16 bits
		uint8_t cmd_READ();				// getting 8 bits
		void cmd_WRITE(uint16_t addr , uint16_t data);
		void cmd_SET_HWORD(uint16_t addr , uint16_t data);

		// configuration
		config()
	
	private:
		// variables
		int _CS;
		int _RVS;
		uint32_t* _recv_buf;

		// functions
		uint16_t _format_cmd_addr(uint8_t cmd, uint8_t addr);
};
#endif