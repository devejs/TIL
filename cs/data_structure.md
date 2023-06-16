# Data Structure

## Why?
### 자료구조란?   
> 데이터를 효율적으로 접근, 수정, 저장, 관리하기 위해 구조화한 것

자료의 특성에 따라 분류, 저장, 처리하기 때문에 어떤 자료 구조를 쓰냐에 따라 데이터 처리의 성능이나 효율이 달라진다.

1. **선형** 자료 구조: 배열, 연결 리스트, 스택, 큐 등
2. **비선형** 자료 구조: 트리, 그래프 등

## 기초 자료구조
### 배열
**동일한 데이터형 변수**를 메모리상 **연속적인 공간**에 할당함<br>
다른 데이터형 변수를 가질 수 있는 구조체와는 다름
- 특징
    - 배열명이 곧 배열의 시작 주소 **상수**
    - 초기화
        1. 전체 초기화는 선언할 때만 가능: `{...};`
        2. 문자열 초기화/배열은 [여기 참고](../c_cpp/string.md)

### 연결 리스트
데이터를 저장한 단위 메모리가 서로 연결됨 <br>
* 단위 메모리: `Node`; {데이터 저장 + 포인터}
* 다뤄야 할 주요 기능
    1. 연결 리스트 생성
    2. Node 추가
    3. 전체 Node 출력
    4. Node 검색/삭제/정렬
    5. 연결 리스트 소멸

#### 단일 연결 리스트
각 노드에 다른 노드를 가리키는 포인터가 하나씩만 있는 연결 리스트

> - Head Node: 연결 리스트의 첫 번째 노드
> - Head Pointer: Head Node를 가리키는 포인터 (필수)
> - Tail Node: 연결 리스트의 마지막 노드
> - Tail Pointer: Tail Node를 가리키는 포인터
> - Node count: Node의 개수; 혹은 실제 데이터를 가진 Node의 개수

* 단일 연결 리스트 관리  
    * Head Node, Tail Node에는 데이터를 넣지 않고 관리하는 방법<br>
    -> 실제 코드 작성시 편의성 증가<br>
    * *Why?*<br>
        * 모든 노드에 데이터를 넣을 경우
        ```c++
        // 특정 노드 삭제가 필요할 때
        if (HEAD_NODE 삭제) {...}
        else if (TAIL_NODE 삭제) {...}
        else {...}  // 중간 노드 삭제
        ```
        * 중간 노드에만 데이터를 넣을 경우
        ```c++
        // 모든 경우에 중간 노드만 삭제하게 되므로
        // 중간 Node만 처리하는 단일 코드 작성
        ```
        > HEAD, TAIL의 메모리는 증가하지만 코드가 깔끔해지고 처리 속도가 빨라짐



### 배열과 연결 리스트의 차이
|연결 리스트| Difference |배열|
|------|---|---|
|Node(구조체) 연결 방식|구현 방식|고정 크기 메모리|
|높음<br>필요한 만큼만 사용 가능|메모리 효용성|낮음<br>고정된 사이즈로 불필요한 메모리 사용|
|빠름<br>중간에 끊어서 다시 연결해주기 용이함|삽입&삭제 속도|느림<br>원소 이동 필요|
|느림<br>순차적으로 접근해야 함|원소 접근 속도|빠름<br>인덱스로 직접 접근|
|복잡|구현 복잡도|간단|


### 스택
데이터가 FILO(First In, Last Out) 으로 쌓이는 자료 구조<br>
입구와 출구가 동일
* 배열이나 연결 리스트로 구현
* 다뤄야 할 주요 기능
    1. 스택 생성
    2. 스택 Full/Empty 검사
    3. 스택 상단에 데이터 추가(push), 꺼내기(pop)
    4. 스택 내의 모든 데이터 출력 
    5. 스택 소멸

> - size: 스택의 공간 크기(저장 가능한 데이터의 양) 
> - push: 스택에 데이터를 넣음
> - pop: 스택에서 데이터를 꺼냄
> - top: 스택에서 데이터를 입출력할 데이터의 위치(index)

