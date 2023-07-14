# Priority Queue 
첫번째 원소가 항상 가장 큰 원소이게 설계된 컨테이너 어댑터<br>
- heap과 흡사함
- 원소는 `back`에서만 `pop`될 수 있다       // `top` 개념<br>
- elements can be inserted at any moment, and only the max heap element can be retrieved (the one at the top in the priority queue

### Definition
```c++
#include <queue>
// std::priority_queue

template <class T, class Container = vector<T>,  class Compare = less<typename Container::value_type> > class priority_queue;

typedef T queue::value_type;
typedef Container queue::container_type
```
> Member function

| Category | Function | Description | Etc |
|--------|--------|--------|--------|
| - | empty | Test whether container is empty | |
| - | size | Return size | |
| - | top | Access top element | |
| - | push | Insert element | |
| - | emplace | Construct and insert element | |
| - | pop | Remove next element | |
| - | swap | Swap contents | |


### 추가 공부할 내용
1. Strict weak order: 수학적 개념


### Reference
[cplusplus: priority queue](hhttps://cplusplus.com/reference/queue/priority_queue/)    
[strict weak order](https://panty.run/strict-weak-ordering/)

======================================================
###### 230714 TIL