# Memory
```C++
using namespace std;
#include <memory>

template <class T> class shared_ptr;
template <class T> class weak_ptr;
```

## Contents
1. [shared_ptr](#shared_ptr)
2. [weak_ptr](#weak_ptr)

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



### 추가 공부할 내용

### Reference
- [cplusplus: shared_ptr](https://cplusplus.com/reference/memory/shared_ptr/)
- [aliasing](https://developers.redhat.com/blog/2020/06/02/the-joys-and-perils-of-c-and-c-aliasing-part-1)


======================================================
###### 230726 TIL