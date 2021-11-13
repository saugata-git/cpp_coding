#include <iostream>
#include <string>
#include <fstream>
#include <thread>
#include <mutex>

class LogFile {
    std::mutex _mu;
    std::ofstream f;
public:
    LogFile(){
      f.open("log.txt");
    }   
    void sheared_print(std::string msg, int id){
        std::unique_lock<std::mutex> locker(_mu ,std::defer_lock);
        //do some thing 
        locker.lock();
        std::cout<< msg << id <<std::endl;
        locker.unlock();

        //do something else 
        /*locker.lock();
        std::cout<< msg << id <<std::endl;
        locker.unlock();*/

        //lock guard can nver be moved but unique lock can be
        //std::unique_lock<std::mutex> locker2 = std::move(locker);
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
           log.sheared_print(std::string("From Main: "), i);
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

/*--------------------------------------------------*/

#include <iostream>
#include <string>
#include <fstream>
#include <thread>
#include <mutex>

class LogFile {
    std::mutex _mu;
    std::once_flag _flag;
    std::ofstream f;
public:
    LogFile(){ 
    }   
    void sheared_print(std::string msg, int id){
       /*
         std::unique_lock<std::mutex> locker2(_mu_open); 
        if(!f.is_open()){
           f.open("log.txt");
        }
        */
        std::call_once(_flag,[&](){f.open("log.txt");});
        std::unique_lock<std::mutex> locker(_mu);
        f<< msg << id <<std::endl;
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
           log.sheared_print(std::string("From Main: "), i);
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



