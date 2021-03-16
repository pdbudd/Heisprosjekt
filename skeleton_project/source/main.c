#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "hardware.h"
#include "orders.h"
#include "initialise.h"
#include "controller.h"


int main(){
    int error = hardware_init();
    if(error != 0){
        fprintf(stderr, "Unable to initialize hardware\n");
        exit(1);
    }
    extern int currentfloor;
    extern HardwareMovement current_direction;
    currentfloor = initialise();

    while(1){
        if(hardware_read_stop_signal()){
            hardware_command_movement(HARDWARE_MOVEMENT_STOP);
        }

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
