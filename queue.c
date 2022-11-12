#include <assert.h>
#include <stdlib.h>
#include <string.h>

typedef int* Type;

typedef struct queue_node queue_node;

struct queue_node {
    Type num;
    queue_node* next;
};

typedef struct queue queue;

struct queue {
    queue_node* front;
    queue_node* back;
    size_t size;
};

queue init_queue() {
    return (queue){
        NULL,
        NULL,
        0,
    };
}

queue_node* create_queue_node(Type x) {
    queue_node* s = (queue_node*)malloc(sizeof(queue_node));
    assert(s != NULL);
    s->next = NULL;
    s->num = x;
    return s;
}

void push_to_queue(queue* q, Type num) {
    queue_node* node = create_queue_node(num);
    q->size += 1;

    if (q->front == NULL) {
        q->front = node;
    } else if (q->back == NULL) {
        q->back = node;
        q->front->next = q->back;
    } else {
        q->back->next = node;
        q->back = node;
    }
}

Type pop_from_queue(queue* s) {
    assert(s != NULL);
    assert(s->size > 0);
    assert(s->front != NULL);
    s->size -= 1;
    if (s->size == 1) {
        s->back = NULL;
    }
    Type num = s->front->num;
    queue_node* tmp = s->front->next;
    free(s->front);
    s->front = tmp;
    return num;
}

// TESTS
// int main() {
//     queue s = init_queue();

//     assert(s.size == 0);
//     push_to_queue(&s, 1);
//     assert(s.size == 1 && s.front->num == 1 && s.back == NULL);
//     push_to_queue(&s, 2);
//     assert(s.size == 2 && s.front->num == 1 && s.back->num == 2);
//     push_to_queue(&s, 3);
//     assert(s.size == 3 && s.front->num == 1 && s.back->num == 3);
//     push_to_queue(&s, 4);
//     assert(s.size == 4 && s.front->num == 1 && s.back->num == 4);
//     push_to_queue(&s, 5);
//     assert(s.size == 5 && s.front->num == 1 && s.back->num == 5);
//     push_to_queue(&s, 6);
//     assert(s.size == 6 && s.front->num == 1 && s.back->num == 6);

//     assert(s.size == 6 && pop_from_queue(&s) == 1);
//     assert(s.size == 5 && pop_from_queue(&s) == 2);
//     assert(s.size == 4 && pop_from_queue(&s) == 3);
//     assert(s.size == 3 && pop_from_queue(&s) == 4);
//     assert(s.size == 2 && pop_from_queue(&s) == 5);
//     assert(s.size == 1 && pop_from_queue(&s) == 6);

//     assert(s.size == 0);
//     push_to_queue(&s, 1);
//     assert(s.size == 1 && s.front->num == 1 && s.back == NULL);
//     push_to_queue(&s, 2);
//     assert(s.size == 2 && s.front->num == 1 && s.back->num == 2);
//     push_to_queue(&s, 3);
//     assert(s.size == 3 && s.front->num == 1 && s.back->num == 3);
//     push_to_queue(&s, 4);
//     assert(s.size == 4 && s.front->num == 1 && s.back->num == 4);
//     push_to_queue(&s, 5);
//     assert(s.size == 5 && s.front->num == 1 && s.back->num == 5);
//     push_to_queue(&s, 6);
//     assert(s.size == 6 && s.front->num == 1 && s.back->num == 6);

//     assert(s.size == 6 && pop_from_queue(&s) == 1);
//     assert(s.size == 5 && pop_from_queue(&s) == 2);
//     assert(s.size == 4 && pop_from_queue(&s) == 3);
//     assert(s.size == 3 && pop_from_queue(&s) == 4);
//     assert(s.size == 2 && pop_from_queue(&s) == 5);
//     assert(s.size == 1 && pop_from_queue(&s) == 6);
// }
