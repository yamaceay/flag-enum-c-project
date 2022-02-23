#include "bool.h"
#include <dirent.h>

char *concat (char *str1, char *str2);
char *read_enum (char *file, int *res_len, char **name, bool flag);
void write_enum (char *file, char *mode, char *name, char *res);
void take_inputs (); 