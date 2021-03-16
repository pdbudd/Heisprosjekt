#include "controller.h"
#include "hardware.h"
#include "orders.h"
#include "door.h"

void poll_buttons()
{
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
  }
  return;
}

void floor_reached(int f)
{
  if (current_direction == HARDWARE_MOVEMENT_UP && up_orders[f])
  {
    hardware_command_movement(HARDWARE_MOVEMENT_STOP);
    current_direction = HARDWARE_MOVEMENT_STOP;
    door_loop();
    order_served(f);
    return;
  }
  if (inside_orders[f])
  {
    hardware_command_movement(HARDWARE_MOVEMENT_STOP);
    current_direction = HARDWARE_MOVEMENT_STOP;
    door_loop();
    order_served(f);
    return;
  }
  if(current_direction == HARDWARE_MOVEMENT_DOWN && down_orders[f])
  {
    hardware_command_movement(HARDWARE_MOVEMENT_STOP);
    current_direction = HARDWARE_MOVEMENT_STOP;
    door_loop();
    order_served();
    return;
  }
  return;
}

void clear_light(int floor)
{
  hardware_command_order_light(floor, HARDWARE_ORDER_INSIDE, 0);
  hardware_command_order_light(floor, HARDWARE_ORDER_UP, 0);
  hardware_command_order_light(floor, HARDWARE_ORDER_DOWN, 0);
  return;
}

void order_served(int floor)
{
  down_orders[floor] = 0;
  up_orders[floor] = 0;
  inside_orders[floor] = 0;
  clear_light(floor);
  new_direction();
  return;
}

void clear_all_order_lights(){
    HardwareOrder order_types[3] = {
        HARDWARE_ORDER_UP,
        HARDWARE_ORDER_INSIDE,
        HARDWARE_ORDER_DOWN
    };

    for(int f = 0; f < HARDWARE_NUMBER_OF_FLOORS; f++){
        for(int i = 0; i < 3; i++){
            HardwareOrder type = order_types[i];
            hardware_command_order_light(f, type, 0);
        }
    }
}

void stop_button()
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
          door_loop();
      }
    }
  }
  hardware_command_stop_light(0);
  return;
}
