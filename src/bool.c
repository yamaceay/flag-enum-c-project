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

void print(uint32_t res, uint32_t len, char *names) {
    bool* bits = new_b(len);
    to_b(bits, res, len);
    
    if (names) {
        char delim[3] = ", ";
        printf("\n{");
        int i = 0;
        char *string = strdup(names);
        char *ptr = strtok(string, delim);
        while (ptr) {
            printf("\n\t%10s: %2d", ptr, bits[i]);
            if (i < len - 1) {
                printf(", ");
            }
            i++;
            ptr = strtok(NULL, delim);
        }
        printf("\n}\n");
        return;
    }

    printf("\n");
    for (int i = 0; i < len; i++) {
        printf("----");
    }
    printf("\n");
    for (int i = 0; i < len; i++) {
        printf("%d | ", bits[i]);
    }
    printf("\n");
    for (int i = 0; i < len; i++) {
        printf("----");
    }
    printf("\n");
    del_b(bits);
}
