#ifndef _PE4302_H_
#define _PE4302_H_

#include "main.h"
#include "delay.h"

#define DB_0    ((u8)0X00)
#define DB_0_5  ((u8)0X01)
#define DB_1    ((u8)0X02)
#define DB_2    ((u8)0X04)
#define DB_4    ((u8)0X08)
#define DB_8    ((u8)0X10)
#define DB_16   ((u8)0X20)
#define DB_31_5 ((u8)0X3F)

#define PE_LE_0_EN      HAL_GPIO_WritePin(GPIOB,GPIO_PIN_3 , GPIO_PIN_SET)
#define PE_LE_1_EN      HAL_GPIO_WritePin(GPIOA,GPIO_PIN_10, GPIO_PIN_SET)

#define PE_LE_0_DIS     HAL_GPIO_WritePin(GPIOB,GPIO_PIN_3 , GPIO_PIN_RESET)
#define PE_LE_1_DIS     HAL_GPIO_WritePin(GPIOA,GPIO_PIN_10, GPIO_PIN_RESET)

#define PE_CLK_0        HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5 , GPIO_PIN_RESET)
#define PE_CLK_1        HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5 , GPIO_PIN_SET)

#define PE_DAT_0        HAL_GPIO_WritePin(GPIOB,GPIO_PIN_4 , GPIO_PIN_RESET)
#define PE_DAT_1        HAL_GPIO_WritePin(GPIOB,GPIO_PIN_4 , GPIO_PIN_SET)

void PE_GPIO_Init(void);
void PE4302_0_Set(unsigned char db);
void PE4302_1_Set(unsigned char db);
#endif
