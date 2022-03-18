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

vector* str2vec(char* str) {
    vector* result = (vector*)malloc(sizeof(vector));
    init(result, sizeof(char));
    resize(result, strlen(str) + 1);
    strcpy(result->buffer, str);
    return result;
}

// считается, что строки a и b заканчиваются нулем
vector* concat_and_del(vector* a, vector* b) {
    size_t old_size = a->size;
    resize(a, a->size + b->size - 1);
    memmove(a->buffer + old_size - 1, b->buffer, b->size);
    del(b);
    return a;
}