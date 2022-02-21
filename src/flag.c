#include "flag.h"

Flag *new_f () {
    Flag *aFlag = malloc(sizeof(Flag));
    init_f(aFlag);
    return aFlag;
}

void init_f(Flag *self) {
    *self = (Flag) {
        .__flags = 0,
        .init = init_f,
        .get = get_f,
        .is = is_f,
        .set = set_f,
        .reset = reset_f,
        .print = print_f
    };
}

void del_f(Flag *self) {
    free(self);
}

uint32_t get_f(Flag* self) {
    return self->__flags;
}

bool is_f(Flag *self, uint32_t aFlag) {
    return self->get(self) & aFlag;
}

void set_f (Flag* self, uint32_t aFlag) {
    self->__flags |= aFlag;
}

void reset_f (Flag* self, uint32_t aFlag) {
    uint32_t flag = self->get(self);
    flag &= ~aFlag;
    self->init(self);
    self->set(self, flag);
}

void print_f(Flag* self, char *names) {
    uint32_t res = self->get(self);
    uint32_t len = 32;
    print(res, len, names);
}
