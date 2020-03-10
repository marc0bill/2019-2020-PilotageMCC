#ifndef _HEADER_H_
#define _HEADER_H_


 #ifdef __dsPIC33FJ128MC802__
#include <p33fj128mc802.h>
#endif
#ifdef __dsPIC33FJ128MC804__
#include <p33fj128mc804.h>
#endif


#include <libpic30.h>


#define FQUARTZ     4000000	// 4 MHz
#define PLL_N1      0	// 2 	(0.8M<FQuartz/N1<8M)
#define PLL_M       78	// 80 	(100M<FQuartz/N1*M<200M)		//  todo voir si MUL_40 définit dans .h
#define PLL_N2      0	// 2	(12.5M<FQuartz*M/(N1*N2)<80M)
				// FOSC=80MHz
				// FCY=40MHz
#define FTYPE       0b011 // Primary oscillator (XT, HS, EC) with PLL (NOSC=0b011)
#define FOSC        (FQUARTZ/(2*2))*80	//(FQUARTZ/(N1*N2))*M
#define FCY         FOSC/2
#define COEFF_PR1   2   // coeff correctif Timer1 pour interrupt tous les 1ms
                        // 1 pour PLL_M=38, soit FCY=20MHz
                        // 2 pour PLL_M=78, soit FCY=40MHz

// broche "sens Moteur 1"
#define	SENS_M1		PORTBbits.RB14		// PORT
//#define	SENS_M1		LATBbits.LATB14
#define T_SENS_M1	TRISBbits.TRISB14	// direction du port
// broche "sens Moteur 2"
#define	SENS_M2		PORTBbits.RB12		// PORT
//#define	SENS_M2		LATBbits.LATB12
#define T_SENS_M2	TRISBbits.TRISB12	// direction du port
// broche "arret des moteurs 1 et 2"
#define Brake12		PORTBbits.RB11		// PORT
#define T_Brake12	TRISBbits.TRISB11	// direction du port
#define L_Brake12	LATBbits.LATAB11		// Latch du port

#endif
