#include "controller.h"

void poll_buttons();
for (int k = 0; k < HARDWARE_NUMBER_OF_FLOORS; k++)
{
  if(hardware_read_order(k,HARDWARE_ORDER_UP))
  {
    placeorder(k,HARDWARE_ORDER_UP);
  }
  if(hardware_read_order(k,HARDWARE_ORDER_DOWN))
  {
    placeorder(k,HARDWARE_ORDER_DOWN);
  }
  if(hardware_read_order(k,HARDWARE_ORDER_INSIDE))
  {
    placeorder(k,HARDWARE_ORDER_INSIDE);
  }
  return
}
