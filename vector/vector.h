#ifndef VECTOR_H
#define VECTOR_H

typedef unsigned char byte;
typedef struct vector vector;
struct vector {
    byte* buf;
    size_t usr_size;
    size_t buf_size;
    size_t sizeof_elem;
};

void init(vector* vec, size_t sizeof_element);

void reserve(vector* vec, size_t size);
void push_back(vector* vec, void* val_ptr);
void resize(vector* vec, size_t new_size);
void* at(vector* vec, size_t index);

void del(vector* vec);

#endif