#define LED PC7
#include <avr/io.h>
#include <util/delay.h>

void Watchdog()
{
	MCUSR &= ~(1<<WDRF); //Initializing the Watchdog in the MCU
	WDTCSR |= (1<<WDCE)|(1<<WDE); //Setting the settings of the Watchdog
	WDTCSR = (1<<WDP0) | (1<<WDP1) | (1<<WDP2) | (1<<WDE); //Setting the Watchdog timing to 2sec
}

int main(void)
{
	Watchdog(); //Setting up the Watchdog
	DDRC |= (1<<LED); //Setting the destination Port of LED
	PORTC |= (1<<LED); //Turning on the LED
	_delay_ms(1000); //Waiting 1 second for the LED to be on
	PORTC &= ~(1<<LED); //Turning off the LED
	while (1) //Loop to wait for the Watchdog to interrupt
	{
	}
}
