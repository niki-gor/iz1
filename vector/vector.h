#ifndef VECTOR_H
#define VECTOR_H

typedef unsigned char byte;

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

void del(vector* vec);

#endif