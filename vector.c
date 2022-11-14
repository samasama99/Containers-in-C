#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef ITERATOR
#define ITERATOR
#include "iterator.c"
#endif

#ifndef CONTAINER_ITERFACE
#define CONTAINER_ITERFACE
#include "container_iterface.c"
#endif

#define IMPORT_VECTOR_TYPE(Type)                                           \
                                                                           \
    typedef struct vector_##Type vector_##Type;                            \
                                                                           \
    typedef void(push_back_vector_##Type##_func)(vector_##Type * vec,      \
                                                 Type value);              \
                                                                           \
    typedef void(push_front_vector_##Type##_func)(vector_##Type * vec,     \
                                                  Type value);             \
                                                                           \
    typedef Type(get_vector_##Type##_func)(const vector_##Type* v,         \
                                           size_t index);                  \
                                                                           \
    typedef Type(pop_back_vector_##Type##_func)(vector_##Type * vec);      \
                                                                           \
    typedef Type(pop_front_vector_##Type##_func)(vector_##Type * vec);     \
                                                                           \
    struct vector_##Type {                                                 \
        begin_func* _begin;                                                \
        end_func* _end;                                                    \
        push_back_vector_##Type##_func* push_back_func;                    \
        pop_back_vector_##Type##_func* pop_back_func;                      \
        push_front_vector_##Type##_func* push_front_func;                  \
        pop_front_vector_##Type##_func* pop_front_func;                    \
        get_vector_##Type##_func* get_func;                                \
        size_t size;                                                       \
        size_t capacity;                                                   \
        Type* arr;                                                         \
    };                                                                     \
                                                                           \
    void vector_next_func_##Type(iterator* iter) {                         \
        iter->current = (Type*)iter->current + 1;                          \
    }                                                                      \
                                                                           \
    void* vector_get_func_##Type(iterator* iter) { return iter->current; } \
                                                                           \
    iterator vector_begin_##Type(void* current) {                          \
        return (iterator){                                                 \
            ((vector_##Type*)current)->arr,                                \
            vector_next_func_##Type,                                       \
            vector_get_func_##Type,                                        \
        };                                                                 \
    }                                                                      \
                                                                           \
    iterator vector_end_##Type(void* current) {                            \
        return (iterator){                                                 \
            ((vector_##Type*)(current))->arr +                             \
                ((vector_##Type*)(current))->size,                         \
            vector_next_func_##Type,                                       \
            vector_get_func_##Type,                                        \
        };                                                                 \
    }                                                                      \
                                                                           \
    void realloc_vector_##Type(vector_##Type* vec, size_t new_capacity) {  \
        Type* arr = malloc(sizeof(Type) * new_capacity);                   \
        memcpy(arr, vec->arr, vec->capacity);                              \
        vec->capacity = new_capacity;                                      \
        free(vec->arr);                                                    \
        vec->arr = arr;                                                    \
    }                                                                      \
                                                                           \
    void push_back_vector_##Type(vector_##Type* vec, Type value) {         \
        assert(vec != NULL);                                               \
        if (vec->size == vec->capacity) {                                  \
            if (vec->capacity == 0)                                        \
                realloc_vector_##Type(vec, 1);                             \
            else                                                           \
                realloc_vector_##Type(vec, vec->capacity * 2);             \
        }                                                                  \
        vec->arr[vec->size++] = value;                                     \
    }                                                                      \
                                                                           \
    Type pop_back_vector_##Type(vector_##Type* vec) {                      \
        assert(vec != NULL);                                               \
        return vec->arr[--vec->size];                                      \
    }                                                                      \
                                                                           \
    void push_front_vector_##Type(vector_##Type* vec, Type value) {        \
        puts("u cant push_front in  vector");                              \
        assert("u cant push_front in  vector");                            \
        (void)vec;                                                         \
        (void)value;                                                       \
    }                                                                      \
                                                                           \
    Type pop_front_vector_##Type(vector_##Type* vec) {                     \
        puts("u cant pop_front in  vector");                               \
        assert("u cant pop_front in  vector");                             \
        (void)vec;                                                         \
        exit(1);                                                           \
    }                                                                      \
                                                                           \
    Type get_vector_##Type(const vector_##Type* v, size_t index) {         \
        assert(v != NULL);                                                 \
        assert(index < v->size);                                           \
        return v->arr[index];                                              \
    }                                                                      \
                                                                           \
    vector_##Type init_vector_##Type(size_t capacity) {                    \
        Type* arr = malloc(sizeof(Type) * capacity);                       \
        assert(arr != NULL);                                               \
        return (vector_##Type){                                            \
            vector_begin_##Type,                                           \
            vector_end_##Type,                                             \
            push_back_vector_##Type,                                       \
            pop_back_vector_##Type,                                        \
            push_front_vector_##Type,                                      \
            pop_front_vector_##Type,                                       \
            get_vector_##Type,                                             \
            0,                                                             \
            capacity,                                                      \
            arr,                                                           \
        };                                                                 \
    }

#define Vector(Type, n) init_vector_##Type(n);

#define vector(Type) vector_##Type
