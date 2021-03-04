#include "clicker.h"


#define NO_NOISE

//#define CLICKER

int main( void )
{ 
  gpio_config();
  uint32_t counter = 0, is_pressed = 0, is_on = 0;
  uint32_t n = 0;
  
  while (1)
  {
#ifdef NO_NOISE
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
    
      //LL_GPIO_WriteOutputPort(GPIOB, 0x0000);
      ++n;
      
      is_pressed = 0;
      counter = 0;
    }
#else
     if (LL_GPIO_IsInputPinSet(GPIOA, LL_GPIO_PIN_0)) 
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
#ifdef CLICKER
        LL_GPIO_WriteOutputPort(GPIOB, 0x0000);
        ++n;
#endif
     }
#endif
    
#ifdef CLICKER
    show_number(n);
#else
    for (int i = 0; i < 20000; ++i)
      show_hell(n);
    n++;
    
#endif
  }
}