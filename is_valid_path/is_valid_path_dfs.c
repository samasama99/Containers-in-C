#include <assert.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/_types/_sigaltstack.h>
#include <unistd.h>

#include "../linked_list.c"
#include "../stack.c"
#include "../vector.c"

#define BUFFER_SIZE 1024

typedef char* line;

IMPORT_VECTOR_TYPE(char)
IMPORT_VECTOR_TYPE(line)

bool is_valid(int row, int col, char **map, size_t num_of_lines) {
    if (row < 0 || col < 0 || row >= (int)num_of_lines || map[row][col] == '\0' ||
        map[row][col] == ' ')
        puts("invalid"), exit(1);
    if (map[row][col] == '1' || map[row][col] == 'S')
        return false;
    return true;
}

char* read_line(int fd) {
    vector(char) buffer = Vector(char, BUFFER_SIZE);
    char r[2] = (char[2]){0, 0};
    int b = 0;
    while ((b = read(fd, r, 1)) != 0 && r[0] != '\n') {
        if (b == 0)
            return NULL;
        Push_back(buffer, r[0]);
    }
    if (buffer.size == 0)
        return NULL;
    Push_back(buffer, '\0');
    return strdup(buffer.arr);
}

int main() {
    int fd = open("test", O_RDONLY);
    char* str;
    vector(line) map_vec = Vector(line, 1024);
    while ((str = read_line(fd))) {
        Push_back(map_vec, str);
    }
    close(fd);
    stack s = init_stack();
    push_to_stack(&s, (int[2]){1, 1});

    char **map = map_vec.arr;
    size_t map_size = map_vec.size;
    int valid = 0;
    while (s.size) {
        int* cur = pop_from_stack(&s);
        int j = cur[0];
        int i = cur[1];
        if (map[j][i] == 'E') {
            valid = 1;
            break;
        }
        if (map[j][i] == '1' || map[j][i] == 'S')
            continue;
        map[j][i] = 'S';
        if (is_valid(j, i - 1, map, map_size))
            push_to_stack(&s, (int[2]){j, i - 1});
        if (is_valid(j - 1, i, map, map_size))
            push_to_stack(&s, (int[2]){j - 1, i});
        if (is_valid(j, i + 1, map, map_size))
            push_to_stack(&s, (int[2]){j, i + 1});
        if (is_valid(j + 1, i, map, map_size))
            push_to_stack(&s, (int[2]){j + 1, i});
    }

    if (valid)
        puts("valid");
    else
        puts("invalid");

    for (size_t i = 0; i < map_size; ++i) {
        size_t j = 0;
        while (map[i][j]) {
            if (map[i][j] == '1')
                printf("%c", '|');
            else if (map[i][j] == 'S')
                printf("%c", 'x');
            else if (map[i][j] == '0')
                printf("%c", '.');
            else if (map[i][j] == 'E')
                printf("%c", 'E');
            else
                printf("%c", ' ');
            ++j;
        };
        printf("\n");
    }
}
