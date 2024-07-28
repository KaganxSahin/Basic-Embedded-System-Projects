//STM32CubeIDE Settings
/*
Click Timer → Click TIM2 →

Clock Source set to Internal Clock

Channel2 set to PWM Generation CH2

Configuration → Parameter Settings →

Prescaler set to 127

Counter Period 625
*/

//Additional code on top of STM32CubeIDE generated code
/* USER CODE BEGIN 2 */
  HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2);
  int x;
/* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {  
    for (x = 0; x <= 625; x++)
    {
        __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, x);
        HAL_Delay(5); 
    }

    for (x = 625; x >= 0; x--)
    {
        __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, x);
        HAL_Delay(5); 
    }
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */

//Wiring
/*
- **STM32 Microcontroller**:
  - The G pin is connected to the negative (ground) rail of the breadboard.
  - The A1 pin is connected to the positive terminal of a current-limiting resistor.
  - The other end of the resistor is connected to the anode (positive terminal) of the LED.
  - The cathode (negative terminal) of the LED is connected to the negative rail of the breadboard.

- **Breadboard Connections**:
  - The negative rail (ground) is connected to the G pin of the STM32.
  - The positive terminal of the current-limiting resistor is connected to the A1 pin of the STM32.
  - The cathode (negative terminal) of the LED is connected to the negative rail (ground) of the breadboard.

Resistor value can be anywhere between 100R - 330R.
*/
