#include "flag.h"

void print_bits(Flag* flag, uint32_t len);

int main() {
    int len = 5;
    Flag *flag = new_f();

    print_bits(flag, len);

    flag->set_f(flag, 0x01);
    flag->set_f(flag, 0x02);

    print_bits(flag, len);

    flag->reset_f(flag, 0x01);
    flag->set_f(flag, 0x04);
    
    print_bits(flag, len);

}

void print_bits(Flag* flag, uint32_t len) {
    uint32_t flag_res = flag->get_f(flag);
    bool* bits = new_b(len);
    to_b(bits, flag_res, len);
    for (int i = 0; i < len; i++) {
        printf("%d ", bits[i]);
    }
    printf("\n");
    del_b(bits);
}