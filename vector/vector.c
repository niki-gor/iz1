#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "vector.h"

void reserve(vector* vec, size_t new_capacity) {
    if (new_capacity <= vec->capacity) {
        return;
    }
    byte* new_buffer = (byte*)realloc(vec->buffer, new_capacity * vec->sizeof_elem);
    if (!new_buffer) {
        fprintf(stderr, "Failed to allocate the memory");
        free(vec->buffer);
    }
    vec->buffer = new_buffer;
    vec->capacity = new_capacity;
}

void push_back(vector* vec, void* val_ptr) {
    if (vec->size == vec->capacity) {
        reserve(vec, vec->capacity * 3 / 2 + 1);
    }
    memmove(vec->buffer + vec->size * vec->sizeof_elem, val_ptr, vec->sizeof_elem);
    ++vec->size;
}

void resize(vector* vec, size_t new_size) {
    if (new_size > vec->capacity) {
        reserve(vec, new_size);
        vec->capacity = new_size;
    }
    vec->size = new_size;
}

void init(vector* vec, size_t sizeof_element) {
    vec->buffer = NULL;
    vec->size = 0;
    vec->capacity = 0;
    vec->sizeof_elem = sizeof_element;
}

void del(vector* vec) {
    if (vec->buffer) {
        free(vec->buffer);
        vec->size = 0;
        vec->capacity = 0;
        vec->sizeof_elem = 0;
    }
}