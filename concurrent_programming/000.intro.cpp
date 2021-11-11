#include<iostream>
#include <thread>

void function_1(){
    std::cout<< "I am in function_1" << std::endl;
}

int main(){
   std::thread t1(function_1);   //t1 starts running
   //t1.join();   // main thread waits for t1 to finish
   t1.detach();    // t1 will run freely of its own --deamon thread

   if(t1.joinable()){
       t1.join();
   }
   return 0;
}
