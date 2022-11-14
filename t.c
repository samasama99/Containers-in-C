#include <stdio.h>
#include "vector.c"

typedef char* char_ptr;

IMPORT_VECTOR_TYPE(int)
IMPORT_VECTOR_TYPE(char_ptr)

int main() {
    {
        vector(int) my_vec = Vector(int, 0);

        Push_back(my_vec, 1);
        Push_back(my_vec, 2);
        Push_back(my_vec, 3);
        Push_back(my_vec, 4);
        Push_back(my_vec, 5);
        Push_back(my_vec, 6);
        Pop_front(my_vec);

        printf("%d\n", Get(my_vec, 0));
        printf("%d\n", Get(my_vec, 5));

        For(it, my_vec) {
            printf("value : %d\n", Get_value(int, it));
        }

        while (my_vec.size) {
            printf("%d ", Pop_back(my_vec));
        }

        printf("\n");
    }
    {
        vector(char_ptr) my_vec = Vector(char_ptr, 10);

        Push_back(my_vec, "hello1");
        Push_back(my_vec, "hello2");
        Push_back(my_vec, "hello3");
        Push_back(my_vec, "hello4");
        Push_back(my_vec, "hello5");
        Push_back(my_vec, "hello6");

        printf("%s\n", Get(my_vec, 0));
        printf("%s\n", Get(my_vec, 5));

        For(it, my_vec) {
            printf("value : %s\n", Get_value(char_ptr, it));
        }

        while (my_vec.size) {
            printf("%s ", Pop_back(my_vec));
        }

        printf("\n");
    }
}

// // for (iterator it = Begin(my_vec);it.current !=
// // End(my_vec).current;Next(it)) {
// //     printf("value : %d\n", Get_value(int, it));
// // }
