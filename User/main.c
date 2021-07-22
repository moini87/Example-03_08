#include "stm32f4xx.h"
#include "gpio.h"

int main(void)
{
  RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN | RCC_AHB1ENR_GPIOEEN;//0x14
  GPIOC->MODER |= GPIO_MODER_MODER13_0;//1 << (2 * 13)
  
  while(1)
  {
    if((GPIOE->IDR & GPIO_IDR_ID4) == 0)
      GPIO_ResetPin(GPIOC, GPIO_ODR_OD13);
    else
      GPIO_SetPin(GPIOC, GPIO_ODR_OD13);
  }
}
