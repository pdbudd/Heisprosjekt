#include "initialise.h"
#include "hardware.h"

//returns the integer floor where the lift is at the end of initialisation
int initialise()
{
    int initialised = 0;

    hardware_command_movement(HARDWARE_MOVEMENT_UP);

    while (initialised == 0)
    {
      for (int f=0; f<HARDWARE_NUMBER_OF_FLOORS; f++)
      {
        if(hardware_read_floor_sensor(f))
        {
            hardware_command_movement(HARDWARE_MOVEMENT_STOP);
            initialised = 1;
            hardware_command_floor_indicator_on(f);
            return f;
        }
      }
    }
}
