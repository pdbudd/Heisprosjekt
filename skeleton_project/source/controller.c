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

void clear_light(int floor);
{
  hardware_command_order_light(floor, HARDWARE_ORDER_INSIDE, 0)
  hardware_command_order_light(floor, HARDWARE_ORDER_UP, 0);
  hardware_command_order_light(floor, HARDWARE_ORDER_DOWN, 0);
  return;
}

void order_served(int floor);
{
  down_orders[floor] = 0;
  up_orders[floor] = 0;
  inside_orders[floor] = 0;
  clear_light(floor);
  new_direction();
  return;
}
