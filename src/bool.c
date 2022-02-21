#include "bool.h"

bool *new_b (uint32_t num) {
    bool* bits = malloc(sizeof(bool) * num);
    for (int i = 0; i < num; i++) {
        bits[i] = 0;
    }
    return bits;
}

void to_b (bool *bits, uint32_t num, uint32_t len) {
    for (int i = 0; i < len; i++) {
        uint32_t exp = 1 << i;
        uint32_t mask = num & exp;
        bits[i] = mask >> i;
    }
}

uint32_t from_b(bool *bits, uint32_t len) {
    uint32_t sum = 0;
    for (int i = 0; i < len; i++) {
        sum += bits[i] << i;
    }
    return sum;
}

void del_b (bool *bits) {
    free(bits);
}