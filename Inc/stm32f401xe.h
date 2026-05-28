/*
 * stm32f401xe.h
 *
 * Created on: 28-May-2026
 * Author: PC
 */

#ifndef STM32F401XE_H_
#define STM32F401XE_H_

#include <stdint.h> // Required for uint32_t

/* Memory Base Addresses */
#define PERIPH_BASE           0x40000000UL
#define AHB1PERIPH_BASE       (PERIPH_BASE + 0x00020000UL)

/* GPIO Base Addresses */
#define GPIOA_BASE            (AHB1PERIPH_BASE + 0x0000UL)
#define GPIOB_BASE            (AHB1PERIPH_BASE + 0x0400UL)

/* GPIO Register Map Structure */
typedef struct {
    volatile uint32_t MODER;    /*!< GPIO port mode register,               Address offset: 0x00 */
    volatile uint32_t OTYPER;   /*!< GPIO port output type register,        Address offset: 0x04 */
    volatile uint32_t OSPEEDR;  /*!< GPIO port output speed register,       Address offset: 0x08 */
    volatile uint32_t PUPDR;    /*!< GPIO port pull-up/pull-down register,  Address offset: 0x0C */
    volatile uint32_t IDR;      /*!< GPIO port input data register,         Address offset: 0x10 */
    volatile uint32_t ODR;      /*!< GPIO port output data register,        Address offset: 0x14 */
    volatile uint32_t BSRR;     /*!< GPIO port bit set/reset register,      Address offset: 0x18 */
    volatile uint32_t LCKR;     /*!< GPIO port configuration lock register, Address offset: 0x1C */
    volatile uint32_t AFR[2];   /*!< GPIO alternate function registers,     Address offset: 0x20-0x24 */
} GPIO_TypeDef;

/* Peripheral Pointers */
#define GPIOA                 ((GPIO_TypeDef *) GPIOA_BASE)
#define GPIOB                 ((GPIO_TypeDef *) GPIOB_BASE)

#endif /* STM32F401XE_H_ */
