#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "types.h"

typedef struct vector vector;
struct vector {
    byte* buffer;
    size_t size;
    size_t capacity;
    size_t sizeof_elem;
};

void init(vector* vec, size_t sizeof_element);

void reserve(vector* vec, size_t new_capacity);
void push_back(vector* vec, void* val_ptr);
void resize(vector* vec, size_t new_size);
vector* str2vec(char* str);
vector* concat_and_del(vector* a, vector* b);

void del(vector* vec);

#endif