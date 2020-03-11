#include "header.h"
#include "pwm.h"

void init_PWM1()
{
    
    P1TCONbits.PTEN=1; //enable time base timer bit
    
    
    
    
    
///////////
////PWM 1 vers PWMM1L
    /*
PWM1CON1bits.PMOD3=1;	
PWM1CON1bits.PMOD2=1;	 //on rend inépendant les pair PWM High et Low
PWM1CON1bits.PMOD2=1;

PWM1CON1bits.PEN1H=0;	
PWM1CON1bits.PEN2H=0;  //Les pin PWM H sotn transformées I/O normales
PWM1CON1bits.PEN3H=0;

PWM1CON1bits.PEN1L=1;  //sortie de la PWM1L1 enable	
PWM1CON1bits.PEN2L=1; //sortie de la PWM1L2 enable 
PWM1CON1bits.PEN3L=0;	

PWM1CON2bits.SEVOPS=1000;
PWM1CON2bits.IUE=1; //updates to the active P1DC register immediate
PWM1CON2bits.OSYNC=1; //output overrides via the P1OVDCON register are synchronized to the pwm time base
PWM1CON2bits.UDIS=0; //updates from Duty Cycle and Period Buffer registers are enable
        
        
P1FLTACONbits.FAOV1L=1; //The pwm output pin is driven incative on an external fault input event
P1FLTACONbits.FLTAM=1; //fault A input pin functions in the cycle-by-cycle mode

P1FLTACONbits.FAEN2=1; // PWM1H2/L2 pin pair is controlled by fault inputA
P1FLTACONbits.FAEN1=1; //PWM1H1/L1 pin pair is controlled by fault inputA

P1OVDCONbits.POVD1L=1;  //Output on PWM1 pin is controlled by the PWM1 generator
 
P1DC1=1000000000000000; //valeur cyclique 50%

///////*
     * */
}



/********************************************************************************
interruption timer PWM1
********************************************************************************/
void __attribute__ ((interrupt, no_auto_psv)) _MPWM1Interrupt(void)
{	
	IFS3bits.PWM1IF=0;		// acquittement
}
