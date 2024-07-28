//STM32CubeIDE Settings
/*
Click System Core → Click SYS -->
Debug: Serial Wire

ADC1 - IN9 (tick)

Parameter Settings --> ADC Settings --> Continuous Conversion Mode (Enabled)

Click Timer → Click TIM2 →

Clock Source set to Internal Clock

Channel2 set to PWM Generation CH2

Configuration → Parameter Settings →

Prescaler set to 15

Counter Period 9999
*/

//Additional code on top of STM32CubeIDE generated code
 /* USER CODE BEGIN 2 */
  HAL_ADC_Start(&hadc1);
  HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2);
  uint16_t readValue;
  uint16_t PWM;
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    HAL_ADC_PollForConversion(&hadc1,1000);
    readValue = HAL_ADC_GetValue(&hadc1);
    PWM = 250 + readValue/4.1;
    __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_2, PWM);
    HAL_Delay(50);
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */

//Wiring
/*
- **STM32 Microcontroller**:
  - The `A1` pin is connected to the middle terminal (analog output) of the potentiometer.
  - The `5V` pin is connected to the power input of the servo motor.
  - The `G` (GND) pin is connected to the ground terminals of both the potentiometer and the servo motor.

- **Potentiometer**:
  - One terminal is connected to `GND`, and the other terminal is connected to `3.3V`.
  - The middle terminal is connected to the `A1` pin of the STM32.

- **SG90 Servo Motor**:
  - The red wire (`VCC`) is connected to the `5V` pin of the STM32.
  - The brown wire (`GND`) is connected to the `GND` pin of the STM32.
  - The orange wire (`PWM` signal) is connected to a PWM output pin of the STM32.

These connections allow the potentiometer to control the angle of the servo motor.
*/
