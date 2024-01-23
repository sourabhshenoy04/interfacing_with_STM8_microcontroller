#include "stm8s.h"
#define LED GPIOB, GPIO_PIN_5 // onboard LED
// Function prototypes
void UART_Config(void);

void main(void)
{
    // Initialize the GPIO and UART
    UART_Config();
    GPIO_DeInit(GPIOB);
    GPIO_Init(GPIOB, GPIO_PIN_5, GPIO_MODE_OUT_PP_HIGH_FAST);

    while (1)
    {
        // Check if data is received
        if (UART1_GetFlagStatus(UART1_FLAG_RXNE))
        {
            // Read the received data
            uint8_t receivedData = UART1_ReceiveData8();

            // Check the received data
            if (receivedData == '0')
            {
                // Turn on the LED
                GPIO_WriteHigh(LED);
            }
            else if (receivedData == '1')
            {
                // Turn off the LED
                GPIO_WriteLow(LED);
            }
        }
    }
}

// Configure UART for communication with HC-05
void UART_Config(void)
{
    UART1_DeInit();

    // Configure UART1
    UART1_Init(9600,
               UART1_WORDLENGTH_8D,
               UART1_STOPBITS_1,
               UART1_PARITY_NO,
               UART1_SYNCMODE_CLOCK_DISABLE,
               UART1_MODE_TXRX_ENABLE);

    // Enable UART1 receive interrupt
    UART1_ITConfig(UART1_IT_RXNE, ENABLE);

    // Enable UART1
    UART1_Cmd(ENABLE);
}
