#include <stdlib.h>
#include <string.h>
#include "vector.h"
#include "utility.h"

void swap(void* a, void* b, size_t size) {
    byte* tmp = (byte*)malloc(size);

    memmove(tmp, a, size);
    memmove(a, b, size);
    memmove(b, tmp, size);

    free(tmp);
}

size_t min(size_t a, size_t b) {
    return (a < b ? a : b);
}
size_t max(size_t a, size_t b) {
    return (a > b ? a : b);
}



size_t edit_distance(vector* first, vector* second) {
    if (first->size == 0)
        return second->size;
    if (second->size == 0)
        return first->size;

    size_t infinity = 0x3f3f3f3f;
    // матрицу dp[(N + 2) x (M + 2)] выразим по последним двум строкам длиной (M + 2)
    vector dp[2];
    for (size_t i = 0; i < 2; ++i) {

        init(&dp[i], sizeof(size_t));

        // second->size + 2, т.к. считаем по второй строке с нулевого до M+1 символа
        resize(&dp[i], second->size + 2);
        memset(dp[i].buffer, infinity, dp[i].size * dp[i].sizeof_elem);
    }

    char* first_string = (char*)first->buffer;
    char* second_string = (char*)second->buffer;

    size_t* current = (size_t*)dp[0].buffer;
    size_t* next = (size_t*)dp[1].buffer;

    current[0] = 0;

    for (size_t i = 0; i <= first->size; ++i) {
        for (size_t j = 0; j <= second->size; ++j) {
            if (first_string[i] == second_string[j]) {
                // здесь и внизу везде стоят j (НЕ i), проверил
                next[j + 1]    = min(next[j + 1],    current[j]);
            }
            else {
                next[j + 1]    = min(next[j + 1],    current[j] + 1);
                next[j]        = min(next[j],        current[j] + 1);
                current[j + 1] = min(current[j + 1], current[j] + 1);
            }
        }
        // dp[0] и dp[1] не изменяются в процессе, поэтому так можно
        swap(&current, &next, sizeof(current));
        // dp[0].size * dp[0].sizeof_elem === dp[1].size * dp[1].sizeof_elem, т.к. не изменяются по длине
        memset(next, infinity, dp[0].size * dp[0].sizeof_elem);
    }

    // current[M + 1] == dp[N + 1][M + 1]
    size_t result = current[second->size + 1];

    for (size_t i = 0; i < 2; ++i) {
        del(&dp[i]);
    }

    return result;
}