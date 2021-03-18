#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "hardware.h"
#include "orders.h"
#include "initialise.h"
#include "controller.h"
#include "door.h"



int current_floor;
HardwareMovement current_direction = HARDWARE_MOVEMENT_STOP;
HardwareMovement previous_direction = HARDWARE_MOVEMENT_STOP;

int main(){
  previous_direction = HARDWARE_MOVEMENT_STOP;
  current_direction = HARDWARE_MOVEMENT_UP;
    int error = hardware_init();
    if(error != 0){
        fprintf(stderr, "Unable to initialize hardware\n");
        exit(1);
    }
    current_floor = initialise();
    printf("initialised at %d floor\n", current_floor);
    current_direction = HARDWARE_MOVEMENT_STOP;
      printf("%d", current_direction);

    while(1){
        if(hardware_read_stop_signal())
        {
          previous_direction = current_direction;
          while(hardware_read_stop_signal())
          {
            stop_button();
          }
        }
        if(door_get_status())
        {hardware_command_movement(HARDWARE_MOVEMENT_STOP);}
        for (int k = 0; k < HARDWARE_NUMBER_OF_FLOORS; k++)
        {
          hardware_command_order_light(k,HARDWARE_ORDER_UP,up_orders[k]);
          hardware_command_order_light(k,HARDWARE_ORDER_DOWN,down_orders[k]);
          hardware_command_order_light(k,HARDWARE_ORDER_INSIDE,inside_orders[k]);
        }

        poll_buttons();

        hardware_command_floor_indicator_on(current_floor);


        for (int f=0; f<HARDWARE_NUMBER_OF_FLOORS; f++)
        {
          if(hardware_read_floor_sensor(f))
          {
              current_floor = f;
              floor_reached(f);
          }
        }
    }

    return 0;
}
