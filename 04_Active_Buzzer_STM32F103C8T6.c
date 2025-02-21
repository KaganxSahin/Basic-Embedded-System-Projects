//STM32CubeIDE Settings
/*
Click System Core → Click SYS -->
Debug: Serial Wire

Click GPIO → Configure GPIO_A → GPIO_PIN_1

Mode set to Output
*/

//Wiring
/*
- **STM32 Microcontroller**:
  - The `A1` pin is connected to the positive terminal of the buzzer.
  - The `G` (GND) pin is connected to the negative terminal of the buzzer.

- **Buzzer**:
  - The positive terminal is connected to the `A1` pin of the STM32.
  - The negative terminal is connected to the `GND` pin of the STM32.

These connections allow the STM32 to control the buzzer by toggling the GPIO pin.
*/

//Additional code on top of STM32CubeIDE generated code
 /* USER CODE BEGIN WHILE */
  while (1)
  {
	  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_1);
	  HAL_Delay(500);
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
