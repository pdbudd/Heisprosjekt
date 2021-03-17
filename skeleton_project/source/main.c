#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "hardware.h"
#include "orders.h"
#include "initialise.h"
#include "controller.h"
#include "door.h"

int current_floor;
HardwareMovement current_direction;
HardwareMovement previous_direction;


int main(){
    int error = hardware_init();
    if(error != 0){
        fprintf(stderr, "Unable to initialize hardware\n");
        exit(1);
    }
    previous_direction = HARDWARE_MOVEMENT_STOP;
    current_direction = HARDWARE_MOVEMENT_UP;
    current_floor = initialise();
    current_direction = HARDWARE_MOVEMENT_STOP;

    while(1){
        if(hardware_read_stop_signal()){
            stop_button();
        }
        if(door_get_status())
        {hardware_command_movement(HARDWARE_MOVEMENT_STOP);}

        poll_buttons();


        for (int f=0; f<HARDWARE_NUMBER_OF_FLOORS; f++)
        {
          if(hardware_read_floor_sensor(f))
          {
              hardware_command_floor_indicator_on(f);
              floor_reached(f);
          }
        }
    }

    return 0;
}
