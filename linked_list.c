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

#define IMPORT_LIST_TYPE(Type)                                                 \
                                                                               \
    typedef struct list_node_##Type list_node_##Type;                          \
                                                                               \
    typedef struct list_##Type list_##Type;                                    \
                                                                               \
    typedef void(push_back_list_##Type##_func)(list_##Type * vec, Type value); \
    typedef void(push_front_list_##Type##_func)(list_##Type * vec,             \
                                                Type value);                   \
                                                                               \
    typedef Type(get_list_##Type##_func)(const list_##Type* v, size_t index);  \
                                                                               \
    typedef Type(pop_back_list_##Type##_func)(list_##Type * vec);              \
    typedef Type(pop_front_list_##Type##_func)(list_##Type * vec);             \
                                                                               \
    struct list_node_##Type {                                                  \
        Type data;                                                             \
        list_node_##Type* previous;                                            \
        list_node_##Type* next;                                                \
    };                                                                         \
                                                                               \
    typedef struct list_##Type list_##Type;                                    \
                                                                               \
    struct list_##Type {                                                       \
        begin_func* _begin;                                                    \
        end_func* _end;                                                        \
        push_back_list_##Type##_func* push_back_func;                          \
        pop_back_list_##Type##_func* pop_back_func;                            \
        push_front_list_##Type##_func* push_front_func;                        \
        pop_front_list_##Type##_func* pop_front_func;                          \
        get_list_##Type##_func* get_func;                                      \
        list_node_##Type* head;                                                \
        list_node_##Type* tail;                                                \
        size_t size;                                                           \
    };                                                                         \
                                                                               \
    void list_next_func_##Type(iterator* iter) {                               \
        iter->current = ((list_node_##Type*)iter->current)->next;              \
    }                                                                          \
                                                                               \
    void* list_get_func_##Type(iterator* iter) {                               \
        return &((list_node_##Type*)iter->current)->data;                      \
    }                                                                          \
                                                                               \
    iterator list_begin_##Type(void* current) {                                \
        return (iterator){                                                     \
            ((list_##Type*)current)->head,                                     \
            list_next_func_##Type,                                             \
            list_get_func_##Type,                                              \
        };                                                                     \
    }                                                                          \
                                                                               \
    iterator list_end_##Type(void* current) {                                  \
        (void)current;                                                         \
        return (iterator){                                                     \
            NULL,                                                              \
            list_next_func_##Type,                                             \
            list_get_func_##Type,                                              \
        };                                                                     \
    }                                                                          \
                                                                               \
    list_node_##Type* create_node_##Type(Type data) {                          \
        list_node_##Type* s =                                                  \
            (list_node_##Type*)malloc(sizeof(list_node_##Type));               \
        assert(s != NULL);                                                     \
        s->previous = NULL;                                                    \
        s->next = NULL;                                                        \
        s->data = data;                                                        \
        return s;                                                              \
    }                                                                          \
                                                                               \
    void push_front_list_##Type(list_##Type* s, Type data) {                   \
        list_node_##Type* node = create_node_##Type(data);                     \
        s->size += 1;                                                          \
        if (s->head == NULL) {                                                 \
            s->head = node;                                                    \
            if (s->tail == NULL) {                                             \
                s->tail = s->head;                                             \
            }                                                                  \
            return;                                                            \
        }                                                                      \
        list_node_##Type* tmp = s->head;                                       \
        s->head = node;                                                        \
        node->next = tmp;                                                      \
        tmp->previous = node;                                                  \
    }                                                                          \
                                                                               \
    void push_back_list_##Type(list_##Type* s, Type data) {                    \
        list_node_##Type* node = create_node_##Type(data);                     \
        s->size += 1;                                                          \
        if (s->tail == NULL) {                                                 \
            s->tail = node;                                                    \
            if (s->head == NULL) {                                             \
                s->head = s->tail;                                             \
            }                                                                  \
            return;                                                            \
        }                                                                      \
        list_node_##Type* tmp = s->tail;                                       \
        s->tail = node;                                                        \
        node->previous = tmp;                                                  \
        tmp->next = node;                                                      \
    }                                                                          \
                                                                               \
    Type pop_back_list_##Type(list_##Type* s) {                                \
        assert(s != NULL);                                                     \
        assert(s->size > 0);                                                   \
        s->size -= 1;                                                          \
                                                                               \
        Type data = s->tail->data;                                             \
        list_node_##Type* tmp = s->tail->previous;                             \
        free(s->tail);                                                         \
        s->tail = tmp;                                                         \
        return data;                                                           \
    }                                                                          \
                                                                               \
    Type pop_front_list_##Type(list_##Type* s) {                               \
        assert(s != NULL);                                                     \
        assert(s->size > 0);                                                   \
        s->size -= 1;                                                          \
                                                                               \
        Type data = s->head->data;                                             \
        list_node_##Type* tmp = s->head->next;                                 \
        free(s->head);                                                         \
        s->head = tmp;                                                         \
        return data;                                                           \
    }                                                                          \
    Type get_list_##Type(const list_##Type* v, size_t index) {                 \
        assert("list canr call get");                                          \
        (void)index;                                                           \
        (void)v;                                                               \
        exit(1);                                                               \
    }                                                                          \
                                                                               \
    list_##Type init_list_##Type() {                                           \
        return (list_##Type){                                                  \
            list_begin_##Type,                                                 \
            list_end_##Type,                                                   \
            push_back_list_##Type,                                             \
            pop_back_list_##Type,                                              \
            push_front_list_##Type,                                            \
            pop_front_list_##Type,                                             \
            get_list_##Type,                                                   \
            NULL,                                                              \
            NULL,                                                              \
            0,                                                                 \
        };                                                                     \
    }

