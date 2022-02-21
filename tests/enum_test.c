#include "enum.h"
enum state {
    waiting,
    busy,
    calling,
    ongoing,
    active,
    postponed
};

void print_bits(Enum *enu, uint32_t len);

int main() {
    uint32_t len = 10;
    Enum* enu = new_e(len);

    enu->init_e(enu, len);

    enu->set_e(enu, postponed);
    enu->set_e(enu, ongoing); 
    enu->set_e(enu, waiting);
    
    print_bits(enu, len);
    
    enu->reset_e(enu, ongoing);
    
    print_bits(enu, len);

    if (enu->isSet_e(enu, waiting)) {
        enu->reset_e(enu, waiting);
    }

    print_bits(enu, len);

    del_e(enu);
}

void print_bits(Enum* enu, uint32_t len) {
    uint32_t enu_res = enu->get_e(enu);
    bool* bits = new_b(len);
    to_b(bits, enu_res, len);
    for (int i = 0; i < len; i++) {
        printf("%d ", bits[i]);
    }
    printf("\n");
    del_b(bits);
}