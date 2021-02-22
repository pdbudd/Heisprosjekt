
struct [Orders]
{
  int floor;
  HardwareOrder order;
} order;

struct Orders order Queue[HARDWARE_NUMBER_OF_FLOORS*2-2];

void placeorder(int floor, HardwareOrder direction);

void clear_all_orders();

void delete_order(int order);
