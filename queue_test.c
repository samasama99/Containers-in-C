#include "queue.h"
#include <stdio.h>

IMPORT_QUEUE_TYPE(int)

int main() {
    queue(int) s = Queue(int);
    assert(s.size == 0);
    Push(s, 1);
    assert(s.size == 1 && s.front->num == 1 && s.back == NULL);
    Push(s, 2);
    assert(s.size == 2 && s.front->num == 1 && s.back->num == 2);
    Push(s, 3);
    assert(s.size == 3 && s.front->num == 1 && s.back->num == 3);
    Push(s, 4);
    assert(s.size == 4 && s.front->num == 1 && s.back->num == 4);
    Push(s, 5);
    assert(s.size == 5 && s.front->num == 1 && s.back->num == 5);
    Push(s, 6);
    assert(s.size == 6 && s.front->num == 1 && s.back->num == 6);
    assert(s.size == 6 && Pop(s) == 1);
    assert(s.size == 5 && Pop(s) == 2);
    assert(s.size == 4 && Pop(s) == 3);
    assert(s.size == 3 && Pop(s) == 4);
    assert(s.size == 2 && Pop(s) == 5);
    assert(s.size == 1 && Pop(s) == 6);
    assert(s.size == 0);
    Push(s, 1);
    assert(s.size == 1 && s.front->num == 1 && s.back == NULL);
    Push(s, 2);
    assert(s.size == 2 && s.front->num == 1 && s.back->num == 2);
    Push(s, 3);
    assert(s.size == 3 && s.front->num == 1 && s.back->num == 3);
    Push(s, 4);
    assert(s.size == 4 && s.front->num == 1 && s.back->num == 4);
    Push(s, 5);
    assert(s.size == 5 && s.front->num == 1 && s.back->num == 5);
    Push(s, 6);
    assert(s.size == 6 && s.front->num == 1 && s.back->num == 6);
    assert(s.size == 6 && Pop(s) == 1);
    assert(s.size == 5 && Pop(s) == 2);
    assert(s.size == 4 && Pop(s) == 3);
    assert(s.size == 3 && Pop(s) == 4);
    assert(s.size == 2 && Pop(s) == 5);
    assert(s.size == 1 && Pop(s) == 6);
    puts("all queue tests are passed");
}
