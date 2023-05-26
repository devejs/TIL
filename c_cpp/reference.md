# Reference

## Reference(참조자) 란?
C에서는 없었던 개념으로서 포인터 대신 어떤 변수나 상수를 가리킬 수 있는 방식   
```c
#include <iostream>

int main()
{
  int a = 10;
  int* ap = &a;
  int& ref_a = a;   //참조자 정의; 타입 뒤에 & 붙여서 정의한다
  int* refap = &ref_a;

  printf("a value: %d, address: %p\n", a, ap);
  printf("ref_a value: %d, address: %p\n", ref_a, refap);
  
  a = 5;
  printf("a value: %d, address: %p\n", a, ap);
  printf("ref_a value: %d, address: %p\n", ref_a, refap);

  ref_a = 7;
  printf("a value: %d, address: %p\n", a, ap);
  printf("ref_a value: %d, address: %p\n", ref_a, refap);

  return 0;

}
}

// result
a value: 10, address: 0x7ffeedb46968
ref_a value: 10, address: 0x7ffeedb46968
a value: 5, address: 0x7ffeedb46968
ref_a value: 5, address: 0x7ffeedb46968
a value: 7, address: 0x7ffeedb46968
ref_a value: 7, address: 0x7ffeedb46968
```
결과를 확인해 보면, 기존 변수 a와 a의 참조자 ref_a의 주소가 동일한 것을 볼 수 있다.   
즉, 주소값을 저장해서 변수가 아닌 직접 주소로 접근하여 사용하는 포인터와 다르게, 참조자는 말 그대로 변수에 접근할 수 있는 이름표를 하나 더 붙여준다고 생각하면 된다.

### 이게 왜 필요한가?
참조자 개념을 처음 배울 때 제일 먼저 들었던 질문. 기존에 포인터가 있는데 왜 굳이 참조자를 사용할까?   
-> 코드가 훨씬 깔끔하고 간결해짐



## 좌측값 / 우측값
- 좌측값: 주소값을 가지고 올 수 있는 값
    - ex. ***int a*** = 3;  // 좌측값은 a 
    - 어떤 표현식의 왼쪽에도 오른쪽에도 올 수 있음
- 우측값: 주소값을 가지고 올 수 없는 값; 즉, 어떤 표현식이 실행될 때에만 잠시 존재하는 값
    - ex. int a = ***3***; // 우측값은 3
    - 어떤 표현식의 오른쪽에만 올 수 있음
    - 레퍼런스를 가질 수 없음(주소값을 가지고 올 수 없기 때문)
    - 우측값은 이름이 없다

- 좌측값 레퍼런스: 일반적으로 참조자라고 말하는 레퍼런스; &로 정의함
- 우측값 레퍼런스
    - 우측값은 주소가 없으므로 레퍼런스를 가질 수 없음
    - 그러나, `const T&` 타입에 한해서 우측값을 레퍼런스로 받을 수 있는 경우가 생김
        -> 왜? `const`이기 때문에 임시로 존재하는 객체의 값을 참조는 할 수 있으나, 변경할 수 없음
        <!-- 
        우측값 레퍼런스 설명하는 예제 코드에서, 
        MyString MyString::operator+(const MyString &s)
        여기서 리턴값이 우측값이라고 얘기하고 있는데 오버로딩된 연산자 내부에서 객체를 선언하고 그걸 리턴하기 때문에 결국 리턴되는 값은 이름 없는/해당 함수 문장이 끝나면 사라지는 값이라서 우측값이라고 하는 건가?
        
        그리고 이 우측값이 어떻게 좌측값 레퍼런스를 인자로 받는 생성자를 호출할 수 있었냐고 하는데 이 내용이 어디 있는 건지 모르겠음ㅠ
        -->

- 이 내용에 이어지는 추가 공부는 [생성자](constructor.md)로







### Reference
- [모두의 코드:참조자](https://modoocode.com/141)
- [모두의 코드: 우측값 레퍼런스](https://modoocode.com/227)



======================================================
###### 230525 TIL
###### 230526 TIL
