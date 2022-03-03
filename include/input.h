#ifndef BOOL_H
#define BOOL_H
#include "bool.h"
#endif

#ifndef DIRENT_H
#define DIRENT_H
#include <dirent.h>
#endif

char *builder (char *str1, char *str2);

// I/O-Functions for enum (private scope)
int _enum_handle_input (int argc, char **argv, char **dest_wdir);
int _enum_write_to_all (struct dirent *entry, char *dest_dir);
char *_enum_set_name(char *temp_file);
char *_enum_set_data(char *file);
char *_enum_set_data_step(char *res, char *buf, uint32_t i);
char *_enum_set_code(char *name, char *data);
void _enum_write_code (char *file, char *mode, char *code);
void _enum_write_path (char *path, char *dest_path);
void _enum_write_file(char *path, char *dest_path);