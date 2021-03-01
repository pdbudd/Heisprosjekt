#include "orders.h"
#

void placeorder(int floor, HardwareOrder direction)
{
  if (hardware_legal_floor(floor, direction))
  {
    for (int i = 0; i < HARDWARE_NUMBER_OF_FLOORS*2-2; i++)
    {
        if (Queue[i].order_floor == floor && Queue[i].order_type == direction)
        {
          return;
        }
        if (current_direction == direction)
        {
          if (current_direction == HARDWARE_MOVEMENT_UP && floor >= currentfloor || current_direction == HARDWARE_MOVEMENT_DOWN && floor <= currentfloor)
          {
            for (int n = 0; n < HARDWARE_NUMBER_OF_FLOORS*2-2; n++)
            {
              hipri_Queue[HARDWARE_NUMBER_OF_FLOORS*2-2-n]=hipri_Queue[HARDWARE_NUMBER_OF_FLOORS*2-1-n];
            }
            hipri_Queue[0]=struct orders{floor,direction};
          }
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
