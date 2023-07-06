# STL이란?
STL(Standard Template Library)<br>
C++의 [Template]()을 이용해 미리 이용할 수 있는 자료구조 등의 클래스 템플릿(class template)들을 표준 라이브러리로 정의해놓은 것<br>
이미 만들어져 있는 알고리즘이나 자료구조 등을 가져다 쓸 수 있다<br>
클래스 템플릿 형태로 구현되어 있기 때문에 임의의 타입의 원소들을 위한 컨테이너를 만들 수 있다

## STL 종류
![가져다 쓸 수 있는 라이브러리 종류](https://i.stack.imgur.com/kQnCS.png)<br>
[C++ Container Cheat Sheet](https://web.archive.org/web/20180824133558/homepages.e3.net.nz/%7Edjm/cppcontainers.html)

## 컨테이너(Container)
같은 타입의 여러 객체를 저장하는 일종의 집합<br>

1. 시퀀스 컨테이너(sequence container)
2. 연관 컨테이너(associative container)
3. 컨테이너 어댑터(adapter container)

| Type | Description | Examples |
|------|------|------|
| 시퀀스 컨테이너 | 데이터를 선형으로 저장하며, 특별한 제약이나 규칙이 없는 가장 일반적인 컨테이너 | vector, deque, list, forwad_list |
| 연관 컨테이너 | 데이터를 일정 규칙에 따라 조직화하여 저장하고 관리하는 컨테이너 | set, multiset, map, multimap |
| 컨테이너 어댑터 | 간결함과 명료성을 위해 인터페이스를 제한한 시퀀스나 연관 컨테이너의 변형 <br> 단, 반복자를 지원하지 않음 | stack, queue, priority_queue |


### STL 공부 리스트
1. 순차 컨테이너 (Sequence Container)
    - [vector](./vector.md): 벡터 (Vector)
    - [deque](): 데크 (double ended queue)
    - [list](): 리스트 (List)

2. 연관 컨테이너
    - [set]() : Set
    - [multiset]() : 여러 키를 가지는 set
    - [map]() : Map
    - [multimap]() : 여러 키를 가지는 map
    - [bitset]() : Bitset

2. 컨테이너 어댑터 (Container Adaptor)
    - [stack]() : LIFO (Last in First out) 스택
    - [queue]() : FIFO (First in First out) 큐
    - [priority_queue]() : 우선순위 큐 (Priority queue)


### Reference
[스택 오버플로우](https://stackoverflow.com/questions/471432/in-which-scenario-do-i-use-a-particular-stl-container)<br>
[TCP 코딩 스쿨](http://www.tcpschool.com/cpp/cpp_container_intro)<br>
[모두의 코드](https://modoocode.com/174)