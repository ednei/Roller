/*
 * LcdDisplay.c
 *
 * Created: 4/1/2014 17:46:59
 *  Author: ednei.alves
 */ 

#include "LcdDisplay.h"

void lcdca_init(void)
{
	struct lcdca_config lcdca_cfg;
	
	// LCDCA Controller initialization
	// - Clock,
	// - Connect to C42364A glass LCD component,
	// - Timing: 64 Hz frame rate & low power waveform, FC0, FC1, FC2
	// - Interrupt: off
	lcdca_clk_init();
	lcdca_cfg.port_mask = PORT_MASK;
	lcdca_cfg.x_bias = false;
	lcdca_cfg.lp_wave = true;
	lcdca_cfg.duty_type = LCD_DUTY;
	lcdca_cfg.lcd_pres = false;
	lcdca_cfg.lcd_clkdiv = 3;
	lcdca_cfg.fc0 = 16;
	lcdca_cfg.fc1 = 2;
	lcdca_cfg.fc2 = 6;
	lcdca_cfg.contrast = LCD_CONTRAST_LEVEL;
	lcdca_set_config(&lcdca_cfg);
	lcdca_enable();
	lcdca_enable_timer(LCDCA_TIMER_FC0);
	lcdca_enable_timer(LCDCA_TIMER_FC1);
	lcdca_enable_timer(LCDCA_TIMER_FC2);
	
	// Turn on LCD back light
	ioport_set_pin_level(LCD_BL_GPIO, IOPORT_PIN_LEVEL_HIGH);
}

