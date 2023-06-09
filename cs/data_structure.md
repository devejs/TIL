# Data Structure

## Why?
### 자료구조란?   
> 데이터를 효율적으로 접근, 수정, 저장, 관리하기 위해 구조화한 것

자료의 특성에 따라 분류, 저장, 처리하기 때문에 어떤 자료 구조를 쓰냐에 따라 데이터 처리의 성능이나 효율이 달라진다.

1. **선형** 자료 구조: 배열, 연결 리스트, 스택, 큐 등
2. **비선형** 자료 구조: 트리, 그래프 등

### 추상 자료형 (ADT)
> ADT(Abstract Data Type)<br>
> 구체적인 기능의 구현 과정을 언급하지 않고, 순수하게 기능이 무엇인지 나열한 것<br>

 > 예를 들어, C에서 구조체를 정의했을 때 해당 구조체가 특정 연산(기능)을 한다면, 그리고 그 연산/기능에 대해 정의되지 않았다면 이 자료형(구조체)은 완성된 것이 아니다??<br>
> 추가 공부 필요

** 중요한 것은, (예를 들어) 파일 입출력 할 때 FILE 구조체의 내부를 알 수는 없지만, 파일 관련한 모든 연산을 처리할 수 있다.


## 기초 자료구조
### 배열
**동일한 데이터형 변수**를 메모리상 **연속적인 공간**에 할당함<br>
다른 데이터형 변수를 가질 수 있는 구조체와는 다름
- 특징
    - 배열명이 곧 배열의 시작 주소 **상수**
    - 초기화
        1. 전체 초기화는 선언할 때만 가능: `{...};`
        2. 문자열 초기화/배열은 [여기 참고](../c_cpp/string.md)

### 2차원 배열

- 특징
    - 기존 1차원 배열과의 차이
    ```c++
    int a[5]; 
    // 라고 하면 열(column)이 5개인 배열로 본다
    int a[4][5];
    // 라고 하면 행(row) 4개에 열이 5개인 배열이다

    // 행/열의 구분의 의미
    // 메모리 주소를 생각하라!! 즉,
    // 1차원 배열: 0열-1열-2열-3열-... -> 메모리 증가
    // 2차원 배열: (0행)0열-1열-2열-3열-...-(1행)0열-1열-2열-...
    // 결국 2차원 배열도 메모리상에서는 일렬로 늘어진 배열
    // -> 행우선 배열
    ```
    - 이차원 배열의 포인터 타입
        ```c++
        void some_func(int (*p)[5]) { ... }
        ```
        - C에서 `int** p` 라고 쓰는 경우도 있는데, 이 경우 경고 발생하며 C++에서는 무조건 에러가 난다
        - 다차원 포인터
            - 배열의 시작 주소는 그 배열의 가장 큰 구성 요소의 한 차원 높은 주소
            ```
            // 구성 요소란? ex. a[4][5]
            1. int 방 4*5 = 20개
            2. int[5] 배열 * 4개
            // 여기서 가장 큰 구성 요소는 int[5] > int; int[5]
            // 이게 (int 배열)의 주소 로 타입을 표기하는 이유
            // 대신 이 때, *의 위치를 잘못 쓰면 다른 의미가 되기 때문에 int(*)[5]로 표기한다.
            ```


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

### 덱
Deque: Double-ended queue <br> 
데이터를 양방향으로 넣고 뺄 수 있는 자료구조<br>

* 배열이나 연결 리스트로 구현
* 다뤄야 할 주요 기능
    1. 덱 생성
    2. 덱 Empty 검사
    3. 덱의 머리에 데이터 추가/삭제
    4. 덱의 꼬리에 데이터 추가/삭제
    5. 덱의 모든 데이터 출력 
    6. 덱 소멸


### 해시 테이블
키(Key)와 값(Value)으로 이루어진 데이터를 저장하기 위한 자료구조<br>
검색하고자 하는 key를 해시 함수를 통해 해시값으로 변경, 해당 값을 index로 하여 value 저장/검색/관리
* 자료수 N과 관계 없이 빠른 성능을 가짐
* 배열이나 연결 리스트로 구현
* 다뤄야 할 주요 기능
    

