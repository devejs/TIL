# Vector
크기를 변화시킬 수 있는 배열을 나타내는 시퀀스 컨테이너<br>
- 원소들에 대해 연속적인 저장 공간을 가짐
    - 배열처럼 각 원소에 대해서 포인터와 오프셋(memory)으로 접근 가능
- 배열과 다른 점은 동적으로 크기가 변할 수 있음
    - 컨테이너에 의해 자동으로 저장 공간이 관리됨

### 벡터 내부 동작
1. 내부적으로 벡터는 동적할당된 배열
2. 새 원소가 삽입되어 사이즈가 변경될 때, 새로운 배열을 동적 할당하여 모든 원소들을 새 배열에 옮겨야 함 (big task)
3. 2번 작업이 너무 비효율적이므로 매번 재할당하지는 않음<br>
    -> 실제로 보이는 크기(`size`)보다 더 큰 공간을 미리 할당: `capacity`
4. 
> Libraries can implement different strategies for growth to balance between memory usage and reallocations, but in any case, reallocations should only happen at logarithmically growing intervals of size so that the insertion of individual elements at the end of the vector can be provided with amortized constant time complexity

### 비교
다른 시퀀스 컨테이너와 비교해서, <br>
- 원소에 바로 접근하기 효율적
- 끝(`end`)에서 원소를 더하거나 삭제하기에 효율적
- 끝이 아닌 위치에서 원소 삽입/삭제는 다른 자료구조보다 비효율적

### Definition
```c++
#include <vector>
// std::vector

template < class T, class Alloc = allocator<T> > class vector; // generic template

typedef T vector::value_type;
typedef Alloc vector::allocator_type;
```
> Member function

| Category | Function | Description | Etc |
|--------|--------|--------|--------|
| **Iterator** | | | |
| Iterator | begin | Return iterator to beginning | |
| Iterator | end | Return iterator to end | |
| Iterator | rbegin | Return reverse iterator to reverse beginning | |
| Iterator | rend | Return reverse iterator to reverse end | |
| Iterator | cbegin | Return const_iterator to beginning | |
| Iterator | cend | Return const_iterator to end | |
| Iterator | crbegin | Return const_reverse_iterator to reverse beginning | |
| Iterator | crend | Return const_reverse_iterator to reverse end | |
| **Capacity** | | | |
| Capacity | size | Return size | |
| Capacity | max_size | Return maximum size | |
| Capacity | resize | Change size | |
| Capacity | capacity | Return size of allocated storage capacity | |
| Capacity | empty | Test whether vector is empty | |
| Capacity | reserve | Request a change in capacity | |
| Capacity | shrink_to_fit | Shrink to fit | |
| **Element access** | | | |
| Element access | operator[] | Access element | |
| Element access | at | Access element | |
| Element access | front | Access first element | |
| Element access | back | Access last element | |
| Element access | data | Access data | |
| **Modifiers** | | | |
| Modifiers | assign | Assign vector content | | 
| Modifiers | push_back | Add element at the end | |
| Modifiers | pop_back | Delete last element | | 
| Modifiers | insert | Insert elements | | 
| Modifiers | erase | Erase elements | | 
| Modifiers | swap | Swap content | | 
| Modifiers | clear | Clear content | | 
| Modifiers | emplace | Construct and insert element | | 
| Modifiers | emplace_back | Construct and insert element at the end | | 
| **Allocator** | | | |
| Allocator | get_allocator | Get allocator | | 


### 추가 공부할 내용
1. template parameter `T`에 들어가는 자료형이 [`move`, 즉 객체 이동시 에러를 뱉지 않는다는게 보장이 되어야 함](https://cplusplus.com/reference/type_traits/is_nothrow_move_constructible/)
    - 관련하여 move 공부
2. [`std::allocator`](https://cplusplus.com/reference/memory/allocator/) 클래스
    


### Reference
[cplusplus: vector](https://cplusplus.com/reference/vector/vector/)


======================================================
###### 230706 TIL