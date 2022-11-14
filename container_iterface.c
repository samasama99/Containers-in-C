#define Push_back(Name, Value) Name.push_back_func(&Name, Value)

#define Push_front(Name, Value) Name.push_front_func(&Name, Value)

#define Get(Name, Index) Name.get_func(&Name, Index)

#define Pop_back(Name) Name.pop_back_func(&Name)

#define Pop_front(Name) Name.pop_front_func(&Name)

// typedef struct vector_##Type vector_##Type;
//
// typedef void(push_back_vector_##Type##_func)(vector_##Type * vec,
//                                              Type value);
//
// typedef void(push_front_vector_##Type##_func)(vector_##Type * vec,
//                                               Type value);
//
// typedef Type(get_vector_##Type##_func)(const vector_##Type* v,
//                                        size_t index);
//
// typedef Type(pop_back_vector_##Type##_func)(vector_##Type * vec);
//
// typedef Type(pop_front_vector_##Type##_func)(vector_##Type * vec);

// struct Interface {
//     begin_func* _begin;
//     end_func* _end;
//     push_back_Cont##Type##_func* push_back_func;
//     pop_back_Cont##Type##_func* pop_back_func;
//     push_front_Cont_##Type##_func* push_front_func;
//     pop_front_Cont_##Type##_func* pop_front_func;
//     get_Cont_##Type##_func* get_func;
// };
