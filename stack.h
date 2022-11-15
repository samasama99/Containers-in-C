#include <assert.h>
#include <stdlib.h>
#include <string.h>

#ifndef CONTAINER_ITERFACE
#define CONTAINER_ITERFACE
#include "container_iterface.c"
#endif

#define IMPORT_STACK_TYPE(Type)                                             \
                                                                            \
    typedef struct stack_##Type stack_##Type;                               \
                                                                            \
    typedef struct stack_node_##Type stack_node_##Type;                     \
                                                                            \
    typedef void(push_stack_##Type##_func)(stack_##Type * vec, Type value); \
                                                                            \
    typedef Type(pop_stack_##Type##_func)(stack_##Type * vec);              \
                                                                            \
    struct stack_node_##Type {                                              \
        Type num;                                                           \
        stack_node_##Type* previous;                                        \
    };                                                                      \
                                                                            \
    struct stack_##Type {                                                   \
        push_stack_##Type##_func* push_func;                                \
        pop_stack_##Type##_func* pop_func;                                  \
        stack_node_##Type* top;                                             \
        size_t size;                                                        \
    };                                                                      \
                                                                            \
    stack_node_##Type* create_stack_node_##Type(Type x) {                   \
        stack_node_##Type* s =                                              \
            (stack_node_##Type*)malloc(sizeof(stack_node_##Type));          \
        assert(s != NULL);                                                  \
        s->previous = NULL;                                                 \
        s->num = x;                                                         \
        return s;                                                           \
    }                                                                       \
                                                                            \
    void push_to_stack_##Type(stack_##Type* s, Type num) {                  \
        stack_node_##Type* node = create_stack_node_##Type(num);            \
        s->size += 1;                                                       \
        node->previous = s->top;                                            \
        s->top = node;                                                      \
    }                                                                       \
                                                                            \
    Type pop_from_stack_##Type(stack_##Type* s) {                           \
        assert(s != NULL);                                                  \
        assert(s->size > 0);                                                \
        assert(s->top != NULL);                                             \
        s->size -= 1;                                                       \
        Type num = s->top->num;                                             \
        free(s->top);                                                       \
        s->top = s->top->previous;                                          \
        return num;                                                         \
    }                                                                       \
    stack_##Type init_stack_##Type() {                                      \
        return (stack_##Type){                                              \
            push_to_stack_##Type,                                           \
            pop_from_stack_##Type,                                          \
            NULL,                                                           \
            0,                                                              \
        };                                                                  \
    }

#define Stack(Type) init_stack_##Type()

#define stack(Type) stack_##Type
