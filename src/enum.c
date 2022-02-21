#include "enum.h"

Enum *new_e (uint32_t len) {
    Enum *anEnum = malloc(sizeof(Enum));
    init_e (anEnum, len);
    return anEnum;
}

void del_e (Enum* self) {
    free(self);
}

void init_e (Enum* self, uint32_t len) {
    Flag flag;
    init_f(&flag);
    *self = (Enum) {
        .flag = flag,
        .__len = len,
        .init = init_e,
        .get = get_e,
        .is = is_e,
        .set = set_e,
        .set_all = set_all_e,
        .reset = reset_e,
        .reset_all = reset_all_e,
        .print = print_e
    };
}

uint32_t len_e (Enum *self) {
    return self->__len;
}

uint32_t get_e (Enum* self) {
    Flag* flag = (Flag*) self;
    return flag->get(flag);
}

bool is_e (Enum *self, uint32_t anEnum) {
    Flag* flag = (Flag*) self;
    return flag->is(flag, 1 << anEnum);
}

void set_e (Enum* self, uint32_t anEnum) {
    Flag* flag = (Flag*) self;
    flag->set(flag, 1 << anEnum);
}

void set_all_e (Enum* self, void *enums, uint32_t enums_len) {
    uint32_t *enums_int = (uint32_t *) enums;
    for (int i = 0; i < enums_len; i++) {
        self->set(self, enums_int[i]);
    }
}

void reset_e (Enum* self, uint32_t anEnum) {
    Flag* flag = (Flag*) self;
    flag->reset(flag, 1 << anEnum);
}

void reset_all_e (Enum *self, void *enums, uint32_t enums_len) {
    uint32_t *enums_int = (uint32_t *) enums;
    for (int i = 0; i < enums_len; i++) {
        self->reset(self, enums_int[i]);
    }
}
    
void print_e(Enum* self, char *names) {
    uint32_t res = self->get(self);
    print(res, self->__len, names);
}