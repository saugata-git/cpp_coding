#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>

/*
void factorial(int n, int& x){
    int res = 1;
    for(int i=n; i>1 ; i--){
        res *= i;
    }
    std::cout << "Result is: " << res << std::endl;
    x = res;
}
*/

int factorial(int n){
    int res = 1;
    for(int i=n; i>1 ; i--){
        res *= i;
    }
    std::cout << "Result is: " << res << std::endl;
    return res;
}

int main() {
    int x;
    //std::thread t1(factorial, 4, std::ref(x));
    //t1.join();

    //std::future<int> fu  = std::async(std::launch::deferred, factorial, 4);     //will not create any thread 
    std::future<int> fu  = std::async(std::launch::async, factorial, 4);        // wait until child thread finish
    x = fu.get();   //call it only once

    return 0;
}


/*---------------------------------------------------------------------------*/

#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>

int factorial(std::future<int>& f){
    int res = 1;
    int n = f.get();
    for(int i=n; i>1 ; i--){
        res *= i;
    }
    return res;
}

int main() {
    int x;

    std::promise<int> p;
    std::future<int> f = p.get_future();
    std::future<int> fu  = std::async(std::launch::async, factorial, std::ref(f));  

    //we will sleep for while
    std::this_thread::sleep_for(std::chrono::milliseconds(20));
    
    //keeping my promise
    p.set_value(4);
      
    x = fu.get();
    std::cout << "Get result from Child :  " << x << std::endl;   

    return 0;
}


/*----------------------------------------------------------------------------------*/

#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>

int factorial(std::future<int>& f){
    int res = 1;
    int n = f.get();  //if not get the promise will through exception.
    for(int i=n; i>1 ; i--){
        res *= i;
    }
    return res;
}

int main() {
    int x;
    
    //promise and future can't be copied  can be movable only std::move() 
    std::promise<int> p;
    std::future<int> f = p.get_future();
    std::future<int> fu  = std::async(std::launch::async, factorial, std::ref(f));  

    //we will sleep for while
    std::this_thread::sleep_for(std::chrono::milliseconds(20));
    
    //we can not make promise 
    p.set_exception(std::make_exception_ptr(std::runtime_error("To err is human")));
    
    x = fu.get();
    std::cout << "Get result from Child :  " << x << std::endl;   

    return 0;
}


/*--------------------------------------------------------------------------------- */
#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>

int factorial(std::shared_future<int> f){
    int res = 1;
    int n = f.get();  //if not get the promise will through exception.
    for(int i=n; i>1 ; i--){
        res *= i;
    }
    return res;
}

int main() {
    int x , y , z ;

    //promise and future can't be copied  can be movable only std::move() 
    std::promise<int> p;
    std::future<int> f = p.get_future();
    std::shared_future<int> sf = f.share();

    std::future<int> fu = std::async(std::launch::async, factorial, sf);     //pass by value not ref
    std::future<int> fu1 = std::async(std::launch::async, factorial, sf); 
    std::future<int> fu2 = std::async(std::launch::async, factorial, sf); 

    //we will sleep for while
    std::this_thread::sleep_for(std::chrono::milliseconds(20));

    //Issue is we can not pass all same future to all the threads.
    //Create 4 promises  or better implement shared future.

    p.set_value(4);

    x = fu.get();
    std::cout << "Get result from Child1 :  " << x << std::endl;   
    
    y = fu1.get();
    std::cout << "Get result from Child2 :  " << y << std::endl; 

    z = fu2.get();
    std::cout << "Get result from Child3 :  " << z << std::endl; 

    return 0;
}