#define List(Type) init_list_##Type();

#define list(Type) list_##Type

// TESTS\
// int main() {\
//     {\
//         list l = init_list();\
//         insert_front(&l, 1);\
//         insert_front(&l, 2);\
//         insert_front(&l, 3);\
//         {\
//             list_node* tmp = l.head;\
//             while (tmp) {\
//                 printf("%d ", tmp->data);\
//                 tmp = tmp->next;\
//             }\
//             printf("\n");\
//         }\
//         {\
//             list_node* tmp = l.tail;\
//             while (tmp) {\
//                 printf("%d ", tmp->data);\
//                 tmp = tmp->previous;\
//             }\
//             printf("\n");\
//         }\
//         {\
//             while (l.size) {\
//                 printf("%d ", pop_back(&l));\
//             }\
//             printf("\n");\
//         }\
//         {\
//             insert_front(&l, 1);\
//             insert_front(&l, 2);\
//             insert_front(&l, 3);\
//             while (l.size) {\
//                 printf("%d ", pop_front(&l));\
//             }\
//             printf("\n");\
//         }\
//     }\
//     {\
//         list l = init_list();\
//         insert_back(&l, 1);\
//         insert_back(&l, 2);\
//         insert_back(&l, 3);\
//         {\
//             list_node* tmp = l.head;\
//             while (tmp) {\
//                 printf("%d ", tmp->data);\
//                 tmp = tmp->next;\
//             }\
//             printf("\n");\
//         }\
//         {\
//             list_node* tmp = l.tail;\
//             while (tmp) {\
//                 printf("%d ", tmp->data);\
//                 tmp = tmp->previous;\
//             }\
//             printf("\n");\
//         }\
//         {\
//             while (l.size) {\
//                 printf("%d ", pop_front(&l));\
//             }\
//             printf("\n");\
//         }\
//         {\
//             insert_back(&l, 1);\
//             insert_back(&l, 2);\
//             insert_back(&l, 3);\
//             while (l.size) {\
//                 printf("%d ", pop_back(&l));\
//             }\
//             printf("\n");\
//         }\
//     }\
// }\
