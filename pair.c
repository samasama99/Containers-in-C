#define IMPORT_PAIR_TYPE(FIRST_TYPE, SECOND_TYPE)      \
    typedef struct pair_##FIRST_TYPE##_##SECOND_TYPE { \
        FIRST_TYPE first;                              \
        SECOND_TYPE second;                            \
    } pair_##FIRST_TYPE##_##SECOND_TYPE;

#define Pair(FIRST_TYPE, SECOND_TYPE, VALUE1, VALUE2) \
    (pair_##FIRST_TYPE##_##SECOND_TYPE) { VALUE1, VALUE2 }

#define pair(FIRST_TYPE, SECOND_TYPE) pair_##FIRST_TYPE##_##SECOND_TYPE

IMPORT_PAIR_TYPE(int, int)

int main() {
    pair(int, int) p1 = Pair(int, int, 10, 20);
    p1.first = 20;
    p1.second = 20;
    return 0;
}
