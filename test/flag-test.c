#include "reflag.h"

int main() {

    // Set length and initialize
    int len = 8;
    char names[] = "arrived, waiting, assigned, ordered, prepared, eating, paid, leaving";

    Flag *flag = new_f(names);

    printf("\nEmpty: \n");
    flag->print(flag);

    // Set
    flag->set(flag, arrived);
    flag->set(flag, waiting);
    
    printf("\nSet: \n");
    flag->print(flag);

    // Set multiple
    flag->set(flag, (uint32_t) assigned | ordered);

    printf("\nMultiple Set: \n");
    flag->print(flag);

     // Is | Reset
    if (flag->is(flag, (uint32_t) assigned | ordered))  
        flag->reset(flag, (uint32_t) arrived | waiting);

    printf("\nIs | Reset\n");
    flag->print(flag);

    // Reset 
    flag->reset(flag, assigned);
    flag->reset(flag, ordered);

    printf("\nReset: \n");
    flag->print(flag);

    flag->set(flag, (uint32_t) eating | paid);
    if (flag->is(flag, (uint32_t) eating | paid)) {
        flag->reset(flag, (uint32_t) eating | paid);
        flag->set(flag, leaving);
    } 

    printf("\nMultiple Is | Multiple Reset: \n");
    flag->print(flag);

    del_f(flag);
}
