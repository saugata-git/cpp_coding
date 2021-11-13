#include <iostream>
#include <string>
#include <fstream>
#include <thread>
#include <mutex>

class LogFile {
    std::mutex _mu;
    std::mutex _mu2;
    std::ofstream f;
public:
    LogFile(){
      f.open("log.txt");
    }   
    void sheared_print(std::string msg, int id){
        std::lock_guard<std::mutex> locker(_mu);
        std::lock_guard<std::mutex> locker2(_mu2);    
        std::cout<< msg << id <<std::endl;
    }

    void sheared_print2(std::string msg, int id){
     /* std::lock_guard<std::mutex> locker2(_mu2);
        std::lock_guard<std::mutex> locker(_mu);       // Dead lock  */       

        //No Dead Lock 
        std::lock_guard<std::mutex> locker(_mu);
        std::lock_guard<std::mutex> locker2(_mu2); 
        std::cout<< msg << id <<std::endl;
    }
    
};

void function_1(LogFile& log) {
    for(int i = 0; i >-100; i--)
    {
        log.sheared_print(std::string("From t1: "), i);
    }
}

int main() {
    LogFile log;
    std::thread t1(function_1,std::ref(log));  //t1 starts running 
    try
    {
        for(int i = 0; i < 100; i++)
        {
           log.sheared_print2(std::string("From Main: "), i);
        }
    }
    catch(...)
    {
       t1.join();
       throw;
    }
    t1.join();
    return 0;
}



/*-------------------------------------------------------------*/



#include <iostream>
#include <string>
#include <fstream>
#include <thread>
#include <mutex>

class LogFile {
    std::mutex _mu;
    std::mutex _mu2;
    std::ofstream f;
public:
    LogFile(){
      f.open("log.txt");
    }   
    void sheared_print(std::string msg, int id){
        std::lock(_mu, _mu2);
        std::lock_guard<std::mutex> lock(_mu ,std::adopt_lock);
        std::lock_guard<std::mutex> lock2(_mu2 ,std::adopt_lock);    
        std::cout<< msg << id <<std::endl;
    }

    void sheared_print2(std::string msg, int id){
 
        std::lock(_mu, _mu2);
        std::lock_guard<std::mutex> lock(_mu ,std::adopt_lock);
        std::lock_guard<std::mutex> lock2(_mu2 ,std::adopt_lock);    
        std::cout<< msg << id <<std::endl;
    }
};

void function_1(LogFile& log) {
    for(int i = 0; i >-100; i--)
    {
        log.sheared_print(std::string("From t1: "), i);
    }
}

int main() {
    LogFile log;
    std::thread t1(function_1,std::ref(log));  //t1 starts running 
    try
    {
        for(int i = 0; i < 100; i++)
        {
           log.sheared_print2(std::string("From Main: "), i);
        }
    }
    catch(...)
    {
       t1.join();
       throw;
    }
    t1.join();
    return 0;
}


/*
Avoiding deadlock
1. Perfer locking singke mutex at a time.
2. Avoid locking a mutex and then calling a user provided  function.
3. try to use std::lock() to lock more than one mutex.
4. lock mutex in same order.
*/



