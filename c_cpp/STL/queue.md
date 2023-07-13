# Queue
선입선출 구조로 작동하게 설계된 컨테이너 어댑터<br>
- 컨테이너 어댑터
    - 기존에 존재하는 특정 컨테이너(underlying container)의 캡슐화된 객체만 사용하는 컨테이너로, 멤버에 접근할 수 있는 특정 방법만 주어지게 된다.
- FIFO context (first-in first-out): 큐의 핵심 포인트는, 어떤 컨테이너를 사용하든 `back`으로 들어가 `front`로 나온다는 것<br>
- 삽입구와 출구가 다른 형태<br>

### Definition
```c++
#include <queue>
// std::queue

template <class T, class Container = deque<T> > class queue;

typedef T queue::value_type;
typedef Container queue::container_type
```
> Member function

| Category | Function | Description | Etc |
|--------|--------|--------|--------|
| - | begin | Return iterator to beginning | |
| - | empty | Test whether container is empty | |
| - | size | Return size | |
| - | front | Access next element | |
| - | back | Access last element | |
| - | push | Insert element | |
| - | emplace | Construct and insert element | |
| - | pop | Remove next element | |
| - | swap | Swap contents | |


### 추가 공부할 내용
[priority queue]()

### Reference
[cplusplus: queue](https://cplusplus.com/reference/queue/queue/)  
[Stack Overflow: what is underlying container?](https://stackoverflow.com/questions/37306979/what-are-underlying-containers)

======================================================
###### 230713 TIL