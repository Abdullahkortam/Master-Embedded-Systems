#include <stdio.h>
typedef volatile unsigned int    vuint32_t;

typedef union
{
	vuint32_t 	ALLPORTS ;
	struct
	{
		vuint32_t reserved:13 ;
		vuint32_t pin13 :1 ;
	}pin;
}R_ODR_t;

#define RCC_BASE     0x40021000
#define GPIO_BASE    0x40010800

#define RCC_APB2ENR  *((vuint32_t *)(RCC_BASE + 0x18))
#define GPIO_RCH     *((vuint32_t *)(GPIO_BASE + 0x04))
#define GPIO_ODR     *((vuint32_t *)(GPIO_BASE +0x0c))

volatile R_ODR_t* R_ODR =(volatile R_ODR_t *)(GPIO_BASE + 0x0c) ;
int main()
{
	vuint32_t  i ;
	RCC_APB2ENR |= (1<<2) ;

	GPIO_RCH &=  0xff0fffff ;
	GPIO_RCH |=  0x00200000 ;
	while(1)
	{
		R_ODR->pin.pin13 = 1;
		for(i=0;i<5000;i++);
		R_ODR->pin.pin13 = 0;
		for(i=0;i<5000;i++);
	}
	return 0;
}
