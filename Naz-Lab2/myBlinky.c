#include "MKL25Z4.h"                    // Device header
#define RED_LED			18	// PortB Pin 18
#define GREEN_LED		19	// PortB Pin 19
#define BLUE_LED		1		// PortD Pin 1
#define MASK(x)			(1 << (x))

unsigned int counter = 0;

enum color_t {
	RED,
	GREEN,
	BLUE
};

static void delay(volatile uint32_t nof) {
	while(nof!=0) {
		__ASM("NOP");
		nof--;
	}
}

void blinkLed(int LED)
{
	if (LED == RED_LED || LED == GREEN_LED)
	{
		PTB->PDOR &= ~MASK(LED);
	}
	else
	{
		PTD->PDOR &= ~MASK(LED);
	}
	
	delay(0xF0000);
	
	if (LED == RED_LED || LED == GREEN_LED)
	{
		PTB->PDOR |= MASK(LED);
	}
	else
	{
		PTD->PDOR |= MASK(LED);
	}
}

void led_control(enum color_t color)
{
	switch (color) {
		case RED:
			blinkLed(RED_LED);
			break;
		
		case GREEN:
			blinkLed(GREEN_LED);
			break;
		
		case BLUE:
			blinkLed(BLUE_LED);
			break;
	}
}

void InitGPIO(void)
{
	// Enable Clock to PORTB and PORTD
	SIM->SCGC5 |= ((SIM_SCGC5_PORTB_MASK) | (SIM_SCGC5_PORTD_MASK));
	
	// Configure MUX settings to make all 3 pins GPIO
	
	PORTB->PCR[RED_LED] &= ~PORT_PCR_MUX_MASK;
	PORTB->PCR[RED_LED] |= PORT_PCR_MUX(1);
	
	PORTB->PCR[GREEN_LED] &= ~PORT_PCR_MUX_MASK;
	PORTB->PCR[GREEN_LED] |= PORT_PCR_MUX(1);
	
	PORTB->PCR[BLUE_LED] &= ~PORT_PCR_MUX_MASK;
	PORTB->PCR[BLUE_LED] |= PORT_PCR_MUX(1);
	
	// Set Data Direction Registers for PortB and PortD
	PTB->PDDR |= (MASK(RED_LED) | MASK(GREEN_LED));
	PTD->PDDR |= MASK(BLUE_LED);
}

/* MAIN function */

int main(void)
{
	SystemCoreClockUpdate();
	InitGPIO();
	
	int color_num;	
	while(1)
	{
		counter++;
		if (counter > 0x0F)
		{
			counter = 0;
		}
		
		color_num = counter % 3;
		
		switch (color_num) {
			case 0:
				led_control(RED);
				break;
			
			case 1:
				led_control(GREEN);
				break;
			
			case 2:
				led_control(BLUE);
				break;
		}
	}
}