#include "renum.h"

Renum *new_r (char *names, uint32_t len) {
    Renum *aRenum = malloc(sizeof(Renum));
    init_r (aRenum, names, len);
    return aRenum;
}

void del_r (Renum* self) {
    free(self);
}

void init_r (Renum* self, char *names, uint32_t len) {
    Flag flag;
    init_f(&flag, names);
    *self = (Renum) {
        .flag = flag,
        .__len = len,
        .getNames = getNames_r,
        .setNames = setNames_r,
        .init = init_r,
        .get = get_r,
        .is = is_r,
        .set = set_r,
        .reset = reset_r,
        .is_all = is_all_r,
        .is_any = is_any_r,
        .set_all = set_all_r,
        .reset_all = reset_all_r,
        .print = print_r
    };
}

char *getNames_r (Renum *self) {
    Flag *flag = (Flag *) self;
    return flag->getNames(flag);
}

void setNames_r (Renum *self, char *newNames) {
    Flag *flag = (Flag* ) self;
    flag->setNames(flag, newNames);
}

uint32_t len_r (Renum *self) {
    return self->__len;
}

uint32_t get_r (Renum* self) {
    Flag* flag = (Flag*) self;
    return flag->get(flag);
}

bool is_r (Renum *self, uint32_t aRenum) {
    Flag* flag = (Flag*) self;
    return flag->is(flag, 1 << aRenum);
}

void set_r (Renum* self, uint32_t aRenum) {
    Flag* flag = (Flag*) self;
    flag->set(flag, 1 << aRenum);
}

void reset_r (Renum* self, uint32_t aRenum) {
    Flag* flag = (Flag*) self;
    flag->reset(flag, 1 << aRenum);
}

bool is_all_r (Renum *self, void *renums, uint32_t renums_len) {
    uint32_t *renums_int = (uint32_t *) renums;
    for (int i = 0; i < renums_len; i++) {
        if (~self->is(self, renums_int[i])) return false;
    }
    return true;
}

bool is_any_r (Renum *self, void *renums, uint32_t renums_len) {
    uint32_t *renums_int = (uint32_t *) renums;
    for (int i = 0; i < renums_len; i++) {
        if (self->is(self, renums_int[i])) return true;
    }
    return false;
}

void set_all_r (Renum* self, void *renums, uint32_t renums_len) {
    uint32_t *renums_int = (uint32_t *) renums;
    for (int i = 0; i < renums_len; i++) {
        self->set(self, renums_int[i]);
    }
}

void reset_all_r (Renum *self, void *renums, uint32_t renums_len) {
    uint32_t *renums_int = (uint32_t *) renums;
    for (int i = 0; i < renums_len; i++) {
        self->reset(self, renums_int[i]);
    }
}
    
void print_r(Renum* self) {
    uint32_t res = self->get(self);
    char *names = self->getNames(self);
    print(res, names ,self->__len);
}