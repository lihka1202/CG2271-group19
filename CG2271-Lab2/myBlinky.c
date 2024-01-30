#include "MKL25Z4.h"


#define RED_LED								18
#define GREEN_LED							19
#define BLUE_LED							1
#define MASK(x)								(1 << (x))

void InitGPIO(void) {
	// Enable Clock to PORTB and PORTD
	SIM->SCGC5 |= ((SIM_SCGC5_PORTB_MASK)| (SIM_SCGC5_PORTD_MASK));
	
	// Configure MUX Settings #include "Board_LED.h"  to make all 3 pins GPIO
	
	//! This seems to be clearing the last i bits
	PORTB->PCR[RED_LED] &= ~PORT_PCR_MUX_MASK;
	PORTB->PCR[RED_LED] |= PORT_PCR_MUX(1);
	
	PORTB->PCR[GREEN_LED] &= ~PORT_PCR_MUX_MASK;
	PORTB->PCR[GREEN_LED] |= PORT_PCR_MUX(1);
	
	PORTD->PCR[BLUE_LED] &= ~PORT_PCR_MUX_MASK;
	PORTD->PCR[BLUE_LED] |= PORT_PCR_MUX(1);
	
	// Set the Data Direction Registers for PortB and PortD
	PTB->PDDR |= ( MASK( RED_LED ) | MASK( GREEN_LED ));
	PTD->PDDR |= MASK(BLUE_LED);
	
}
unsigned int counter = 0;

// Main function


int main(void) {
	SystemCoreClockUpdate();
	InitGPIO();
	while(1) {
		counter+=1;
		if(counter > 0x0F) {
			counter = 0;
		}
	}
}
