#ifndef BOOL_H
#define BOOL_H
#include "bool.h"
#endif

typedef struct _Flag Flag;
typedef struct _Flag {
    uint32_t __flags;
    char __names[BUF];

    char * (*getNames) (void *_self);
    void (*setNames) (void *_self, char *newNames);

    void (*init) (void *_self, char *names);
    uint32_t (*get) (void *_self);

    bool (*is) (void *_self, uint32_t aFlag);
    void (*set) (void *_self, uint32_t aFlag);
    void (*reset) (void *_self, uint32_t aFlag);

    void (*print) (void *_self);

} Flag;

Flag* new_f (char *names);
void del_f (void *_self);

char *getNames_f(void *_self);
void setNames_f(void *_self, char *newNames);

void init_f (void *_self, char *names);
uint32_t get_f (void *_self);
bool is_f (void *_self, uint32_t aFlag);
void set_f (void *_self, uint32_t aFlag);
void reset_f (void *_self, uint32_t aFlag);
void print_f (void *_self);
