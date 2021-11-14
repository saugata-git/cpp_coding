#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>
#include <functional>
#include <deque>
#include <chrono>

int factorial(int n){
   int res = 1;
   for(int i=n; i>1 ; i--){
       res *= i;
   }
   std::cout << "Result is: " << res << std::endl;
   return res;
}

int main() {

   /* thread */
   std::thread t1(factorial, 6);
   std::this_thread::sleep_for(std::chrono::milliseconds(3));
   chrono::steady_clock::time_point tp = chrono::steady_clock::now() + chrono::microseconds(4);
   std::this_thread::sleep_until(tp);

   /* Mutex */
   std::mutex mx;
   std::lock_guard<std::mutex> locker(mu);
   std::unique_lock<std::mutex> ulocker(mu);
   ulocker.try_lock();
   ulocker.try_lock_for(chrono::nanoseconds(500));
   ulocker.try_lock_until(tp);

   /* Condition Varivale */
   std::condition_variable cond;
   cond.wait_for(ulocker, std::chrono::microseconds(2));
   cond.wait_until(ulocker, tp);

   /* Future and Promise */
   std::promise<int> p;
   std::future<int> f = p.get_future();
   f.get();
   f.wait();
   f.wait_for(std::chrono::microseconds(2));
   f.wait_until(std::chrono::microseconds(2));
   
   /* async() */
   std::future<int> fu = async(std::launch::async, factorial, 6);

   /* Packaged Task */
   std::packaged_task<int(int)>  t(factorial);
   std::future<int> fu2 = t.get_future();
   t(6);

   return 0;
}

