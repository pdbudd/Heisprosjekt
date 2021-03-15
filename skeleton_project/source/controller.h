/**
* quickly polls all buttons and places orders into relevant arrays if one is pressed.
*/
void poll_buttons();

/**
*Clears order_type light at floor
*/
void clear_light(int floor, HardwareOrder order_type);

/**
*Deletes orders related to the floor served and calls new_direction() to determine where
*elevator proceeds
*/
void order_served(int floor);

/**
* clears all orders, lights, and opens the doors if the elevator is at a floor.
*/
void stop_button();

void floor_reached();