#include <avr/io.h>
#include <avr/interrupt.h>

#define LED PC7
#define F_CPU 16000000
#define BLINK_FREQ 4 // We can change this value to change the frequency of the blinking

void Timer1_Init(void) {
	TCCR1B |= (1 << CS10) | (1 << CS12) | (1 << WGM12); // Set prescaler to 1024
	OCR1A = (F_CPU / (2 * BLINK_FREQ * 1024)) - 1; // Set the compare value
	TIMSK1 |= (1 << OCIE1A); // Enable interrupt on compare match A
}

ISR(TIMER1_COMPA_vect) {
	PORTC ^= (1 << LED); // Toggle the LED
}

int main(void) {
	DDRC |= (1 << LED); // Set LED pin as output
	Timer1_Init(); // Initialize Timer 1
	sei(); // Enable global interrupts
	
	while (1) {} // Empty loop to wait for interrupts
}