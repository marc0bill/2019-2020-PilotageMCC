/*
Club Robot - Polytech Marseille

Révision:     	$Rev: $
Auteur:       	$Author: $
Date révision: 	$Date:  $
projet:      	$URL: $

*/

#include "header.h"	// processor, constantes, variables globales...
#include "init_pic.h"
#include "pwm.h"
#include "QEI.h"
#include "timer.h"
#include "uart.h"




/***********************************************************************
				CONFIGURATION DU PIC
***********************************************************************/
_FOSCSEL(FNOSC_PRIPLL); // Primary Oscillator (XT, HS, EC) w/ PLL
_FOSC(FCKSM_CSECMD & OSCIOFNC_OFF  & POSCMD_XT);
    //FCKSM_CSECMD  Clock switching is enabled, Fail-Safe Clock Monitor is disabled
    //OSCIOFNC_OFF  OSC2 pin has clock out function
    //POSCMD_XT     XT Oscillator Mode
_FWDT(FWDTEN_OFF);
    // FWDTEN_OFF   Watchdog timer enabled/disabled by user software
//Configuration pin I2C
_FPOR(ALTI2C_ON);



int main(void) {
    //initialisation
    init_clock();	// horloge
    init_port();	// ports
    init_interrupt();	// inerruption
    init_PWM1();      // PWM1
    init_QEI();       // Capteurs incrementals
    init_timer1();	 // Timer 1
    initUART1(230400); 
    tempsjeux=0;
    while(1){

    }
}



