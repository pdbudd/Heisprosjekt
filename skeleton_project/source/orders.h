/**
*High priority queue array including integer floors elevator is currently on path to
*/
int hipri_Queue[HARDWARE_NUMBER_OF_FLOORS-1];

/**
*Function that determines whether an order is serviced on the elevators current path
*Either updates high priority queue array or places order in correct place of low priority array
*/
void placeorder(int floor);

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
void delete_order(int floor, HardwareOrder direction);

int down_orders[HARDWARE_NUMBER_OF_FLOORS-1];

int inside_orders[HARDWARE_NUMBER_OF_FLOORS-1];

int up_orders[HARDWARE_NUMBER_OF_FLOORS-1];
