#ifndef STR_H
#define STR_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>



typedef struct string_struct string_struct;
typedef string_struct* string;
struct string_struct {
    char* data;
    size_t size;
    size_t capacity;
};

void str_reserve(string s, size_t new_capacity);
void str_push_back(string s, char c);
void str_resize(string s, size_t new_size);
void str_init(string s);
void str_del(string s);

string concat(string a, string b);
string join(string a, string b);
string str(const char* s);
char* at(string s, size_t index);
void print(string s);
string input();
//vector split(string s, char delim);



#endif