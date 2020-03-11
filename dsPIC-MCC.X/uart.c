#include "header.h"	// processor, constantes,
#include "uart.h"

/* variables globales */
char U1Tx_string[25] = "ProjetUart1\n";


void initUART1(unsigned long baudrate) {
    U1BRG = FCY/(baudrate<<2)-1;
    
	U1MODEbits.UARTEN=1; //Enable UART 1
    U1MODEbits.BRGH=1;
    
    // Transmission
    U1MODEbits.PDSEL=0x00; //8bits, no parity
    U1STAbits.UTXEN=1; //Enable transmission
    
    // Interruption
    IEC0bits.U1TXIE=1;
    IPC3bits.U1TXIP
    
    'A';
    
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