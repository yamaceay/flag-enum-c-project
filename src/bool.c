#ifndef BOOL_H
#define BOOL_H
#include "bool.h"
#endif

/**
 * @brief Creates a new bit array
 * 
 * @param num Number of bits
 * @return bool* Bit array
 */
bool *new_b (uint32_t num) {
    bool* bits = malloc(sizeof(bool) * num);
    for (int i = 0; i < num; i++) {
        bits[i] = 0;
    }
    return bits;
}

/**
 * @brief Converts a number to a bit array
 * 
 * @param bits Bits
 * @param num The sum of flags
 * @param len Number of flags in num
 */
void to_b (bool *bits, uint32_t num, uint32_t len) {
    for (int i = 0; i < len; i++) {
        uint32_t exp = 1 << i;
        uint32_t mask = num & exp;
        bits[i] = mask >> i;
    }
}

/**
 * @brief Converts a bit array to a number
 * 
 * @param bits Bit array
 * @param len Number of bits in bit array
 * @return uint32_t The sum of flags
 */
uint32_t from_b(bool *bits, uint32_t len) {
    uint32_t sum = 0;
    for (int i = 0; i < len; i++) {
        sum += bits[i] << i;
    }
    return sum;
}

/**
 * @brief Deletes the bit array
 * 
 * @param bits Bit array
 */
void del_b (bool *bits) {
    free(bits);
}

/**
 * @brief Prints the bit array without names
 * 
 * @param bits Bit array
 * @param len Length of bit array
 */
void _print_without_names(bool *bits, uint32_t len) {
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
}

/**
 * @brief Prints the bit array with names
 * 
 * @param bits Bit array
 * @param names Names 
 * @param len Length of bit array
 */
void _print_with_names(bool *bits, char *names, uint32_t len) {
    printf("\n{");

    char *string = strdup(names);
        
    char delim[3] = ", ";
    char *ptr = strtok(string, delim);
    free(string);

    int i = 0;
    while (ptr) {
        printf("\n\t%10s: %2d", ptr, bits[i]);

        if (i < len - 1) {
            printf(", ");
        }

        i++;
        ptr = strtok(NULL, delim);
    }

    printf("\n}\n");
}

/**
 * @brief Pretty-print the contents of 
 * bit array given names for each flag
 * 
 * @param res Sum of flags
 * @param names Name of flags
 * @param len Number of flags
 */
void _print(uint32_t res, char *names, uint32_t len) {
    bool* bits = new_b(len);
    to_b(bits, res, len);
    
    if (names) _print_with_names(bits, names, len);
    else _print_without_names(bits, len);

    del_b(bits);
}
