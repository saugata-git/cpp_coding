#include<iostream>
#include <thread>
#include <mutex>

std::mutex mu;

void  sheared_print(std::string msg, int id){
   //mu.lock();
   std::lock_guard<std::mutex> locker(mu);   //RAII
   std::cout<< msg <<id <<std::endl;
   // mu.unlock();
}
void thread1() {
    for(int i = 0; i >-100; i--)
    {
        sheared_print(std::string("From t1: "), i);
    }
}

int main() {
    std::thread t1(thread1);  //t1 starts running 
    try
    {
        for(int i = 0; i < 100; i++)
        {
           sheared_print(std::string("From Main: "), i);
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

/*----------------------------------------------------------*/

#include<iostream>
#include <string>
#include <fstream>
#include <thread>
#include <mutex>

std::mutex mu;

class LogFile {
    std::mutex m_mutex;
    std::ofstream f;
public:
    LogFile(){
      f.open("log.txt");
    }   
    void sheared_print(std::string msg, int id){
        std::lock_guard<std::mutex> locker(mu);   
        f << msg << id <<std::endl;
    }
    //Never do 
    //do not return f to ouside world
    /*
    std::ofstream& getStream(){
       return f;
    }
    */	
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















 
