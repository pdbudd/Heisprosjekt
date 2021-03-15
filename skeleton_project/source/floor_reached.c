#include "floor_reached.h"
#include "orders.h"
#include "door.h"
#include "controller.h"

void floor_reached(int f)
{
  if (current_direction == HARDWARE_MOVEMENT_UP && up_orders[f])
  {
    door_loop();
    order_served(f);
    return;
  }
  if (inside_orders[f])
  {
    door_loop();
    order_served(f);
    return;
  }
  return;
}
