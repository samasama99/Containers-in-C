#include "stack.h"
#include <stdio.h>

IMPORT_STACK_TYPE(int)

int main() {
    stack(int) s = Stack(int);

    assert(s.size == 0);
    Push(s, 1);
    assert(s.size == 1);
    Push(s, 2);
    assert(s.size == 2);
    Push(s, 3);
    assert(s.size == 3);
    Push(s, 4);
    assert(s.size == 4);
    Push(s, 5);
    assert(s.size == 5);
    Push(s, 6);
    assert(s.size == 6);

    assert(s.size == 6 && Pop(s) == 6);
    assert(s.size == 5 && Pop(s) == 5);
    assert(s.size == 4 && Pop(s) == 4);
    assert(s.size == 3 && Pop(s) == 3);
    assert(s.size == 2 && Pop(s) == 2);
    assert(s.size == 1 && Pop(s) == 1);

    assert(s.size == 0);
    Push(s, 1);
    assert(s.size == 1);
    Push(s, 2);
    assert(s.size == 2);
    Push(s, 3);
    assert(s.size == 3);
    Push(s, 4);
    assert(s.size == 4);
    Push(s, 5);
    assert(s.size == 5);
    Push(s, 6);
    assert(s.size == 6);

    assert(s.size == 6 && Pop(s) == 6);
    assert(s.size == 5 && Pop(s) == 5);
    assert(s.size == 4 && Pop(s) == 4);
    assert(s.size == 3 && Pop(s) == 3);
    assert(s.size == 2 && Pop(s) == 2);
    assert(s.size == 1 && Pop(s) == 1);

    puts("all stack tests are passed");
}
