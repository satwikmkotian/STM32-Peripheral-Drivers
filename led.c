#include "led.h"

#define GPIODEN (1U<<3) //0000 0000 0000 0000 0000 0000 0000 1000   // The 3rd bit is set now means D port
#define LED_PIN (1U<<12)



void led_init(void) {
	// Enable Clock here access to the port LED D
	// Register Initial state:    0000 0000 0000 1100 0000 0000 0000 0000
	// set bit 3 as 0  = (1U<<3)= 0000 0000 0000 0000 0000 0000 0000 1000

	// final state = Initial State OR Set bit0 = 0000 0000 0000 1100 0000 0000 0000 1000
	RCC->AHB1ENR |= GPIODEN;



	// Set the LED pin as the output pin now

	GPIOD->MODER |=  (1U<<24);      // OR is used for SET
	GPIOD->MODER &=  ~(1U<<25);    // AND is used for RESET


}


void led_on(void) {
	// set the LED pin High (PA 12)

	GPIOD->ODR |= LED_PIN;

}


void led_off(void) {
	// Set the LED pin LOW here
	GPIOD->ODR &= LED_PIN;

}
