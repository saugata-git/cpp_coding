#include <iostream>
#include<iterator>
#include <vector>

// C++ 11 : Rvalue Reference
// 1. Moving Semantics
// 2. Perfect Forwarding
// Prerequisite: undersatnding of rvalue and lvalue


/**
 * @brief  Moving Semantics
 * 
 */

void printInt(int& i){  std::cout<< "lvalue reference : "<< i <<std::endl; }
void printInt(int&& i){  std::cout<< "rvalue reference : "<< i <<std::endl; }

//void printInt(int i){ } // function overloading of this kind will not work

int main(){

    //what is rvalue reference?
     
    int a = 5;    //a is a lvalue
   /*  int& b = a;   //b is lvalue reference (reference only in C++03)
       int&& c       //c is rvalue reference 
   */
    
    printInt(a);  // call printInt(int& i)
    printInt(6);  // call printInt(int&& i)

}
