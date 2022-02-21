#include "flag.h"
#define BUF 100

typedef struct Enum Enum;

Enum* new_e (uint32_t num);
void del_e (Enum* self);

void init_e (Enum* self, uint32_t len);
uint32_t len_e (Enum* self);
uint32_t get_e (Enum* self);
bool is_e (Enum* self, uint32_t aFlag);
void set_e (Enum* self, uint32_t anEnum); 
void set_all_e (Enum* self, void *enums, uint32_t enums_len);
void reset_e (Enum* self, uint32_t anEnum);
void reset_all_e (Enum *self, void *enums, uint32_t enums_len);
void print_e(Enum* self, char *names);

typedef struct Enum {
    Flag flag;
    uint32_t __len;

    void (*init) (Enum* self, uint32_t len);
    uint32_t (*len) (Enum* self);
    uint32_t (*get) (Enum* self);
    bool (*is) (Enum* self, uint32_t anEnum);
    void (*set) (Enum* self, uint32_t anEnum);
    void (*set_all) (Enum* self, void *enums, uint32_t enums_len); 
    void (*reset) (Enum* self, uint32_t anEnum);
    void (*reset_all) (Enum* self, void *enums, uint32_t enums_len);
    void (*print) (Enum* self, char *names);
} Enum;