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
4. 재할당은 그 크기가 로그적으로 증가할 때만 발생한다
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

- `assign`
    ```C++
    template <class InputIterator>  void assign (InputIterator first, InputIterator last);      // 1. range
    void assign (size_type n, const value_type& val);       // 2. fill
    void assign (initializer_list<value_type> il);      // 3. initialize list
    ```
    현재의 벡터 내용을 새 벡터로 대체하며 size도 변경 적용
    - 선언한 벡터를 아예 새 벡터로 재할당한다는 느낌; 그러나 메모리 주소 자체가 바뀌지는 않음(값, size만 재할당)
- `clear`
    ```C++
    void clear() noexcept;
    // noexcept: c++11 이후에서 사용하는 키워드로, 자세한 내용은 다른 곳에서
    ```
    벡터의 모든 원소를 삭제하고 size를 0으로 변경
    - 메모리 재할당/벡터 capacity 변경이 보장되지 않음
    - 메모리가 재할당되는 대표적인 함수는 `swap`
- `erase`
    ```C++
    iterator erase (iterator position);
    iterator erase (iterator first, iterator last);
    ```
    vector 에서 하나의 원소(position) 또는 범위 [first, last) 를 삭제
        - 실제로 컨테이너의 size 를 삭제된 원소만큼 줄이는 동작
        - 벡터가 배열 기반의 컨테이너이기 때문에, 벡터 끝이 아닌 요소를 지우는 동작은 모든 원소를 재할당하게 만듦 -> 리스트에 비해 비효율적
        - 지워진 원소의 다음 요소가 새로 할당된 위치의 iterator 리턴
- algorithm 함수
    - `remove`
        ```C++
        template <class ForwardIterator, class T>  ForwardIterator remove (ForwardIterator first, ForwardIterator last, const T& val);
        ```
        ` [first,last)` 범위에서 val 와 동일한 값을 삭제하고 범위의 마지막 원소 iterator 리턴 
            - 값을 삭제하더라도 객체의 size를 변경할 수는 없음
            - `operator==` 로 값 비교 
            - val과 동일한 값을 확인하면 그 다음에 있는 동일하지 않은 원소로 대체(replace)하는 것을 반복하여 val 값이 없는 새로운 범위를 만들고 그 범위의 마지막 iterator를 리턴하는 것
            - 따라서 리턴된 iterator 뒤부터 마지막 last까지는 `valid but unspecified state.`
                - 객체의 상태는 유효하지만 특정 상태라고 확정할 수 없는 상태. (주로 MOVE SEMANTICS 연산에서 발생함)
            - 지워지지 않은 원소들의 상대적 위치는 유지되나, 지워질 원소들의 상대적 위치의 경우 유지가 보장되지 않음
    - `remove_if`
        ```C++
        template <class ForwardIterator, class UnaryPredicate>  ForwardIterator remove_if (ForwardIterator first, ForwardIterator last,                             UnaryPredicate pred);
        ```
        ` [first,last)` 범위에서 pred가 true를 리턴하는 원소를 삭제하고 범위의 마지막 원소 iterator 리턴 
            - remove와 동일하게, 값을 삭제하더라도 객체의 size를 변경할 수는 없음
            - 조건을 만족하여 true를 리턴하는 경우에만 그 다음의 false 리턴하는 원소로 대체(replace)
            - pred - 단항 함수는 range 내의 원소를 인자로 받는다
            - 그 외 조건은 remove와 동일(순서 보장, 객체 상태 등)

### 추가 공부할 내용
1. template parameter `T`에 들어가는 자료형이 [`move`, 즉 객체 이동시 에러를 뱉지 않는다는게 보장이 되어야 함](https://cplusplus.com/reference/type_traits/is_nothrow_move_constructible/)
    - 관련하여 move 공부
2. [`std::allocator`](https://cplusplus.com/reference/memory/allocator/) 클래스
    


### Reference
[cplusplus: vector](https://cplusplus.com/reference/vector/vector/)
[cplusplus: remove](https://cplusplus.com/reference/algorithm/remove/?kw=remove)
[cplusplus: remove_if](https://cplusplus.com/reference/algorithm/remove_if/?kw=remove_if)
[cplusplus: erase](https://cplusplus.com/reference/vector/vector/erase/)
[cplusplus: clear](https://cplusplus.com/reference/vector/vector/clear/)


======================================================
###### 230706 TIL
###### 240121 TIL
###### 240123 TIL