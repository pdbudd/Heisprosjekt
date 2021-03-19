#ifndef DOOR_H_
#define DOOR_H_
/**
*@file
*@brief Declaration of door functions
*/
int door_keep_open();



/**
* @brief Open the door and set the @p
* is_door_open int to 1.
*/
void door_open();

/**
* @brief Close the door and set the @p
* is_door_open int to 0.
*
*/
void door_close();

/**
* @brief Fetch door status.
*
* @return 0 when door is closed
* * @return 1 when door i open.
*/
int door_get_status();

/**
* @brief calls @c door_open, while @c door_keep_open is high calls @c
* poll_buttons, @c door_keep_open and updates @c hardware_command_stop_light
* calls @c door_close when @c door_keep_open goes low
*
*/
void door_loop();

#endif
