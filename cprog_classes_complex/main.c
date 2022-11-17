//
// Created by nimab on 11/17/22.
//
#include <stdint.h>
#include <stdlib.h>

typedef void (*FuncPointer)();


typedef enum type {
    INT8,
    INT16,
    INT32,
    INT64,
    CHAR
} Type;

typedef struct var {
    Type var_type;
    void *val;

} Variable;

typedef struct class {
    void *vars;
    uint16_t num_vars;
    void *methods;
    uint8_t num_methods;
} Object;

Object *create_new_object(
        Variable *vars,
        uint16_t num_vars,
        FuncPointer *methods,
        uint8_t num_methods) {

    Object *new_object = (Object *)malloc(sizeof(Object));

    new_object->vars = vars;
    new_object->num_vars = num_vars;
    new_object->methods = methods;
    new_object->num_methods = num_methods;
    return new_object;
}

int main(void) {
    return 0;
}