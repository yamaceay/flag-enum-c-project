#include "flag.h"

int main() {

    // Set length and initialize
    int len = 8;
    char names[] = "arrived, waiting, assigned, ordered, prepared, eating, paid, leaving";

    Flag *flag = new_f(names);

    printf("\nEmpty: \n");
    flag->print(flag);

    // Set
    flag->set(flag, waiting);
    flag->set(flag, arrived);
    
    printf("\nSet: \n");
    flag->print(flag);

    // Set multiple
    flag->set(flag, (uint32_t) assigned | ordered | eating);

    printf("\nMultiple Set: \n");
    flag->print(flag);

    // Reset 
    flag->reset(flag, ordered);

    printf("\nReset: \n");
    flag->print(flag);

    // Is
    if (flag->is(flag, (uint32_t) arrived | waiting)) 
        flag->reset(flag, (uint32_t) arrived | waiting);
        
    printf("\nMultiple Is | Multiple Reset: \n");
    flag->print(flag);

    del_f(flag);
}
