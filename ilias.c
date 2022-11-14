#include "linked_list.c"

IMPORT_LIST_TYPE(float)

typedef void(func)(void*);

void ff(void* value) {
    *(float*)value += 1;
}

void for_each(iterator begin, iterator end, func f) {
    while (begin.current != end.current) {
        f(get_value(&begin));
        next(&begin);
    }
}

int main() {
    list(float) v1 = List(float);

    Push_back(v1, 1.1);
    Push_back(v1, 2.1);
    Push_back(v1, 3.1);
    Push_back(v1, 4.1);
    Push_back(v1, 5.1);
    Push_back(v1, 6.1);
    Push_back(v1, 7.1);
    Push_back(v1, 8.1);

    // while (v1.size) {
    //     printf("%f\n", Pop_back(v1));
    // }

    for_each(Begin(v1), End(v1), ff);

    while (v1.size) {
        printf("%f\n", Pop_front(v1));
    }
}
