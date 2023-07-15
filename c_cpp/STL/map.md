# Map
키 값과, 매핑된 값의 조합을 원소로 이루어진 연관 컨테이너<br>
- 키: 원소를 식별하는데 사용되는 값으로, 정렬할 떄도 사용
- 값: 키와 연결된 값
- 키와 값은 `pair`로 묶여서 멤버 변수 `value_type`로 사용
    - `[]` 오퍼레이터로 key와 맞는 값에 바로 접근 가능
- 이진 탐색 트리로 구현

### 맵 내부 동작
내부 비교 객체에 의해 항상 키를 기준으로 정렬된다.


### 비교
다른 정렬되지 않은 컨테이너들에 비해서 키로 각 원소에 접근하는 게 느리지만, 순서에 따라 하위 부분집합들 반복자 사용이 가능   
but they allow the direct iteration on subsets based on their order.

### Definition
```c++
#include <map>
// std::map

template < class Key,  // map::key_type
class T,    // map::mapped_type           
class Compare = less<Key>,    // map::key_compare
class Alloc = allocator<pair<const Key,T> >    // map::allocator_type
> class map;

typedef pair<const Key, T> value_type;

typedef T map::value_type;
typedef Container map::container_type
```
> Member function


### 추가 공부할 내용
[multimap]()


### Reference
[cplusplus: map](https://cplusplus.com/reference/map/)    


======================================================
###### 230715 TIL