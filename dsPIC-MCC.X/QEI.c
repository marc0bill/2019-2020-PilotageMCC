#include "header.h"	// processor, constantes,


void init_QEI()			// configure Encodeurs
{
	//Interruptions sur les QEI
    IFS3bits.QEI1IF=0; //Flag 1
    IFS4bits.QEI2IF=0; //Flag 2
    IEC3bits.QEI1IE=1; //accepte interr QEI1
    IEC4bits.QEI2IE=1; //accepte interr QEI2
    //Liaisons filaires
    RPINR15bits.INDX1R=0b01010; //Lier QEI1 au RP10 
    RPINR17bits.INDX2R=0b10110; //Lier QEI2 au RP22
    //Initialisation du QEI
    QEI1CONbits.QEIM=0b111; //mode *4
    QEI2CONbits.QEIM=0b111;//identique
    //reset quand nombre atteint MAXxCNT
    
}

/***************************************************************************************
Interruption module QEI1
 * Les interruptions sont créées quand POSxCON atteint MAXxCON ou 0
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
