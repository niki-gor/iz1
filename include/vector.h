#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "types.h"



typedef struct vector_struct vector_struct;
typedef vector_struct* vector;
struct vector_struct {
    byte* buffer;
    size_t size;
    size_t capacity;
    size_t sizeof_elem;
};

void vec_init(vector vec, size_t sizeof_element);

void vec_reserve(vector vec, size_t new_capacity);
void vec_push_back(vector vec, void* val_ptr);
void vec_resize(vector vec, size_t new_size);

void vec_del(vector vec);

#endif