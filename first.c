#define LED GPIOB, GPIO_PIN_5
#include "STM8S.h"

void delay(int ms) {
    int i = 0;
    int j = 0;
    for (i = 0; i < ms; i++) {
        for (j = 0; j < 120; j++); 
    }
}

void main() {
    GPIO_DeInit(GPIOB); // prepare Port B for working

    // Declare PA3 as Push Pull Output pin
    GPIO_Init(LED, GPIO_MODE_OUT_PP_LOW_SLOW);

    while (1) {
        GPIO_WriteReverse(LED); // Toggle LED state
        delay(500); // Delay for 500 milliseconds
    }
}
