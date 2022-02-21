#include "flag.h"

typedef enum state {
    waiting = 0x1,
    busy = 0x2,
    calling = 0x4,
    ongoing = 0x8,
    active = 0x10,
    postponed = 0x20
} state;

int main() {

    // Set length and initialize
    int len = 6;
    char names[] = "waiting, busy, calling, ongoing, active, postponed";

    Flag *flag = new_f();

    printf("\nEmpty: \n");
    flag->print(flag, names);

    // Set
    flag->set(flag, waiting);
    flag->set(flag, postponed);
    
    printf("\nSet: \n");
    flag->print(flag, names);

    // Set multiple
    flag->set(flag, (uint32_t) busy | calling | active);

    printf("\nMultiple Set: \n");
    flag->print(flag, names);

    // Reset 
    flag->reset(flag, busy);

    printf("\nReset: \n");
    flag->print(flag, names);

    // Is
    if (flag->is(flag, (uint32_t) active | waiting)) 
        flag->reset(flag, (uint32_t) active | waiting);
        
    printf("\nMultiple Is | Multiple Reset: \n");
    flag->print(flag, names);

    del_f(flag);
}
