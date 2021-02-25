#include "stm32f0xx_ll_rcc.h"
#include "stm32f0xx_ll_system.h"
#include "stm32f0xx_ll_bus.h"
#include "stm32f0xx_ll_gpio.h"

void delay( void )
{
  for (int i = 0; i < 600000; i++);
}

void delay10( void )
{
  for (int i = 0; i < 6000; i++);
}

void gpio_config( void )
{
  LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOA);
  LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOC);
  
  LL_GPIO_SetPinMode(GPIOC, LL_GPIO_PIN_9, LL_GPIO_MODE_OUTPUT);
  LL_GPIO_SetPinMode(GPIOC, LL_GPIO_PIN_8, LL_GPIO_MODE_OUTPUT);
  LL_GPIO_SetPinMode(GPIOC, LL_GPIO_PIN_0, LL_GPIO_MODE_INPUT);
}

int main( void )
{ 
  gpio_config();
  uint32_t counter = 0, is_pressed = 0, is_on = 0;
  
  while (1)
  {
    // 1 - on, 0 - off
    /* Check if button pressed */
    if (LL_GPIO_IsInputPinSet(GPIOA, LL_GPIO_PIN_0))
    {
      is_pressed = 1; 
      counter = 0; /* reset counter */
    }
   
    if (is_pressed)
    {
      counter++;
      delay10();
    }
    
    if (counter >= 5)
    {
      if (is_on)
      {
        LL_GPIO_ResetOutputPin(GPIOC, LL_GPIO_PIN_9);
        LL_GPIO_SetOutputPin(GPIOC, LL_GPIO_PIN_8);
      }
      else
      {
        LL_GPIO_SetOutputPin(GPIOC, LL_GPIO_PIN_9);
        LL_GPIO_ResetOutputPin(GPIOC, LL_GPIO_PIN_8);
      }
      // change state
      is_on = 1 - is_on;
      
      is_pressed = 0;
      counter = 0;
    }
  }
  return 0;
}