/*
 * LcdDisplay.h
 *
 * Created: 4/1/2014 18:03:52
 *  Author: ednei.alves
 */ 


#ifndef LCDDISPLAY_H_
#define LCDDISPLAY_H_

#include <asf.h>
#include "config/conf_lcd_display.h"
#include "config/conf_lcdca.h"

void lcdca_init(void);
void LcdWrite(const char * str);



#endif /* LCDDISPLAY_H_ */