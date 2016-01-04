#include <avr/io.h>
#include "uart.h"

int main(void)
{
  initUART();
  while(1)
  {
    writeString("Surya Na Mass");
    putByte('\r');
    putByte('\n');
  }
  return 0;
}