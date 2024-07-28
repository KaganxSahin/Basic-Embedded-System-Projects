//STM32CubeIDE Settings
/*
Click System Core → Click SYS -->
Debug: Serial Wire

Clock Configuration:
- External Crystal (8MHz) is used to provide the clock via the PLL.
- The system is running at 60MHz.
- APB2 Timer clock is at 60MHz.

Click Timer → Click TIM1 → 

Clock Source set to Internal Clock

Channel1 set to PWM Generation CH1

Configuration → Parameter Settings →

Set the Clock source as internal clock, which is at 60 MHz.
*/

//Additional code on top of STM32CubeIDE generated code
 /* USER CODE BEGIN 2 */
  __HAL_TIM_SET_PRESCALER(&htim1, 24);
  HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
  /* USER CODE END 2 */

//Wiring
/*
- **STM32 Microcontroller**:
  - The `PA8` pin is connected to the signal pin of the active buzzer.
  - The `5V` pin is connected to the power input of the active buzzer.
  - The `G` (GND) pin is connected to the ground terminal of the active buzzer.

- **Buzzer**:
  - The `VCC` pin is connected to the `5V` pin of the STM32.
  - The `GND` pin is connected to the `GND` pin of the STM32.
  - The `I/O` pin is connected to the `PA8` pin of the STM32.

These connections allow the STM32 to control the buzzer by generating PWM signals.
*/
