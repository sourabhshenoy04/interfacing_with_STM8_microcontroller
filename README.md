# Interfacing with STM8 Microcontroller

## Objectives:
 
1. On-Board LED Blinking
2. On-Board LED with Push Button
3. Interfacing HC-05 with STM8 and controlling LED by passing 1/0 to turn LED ON/OFF
4. Interfacing HC-05 with STM8 and sending “NMAMIT” to the Serial Monitor every 1 Second
5. Interfacing LED with STM8 and changing its Brightness using PWM

## 🛠  Tech Stack

**Hardware:**
- STM8 Microcontroller (STM8S003F3P6)
- ST-Link V2 Board (STM8S103F3P6 Programmer)
- HC-05 Bluetooth Module

**Software/Tools Used:** 
- ST Visual Develop (STVD)
- ST Visual Programmer (STVP)
- Cosmic C Compiler
- Standard Peripheral Library (from GitHub)
- Bluetooth Serial Monitor App (from Google Play Store)

## Explaination of Hardware Components: 
- Arduino UNO:
    - The Arduino Uno is based on the ATmega328P microcontroller and is a popular choice for beginners and experienced makers alike. It features a simple and easy-to-use design, making it suitable for a wide range of projects, from             simple LED blinking exercises to more complex applications like robotics and sensor interfacing.
  - Key Features:
    - ATmega328P Microcontroller: The heart of the Arduino Uno, responsible for executing the program and controlling connected devices.
    - Digital and Analog I/O Pins: Provides a variety of pins for interfacing with sensors, actuators, and other electronic components.
    - USB Interface: Allows easy programming and communication with a computer.
    - Open-Source Platform: Arduino Uno is based on an open-source platform, enabling a large community of developers and enthusiasts to contribute to its growth and share knowledge.
    ![App Screenshot](./assets/output/arduino_uno.jpg)
- TFT Display:
  - The 2.4 Inch Touch Screen TFT Display Shield is a compact and user-friendly display module designed to seamlessly integrate with the Arduino Uno. Equipped with a touch-sensitive screen, this shield enhances the user interface possibilities for Arduino projects.

   - Key Features:
        - 2.4-Inch TFT LCD Display: Offers vibrant and clear visual output for text and graphics.
        - Touch Screen Interface: Allows user interaction through touch, opening up possibilities for interactive applications.
        - Arduino Uno Compatibility: Designed specifically for use with the Arduino Uno microcontroller board.
        - Easy to Use: The shield format simplifies the connection and integration process, making it accessible for both beginners and experienced developers.
  
    ![App Screenshot](./assets/output/tftdisplay1.jpg)

    ![App Screenshot](./assets/output/tftdisplay2.jpg)


## Working of code:
1. **On-Board LED Blinking:** 
- #define LED GPIOB, GPIO_PIN_5: This line creates a macro named "LED" that represents GPIOB (Port B) and pin 5 on that port.

- #include "STM8S.h": This line includes a header file necessary for working with the STM8S microcontroller. It likely contains definitions and configurations specific to the STM8S.

- void delay(int ms): This function takes an integer argument ms (milliseconds) and creates a simple delay function using nested loops. The delay is created by iterating ms times, with an inner loop that runs 120 times.

- void main(): This is the main function that serves as the entry point for the program.

- GPIO_DeInit(GPIOB): This line initializes or resets the GPIO (General Purpose Input/Output) Port B for use.

- GPIO_Init(LED, GPIO_MODE_OUT_PP_LOW_SLOW): This line configures the pin specified by the "LED" macro as a push-pull output with low level (LED is active low) and slow speed.

- while (1) { ... }: This creates an infinite loop that toggles the state of the LED (turns it on or off) using GPIO_WriteReverse(LED) and then introduces a delay of 500 milliseconds using the delay(500) function.

- ***Output:***

  ![App Screenshot](./assets/output/helloworld.jpg)
  
