#ifndef __MAIN_H
#define __MAIN_H

typedef struct
{
  volatile unsigned int MODER;
  volatile unsigned int OTYPER;
  volatile unsigned int OSPEEDER;
  volatile unsigned int PUPDR;
  volatile unsigned int IDR;
  volatile unsigned int ODR;
  volatile unsigned int BSRR;
  volatile unsigned int LCKR;
  volatile unsigned int AFRL;
  volatile unsigned int AFRH;
} GPIO_t;
#define GPIOC  ((GPIO_t *)0x40020800)
#define GPIOE  ((GPIO_t *)0x40021000)

#endif
