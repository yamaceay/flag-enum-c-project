#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum Bool {false, true} bool;

bool *new_b (uint32_t num);
void to_b (bool *bits, uint32_t num, uint32_t len);
uint32_t from_b (bool *bits, uint32_t len);
void del_b (bool *bits);
void print(uint32_t res, uint32_t len, char *names);

