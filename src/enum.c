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
    self->flag = flag;
    self->len = len;
    self->init_e = init_e;
    self->get_e = get_e;
    self->isSet_e = isSet_e;
    self->set_e = set_e;
    self->reset_e = reset_e;
}

uint32_t get_e (Enum* self) {
    Flag* flag = (Flag*) self;
    return flag->get_f(flag);
}

bool isSet_e (Enum *self, uint32_t anEnum) {
    Flag* flag = (Flag*) self;
    return flag->isSet_f(flag, 1 << anEnum);
}

void set_e (Enum* self, uint32_t anEnum) {
    Flag* flag = (Flag*) self;
    flag->set_f(flag, 1 << anEnum);
}

void reset_e (Enum* self, uint32_t anEnum) {
    Flag* flag = (Flag*) self;
    flag->reset_f(flag, 1 << anEnum);
}

