//STM32CubeIDE Settings
/*
Pinout & Configuration
Pinout View
PC13 --> GPIO Output
*/

//Additional code on top of STM32CubeIDE generated code
/* USER CODE BEGIN 2 */
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, 1); // Turn LED on
    HAL_Delay(500); // Delay for 500 ms

    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, 0); // Turn LED off
    HAL_Delay(500); // Delay for 500 ms
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */

