# Set
특정 순서를 따르는 유니크한 원소들을 저장하는 연관 컨테이너<br>
- 원소의 값이 곧 키가 됨: 즉, 각 값은 하나뿐이어야 함(unique)
- 원소들은 항상 상수: 즉, 수정될 수 없음
    - 수정될 수는 없지만, 삽입/삭제는 가능하다
- 이진 탐색 트리로 구현


### set 내부 동작
내부 비교 객체에 의해 항상 정렬된다. 이 때 정렬 기준은 특정 `strict weak ordering criterion` 


### 비교
map과 동일;<br>
다른 정렬되지 않은 컨테이너들에 비해서 키로 각 원소에 접근하는 게 느리지만, 순서에 따라 하위 부분집합들 반복자 사용이 가능   
but they allow the direct iteration on subsets based on their order.

#### map과의 차이
구조가 아주 유사하여 `key`만 있고 `value`가 없는 map과 흡사하다. 모든 원소가 key이므로 중복이 불가하고 정렬되어 있다.


### Definition
```c++
#include <set>
// std::set

template < class T, // set::key_type/value_type           
class Compare = less<T>,        // set::key_compare/value_compare           
class Alloc = allocator<T>      // set::allocator_type           
> class set;


```
> Member function


### 추가 공부할 내용
[multiset]()


### Reference
[cplusplus: set](https://cplusplus.com/reference/set/set/)    


======================================================
###### 230716 TIL