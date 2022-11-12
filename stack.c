#include <assert.h>
#include <stdlib.h>
#include <string.h>

typedef int* Type;

typedef struct list_node stack_node;

struct list_node {
    Type num;
    stack_node* previous;
};

typedef struct stack stack;

struct stack {
    stack_node* top;
    size_t size;
};

stack init_stack() {
    return (stack){
        NULL,
        0,
    };
}

stack_node* create_stack_node(Type x) {
    stack_node* s = (stack_node*)malloc(sizeof(stack_node));
    assert(s != NULL);
    s->previous = NULL;
    s->num = x;
    return s;
}

void push_to_stack(stack* s, Type num) {
    stack_node* node = create_stack_node(num);
    s->size += 1;
    node->previous = s->top;
    s->top = node;
}

Type pop_from_stack(stack* s) {
    assert(s != NULL);
    assert(s->size > 0);
    assert(s->top != NULL);
    s->size -= 1;
    Type num = s->top->num;
    free(s->top);
    s->top = s->top->previous;
    return num;
}

// TESTS
// int main() {
//     stack s = init_stack();

//     assert(s.size == 0);
//     push_to_stack(&s, 1);
//     assert(s.size == 1);
//     push_to_stack(&s, 2);
//     assert(s.size == 2);
//     push_to_stack(&s, 3);
//     assert(s.size == 3);
//     push_to_stack(&s, 4);
//     assert(s.size == 4);
//     push_to_stack(&s, 5);
//     assert(s.size == 5);
//     push_to_stack(&s, 6);
//     assert(s.size == 6);

//     assert(s.size == 6 && pop_from_stack(&s) == 6);
//     assert(s.size == 5 && pop_from_stack(&s) == 5);
//     assert(s.size == 4 && pop_from_stack(&s) == 4);
//     assert(s.size == 3 && pop_from_stack(&s) == 3);
//     assert(s.size == 2 && pop_from_stack(&s) == 2);
//     assert(s.size == 1 && pop_from_stack(&s) == 1);

//     assert(s.size == 0);
//     push_to_stack(&s, 1);
//     assert(s.size == 1);
//     push_to_stack(&s, 2);
//     assert(s.size == 2);
//     push_to_stack(&s, 3);
//     assert(s.size == 3);
//     push_to_stack(&s, 4);
//     assert(s.size == 4);
//     push_to_stack(&s, 5);
//     assert(s.size == 5);
//     push_to_stack(&s, 6);
//     assert(s.size == 6);

//     assert(s.size == 6 && pop_from_stack(&s) == 6);
//     assert(s.size == 5 && pop_from_stack(&s) == 5);
//     assert(s.size == 4 && pop_from_stack(&s) == 4);
//     assert(s.size == 3 && pop_from_stack(&s) == 3);
//     assert(s.size == 2 && pop_from_stack(&s) == 2);
//     assert(s.size == 1 && pop_from_stack(&s) == 1);
// }
