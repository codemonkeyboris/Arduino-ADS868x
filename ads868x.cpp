/* 
	ADS868x.h - Library for TI 16-Bit, High-Speed, Single-Supply, SAR ADC Data Acquisition System
				with Programmable, Bipolar Input Ranges
	
	Started with ADS8689. The other 2 types will be implemented soon...
		
	version 0.1 (Sep 13, 2018) - Kick off.
	Created by Bohan Zheng, Sep 13, 2018.
	Copyright (c) 2018 Bohan Zheng(codemonkeyboris) under The MIT License (MIT)
	for other librarys and sketches look at https://github.com/codemonkeyboris
*/



#include <SPI.h>
#include <ads868x.h>
#include <Arduino.h>


ADS868x::ADS868x(int CS)
{
	_CS = CS;
	pinMode(_CS, OUTPUT);
	digitalWrite(_CS, HIGH);	//deactivate Chipselect
	SPI.begin();
}


void ADS868x::cmd_CLEAR_HWORD(uint16_t addr , uint16_t data)
{
	uint8_t i = 0;
	uint16_t cmd_addr = _format_cmd_addr(CMDBITS_CLEAR_HWORD , addr);
	uint16_t recv[2];

	SPI.setClockDivider(SPI_CLOCK_DIV16);	//Set Clockdivider for 1MHz SPI freq.
	SPI.setBitOrder(MSBFIRST);
	SPI.setDataMode(SPI_MODE0);

	digitalWrite(_CS,LOW);
	recv[0] = SPI.transfer16(cmd_addr);
	recv[1] = SPI.transfer16(data);
	digitalWrite(_CS,HIGH);
		
}


uint16_t ADS868x::cmd_READ_HWORD()
{
	uint8_t i = 0;
	uint16_t cmd_addr = _format_cmd_addr(CMDBITS_READ_HWORD , addr);
	uint16_t recv[2];

	SPI.setClockDivider(SPI_CLOCK_DIV16);	//Set Clockdivider for 1MHz SPI freq.
	SPI.setBitOrder(MSBFIRST);
	SPI.setDataMode(SPI_MODE0);

	digitalWrite(_CS,LOW);
	recv[0] = SPI.transfer16(cmd_addr);
	recv[1] = SPI.transfer16(data);
	digitalWrite(_CS,HIGH);

	return recv[1];
}


uint8_t ADS868x::cmd_READ()
{
	uint8_t i = 0;
	uint16_t cmd_addr = _format_cmd_addr(CMDBITS_READ , addr);
	uint16_t recv[2];

	SPI.setClockDivider(SPI_CLOCK_DIV16);	//Set Clockdivider for 1MHz SPI freq.
	SPI.setBitOrder(MSBFIRST);
	SPI.setDataMode(SPI_MODE0);

	digitalWrite(_CS,LOW);
	recv[0] = SPI.transfer16(cmd_addr);
	recv[1] = SPI.transfer16(data);
	digitalWrite(_CS,HIGH);

	return recv[1];

}


void ADS868x::cmd_WRITE(uint16_t addr , uint16_t data)
{

}


void ADS868x::cmd_SET_HWORD(uint16_t addr , uint16_t data)
{

}


////////////////////////////////

uint16_t ADS868x::_format_cmd_addr(uint8_t cmd, uint8_t addr)
{
	uint16_t res = (cmd | (addr > 7)) < 8;
	res |= (addr < 1);		// last bit is the 1st bit of the address
	return res;
}







