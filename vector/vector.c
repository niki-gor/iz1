#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "vector.h"

void reserve(vector* vec, size_t size) {
    if (size <= vec->buf_size) {
        return;
    }
    byte* new_buf = realloc(vec->buf, size * vec->sizeof_elem);
    if (!new_buf) {
        fprintf(stderr, "Failed to allocate the memory");
        free(vec->buf);
    }
    vec->buf = new_buf;
    vec->buf_size = size;
}

void push_back(vector* vec, void* val_ptr) {
    if (vec->usr_size == vec->buf_size) {
        reserve(vec, vec->buf_size * 3 / 2 + 1);
    }
    memmove(vec->buf + vec->usr_size * vec->sizeof_elem, val_ptr, vec->sizeof_elem);
    ++vec->usr_size;
}

void resize(vector* vec, size_t size) {
    if (size > vec->buf_size) {
        reserve(vec, size);
        vec->buf_size = size;
    }
    vec->usr_size = size;
}

void init(vector* vec, size_t sizeof_element) {
    vec->buf = NULL;
    vec->usr_size = 0;
    vec->buf_size = 0;
    vec->sizeof_elem = sizeof_element;
}

void del(vector* vec) {
    if (vec->buf) {
        free(vec->buf);
        vec->usr_size = 0;
        vec->buf_size = 0;
        vec->sizeof_elem = 0;
    }
}

void* at(vector* vec, size_t index) {
    if (index > vec->usr_size) {
        fprintf(stderr, "Index out of range");
    }
    return (void*)(vec->buf + index * vec->sizeof_elem);
}