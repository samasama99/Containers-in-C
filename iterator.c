typedef struct iterator iterator;

typedef int iterType;
typedef void (next_func)(iterator*);
typedef iterType* (get_func)(iterator*);
typedef iterator (begin_func)(void* current);
typedef iterator (end_func)(void* current);

struct iterator {
    void* current;
    next_func* next;
    get_func* get;
};

typedef struct begin_end {
    begin_func* _begin;
    end_func* _end;
} begin_end;

void next(iterator* iter) {
    iter->next(iter);
}

iterType* get_value(iterator* iter) {
    return iter->get(iter);
}

iterator begin(void*cont) {
    return ((begin_end*)cont)->_begin(cont);
}

iterator end(void*cont) {
    return ((begin_end*)cont)->_end(cont);
}