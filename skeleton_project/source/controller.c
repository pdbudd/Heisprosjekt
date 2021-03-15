#include <stdio>
#include "controller.h"
#include "hardware.h"

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

void stop_button();
{
  clear_all_orders();
  clear_all_order_lights();
  hardware_command_movement(HARDWARE_MOVEMENT_STOP);
  hardware_command_stop_light(1);
  while(hardware_read_stop_signal())
  {
    for (int f=0; f<HARDWARE_NUMBER_OF_FLOORS; f++)
    {
      if(hardware_read_floor_sensor(f))
      {
          door_open();
      }
    }
  }
  hardware_command_stop_light(0);
  return;
}
