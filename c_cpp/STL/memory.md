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

### shared_ptr
포인터의 소유권을 가지고, 그 **소유권을 공유**할 수 있는 스마트 포인터. <br>
소유권을 가진 마지막 객체가 소유권을 잃을 때, 즉 아무도 해당 포인터의 소유권을 갖지 않게 될 때 포인터를 소멸시킨다. 
- 소유권을 잃는 경우
    1. 객체가 소멸될 때
    2. 객체에 다른 값이 할당될 때
    3. `shared_ptr::reset` 명시적 호출

#### shared_ptr 동작
1. `shared_ptr`는 그 값을 복사함으로써 소유권만 공유한다
    - 두 개의 shared_ptr가 하나의 포인터(ptr)로부터 생성되면 두 개 다 ptr을 소유한다
    - 

2. `aliasing`: 
    - stored pointer
    - owned pointer

### weak_ptr
`shared_ptr`처럼 포인터를 공유할 수 있으나, 소유권은 없는 약한 스마트 포인터<br>


### unique_ptr
제한된 GC(Garbage Collection) 기능을 제공하는 스마트 포인터로, 즉 한번 소유권을 가지게 되면 소유권을 잃게 될 때 해당 포인터를 반드시 소멸시킨다. 소유권을 잃게 되는 경우는 [shared_ptr](#share_ptr)와 동일하다. 
- 포인터를 혼자만 소유
    - 다른 객체가 `unique_ptr`이 가리키는 포인터에 대해 관여하지 않음
    - 다른 포인터가 동일한 포인터를 가리키는 것에 대해 막지는 않지만, `unique_ptr`이 소멸되면서 해당 포인터를 release하기 때문에 다른 포인터가 가리키는 값을 잃는 것에 대해서 보장하지 않음
- components
    - stored pointer
        - This is set on construction, can be altered by an assignment operation or by calling member reset, and can be individually accessed for reading using members get or release.
    - stored deleter
        - a callable object that takes an argument of the same type as the stored pointer and is called to delete the managed object. It is set on construction, can be altered by an assignment operation, and can be individually accessed using member get_deleter.


### 추가 공부할 내용

### Reference
- [cplusplus: shared_ptr](https://cplusplus.com/reference/memory/shared_ptr/)
- [aliasing](https://developers.redhat.com/blog/2020/06/02/the-joys-and-perils-of-c-and-c-aliasing-part-1)
- [cplusplus: unique_ptr](https://cplusplus.com/reference/memory/unique_ptr/)


======================================================
###### 230726 TIL
###### 230728 TIL