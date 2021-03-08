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

void clear_all_orders()
{

}

void delete_order(int order)
{

}

void placeorder_lopri(int floor, HardwareOrder direction)
{
  size_t m = NELEMS(lopri_Queue);
  for (size_t n = 0; n < m; n++)
  {

  }
}
