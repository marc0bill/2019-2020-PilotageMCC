#include "header.h"
#include "pwm.h"

void init_PWM1()
{
	// todo
 }



/********************************************************************************
interruption timer PWM1
********************************************************************************/
void __attribute__ ((interrupt, no_auto_psv)) _MPWM1Interrupt(void)
{	
	IFS3bits.PWM1IF=0;		// acquittement
}
