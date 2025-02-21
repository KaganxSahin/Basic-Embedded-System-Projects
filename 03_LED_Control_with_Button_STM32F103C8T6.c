// STM32CubeIDE Settings
/*
Click System Core → Click SYS -->
Debug: Serial Wire

Set PA1 to GPIO_Output
Set PB1 to GPIO_Input
*/

//Wiring
/*
- **STM32 Microcontroller**:
  - PA1 pin is connected to the anode (positive leg) of the red LED through a current-limiting resistor (220Ω).
  - GND pin is connected to the cathode (negative leg) of the red LED.
  - PB1 pin is connected to one terminal of the push button through a pull-down resistor (10kΩ).
  - The other terminal of the push button is connected to the GND pin.

- **Push Button**:
  - One terminal is connected to GND.
  - The other terminal is connected to PB1 pin of the STM32 through a pull-down resistor (10kΩ).

- **Red LED**:
  - The anode (long leg) is connected to the PA1 pin of the STM32 through a current-limiting resistor (220Ω).
  - The cathode (short leg) is connected to GND.

### Resistor Values:
- **Current-limiting Resistor for LED**: 220Ω
- **Pull-down Resistor for Push Button**: 10kΩ

These connections allow the push button to control the LED.
*/

// Additional code on top of STM32CubeIDE generated code
/* USER CODE BEGIN WHILE */
while (1)
{
    if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_1) == GPIO_PIN_RESET)
    {
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, 0);
    }
    else
    {
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, 1);
    }
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
}
/* USER CODE END 3 */
