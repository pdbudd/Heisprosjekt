#include "orders.h"
#define NELEMS(x) (sizeof(x)/sizeof(x[0]))

void placeorder(int floor, HardwareOrder direction)
{
  if (hardware_legal_floor(floor, direction))
  {
    for (int i = 0; i < HARDWARE_NUMBER_OF_FLOORS-1; i++)
    {
        if (hipri_Queue[i] == floor)
        {
          return;
        }
        if (direction == current_direction)
        {
          //Does this make sure that the target is within current path??
          if(current_direction == HARDWARE_MOVEMENT_UP && floor < currentgoal || current_direction == HARDWARE_MOVEMENT_DOWN && floor > currentgoal)
          {
            for (int n = 0; n < HARDWARE_NUMBER_OF_FLOORS-1; n++)
            {
              if(floor>hipri_Queue[n] && current_direction == HARDWARE_ORDER_DOWN)
              {
                hipri_Queue[n-1] = floor;
                return;
              }
              if(floor<hipri_Queue[n] && current_direction == HARDWARE_ORDER_UP)
              {
                hipri_Queue[n-1] = floor;
                return;
              }
            }
          }
          else
          {
            placeorder_lopri(floor,direction);
        }
    }
  }
  else
  {
    return
  }
}

void placeorder_lopri(int floor, HardwareOrder direction)
{
  size_t m = NELEMS(lopri_Queue);
  for (size_t n = 0; n < m; n++)
  {
    if(direction == lopri_Queue[n].order_type && floor == lopri_Queue[n].order_floor)
    {
      return;
    }
    if(direction == lopri_Queue[n].order_type)
    {
      if(direction == HARDWARE_ORDER_UP && floor < lopri_Queue[n].order_floor)
      {
        for (size_t u = m-1; u>= n; u--)
        {
          lopri_Queue[u] = lopri_Queue[u-1];
        }
        lopri_Queue[u] = {floor, direction};
        return;
      }
      if(direction == HARDWARE_ORDER_DOWN && floor > lopri_Queue[n].order_floor)
      {
        for (size_t u = m-1; u>= n; u--)
        {
          lopri_Queue[u] = lopri_Queue[u-1];
        }
        lopri_Queue[u] = {floor, direction};
        return;
      }
    }
  }
}

void hipri_Queue_update()
{
  size_t m = NELEMS(lopri_Queue);
  int n = 0;
  HardwareOrder h = lopri_Queue[0].order_type;
  //gotta fix how this clears the lopri orders that are added to the hipri_Queue
  //atm it is both iterating through lopri list and procedurally shrinking it leading to
  //the indices getting out of whack.
  while (lopri_Queue[n].order_type == lopri_Queue[n-1].ordertype)
  {
    hipri_Queue[n] = lopri_Queue[n].order_floor;
    for (size_t j = 0; j < m-1; j++)
    {
      lopri_Queue[j] =
    }
  }
}

void clear_all_orders()
{

}

void delete_order(int order)
{

}
