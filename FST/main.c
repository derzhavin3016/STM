#include "stm32f0xx_ll_rcc.h"
#include "stm32f0xx_ll_system.h"
#include "stm32f0xx_ll_bus.h"
#include "stm32f0xx_ll_gpio.h"

void delay( void )
{
  for (int i = 0; i < 600000; i++);
}

void gpio_config( void )
{
  LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOA);
  LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOC);
  
  LL_GPIO_SetPinMode(GPIOC, LL_GPIO_PIN_8, LL_GPIO_MODE_OUTPUT);
  LL_GPIO_SetPinMode(GPIOC, LL_GPIO_PIN_0, LL_GPIO_MODE_INPUT);
}

int main( void )
{ 
  gpio_config();

  while (1)
  {
    /*LL_GPIO_SetOutputPin(GPIOC, LL_GPIO_PIN_8);
    delay();
    LL_GPIO_ResetOutputPin(GPIOC, LL_GPIO_PIN_8);
    delay();*/

    // 1 - off, 0 - on
    uint32_t status = LL_GPIO_IsInputPinSet(GPIOA, LL_GPIO_PIN_0);
    
    if (status == 1)
      LL_GPIO_SetOutputPin(GPIOC, LL_GPIO_PIN_8);
    else if (status == 0)
      LL_GPIO_ResetOutputPin(GPIOC, LL_GPIO_PIN_8);
  }
  return 0;
}