#include "stm32f4xx.h"

typedef enum
{
  GPIO_Mode_IN = 0,
  GPIO_Mode_OUT,
  GPIO_Mode_AF,
  GPIO_Mode_AN
} GPIO_Mode_t;
typedef enum
{
  GPIO_OType_PP = 0,
  GPIO_OType_OD,
} GPIO_OType_t;
typedef enum
{
  GPIO_OSpeed_Low = 0,
  GPIO_OSpeed_Medium,
  GPIO_OSpeed_High,
  GPIO_OSpeed_VeryHigh,
} GPIO_OSpeed_t;
typedef enum
{
  GPIO_PuPd_NoPull = 0,
  GPIO_PuPd_Pu,
  GPIO_PuPd_Pd,
} GPIO_PuPd_t;

typedef struct
{
  uint32_t       GPIO_Pin;
  GPIO_Mode_t    GPIO_Mode;
  GPIO_OType_t   GPIO_OType;
  GPIO_OSpeed_t  OSpeed;
  GPIO_PuPd_t    GPIO_PuPd;
} GPIO_InitStruct;

void GPIO_WritePin(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin, uint8_t value);
void GPIO_SetPin(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin);
void GPIO_ResetPin(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin);
void GPIO_Init1(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin, GPIO_Mode_t GPIO_Mode, GPIO_OType_t GPIO_OType, uint32_t OSpeed, GPIO_PuPd_t GPIO_PuPd);
void GPIO_Init2(GPIO_TypeDef *GPIOx, GPIO_InitStruct *GPIO_initStruct);

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
/****************************************/
void GPIO_WritePin(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin, uint8_t value)
{
  if(value == 1)
    GPIOx->ODR |= GPIO_Pin;
  else
    GPIOx->ODR &= ~GPIO_Pin;
}
/****************************************/
void GPIO_SetPin(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin)
{
  GPIOx->BSRR = GPIO_Pin;
}
/****************************************/
void GPIO_ResetPin(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin)
{
  GPIOx->BSRR = GPIO_Pin << 16;
}
/****************************************/
void GPIO_Init1(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin, GPIO_Mode_t GPIO_Mode, GPIO_OType_t GPIO_OType, uint32_t OSpeed, GPIO_PuPd_t GPIO_PuPd)
{
  // do something
}
/****************************************/
void GPIO_Init2(GPIO_TypeDef *GPIOx, GPIO_InitStruct *GPIO_initStruct)
{
  // do something
}
