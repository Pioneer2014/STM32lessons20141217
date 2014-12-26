
#define     __IO    volatile             
typedef unsigned           int uint32_t;
typedef __IO uint32_t  vu32; 
typedef unsigned short     int uint16_t;
//i love GitHub.
#define GPIO_Pin_0                 ((uint16_t)0x0001)  /*!< Pin 0 selected */
#define GPIO_Pin_1                 ((uint16_t)0x0002)  /*!< Pin 1 selected */
#define GPIO_Pin_2                 ((uint16_t)0x0004)  /*!< Pin 2 selected */
#define GPIO_Pin_3                 ((uint16_t)0x0008)  /*!< Pin 3 selected */
#define GPIO_Pin_4                 ((uint16_t)0x0010)  /*!< Pin 4 selected */
#define GPIO_Pin_5                 ((uint16_t)0x0020)  /*!< Pin 5 selected */
#define GPIO_Pin_6                 ((uint16_t)0x0040)  /*!< Pin 6 selected */
#define GPIO_Pin_7                 ((uint16_t)0x0080)  /*!< Pin 7 selected */
#define GPIO_Pin_8                 ((uint16_t)0x0100)  /*!< Pin 8 selected */
#define GPIO_Pin_9                 ((uint16_t)0x0200)  /*!< Pin 9 selected */
#define GPIO_Pin_10                ((uint16_t)0x0400)  /*!< Pin 10 selected */
#define GPIO_Pin_11                ((uint16_t)0x0800)  /*!< Pin 11 selected */
#define GPIO_Pin_12                ((uint16_t)0x1000)  /*!< Pin 12 selected */
#define GPIO_Pin_13                ((uint16_t)0x2000)  /*!< Pin 13 selected */
#define GPIO_Pin_14                ((uint16_t)0x4000)  /*!< Pin 14 selected */
#define GPIO_Pin_15                ((uint16_t)0x8000)  /*!< Pin 15 selected */
#define GPIO_Pin_All               ((uint16_t)0xFFFF)  /*!< All pins selected */

#define RCC_APB2Periph_AFIO              ((uint32_t)0x00000001)
#define RCC_APB2Periph_GPIOA             ((uint32_t)0x00000004)
#define RCC_APB2Periph_GPIOB             ((uint32_t)0x00000008)
#define RCC_APB2Periph_GPIOC             ((uint32_t)0x00000010)
#define RCC_APB2Periph_GPIOD             ((uint32_t)0x00000020)

/************ GPIOD <*************/
typedef struct
{
  __IO uint32_t CRL;
  __IO uint32_t CRH;
  __IO uint32_t IDR;
  __IO uint32_t ODR;
  __IO uint32_t BSRR;
  __IO uint32_t BRR;
  __IO uint32_t LCKR;
} GPIO_TypeDef;

typedef struct
{
  __IO uint32_t CR;
  __IO uint32_t CFGR;
  __IO uint32_t CIR;
  __IO uint32_t APB2RSTR;
  __IO uint32_t APB1RSTR;
  __IO uint32_t AHBENR;
  __IO uint32_t APB2ENR;
  __IO uint32_t APB1ENR;
  __IO uint32_t BDCR;
  __IO uint32_t CSR;
} RCC_TypeDef;

/********* GPIOD管脚的内存对应地址 *******/
#define PERIPH_BASE           ((uint32_t)0x40000000) 
#define APB2PERIPH_BASE       (PERIPH_BASE + 0x10000)
#define GPIOD_BASE            (APB2PERIPH_BASE + 0x1400)
#define GPIOD               ((GPIO_TypeDef *) GPIOD_BASE)

/************ RCC时钟 <*************/
#define AHBPERIPH_BASE        (PERIPH_BASE + 0x20000)
#define RCC_BASE              (AHBPERIPH_BASE + 0x1000)
#define RCC                 ((RCC_TypeDef *) RCC_BASE)

void Delay(vu32 nCount);
/************ www.armjishu.com *******/
int main(void)	 //main?????
{
  	/* ??APB2?????,?GPIO???D???? */
  	RCC->APB2ENR |= RCC_APB2Periph_GPIOD;	

	/*-- GPIO Mode Configuration??,????? -----------------------*/
	/*-- GPIO CRL Configuration ??IO???8????(??????)---*/
	/*-- GPIO CRH Configuration ??IO???8????(??????)---*/
	GPIOD->CRL &=  0xFFFFF0FF;
	GPIOD->CRL |=  0x00000300;

  	while (1)
  	{	
  		GPIOD->BRR = GPIO_Pin_2; 
		  Delay(0x2FFFFF);
		  GPIOD->BSRR = GPIO_Pin_2;
    	Delay(0x2FFFFF);
  	}
}

void Delay(vu32 nCount)		 //通过不断for循环nCount次，达到延时的目的口
{
  for(; nCount != 0; nCount--);
}
