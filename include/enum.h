#ifndef FLAG_H
#define FLAG_H
#include "flag.h"
#endif

struct _Enum {
    Flag flag;
    uint32_t __len;
    
    char* (*getNames) (void *_self);
    void (*setNames) (void *_self, char *newNames);

    void (*init) (void *_self, char *names, uint32_t len);
    uint32_t (*len) (void *_self);
    uint32_t (*get) (void *_self);
    
    bool (*is) (void *_self, uint32_t anEnum);
    void (*set) (void *_self, uint32_t anEnum);
    void (*reset) (void *_self, uint32_t anEnum);
    
    void (*print) (void *_self);
};
typedef struct _Enum Enum;

Enum* new_e (char *names, uint32_t len);
void del_e (void *_self);

void init_e (void *_self, char* names, uint32_t len);
uint32_t len_e (void *_self);

bool is_e (void *_self, uint32_t aFlag);
void set_e (void *_self, uint32_t anEnum); 
void reset_e (void *_self, uint32_t anEnum);
