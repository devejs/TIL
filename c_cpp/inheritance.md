# Inheritance

## 상속


### Example
```c++
#include <iostream>
#include <stdio.h>

using namespace std;

class A
{
public:
    A();
protected:
    virtual void init_func();
    virtual void protected_func();
}

class B : public A
{
public:
    B();
protected:
    virtual void protected_func();
}

A::A()
{
    printf("A constructor\n");
    init_func();
}

void A::init_func()
{
    printf("A init_func\n");
    protected_func();
}

void A::protected_func()
{
    printf("A protected_func\n");
}

void B::B() : A()
{
    printf("B constructor");
}

int main()
{
    printf("start practicing...\n");
    A* ptr = new B();
    
    // ptr->init_func();    /* error */

    return 0;   
}
```