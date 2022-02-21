#include "flag.h"

Flag *new_f (char *names) {
    Flag *aFlag = malloc(sizeof(Flag));
    init_f(aFlag, names);
    return aFlag;
}

void init_f(Flag *self, char *names) {
    *self = (Flag) {
        .__flags = 0,
        .getNames = getNames_f,
        .setNames = setNames_f,
        .init = init_f,
        .get = get_f,
        .is = is_f,
        .set = set_f,
        .reset = reset_f,
        .print = print_f
    };
    self->setNames(self, names);
}

char *getNames_f (Flag *self) {
    return self->__names;
}

void setNames_f (Flag *self, char *newNames) {
    memcpy(self->__names, newNames, strlen(newNames));
    self->__names[strlen(newNames)] = 0;
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
    char *names = strdup(self->getNames(self));
    flag &= ~aFlag;
    self->init(self, names);
    self->set(self, flag);
}

void print_f(Flag* self) {
    uint32_t res = self->get(self);
    char *names = self->getNames(self);
    uint32_t len = 32;
    print(res, names, len);
}
