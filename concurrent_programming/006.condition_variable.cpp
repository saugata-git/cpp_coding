#include <iostream>
#include <string>
#include <deque>
#include <condition_variable>
#include <fstream>
#include <chrono>
#include <thread>
#include <mutex>

std::deque<int> dq;
std::mutex mu;
std::condition_variable cond;

void function_1() {
    int count = 10;
    while( count > 0){
        std::unique_lock<std::mutex> locker(mu);
        dq.push_front(count);
        locker.unlock();
        cond.notify_one();  //Notify one wating thread if one  // notify_all()
        std::this_thread::sleep_for(std::chrono::seconds(1));
        count--;
    }    
}

void function_2(){
    int data = 0;
    while(data != 1){
        std::unique_lock<std::mutex> locker(mu);
        cond.wait(locker, [](){ return !dq.empty();});     //spurious wake
        data = dq.back();
        dq.pop_back();
        locker.unlock();
        std::cout << "t2 got a value from t1: "<< data <<std::endl; 
    }
}

int main() {
    std::thread t1(function_1);
    std::thread t2(function_2);
    t1.join();
    t2.join();
    return 0;
}


