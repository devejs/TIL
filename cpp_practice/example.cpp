#include "./interface.h"

class Executor : public Interface
{
    public: 
        Executor() {};
        ~Executor() {};

        int get_input();
        int solution();
        int solution(int answer);
};

int Executor::get_input()
{
    int a = 1;
    return a;
}

int Executor::solution()
{
    printf("Executor solution\n");
    return 0;
}

int Executor::solution(int answer)
{
    printf("print answer: %d\n", answer);
    return 0;
}

int main(int argc, const char * argv[])
{
    Executor* app = new Executor();
    int input = app->get_input();
    app->solution();
    app->solution(input);

    return 0;
}
