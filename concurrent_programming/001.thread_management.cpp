#include<iostream>
#include <thread>

void thread1() {
    std::cout << "Hello, World" << std::endl;
}

int main() {
    std::thread t1(thread1);  //t1 starts running 
    try
    {
        for(int i = 0; i < 100; i++)
        {
        std::cout<<"From Main: "<< i <<std::endl;
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


/*-----------------------------------------------------------------*/

class Functor{
public:
    void operator()(){
        for(int i=0; i>-100; i--){
            std::cout<< "Form t1" << i <<std::endl;
        }
    }
};

int main() {
    //Functor fct;
    //std::thread t1(fct);
    std::thread t1((Functor()));
    //using RAII
    //Wrapper w(t1)
    try
    {
        for(int i = 0; i < 100; i++)
        {
        std::cout<<"From Main: "<< i <<std::endl;
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

/*-----------------------------------------------------------*/
class Functor{
public:
     //void operator()(std::string msg){                   //pass by value not by refernce 
     void operator()(std::string& msg){  
        std::cout<< "t1 says: " << msg <<std::endl;
        msg = "Proof pass by value not by refernce";                         
    }
};

int main() {
    std::string s = "No trust,no love";  //memory shearing
    //std::thread t1((Functor()), s);                      //parameter to thread always passed by value
    std::thread t1((Functor()), std::ref(s));               //pass by ref
    t1.join();
    std::cout<<"From Main: "<< s <<std::endl;
    return 0;
}

/*--------------------------------------------------------*/
class Functor{
public:
    void operator()(std::string&& msg){                    /rvalue ref
        std::cout<< "t1 says: " << msg <<std::endl;
        msg = "Proof pass by value not by refernce";                         
    }
};

int main() {
     std::string s = "No trust,no love";
     std::cout<< std::this_thread::get_id() <<std::endl;

     std::thread t1((Functor()), std::move(s));    // move semantics avoid copying 
     std::cout<< t1.get_id() <<std::endl;

     std::thread t2 = std::move(t1);          
     t2.join();
    
     return 0;
}

/*--------------------------------------------------------*/
//Number of concurrent threads supported. If the value is not well defined or not computable, returns ​0​.
int main() {
    //Oversubcription
    unsigned int n = std::thread::hardware_concurrency();
    std::cout << n << " concurrent threads are supported.\n";
    return 0;
}


