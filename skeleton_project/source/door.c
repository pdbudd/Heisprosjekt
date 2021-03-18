#include "door.h"
#include "controller.h"
#include "hardware.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


#define DOOR_OPEN_INTERVAL 3

int is_door_open = 0;


time_t door_time_opened_pointer;

HardwareMovement previous_direction;
HardwareMovement current_direction;
int current_floor;




int door_keep_open() {
	if (hardware_read_obstruction_signal()){
		door_time_opened_pointer = time(NULL);
		return 1;
	}
    if(time(NULL) < door_time_opened_pointer + DOOR_OPEN_INTERVAL) {
		return 1;
	}
	return 0;
}



void door_open() {
	for(int i = 0; i<HARDWARE_NUMBER_OF_FLOORS; i++)
	{
		if(hardware_read_floor_sensor(i) && current_direction == HARDWARE_MOVEMENT_STOP)
		{
			hardware_command_door_open(1);
		    door_time_opened_pointer = time(NULL);  //oppdater klokken
			is_door_open = 1;
		}
	}
	return;
}




void door_close() {
	hardware_command_door_open(0);
    is_door_open = 0;
		return;
}


int door_get_status(){
    return is_door_open;
}

void door_loop()
{
	door_open();
	while (door_keep_open())
	{
		hardware_command_stop_light(hardware_read_stop_signal());
		poll_buttons();
		door_keep_open();
	}
	door_close();
	is_door_open = 0;
	return;
}
