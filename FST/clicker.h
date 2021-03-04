#include "stm32f0xx_ll_rcc.h"
#include "stm32f0xx_ll_system.h"
#include "stm32f0xx_ll_bus.h"
#include "stm32f0xx_ll_gpio.h"

void delay( void );

void delay10( void );

void gpio_config( void );

uint16_t show_digit( uint32_t digit );

uint16_t get_hell_sym( uint8_t sym );

void show_hell( uint32_t cnt );

void show_number( uint32_t num );

void noise_cl( void );

void no_noise_cl( void );

void show_word( void );