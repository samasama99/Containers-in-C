# Containers In C

## Why :
Because i was tired of reimplementing basic data structures everytime i want to prototype something in c

## My Solution :
Making "c++ containers" in C which means a generic data structure

## How to use
All my containers have an easy to use and unified interface

```
  // import the right header file
  #include "stack.h"
  // ...
  // import the needed types
  // you should always typedef your type to a single word like :
  // long long to ll
  // char* to char_ptr
  IMPORT_STACK_TYPE(int)
  IMPORT_VECTOR_TYPE(my_struct)
  IMPORT_LIST_TYPE(char_ptr)

  int main() {
    // to contstruct a container
    list(int) my_list = List(int);
    // then you use the appropriate methodes
    // look at the methodes table 
    Push_back(my_list, 10);
    Push_front(my_list, 20);
    int x = Pop_back(my_list);
    assert(x == 10);
    // todo :: to free the container
    Destroy(my_list);
  }
```

## Iterators

| Container   | Begin/End   |
| ----------- | ----------- |
| Stack       | No          |
| Queue       | No          |
| List        | Yes         |
| Vector      | yes         |

## Methods

| Container   | Push   | Pop | Push_back   | Pop_back | Push_front | Pop_front | Destroy |
| ----------- | ------ | --  | ----------  | -------- | ---------  | --------  | todo    |
| Stack       | Yes    | Yes | No          | No       | No         | No        | todo    |
| Queue       | Yes    | Yes | No          | No       | No         | No        | todo    |
| List        | No     | No  | Yes         | Yes      | Yes        | Yes       | todo    |
| Vector      | No     | No  | Yes         | Yes      | Todo       | Todo      | todo    |
