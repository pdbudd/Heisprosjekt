#include "orders.h"
#define NELEMS(x) (sizeof(x)/sizeof(x[0]))

void placeorder(int floor, HardwareOrder direction)
{
  if (hardware_legal_floor(floor, direction))
  {
    switch (direction)
    {
      case HARDWARE_ORDER_UP:
      up_orders[floor-1] = 1;
      break;
      case HARDWARE_ORDER_DOWN:
      down_orders[floor-1] = 1;
      break;
      case HARDWARE_ORDER_INSIDE:
      inside_orders[floor-1] = 1;
      break;
      default:
    }
    return;
  }
  else
  {
    return;
  }
}

void new_direction()
{
  switch (current_direction)
  {
    case HARDWARE_MOVEMENT_UP:
    delete_order(currentfloor);
    for(int j = currentfloor; j<HARDWARE_NUMBER_OF_FLOORS; j++)
    {
      if(up_orders[j] == 1 || down_orders[j] == 1 || inside_orders[j] == 1)
      {
      hardware_command_movement(HARDWARE_MOVEMENT_UP);
      break;
      }
    }
    for(int k = 0; k < currentfloor +1; k++)
    {
      if(up_orders[k] == 1 || down_orders[k] == 1 || inside_orders[k] == 1)
      hardware_command_movement(HARDWARE_MOVEMENT_DOWN);
      break;
    }
    hardware_command_movement(HARDWARE_MOVEMENT_STOP);
    break;
    case HARDWARE_MOVEMENT_DOWN:
    delete_order(currentfloor);
    for(int j = 0; j =< currentfloor; j++)
    {
      if(up_orders[j] == 1 || down_orders[j] == 1 || inside_orders[j] == 1)
      {
      hardware_command_movement(HARDWARE_MOVEMENT_DOWN);
      break;
      }
    }
    for(int k = currentfloor; k < HARDWARE_NUMBER_OF_FLOORS; k++)
    {
      if(up_orders[k] == 1 || down_orders[k] == 1 || inside_orders[k] == 1)
      hardware_command_movement(HARDWARE_MOVEMENT_UP);
      break;
    }
    hardware_command_movement(HARDWARE_MOVEMENT_STOP);
    break;
    default:
  }
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

void delete_order(int order)
{
  switch () {
    case /* value */:
  }
}