#define F_CPU 16000000
#define LED PC7
#include <avr/io.h>
#include <util/delay.h>
void initPWM(void) {
	DDRB |= (1<<PB5);
	// Configure Timer1 in Fast PWM mode with ICR1 as TOP
	TCCR1A |= (1<<COM1A1) | (1<<WGM11); // bits: WGM11 | COM1A1;
	TCCR1B |= (1<<WGM12) | (1<<WGM13); // bits: WGM12 | WGM13
	// Set prescaler to '8' bit: CS11
	TCCR1B |= (1<<CS11);
	ICR1 = 19999; // Setting the TOP value for generating PWM signal at a specific frequency
}
void setPWM(uint16_t duty) {
	if (duty > 19999) {
		duty = 19999; // If the value of 'duty' is greater than maximum, set it to maximum
	}
	OCR1A = duty; // Setting the PWM duty cycle
}

int main(void) {
	initPWM(); // Initialize PWM
	while (1) {
		// Brightening
		for (uint16_t i = 0 ; i < 10000; i += 20) {
			setPWM(i);
			_delay_ms(1); // Short delay
		}
		// Dimming
		for (uint16_t i = 10000; i > 0; i -= 20) {
			setPWM(i);
			_delay_ms(1); // Short delay
		}
	}
	return 0;
}