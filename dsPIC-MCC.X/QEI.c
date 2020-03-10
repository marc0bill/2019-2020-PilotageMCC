#include "header.h"	// processor, constantes,


void init_QEI()			// configure Encodeurs
{
	// to do
}

/***************************************************************************************
Interruption module QEI1
***************************************************************************************/
void __attribute__ ((interrupt, no_auto_psv)) _QEI1Interrupt(void) 
{
	IFS3bits.QEI1IF=0;	// acquittement
}

/***************************************************************************************
Interruption module QEI2
***************************************************************************************/
void __attribute__ ((interrupt, no_auto_psv)) _QEI2Interrupt(void) 
{
	IFS4bits.QEI2IF=0;	// acquittement
}
