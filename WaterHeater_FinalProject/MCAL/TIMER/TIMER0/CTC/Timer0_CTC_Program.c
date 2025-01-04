/*
 * Timer0_CTC_Program.c
 *
 * Created: 16/12/2024
 * Author: zyade
 */

#include "Timer0_CTC_Interface.h"


void Timer0_CTC_WithInterrupt_Initialize(void)
{
    

    // Configure Timer0 for CTC mode
    TCCR0 = 0;                    // Clear TCCR0 register
    TCCR0 |= (1 << WGM01);        // Enable CTC mode

    // Enable Compare Match interrupt
    TIMSK |= (1 << OCIE0);

    // Set initial value for OCR0
    OCR0 = 155;                   // Compare match value for 100 ms (calculated for 16 MHz with prescaler 1024)

    sei();                        // Enable global interrupts
}

void Timer0_CTC_WithInterrupt_Start(void)
{
    // Set prescaler to 1024 and start Timer0
    TCCR0 |= (1 << CS02) | (1 << CS00);
}

void Timer0_CTC_WithInterrupt_Stop(void)
{
    // Stop Timer0 by clearing prescaler bits
    TCCR0 &= ~((1 << CS02) | (1 << CS01) | (1 << CS00));
}

