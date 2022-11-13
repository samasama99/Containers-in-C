#include "vector.c"

IMPORT_VECTOR_TYPE(int)

int main() {
    vector(int) my_vec = Vector(int, 10);

    Push_back(int, my_vec, 1);
    Push_back(int, my_vec, 2);
    Push_back(int, my_vec, 3);
    Push_back(int, my_vec, 4);
    Push_back(int, my_vec, 5);
    Push_back(int, my_vec, 6);

    // for (iterator it = Begin(my_vec);it.current !=
    // End(my_vec).current;Next(it)) {
    //     printf("value : %d\n", Get_value(int, it));
    // }

    For(it, my_vec) {
        printf("value : %d\n", Get_value(int, it));
    }
}
