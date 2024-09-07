//STM32CubeIDE Settings
/*
Click System Core → Click SYS -->
Debug: Serial Wire

Click Timer → Click TIM2 →

Clock Source set to Internal Clock

Channel2 set to PWM Generation CH2

Configuration → Parameter Settings →

Prescaler set to 15

Counter Period 9999
*/

//Additional code on top of STM32CubeIDE generated code
 /* USER CODE BEGIN 2 */
  HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    int x;
    for(x=250; x<1250; x=x+1)
    {
      __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_2, x);
      HAL_Delay(3);
    }
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */

//Wiring
/*
- **STM32 Microcontroller**:
  - The `A1` pin is connected to the PWM signal pin of the SG90 Servo Motor.
  - The `5V` pin is connected to the power input of the servo motor.
  - The `G` (GND) pin is connected to the ground terminal of the servo motor.

- **SG90 Servo Motor**:
  - The red wire (`VCC`) is connected to the `5V` pin of the STM32.
  - The brown wire (`GND`) is connected to the `GND` pin of the STM32.
  - The orange wire (`PWM` signal) is connected to the `A1` pin of the STM32.

These connections allow the STM32 to control the angle of the servo motor by generating PWM signals.
*/
