#include "flag.h"

typedef struct Enum Enum;

Enum* new_e (uint32_t num);
void del_e (Enum* self);

void init_e (Enum* self, uint32_t len);
uint32_t get_e (Enum* self);
bool isSet_e (Enum* self, uint32_t aFlag);
void set_e (Enum* self, uint32_t anEnum); 
void reset_e (Enum* self, uint32_t anEnum);

typedef struct Enum {
    Flag flag;
    uint32_t len;

    void (*init_e) (Enum* self, uint32_t len);
    uint32_t (*get_e) (Enum* self);
    bool (*isSet_e) (Enum* self, uint32_t anEnum);
    void (*set_e) (Enum* self, uint32_t anEnum); 
    void (*reset_e) (Enum* self, uint32_t anEnum);

} Enum;