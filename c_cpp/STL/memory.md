# Memory
```C++
using namespace std;
#include <memory>

template <class T> class shared_ptr;
template <class T> class weak_ptr;
template <class T, class D = default_delete<T>> class unique_ptr;
// array specialization	
template <class T, class D> class unique_ptr<T[],D>;
```

## Contents
1. [shared_ptr](#shared_ptr)
2. [weak_ptr](#weak_ptr)
3. [unique_ptr](#unique_ptr)
4. (deprecated) [auto_ptr](#auto_ptr)

### 스마트 포인터
기존 포인터를 사용할 때 발생하는 문제점들, 특히 메모리 누수(memory leak) 이슈를 방지하기 위해 c++ 에서 구현된 wrapper class. Java나 C#의 Garbage Collector 대신 사용하는 메커니즘이다.


### shared_ptr
포인터의 소유권을 가지고, 그 **소유권을 공유**할 수 있는 스마트 포인터. <br>
여러 개의 shared_ptr가 하나의 객체를 참조할 수 있으며, 참조하는 스마트 포인터의 개수를 참조 횟수(reference count)라고 한다. <br>
소유권을 가진 마지막 객체가 소유권을 잃을 때, 즉 아무도 해당 포인터의 소유권을 갖지 않게 될 때, **참조 횟수가 0이 될 때** 포인터를 소멸시킨다. 
- 소유권을 잃는 경우
    1. 객체가 소멸될 때 (해당 객체가 선언된 scope 를 벗어날 때)
    2. 객체에 다른 값이 할당될 때
    3. `shared_ptr::reset` 명시적 호출


#### shared_ptr 동작
1. `shared_ptr`는 그 값을 복사함으로써 소유권만 공유한다
    - 두 개의 shared_ptr가 하나의 포인터(ptr)로부터 생성되면 두 개 다 ptr을 소유한다
    - 

2. `aliasing`: 
    - stored pointer
    - owned pointer

3. 순환 참조
    - 서로 다른 두 개의 shared_ptr 가 서로를 참조하는 경우
        - 간단히 말해서 두 개의 객체(A, B)가 각각 서로를 참조하는 shared_ptr를 가지고 있을 때, 각각의 reference count는 2 (처음 shared_ptr을 )
        - [reference count ex](../../cpp_practice/shared_ptr_circular_refer.cpp) 
    - 언제 이런 경우가 발생하는지, 누가 코드를 그렇게 짜는지 계속 고민을 했는데 이런 경우가 발생할지를 생각하지 않고 막 짜다 보면 충분히 발생 가능함
    - ex1. 그룹-멤버 의 관계에서 그룹이 멤버의 리스트를 가지고 있고, 멤버도 본인이 어떤 그룹에 속해 있는지 알기 위해 그룹의 포인터를 참조할 경우
        - [그나마 제일 이해가 잘 간 예시](https://3dmpengines.tistory.com/1622)
        - 이런 경우, 원래는 그룹의 id를 가지고 그룹 상위 Manager 에서 그룹을 찾아 필요한 행동을 하는 식으로 구현하는 게 맞고, 이게 너무 번거롭다고 생각되면 weak_ptr을 쓴다.


### weak_ptr
`shared_ptr`처럼 포인터를 공유할 수 있으나, 소유권은 없는 약한 스마트 포인터<br>
shared_ptr 인스턴스 사이의 순환 참조를 제거하기 위해 사용됨<br>
-> 즉, 항상 shared_ptr 와 함께 사용되며, 자원 상태를 확인하는 동시에 count 를 하고 싶지 않을 때 사용<br>
-> 그럼 누가 weak_ptr 을 release 해 주는가???<br>
    -> [TODO: 공부 후 정리해서 삭제하기](https://jungwoong.tistory.com/50)

> **정리**<br>
> 


### unique_ptr
제한된 GC(Garbage Collection) 기능을 제공하는 스마트 포인터로, 하나의 스마트 포인터만이 객체에 소유권을 가질 수 있다. <br>
즉 한번 소유권을 가지게 되면 소유권을 잃게 될 때 해당 포인터를 반드시 소멸시킨다. 소유권을 잃게 되는 경우는 [shared_ptr](#shared_ptr)와 동일하다. 
- 포인터를 혼자만 소유
    - 다른 객체가 `unique_ptr`이 가리키는 포인터에 대해 관여하지 않음
    - 다른 포인터가 동일한 포인터를 가리키는 것에 대해 막지는 않지만, `unique_ptr`이 소멸되면서 해당 포인터를 release하기 때문에 다른 포인터가 가리키는 값을 잃는 것에 대해서 보장하지 않음
    - C++14 이후로 지원하는 `make_unique()` 함수를 쓰면 예외에 대해서 안전하게 포인터 생성 가능
- components
    - stored pointer
        - This is set on construction, can be altered by an assignment operation or by calling member reset, and can be individually accessed for reading using members get or release.
    - stored deleter
        - a callable object that takes an argument of the same type as the stored pointer and is called to delete the managed object. It is set on construction, can be altered by an assignment operation, and can be individually accessed using member get_deleter.
- 소유권 이전
    - move() 멤버 함수를 통해 소유권을 이전할 수 있지만, 복사할 수는 없다.
    - 소유권이 이전되면, 이전 unique_ptr은 더이상 가리키던 객체를 소유하지 않는다. (즉, 소멸시킬 수 없다)
- 내부 동작
    - 엄밀히 말해서 unique_ptr은 포인터처럼 동작하게 만든 클래스 템플릿으로, 구현부에서 `*` 와 `->` 를 오버로딩해 객체에 저장된 포인터에 직접 접근할 수 있도록 하여 포인터 동작 구현

```c++
#include <memory>
using namespace std;

// example 1. 
unique_ptr<int> ptr01(new int(5)); // int형 unique_ptr인 ptr01을 선언하고 초기화함.
auto ptr02 = move(ptr01);          // ptr01에서 ptr02로 소유권을 이전함.
// unique_ptr<int> ptr03 = ptr01;  // 대입 연산자를 이용한 복사는 오류를 발생시킴. 
ptr02.reset();                     // ptr02가 가리키고 있는 메모리 영역을 삭제함.
ptr01.reset();                     // ptr01가 가리키고 있는 메모리 영역을 삭제함.

// example 2.
// C++14 이후로 make_unique() 함수 지원
unique_ptr<int> ptr03 = make_unique<int>(5);
int* intptr = ptr03.release();      // 저장된 포인터 리턴하고, 저장된 포인터는 nullptr로 초기화 
// 중요!! 리턴한 포인터를 해제하지 않기 때문에 따로 해제를 해줘야 한다

```

### auto_ptr
c++11 이전에 사용되던 스마트 포인터로, c++11 이후로는 대신 `unique_ptr`을 사용한다. 간단하게만 알아둘 것. <br>
제한된 garbage collection을 가지는데, 이 뜻은 어떤 포인터에 대해 소유권을 가지지만 auto_ptr가 소멸될 때 가리키는 포인터도 반드시 소멸시킨다. 즉, 동일한 포인터에 대해 두 개의 auto_ptr을 생성할 수 없다. 

- unique_ptr 에서 개선된 점
    - no fake copy assignments
    - deleter 기능 추가
    - 배열 지원

### 추가 공부할 내용

### Reference
- [cplusplus: shared_ptr](https://cplusplus.com/reference/memory/shared_ptr/)
- [aliasing](https://developers.redhat.com/blog/2020/06/02/the-joys-and-perils-of-c-and-c-aliasing-part-1)
- [cplusplus: unique_ptr](https://cplusplus.com/reference/memory/unique_ptr/)
- [smart pointers](https://www.geeksforgeeks.org/smart-pointers-cpp/)
- [shared_ptr: circular references example](https://www.learncpp.com/cpp-tutorial/circular-dependency-issues-with-stdshared_ptr-and-stdweak_ptr/)


======================================================
###### 230726 TIL
###### 230728 TIL
###### 230730 TIL
###### 230731 TIL
###### 230801 TIL
###### 230929 TIL
###### 230930 TIL