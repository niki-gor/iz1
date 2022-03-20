#include "str.h"



void str_reserve(string s, size_t new_capacity) {
    if (new_capacity <= s->capacity) {
        return;
    }
    char* new_data = (char*)realloc(s->data, new_capacity);
    if (!new_data) {
        fprintf(stderr, "Failed to allocate the memory");
        free(s->data);
    }
    s->data = new_data;
    s->capacity = new_capacity;
}

void str_push_back(string s, char c) {
    if (s->size == s->capacity) {
        str_reserve(s, s->capacity * 3 / 2 + 1);
    }
    s->data[s->size++] = c;
}

void str_resize(string s, size_t new_size) {
    if (new_size > s->capacity) {
        str_reserve(s, new_size);
        s->capacity = new_size;
    }
    s->size = new_size;
}

void str_init(string s) {
    s = (string)malloc(sizeof(string_struct));
    s->data = NULL;
    s->size = 0;
    s->capacity = 0;
}

void str_del(string s) {
    if (s->data) {
        free(s->data);
    }
    free(s);
}

// считается, что строки a и b заканчиваются нулем
string concat(string a, string b) {
    string result = malloc(sizeof(string_struct));
    str_init(result);
    str_resize(result, a->size + b->size - 1);
    strcpy(result->data, a->data);
    strcpy(result->data + a->size - 1, b->data);
    return result;
}

// считается, что строки a и b заканчиваются нулем
string join(string a, string b) {
    size_t old_size = a->size;
    str_resize(a, a->size + b->size - 1);
    strcpy(a->data + old_size - 1, b->data);
    str_del(b);
    return a;
}

string str(const char* s) {
    string result = (string)malloc(sizeof(string_struct));
    str_init(result);
    str_resize(result, strlen(s) + 1);
    strcpy(result->data, s);
    return result;
}

char* at(string s, size_t index) {
    return s->data + index;
}

void print(string s) {
    fprintf(stdout, "%s", s->data);
}

string input() {
    string result = (string)malloc(sizeof(string_struct));
    char c;
    while (fscanf(stdin, "%c", &c) != EOF && c != '\n') {
        str_push_back(result, c);
    }
    return result;
}