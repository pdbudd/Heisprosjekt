/**
* @file
* @brief file containing functions for manipulating orders
*/
#include "orders.h"
#include "hardware.h"
#include "door.h"
#include <stdio.h>
#include <stdlib.h>

HardwareMovement current_direction;
HardwareMovement previous_direction;
int current_floor;
int is_door_open;

void placeorder(int floor, HardwareOrder direction)
{
  if (hardware_legal_floor(floor, direction))
  {
      if(hardware_read_floor_sensor(floor) && current_direction == HARDWARE_MOVEMENT_STOP)
      {
        door_loop();
        return;
      }
      switch (direction)
      {
        case HARDWARE_ORDER_UP:
        up_orders[floor] = 1;
        break;
        case HARDWARE_ORDER_DOWN:
        down_orders[floor] = 1;
        break;
        case HARDWARE_ORDER_INSIDE:
        inside_orders[floor] = 1;
        break;
        default:;
      }
        if(!door_get_status() && current_direction == HARDWARE_MOVEMENT_STOP)
        {
          if(current_floor < floor)
          {
            hardware_command_movement (HARDWARE_MOVEMENT_UP);
            current_direction = HARDWARE_MOVEMENT_UP;
            return;
          }
          if(current_floor > floor)
          {
            hardware_command_movement(HARDWARE_MOVEMENT_DOWN);
            current_direction = HARDWARE_MOVEMENT_DOWN;
            return;
          }
        }
    return;
    }
  else
  {
    return;
  }
}

//returns 1 if the elevator has no orders further along its current path
int floor_stop_query()
{
  switch (current_direction)
  {
    case HARDWARE_MOVEMENT_UP:
    {
      for(int j = current_floor+1; j<HARDWARE_NUMBER_OF_FLOORS; j++)
      {
        if(up_orders[j] || down_orders[j] || inside_orders[j])
        {
        return 0;
        }
      }
    }
    case HARDWARE_MOVEMENT_DOWN:
    for(int j = 0; j < current_floor; j++)
    {
      if(up_orders[j] || down_orders[j] || inside_orders[j])
      {
      return 0;
      }
      default:;
    }
  }
  return 1;
}

void clear_all_orders()
{
  for(int i = 0; i < HARDWARE_NUMBER_OF_FLOORS; i++)
  {
    up_orders[i] = 0;
    down_orders[i] = 0;
    inside_orders[i] = 0;
  }
  return;
}
