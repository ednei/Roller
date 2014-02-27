/*
* UsbCDC.c
*
* Created: 4/1/2014 22:09:43
*  Author: ednei.alves
*/

#include "UsbCdcHandlers.h"
#include "LcdDisplay.h"

char str[8];
int count;
bool usbCdcEnable(uint8_t port){
	for(int c=0;c<8;c++){
		str[c]=0;
	}
	count=0;
	return true;
}

void usbCdcDisable(uint8_t port){
	
}

void usbReceive(uint8_t port){
	if (udi_cdc_is_rx_ready()) {
		// Transmit next data
		str[count] = udi_cdc_getc();
		count++;
		if(count>=7){
			count=0;
		}
		LcdWrite(str);
		}else{
		LcdWrite("F");
	}
}