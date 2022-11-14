#include "../linked_list.c"

typedef char* char_ptr;
typedef struct pair {
    char* key;
    char* value;
} pair_t;

// IMPORT_LIST_TYPE(pair_t);

// int main(int ac, char** av, char** env) {
//     (void)ac;
//     (void)av;

//     list(pair_t) env_list = List(pair_t);

//     int i = 0;

//     while (env[i]) {
//         char* eql = strchr(env[i], '=');
//         eql[0] = '\0';

//         char* value = strdup(eql + 1);
//         char* key = strdup(env[i]);

//         Push_back(env_list, ((pair_t){key, value}));
//         i++;
//     };

//     For(it, env_list) {
//         pair_t p = Get_value(pair_t, it);
//         printf("%s=%s\n", p.key, p.value);
//     }
// }

#include "../vector.c"

IMPORT_VECTOR_TYPE(pair_t);

int main(int ac, char** av, char** env) {
    (void)ac;
    (void)av;

    vector(pair_t) env_list = Vector(pair_t, 1);

    int i = 0;

    while (env[i]) {
        char* eql = strchr(env[i], '=');
        eql[0] = '\0';

        char* value = strdup(eql + 1);
        char* key = strdup(env[i]);

        Push_back(env_list, ((pair_t){key, value}));
        i++;
    };

    For(it, env_list) {
        pair_t p = Get_value(pair_t, it);
        printf("%s=%s\n", p.key, p.value);
    }
}
