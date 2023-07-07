# List
삽입/삭제 동작에 항상 상수 시간을 보장하는 시퀀스 컨테이너<br>
- 노드 포인터가 어디로 연결되어 있냐에 따라서 메모리에 흩어져 있는 연결되지 않은 원소들을 가짐

### 리스트 내부 동작
1. 이중 연결 리스트(이전 노드-다음 노드)로 구현


### 비교
다른 시퀀스 컨테이너와 비교해서, <br>
- 원소 삽입/추출/이동에 효울적
- 원소에 대한 직접적인 접근에 약함 (연결 노드를 타고 가야 함)
- 단방향 리스트(`forward_list`)와 다른 점은 양방향이라는 것

### Definition
```c++
#include <list>
// std::list

template < class T, class Alloc = allocator<T> > class list;

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
| Capacity | empty | Test whether vector is empty | |
| **Element access** | | | |
| Element access | front | Access first element | |
| Element access | back | Access last element | |
| **Modifiers** | | | |
| Modifiers | assign | Assign new content to container | |
| Modifiers | emplace_front | Construct and insert element at beginning | |
| Modifiers | push_front | nsert element at beginning | |
| Modifiers | pop_front | Delete first element | |
| Modifiers | emplace_back | Construct and insert element at the end | |
| Modifiers | push_back | Add element at the end | |
| Modifiers | pop_back | Delete last element | |
| Modifiers | emplace | Construct and insert element | |
| Modifiers | insert | Insert elements | |
| Modifiers | erase | Erase elements | |
| Modifiers | swap | Swap content | |
| Modifiers | resize | Change size | |
| Modifiers | clear | Clear content | |
| **Operations** | | | | 
| Operations | splice | Transfer elements from list to list | |
| Operations |remove | Remove elements with specific value | |
| Operations |remove_if	| Remove elements fulfilling condition | | 
| Operations | unique | Remove duplicate values | |
| Operations | merge | Merge sorted lists | |
| Operations | sort	| Sort elements in container | |
| Operations | reverse | Reverse the order of elements | |
| **Observers** | | | |
| Observers | get_allocator | Get allocator | | 


### 추가 공부할 내용
1. get_allocator는 벡터의 Allocator과 뭐가 다른가
2. 이중 연결 리스트 추가 공부 - [자료구조](../../cs/data_structure.md)

### Reference
[cplusplus: list](https://cplusplus.com/reference/list/list/)


======================================================
###### 230707 TIL
