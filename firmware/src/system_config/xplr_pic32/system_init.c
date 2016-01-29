/* TODO: Define processor configuration bits */
/* Initialize the System */
/* Processor Configuration bits */
// DEVCFG3
#pragma config FSRSSEL = PRIORITY_7 // SRS Select
#pragma config FUSBIDIO = ON // USB USID Selection
#pragma config FVBUSONIO = ON // USB VBUS ON Selection
// DEVCFG2
#pragma config FPLLIDIV = DIV_2 // PLL Input Divider
#pragma config FPLLMUL = MUL_20 // PLL Multiplier
#pragma config UPLLIDIV = DIV_2 // USB PLL Input Divider
#pragma config UPLLEN = OFF // USB PLL Enable
#pragma config FPLLODIV = DIV_256 // System PLL Output Clock Divider
// DEVCFG1
#pragma config FNOSC = PRIPLL // Oscillator Selection Bits
#pragma config FSOSCEN = OFF // Secondary Oscillator Enable
#pragma config IESO = ON // Internal/External Switch Over
#pragma config POSCMOD = OFF // Primary Oscillator Configuration
#pragma config OSCIOFNC = OFF // CLKO Output Signal Active on the OSCO Pin
#pragma config FPBDIV = DIV_1 // Peripheral Clock Divisor
#pragma config FCKSM = CSDCMD // Clock Switching and Monitor Selection
#pragma config WDTPS = PS1048576 // Watchdog Timer Postscaler (1048576:1)
#pragma config FWDTEN = OFF // Watchdog Timer Enable
// DEVCFG0
#pragma config DEBUG = OFF // Background Debugger Enable
#pragma config ICESEL = ICS_PGx2 // ICE/ICD Communication Channel Select
#pragma config PWP = OFF // Program Flash Write Protect
#pragma config BWP = OFF // Boot Flash Write Protect bit
#pragma config CP = OFF // Code Protect

void SYS_Initialize ( void *data )
{
 /* TODO: Initialize all modules and the application. */
}