### 스택 구현
```C++
// 스택 관리 구조체
typedef struct_stack
{
    int *stack;     // 스태긍로 사용되는 동적할당 배열 주소
    int size;       // 스택의 크기
    int top;        // 스택의 입출력 위치 정보
} Stack;

// 구현해야 할 함수들
bool createStack();
bool isStackFull();
bool isStackEmpty();
bool push();
bool pop();
void printStack();
void destroyStack();
```
* [C로 구현]() <br>
* [C++로 구현]()


### 큐
데이터가 FIFO(First In, First Out) 으로 쌓이는 자료 구조<br>
입구와 출구가 구분됨
* 배열이나 연결 리스트로 구현
* 다뤄야 할 주요 기능
    1. 큐 생성
    2. 큐 Full/Empty 검사
    3. 큐에 데이터 추가(put), 꺼내기(get)
    4. 큐의 모든 데이터 출력 
    5. 큐 소멸

> - size: 큐의 공간 크기(저장 가능한 데이터의 양) 
> - put(enqueue): 큐에 데이터를 넣음
> - get(dequeue): 큐에서 데이터를 꺼냄
> - front: 큐에서 출력할 데이터의 위치(index); 첫번째 데이터 위치
> - rear: 큐에서 입력할 데이터의 위치(index); 마지막 데이터+1

#### 일반 큐를 쓰지 않는 이유
일자 큐는 1회성으로밖에 사용할 수 없다.<br>
```c++
// 큐가 비어있는 경우; front == rear
const int SIZE = 3;
int que = new int[SIZE];
int front = 0, rear = 0;

que[rear++] = 10;   // rear == 1;
que[rear++] = 20;   // rear == 2;
que[rear++] = 30;   // rear == 3;
// 큐가 꽉 차있음; SIZE == rear;

// 데이터를 빼냄
// dequeue 구현 안 되었으므로 front++ 로 get 처리
int data = queue[front++];  // front == 1;
data = queue[front++];      // front == 2;
data = queue[front++];      // front == 3;

/*
데이터를 전부 빼냈으므로 큐는 비어 있음
그런데???
SIZE == rear == front == 3
empty인지 full인지 알 수가 없는 상태가 됨
-> 재사용 불가
*/ 
```

### 원형 큐
일반 큐의 단점(1회성) 해결한 자료 구조<br>
FIFO를 유지하되, 큐의 입구와 출구 연결(당연하지만 물리적으로 연결한다는 뜻은 아님)
* 완충지대 개념 
    - 원형 큐의 Empty/Full 상태를 구분하기 위해 front/rear 사이 비어 있는 인덱스 개념 도입
    - 데이터 저장하지 않는 인덱스
    - `if (rear == 완충지대) { // Full };`
    - `if (front == rear) { // Empty };`
    - 이전 일자 큐가 문제였던 부분, 꽉 찬 상태일 때 front와 rear가 같은 곳을 가리키면 안 됨 => 완충지대가 필요한 이유
    - 완충지대 위치: **front 앞 index**
        - 원형 큐는 데이터를 빼고 넣으면서 계속 인덱스가 움직이기 때문에 완충지대 역시 움직이게 된다(무조건 마지막 x) 
* `rear = (rear+1) % Q_SIZE`

### 큐 구현
```C++
// 큐 관리 구조체
typedef struct_queue
{
    int *queue;         // 큐로 사용되는 동적할당 배열 주소
    int size;           // 큐의 크기
    int front, rear;    // 큐의 출/입력 위치 정보
} Que;

// 구현해야 할 함수들
bool createQueue();
bool isQueueFull();
bool isQueueEmpty();
bool enqueue();
bool dequeue();
void printQueue();
void destroyQueue();
```
* [C로 구현]() <br>
* [C++로 구현]()


### Reference
- [인프런 판타스틱 자료구조 입문](https://www.inflearn.com/course/판타스틱-자료구조-입문)



======================================================
###### 230612 TIL
###### 230615 TIL
###### 230616 TIL