/**
* @file
* @brief file for functions pertaining to the control of the machine as well as
* retrieving information about the state of the machine.
*/

#include "hardware.h"

/**
* @brief checks that @c hardware_read_stop_signal is low then proceeds to check
* whether any button is being pressed, in which case @c placeorder and
* @c hardware_command_order_light are called
*/
void poll_buttons();

/**
* @brief calls ©hardware_command_order_light for all @c order_types at the floor
*
* @param[in] floor floor
*/
void clear_light(int floor);

/**
* @brief deletes orders related to the floor served and calls @c new_direction
*
* @param[in] floor floor
*/
void order_served(int floor);


/**
* @brief clears all order lights
*/
void clear_all_order_lights();

/**
* @brief calls @c hardware_command_movement to stop, calls @c clear_all_orders
* @c clear_all_order_lights. Then calls @c door_loop if elevator is at a floor.
*/
void stop_button();

/**
* @brief checks to see if there are orders it should stop for, in which case
* @c hardware_command_movement is called to stop, @c door_loop is called
* and @c order_served is called.
*
* @param[in] floor floor
*/
void floor_reached(int f);

/**
* @brief Sets elevator motion to same direction as before if there are more
* orders along the path it was travelling,
* otherwise sets elevator motion in opposite direction of previous if there are
* orders to serve there, otherwise sets motion to stopped.
*
*/
void new_direction();

/**
* @brief calls @c hardware_command_movement to set movement up, when @c
* hardware_read_floor_sensor returns 1 the function returns the floor.
*
* @return the integer floor number
*
* @warning failure to initialise will never return anything
*/
int initialise();
