/**
* quickly polls all buttons and places orders into relevant arrays if one is pressed.
*/
void poll_buttons();

/**
*Sets order_type light at floor on
*/
void set_light(int floor, HardwareOrder order_type);

/**
*Clears order_type light at floor
*/
void clear_light(int floor, HardwareOrder order_type);

/**
*Deletes orders related to the floor served and calls new_direction() to determine where
*elevator proceeds
*/
void order_served(int floor);
