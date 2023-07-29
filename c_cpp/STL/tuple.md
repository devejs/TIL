# Tuple
여러 개 원소를 묶어 하나의 객체로 나타내는 객체. 그룹화되는 원소는 각각 다른 타입이어도 된다.<br>
여러 데이터 타입을 묶는다는 면에서 구조체와도 비슷하지만, 구조체 내 이름으로 접근하는 것과 다르게 **순서** 로 접근한다.

### tuple 내부 동작
tuple 내 특정 원소들을 지정하는 동작은 `template-instantiation level` 에서 완료되므로 `get` 이나 `tie`와 같은 헬퍼 함수들처럼 컴파일 시간에 정해져야 한다.
- `get`: tuple의 x번째 원소를 리턴
    * ex. `std::get<0>(tuple_name)`
- `tie`: tuple의 원소를 unpack 해서 변수로 리턴
    * ex. `std::tie (first_element, std::ignore, third_element) = tuple_name;`
    * `std::ignore`로 패스 가능
    * first/third_element 는 해당 자료형이어야 함

### 비교
`utility` 헤더의 `pair`와 다른 점
- `pair`가 일종의 tuple로, 더 좁은 의미에서 사용된다
- 두 개의 값을 묶어서 `first`, `second`로 사용
- definition
    ```c++
    #include <utility>

    template <class T1, class T2> struct pair;
    ```
- tuple은 더 general 하게, 개수에 상관없이 원소를 묶을 수 있다

### Definition
```c++
#include <tuple>
// std::tuple

template <class... Types> class tuple;
/* Types means a list of types used for the elements,
and its order is same as used in the tuple
*/
```

### How to use
```C++
#include <tuple>
using namespace std;

...
std::tuple<int,char> foo (10,'x');
auto bar = std::make_tuple ("test", 3.1, 14, 'y');

std::get<2>(bar) = 100;                                    // access element

  int myint; char mychar;

  std::tie (myint, mychar) = foo;                            // unpack elements
  std::tie (std::ignore, std::ignore, myint, mychar) = bar;  // unpack (with ignore)

  mychar = std::get<3>(bar);

  std::get<0>(foo) = std::get<2>(bar);
  std::get<1>(foo) = mychar;

  std::cout << "foo contains: ";
  std::cout << std::get<0>(foo) << ' ';
  std::cout << std::get<1>(foo) << '\n';

...
```



### 추가 공부할 내용


### Reference
- [cplusplus: tuple](https://cplusplus.com/reference/tuple/tuple/)   
- [cplusplus: pair](https://cplusplus.com/reference/utility/pair/)


======================================================
###### 230729 TIL