> - slot: 1개의 레코드를 저장할 수 있는 공간; n개의 슬롯이 모여 버킷을 형성함 
> - bucket: 레코드를 저장하는 공간; 한 버킷은 하나 이상의 레코드를 수용함 
> - Hash Table: 버킷의 집합
> - key: 해시 테이블에서 레코드를 찾기 위한 값
> - Hash Value: 레코드를 해시 테이블에 저장하기 위한 위치 값
> - Hash Function: 키를 해시 값으로 바꿔주는 함수
> - *Hash Collision*: 서로 다른 2개 이상의 레코드가 같은 해시 값을 갖는 현상<br>
>   -> **해당 현상을 해결하는 것이 핵심**<br>
>   1) Synonym이 없게 해시 테이블 생성
>   2) Synonym이 있더라도 부가적인 방식으로 해결할 수 있게 해시 테이블 생성
> - Synonym: 같은 해시 값을 갖는 레코드들의 집합
> - Overflow: 계산된 해시 값의 bucket 내에 저장할 기억 공간이 없는 상태;
>   - 버킷을 구성하는 슬롯이 여러 개일 때는 Collision은 발생하나 Overflow는 발생하지 않을 수 있다. 
>   - 해시 테이블 > 버킷 > 슬롯
>   - 해시 값으로 찾아간 데이터는 결국 버킷 안의 슬롯에 들어있는 레코드; 버킷은 여러 개의 슬롯으로 이루어질 수 있으므로 해시 값이 충돌하더라도 저장할 여유 공간은 존재할 수 있다

* 해시 함수 작성시 고려사항
    * 평균적인 입력에 대해 해시값의 분포가 고르게 잡히는 것이 좋은 해시 함수
    * 특정 해시 값이 많이 나오게 되면 버킷이 넘치게 되므로 부가적인 작업 필요함
    * 해시 함수가 사용할 수 있는 연산 형태: `나머지, 제곱, 나누기, 합치기` 등
    * 해시 값은 테이블의 크기를 초과해서는 안 됨

### 해시 검색법
상수의 검색 시간을 가지는 매우 빠른 검색 기법

#### 해시 선형 탐색법
* 정적인 해시 테이블을 이용해 구현
    * 배열과 같이 이미 크기가 정해진 해시 테이블
* 자료 변동이 별로 없는 경우에 적합함
* 구현 난이도 쉬움
* 문제점: 속도 저하 이슈가 발생할 수 있음<br>
    -> 해시 테이블을 쓰는 이유가 빠른 속도(성능)인데, 속도가 선형 검색(N)에 가까워지면 사용 의미가 없음

#### 구현
```C++

// 구현해야 할 함수들

```
* [C로 구현]() <br>
* [C++로 구현]()


#### 해시 연결법(Seperate chaining)
동적 할당을 통해 해시 테이블의 크기보다 큰 자료를 저장<br>
기본적인 해시 테이블 + 연결 리스트 => 동적인 자료 검색
* 대용량 자료 처리에 유리함
    * 처리 가능한 자료 수가 메모리 limit이나 디스크 용량에 의해 결정됨
* 자료 변동이 별로 없는 경우에 적합함
* 구현 난이도 쉬움


### 트리
비선형으로, 계층 구조를 **표현**하기 적합한 자료구조<br>
* 노드의 관계가 1:N
* 서브 트리 구조
    - 특정 노드에서 그 아래 노드들과의 관계가 다시 한 번 트리 구조가 됨
    - 이 때 특정 노드 위의 노드를 `부모 노드`, 바로 아래 있는 노드를 `자식 노드` 라고 함
    - 같은 부모 노드를 가진 자식 노드들을 `형제 노드`
    - 가장 위에 있는 노드는 `루트 노드`
    - 레벨(level): 루트 노드에서 임의의 노드까지 방문한 노드의 수
    - 깊이(depth): 트리의 최대 레벨

