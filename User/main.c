int main()
{
  *(unsigned int *)(0x40023800 + 0x30) |= 0x14; // RCC_AHB1ENR = (1 << 4) | (1 << 2)
  *(unsigned int *)0x40020800 |= 1 << (2 * 13); // GPIOC_MODER
  
  while(1)
  {
    if((*(unsigned int *)(0x40021000 + 0x10) & (1 << 4)) == 0) // GPIOE_IDR
      *(unsigned int *)(0x40020800 + 0x14) &= ~(unsigned int)(1 << 13); // GPIOC_ODR
    else
      *(unsigned int *)(0x40020800 + 0x14) |= (1 << 13); // GPIOC_ODR
  }
}
