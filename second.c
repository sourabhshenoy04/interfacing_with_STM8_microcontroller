#define LED GPIOB, GPIO_PIN_5 // onboard LED
#include "STM8S.h"

void delay(int ms) // Function Definition
{
    int i = 0;
    int j = 0;
    for (i = 0; i <= ms; i++)
        for (j = 0; j < 120; j++)
            ;
}
main()
{
    GPIO_DeInit(GPIOA); // prepare Port A for working
    GPIO_DeInit(GPIOB); // prepare Port B for working

    // Declare PA2  as input pull up pin
    GPIO_Init(GPIOA, GPIO_PIN_2, GPIO_MODE_IN_PU_IT);

    // Declare PB5 as push pull Output pin
    GPIO_Init(GPIOB, GPIO_PIN_5, GPIO_MODE_OUT_PP_LOW_SLOW); // onboard led

    while (1)
    {
        if (GPIO_ReadInputPin(GPIOA, GPIO_PIN_2)) // if button pressed
            GPIO_WriteHigh(LED);                  // LED ON
        else
            GPIO_WriteLow(LED); // LED OFF
        delay(100);
    }
}
