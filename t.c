#include <string.h>
#include <stdio.h>

#define MAKE_PRINTEACH(TYPE)                         \
    void printeach_##TYPE(size_t n, TYPE array[n]) { \
        for (size_t i = 0; i < n; i++) {             \
            printf("%d\n", array[i]);                \
        }                                            \
    }

MAKE_PRINTEACH(int);

int main() {
    int arr[] = {1, 2, 3};
    printeach_int(3, arr);
    return 0;
}
