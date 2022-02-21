#include "bool.h"

typedef struct Flag Flag;

Flag* new_f (char *names);
void del_f (Flag* self);

char *getNames_f(Flag *self);
void setNames_f(Flag *self, char *newNames);

void init_f (Flag* self, char *names);
uint32_t get_f (Flag* self);
bool is_f (Flag* self, uint32_t aFlag);
void set_f (Flag* self, uint32_t aFlag);
void reset_f (Flag* self, uint32_t aFlag);
void print_f (Flag* self);

typedef struct Flag {
    uint32_t __flags;
    char __names[BUF];

    char * (*getNames) (Flag *self);
    void (*setNames) (Flag *self, char *newNames);

    void (*init) (Flag* self, char *names);
    uint32_t (*get) (Flag* self);

    bool (*is) (Flag* self, uint32_t aFlag);
    void (*set) (Flag* self, uint32_t aFlag);
    void (*reset) (Flag* self, uint32_t aFlag);

    void (*print) (Flag* self);

} Flag;