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


ADS868x::cmd_CLEAR_HWORD()
{

}


ADS868x::cmd_READ_HWORD()
{

}


ADS868x::cmd_READ()
{


}


ADS868x::cmd_WRITE()
{

}


ADS868x::cmd_SET_HWORD()
{

}


