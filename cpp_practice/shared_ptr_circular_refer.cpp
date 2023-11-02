#include <iostream>
#include <memory>
#include <stdio.h>

using namespace std;

class A
{
class B;

public:
    A()
    {
        printf("A Created\n");
    }
    ~A()
    {
        printf("A Destroyed\n");
    }

    shared_ptr<B> b_ptr;

    void set_b_ptr()
    {
        printf("Create B ptr");
        b_ptr = make_shared<B>(this);
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
        printf("B Created\n");
    }
    
};

void count_referCount()
{
    printf("count_referCount called\n");
};

int main()
{
    printf("Program start!\n");
    // create normal A
    // A* a = new A();
    // create shared_ptr
    shared_ptr<A> share_a = make_shared<A>();
    int use_a = share_a.use_count();
    // why use . not -> ??
    printf("a use count: %d\n", use_a);
    share_a->set_b_ptr();
    int use_b = share_a->b_ptr.use_count();
    printf("b use count: %d\n", use_b);

    return 0;
}






/* Error Log




*/