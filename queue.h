#include <assert.h>
#include <stdlib.h>
#include <string.h>
#ifndef CONTAINER_ITERFACE
#define CONTAINER_ITERFACE
#include "container_iterface.c"
#endif

#define IMPORT_QUEUE_TYPE(Type)                                             \
                                                                            \
    typedef struct queue_##Type queue_##Type;                               \
                                                                            \
    typedef struct queue_node_##Type queue_node_##Type;                     \
                                                                            \
    typedef void(push_queue_##Type##_func)(queue_##Type * vec, Type value); \
                                                                            \
    typedef Type(pop_queue_##Type##_func)(queue_##Type * vec);              \
                                                                            \
    typedef struct queue_node_##Type queue_node_##Type;                     \
                                                                            \
    struct queue_node_##Type {                                              \
        Type num;                                                           \
        queue_node_##Type* next;                                            \
    };                                                                      \
                                                                            \
    typedef struct queue_##Type queue_##Type;                               \
                                                                            \
    struct queue_##Type {                                                   \
        push_queue_##Type##_func* push_func;                                \
        pop_queue_##Type##_func* pop_func;                                  \
        queue_node_##Type* front;                                           \
        queue_node_##Type* back;                                            \
        size_t size;                                                        \
    };                                                                      \
                                                                            \
    queue_node_##Type* create_queue_node_##Type(Type x) {                   \
        queue_node_##Type* s =                                              \
            (queue_node_##Type*)malloc(sizeof(queue_node_##Type));          \
        assert(s != NULL);                                                  \
        s->next = NULL;                                                     \
        s->num = x;                                                         \
        return s;                                                           \
    }                                                                       \
                                                                            \
    void push_to_queue_##Type(queue_##Type* q, Type num) {                  \
        queue_node_##Type* node = create_queue_node_##Type(num);            \
        q->size += 1;                                                       \
                                                                            \
        if (q->front == NULL) {                                             \
            q->front = node;                                                \
        } else if (q->back == NULL) {                                       \
            q->back = node;                                                 \
            q->front->next = q->back;                                       \
        } else {                                                            \
            q->back->next = node;                                           \
            q->back = node;                                                 \
        }                                                                   \
    }                                                                       \
                                                                            \
    Type pop_from_queue_##Type(queue_##Type* s) {                           \
        assert(s != NULL);                                                  \
        assert(s->size > 0);                                                \
        assert(s->front != NULL);                                           \
        s->size -= 1;                                                       \
        if (s->size == 1) {                                                 \
            s->back = NULL;                                                 \
        }                                                                   \
        Type num = s->front->num;                                           \
        queue_node_##Type* tmp = s->front->next;                            \
        free(s->front);                                                     \
        s->front = tmp;                                                     \
        return num;                                                         \
    }                                                                       \
                                                                            \
    queue_##Type init_queue_##Type() {                                      \
        return (queue_##Type){                                              \
            push_to_queue_##Type, pop_from_queue_##Type, NULL, NULL, 0,     \
        };                                                                  \
    }

#define Queue(Type) init_queue_##Type()

#define queue(Type) queue_##Type
