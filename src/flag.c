#include "flag.h"

Flag *new_f () {
    Flag *aFlag = malloc(sizeof(Flag));
    init_f(aFlag);
    return aFlag;
}

void init_f(Flag *self) {
    *self = (Flag) {
        .__flags = 0,
        .init_f = init_f,
        .get_f = get_f,
        .isSet_f = isSet_f,
        .set_f = set_f,
        .reset_f = reset_f,
    };
}

void del_f(Flag *self) {
    free(self);
}

uint32_t get_f(Flag* self) {
    return self->__flags;
}

bool isSet_f(Flag *self, uint32_t aFlag) {
    return self->get_f(self) & aFlag;
}

void set_f (Flag* self, uint32_t aFlag) {
    self->__flags |= aFlag;
}

void reset_f (Flag* self, uint32_t aFlag) {
    uint32_t flag = self->get_f(self);
    flag &= ~aFlag;
    self->init_f(self);
    self->set_f(self, flag);
}
