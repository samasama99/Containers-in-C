#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef ITERATOR
#define ITERATOR
#include "iterator.c"
#endif

// typedef int TYPE;\
// \
//
//

#define IMPORT_VECTOR_TYPE(Type)                                                  \
    typedef struct vector_##Type vector_##Type;                            \
    struct vector_##Type {                                                 \
        begin_func* _begin;                                                \
        end_func* _end;                                                    \
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
    vector_##Type init_vector_##Type(size_t capacity) {                    \
        Type* arr = malloc(sizeof(Type) * capacity);                       \
        assert(arr != NULL);                                               \
        return (vector_##Type){                                            \
            vector_begin_##Type, vector_end_##Type, 0, capacity, arr,      \
        };                                                                 \
    }                                                                      \
                                                                           \
    void realloc_vector_##Type(vector_##Type* vec, size_t new_capacity) {  \
        vec->capacity = new_capacity;                                      \
        Type* arr = malloc(sizeof(Type) * new_capacity);                   \
        memcpy(arr, vec->arr, new_capacity);                               \
        free(vec->arr);                                                    \
        vec->arr = arr;                                                    \
    }                                                                      \
                                                                           \
    void push_back_##Type(vector_##Type* vec, Type value) {                \
        assert(vec != NULL);                                               \
        if (vec->size == vec->capacity) {                                  \
            realloc_vector_##Type(vec, vec->capacity * 2);                 \
        }                                                                  \
        vec->arr[vec->size++] = value;                                     \
    }                                                                      \
                                                                           \
    Type pop_back_##Type(vector_##Type* vec) {                             \
        assert(vec != NULL);                                               \
        return vec->arr[--vec->size];                                      \
    }                                                                      \
                                                                           \
    Type get_##Type(const vector_##Type* v, size_t index) {                \
        assert(v != NULL);                                                 \
        assert(index < v->size);                                           \
        return v->arr[index];                                              \
    }

#define Vector(Type, n) init_vector_##Type(n);

#define vector(Type) vector_##Type

#define Create_vector(Type, Name, Capacity) \
    vector(Type) Name = Vector(Type, Capacity);

#define Push_back(Type, Name, Value) push_back_##Type(&Name, Value)

#define Get(Type, Name, Value) get_##Type(&Name, Value)

#define Pop(Type, Name) pop_back_##Type(&Name)

IMPORT_VECTOR_TYPE(int);
IMPORT_VECTOR_TYPE(float);

int main() {
    {
        vector(int) vec = Vector(int, 10);
        // Create_vector(int, vec, 10);
        Push_back(int, vec, 1);
        Push_back(int, vec, 2);
        Push_back(int, vec, 3);
        Push_back(int, vec, 4);
        Push_back(int, vec, 5);
        Push_back(int, vec, 6);
        Push_back(int, vec, 7);
        Push_back(int, vec, 8);
        Push_back(int, vec, 9);
        for (size_t i = 0; i < vec.size; ++i) {
            printf("index %zu value %d\n", i, Get(int, vec, i));
        }
        while (vec.size) {
            printf("value %d\n", Pop(int, vec));
        }
    }
    {
        Create_vector(float, vec, 10);
        Push_back(float, vec, 1.5);
        Push_back(float, vec, 2.5);
        Push_back(float, vec, 3.5);
        Push_back(float, vec, 4.5);
        Push_back(float, vec, 5.5);
        Push_back(float, vec, 6.5);
        Push_back(float, vec, 7.5);
        Push_back(float, vec, 8.5);
        Push_back(float, vec, 9.5);
        for (size_t i = 0; i < vec.size; ++i) {
            printf("index %zu value %f\n", i, Get(float, vec, i));
        }
        while (vec.size) {
            printf("value %f\n", Pop(float, vec));
        }
    }
}
