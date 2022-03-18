#include <stdio.h>
#include <string.h>
#include "vector.h"
#include "parser.h"

void main() {
    vector first = *concat_and_del(str2vec("Hello "), str2vec("world"));

    fprintf(stdout, "%s", first.buffer);

    vector second = *str2vec("Lllololol");

    fprintf(stdout, "%d\n", edit_distance(first.buffer, second.buffer));
    
    del(&first);
    del(&second);
}