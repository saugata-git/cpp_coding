#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>
#include <functional>

/*packaged_task */
int factorial(int n){
    int res = 1;
    for(int i=n; i>1 ; i--){
        res *= i;
    }
    std::cout << "Result is: " << res << std::endl;
    return res;
}

int main() {
  
    std::packaged_task<int(int)> t(factorial);
   
    //....

    //Can be executed in differnet context after certain interval
    t(6);

    // the  get the return value
    int x = t.get_future().get();

/*
    // if you directly want to pass the value
    std::packaged_task<int()> t(std::bind(factorial, 6));
    t();
*/

    return 0;
}

/*-----------------------------------------------------------------------*/

#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>
#include <functional>
#include <deque>
#include <condition_variable>


/*packaged_task */
int factorial(int n){
    int res = 1;
    for(int i=n; i>1 ; i--){
        res *= i;
    }
    std::cout << "Result is: " << res << std::endl;
    return res;
}

std::deque<std::packaged_task<int()>> task_q;
std::mutex mu;
std::condition_variable cond;

void thread_1(){
    std::packaged_task<int()> t;
    {
      std::unique_lock<std::mutex> locker(mu); 
      cond.wait(locker, [](){ return !task_q.empty();});
      t = std::move(task_q.front());
      task_q.pop_front();
    }   
    t();
}

int main() {
  
    std::thread t1(thread_1);
    std::packaged_task<int()> t(std::bind(factorial, 6));
    std::future<int> fu = t.get_future();
    {
      std::lock_guard<std::mutex> locker(mu); 
      task_q.push_back(std::move(t));
    }   
    cond.notify_one();

    std::cout<< fu.get();

    t1.join();
    /*
    auto t = std::bind(factorial, 6);   //function object
    t();
    */
    return 0;
}

/*
Promise :: get_future();
Packaged_task :: get_future();
async() returns a future;
*/







