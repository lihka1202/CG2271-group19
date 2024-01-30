#include "MKL25Z4.h"
unsigned int counter = 0;

// Main function

int main(void) {
	SystemCoreClockUpdate();
	while(1) {
		counter+=1;
		if(counter > 0x0F) {
			counter = 0;
		}
	}
}
