#include "stm32f4xx.h"

int main(void)
{
  RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN | RCC_AHB1ENR_GPIOEEN;//0x14
  GPIOC->MODER |= GPIO_MODER_MODER13_0;//1 << (2 * 13)
  
  while(1)
  {
    if((GPIOE->IDR & GPIO_IDR_ID4) == 0)
      GPIOC->ODR &= ~GPIO_ODR_OD13;
    else
      GPIOC->ODR |= GPIO_ODR_OD13;
  }
}
