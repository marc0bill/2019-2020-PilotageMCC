#include "header.h"	// processor, constantes,
#include "uart.h"

/* variables globales */
char U1Tx_string[25] = "ProjetUart1\n";


void initUART1(unsigned long baudrate) {
    U1BRG = FCY/(16 * baudrate)-1;
    
	U1MODEbits.UARTEN=1; // Active l'UART 1
    U1STAbits.UTXEN=1;
    
    // Transmission
    U1MODEbits.PDSEL=0x; // Nb de bits + Parit�
    U1MODEbits.STSEL=0; //Nb de stop
    
    
    
}


/******************************************************************************** 
routine d'interruption sur reception UART1
********************************************************************************/
void __attribute__ ((interrupt, no_auto_psv)) _U1RXInterrupt(void) {	
	IFS0bits.U1RXIF = 0;	// acquittement interruption
}

/******************************************************************************** 
routine d'interruption transmission UART1 (buffer vide)
********************************************************************************/
void __attribute__ ((interrupt, no_auto_psv)) _U1TXInterrupt(void) 
{
	IFS0bits.U1TXIF = 0;	// acquittement
}