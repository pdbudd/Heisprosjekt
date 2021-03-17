#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include <stdint.h>
#include "hardware.h"
#include "orders.h"
#include "initialise.h"
#include "controller.h"
#include "door.h"

HardwareMovement current_direction;
HardwareMovement previous_direction;
int current_floor;


int main(){
    current_floor = 2;
    current_direction = HARDWARE_MOVEMENT_STOP;
    previous_direction = HARDWARE_MOVEMENT_STOP;
    placeorder(3,HARDWARE_ORDER_DOWN);
    floor_reached(3);
    initialise();





    return 0;
}
