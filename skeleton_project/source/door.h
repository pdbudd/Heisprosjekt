#ifndef DOOR_H_
#define DOOR_H_
/**
*@file
*@brief A executive controlling operations connected to the doors
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

void door_loop();

#endif
