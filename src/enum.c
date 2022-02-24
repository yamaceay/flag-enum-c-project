#ifndef ENUM_H
#define ENUM_H
#include "enum.h"
#endif

/**
 * @brief Creates a new Enum instance 
 * 
 * @param names Names (optional)
 * @param len Length of enum
 * @return Enum* Enum instance
 */
Enum *new_e (char *names, uint32_t len) {
    Enum *anEnum = malloc(sizeof(Enum));
    init_e (anEnum, names, len);
    return anEnum;
}

/**
 * @brief Delete Enum instance
 * 
 * @param _self Enum instance
 */
void del_e (void* _self) {
    Enum *self = (Enum *) _self;
    free(self);
}

/**
 * @brief Initializes Enum instance given
 * names and length of enum
 * 
 * @param _self Enum instance
 * @param names Names 
 * @param len Length
 */
void init_e (void* _self, char *names, uint32_t len) {
    Enum *self = (Enum *) _self;
    Flag flag;
    init_f(&flag, names);
    *self = (Enum) {
        .flag = flag,
        .__len = len,
        .getNames = getNames_f,
        .setNames = setNames_f,
        .print = print_f,
        .get = get_f,
        .init = init_e,
        .is = is_e,
        .set = set_e,
        .reset = reset_e
    };
}

/**
 * @brief Getter for __len attribute
 * of Enum instance
 * 
 * @param _self Enum instance
 * @return uint32_t Length
 */
uint32_t len_e (void *_self) {
    Enum *self = (Enum *) _self;
    return self->__len;
}

/**
 * @brief Checks if an enum variable matches
 * one of the flags
 * 
 * @param _self Enum instance
 * @param anEnum Enum variable
 * @return bool true if yes else false
 */
bool is_e (void* _self, uint32_t anEnum) {
    Flag *self = (Flag *) _self;
    uint32_t n = self->is(self, 1 << anEnum);
    return ((n | (~n + 1)) >> 31) & 1;
}

/**
 * @brief Adds the enum variable to 
 * the Enum instance
 * 
 * @param _self Enum instance
 * @param anEnum Enum variable
 */
void set_e (void* _self, uint32_t anEnum) {
    Flag *self = (Flag *) _self;
    self->set(self, 1 << anEnum);
}

/**
 * @brief Removes the enum variable from 
 * the Enum instance
 * 
 * @param _self Enum instance
 * @param anEnum Enum variable
 */
void reset_e (void* _self, uint32_t anEnum) {
    Flag *self = (Flag *) _self;
    self->reset(self, 1 << anEnum);
}
