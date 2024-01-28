# Chapter 1. 타입 추론하기 (Deducing Types)

C++98 에는 타입 추론에 대한 일련의 규칙이 있다: 함수 템플릿에 관한 규칙이다. C++11은 그 규칙을 조금 수정하고 2가지를 더했는데, 하나는 `auto`이고 하나는 `decltype` 이다. C++14는 `auto`와 `decltype`이 사용되는 문맥(용법)을 확장했다. 타입 추론을 점점 더 많이 사용하면서 너무 명백하거나 불필요하게 많이 타입을 일일이 명시할 필요가 없어졌다. 소스코드에서 타입을 특정 위치에서 바꾸면 자동으로 다른 위치까지 타입 추론을 통해 자동으로 바뀌기 때문에 C++ 소프트웨어를 좀 더 유연하게 사용할 수 있게 되었다. 하지만 컴파일러에 의해 타입이 추론되는 것은 그렇게 명확하지 않기 때문에 코드를 해석하기 더 어려워질 수 있다.
타입 추론이 어떻게 작용하는지 확실히 이해하지 않으면 모던 C++ 에서 효율적인 프로그래밍은 거의 불가능하다. 타입 추론은 함수 템플릿을 호출할 때, `auto` 를 사용하는 대부분의 상황, `decltype` 구문, C++14에서 헷갈리는 `decltype(auto)` 구조체가 동작할 때 등 매우 많은 상황에서 사용된다. 이번 챕터에서는 모든 c++ 개발자가 필요한 타입추론에 관한 내용에 대해 다룬다. 어떻게 템플릿 타입 추론이 동작하는지, `auto`가 그 기반에서 동작하는지, `decltype`은 어떻게 작동하는지 등을 설명한다. 추가로 컴파일러의 타입 추론 결과를 보이게 하여 사용자가 원하는 타입을 추론하고 있는 것을 확인할 수 있다.

## Item 1: 템플릿 타입 추론 이해하기 (Understand template type deduction)

사용자가 복잡한 시스템이 어떻게 동작하는지는 몰라도 그 결과에 만족한다는 것은 그 시스템의 설계에 대해 많은 것을 알려준다. 그런 의미에서 템플릿 타입 추론은 C++ 에서 엄청난 성공을 거뒀다. 수많은 프로그래머들이 템플릿 함수들에서 사용되는 타입들이 어떻게 추론되는지 정확히 설명하기 어렵지만 그 함수로 인자를 넘기면서 예상하는 결과를 얻는다.
만약 당신도 그렇다면, 좋은 소식과 나쁜 소식이 있다. 좋은 것은 템플릿에서의 타입 추론이 모던 C++의 가장 강력한 기능중 하나인 `auto`의 기초라는 것이다. 당신이 C++98에서 템플릿 타입 추론하는 것에 만족했다면 C+11에서 `auto`로 타입 추론하는 것도 좋아할 것이다. 반면 나쁜 소식은 템플릿 타입 추론 규칙이 `auto`에 적용될 때 종종 템플릿에서 적용되는 것만큼 직관적이지 않다는 것이다. 그래서 `auto`가 기반하는 템플릿 타입 추론을 온전히 이해하는 것이 중요하다. 이것이 당신이 알아야 하는 것을 커버한다.
수도 코드로 살펴보면, 함수 템플릿은 다음과 같다.
```C++
template<typename T> void f(ParamType param);   // function template

f(expr); // call f with some expression

```

