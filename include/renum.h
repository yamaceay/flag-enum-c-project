#include "flag.h"

typedef struct _Renum Renum;
typedef struct _Renum {
    Flag flag;
    uint32_t __len;
    
    char* (*getNames) (Renum *self);
    void (*setNames) (Renum *self, char *newNames);

    void (*init) (Renum* self, char *names, uint32_t len);
    uint32_t (*len) (Renum* self);
    uint32_t (*get) (Renum* self);
    
    bool (*is) (Renum* self, uint32_t aRenum);
    void (*set) (Renum* self, uint32_t aRenum);
    void (*reset) (Renum* self, uint32_t aRenum);
    
    bool (*is_all) (Renum* self, void *renums, uint32_t renums_len);
    bool (*is_any) (Renum* self, void *renums, uint32_t renums_len);
    void (*set_all) (Renum* self, void *renums, uint32_t renums_len);
    void (*reset_all) (Renum* self, void *renums, uint32_t renums_len);
    
    void (*print) (Renum* self);
} Renum;

Renum* new_r (char *names, uint32_t len);
void del_r(Renum *self);

char* getNames_r (Renum *self);
void setNames_r (Renum *self, char *newNames);

void init_r (Renum* self, char* names, uint32_t len);
uint32_t len_r (Renum* self);
uint32_t get_r (Renum* self);

bool is_r (Renum* self, uint32_t aFlag);
void set_r (Renum* self, uint32_t aRenum); 
void reset_r (Renum* self, uint32_t aRenum);

bool is_all_r (Renum* self, void *renums, uint32_t renums_len);
bool is_any_r (Renum* self, void *renums, uint32_t renums_len);
void set_all_r (Renum* self, void *renums, uint32_t renums_len);
void reset_all_r (Renum *self, void *renums, uint32_t renums_len);

void print_r(Renum* self);
