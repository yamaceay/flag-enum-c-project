#ifndef FLAG_H
#define FLAG_H
#include "flag.h"
#endif

/**
 * @brief Creates a new Flag instance
 * 
 * @param names Names of flags (optional)
 * @return Flag* Flag pointer
 */
Flag *new_f (char *names) {
    Flag *aFlag = malloc(sizeof(Flag));
    init_f(aFlag, names);
    return aFlag;
}

/**
 * @brief Initializes the Flag instance
 * 
 * @param _self Flag instance 
 * @param names Names given
 */
void init_f(void *_self, char *names) {
    Flag *self = (Flag *) _self;
    *self = (Flag) {
        .__flags = 0,
        .names = names_f,
        .set_names = set_names_f,
        .init = init_f,
        .get = get_f,
        .is = is_f,
        .set = set_f,
        .reset = reset_f,
        .print = print_f
    };
    self->set_names(self, names);
}

/**
 * @brief Getter for __names attribute 
 * of Flag instance
 * 
 * @param _self Flag instance
 * @return char* Names
 */
char *names_f (void *_self) {
    Flag *self = (Flag *) _self;
    return self->__names;
}

/**
 * @brief Setter for __names attribute
 * of Flag instance
 * 
 * @param _self Flag instance
 * @param newNames New names
 */
void set_names_f (void *_self, char *newNames) {
    Flag *self = (Flag *) _self;
    memcpy(self->__names, newNames, strlen(newNames));
    self->__names[strlen(newNames)] = 0;
}

/**
 * @brief Clears the memory of Flag instance
 * 
 * @param _self Flag instance
 */
void del_f(void *_self) {
    Flag *self = (Flag *) _self;
    free(self);
}

/**
 * @brief Getter for __flags attribute
 * of Flag instance
 * 
 * @param _self Flag instance
 * @return uint32_t Flag value
 */
uint32_t get_f(void* _self) {
    Flag *self = (Flag *) _self;
    return self->__flags;
}

/**
 * @brief Checks if given flag value is
 * contained in Flag instance
 * 
 * @param _self Flag instance
 * @param aFlag Flag value
 * @return bool true if yes else false
 */
bool is_f(void *_self, uint32_t aFlag) {
    Flag *self = (Flag *) _self;
    return self->get(self) & aFlag;
}

/**
 * @brief Adds the flag value to the
 * Flag instance
 * 
 * @param _self Flag instance
 * @param aFlag Flag value
 */
void set_f (void* _self, uint32_t aFlag) {
    Flag *self = (Flag *) _self;
    self->__flags |= aFlag;
}

/**
 * @brief Removes the flag value from the
 * Flag instance
 * 
 * @param _self Flag instance
 * @param aFlag Flag value
 */
void reset_f (void* _self, uint32_t aFlag) {   
    Flag *self = (Flag *) _self;
    uint32_t flag = self->get(self);
    char *names = strdup(self->names(self));
    flag &= ~aFlag;
    self->init(self, names);
    self->set(self, flag);
}

/**
 * @brief Pretty-prints the Flag instance
 * 
 * @param _self Flag instance
 */
void print_f(void* _self) {
    Flag *self = (Flag *) _self;
    uint32_t res = self->get(self);
    char *names = self->names(self);
    uint32_t len = 32;
    _print(res, names, len);
}
