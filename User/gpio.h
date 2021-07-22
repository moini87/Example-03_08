#ifndef __GPIO_H
#define __GPIO_H

#ifdef __cplusplus
extern "C" {
#endif

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
  uint32_t       pin;
  GPIO_Mode_t    mode;
  GPIO_OType_t   oType;
  GPIO_OSpeed_t  OSpeed;
  GPIO_PuPd_t    puPd;
} GPIO_InitStruct;

void GPIO_WritePin(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin, uint8_t value);
void GPIO_SetPin(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin);
void GPIO_ResetPin(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin);
void GPIO_Init1(GPIO_TypeDef *GPIOx, uint32_t pin, GPIO_Mode_t mode, GPIO_OType_t oType, GPIO_OSpeed_t oSpeed, GPIO_PuPd_t puPd);
void GPIO_Init2(GPIO_TypeDef *GPIOx, GPIO_InitStruct *initStruct);

#ifdef __cplusplus
}
#endif

#endif
