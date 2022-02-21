#include "enum.h"

// define the enumeration type
typedef enum state {
    waiting,
    busy,
    calling,
    ongoing,
    active,
    postponed
} state;

int main() {

    // set length and configure the names (optional)
    uint32_t len = 6;
    char names[] = "waiting, busy, calling, ongoing, active, postponed";

    Enum* enu = new_e(names, len);

    printf("\nEmpty: \n");
    enu->print(enu);

    // set all enums listed below 
    state enums_set[] = {postponed, ongoing, waiting};
    enu->set_all(enu, enums_set, 3);
    
    printf("\nMultiple set: \n");
    enu->print(enu);

    // reset all enums listed below
    state enums_reset[] = {ongoing, calling, postponed};
    enu->reset_all(enu, enums_reset, 3);

    printf("\nMultiple reset: \n");
    enu->print(enu);
    
    // set / reset a single enum
    enu->reset(enu, ongoing);
    enu->set(enu, calling);

    printf("\nSet | Reset: \n");
    enu->print(enu);

    // check if set and reset a enum
    if (enu->is(enu, waiting)) {
        enu->reset(enu, waiting);
    }

    printf("\nIs | Reset: \n");
    enu->print(enu);
    
    // free memory
    del_e(enu);
}