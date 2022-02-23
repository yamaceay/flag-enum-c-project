#ifndef RENUM_H
#define RENUM_H
#include "renum.h"
#endif

Renum *new_r (char *names, uint32_t len) {
    Renum *aRenum = malloc(sizeof(Renum));
    init_r (aRenum, names, len);
    return aRenum;
}

void del_r (Renum* self) {
    free(self);
}

void init_r (void *_self, char *names, uint32_t len) {
    Renum *self = (Renum *) _self;
    Flag flag;
    init_f(&flag, names);
    *self = (Renum) {
        .flag = flag,
        .__len = len,
        .getNames = getNames_r,
        .setNames = setNames_r,
        .init = init_r,
        .get = get_r,
        .all = all_r,
        .any = any_r,
        .set = set_r,
        .reset = reset_r,
        .print = print_r
    };
}

char *getNames_r (void *_self) {
    Flag *self = (Flag *) _self;
    return self->getNames(self);
}

void setNames_r (void *_self, char *newNames) {
    Flag *self = (Flag *) _self;
    self->setNames(self, newNames);
}

uint32_t len_r (void *_self) {
    Renum *self = (Renum *) _self;
    return self->__len;
}

uint32_t get_r (void *_self) {
    Flag *self = (Flag *) _self;
    return self->get(self);
}

bool all_r (void *_self, uint32_t *renums, uint32_t renums_len) {
    Flag *self = (Flag *) _self;
    for (int i = 0; i < renums_len; i++) {
        if (~self->is(self, 1 << renums[i])) return false;
    }
    return true;    
}

bool any_r (void *_self, uint32_t *renums, uint32_t renums_len) {
    Flag *self = (Flag *) _self;
    for (int i = 0; i < renums_len; i++) {
        if (self->is(self, 1 << renums[i])) return true;
    }
    return false;    
}

void set_r (void *_self, uint32_t *renums, uint32_t renums_len) {
    Flag *self = (Flag *) _self;
    for (int i = 0; i < renums_len; i++) {
        self->set(self, 1 << renums[i]);
    }
}

void reset_r (void *_self, uint32_t *renums, uint32_t renums_len) {
    Flag *self = (Flag *) _self;
    for (int i = 0; i < renums_len; i++) {
        self->reset(self, 1 << renums[i]);
    }
}
    
void print_r(void *_self) {
    Renum* self = (Renum *)_self;
    uint32_t res = self->get(self);
    char *names = self->getNames(self);
    print(res, names ,self->__len);
}