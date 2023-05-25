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










### Reference
- [모두의 코드:참조자](https://modoocode.com/141)
- [모두의 코드: 우측값 레퍼런스](https://modoocode.com/227)



======================================================
###### 230525 TIL
