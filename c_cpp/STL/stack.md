# Stack
LIFO(Last In Fist Out) 구조로 동작하는 컨테이너 어댑터<br>
- LIFO context: 스택의 핵심 포인트는, 어떤 컨테이너를 사용하든 `back` 으로 들어가 쌓이고, 마지막에 들어간 원소가 제일 먼저 나오는 구조
- 입출구가 하나

> The standard container classes vector, deque and list fulfill these requirements. By default, if no container class is specified for a particular stack class instantiation, the standard container deque is used.

### Definition
```c++
#include <stack>
// std::stack

template <class T, class Container = deque<T> > class stack;

typedef T stack::value_type;
typedef Alloc stack::container_type;
```
> Member function

| Category | Function | Description | Etc |
|--------|--------|--------|--------|
| - | empty | Test whether container is empty | |
| - | size | Return size | |
| - | top | Access next element | |
| - | push | Insert element | |
| - | emplace | Construct and insert element | |
| - | pop | Remove top element | |
| - | swap | Swap contents | |


### 추가 공부할 내용


### Reference
[cplusplus: stack](https://cplusplus.com/reference/stack/stack/)    


======================================================
###### 230721 TIL