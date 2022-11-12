#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int Type;

typedef struct list_node list_node;

struct list_node {
    Type data;
    list_node* previous;
    list_node* next;
};

typedef struct list list;

struct list {
    list_node* head;
    list_node* tail;
    size_t size;
};

list init_list() {
    return (list){
        NULL,
        NULL,
        0,
    };
}

list_node* create_node(Type data) {
    list_node* s = (list_node*)malloc(sizeof(list_node));
    assert(s != NULL);
    s->previous = NULL;
    s->next = NULL;
    s->data = data;
    return s;
}

void insert_front(list* s, Type data) {
    list_node* node = create_node(data);
    s->size += 1;
    if (s->head == NULL) {
        s->head = node;
        if (s->tail == NULL) {
            s->tail = s->head;
        }
        return;
    }
    list_node* tmp = s->head;
    s->head = node;
    node->next = tmp;
    tmp->previous = node;
}

void insert_back(list* s, Type data) {
    list_node* node = create_node(data);
    s->size += 1;
    if (s->tail == NULL) {
        s->tail = node;
        if (s->head == NULL) {
            s->head = s->tail;
        }
        return;
    }
    list_node* tmp = s->tail;
    s->tail = node;
    node->previous = tmp;
    tmp->next = node;
}

Type pop_back(list* s) {
    assert(s != NULL);
    assert(s->size > 0);
    s->size -= 1;

    Type data = s->tail->data;
    list_node* tmp = s->tail->previous;
    free(s->tail);
    s->tail = tmp;
    return data;
}

Type pop_front(list* s) {
    assert(s != NULL);
    assert(s->size > 0);
    s->size -= 1;

    Type data = s->head->data;
    list_node* tmp = s->head->next;
    free(s->head);
    s->head = tmp;
    return data;
}

// TESTS
int main() {
    {
        list l = init_list();
        insert_front(&l, 1);
        insert_front(&l, 2);
        insert_front(&l, 3);
        {
            list_node* tmp = l.head;
            while (tmp) {
                printf("%d ", tmp->data);
                tmp = tmp->next;
            }
            printf("\n");
        }
        {
            list_node* tmp = l.tail;
            while (tmp) {
                printf("%d ", tmp->data);
                tmp = tmp->previous;
            }
            printf("\n");
        }
        {
            while (l.size) {
                printf("%d ", pop_back(&l));
            }
            printf("\n");
        }
        {
            insert_front(&l, 1);
            insert_front(&l, 2);
            insert_front(&l, 3);
            while (l.size) {
                printf("%d ", pop_front(&l));
            }
            printf("\n");
        }
    }
    {
        list l = init_list();
        insert_back(&l, 1);
        insert_back(&l, 2);
        insert_back(&l, 3);
        {
            list_node* tmp = l.head;
            while (tmp) {
                printf("%d ", tmp->data);
                tmp = tmp->next;
            }
            printf("\n");
        }
        {
            list_node* tmp = l.tail;
            while (tmp) {
                printf("%d ", tmp->data);
                tmp = tmp->previous;
            }
            printf("\n");
        }
        {
            while (l.size) {
                printf("%d ", pop_front(&l));
            }
            printf("\n");
        }
        {
            insert_back(&l, 1);
            insert_back(&l, 2);
            insert_back(&l, 3);
            while (l.size) {
                printf("%d ", pop_back(&l));
            }
            printf("\n");
        }
    }
}