2. **On-Board LED with Push Button**
- #define LED GPIOB,GPIO_PIN_5 //onboard LED: This line creates a macro named "LED" representing Port B and pin 5, which is typically connected to an onboard LED.

- #include "STM8S.h": This line includes a header file needed for working with the STM8S microcontroller.

- void delay (int ms): This line declares a function named delay that takes an integer argument ms (milliseconds) and creates a delay using nested loops.

- GPIO_DeInit(GPIOA); and GPIO_DeInit(GPIOB);: These lines reset or initialize Port A and Port B for use.

- GPIO_Init (GPIOA, GPIO_PIN_2, GPIO_MODE_IN_PU_IT);: This line configures pin 2 on Port A as an input with a pull-up resistor and interrupt capability.

- GPIO_Init (GPIOB, GPIO_PIN_5, GPIO_MODE_OUT_PP_LOW_SLOW);//onboard led: This line configures pin 5 on Port B as a push-pull output with low level (onboard LED is active low) and slow speed.

- while (1) { ... }: This creates an infinite loop that checks the state of pin 2 on Port A. If the button connected to this pin is pressed (GPIO_ReadInputPin(GPIOA, GPIO_PIN_2) is true), it turns on the LED (GPIO_WriteHigh(LED)); otherwise, it turns off the LED (GPIO_WriteLow(LED)).

- delay (100);: After checking the button state and updating the LED, the program introduces a delay of 100 milliseconds.

- ***Output:***

  ![App Screenshot](./assets/output/colorfulhelloworld.png)
  
3. **Interfacing HC-05 with STM8 and controlling LED by passing 1/0 to turn LED ON/OFF:**
- #include "stm8s.h": This line includes the necessary header file for STM8S microcontroller programming.

- #define LED GPIOB,GPIO_PIN_5 //onboard LED: This line creates a macro named "LED" representing Port B and pin 5, which is likely connected to an onboard LED.

- void UART_Config(void);: This is a function prototype declaration for a function named UART_Config that will configure the UART (Universal Asynchronous Receiver/Transmitter).

- void main(void) { ... }: This is the main function, the entry point of the program.

- UART_Config();: This line calls the function UART_Config() to initialize and configure the UART.

- GPIO_DeInit(GPIOB);: This line resets or initializes Port B for use.

- GPIO_Init (GPIOB, GPIO_PIN_5, GPIO_MODE_OUT_PP_HIGH_FAST);: This line configures pin 5 on Port B as a push-pull output with high level (onboard LED is active high) and fast speed.

- The while (1) loop: This is an infinite loop that continually checks if data is received on the UART. If data is received, it reads the received data and checks if it is '0' or '1'. If '0' is received, it turns on the LED; if '1' is received, it turns off the LED.

- void UART_Config(void) { ... }: This is the function definition for configuring the UART. It uses the UART1 module, initializes it with a baud rate of 9600, 8 data bits, 1 stop bit, and no parity. It also enables the UART receive interrupt and enables the UART1 module.

- ***Output:***

  ![App Screenshot](./assets/output/colorfulstrips.jpg)
  
4. **Interfacing HC-05 with STM8 and sending “NMAMIT” to the Serial Monitor every 1 second**
- #include "stm8s.h": Includes the necessary header file for STM8S microcontroller programming.

- #include <string.h>: Includes the standard C library for string manipulation.

- #define LED GPIOB, GPIO_PIN_5 // onboard LED: Macro definition for the onboard LED on Port B, Pin 5.

- Function Prototypes:

    - void UART_Config(void);: Function prototype for configuring UART communication.
    - void sendTextToBluetooth(const char *text);: Function prototype for sending text through UART.
- void delay(int ms): Definition of a simple delay function using nested loops.
- void main(void) { ... }: The main function, the entry point of the program.

- GPIO_DeInit(GPIOB);: Resets or initializes Port B for use.

- GPIO_Init(GPIOB, GPIO_PIN_5, GPIO_MODE_OUT_PP_HIGH_FAST);: Configures Pin 5 on Port B as a push-pull output with high level (active high) and fast speed.