컴파일 하는 동안 컴파일러는 `expr` 을 사용해 두 가지 타입을 추론하는데, 하나는 T이고 하나는 ParamType 이다. ParamType이 const나 참조 한정자와 같은 키워드를 가지고 있는 경우가 많기 때문에 이 타입들은 자주 달라질 수 있다.
예를 들어, 함수 템플릿이 다음과 같이 선언된다면
```C++
template<typename T> void f(const T& param);    // ParamType is const T&

int x = 0;
f(x);       // call f with an int
```
T는 `int`로, ParamType은 `const int&`로 추론된다.
T의 타입은 함수에 전달된 인자와 동일한 타입, 즉 expr의 타입으로 추론하는 것이 자연스럽다. 위 예시가 x가 int이고, T는 int로 추론되는 경우이다. 하지만 항상 이렇게 동작하는 것은 아니다. T가 추론되는 타입은 expr의 타입에만 의존하는 것이 아니라 ParamType의 형태에도 의존한다. 다음 세 가지 경우가 있다.
1. ParamType 은 포인터나 참조자 타입이나 보편적인 참조는 아니다. (보편적인 참조는 Item 24에서 설명한다.) 여기서 알아야 하는 것은 보편적인 참조자가 존재하며 lvalue 참조와 rvalue 참조가 같지 않다는 것이다.
    <details>
    <summary>1번 내용 추가 공부 필요</summary>

    ParamType is a pointer or reference type, but not a universal reference. (Univer‐ sal references are described in Item 24. At this point, all you need to know is that they exist and that they’re not the same as lvalue references or rvalue references.)
    </details>
2. ParamType은 보편적인 참조자이다.
3. ParamType은 포인터도 아니고, 참조자도 아니다. 

이렇게 3가지의 타입 추론 시나리오가 있고, 각각은 일반적으로 템플릿과 템플릿을 호출하는 일반적인 형태에 의존한다.

```C++
emplate<typename T> void f(ParamType param);
f(expr);     // deduce T and ParamType from expr
```

### Case 1: ParamType이 참조자나 포인터이나 보편적인 참조자가 아닌 경우
가장 단순한 상황이다. 이 경우, 타입 추론은 다음과 같이 동작한다
1. expr의 타입이 참조자이면, 참조자 부분을 무시한다.
2. Then pattern-match expr’s type against ParamType to determine T.

예를 들면, 
```C++
template<typename T>
void f(T& param);   // param is a reference

int x = 27;             // x is an int
const int cx = x;       // cx is a const int
const int& rx = x;      // rx is a reference to x as a const int

// expr 의 값에 따른 param과 T의 타입 추론 형태
f(x);               // T is int, param's type is int&
f(cx);              // T is const int,
                    // param's type is const int&
f(rx);              // T is const int,
                    // param's type is const int&
```

두번째와 세번째 호출에서, cx와 rx가 const 값으로 설계되었기 때문에 T가 `const int` 로 추론되고, 그에 따라 매개변수(Parameter) 타입이 `const int&`가 된 것임을 알아야 한다. 호출자에게 그것이 중요하다. 참조 매개변수에 const 객체를 전달하면, 그 객체는 변하지 않으므로 매개변수가 const에 대한 참조자가 된다. 객체의 상수성이 T의 타입 추론에 일부가 되는 것으로, const 객체를 `T&` 매개변수를 갖는 템플릿에 전달하는 것이 안전한 이유이다.
세번째 예시에서, rx의 타입이 참조자더라도 T는 non-reference 타입으로 추론된다. rx의 참조성이 타입 추론중 무시되기 때문이다.
    <details>
    <summary>추가 공부 필요</summary>

In the third example, note that even though rx’s type is a reference, T is deduced to be a non-reference. That’s because rx’s reference-ness is ignored during type deduc‐ tion.
    </details>


