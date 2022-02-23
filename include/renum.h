#ifndef FLAG_H
#define FLAG_H
#include "flag.h"
#endif

typedef struct _Renum Renum;
typedef struct _Renum {
    Flag flag;
    uint32_t __len;
    
    char* (*getNames) (void *_self);
    void (*setNames) (void *_self, char *newNames);

    void (*init) (void *_self, char *names, uint32_t len);
    uint32_t (*len) (void *_self);
    uint32_t (*get) (void *_self);

    bool (*all) (void *_self, uint32_t *renums, uint32_t renums_len);
    bool (*any) (void *_self, uint32_t *renums, uint32_t renums_len);
    void (*set) (void *_self, uint32_t *renums, uint32_t renums_len);
    void (*reset) (void *_self, uint32_t *renums, uint32_t renums_len);
    
    void (*print) (void *_self);
} Renum;

Renum* new_r (char *names, uint32_t len);
void del_r(Renum *self);

char* getNames_r (void *_self);
void setNames_r (void *_self, char *newNames);

void init_r (void *_self, char* names, uint32_t len);
uint32_t len_r (void *_self);
uint32_t get_r (void *_self);

bool all_r (void *_self, uint32_t *renums, uint32_t renums_len);
bool any_r (void *_self, uint32_t *renums, uint32_t renums_len);
void set_r (void *_self, uint32_t *renums, uint32_t renums_len);
void reset_r (void *_self, uint32_t *renums, uint32_t renums_len);

void print_r(void *_self);

