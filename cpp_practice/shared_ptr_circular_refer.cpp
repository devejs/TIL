#include <iostream>
#include <memory>
#include <stdio.h>

class A
{
public:
    A()
    {
        printf("A Created\n");
    }
    ~A()
    {
        printf("A Destroyed\n");
    }

    shared_ptr

    void set_b_ptr()
    {
        printf("Create B ptr");
        
    }
};

class B
{
public:
    B()
    {
        printf("basic B Created\n");
    }

    B(shared_ptr<A> a)
    {
        
    }
    
};

void count_referCount()
{
    printf("count_referCount called\n");
};

int main()
{
    printf("Program start!\n");
    

    return 0;
}