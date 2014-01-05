/*
 * Usb.h
 *
 * Created: 4/1/2014 22:10:10
 *  Author: ednei.alves
 */ 


#ifndef USB_H_
#define USB_H_

#include <stdint.h> 
#include <stdbool.h>
#include "usb_protocol_cdc.h"

bool usbCdcEnable(uint8_t port);
void usbCdcDisable(uint8_t port);
void usbReceive(uint8_t port);



#endif /* USB_H_ */