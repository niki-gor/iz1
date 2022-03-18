#include <stdio.h>
#include "vector.h"
#include <string.h>

void main() {
    const char* str1 = "Hello";
    const char* str2 = "hello";

    vector first;
    init(&first, sizeof(char));
    resize(&first, sizeof(str1));

    vector second;
    init(&second, sizeof(char));
    resize(&second, sizeof(str2));

    strcpy(first.buffer, str1);
    strcpy(second.buffer, str2);

    fprintf(stdout, "%d\n", edit_distance(&first, &second));
    
    del(&first);
    del(&second);
}