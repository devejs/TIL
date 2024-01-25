# Chapter 1. 타입 추론하기 (Deducing Types)

C++98 에는 타입 추론에 대한 일련의 규칙이 있다: 함수 템플릿에 관한 규칙이다. C++11은 그 규칙을 조금 수정하고 2가지를 더했는데, 하나는 `auto`이고 하나는 `decltype` 이다. C++14는 `auto`와 `decltype`이 사용되는 문맥(용법)을 확장했다. 타입 추론을 점점 더 많이 사용하면서 너무 명백하거나 불필요하게 많이 타입을 일일이 명시할 필요가 없어졌다. 소스코드에서 타입을 특정 위치에서 바꾸면 자동으로 다른 위치까지 타입 추론을 통해 자동으로 바뀌기 때문에 C++ 소프트웨어를 좀 더 유연하게 사용할 수 있게 되었다. 하지만 컴파일러에 의해 타입이 추론되는 것은 그렇게 명확하지 않기 때문에 코드를 해석하기 더 어려워질 수 있다.
타입 추론이 어떻게 작용하는지 확실히 이해하지 않으면 모던 C++ 에서 효율적인 프로그래밍은 거의 불가능하다. 타입 추론은 함수 템플릿을 호출할 때, `auto` 를 사용하는 대부분의 상황, `decltype` 구문, C++14에서 헷갈리는 `decltype(auto)` 구조체가 동작할 때 등 매우 많은 상황에서 사용된다. 이번 챕터에서는 모든 c++ 개발자가 필요한 타입추론에 관한 내용에 대해 다룬다. 어떻게 템플릿 타입 추론이 동작하는지, `auto`가 그 기반에서 동작하는지, `decltype`은 어떻게 작동하는지 등을 설명한다. 추가로 컴파일러의 타입 추론 결과를 보이게 하여 사용자가 원하는 타입을 추론하고 있는 것을 확인할 수 있다.


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




======================================================
###### 240125 TIL