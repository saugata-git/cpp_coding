#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>

class A{
public:
   void f(int x, char c) {}
   long g(double x) { return 0;}
   int operator()(int N) { return 0;}
};

void foo(int x){

}

int main() {
    A a;
    std::thread t1(a, 6);              // copy of a() in diffrent thread
    std::thread t2(std::ref(a), 6);    // a() in diffrent thread
    std::thread t8(std::move(a), 6);   // a is no longer usable in parent thered
    std::thread t4([](int x){return x*x;}, 6);
    std::thread t5(foo, 7);

    std::thread t6(&A::f, a, 8, 'w');   // copy of a.f(8, 'w') in different thread
    std::thread t7(&A::f, &a, 8, 'w');  // a.f(8, 'w') in different thread

    /* std::async(std::launch::async, a, 6);
    std::bind(a,6);
    std::call_once(once_flag, a, 6); */

    return 0;
}
