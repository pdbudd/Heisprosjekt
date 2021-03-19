/**
* @file
* @brief Declaration of order functions and arrays
*/

#include "hardware.h"

/**
* @brief does nothing if @c hardware_legal_floor is low
* otherwise calls @door_loop if the order is from the current floor then returns
* if the order is from anothe floor the relevant order array is updated,
* if doors are closed and elevator is stationary sets movement towards order.
*
* @param[in] floor floor
* @param[in] direction order type
*/
void placeorder(int floor, HardwareOrder direction);

/**
* @brief Clears all orders
*/
void clear_all_orders();

/**
* @brief checks to see if there are orders further along the current path
*
* @return 0 if there are orders further along the current path, 1 otherwise
*/
int floor_stop_query();

int down_orders[HARDWARE_NUMBER_OF_FLOORS-1];

int inside_orders[HARDWARE_NUMBER_OF_FLOORS-1];

int up_orders[HARDWARE_NUMBER_OF_FLOORS-1];
