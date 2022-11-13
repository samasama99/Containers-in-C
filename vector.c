#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef ITERATOR
#define ITERATOR
#include "iterator.c"
#endif

typedef struct vector vector;
typedef int Type;

struct vector {
    begin_func* _begin;
    end_func* _end;
    size_t size;
    size_t capacity;
    Type* arr;
};

void vector_next_func(iterator* iter) {
    iter->current = (Type*)iter->current + 1;
}

Type* vector_get_func(iterator* iter) {
    return iter->current;
}

iterator vector_begin(void* current) {
    return (iterator){
        ((vector*)current)->arr,
        vector_next_func,
        vector_get_func,
    };
}

iterator vector_end(void* current) {
    return (iterator){
        ((vector*)(current))->arr + ((vector*)(current))->size,
        vector_next_func,
        vector_get_func,
    };
}

vector init_vector(size_t capacity) {
    Type* arr = malloc(sizeof(Type) * capacity);
    assert(arr != NULL);
    return (vector){
        vector_begin, vector_end, 0, capacity, arr,
    };
}

void realloc_vector(vector* vec, size_t new_capacity) {
    vec->capacity = new_capacity;
    Type* arr = malloc(sizeof(Type) * new_capacity);
    memcpy(arr, vec->arr, new_capacity);
    free(vec->arr);
    vec->arr = arr;
}

void push_back(vector* vec, Type value) {
    assert(vec != NULL);
    if (vec->size == vec->capacity) {
        realloc_vector(vec, vec->capacity * 2);
    }
    vec->arr[vec->size++] = value;
}

Type pop_back(vector* vec) {
    assert(vec != NULL);
    return vec->arr[--vec->size];
}

Type get(const vector* v, size_t index) {
    assert(v != NULL);
    assert(index < v->size);
    return v->arr[index];
}

// int main() {
//     vector vec = init_vector(0);
//     push_back(&vec, 1);
//     push_back(&vec, 2);
//     push_back(&vec, 3);
//     push_back(&vec, 4);
//     push_back(&vec, 5);
//     push_back(&vec, 6);
//     push_back(&vec, 7);
//     push_back(&vec, 8);
//     for (size_t i = 0; i < vec.size; ++i) {
//         printf("index %zu value %d\n", i, get(&vec, i));
//     }
//     while (vec.size) {
//         printf("value %d\n", pop_back(&vec));
//     }
// }
