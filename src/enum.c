#ifndef ENUM_H
#define ENUM_H
#include "enum.h"
#endif

Enum *new_e (char *names, uint32_t len) {
    Enum *anEnum = malloc(sizeof(Enum));
    init_e (anEnum, names, len);
    return anEnum;
}

void del_e (void* _self) {
    Enum *self = (Enum *) _self;
    free(self);
}

void init_e (void* _self, char *names, uint32_t len) {
    Enum *self = (Enum *) _self;
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

char *getNames_e (void* _self) {
    Flag *self = (Flag *) _self;
    return self->getNames(self);
}

void setNames_e (void *_self, char *newNames) {
    Flag *self = (Flag *) _self;
    self->setNames(self, newNames);
}

uint32_t len_e (void *_self) {
    Enum *self = (Enum *) _self;
    return self->__len;
}

uint32_t get_e (void* _self) {
    Flag *self = (Flag *) _self;
    return self->get(self);
}

bool is_e (void* _self, uint32_t anEnum) {
    Flag *self = (Flag *) _self;
    uint32_t n = self->is(self, 1 << anEnum);
    return ((n | (~n + 1)) >> 31) & 1;
}

void set_e (void* _self, uint32_t anEnum) {
    Flag *self = (Flag *) _self;
    self->set(self, 1 << anEnum);
}

void reset_e (void* _self, uint32_t anEnum) {
    Flag *self = (Flag *) _self;
    self->reset(self, 1 << anEnum);
}

void print_e(void* _self) {
    Enum* self = (Enum* ) _self;
    uint32_t res = self->get(self);
    char *names = self->getNames(self);
    print(res, names ,self->__len);
}