- UART_Config();: Calls the function to configure UART communication.

- The while (1) loop:

    - Turns on the LED by setting the GPIO pin low (GPIO_WriteLow(LED)).
    - Sends the text "NMAMIT!\r\n" to the Bluetooth terminal using sendTextToBluetooth.
    - Introduces a delay of 1000 milliseconds.
    - Turns off the LED by setting the GPIO pin high (GPIO_WriteHigh(LED)).
    - Introduces another delay of 1000 milliseconds.
- void UART_Config(void) { ... }: Function definition for configuring UART1 with a baud rate of 9600, 8 data bits, 1 stop bit, and no parity. It enables the UART1 module.

- void sendTextToBluetooth(const char *text) { ... }: Function definition to send text through UART. It iterates through each character in the input text, waits until the UART is ready to transmit, sends the character, and waits for the transmission to complete.
- ***Output:***

  ![App Screenshot](./assets/output/smallheartpixel.jpg)
  
5. **Interfacing LED with STM8 and changing its Brightness using PWM:** 
- #include "STM8S.h": This line includes the necessary header file for STM8S microcontroller programming.

- signed int pwm_duty = 0;: Declaration of a signed integer variable pwm_duty to control the PWM duty cycle.

- void delay_ms(int ms): Definition of a simple delay function using nested loops, which causes a delay of ms milliseconds.

- void main(void) { ... }: The main function, the entry point of the program.

- GPIO_DeInit(GPIOD);: Resets or initializes Port D for use.

- TIM2_DeInit();: Resets or initializes Timer 2 for use.

- GPIO_Init(GPIOD, GPIO_PIN_4, GPIO_MODE_OUT_PP_HIGH_FAST);: Configures Pin 4 on Port D as a push-pull output with high level (active high) and fast speed.

- TIM2_OC1Init(TIM2_OCMODE_PWM1, TIM2_OUTPUTSTATE_ENABLE, 1000, TIM2_OCPOLARITY_HIGH);: Initializes Timer 2 Channel 1 for PWM generation. It sets the PWM mode, enables the output, sets the period to 1000, and sets the polarity to high.

- TIM2_TimeBaseInit(TIM2_PRESCALER_1, 500);: Initializes the Time Base Unit of Timer 2. It sets the prescaler to 1 and the period to 500.

- TIM2_Cmd(ENABLE);: Enables Timer 2.

- The main loop:

    - The loop starts with a for loop where pwm_duty increases from 0 to 1000 with a step size of 2. This increases the duty cycle of the PWM signal.
    - TIM2_SetCompare1(pwm_duty);: Sets the compare value for Timer 2 Channel 1, effectively controlling the PWM duty cycle.
    - delay_ms(10);: Introduces a delay of 10 milliseconds.
    - After reaching a duty cycle of 1000, the loop reverses, decreasing the duty cycle until reaching 0.
    - This creates a fading effect on the LED connected to Pin 4 of Port D.

- ***Output:***

  ![App Screenshot](./assets/output/boxpixel.jpg)
  
  
## Steps in  :

1. Open the Arduino IDE Software.


2. Click on File > New Sketch

  ![App Screenshot](./assets/steps/first.png)

3. New window of code editor opens
   
  ![App Screenshot](./assets/steps/second.png)

4. Write the required code in the Code Editor

5. Select the Board according to the specification (Arduino UNO here) COM Port varies from PC to PC.
 
  ![App Screenshot](./assets/steps/third.png)

6. To verify this, head towards Device Manager in PC -> USB Controllers. Check the port number.
     
  ![App Screenshot](./assets/steps/fourth.png)

7. After writing the code click on 'Tick mark' to compile the code.
    
  ![App Screenshot](./assets/steps/fifth.png)

8. This is the final step and click on the right arrow mark to dump the code on the device.
   
  ![App Screenshot](./assets/steps/sixth.png)
