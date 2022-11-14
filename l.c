#include <stdio.h>
#include "linked_list.c"

typedef char* char_ptr;

IMPORT_LIST_TYPE(int)
IMPORT_LIST_TYPE(char_ptr)

int main() {
    {
        list(int) my_list = List(int);

        Push_back(my_list, 1);
        Push_back(my_list, 2);
        Push_back(my_list, 3);
        Push_back(my_list, 4);
        Push_back(my_list, 5);
        Push_back(my_list, 6);

        For(it, my_list) {
            printf("value : %d\n", Get_value(int, it));
        }

        while (my_list.size) {
            printf("%d ", Pop_back(my_list));
        }

        printf("\n");
    }
    {
        list(char_ptr) my_list = List(char_ptr);

        Push_front(my_list, "hello1");
        Push_front(my_list, "hello2");
        Push_front(my_list, "hello3");
        Push_front(my_list, "hello4");
        Push_front(my_list, "hello5");
        Push_front(my_list, "hello6");

        For(it, my_list) {
            printf("value : %s\n", Get_value(char_ptr, it));
        }

        while (my_list.size) {
            printf("%s ", Pop_front(my_list));
        }

        printf("\n");
    }
}
