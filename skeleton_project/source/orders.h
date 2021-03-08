
/**
*Order structure including floor and direction
*/

struct [Orders]
{
  int order_floor;
  HardwareOrder order_type;
};
/**
*High priority queue array including integer floors elevator is currently on path to
*/
int hipri_Queue[HARDWARE_NUMBER_OF_FLOORS-1];

/**
*integer variable defining the end of the elevator's current path
*/

int currentgoal;

/**
*Low priority queue storing orders so that next high priority queue block can be generated
*/
struct Orders lopri_Queue[HARDWARE_NUMBER_OF_FLOORS*2-2];

/**
*Function that determines whether an order is serviced on the elevators current path
*Either updates high priority queue array or places order in correct place of low priority array
*/
void placeorder(int floor, HardwareOrder direction);

/**
*function places order in lopri_Queue
*/
void placeorder_lopri(int floor, HardwareOrder direction)

/**
* Updates High priority queue
*/
void hipri_Queue_update();

/**
*Clears all orders
*/
void clear_all_orders();

/**
*Deletes order lopri_Queue[order]
*/
void delete_order(int order);
