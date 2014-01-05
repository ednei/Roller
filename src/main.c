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
#include "TargetCode/LcdDisplay.h"

int main (void)
{
	//used by usb
	irq_initialize_vectors();
	cpu_irq_enable();
	
	sysclk_init();
	board_init();
	sleepmgr_init();
	lcdca_init();
	//init usb stack
	udc_start();
	
	LcdWrite("Hw3");

	//if we but cpu on sleep mode we have to wake it but how
	while (true); /*{
		sleepmgr_enter_sleep();
	}*/

	// Insert application code here, after the board has been initialized.
}
