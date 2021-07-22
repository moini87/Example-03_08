#include "gpio.h"

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
void GPIO_Init1(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin, GPIO_Mode_t mode, GPIO_OType_t oType, GPIO_OSpeed_t oSpeed, GPIO_PuPd_t puPd)
{
  // do something
}
/****************************************/
void GPIO_Init2(GPIO_TypeDef *GPIOx, GPIO_InitStruct *initStruct)
{
  // do something
}
