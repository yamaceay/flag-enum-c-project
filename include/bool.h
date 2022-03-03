#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#define BUF 1024

typedef enum Bool {false, true} bool;

bool *new_b (uint32_t num);
void to_b (bool *bits, uint32_t num, uint32_t len);
uint32_t from_b (bool *bits, uint32_t len);
void del_b (bool *bits);
void _print_without_names(bool *bits, uint32_t len);
void _print_with_names(bool *bits, char *names, uint32_t len);
void _print(uint32_t res, char *names, uint32_t len);