### Chapter 1. voca
- deduction: the process of reaching a decision or answer by thinking about the known facts, or the decision that is reached
    - `type deduction` vs `type inference`
        - [여기 참고](https://stackoverflow.com/questions/36465664/whats-the-difference-between-c-type-deduction-and-haskell-type-inference)
        - 요약: 주로 프로그래밍 언어 전반에서 타입 추론에 대해 말할 때 type inference 를 쓰는데(General함), c++ 에서는 유달리(?) type deduction을 씀. 아마 Template argument deduction 의 영향을 받은 듯.
- inference: a guess that you make or an opinion that you form based on the information that you have
- tyranny: unlimited authority or use of power, or a government which exercises such power without any control or limits
    - tyrant(noun), tyrannical(adj), tyrannize(verb)
    - text: `type deduction frees you from the tyranny of spelling out types that are obvious or redundant`
- redundant: not or no longer needed or useful; superfluous
    - superfluous: unnecessary, especially through being more than enough.
    - In computer programming, redundant code is source code or compiled code in a computer program that is unnecessary
        - 실행되지 않는 코드 (unreachable code)나 실행되지만 영향이 없는 코드(dead code)
            ```C++
            int foo(int par)
            {
                int redundant = par*2;

                return par*2;
            }
            ```
    - text: tyranny 참조
- propagate: to transmit something through a medium / extend / publicize
    - text: `It makes C++ software more adaptable, because changing a type at one point in the source code automatically propagates through type deduction to other locations`
- render: to cause someone or something to be in a particular state(cause), to give something to someone(give)
    - text: `it can render code more difficult to reason about, because the types deduced by compilers may not be as apparent as you’d like.`
- enigmatic: mysterious and impossible to understand completely
    - text: `in most situations where auto appears, in decltype expressions, and, as of C++14, where the enigmatic decltype(auto) construct is employed`
- hard-pressed: experiencing a lot of difficulty
- hazy: not remembering things clearly; not clear because of haze(fog)
- compelling: 
    - text: `type deduction for templates is the basis for one of modern C++’s most compelling features`
- reference qualifier
    - qualifier

- yield: to give up the control of or responsibility for something, often because you have been forced to

- aliasing: In computing, aliasing describes a situation in which **a data location in memory can be accessed through different symbolic names** in the program. Thus, modifying the data through one name implicitly modifies the values associated with all aliased names, which may not be expected by the programmer. As a result, aliasing makes it particularly difficult to understand, analyze and optimize progra


### 추가 공부
#### reference type
참조자는 객체를 대체할수 있는 이름 혹은 별명(alias)이다. 참조자에 적용되는 모든 동작들이 참조자가 참조하는 객체에 작용한다. 참조자의 주소는 진짜 객체(별명의 진짜 주인)의 주소이다. 
참조자 타입은 좌측값 참조자와 우측값 참조자를 모두 포함한다. 좌측값 참조자 타입은 형식 지정자(type specifier) 뒤에 `reference modifier &` 을 위치시켜 정의한다. 우측값 참조자는 형식 지정자 뒤에 `reference modifier &&` 를 위치시켜 정의한다. 
함수 매개변수를 제외한 모든 참조자들은 반드시 정의될 때 초기화되어야 한다. 타겟의 별명(alias)이기 때문에 참조자는 한번 정의되면 재할당될 수 없다. 참조자를 재할당하려고 하면 타겟에 새로운 값이 할당되는 것을 볼 수 있다.
함수의 인자가 값으로 전달되기 때문에, 함수 호출은 인자의 실제 값을 변경할 수 없다. 만약 함수가 인자의 실제 값을 수정하거나 한 개 이상의 값을 반환해야 한다면 인자는 반드시 참조로 전달되어야 한다. 참조로 인자를 전달하는 것은 참조자를 사용하거나 포인터를 사용한다. C와 다르게 C++은 참조로 값을 전달할 때 반드시 포인터를 사용할 필요는 없다. 참조자를 사용하는 문법이 포인터를 사용하는 것보다 다소 간단하다.
값을 참조로 전달하면 함수 내에서 복사본 없이 참조된 객체를 변경할 수 있다. 전체 객체가 아니라 원본 객체의 주소만 스택에 올라간다.
- 예시
    ```C++
    int f(int&);
    
    int main()
    {
        extern int i;
        f(i);
    }
    ```
- 참조가 불가능한 객체
    - NULL
    - void
    - invalid objects or functions
    - bit field
    - 참조자(reference)
        - [Reference collapsing](https://www.ibm.com/docs/en/i/7.3?topic=operators-reference-collapsing-c11)

- [참고 문서](https://www.ibm.com/docs/en/i/7.3?topic=declarators-references-c-only)

======================================================
###### 240125 TIL
###### 240127 TIL
###### 240128 TIL