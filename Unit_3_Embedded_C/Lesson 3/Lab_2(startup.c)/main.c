#define RCC_BASE    0x40021000
#define GPIO_BASE   0x40010800

#define APB2ENR     *((volatile int*)(RCC_BASE  + 0x18))
#define GPIO_RCH    *((volatile int*)(GPIO_BASE + 0x04))
#define GPIO_ODR    *((volatile int*)(GPIO_BASE + 0x0c))

typedef union
{
    volatile int all_ports ;
    struct
    {
        volatile int reversed:13 ;
        volatile int pin13:1 ;
    }pin;
}R_ODR_t;

volatile R_ODR_t* R_ODR =(volatile R_ODR_t *)(GPIO_BASE + 0x0c);

int main()
{
   int i ;
    APB2ENR |= 1<<2 ;
    GPIO_RCH &=0xff0fffff ;
    GPIO_RCH |=0x00200000 ;
    while(1)
    {
        R_ODR->pin.pin13 = 1 ;
        for(i=0 ; i<5000;i++);
        R_ODR->pin.pin13 = 0;
        for(i=0 ; i<5000;i++);
    }
    return 0 ;
}
