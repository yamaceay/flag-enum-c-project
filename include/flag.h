#include "bool.h"

typedef struct Flag Flag;

Flag* new_f ();
void del_f (Flag* self);

void init_f (Flag* self);
uint32_t get_f (Flag* self);
bool isSet_f (Flag* self, uint32_t aFlag);
void set_f (Flag* self, uint32_t aFlag);
void reset_f (Flag* self, uint32_t aFlag);

typedef struct Flag {
    uint32_t __flags;
    
    void (*init_f) (Flag* self);
    uint32_t (*get_f) (Flag* self);
    bool (*isSet_f) (Flag* self, uint32_t aFlag);
    void (*set_f) (Flag* self, uint32_t aFlag);
    void (*reset_f) (Flag* self, uint32_t aFlag);

} Flag;