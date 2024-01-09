#include <avr/io.h>
#include <util/delay.h>

#define F_CPU 16000000
#define LED PC7
void initPWM(void) {
	DDRB |= (1<<LED) ;
	// Configure Timer1 in Fast PWM mode with ICR1 as TOP
	TCCR1A |= (1<<COM1A1) | (1<<WGM11); // bits: WGM11 | COM1A1;
	TCCR1B |= (1<<WGM12) | (1<<WGM13); // bits: WGM12 | WGM13
	// Set prescaler to '8' bit: CS11
	TCCR1B |= (1<<CS11);
	ICR1 = 19999; // Setting the TOP value for generating PWM signal at a specific frequency
	// Setting the PWM duty cycle
	OCR1A = 9999 ; //
}
int main(void) {
	initPWM(); // Initialize PWM
	while (1) {
		// Main program loop - in this case empty, as PWM is generated in hardware
	}
	return 0;
}