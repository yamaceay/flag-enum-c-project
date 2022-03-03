#ifndef FLAG_H
#define FLAG_H
#include "flag.h"
#endif

struct _Renum {
    Flag flag;
    uint32_t __len;
    
    char* (*names) (void *_self);
    void (*set_names) (void *_self, char *newNames);

    void (*init) (void *_self, char *names, uint32_t len);
    uint32_t (*len) (void *_self);
    uint32_t (*get) (void *_self);

    bool (*is) (void *_self, uint32_t aRenum);
    bool (*all) (void *_self, uint32_t size, ...);
    bool (*any) (void *_self, uint32_t size, ...);
    
    void (*set) (void *_self, uint32_t aRenum);
    void (*set_all) (void *_self, uint32_t size, ...);
    
    void (*reset) (void *_self, uint32_t aRenum);
    void (*reset_all) (void *_self, uint32_t size, ...);
    
    void (*print) (void *_self);
};
typedef struct _Renum Renum;

Renum* new_r (char *names, uint32_t len);
void del_r(Renum *self);

void init_r (void *_self, char* names, uint32_t len);
uint32_t len_r (void *_self);

bool is_r (void *_self, uint32_t aRenum);
bool all_r (void *_self, uint32_t size, ...);
bool any_r (void *_self, uint32_t size, ...);

void set_r (void *_self, uint32_t aRenum);
void set_all_r (void *_self, uint32_t size, ...);

void reset_r (void *_self, uint32_t aRenum);
void reset_all_r (void *_self, uint32_t size, ...);


