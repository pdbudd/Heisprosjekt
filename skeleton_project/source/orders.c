#include "orders.h"
#include "hardware.h"

void placeorder(int floor, HardwareOrder direction)
{
  if (hardware_legal_floor(floor, direction))
  {
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
    if(current_direction == HARDWARE_MOVEMENT_STOP)
    {
      if(current_floor == floor)
      {
        door_open();
        return;
      }
        while(door_get_status())
        {}
        if(current_floor < floor)
        {
          hardware_command_movement (HARDWARE_MOVEMENT_UP);
          return;
        }
        if(current_floor > floor)
        {
          hardware_command_movement(HARDWARE_MOVEMENT_DOWN);
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

      if(up_orders[j] || down_orders[j] || inside_orders[j])
      {
      return 0;
      }
      default:;
    }
  }
  return 1;
}

void new_direction()
{
  switch (previous_direction)
  {
    case HARDWARE_MOVEMENT_UP:
    for(int j = current_floor; j<HARDWARE_NUMBER_OF_FLOORS; j++)
    {
      if(up_orders[j] || down_orders[j] || inside_orders[j])
      {
      hardware_command_movement(HARDWARE_MOVEMENT_UP);
      current_direction == HARDWARE_MOVEMENT_UP;
      break;
      }
    }
    for(int k = 0; k < current_floor +1; k++)
    {
      if(up_orders[k] || down_orders[k] || inside_orders[k])
      hardware_command_movement(HARDWARE_MOVEMENT_DOWN);
      current_direction == HARDWARE_MOVEMENT_DOWN;
      break;
    }
    hardware_command_movement(HARDWARE_MOVEMENT_STOP);
    current_direction == HARDWARE_MOVEMENT_STOP;
    break;
    case HARDWARE_MOVEMENT_DOWN:
    for(int j = 0; j <= current_floor; j++)
    {
      if(up_orders[j] || down_orders[j] || inside_orders[j])
      {
      hardware_command_movement(HARDWARE_MOVEMENT_DOWN);
      current_direction == HARDWARE_MOVEMENT_DOWN;
      break;
      }
    }
    for(int k = current_floor; k < HARDWARE_NUMBER_OF_FLOORS; k++)
    {
      if(up_orders[k] || down_orders[k] || inside_orders[k])
      hardware_command_movement(HARDWARE_MOVEMENT_UP);
      current_direction == HARDWARE_MOVEMENT_UP;
      break;
    }
    hardware_command_movement(HARDWARE_MOVEMENT_STOP);
    break;
    default:;
  }
  return;
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
