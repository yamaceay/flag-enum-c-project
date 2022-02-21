#include "bool.h"

typedef struct Flag Flag;

Flag* new_f ();
void del_f (Flag* self);

void init_f (Flag* self);
uint32_t get_f (Flag* self);
bool is_f (Flag* self, uint32_t aFlag);
void set_f (Flag* self, uint32_t aFlag);
void reset_f (Flag* self, uint32_t aFlag);
void print_f (Flag* self, char *names);

typedef struct Flag {
    uint32_t __flags;

    void (*init) (Flag* self);
    uint32_t (*get) (Flag* self);
    bool (*is) (Flag* self, uint32_t aFlag);
    void (*set) (Flag* self, uint32_t aFlag);
    void (*reset) (Flag* self, uint32_t aFlag);
    void (*print) (Flag* self, char *names);

} Flag;