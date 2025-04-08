#include "PE4302.H"

void PE_GPIO_Init(void)
{
    GPIO_InitTypeDef GPIO_Initure;
    
    __HAL_RCC_GPIOB_CLK_ENABLE();   //使能GPIOB时钟
    
    GPIO_Initure.Pin=GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5;
    GPIO_Initure.Mode=GPIO_MODE_OUTPUT_PP;  //推挽输出
    GPIO_Initure.Pull=GPIO_PULLUP;          //上拉
    GPIO_Initure.Speed=GPIO_SPEED_HIGH;     //快速
    HAL_GPIO_Init(GPIOB,&GPIO_Initure);
	
	__HAL_RCC_GPIOA_CLK_ENABLE();   //使能GPIOB时钟	
    GPIO_Initure.Pin=GPIO_PIN_10;
    GPIO_Initure.Mode=GPIO_MODE_OUTPUT_PP;  //推挽输出
    GPIO_Initure.Pull=GPIO_PULLUP;          //上拉
    GPIO_Initure.Speed=GPIO_SPEED_HIGH;     //快速
    HAL_GPIO_Init(GPIOA,&GPIO_Initure);	
}


void PE4302_0_Set(unsigned char db)
{
  unsigned char i;
  unsigned char W_DB;
  db = db&0X3F;
	
	PE_LE_1_DIS;
	delay_us(500);
  PE_CLK_0;
	delay_us(500);
  PE_LE_0_EN;
	delay_us(500);
  for(i = 0; i < 6;i++)
  {
    W_DB = (db>>5);
    if(W_DB == 1)
    {
      PE_DAT_1;
    }
    else
    {
      PE_DAT_0;
    }
		delay_us(500);
    PE_CLK_1;
		delay_us(500);
    db = (db << 1)&0X3F;
    PE_CLK_0;
		delay_us(500);
  }
  PE_LE_0_DIS;
	delay_us(500);
	PE_DAT_0;
}

void PE4302_1_Set(unsigned char db)
{
  unsigned char i;
  unsigned char W_DB;
  db = db&0X3F;
	
	PE_LE_0_DIS;
	delay_us(500);
  PE_CLK_0;
	delay_us(500);
  PE_LE_1_EN;
	delay_us(500);
  for(i = 0; i < 6;i++)
  {
    W_DB = (db>>5);
    if(W_DB == 1)
    {
      PE_DAT_1;
    }
    else
    {
      PE_DAT_0;
    }
		delay_us(500);
    PE_CLK_1;
		delay_us(500);
    db = (db << 1)&0X3F;
    PE_CLK_0;
		delay_us(500);
  }
  PE_LE_1_DIS;
	delay_us(500);
	PE_DAT_0;
}

