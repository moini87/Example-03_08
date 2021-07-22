#include "main.h"

int main(void)
{
  *(unsigned int *)(0x40023800 + 0x30) |= 0x14; // RCC_AHB1ENR = (1 << 4) | (1 << 2)
  GPIOC->MODER |= 1 << (2 * 13); // GPIOC_MODER
  
  while(1)
  {
    if((GPIOE->IDR & (1 << 4)) == 0) // GPIOE_IDR
      GPIOC->ODR &= ~(unsigned int)(1 << 13); // GPIOC_ODR
    else
      GPIOC->ODR |= (1 << 13); // GPIOC_ODR
  }
}
