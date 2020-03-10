#include "header.h"


//fonction d'initialisation de la clock
void init_clock() {
    PLLFBD = PLL_M;
    CLKDIVbits.PLLPOST = PLL_N1;    // N1 = 2
    CLKDIVbits.PLLPRE = PLL_N2;     // N2 = 2
    OSCTUN = 0;                     // Tune FRC oscillator, if FRC is used
    RCONbits.SWDTEN = 0;            // Disable WatchDog Timer
    RCON = 0; // aucune erreur ne gener de RESET
// Clock switch to incorporate PLL
    __builtin_write_OSCCONH(FTYPE); // Initiate Clock Switch to
                                    // Primary oscillator (XT, HS, EC) with PLL (NOSC=0b011)
    __builtin_write_OSCCONL(0x01);  // Start clock switching
    while (OSCCONbits.COSC != FTYPE);	// Wait for Clock switch to occur
    while(OSCCONbits.LOCK != 1) {};
}

/****************************************************************************************
*/
void init_port(void)
{	
    // configure entr�e analgique/num�rique
    AD1PCFGLbits.PCFG0=1;		// utilisation digitale de AN0
    AD1PCFGLbits.PCFG1=1;		// utilisation digitale de AN1
    AD1PCFGLbits.PCFG4=1;		// QEA1 : utilisation digitale de AN4
    AD1PCFGLbits.PCFG5=1;		// QEB1 : utilisation digitale de AN5
    AD1PCFGLbits.PCFG6=0;		// Current Sense 2 : Analog Input
    AD1PCFGLbits.PCFG7=0;           // Current Sense 1 : Analog Input
    
    TRISBbits.TRISB2 = 0; // RB2/RP2 en sortie
    TRISBbits.TRISB3 = 0; // RB3/RP3 en sortie
	RPINR14bits.QEB1R	=	2;	// voie B du QEI1 sur RP3
	RPINR14bits.QEA1R 	=	3;	// voie A du QEI1 sur RP2
	RPINR15bits.INDX1R 	=	10;	// Index du QEI1 sur RP10
	RPINR16bits.QEB2R 	=	9;	// voie B du QEI2 sur RP9
	RPINR16bits.QEA2R 	=	8;	// voie A du QEI2 sur RP8
	RPINR17bits.INDX2R 	=	22;	// Index du QEI2 sur RP22
	RPINR18bits.U1RXR 	= 	21;  	// assigne RX de UART1 sur RP21
	RPINR19bits.U2RXR 	= 	23;  	// assigne RX de UART2 sur RP23
	RPOR10bits.RP20R	= 0b00011 ;	// assigne TX de UART1 sur RP20 (00011<=>U1TX)
	RPOR3bits.RP7R		= 0b00101 ;	// assigne TX de UART2 sur RP7 (00101<=>U2TX)

	// configure direction des ports:
	T_Brake12=0;	// TRIS de Brake : sortie 
	T_SENS_M1=0;	// TRIS de SENS_M1 : sortie
	T_SENS_M2=0;	// TRIS de SENS_M2 : sortie

    // initialise les sorties:
	Brake12=0; 		// (PORT de) EN_MOT1 � 0
	SENS_M1=0;		// sens moteur 1: avance (a v�rifier)
	SENS_M2=0;		// sens moteur 2: avance (a v�rifier)
}


//fonction de configuration de l'interruption
void init_interrupt(void){
	INTCON1bits.NSTDIS=0;          // Autorisation des nested interruptions
	INTCON2bits.ALTIVT=0;          // standard vector table
}


