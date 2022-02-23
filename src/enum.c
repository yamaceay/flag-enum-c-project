#include "enum.h"

Enum *new_e (char *names, uint32_t len) {
    Enum *anEnum = malloc(sizeof(Enum));
    init_e (anEnum, names, len);
    return anEnum;
}

void del_e (Enum* self) {
    free(self);
}

void init_e (Enum* self, char *names, uint32_t len) {
    Flag flag;
    init_f(&flag, names);
    *self = (Enum) {
        .flag = flag,
        .__len = len,
        .getNames = getNames_e,
        .setNames = setNames_e,
        .init = init_e,
        .get = get_e,
        .is = is_e,
        .set = set_e,
        .reset = reset_e,
        .print = print_e
    };
}

char *getNames_e (Enum *self) {
    Flag *flag = (Flag *) self;
    return flag->getNames(flag);
}

void setNames_e (Enum *self, char *newNames) {
    Flag *flag = (Flag* ) self;
    flag->setNames(flag, newNames);
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
    uint32_t n = flag->is(flag, 1 << anEnum);
    return ((n | (~n + 1)) >> 31) & 1;
}

void set_e (Enum* self, uint32_t anEnum) {
    Flag* flag = (Flag*) self;
    flag->set(flag, 1 << anEnum);
}

void reset_e (Enum* self, uint32_t anEnum) {
    Flag* flag = (Flag*) self;
    flag->reset(flag, 1 << anEnum);
}

void print_e(Enum* self) {
    uint32_t res = self->get(self);
    char *names = self->getNames(self);
    print(res, names ,self->__len);
}
