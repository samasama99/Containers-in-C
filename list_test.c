#include "list.h"
#include <stdio.h>

typedef char* char_ptr;

IMPORT_LIST_TYPE(int)
IMPORT_LIST_TYPE(char_ptr)

int main() {
    {
        int arr[] = {1, 2, 3, 4, 5, 6};
        list(int) my_list = List(int);

        Push_back(my_list, 1);
        Push_back(my_list, 2);
        Push_back(my_list, 3);
        Push_back(my_list, 4);
        Push_back(my_list, 5);
        Push_back(my_list, 6);

        int i = 0;
        For(it, my_list) {
            assert(Get_value(int, it) == arr[i]);
            i++;
        }

        while (my_list.size) {
            --i;
            assert(Pop_back(my_list) == arr[i]);
        }
    }
    {
        list(char_ptr) my_list = List(char_ptr);

        Push_back(my_list, "hello1");
        Push_back(my_list, "hello2");
        Push_back(my_list, "hello3");
        Push_back(my_list, "hello4");
        Push_back(my_list, "hello5");
        Push_back(my_list, "hello6");

        assert(strcmp(my_list.head->data, "hello1") == 0);
        assert(strcmp(my_list.tail->data, "hello6") == 0);
    }
    puts("all list tests are passed");
    return 0;
}
