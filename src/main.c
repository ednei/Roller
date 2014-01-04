/**
 * \file
 *
 * \brief Empty user application template
 *
 */

/**
 * \mainpage User Application template doxygen documentation
 *
 * \par Empty user application template
 *
 * Bare minimum empty user application template
 *
 * \par Content
 *
 * -# Include the ASF header files (through asf.h)
 * -# Minimal main function that starts with a call to board_init()
 * -# "Insert application code here" comment
 *
 */

/*
 * Include header files for all drivers that have been imported from
 * Atmel Software Framework (ASF).
 */
#include <asf.h>

#define PORT_MASK 40
#define LCD_DUTY LCDCA_DUTY_1_4
#define LCD_CONTRAST_LEVEL 30

/** 14-segment with 4 commons terminals */
#define FIRST_14SEG_4C 36
#define WIDTH_14SEG_4C 7
#define DIR_14SEG_4C   1  /* 1 = from right to left */


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

int main (void)
{
	struct lcdca_circular_shift_config cs_cfg;
	struct lcdca_automated_char_config automated_char_cfg;

	sysclk_init();
	board_init();
	sleepmgr_init();
	lcdca_init();
	//lcdca_write_packet(LCDCA_TDG_7SEG4COM,0,"HW1",2,0);
	//lcdca_write_packet(LCDCA_TDG_14SEG4COM, FIRST_14SEG_4C, "Hello World", WIDTH_14SEG_4C, DIR_14SEG_4C);
	cs_cfg.lcd_csr_timer = LCDCA_TIMER_FC1;
	cs_cfg.lcd_csr_dir = LCDCA_CSR_RIGHT;
	cs_cfg.size = 7;    /* Total 7-pixels */
	cs_cfg.data = 0x03; /* Display 2 pixel at one time */
	lcdca_circular_shift_set_config(&cs_cfg);
	lcdca_circular_shift_enable();
	
	/* Automated sequential character string display */
	automated_char_cfg.automated_mode = LCDCA_AUTOMATED_MODE_SEQUENTIAL;
	automated_char_cfg.automated_timer = LCDCA_TIMER_FC2;
	automated_char_cfg.lcd_tdg = LCDCA_TDG_14SEG4COM;
	automated_char_cfg.stseg = FIRST_14SEG_4C;
	automated_char_cfg.dign = WIDTH_14SEG_4C;
	automated_char_cfg.steps = 0;
	automated_char_cfg.dir_reverse = LCDCA_AUTOMATED_DIR_REVERSE;
	lcdca_automated_char_set_config(&automated_char_cfg);
	lcdca_automated_char_start("Hello World ", 12);
//	printf("Press PB0 to stop automated sequential mode and continue.\n\r");
//	lcdca_automated_char_stop();

	while(1);

	// Insert application code here, after the board has been initialized.
}
