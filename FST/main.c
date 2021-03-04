#include "clicker.h"

#define NO_NOISE

#define CLICKER

int main( void )
{ 
  gpio_config();
  
  while (1)
  {
#ifdef CLICKER

#ifdef NO_NOISE
    no_noise_cl();
#else
    noise_cl();
#endif
    
#else
    show_word();
#endif
  }
}