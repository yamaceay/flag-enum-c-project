#ifndef BOOL_H
#define BOOL_H
#include "bool.h"
#endif

#ifndef DIRENT_H
#define DIRENT_H
#include <dirent.h>
#endif

char *concat (char *str1, char *str2);
char *read_enum (char *file, int *res_len, char **name, bool flag);
void write_enum (char *file, char *mode, char *name, char *res);
void take_inputs (); 

