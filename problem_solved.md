# 이슈 디버깅

## 맥 g++ 환경 이슈
```
Undefined symbols for architecture x86_64:
  "Executor::Executor()", referenced from:
      _main in example-c7b49b.o
  "xec", referenced from:
     implicit entry/start for main executable
     (maybe you meant: Executor::solution(int), Executor::solution() , Executor::get_input() )
ld: symbol(s) not found for architecture x86_64
clang: error: linker command failed with exit code 1 (use -v to see invocation)
```
```
Undefined symbols for architecture x86_64:
  "vtable for B", referenced from:
      B::B() in test-b143fb.o
  NOTE: a missing vtable usually means the first non-inline virtual member function has no definition.
ld: symbol(s) not found for architecture x86_64
clang: error: linker command failed with exit code 1 (use -v to see invocation)

```