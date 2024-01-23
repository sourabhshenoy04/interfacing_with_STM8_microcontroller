#include "stm8s.h"
#include <string.h>

#define LED GPIOB, GPIO_PIN_5 // onboard LED

// Function prototypes
void UART_Config(void);
void sendTextToBluetooth(const char *text);

void delay(int ms) // Function Definition
{
    int i = 0;
    int j = 0;
    for (i = 0; i <= ms; i++)
        for (j = 0; j < 120; j++)
            ;
}

void main(void)
{
    // Initialize the GPIO and UART
    GPIO_DeInit(GPIOB);
    GPIO_Init(GPIOB, GPIO_PIN_5, GPIO_MODE_OUT_PP_HIGH_FAST);
    UART_Config();

    while (1)
    {

        // Turn on the LED
        GPIO_WriteLow(LED);

        // Send text to Bluetooth terminal
        sendTextToBluetooth("NMAMIT!\r\n");

        delay(1000);

        // Turn off the LED
        GPIO_WriteHigh(LED);
        delay(1000);
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

    // Enable UART1
    UART1_Cmd(ENABLE);
}

// Function to send text through UART
void sendTextToBluetooth(const char *text)
{
    while (*text)
    {
        // Wait until the UART is ready to transmit
        while (!UART1_GetFlagStatus(UART1_FLAG_TXE))
            ;

        // Send the character
        UART1_SendData8(*text++);

        // Wait for the transmission to complete
        while (!UART1_GetFlagStatus(UART1_FLAG_TC))
            ;
    }
}
