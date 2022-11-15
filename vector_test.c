#include "vector.h"
#include <stdio.h>

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

        assert(Get(my_vec, 0) == 1);
        assert(Get(my_vec, 5) == 6);

        int i = 0;
        For(it, my_vec) {
            assert(Get_value(int, it) == my_vec.arr[i]);
            i++;
        }

        while (my_vec.size) {
            --i;
            assert(Pop_back(my_vec) == my_vec.arr[i]);
        }
    }
    {
        vector(char_ptr) my_vec = Vector(char_ptr, 10);

        Push_back(my_vec, "hello1");
        Push_back(my_vec, "hello2");
        Push_back(my_vec, "hello3");
        Push_back(my_vec, "hello4");
        Push_back(my_vec, "hello5");
        Push_back(my_vec, "hello6");

        assert(strcmp(Get(my_vec, 0), "hello1") == 0);
        assert(strcmp(Get(my_vec, 5), "hello6") == 0);
    }
    puts("all vector tests are passed");
    return 0;
}