### 이진 트리
모든 노드들의 자식 노드가 2개 이하인 트리<br>
* 서브 트리를 왼쪽/오른쪽으로 구분함
* 레벨이 d인 이진 트리의 노드 개수는 d `d <= N <= 2^d-1`
* 배열이나 연결 리스트로 구현
    - 데이터 영역
    - 왼쪽 자식 노드 포인터
    - 오른쪽 자식 노드 포인터

#### 이진 트리의 순회
이진 트리의 모든 노드를 특정한 순서대로 한 번씩 방문하는 것
1. 전위: 루트 노드 -> 왼쪽 서브 트리 -> 오른쪽 서브 트리
2. 중위: 왼쪽 서브 트리 -> 루트 노드 -> 오른쪽 서브 트리
3. 후위: 왼쪽 서브 트리 -> 오른쪽 서브 트리 -> 루트 노드

### 포화 이진 트리
모든 노드가 채워진 이진 트리<br>

### 완전 이진 트리
마지막 노드 번호와 노드 개수가 같은 이진 트리<br>
즉, 중간에 빠진 노드가 없는 이진 트리<br>
* 노드 번호 붙이는 규칙: root를 1로 시작해 왼쪽->오른쪽, 위->아래 순차적으로 번호를 붙인다.

### 힙
우선 순위가 높은 요소를 효율적으로 선택할 수 있는 자료구조<br>
주로 우선 순위 큐를 구현하는데 사용<br>
* 완전 이진 트리로 구현
    * 트리 구조에서 부모의 키 값 우선순위가 자식의 키 값보다 높게 구현
    * 힙의 root 노드가 가장 큰 우선 순위
    * 노드 추가시 마지막 번호 다음에만 추가하고, 마지막 번호만 삭제한다 (완전 이진 트리 유지)
* 최소 힙: 작은 숫자의 우선 순위가 높은 힙 (루트 최솟값)
* 최대 힙: 높은 숫자의 우선 순위가 높은 힙 (루트 최댓값)

#### 배열로 구현
* root node가 1번
    * 번호 j를 갖는 노드의 부모 노드는 j/2
    * 번호 j를 갖는 노드의 자식 노드는 `j*2`(왼쪽), `j*2+1`(오른쪽)


### 그래프
연결되어 있는 원소 간의 관계를 표현하는 자료구조<br>
정점(Vertex)과 간선(Edge)의 집합<br>
선형구조 및 트리 구조로 표현하기 어려운 다양한 연결 구조를 표현할 때 사용

* 그래프의 종류
    1. 무방향 그래프
        * 두 정점을 연결하는 간선의 방향이 없음
        * 정점 Vi,Vj를 연결하는 간선 `(Vi,Vj)`은 `(Vj,Vi)`와 동일
    2. 방향 그래프
        * 간선에 방향이 있음
        * `(Vi, Vj)`는 `Vi -> Vj`로, Vi를 머리(head), Vj를 꼬리(tail)라고 한다.
    3. 완전 그래프
        * 각 정점에서 다른 모든 정점을 연결하여 가능한 최대의 간선 수를 가지는 그래프
        * 정점이 n개의 그래프에서,
            * 무방향 그래프는 간선의 수 `n*(n-1)/2`
            * 방향 그래프는 간선의 수 `n*(n-1)`
    4. 부분 그래프
        * 그래프의 일부 정점과 간선을 제외하여 만든 그래프
    5. 가중치 그래프
        * 정점을 연결하는 간선에 가중치(weight)를 할당한 그래프



### Reference
- [인프런 판타스틱 자료구조 입문](https://www.inflearn.com/course/판타스틱-자료구조-입문)
- [인프런 판타스틱 자료구조](www.inflearn.com/course/판타스틱-자료구조-심화)
- 윤성우 열혈 자료구조


======================================================
###### 230612 TIL
###### 230615 TIL
###### 230616 TIL
###### 230617 TIL
###### 230623 TIL
###### 230624 TIL
###### 230625 TIL
###### 230626 TIL