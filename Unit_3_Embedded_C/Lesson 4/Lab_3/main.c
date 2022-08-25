#define SET_BIT(reg,n)  (reg |= (1<<n))
#define CLR_BIT(reg,n)  (reg &= ~(1<<n))


#define SYSCTL_RCGC2_R_BASE 0x400FE000
#define GPIO_BASE           0x40025000

#define SYSCTL_RCGC2_R *((volatile unsigned long*)(SYSCTL_RCGC2_R_BASE + 0x108))
#define GPIO_PORTF_DATA_R *((volatile unsigned long*)(GPIO_BASE + 0x3FC))
#define GPIO_PORTF_DIR_R *((volatile unsigned long*)(GPIO_BASE + 0x400))
#define GPIO_PORTF_DEN_R *((volatile unsigned long*)(GPIO_BASE + 0x51C))

void DELAY(unsigned long delay_c);

int main()
{
    volatile unsigned long delay_c ;
    SYSCTL_RCGC2_R = 0x00000020 ;
    DELAY(200);
    SET_BIT(GPIO_PORTF_DIR_R,3);
    SET_BIT(GPIO_PORTF_DEN_R,3);

    while(1)
    {
        SET_BIT(GPIO_PORTF_DATA_R,3);
        DELAY(20000);
        CLR_BIT(GPIO_PORTF_DATA_R,3);
        DELAY(20000);
    }
    return 0 ;
}

void DELAY(unsigned long delay_c)
{
   for(delay_c=0;delay_c<delay_c;delay_c++);
}
