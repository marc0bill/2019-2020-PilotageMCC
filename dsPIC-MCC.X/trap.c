/*
Club Robot - Polytech Marseille

repris sur l'exemple de code CE119_I2C_EEPROM (Microchip (TM))

R�vision:     	$Rev: $
Auteur:       	$Author: $
Date r�vision: 	$Date:  $
projet:      	$URL: $

*/
#include "header.h"

void __attribute__((__interrupt__)) _OscillatorFail(void);
void __attribute__((__interrupt__)) _AddressError(void);
void __attribute__((__interrupt__)) _StackError(void);
void __attribute__((__interrupt__)) _MathError(void);
void __attribute__((__interrupt__)) _DMACError(void);

void __attribute__((__interrupt__)) _AltOscillatorFail(void);
void __attribute__((__interrupt__)) _AltAddressError(void);
void __attribute__((__interrupt__)) _AltStackError(void);
void __attribute__((__interrupt__)) _AltMathError(void);
void __attribute__((__interrupt__)) _AltDMACError(void);

/*
Primary Exception Vector handlers:
These routines are used if INTCON2bits.ALTIVT = 0.
All trap service routines in this file simply ensure that device
continuously executes code within the trap service routine. Users
may modify the basic framework provided here to suit to the needs
of their application.
*/
void __attribute__((interrupt, no_auto_psv)) _OscillatorFail(void)
{
        INTCON1bits.OSCFAIL = 0;        //Clear the trap flag
		// allumer une led pour avertir?
        //while (1);		// autre action?
}

void __attribute__((interrupt, no_auto_psv)) _AddressError(void)
{
        INTCON1bits.ADDRERR = 0;        //Clear the trap flag
// allumer une led?
        //while (1);
}
void __attribute__((interrupt, no_auto_psv)) _StackError(void)
{
        INTCON1bits.STKERR = 0;         //Clear the trap flag
// allumer une led?
        //while (1);
}

void __attribute__((interrupt, no_auto_psv)) _MathError(void)
{
        INTCON1bits.MATHERR = 0;        //Clear the trap flag
// allumer une led?
        //while (1);
}

void __attribute__((interrupt, no_auto_psv)) _DMACError(void)
{
        INTCON1bits.DMACERR = 0;        //Clear the trap flag
        //while (1);
}





/*
Alternate Exception Vector handlers:
These routines are used if INTCON2bits.ALTIVT = 1.
All trap service routines in this file simply ensure that device
continuously executes code within the trap service routine. Users
may modify the basic framework provided here to suit to the needs
of their application.
*/

void __attribute__((interrupt, no_auto_psv)) _AltOscillatorFail(void)
{
        INTCON1bits.OSCFAIL = 0;
        //while (1);
}

void __attribute__((interrupt, no_auto_psv)) _AltAddressError(void)
{
        INTCON1bits.ADDRERR = 0;
        //while (1);
}

void __attribute__((interrupt, no_auto_psv)) _AltStackError(void)
{
        INTCON1bits.STKERR = 0;
        //while (1);
}

void __attribute__((interrupt, no_auto_psv)) _AltMathError(void)
{
        INTCON1bits.MATHERR = 0;
        //while (1);
}

void __attribute__((interrupt, no_auto_psv)) _AltDMACError(void)
{
        INTCON1bits.DMACERR = 0;        //Clear the trap flag
        //while (1);
}
