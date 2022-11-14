// #include "linked_list.c"
// #include "vector.c"

// typedef void(for_each_func)(void*);

// void add_one(iterator begin, iterator end) {
//     while (begin.current != end.current) {
//         ++*get_value(&begin);
//         next(&begin);
//     }
// }

// void pow_2(void *p) {
//     int *value = p;
//     *value *= *value;
// }

// void print(void*num) {
//     printf("%d ", *(int*)num);
// }

// void for_each(iterator begin, iterator end, for_each_func f) {
//     while (begin.current != end.current) {
//         f(get_value(&begin));
//         next(&begin);
//     }
// };

// // size_t container_size(iterator begin, iterator end) {
// //     size_t t = 0;
// //     for (;begin.current != end.current;++t){
// //         next(&begin);
// //     }
// //     return t;
// // }

// VECTOR_TYPE(int);
// int main() {
//     puts("list iterator test");
//     {
//         list l = init_list();
//         insert_back(&l, 1);
//         insert_back(&l, 2);
//         insert_back(&l, 3);
//         insert_back(&l, 4);
//         insert_back(&l, 5);
//         insert_back(&l, 6);
//         insert_back(&l, 7);
//         insert_back(&l, 8);
//         add_one(begin(&l), end(&l));
//         for_each(begin(&l), end(&l), pow_2);
//         iterator iter = begin(&l);
//         iterator _end = end(&l);
//         while (iter.current != _end.current) {
//             printf("%d ", *get_value(&iter));
//             next(&iter);
//         }
//         puts("\n");
//     }
//     puts("vector iterator test");
//     {
//         vector v = init_vector(0);
//         push_back(&v, 1);
//         push_back(&v, 2);
//         push_back(&v, 3);
//         push_back(&v, 4);
//         push_back(&v, 5);
//         push_back(&v, 6);
//         push_back(&v, 7);
//         push_back(&v, 8);
//         add_one(begin(&v), end(&v));
//         for_each(begin(&v), end(&v), pow_2);
//         for_each(begin(&v), end(&v), print);
//         puts("\n");
//     }
// }
