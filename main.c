#include <stdio.h>
#include "vector.h"

void main() {
    vector vec;
    init(&vec, sizeof(size_t));

    for (size_t i = 0; i < 100; ++i) {
        push_back(&vec, &i);
    }
    for (size_t i = 0; i < 100; ++i) {
        fprintf(stdout, "%d ", *(size_t*)at(&vec, i));
    }

    fprintf(stdout, "%d", vec.buf_size);
    
    del(&vec);
}