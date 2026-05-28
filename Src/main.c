#include "stm32f401xe.h"

// Define RCC base address (needed to enable the GPIO clock)
#define RCC_BASE              0x40023800UL
#define RCC_AHB1ENR           (*(volatile uint32_t *)(RCC_BASE + 0x30))

int main(void)
{
    /* 1. Enable Clock for GPIOA (Bit 0 of AHB1ENR) */
    RCC_AHB1ENR |= (1 << 0);

    /* 2. Configure PA5 as Output (Set bits 11:10 to 01 in MODER) */
    // Clear bits 11:10 first
    GPIOA->MODER &= ~(3 << 10);
    // Set bits 11:10 to 01
    GPIOA->MODER |= (1 << 10);

    /* 3. Infinite loop to toggle PA5 */
    while(1)
    {
        GPIOA->ODR ^= (1 << 5); // Toggle PA5

        // Simple delay loop
        for(int i = 0; i < 500000; i++);
    }
}
