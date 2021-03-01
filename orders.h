
struct [Orders]
{
  int order_floor;
  HardwareOrder order_type;
} orders;

struct Orders hipri_Queue[HARDWARE_NUMBER_OF_FLOORS*2-2];

struct Orders lopri_Queue[HARDWARE_NUMBER_OF_FLOORS*2-2];

void placeorder(int floor, HardwareOrder direction);

void clear_all_orders();

void delete_order(int order);
