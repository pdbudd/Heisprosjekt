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
    int currentfloor = initialise();
    current_direction = HARDWARE_MOVEMENT_STOP;

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




        /* Lights are set and cleared like this: */
        for(int f = 0; f < HARDWARE_NUMBER_OF_FLOORS; f++){
            /* Internal orders */
            if(hardware_read_order(f, HARDWARE_ORDER_INSIDE)){
                hardware_command_order_light(f, HARDWARE_ORDER_INSIDE, 1);
            }

            /* Orders going up */
            if(hardware_read_order(f, HARDWARE_ORDER_UP)){
                hardware_command_order_light(f, HARDWARE_ORDER_UP, 1);
            }

            /* Orders going down */
            if(hardware_read_order(f, HARDWARE_ORDER_DOWN)){
                hardware_command_order_light(f, HARDWARE_ORDER_DOWN, 1);
            }
        }

        /* Code to clear all lights given the obstruction signal */
        if(hardware_read_obstruction_signal()){
            hardware_command_stop_light(1);
            clear_all_order_lights();
        }
        else{
            hardware_command_stop_light(0);
        }
    }

    return 0;
}
