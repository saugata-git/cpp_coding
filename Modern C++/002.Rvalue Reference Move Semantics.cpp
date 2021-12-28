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

/**
 * @brief  Moving Semantics
 * 
 */

class Vector{
    int size;
    double* arr_;
   public:
       Vector( const Vector& rhs) {   //Copy constructor  (deep copy)
            size = rhs.size;
            arr_ = new double[size];
            for( int i=0; i<size; i++){
                arr_[i] = rhs.arr_[i];
            }
       }

       Vector( Vector&& rhs) {   //Move constructor  (shallow copy)
            size = rhs.size;
            arr_ = rhs.arr_;
            rhs.arr_ = nullptr;
       } 
      ~Vector() { delete arr_; }
};

void foo(Vector v);

Vector createVector();

int main(){
    Vector reusable = createVector();
    foo(reusable);    // calls Copy Constructor

    foo(createVector());    // calls Move Constructor

}

/*
if not move constructor 

void foo_by_value(Vector v);
void foo_by_ref(Vector& v);

Vector createVector();

int main(){
    Vector reusable = createVector();
    foo_by_value(reusable);    
    foo_by_ref(createVector());   

}
*/

class Vector{
    int size;
    double* arr_;
   public:
       Vector( const Vector& rhs) {   //Copy constructor  (deep copy)
            size = rhs.size;
            arr_ = new double[size];
            for( int i=0; i<size; i++){
                arr_[i] = rhs.arr_[i];
            }
       }

       Vector( Vector&& rhs) {   //Move constructor  (shallow copy)
            size = rhs.size;
            arr_ = rhs.arr_;
            rhs.arr_ = nullptr;
       } 
      ~Vector() { delete arr_; }
};

void foo(Vector v);
void foo_by_ref(Vector& v);
Vector createVector();

int main(){
    Vector reusable = createVector();
    foo_by_ref(reusable);  //  call no constuctor    most efficient         
    foo(reusable);   // call copy constructor          least efficient        
    foo(std::move(reusable)); // call move constructor   2nd most efficient        
    // reusable is destoyed here dont use it as   rhs.arr_ = nullptr;
}

/**
 * Note 1: the most useful place for rvalue reference is overloading 
 * copy constuctor and copy assignment operator, to achieve move semantics.
 */
X& X::operator=(X const &rhs);
X& X::operator=(X&& rhs);


/**
 * Note 2: Move semantics is implemented for all STL containers,which means :
 *  a. Move to C++11,Your code will be faster withour chnaging anything.
 *  b.Passing-byvalue can be used for STL containers.
 */

std::vector<int> foo() {
    //.... 
    return myvector; 
}

void hoo(std::string s);
bool goo(std::vector<int>& arg); // pass by reference if you  
                                 // use arg to carry data back from goo()









